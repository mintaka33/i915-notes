# context

## user mode
CodechalDevice::CreateFactory or VphalDevice::CreateFactory

Mos_InitInterface

Mos_Specific_InitInterface

Linux_InitContext

mos_gem_context_create

## kernel mode
i915_gem_context_create_ioctl

i915_gem_create_context

__create_hw_context

## user mode driver call stack

mos_gem_context_create
```
iHD_drv_video.so!drmIoctl(int fd, unsigned long request, void * arg) (/home/fresh/data/work/intel_opencl_linux/source/media-driver/media_driver/linux/common/os/i915/xf86drm.c:181)
iHD_drv_video.so!mos_gem_context_create(mos_bufmgr * bufmgr) (/home/fresh/data/work/intel_opencl_linux/source/media-driver/media_driver/linux/common/os/i915/mos_bufmgr.c:4119)
iHD_drv_video.so!OsContextSpecific::Init(OsContextSpecific * const this, PMOS_CONTEXT pOsDriverContext) (/home/fresh/data/work/intel_opencl_linux/source/media-driver/media_driver/linux/common/os/mos_context_specific.cpp:450)
iHD_drv_video.so!Mos_Specific_InitInterface(PMOS_INTERFACE pOsInterface, PMOS_CONTEXT pOsDriverContext) (/home/fresh/data/work/intel_opencl_linux/source/media-driver/media_driver/linux/common/os/mos_os_specific.c:6150)
iHD_drv_video.so!Mos_InitInterface(PMOS_INTERFACE pOsInterface, PMOS_CONTEXT pOsDriverContext, MOS_COMPONENT component) (/home/fresh/data/work/intel_opencl_linux/source/media-driver/media_driver/agnostic/common/os/mos_os.c:736)
iHD_drv_video.so!CodechalDevice::CreateFactory(PMOS_INTERFACE osInterface, PMOS_CONTEXT osDriverContext, void * standardInfo, void * settings) (/home/fresh/data/work/intel_opencl_linux/source/media-driver/media_driver/linux/common/media_interfaces/media_interfaces.cpp:248)
iHD_drv_video.so!DdiMediaDecode::CreateCodecHal(DdiMediaDecode * const this, DDI_MEDIA_CONTEXT * mediaCtx, void * ptr, _CODECHAL_STANDARD_INFO * standardInfo) (/home/fresh/data/work/intel_opencl_linux/source/media-driver/media_driver/linux/common/codec/ddi/media_ddi_decode_base.cpp:945)
iHD_drv_video.so!DdiDecodeMPEG2::CodecHalInit(DdiDecodeMPEG2 * const this, DDI_MEDIA_CONTEXT * mediaCtx, void * ptr) (/home/fresh/data/work/intel_opencl_linux/source/media-driver/media_driver/linux/common/codec/ddi/media_ddi_decode_mpeg2.cpp:651)
iHD_drv_video.so!DdiDecode_CreateContext(VADriverContextP ctx, VAConfigID configId, int32_t pictureWidth, int32_t pictureHeight, int32_t flag, VASurfaceID * renderTargets, int32_t numRenderTargets, VAContextID * context) (/home/fresh/data/work/intel_opencl_linux/source/media-driver/media_driver/linux/common/codec/ddi/media_libva_decoder.cpp:338)
libva.so.2!vaCreateContext(VADisplay dpy, VAConfigID config_id, int picture_width, int picture_height, int flag, VASurfaceID * render_targets, int num_render_targets, VAContextID * context) (/home/fresh/data/work/intel_opencl_linux/source/libva/va/va.c:1167)
main(int argc, char ** argv) (/home/fresh/data/work/intel_opencl_linux/source/vaapi-opencl-interop/interop/vaocl.c:355)
```

GpuContextMgr::CreateGpuContext
```
iHD_drv_video.so!GpuContext::Create(const MOS_GPU_NODE gpuNode, MOS_GPU_CONTEXT mosGpuCtx, CmdBufMgr * cmdBufMgr, GpuContext * reusedContext) (/home/fresh/data/work/intel_opencl_linux/source/media-driver/media_driver/agnostic/common/os/mos_gpucontext.cpp:40)
iHD_drv_video.so!GpuContextMgr::CreateGpuContext(GpuContextMgr * const this, const MOS_GPU_NODE gpuNode, CmdBufMgr * cmdBufMgr, MOS_GPU_CONTEXT mosGpuCtx) (/home/fresh/data/work/intel_opencl_linux/source/media-driver/media_driver/agnostic/common/os/mos_gpucontextmgr.cpp:143)
iHD_drv_video.so!Mos_Specific_CreateGpuContext(PMOS_INTERFACE pOsInterface, MOS_GPU_CONTEXT mosGpuCxt, MOS_GPU_NODE GpuNode, PMOS_GPUCTX_CREATOPTIONS createOption) (/home/fresh/data/work/intel_opencl_linux/source/media-driver/media_driver/linux/common/os/mos_os_specific.c:4126)
iHD_drv_video.so!CodechalDecode::CreateGpuContexts(CodechalDecode * const this, CodechalSetting * codecHalSettings) (/home/fresh/data/work/intel_opencl_linux/source/media-driver/media_driver/agnostic/common/codec/hal/codechal_decoder.cpp:292)
iHD_drv_video.so!CodechalDecode::Allocate(CodechalDecode * const this, CodechalSetting * codecHalSettings) (/home/fresh/data/work/intel_opencl_linux/source/media-driver/media_driver/agnostic/common/codec/hal/codechal_decoder.cpp:509)
iHD_drv_video.so!DdiMediaDecode::CreateCodecHal(DdiMediaDecode * const this, DDI_MEDIA_CONTEXT * mediaCtx, void * ptr, _CODECHAL_STANDARD_INFO * standardInfo) (/home/fresh/data/work/intel_opencl_linux/source/media-driver/media_driver/linux/common/codec/ddi/media_ddi_decode_base.cpp:955)
iHD_drv_video.so!DdiDecodeMPEG2::CodecHalInit(DdiDecodeMPEG2 * const this, DDI_MEDIA_CONTEXT * mediaCtx, void * ptr) (/home/fresh/data/work/intel_opencl_linux/source/media-driver/media_driver/linux/common/codec/ddi/media_ddi_decode_mpeg2.cpp:651)
iHD_drv_video.so!DdiDecode_CreateContext(VADriverContextP ctx, VAConfigID configId, int32_t pictureWidth, int32_t pictureHeight, int32_t flag, VASurfaceID * renderTargets, int32_t numRenderTargets, VAContextID * context) (/home/fresh/data/work/intel_opencl_linux/source/media-driver/media_driver/linux/common/codec/ddi/media_libva_decoder.cpp:338)
libva.so.2!vaCreateContext(VADisplay dpy, VAConfigID config_id, int picture_width, int picture_height, int flag, VASurfaceID * render_targets, int num_render_targets, VAContextID * context) (/home/fresh/data/work/intel_opencl_linux/source/libva/va/va.c:1167)
main(int argc, char ** argv) (/home/fresh/data/work/intel_opencl_linux/source/vaapi-opencl-interop/interop/vaocl.c:355)
```

do_exec2
```
iHD_drv_video.so!drmIoctl(int fd, unsigned long request, void * arg) (/home/fresh/data/work/intel_opencl_linux/source/media-driver/media_driver/linux/common/os/i915/xf86drm.c:180)
iHD_drv_video.so!do_exec2(mos_linux_bo * bo, int used, mos_linux_context * ctx, drm_clip_rect_t * cliprects, int num_cliprects, int DR4, unsigned int flags) (/home/fresh/data/work/intel_opencl_linux/source/media-driver/media_driver/linux/common/os/i915/mos_bufmgr.c:3295)
iHD_drv_video.so!mos_gem_bo_context_exec2(mos_linux_bo * bo, int used, mos_linux_context * ctx, drm_clip_rect_t * cliprects, int num_cliprects, int DR4, unsigned int flags) (/home/fresh/data/work/intel_opencl_linux/source/media-driver/media_driver/linux/common/os/i915/mos_bufmgr.c:3385)
iHD_drv_video.so!GpuContextSpecific::SubmitCommandBuffer(GpuContextSpecific * const this, PMOS_INTERFACE osInterface, PMOS_COMMAND_BUFFER cmdBuffer, bool nullRendering) (/home/fresh/data/work/intel_opencl_linux/source/media-driver/media_driver/linux/common/os/mos_gpucontext_specific.cpp:792)
iHD_drv_video.so!Mos_Specific_SubmitCommandBuffer(PMOS_INTERFACE pOsInterface, PMOS_COMMAND_BUFFER pCmdBuffer, int32_t bNullRendering) (/home/fresh/data/work/intel_opencl_linux/source/media-driver/media_driver/linux/common/os/mos_os_specific.c:3512)
iHD_drv_video.so!CodechalDecodeMpeg2::SliceLevel(CodechalDecodeMpeg2 * const this) (/home/fresh/data/work/intel_opencl_linux/source/media-driver/media_driver/agnostic/common/codec/hal/codechal_decode_mpeg2.cpp:1176)
iHD_drv_video.so!CodechalDecode::Execute(CodechalDecode * const this, void * params) (/home/fresh/data/work/intel_opencl_linux/source/media-driver/media_driver/agnostic/common/codec/hal/codechal_decoder.cpp:1235)
iHD_drv_video.so!DdiMediaDecode::EndPicture(DdiMediaDecode * const this, VADriverContextP ctx, VAContextID context) (/home/fresh/data/work/intel_opencl_linux/source/media-driver/media_driver/linux/common/codec/ddi/media_ddi_decode_base.cpp:716)
iHD_drv_video.so!DdiDecode_EndPicture(VADriverContextP ctx, VAContextID context) (/home/fresh/data/work/intel_opencl_linux/source/media-driver/media_driver/linux/common/codec/ddi/media_libva_decoder.cpp:147)
iHD_drv_video.so!DdiMedia_EndPicture(VADriverContextP ctx, VAContextID context) (/home/fresh/data/work/intel_opencl_linux/source/media-driver/media_driver/linux/common/ddi/media_libva.cpp:3325)
libva.so.2!vaEndPicture(VADisplay dpy, VAContextID context) (/home/fresh/data/work/intel_opencl_linux/source/libva/va/va.c:1520)
main(int argc, char ** argv) (/home/fresh/data/work/intel_opencl_linux/source/vaapi-opencl-interop/interop/vaocl.c:408)
```
