# i915-notes

#perf

## decode only

```bash
ffmpeg -hwaccel vaapi -hwaccel_output_format vaapi -i test.264 -f null -
```
frame=10000 fps=890 q=-0.0 Lsize=N/A time=00:06:40.00 bitrate=N/A speed=35.6x

## decode + jpeg encode

```bash
ffmpeg -y -loglevel verbose -hwaccel vaapi -vaapi_device /dev/dri/renderD128 -hwaccel_output_format vaapi -i test.264 \
-c:v mjpeg_vaapi -global_quality 100 out.mjpeg
```
frame=10000 fps=423 q=-0.0 Lsize=  601827kB time=00:06:40.00 bitrate=12325.4kbits/s speed=16.9x 
