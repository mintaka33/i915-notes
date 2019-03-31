# i915-notes

i915_gem_create_context
```c
ctx = __create_hw_context(dev_priv, file_priv);
if (IS_ERR(ctx))
	return ctx;

if (HAS_FULL_PPGTT(dev_priv)) {
	struct i915_hw_ppgtt *ppgtt;

	ppgtt = i915_ppgtt_create(dev_priv, file_priv);
	if (IS_ERR(ppgtt)) {
		DRM_DEBUG_DRIVER("PPGTT setup failed (%ld)\n",
				 PTR_ERR(ppgtt));
		__destroy_hw_context(ctx, file_priv);
		return ERR_CAST(ppgtt);
	}

	ctx->ppgtt = ppgtt;
	ctx->desc_template = default_desc_template(dev_priv, ppgtt);
}
```
  
  
  
