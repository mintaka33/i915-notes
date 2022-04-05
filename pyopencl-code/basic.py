import numpy as np
import pyopencl as cl

# Platform
pf = cl.get_platforms()
for i, p in enumerate(pf):
    print('platform[%d]:'%i, p)

p = pf[0]

print(p.get_info(cl.platform_info.VERSION))
print(p.get_info(cl.platform_info.VENDOR))
print(p.get_info(cl.platform_info.PROFILE))
print(p.get_info(cl.platform_info.NAME))
print(p.get_info(cl.platform_info.NUMERIC_VERSION))
print(p.get_info(cl.platform_info.HOST_TIMER_RESOLUTION))
print(p.get_info(cl.platform_info.EXTENSIONS_WITH_VERSION))
for e in p.get_info(cl.platform_info.EXTENSIONS).split():
    print(e)

# Device
for i, p in enumerate(pf):
    print('platform[%d]:'%i, p)
    for t in [cl.device_type.ALL, cl.device_type.DEFAULT, cl.device_type.CPU, cl.device_type.GPU, cl.device_type.ACCELERATOR, cl.device_type.CUSTOM]:
        try:
            print('    0x%08x:'%t, p.get_devices(device_type=t))
        except:
            print('    0x%08x:'%t, 'Invalid device')

d = pf[0].get_devices(device_type=cl.device_type.GPU)
print(cl.device_info.ADDRESS_BITS)

# Context
ctx = cl.Context( dev_type=cl.device_type.ALL, properties=[(cl.context_properties.PLATFORM, pf[0])])
print(ctx)

print('done')