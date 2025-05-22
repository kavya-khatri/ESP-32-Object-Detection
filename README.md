# ESP32 Object Detection
This project implements real-time object detection on an ESP32 microcontroller. It leverages a machine learning model trained using Edge Impulse to identify objects from images captured by the ESP32. The system communicates over Wi-Fi to send detection data and uses an FTDI adapter for programming and debugging.

---

## Features

* **Real-time object detection** using a custom-trained model from Edge Impulse
* **Wi-Fi connectivity** for internet communication and data transmission
* **FTDI interface** for easy serial communication and flashing
* **Optimized for ESP32** to fit within program memory and RAM constraints
* Lightweight and modular code for easy customization and integration

---

## Hardware Requirements

* ESP32 development board (any common variant)
* FTDI USB-to-Serial adapter (for programming if your ESP32 board lacks built-in USB)
* Camera module compatible with ESP32 (e.g., ESP32-CAM)
* USB cable for FTDI and/or ESP32 board
* Internet connection for Wi-Fi functionality

---

## Software Requirements

* Arduino IDE with ESP32 board support installed
* Edge Impulse trained model files
* Required libraries:

  * `WiFi.h` (ESP32 Wi-Fi library)
  * Edge Impulse inference SDK (if applicable)
  * Other dependencies included in the code comments

---

## Installation & Setup

1. **Clone the repository:**

   ```bash
   git clone https://github.com/kavya-khatri/ESP-32-Object-Detection.git
   cd ESP-32-Object-Detection
   ```

2. **Open the project in Arduino IDE or VS Code with PlatformIO.**

3. **Install the ESP32 Board:**

   * Go to Arduino IDE Preferences and add the ESP32 boards URL:

     ```
     https://dl.espressif.com/dl/package_esp32_index.json
     ```
   * Then install the ESP32 platform via Board Manager.

4. **Install required libraries:**

   * Use Library Manager to install `WiFi.h` and other dependencies.

5. **Configure Wi-Fi credentials:**

   * Modify the code to set your Wi-Fi SSID and password for internet access.

6. **Upload the code:**

   * Connect your ESP32 board or FTDI adapter.
   * Select the correct COM port.
   * Upload the sketch.

---

## Usage

* Once uploaded, the ESP32 will connect to your Wi-Fi network.
* The object detection model will scan images captured by the camera.
* Detected objects and their confidence levels will be processed and can be sent to a server or displayed via serial output.

---

## Troubleshooting

* Ensure your FTDI adapter or ESP32 board is properly connected and recognized by your PC.
* If you encounter serial port errors, verify drivers for USB-to-serial converters (e.g., CP2102, CH340).
* Confirm Wi-Fi credentials are correct and your network is accessible.
* For ESP32 library errors, ensure you have installed the latest ESP32 Arduino core.

---

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

---

## Acknowledgments

* Edge Impulse for the easy-to-use machine learning training platform.
* Espressif for the ESP32 platform and tools.
* FTDI for USB-to-serial communication hardware.

Author-- Kavya Khatri 
