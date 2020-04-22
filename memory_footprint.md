# profile memory footprint

## pmap
```bash
ps aus | grep ffmpeg
pmap -x pid >pmap.log
```

## smaps
```bash
ps aus | grep gst
cat /proc/pid/smaps >smaps.log
```

## valgrind + massif

http://valgrind.org/docs/manual/ms-manual.html

```bash
valgrind --tool=massif gst-launch-1.0 filesrc location=/home/fresh/data/video/test.mp4 ! qtdemux ! h264parse ! vaapih264dec ! fakesink sync=true
valgrind --tool=massif --time-unit=B  gst-launch-1.0 filesrc location=/home/fresh/data/video/test.mp4 ! qtdemux ! h264parse ! vaapih264dec ! fakesink sync=true

# low level memory allocation profiling (mmap)
valgrind --tool=massif --pages-as-heap=yes gst-launch-1.0 filesrc location=/home/fresh/data/video/test.mp4 ! qtdemux ! h264parse ! vaapih264dec ! fakesink sync=true

ms_print massif.out.8193 >massif.out.8193.log

```

