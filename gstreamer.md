# gstreamer command

## install gstreamer
```bash
sudo apt update 
sudo apt upgrade
sudo apt install build-essential pkg-config

sudo apt install \
libgstreamer1.0-0 \
gstreamer1.0-tools \
gstreamer1.0-doc \
gstreamer1.0-plugins-base \
gstreamer1.0-plugins-good \
gstreamer1.0-plugins-bad \
gstreamer1.0-plugins-ugly \
gstreamer1.0-libav \
gstreamer1.0-vaapi \
gstreamer1.0-vaapi-doc \
gstreamer1.0-x \
gstreamer1.0-alsa \
gstreamer1.0-gl \
gstreamer1.0-gtk3 \
gstreamer1.0-qt5 \
gstreamer1.0-pulseaudio
```

## inspect
```bash
gst-inspect-1.0 | grep vaapi
gst-inspect-1.0 | grep gva
```

## h264 decode
```bash
gst-launch-1.0 filesrc location=/home/fresh/data/video/test.mp4 ! decodebin ! fakesink
gst-launch-1.0 filesrc location=/home/fresh/data/video/test.mp4 ! qtdemux ! h264parse ! vaapih264dec ! fakesink sync=false
gst-launch-1.0 filesrc location=/home/fresh/data/video/test.mp4 ! qtdemux ! h264parse ! vaapih264dec ! gvafpscounter ! fakesink sync=false

# h264 decode free run
gst-launch-1.0 filesrc location=/home/fresh/data/video/test.mp4 ! qtdemux ! h264parse ! vaapih264dec ! "video/x-raw(memory:VASurface)" ! fakesink sync=false

# h264 decode free run + display
gst-launch-1.0 filesrc location=/home/fresh/data/video/test.mp4 ! qtdemux ! h264parse ! vaapih264dec ! \
fpsdisplaysink video-sink=xvimagesink sync=false

# h264 decode fix fps + display
gst-launch-1.0 filesrc location=/home/fresh/data/video/test.mp4 ! qtdemux ! h264parse ! vaapih264dec ! \
fpsdisplaysink video-sink=xvimagesink sync=true

gst-launch-1.0 filesrc location=/home/fresh/data/video/dog100.mp4 ! \
qtdemux ! h264parse ! vaapih264dec ! "video/x-raw(memory:VASurface)" ! \
gvafpscounter ! fakesink sync=true

gst-launch-1.0 filesrc location=/home/fresh/data/video/dog100.264 ! \
h264parse ! vaapih264dec ! "video/x-raw(memory:VASurface)" ! \
gvafpscounter ! fakesink sync=true

gst-launch-1.0 filesrc location=/home/fresh/data/video/dog100.264 ! \
h264parse ! vaapih264dec ! "video/x-raw(memory:VASurface)" ! vaapipostproc ! video/x-raw\(memory:VASurface\) !  \
gvafpscounter ! fakesink sync=true

```

## decode + VPP
```bash
gst-launch-1.0 filesrc location=/home/fresh/data/video/test.mp4 ! qtdemux ! h264parse ! vaapih264dec ! \
vaapipostproc ! videoconvert ! video/x-raw, format=BGR ! gvafpscounter ! fakesink sync=false

gst-launch-1.0 filesrc location=/home/fresh/data/video/test2.mp4 ! qtdemux ! h264parse ! vaapih264dec ! \
vaapipostproc ! videoconvert ! video/x-raw, format=BGR ! filesink location=out.yuv

gst-launch-1.0 filesrc location=/home/fresh/data/video/test.mp4 ! \
qtdemux ! h264parse ! vaapih264dec ! \
vaapipostproc ! video/x-raw,format=YUY2,width=300,height=300 ! \
fpsdisplaysink video-sink=xvimagesink sync=false

gst-launch-1.0 filesrc location=/home/fresh/data/video/test.mp4 ! \
qtdemux ! h264parse ! vaapih264dec ! \
vaapipostproc ! video/x-raw, format=BGR ! \
fpsdisplaysink video-sink=fakesink text-overlay=false signal-fps-measurements=true sync=false

gst-launch-1.0 filesrc location=/home/fresh/data/video/dog100.264 ! \
decodebin ! vaapipostproc ! video/x-raw,format=BGRA,width=300,height=300 !  \
gvafpscounter ! fakesink sync=true

gst-launch-1.0 filesrc location=/home/fresh/data/video/dog100.264 ! \
decodebin ! vaapipostproc ! video/x-raw,format=YUY2,width=300,height=300 ! \
gvafpscounter ! fakesink sync=false

gst-launch-1.0 filesrc location=/home/fresh/data/video/dog100.264 ! \
h264parse ! vaapih264dec ! "video/x-raw(memory:VASurface)" ! vaapipostproc ! video/x-raw,format=YUY2,width=300,height=300 ! \
gvafpscounter ! fakesink sync=false

gst-launch-1.0 filesrc location=/home/fresh/data/video/dog100.264 ! \
h264parse ! vaapih264dec ! video/x-raw,format=NV12,width=1920,height=1088 ! vaapipostproc ! video/x-raw,format=YUY2,width=300,height=300 ! \
gvafpscounter ! fakesink sync=false

gst-launch-1.0 filesrc location=/home/fresh/data/video/dog100.264 ! \
h264parse ! vaapih264dec ! vaapipostproc ! \
gvafpscounter ! fakesink sync=false
```

## decode + vpp + gst_inference

```bash
gst-launch-1.0 --gst-plugin-path ${GST_PLUGIN_PATH} -v filesrc location=~/data/video/cat.mp4 ! \
decodebin ! video/x-raw ! videoconvert ! \
gvadetect model=~/data/model/mobilenet-ssd/mobilenet-ssd.xml device=GPU every-nth-frame=1 batch-size=1 gpu-streams=1 ! queue ! \
gvaclassify model=~/data/model/resnet-50/resnet-50-128.xml device=GPU batch-size=1 gpu-streams=1 ! queue ! \
gvawatermark ! videoconvert ! fpsdisplaysink video-sink=xvimagesink sync=false

gst-launch-1.0 --gst-plugin-path -v filesrc location=~/data/video/cat.mp4 ! \
decodebin ! video/x-raw ! videoconvert ! \
gvadetect model=~/data/model/mobilenet-ssd/mobilenet-ssd.xml device=CPU every-nth-frame=1 ! queue ! \
gvametaconvert converter=json method=all ! \
gvametapublish method=file filepath="./out.json" ! \
gvafpscounter ! fakesink

gst-launch-1.0 --gst-plugin-path -v filesrc location=~/data/video/dog100.264 ! \
decodebin ! video/x-raw ! videoconvert ! \
gvadetect model=~/data/model/mobilenet-ssd/mobilenet-ssd.xml device=GPU every-nth-frame=1 ! queue ! \
gvaclassify model=~/data/model/resnet-50/resnet-50-128.xml device=GPU every-nth-frame=1 ! queue ! \
gvametaconvert converter=json method=all ! \
gvametapublish method=file filepath="/tmp/out.json" ! \
gvafpscounter ! fakesink

# pre-proc with OpenCV
gst-launch-1.0 filesrc location=/home/fresh/data/video/dog1.264 ! \
decodebin ! video/x-raw ! videoconvert ! \
gvadetect model=~/data/model/mobilenet-ssd/mobilenet-ssd.xml device=GPU every-nth-frame=1 ! queue ! \
gvaclassify model=~/data/model/resnet-50/resnet-50-128.xml device=GPU batch-size=1 gpu-streams=1 ! queue ! \
gvametaconvert converter=json method=all ! \
gvametapublish method=file filepath="/tmp/out.json" ! \
gvafpscounter ! fakesink

gst-launch-1.0 filesrc location=/home/fresh/data/video/dog1.264 ! \
decodebin ! video/x-raw ! videoconvert ! \
gvadetect model=~/data/model/mobilenet-ssd/mobilenet-ssd.xml device=GPU every-nth-frame=1 ! queue ! \
gvametaconvert converter=json method=all ! \
gvametapublish method=file filepath="/tmp/out.json" ! \
gvafpscounter ! fakesink

# pre-proc with VPP vaapi
gst-launch-1.0 filesrc location=/home/fresh/data/video/dog1.264 ! \
h264parse ! vaapih264dec ! vaapipostproc ! video/x-raw\(memory:VASurface\) ! \
gvadetect model=~/data/model/mobilenet-ssd/mobilenet-ssd.xml device=GPU every-nth-frame=1 pre-proc=vaapi ! queue ! \
gvaclassify model=~/data/model/resnet-50/resnet-50-128.xml device=GPU batch-size=1 gpu-streams=1 pre-proc=vaapi ! queue ! \
gvametaconvert converter=json method=all ! \
gvametapublish method=file filepath="/tmp/out.json" ! \
gvafpscounter ! fakesink

gst-launch-1.0 filesrc location=/home/fresh/data/video/dog1.264 ! \
h264parse ! vaapih264dec ! vaapipostproc ! video/x-raw\(memory:VASurface\) ! \
gvadetect model=~/data/model/mobilenet-ssd/mobilenet-ssd.xml device=GPU every-nth-frame=1 pre-proc=vaapi ! queue ! \
gvametaconvert converter=json method=all ! \
gvametapublish method=file filepath="/tmp/out.json" ! \
gvafpscounter ! fakesink
```
