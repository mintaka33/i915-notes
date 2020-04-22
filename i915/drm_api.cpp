#define DRM_IOCTL_BASE 'd'

#define DRM_IO(nr) _IO(DRM_IOCTL_BASE, nr)
#define DRM_IOR(nr, type) _IOR(DRM_IOCTL_BASE, nr, type)
#define DRM_IOW(nr, type) _IOW(DRM_IOCTL_BASE, nr, type)
#define DRM_IOWR(nr, type) _IOWR(DRM_IOCTL_BASE, nr, type)

#define DRM_IOCTL_VERSION               DRM_IOWR(0x00, struct drm_version)
#define DRM_IOCTL_GET_UNIQUE            DRM_IOWR(0x01, struct drm_unique)
#define DRM_IOCTL_GET_MAGIC             DRM_IOR(0x02, struct drm_auth)
#define DRM_IOCTL_IRQ_BUSID             DRM_IOWR(0x03, struct drm_irq_busid)
#define DRM_IOCTL_GET_MAP               DRM_IOWR(0x04, struct drm_map)
#define DRM_IOCTL_GET_CLIENT            DRM_IOWR(0x05, struct drm_client)
#define DRM_IOCTL_GET_STATS             DRM_IOR(0x06, struct drm_stats)
#define DRM_IOCTL_SET_VERSION           DRM_IOWR(0x07, struct drm_set_version)
#define DRM_IOCTL_MODESET_CTL           DRM_IOW(0x08, struct drm_modeset_ctl)
#define DRM_IOCTL_GEM_CLOSE             DRM_IOW(0x09, struct drm_gem_close)
#define DRM_IOCTL_GEM_FLINK             DRM_IOWR(0x0a, struct drm_gem_flink)
#define DRM_IOCTL_GEM_OPEN              DRM_IOWR(0x0b, struct drm_gem_open)
#define DRM_IOCTL_GET_CAP               DRM_IOWR(0x0c, struct drm_get_cap)
#define DRM_IOCTL_SET_CLIENT_CAP        DRM_IOW(0x0d, struct drm_set_client_cap)

#define DRM_IOCTL_SET_UNIQUE            DRM_IOW(0x10, struct drm_unique)
#define DRM_IOCTL_AUTH_MAGIC            DRM_IOW(0x11, struct drm_auth)
#define DRM_IOCTL_BLOCK                 DRM_IOWR(0x12, struct drm_block)
#define DRM_IOCTL_UNBLOCK               DRM_IOWR(0x13, struct drm_block)
#define DRM_IOCTL_CONTROL               DRM_IOW(0x14, struct drm_control)
#define DRM_IOCTL_ADD_MAP               DRM_IOWR(0x15, struct drm_map)
#define DRM_IOCTL_ADD_BUFS              DRM_IOWR(0x16, struct drm_buf_desc)
#define DRM_IOCTL_MARK_BUFS             DRM_IOW(0x17, struct drm_buf_desc)
#define DRM_IOCTL_INFO_BUFS             DRM_IOWR(0x18, struct drm_buf_info)
#define DRM_IOCTL_MAP_BUFS              DRM_IOWR(0x19, struct drm_buf_map)
#define DRM_IOCTL_FREE_BUFS             DRM_IOW(0x1a, struct drm_buf_free)

#define DRM_IOCTL_RM_MAP                DRM_IOW(0x1b, struct drm_map)

#define DRM_IOCTL_SET_SAREA_CTX         DRM_IOW(0x1c, struct drm_ctx_priv_map)
#define DRM_IOCTL_GET_SAREA_CTX         DRM_IOWR(0x1d, struct drm_ctx_priv_map)

#define DRM_IOCTL_SET_MASTER            DRM_IO(0x1e)
#define DRM_IOCTL_DROP_MASTER           DRM_IO(0x1f)

#define DRM_IOCTL_ADD_CTX               DRM_IOWR(0x20, struct drm_ctx)
#define DRM_IOCTL_RM_CTX                DRM_IOWR(0x21, struct drm_ctx)
#define DRM_IOCTL_MOD_CTX               DRM_IOW(0x22, struct drm_ctx)
#define DRM_IOCTL_GET_CTX               DRM_IOWR(0x23, struct drm_ctx)
#define DRM_IOCTL_SWITCH_CTX            DRM_IOW(0x24, struct drm_ctx)
#define DRM_IOCTL_NEW_CTX               DRM_IOW(0x25, struct drm_ctx)
#define DRM_IOCTL_RES_CTX               DRM_IOWR(0x26, struct drm_ctx_res)
#define DRM_IOCTL_ADD_DRAW              DRM_IOWR(0x27, struct drm_draw)
#define DRM_IOCTL_RM_DRAW               DRM_IOWR(0x28, struct drm_draw)
#define DRM_IOCTL_DMA                   DRM_IOWR(0x29, struct drm_dma)
#define DRM_IOCTL_LOCK                  DRM_IOW(0x2a, struct drm_lock)
#define DRM_IOCTL_UNLOCK                DRM_IOW(0x2b, struct drm_lock)
#define DRM_IOCTL_FINISH                DRM_IOW(0x2c, struct drm_lock)

#define DRM_IOCTL_PRIME_HANDLE_TO_FD    DRM_IOWR(0x2d, struct drm_prime_handle)
#define DRM_IOCTL_PRIME_FD_TO_HANDLE    DRM_IOWR(0x2e, struct drm_prime_handle)

#define DRM_IOCTL_AGP_ACQUIRE           DRM_IO(0x30)
#define DRM_IOCTL_AGP_RELEASE           DRM_IO(0x31)
#define DRM_IOCTL_AGP_ENABLE            DRM_IOW(0x32, struct drm_agp_mode)
#define DRM_IOCTL_AGP_INFO              DRM_IOR(0x33, struct drm_agp_info)
#define DRM_IOCTL_AGP_ALLOC             DRM_IOWR(0x34, struct drm_agp_buffer)
#define DRM_IOCTL_AGP_FREE              DRM_IOW(0x35, struct drm_agp_buffer)
#define DRM_IOCTL_AGP_BIND              DRM_IOW(0x36, struct drm_agp_binding)
#define DRM_IOCTL_AGP_UNBIND            DRM_IOW(0x37, struct drm_agp_binding)

#define DRM_IOCTL_SG_ALLOC              DRM_IOWR(0x38, struct drm_scatter_gather)
#define DRM_IOCTL_SG_FREE               DRM_IOW(0x39, struct drm_scatter_gather)

#define DRM_IOCTL_WAIT_VBLANK           DRM_IOWR(0x3a, union drm_wait_vblank)

#define DRM_IOCTL_CRTC_GET_SEQUENCE     DRM_IOWR(0x3b, struct drm_crtc_get_sequence)
#define DRM_IOCTL_CRTC_QUEUE_SEQUENCE   DRM_IOWR(0x3c, struct drm_crtc_queue_sequence)

#define DRM_IOCTL_UPDATE_DRAW           DRM_IOW(0x3f, struct drm_update_draw)

#define DRM_IOCTL_MODE_GETRESOURCES     DRM_IOWR(0xA0, struct drm_mode_card_res)
#define DRM_IOCTL_MODE_GETCRTC          DRM_IOWR(0xA1, struct drm_mode_crtc)
#define DRM_IOCTL_MODE_SETCRTC          DRM_IOWR(0xA2, struct drm_mode_crtc)
#define DRM_IOCTL_MODE_CURSOR           DRM_IOWR(0xA3, struct drm_mode_cursor)
#define DRM_IOCTL_MODE_GETGAMMA         DRM_IOWR(0xA4, struct drm_mode_crtc_lut)
#define DRM_IOCTL_MODE_SETGAMMA         DRM_IOWR(0xA5, struct drm_mode_crtc_lut)
#define DRM_IOCTL_MODE_GETENCODER       DRM_IOWR(0xA6, struct drm_mode_get_encoder)
#define DRM_IOCTL_MODE_GETCONNECTOR     DRM_IOWR(0xA7, struct drm_mode_get_connector)
#define DRM_IOCTL_MODE_ATTACHMODE       DRM_IOWR(0xA8, struct drm_mode_mode_cmd) /* deprecated (never worked) */
#define DRM_IOCTL_MODE_DETACHMODE       DRM_IOWR(0xA9, struct drm_mode_mode_cmd) /* deprecated (never worked) */

#define DRM_IOCTL_MODE_GETPROPERTY      DRM_IOWR(0xAA, struct drm_mode_get_property)
#define DRM_IOCTL_MODE_SETPROPERTY      DRM_IOWR(0xAB, struct drm_mode_connector_set_property)
#define DRM_IOCTL_MODE_GETPROPBLOB      DRM_IOWR(0xAC, struct drm_mode_get_blob)
#define DRM_IOCTL_MODE_GETFB            DRM_IOWR(0xAD, struct drm_mode_fb_cmd)
#define DRM_IOCTL_MODE_ADDFB            DRM_IOWR(0xAE, struct drm_mode_fb_cmd)
#define DRM_IOCTL_MODE_RMFB             DRM_IOWR(0xAF, unsigned int)
#define DRM_IOCTL_MODE_PAGE_FLIP        DRM_IOWR(0xB0, struct drm_mode_crtc_page_flip)
#define DRM_IOCTL_MODE_DIRTYFB          DRM_IOWR(0xB1, struct drm_mode_fb_dirty_cmd)

#define DRM_IOCTL_MODE_CREATE_DUMB          DRM_IOWR(0xB2, struct drm_mode_create_dumb)
#define DRM_IOCTL_MODE_MAP_DUMB             DRM_IOWR(0xB3, struct drm_mode_map_dumb)
#define DRM_IOCTL_MODE_DESTROY_DUMB         DRM_IOWR(0xB4, struct drm_mode_destroy_dumb)
#define DRM_IOCTL_MODE_GETPLANERESOURCES    DRM_IOWR(0xB5, struct drm_mode_get_plane_res)
#define DRM_IOCTL_MODE_GETPLANE             DRM_IOWR(0xB6, struct drm_mode_get_plane)
#define DRM_IOCTL_MODE_SETPLANE             DRM_IOWR(0xB7, struct drm_mode_set_plane)
#define DRM_IOCTL_MODE_ADDFB2               DRM_IOWR(0xB8, struct drm_mode_fb_cmd2)
#define DRM_IOCTL_MODE_OBJ_GETPROPERTIES    DRM_IOWR(0xB9, struct drm_mode_obj_get_properties)
#define DRM_IOCTL_MODE_OBJ_SETPROPERTY      DRM_IOWR(0xBA, struct drm_mode_obj_set_property)
#define DRM_IOCTL_MODE_CURSOR2              DRM_IOWR(0xBB, struct drm_mode_cursor2)
#define DRM_IOCTL_MODE_ATOMIC               DRM_IOWR(0xBC, struct drm_mode_atomic)
#define DRM_IOCTL_MODE_CREATEPROPBLOB       DRM_IOWR(0xBD, struct drm_mode_create_blob)
#define DRM_IOCTL_MODE_DESTROYPROPBLOB      DRM_IOWR(0xBE, struct drm_mode_destroy_blob)

#define DRM_IOCTL_SYNCOBJ_CREATE            DRM_IOWR(0xBF, struct drm_syncobj_create)
#define DRM_IOCTL_SYNCOBJ_DESTROY           DRM_IOWR(0xC0, struct drm_syncobj_destroy)
#define DRM_IOCTL_SYNCOBJ_HANDLE_TO_FD      DRM_IOWR(0xC1, struct drm_syncobj_handle)
#define DRM_IOCTL_SYNCOBJ_FD_TO_HANDLE      DRM_IOWR(0xC2, struct drm_syncobj_handle)
#define DRM_IOCTL_SYNCOBJ_WAIT              DRM_IOWR(0xC3, struct drm_syncobj_wait)
#define DRM_IOCTL_SYNCOBJ_RESET             DRM_IOWR(0xC4, struct drm_syncobj_array)
#define DRM_IOCTL_SYNCOBJ_SIGNAL            DRM_IOWR(0xC5, struct drm_syncobj_array)

#define DRM_IOCTL_MODE_CREATE_LEASE         DRM_IOWR(0xC6, struct drm_mode_create_lease)
#define DRM_IOCTL_MODE_LIST_LESSEES         DRM_IOWR(0xC7, struct drm_mode_list_lessees)
#define DRM_IOCTL_MODE_GET_LEASE            DRM_IOWR(0xC8, struct drm_mode_get_lease)
#define DRM_IOCTL_MODE_REVOKE_LEASE         DRM_IOWR(0xC9, struct drm_mode_revoke_lease)

/*
 * i915 specific ioctls.
 *
 * The device specific ioctl range is [DRM_COMMAND_BASE, DRM_COMMAND_END) ie
 * [0x40, 0xa0) (a0 is excluded). The numbers below are defined as offset
 * against DRM_COMMAND_BASE and should be between [0x0, 0x60).
 */
#define DRM_I915_INIT		0x00
#define DRM_I915_FLUSH		0x01
#define DRM_I915_FLIP		0x02
#define DRM_I915_BATCHBUFFER	0x03
#define DRM_I915_IRQ_EMIT	0x04
#define DRM_I915_IRQ_WAIT	0x05
#define DRM_I915_GETPARAM	0x06
#define DRM_I915_SETPARAM	0x07
#define DRM_I915_ALLOC		0x08
#define DRM_I915_FREE		0x09
#define DRM_I915_INIT_HEAP	0x0a
#define DRM_I915_CMDBUFFER	0x0b
#define DRM_I915_DESTROY_HEAP	0x0c
#define DRM_I915_SET_VBLANK_PIPE	0x0d
#define DRM_I915_GET_VBLANK_PIPE	0x0e
#define DRM_I915_VBLANK_SWAP	0x0f
#define DRM_I915_HWS_ADDR	0x11
#define DRM_I915_GEM_INIT	0x13
#define DRM_I915_GEM_EXECBUFFER	0x14
#define DRM_I915_GEM_PIN	0x15
#define DRM_I915_GEM_UNPIN	0x16
#define DRM_I915_GEM_BUSY	0x17
#define DRM_I915_GEM_THROTTLE	0x18
#define DRM_I915_GEM_ENTERVT	0x19
#define DRM_I915_GEM_LEAVEVT	0x1a
#define DRM_I915_GEM_CREATE	0x1b
#define DRM_I915_GEM_PREAD	0x1c
#define DRM_I915_GEM_PWRITE	0x1d
#define DRM_I915_GEM_MMAP	0x1e
#define DRM_I915_GEM_SET_DOMAIN	0x1f
#define DRM_I915_GEM_SW_FINISH	0x20
#define DRM_I915_GEM_SET_TILING	0x21
#define DRM_I915_GEM_GET_TILING	0x22
#define DRM_I915_GEM_GET_APERTURE 0x23
#define DRM_I915_GEM_MMAP_GTT	0x24
#define DRM_I915_GET_PIPE_FROM_CRTC_ID	0x25
#define DRM_I915_GEM_MADVISE	0x26
#define DRM_I915_OVERLAY_PUT_IMAGE	0x27
#define DRM_I915_OVERLAY_ATTRS	0x28
#define DRM_I915_GEM_EXECBUFFER2	0x29
#define DRM_I915_GEM_EXECBUFFER2_WR	DRM_I915_GEM_EXECBUFFER2
#define DRM_I915_GET_SPRITE_COLORKEY	0x2a
#define DRM_I915_SET_SPRITE_COLORKEY	0x2b
#define DRM_I915_GEM_WAIT	0x2c
#define DRM_I915_GEM_CONTEXT_CREATE	0x2d
#define DRM_I915_GEM_CONTEXT_DESTROY	0x2e
#define DRM_I915_GEM_SET_CACHING	0x2f
#define DRM_I915_GEM_GET_CACHING	0x30
#define DRM_I915_REG_READ		0x31
#define DRM_I915_GET_RESET_STATS	0x32
#define DRM_I915_GEM_USERPTR		0x33
#define DRM_I915_GEM_CONTEXT_GETPARAM	0x34
#define DRM_I915_GEM_CONTEXT_SETPARAM	0x35
#define DRM_I915_PERF_OPEN		0x36
#define DRM_I915_PERF_ADD_CONFIG	0x37
#define DRM_I915_PERF_REMOVE_CONFIG	0x38
#define DRM_I915_QUERY			0x39

#define DRM_IOCTL_I915_INIT                     DRM_IOW( DRM_COMMAND_BASE + DRM_I915_INIT, drm_i915_init_t)
#define DRM_IOCTL_I915_FLUSH                    DRM_IO ( DRM_COMMAND_BASE + DRM_I915_FLUSH)
#define DRM_IOCTL_I915_FLIP                     DRM_IO ( DRM_COMMAND_BASE + DRM_I915_FLIP)
#define DRM_IOCTL_I915_BATCHBUFFER              DRM_IOW( DRM_COMMAND_BASE + DRM_I915_BATCHBUFFER, drm_i915_batchbuffer_t)
#define DRM_IOCTL_I915_IRQ_EMIT                 DRM_IOWR(DRM_COMMAND_BASE + DRM_I915_IRQ_EMIT, drm_i915_irq_emit_t)
#define DRM_IOCTL_I915_IRQ_WAIT                 DRM_IOW( DRM_COMMAND_BASE + DRM_I915_IRQ_WAIT, drm_i915_irq_wait_t)
#define DRM_IOCTL_I915_GETPARAM                 DRM_IOWR(DRM_COMMAND_BASE + DRM_I915_GETPARAM, drm_i915_getparam_t)
#define DRM_IOCTL_I915_SETPARAM                 DRM_IOW( DRM_COMMAND_BASE + DRM_I915_SETPARAM, drm_i915_setparam_t)
#define DRM_IOCTL_I915_ALLOC                    DRM_IOWR(DRM_COMMAND_BASE + DRM_I915_ALLOC, drm_i915_mem_alloc_t)
#define DRM_IOCTL_I915_FREE                     DRM_IOW( DRM_COMMAND_BASE + DRM_I915_FREE, drm_i915_mem_free_t)
#define DRM_IOCTL_I915_INIT_HEAP                DRM_IOW( DRM_COMMAND_BASE + DRM_I915_INIT_HEAP, drm_i915_mem_init_heap_t)
#define DRM_IOCTL_I915_CMDBUFFER                DRM_IOW( DRM_COMMAND_BASE + DRM_I915_CMDBUFFER, drm_i915_cmdbuffer_t)
#define DRM_IOCTL_I915_DESTROY_HEAP             DRM_IOW( DRM_COMMAND_BASE + DRM_I915_DESTROY_HEAP, drm_i915_mem_destroy_heap_t)
#define DRM_IOCTL_I915_SET_VBLANK_PIPE          DRM_IOW( DRM_COMMAND_BASE + DRM_I915_SET_VBLANK_PIPE, drm_i915_vblank_pipe_t)
#define DRM_IOCTL_I915_GET_VBLANK_PIPE          DRM_IOR( DRM_COMMAND_BASE + DRM_I915_GET_VBLANK_PIPE, drm_i915_vblank_pipe_t)
#define DRM_IOCTL_I915_VBLANK_SWAP              DRM_IOWR(DRM_COMMAND_BASE + DRM_I915_VBLANK_SWAP, drm_i915_vblank_swap_t)
#define DRM_IOCTL_I915_HWS_ADDR                 DRM_IOW(DRM_COMMAND_BASE + DRM_I915_HWS_ADDR, struct drm_i915_gem_init)
#define DRM_IOCTL_I915_GEM_INIT                 DRM_IOW(DRM_COMMAND_BASE + DRM_I915_GEM_INIT, struct drm_i915_gem_init)
#define DRM_IOCTL_I915_GEM_EXECBUFFER           DRM_IOW(DRM_COMMAND_BASE + DRM_I915_GEM_EXECBUFFER, struct drm_i915_gem_execbuffer)
#define DRM_IOCTL_I915_GEM_EXECBUFFER2          DRM_IOW(DRM_COMMAND_BASE + DRM_I915_GEM_EXECBUFFER2, struct drm_i915_gem_execbuffer2)
#define DRM_IOCTL_I915_GEM_EXECBUFFER2_WR       DRM_IOWR(DRM_COMMAND_BASE + DRM_I915_GEM_EXECBUFFER2_WR, struct drm_i915_gem_execbuffer2)
#define DRM_IOCTL_I915_GEM_PIN                  DRM_IOWR(DRM_COMMAND_BASE + DRM_I915_GEM_PIN, struct drm_i915_gem_pin)
#define DRM_IOCTL_I915_GEM_UNPIN                DRM_IOW(DRM_COMMAND_BASE + DRM_I915_GEM_UNPIN, struct drm_i915_gem_unpin)
#define DRM_IOCTL_I915_GEM_BUSY                 DRM_IOWR(DRM_COMMAND_BASE + DRM_I915_GEM_BUSY, struct drm_i915_gem_busy)
#define DRM_IOCTL_I915_GEM_SET_CACHING          DRM_IOW(DRM_COMMAND_BASE + DRM_I915_GEM_SET_CACHING, struct drm_i915_gem_caching)
#define DRM_IOCTL_I915_GEM_GET_CACHING          DRM_IOWR(DRM_COMMAND_BASE + DRM_I915_GEM_GET_CACHING, struct drm_i915_gem_caching)
#define DRM_IOCTL_I915_GEM_THROTTLE             DRM_IO ( DRM_COMMAND_BASE + DRM_I915_GEM_THROTTLE)
#define DRM_IOCTL_I915_GEM_ENTERVT              DRM_IO(DRM_COMMAND_BASE + DRM_I915_GEM_ENTERVT)
#define DRM_IOCTL_I915_GEM_LEAVEVT              DRM_IO(DRM_COMMAND_BASE + DRM_I915_GEM_LEAVEVT)
#define DRM_IOCTL_I915_GEM_CREATE               DRM_IOWR(DRM_COMMAND_BASE + DRM_I915_GEM_CREATE, struct drm_i915_gem_create)
#define DRM_IOCTL_I915_GEM_PREAD                DRM_IOW (DRM_COMMAND_BASE + DRM_I915_GEM_PREAD, struct drm_i915_gem_pread)
#define DRM_IOCTL_I915_GEM_PWRITE               DRM_IOW (DRM_COMMAND_BASE + DRM_I915_GEM_PWRITE, struct drm_i915_gem_pwrite)
#define DRM_IOCTL_I915_GEM_MMAP                 DRM_IOWR(DRM_COMMAND_BASE + DRM_I915_GEM_MMAP, struct drm_i915_gem_mmap)
#define DRM_IOCTL_I915_GEM_MMAP_GTT             DRM_IOWR(DRM_COMMAND_BASE + DRM_I915_GEM_MMAP_GTT, struct drm_i915_gem_mmap_gtt)
#define DRM_IOCTL_I915_GEM_SET_DOMAIN           DRM_IOW (DRM_COMMAND_BASE + DRM_I915_GEM_SET_DOMAIN, struct drm_i915_gem_set_domain)
#define DRM_IOCTL_I915_GEM_SW_FINISH            DRM_IOW (DRM_COMMAND_BASE + DRM_I915_GEM_SW_FINISH, struct drm_i915_gem_sw_finish)
#define DRM_IOCTL_I915_GEM_SET_TILING           DRM_IOWR (DRM_COMMAND_BASE + DRM_I915_GEM_SET_TILING, struct drm_i915_gem_set_tiling)
#define DRM_IOCTL_I915_GEM_GET_TILING           DRM_IOWR (DRM_COMMAND_BASE + DRM_I915_GEM_GET_TILING, struct drm_i915_gem_get_tiling)
#define DRM_IOCTL_I915_GEM_GET_APERTURE         DRM_IOR  (DRM_COMMAND_BASE + DRM_I915_GEM_GET_APERTURE, struct drm_i915_gem_get_aperture)
#define DRM_IOCTL_I915_GET_PIPE_FROM_CRTC_ID    DRM_IOWR(DRM_COMMAND_BASE + DRM_I915_GET_PIPE_FROM_CRTC_ID, struct drm_i915_get_pipe_from_crtc_id)
#define DRM_IOCTL_I915_GEM_MADVISE              DRM_IOWR(DRM_COMMAND_BASE + DRM_I915_GEM_MADVISE, struct drm_i915_gem_madvise)
#define DRM_IOCTL_I915_OVERLAY_PUT_IMAGE        DRM_IOW(DRM_COMMAND_BASE + DRM_I915_OVERLAY_PUT_IMAGE, struct drm_intel_overlay_put_image)
#define DRM_IOCTL_I915_OVERLAY_ATTRS            DRM_IOWR(DRM_COMMAND_BASE + DRM_I915_OVERLAY_ATTRS, struct drm_intel_overlay_attrs)
#define DRM_IOCTL_I915_SET_SPRITE_COLORKEY      DRM_IOWR(DRM_COMMAND_BASE + DRM_I915_SET_SPRITE_COLORKEY, struct drm_intel_sprite_colorkey)
#define DRM_IOCTL_I915_GET_SPRITE_COLORKEY      DRM_IOWR(DRM_COMMAND_BASE + DRM_I915_GET_SPRITE_COLORKEY, struct drm_intel_sprite_colorkey)
#define DRM_IOCTL_I915_GEM_WAIT                 DRM_IOWR(DRM_COMMAND_BASE + DRM_I915_GEM_WAIT, struct drm_i915_gem_wait)
#define DRM_IOCTL_I915_GEM_CONTEXT_CREATE       DRM_IOWR (DRM_COMMAND_BASE + DRM_I915_GEM_CONTEXT_CREATE, struct drm_i915_gem_context_create)
#define DRM_IOCTL_I915_GEM_CONTEXT_DESTROY      DRM_IOW (DRM_COMMAND_BASE + DRM_I915_GEM_CONTEXT_DESTROY, struct drm_i915_gem_context_destroy)
#define DRM_IOCTL_I915_REG_READ                 DRM_IOWR (DRM_COMMAND_BASE + DRM_I915_REG_READ, struct drm_i915_reg_read)
#define DRM_IOCTL_I915_GET_RESET_STATS          DRM_IOWR (DRM_COMMAND_BASE + DRM_I915_GET_RESET_STATS, struct drm_i915_reset_stats)
#define DRM_IOCTL_I915_GEM_USERPTR              DRM_IOWR (DRM_COMMAND_BASE + DRM_I915_GEM_USERPTR, struct drm_i915_gem_userptr)
#define DRM_IOCTL_I915_GEM_CONTEXT_GETPARAM     DRM_IOWR (DRM_COMMAND_BASE + DRM_I915_GEM_CONTEXT_GETPARAM, struct drm_i915_gem_context_param)
#define DRM_IOCTL_I915_GEM_CONTEXT_SETPARAM     DRM_IOWR (DRM_COMMAND_BASE + DRM_I915_GEM_CONTEXT_SETPARAM, struct drm_i915_gem_context_param)
#define DRM_IOCTL_I915_PERF_OPEN                DRM_IOW(DRM_COMMAND_BASE + DRM_I915_PERF_OPEN, struct drm_i915_perf_open_param)
#define DRM_IOCTL_I915_PERF_ADD_CONFIG          DRM_IOW(DRM_COMMAND_BASE + DRM_I915_PERF_ADD_CONFIG, struct drm_i915_perf_oa_config)
#define DRM_IOCTL_I915_PERF_REMOVE_CONFIG       DRM_IOW(DRM_COMMAND_BASE + DRM_I915_PERF_REMOVE_CONFIG, __u64)
#define DRM_IOCTL_I915_QUERY                    DRM_IOWR(DRM_COMMAND_BASE + DRM_I915_QUERY, struct drm_i915_query)

