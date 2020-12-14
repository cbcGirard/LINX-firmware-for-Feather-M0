# LINX-firmware-for-Feather-M0

After downloading this repo, copy its three folders into the Arduino libraries directory (i.e., LinxAdafruitFeatherM0WiFi and the others must be directly under Arduino/libraries).

The Arduino IDE must be configured to use the Adafruit Feather board; follow the instructions at https://learn.adafruit.com/adafruit-feather-m0-wifi-atwinc1500/setup and the following pages (Using with Arduino IDE and Using the WiFi Module). In addition to the WiFi101 library, you will also need to install the FlashStorage library to use this firmware.

To load firmware onto the microcontroller, open the sketch under Examples>LINX>LinxAdafruitFeatherM0WiFi>AdafruitFeatherM0_Serial and upload to Feather M0 board

To communicate with Labview over WiFi, instead upload the AdafruitFeatherM0_WiFi sketch after changing the SSID (network name) and password in wifiInfo.h to match your home network.

NB: re-configuring WiFi from Labview is currently not functional, and loading that firmware version will disable the board's USB connection. If that happens, double-press the board's reset button to enter recovery mode, and upload a working firmware (e.g. the Blink example) to the newly-created port.