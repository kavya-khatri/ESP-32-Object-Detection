#include <WiFi.h>
#include "esp_camera.h"
#include "edge-impulse-sdk/classifier/ei_run_classifier.h"

// Replace with your WiFi credentials
const char* ssid = "Kavya-5g";
const char* password = "Temp@JKL";

// CAMERA_MODEL_AI_THINKER is used for most ESP32-CAM boards
#define PWDN_GPIO_NUM     -1
#define RESET_GPIO_NUM    -1
#define XCLK_GPIO_NUM      0
#define SIOD_GPIO_NUM     26
#define SIOC_GPIO_NUM     27
#define Y9_GPIO_NUM       35
#define Y8_GPIO_NUM       34
#define Y7_GPIO_NUM       39
#define Y6_GPIO_NUM       36
#define Y5_GPIO_NUM       21
#define Y4_GPIO_NUM       19
#define Y3_GPIO_NUM       18
#define Y2_GPIO_NUM        5
#define VSYNC_GPIO_NUM    25
#define HREF_GPIO_NUM     23
#define PCLK_GPIO_NUM     22

ei_device_t device;
signal_t signal;

// Function to capture image and prepare signal for Edge Impulse
bool capture_image(size_t width, size_t height, ei::signal_t *signal, uint8_t *out_buf) {
  camera_fb_t *fb = esp_camera_fb_get();
  if (!fb) {
    Serial.println("Camera capture failed");
    return false;
  }

  if (fb->width != width || fb->height != height) {
    Serial.printf("Resolution mismatch: got %dx%d, expected %dx%d\n", fb->width, fb->height, width, height);
    esp_camera_fb_return(fb);
    return false;
  }

  memcpy(out_buf, fb->buf, fb->len);
  esp_camera_fb_return(fb);
  return true;
}

void setup() {
  Serial.begin(115200);
  delay(1000);

  // Connect to WiFi
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi...");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("Connected!");

  // Initialize camera
  camera_config_t config;
  config.ledc_channel = LEDC_CHANNEL_0;
  config.ledc_timer = LEDC_TIMER_0;
  config.pin_d0 = Y2_GPIO_NUM;
  config.pin_d1 = Y3_GPIO_NUM;
  config.pin_d2 = Y4_GPIO_NUM;
  config.pin_d3 = Y5_GPIO_NUM;
  config.pin_d4 = Y6_GPIO_NUM;
  config.pin_d5 = Y7_GPIO_NUM;
  config.pin_d6 = Y8_GPIO_NUM;
  config.pin_d7 = Y9_GPIO_NUM;
  config.pin_xclk = XCLK_GPIO_NUM;
  config.pin_pclk = PCLK_GPIO_NUM;
  config.pin_vsync = VSYNC_GPIO_NUM;
  config.pin_href = HREF_GPIO_NUM;
  config.pin_sscb_sda = SIOD_GPIO_NUM;
  config.pin_sscb_scl = SIOC_GPIO_NUM;
  config.pin_pwdn = PWDN_GPIO_NUM;
  config.pin_reset = RESET_GPIO_NUM;
  config.xclk_freq_hz = 20000000;
  config.pixel_format = PIXFORMAT_GRAYSCALE;
  config.frame_size = FRAMESIZE_96X96; // Must match EI model
  config.fb_count = 1;

  // Init camera
  esp_err_t err = esp_camera_init(&config);
  if (err != ESP_OK) {
    Serial.printf("Camera init failed with error 0x%x", err);
    return;
  }

  Serial.println("Camera init successful!");
}

void loop() {
  static uint8_t image_buf[96 * 96]; // adjust if different model resolution

  if (!capture_image(96, 96, &signal, image_buf)) {
    Serial.println("Image capture failed");
    delay(1000);
    return;
  }

  // Wrap buffer in signal_t
  signal.total_length = 96 * 96;
  signal.get_data = [](size_t offset, size_t length, float *out) -> int {
    for (size_t i = 0; i < length; i++) {
      out[i] = image_buf[offset + i] / 255.0f;
    }
    return 0;
  };

  ei_impulse_result_t result;
  EI_IMPULSE_ERROR res = run_classifier(&signal, &result, false);

  if (res != EI_IMPULSE_OK) {
    Serial.println("Inference failed");
    return;
  }

  // Print results
  Serial.println("Inference results:");
  for (size_t i = 0; i < result.classification.count; i++) {
    ei_classifier_label_t label = result.classification.labels[i];
    float value = result.classification.values[i];
    Serial.printf("%s: %.2f\n", label.name, value * 100);
  }

  delay(5000); // run every 5 seconds
}
