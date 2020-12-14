/****************************************************************************************	
**  This is example LINX firmware for use with the Feather
**
**  For more information see:           www.labviewmakerhub.com/linx
**  For support visit the forums at:    www.labviewmakerhub.com/forums/linx
**  
**  Written By Ken Sharp, modified for Adafruit Feather M0 WiFi by CBC Girard
**
**  BSD2 License.
****************************************************************************************/

// Leave uncommented if network name+password programmed in sketch
  #define WIFI_HARDCODED
// WARNING: firmware is currently not functional if the above is commented out!!! After programming the Feather, the USB connection will no longer work. To rescue the Feather, double-tap its reset button to enter a recovery mode, where the red LED will pulse and a new USB device will appear to the PC. Select this new port and upload a working firmware to restore the Feather.

//Include All Peripheral Libraries Used By LINX
#include <SPI.h>
#include <Wire.h>
#include <FlashAsEEPROM.h>
#include <Servo.h>
#include <WiFi101.h>

// Pre-Programmed 
#ifdef WIFI_HARDCODED
#include "wifiInfo.h"
#endif

//Include Device Specific Header From Sketch>>Import Library (In This Case LinxAdafruitFeatherM0WiFi.h)
//Also Include Desired LINX Listener From Sketch>>Import Library 
#include <LinxAdafruitFeatherM0WiFi.h>
#include <LinxWiFi101Listener.h>

//Create A Pointer To The LINX Device Object We Instantiate In Setup()
LinxAdafruitFeatherM0WiFi* LinxDevice;

//Initialize LINX Device And Listener
void setup()
{
  //Instantiate The LINX Device
  LinxDevice = new LinxAdafruitFeatherM0WiFi();
  
  //The LINX Serial Listener Is Included In WIFI Listener And Pre Instantiated.  This Is Necessary For Configuring Wifi Settings.
  LinxSerialConnection.Start(LinxDevice, 0);

  
  //Start Wifi Listener.  Settings (IP, SSID, etc) Will Be Read From Non Volatile Storage And Can Be Set Using LINX VIs Via USB
  #ifndef WIFI_HARDCODED
   LinxWifiConnection.Start(LinxDevice);
  #else
  //Or, set manually: 

  LinxWifiConnection.SetSsid(THE_SSID);
  LinxWifiConnection.SetSecurity(WPA2_PASSPHRASE);  //NONE, WPA2_PASSPHRASE, WPA2_KEY, WEP40, WEO104
  LinxWifiConnection.SetPassphrase(THE_PW);    			   
  LinxWifiConnection.Start(LinxDevice, 0, 0, 0, 0, 44300);  //Start With Fixed IP and Port.  When Using This Method You Cannot Update The IP/Port Using LINX VIs
 // Use an IP address of 0.0.0.0 for DHCP; router will assign address
  #endif

}

void loop()
{
  //Listen For New Packets From LabVIEW
  LinxWifiConnection.CheckForCommands();
  LinxSerialConnection.CheckForCommands();
  
  //Your Code Here, But It will Slow Down The Connection With LabVIEW
}