import numpy as np
import pyopencl as cl
import time

a_np = np.random.rand(10000000).astype(np.float32)
b_np = np.random.rand(10000000).astype(np.float32)

ctx = cl.create_some_context(interactive=False)
queue = cl.CommandQueue(ctx, properties=cl.command_queue_properties.PROFILING_ENABLE)

mf = cl.mem_flags
a_g = cl.Buffer(ctx, mf.READ_ONLY | mf.COPY_HOST_PTR, hostbuf=a_np)
b_g = cl.Buffer(ctx, mf.READ_ONLY | mf.COPY_HOST_PTR, hostbuf=b_np)

prg = cl.Program(ctx, '''
__kernel void sum(
    __global const float *a_g, __global const float *b_g, __global float *res_g)
{
  int gid = get_global_id(0);
  //printf(\"a[\%d]=\%f, b[\%d]=\%f\\n\", gid, a_g[gid], gid, b_g[gid]);
  res_g[gid] = a_g[gid] * b_g[gid];

}
''').build()

res_g = cl.Buffer(ctx, mf.WRITE_ONLY, a_np.nbytes)
knl = prg.sum  # Use this Kernel object for repeated calls
evt = knl(queue, a_np.shape, None, a_g, b_g, res_g)

print('status = ', evt.get_info(cl.event_info.COMMAND_EXECUTION_STATUS))
evt.wait() # or cl.wait_for_events([evt])
print('status = ', evt.get_info(cl.event_info.COMMAND_EXECUTION_STATUS))

queued = evt.get_profiling_info(cl.profiling_info.QUEUED)
submit = evt.get_profiling_info(cl.profiling_info.SUBMIT)
start = evt.get_profiling_info(cl.profiling_info.START)
end = evt.get_profiling_info(cl.profiling_info.END)
complete = evt.get_profiling_info(cl.profiling_info.COMPLETE)

print('interval (submit - queued) = %f ms' % ((submit - queued)/1e6))
print('interval (start - submit) = %f ms' % ((start - submit)/1e6))
print('interval (end - start) = %f ms' % ((end - start)/1e6))
# print('interval (complete - end) = %f ms' % ((complete - end)/1e6))

res_np = np.empty_like(a_np)
cl.enqueue_copy(queue, res_np, res_g)

# Check on CPU with Numpy:

cpu_start = time.time_ns()
np_cpu = (a_np * b_np)
print('CPUe executin time = %f ms' % ((time.time_ns() - cpu_start)/1e6))
print(res_np - np_cpu)

print(np.linalg.norm(res_np - (a_np * b_np)))
assert np.allclose(res_np, a_np * b_np)
