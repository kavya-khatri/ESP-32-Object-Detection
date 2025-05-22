# ESP32 Object Detection

This project demonstrates an object detection system using the ESP32-CAM module. The ESP32 captures images, processes them using a model trained with [Edge Impulse](https://www.edgeimpulse.com/), and identifies objects in real-time.

## Features

- Image capture using ESP32-CAM camera module
- On-device object detection with a pre-trained Edge Impulse model
- Connectivity via WiFi (configurable)
- Serial output of detection results
- Compatible with FTDI USB-to-Serial adapters

## Hardware Requirements

- ESP32-CAM AI Thinker Module (or compatible ESP32 with camera)
- FTDI USB-to-Serial adapter for programming/debugging (if needed)
- USB cable and power source

## Software Requirements

- Arduino IDE or PlatformIO for compiling and uploading code
- ESP32 Arduino core installed ([installation guide](https://github.com/espressif/arduino-esp32))
- Edge Impulse Arduino library (exported from your Edge Impulse project)

## Setup Instructions

1. **Clone or download this repository.**

2. **Configure WiFi credentials:**

   Edit the source code file (`main.cpp` or `.ino`) and update:

   ```cpp
   const char* ssid = "YOUR_WIFI_SSID";
   const char* password = "YOUR_WIFI_PASSWORD";
````

3. Upload the code:

   Use Arduino IDE or PlatformIO to compile and upload the code to your ESP32-CAM.

4. Monitor results:

   Open the Serial Monitor at 115200 baud to view detection output.

## Notes

* Ensure the camera settings in the code match your hardware and model input requirements.
* The object detection model was trained using Edge Impulse with a 96x96 grayscale input.
* Modify the code to send detection data over WiFi if needed.

## References

* [Edge Impulse Documentation](https://docs.edgeimpulse.com/)
* [ESP32-CAM AI Thinker Pinout and Tutorials](https://randomnerdtutorials.com/esp32-cam-pinout/)
* [ESP32 Arduino Core GitHub](https://github.com/espressif/arduino-esp32)

## License

This project is licensed under the MIT License.

## Author

Your Name —   Kavya Khatri (https://github.com/kavya-khatri)
