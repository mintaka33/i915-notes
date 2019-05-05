i915 command buffer submission flow

# submission flow

## i915_request_queue

## i915_request_add

## i915_request_submit

## i915_request_execute

init platform
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
```

request_execute call flow
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

## i915_request_in
```c
# intel_lrc.c
void __i915_request_submit(struct i915_request *request)
{trace_i915_request_in(rq, port_index(port, execlists));}
```
## i915_request_out
