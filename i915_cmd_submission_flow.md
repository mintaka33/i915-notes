i915 command buffer submission flow
====

# i915_request_queue
```c
// i915_gem_execbuffer.c
i915_gem_do_execbuffer(struct drm_device *dev,
		       struct drm_file *file,
		       struct drm_i915_gem_execbuffer2 *args,
		       struct drm_i915_gem_exec_object2 *exec,
		       struct drm_syncobj **fences)
{
    trace_i915_request_queue(eb.request, eb.batch_flags);
}
```
# i915_request_add
```c
// i915_gem_execbuffer.c
i915_gem_do_execbuffer(struct drm_device *dev,
		       struct drm_file *file,
		       struct drm_i915_gem_execbuffer2 *args,
		       struct drm_i915_gem_exec_object2 *exec,
		       struct drm_syncobj **fences)
{
    __i915_request_add(eb.request, err == 0);
}

// i915_request.c
void __i915_request_add(struct i915_request *request, bool flush_caches)
{trace_i915_request_add(request);}
```

# i915_request_submit
```c
submit_notify(struct i915_sw_fence *fence, enum i915_sw_fence_notify state)
{
	struct i915_request *request =
		container_of(fence, typeof(*request), submit);

	switch (state) {
	case FENCE_COMPLETE:
		trace_i915_request_submit(request);
		rcu_read_lock();
		request->engine->submit_request(request);
		rcu_read_unlock();
		break;

	case FENCE_FREE:
		i915_request_put(request);
		break;
	}

	return NOTIFY_DONE;
}

i915_request_alloc(struct intel_engine_cs *engine, struct i915_gem_context *ctx)
{i915_sw_fence_init(&i915_request_get(rq)->submit, submit_notify);}

i915_gem_do_execbuffer(struct drm_device *dev,
		       struct drm_file *file,
		       struct drm_i915_gem_execbuffer2 *args,
		       struct drm_i915_gem_exec_object2 *exec,
		       struct drm_syncobj **fences)
{
	/* Allocate a request for this batch buffer nice and early. */
	eb.request = i915_request_alloc(eb.engine, eb.ctx);
}
```

# i915_request_execute

**init platform**
```c
// i915_pci.c
#define GEN8_FEATURES \
	G75_FEATURES, \
	GEN(8), \
	BDW_COLORS, \
	.page_sizes = I915_GTT_PAGE_SIZE_4K | \
		      I915_GTT_PAGE_SIZE_2M, \
	.has_logical_ring_contexts = 1, \ // use lrc in Gen8+
	.has_full_48bit_ppgtt = 1, \
	.has_64bit_reloc = 1, \
	.has_reset_engine = 1
  
#define GEN9_FEATURES \
	GEN8_FEATURES, \
	GEN(9), \
	GEN9_DEFAULT_PAGE_SIZES, \
	.has_logical_ring_preemption = 1, \
	.has_csr = 1, \
	.has_guc = 1, \
	.has_ipc = 1, \
	.ddb_size = 896
  
#define CFL_PLATFORM \
	GEN9_FEATURES, \
	PLATFORM(INTEL_COFFEELAKE)

#define HAS_EXECLISTS(dev_priv) HAS_LOGICAL_RING_CONTEXTS(dev_priv)

#define HAS_LOGICAL_RING_CONTEXTS(dev_priv) \
		((dev_priv)->info.has_logical_ring_contexts)
```

**init func pointer**
```c
// intel_engine_cs.c
int intel_engines_init(struct drm_i915_private *dev_priv)
{
    if (HAS_EXECLISTS(dev_priv))
        init = class_info->init_execlists;
    else
       init = class_info->init_legacy;
}

// intel_engine_cs.c
static const struct engine_class_info intel_engine_classes[] = {
	[RENDER_CLASS] = {
		.name = "rcs",
		.init_execlists = logical_render_ring_init,
		.init_legacy = intel_init_render_ring_buffer,
		.uabi_class = I915_ENGINE_CLASS_RENDER,
	},
}

int logical_render_ring_init(struct intel_engine_cs *engine)
{logical_ring_setup(engine);}

logical_ring_setup(struct intel_engine_cs *engine)
{logical_ring_default_vfuncs(engine);}

logical_ring_default_vfuncs(struct intel_engine_cs *engine)
{engine->set_default_submission = execlists_set_default_submission;}

static void execlists_set_default_submission(struct intel_engine_cs *engine)
{
    engine->submit_request = execlists_submit_request;
    engine->cancel_requests = execlists_cancel_requests;
    engine->schedule = execlists_schedule;
    engine->execlists.tasklet.func = execlists_submission_tasklet;
}
```

**request_execute call flow**
```c
static void execlists_set_default_submission(struct intel_engine_cs *engine)
{engine->execlists.tasklet.func = execlists_submission_tasklet;}

static void execlists_submission_tasklet(unsigned long data)
{execlists_dequeue(engine);}

static void execlists_dequeue(struct intel_engine_cs *engine)
{submit = __execlists_dequeue(engine);}

static bool __execlists_dequeue(struct intel_engine_cs *engine)
{__i915_request_submit(rq);}

void __i915_request_submit(struct i915_request *request)
{trace_i915_request_execute(request);}
```

# i915_request_in
```c
// intel_lrc.c
void __i915_request_submit(struct i915_request *request)
{trace_i915_request_in(rq, port_index(port, execlists));}
```
# i915_request_out
```c
static void execlists_submission_tasklet(unsigned long data)
{
    execlists_context_schedule_out(rq, INTEL_CONTEXT_SCHEDULE_OUT);
}

execlists_context_schedule_out(struct i915_request *rq, unsigned long status)
{
    intel_engine_context_out(rq->engine);	
    execlists_context_status_change(rq, status);
    trace_i915_request_out(rq);
}
```
