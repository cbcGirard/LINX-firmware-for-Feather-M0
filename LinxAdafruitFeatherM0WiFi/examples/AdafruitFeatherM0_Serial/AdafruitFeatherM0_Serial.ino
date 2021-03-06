/****************************************************************************************	
**  This is example LINX firmware for use with the Adafruit Feather M0 with the serial 
**  interface enabled.
**
**  For more information see:           www.labviewmakerhub.com/linx
**  For support visit the forums at:    www.labviewmakerhub.com/forums/linx
**  
**  Written By Sam Kristoff, modified by CBC Girard
**
**  BSD2 License.
****************************************************************************************/

//Include All Peripheral Libraries Used By LINX
#include <SPI.h>
#include <Wire.h>
#include <FlashAsEEPROM.h>
#include <Servo.h>

//Include Device Specific Header From Sketch>>Import Library (In This Case LinxAdafruitFeatherM0WiFi.h)
//Also Include Desired LINX Listener From Sketch>>Import Library (In This Case LinxSerialListener.h)
#include <LinxAdafruitFeatherM0WiFi.h>
#include <LinxSerialListener.h>
 
//Create A Pointer To The LINX Device Object We Instantiate In Setup()
LinxAdafruitFeatherM0WiFi* LinxDevice;

//Initialize LINX Device And Listener
void setup()
{
  //Instantiate The LINX Device
  LinxDevice = new LinxAdafruitFeatherM0WiFi();
  
  //The LINXT Listener Is Pre Instantiated, Call Start And Pass A Pointer To The LINX Device And The UART Channel To Listen On
  LinxSerialConnection.Start(LinxDevice, 0);  
}

void loop()
{
  //Listen For New Packets From LabVIEW
  LinxSerialConnection.CheckForCommands();
  
  //Your Code Here, But It will Slow Down The Connection With LabVIEW
}


