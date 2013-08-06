node js/app.js &

cd ~/mjpg-streamer/mjpg-streamer
./mjpg_streamer -i "./input_uvc.so -d /dev/video0  -r 320x240 -f 5 -y YUV" -o "./output_http.so -p 8090 -w ./www" && fg


