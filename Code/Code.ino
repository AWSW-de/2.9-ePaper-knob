// #######################################################################################################################################################
// #
// # Code for the printables "2.9" ePaper knob" project: https://www.printables.com/de/model/309889-29-epaper-knob
// #
// # Code by https://github.com/AWSW-de
// #
// # Released under license: GNU General Public License v3.0: https://github.com/AWSW-de/2.9-ePaper-knob/blob/main/LICENSE
// #
// #######################################################################################################################################################
/*
      ___           ___           ___           ___           ___           ___                    ___           ___           ___           ___     
     /\  \         /\  \         /\  \         /\  \         /\  \         /\  \                  /\__\         /\__\         /\  \         /\  \    
    /::\  \       /::\  \       /::\  \       /::\  \       /::\  \       /::\  \                /:/  /        /::|  |       /::\  \       /::\  \   
   /:/\:\  \     /:/\:\  \     /:/\:\  \     /:/\:\  \     /:/\:\  \     /:/\:\  \              /:/__/        /:|:|  |      /:/\:\  \     /:/\:\  \  
  /::\~\:\  \   /::\~\:\  \   /::\~\:\  \   /::\~\:\  \   /::\~\:\  \   /::\~\:\  \            /::\__\____   /:/|:|  |__   /:/  \:\  \   /::\~\:\__\ 
 /:/\:\ \:\__\ /:/\:\ \:\__\ /:/\:\ \:\__\ /:/\:\ \:\__\ /:/\:\ \:\__\ /:/\:\ \:\__\          /:/\:::::\__\ /:/ |:| /\__\ /:/__/ \:\__\ /:/\:\ \:|__|
 \:\~\:\ \/__/ \/__\:\/:/  / \/__\:\/:/  / \/__\:\/:/  / \:\~\:\ \/__/ \/_|::\/:/  /          \/_|:|~~|~    \/__|:|/:/  / \:\  \ /:/  / \:\~\:\/:/  /
  \:\ \:\__\        \::/  /       \::/  /       \::/  /   \:\ \:\__\      |:|::/  /              |:|  |         |:/:/  /   \:\  /:/  /   \:\ \::/  / 
   \:\ \/__/         \/__/        /:/  /         \/__/     \:\ \/__/      |:|\/__/               |:|  |         |::/  /     \:\/:/  /     \:\/:/  /  
    \:\__\                       /:/  /                     \:\__\        |:|  |                 |:|  |         /:/  /       \::/  /       \::/__/   
     \/__/                       \/__/                       \/__/         \|__|                  \|__|         \/__/         \/__/         ~~       
*/



// #######################################################################################################################################################
// Change text here: 
String Line1 = "ePaper knob";
String Line2 = "Your text here";
// NOTE: No changes needed from this line on
// #######################################################################################################################################################



// #######################################################################################################################################################
// Code version:
String codeversion = "V1.0.0";


// #######################################################################################################################################################
// # Includes:
// # You will need to add the following libraries to your Arduino IDE to use the project:
// "GxEPD" plus its named addons and restart Ardunino         --> https://github.com/ZinggJM/GxEPD
// "Adafruit GFX" plus its named addons and restart Ardunino  --> https://github.com/adafruit/Adafruit-GFX-Library
// #######################################################################################################################################################
// ePaper display and fonts:
#include <GxEPD.h>                        
#include <GxGDEH029A1/GxGDEH029A1.h>      // 2.9" b/w
#include <GxIO/GxIO_SPI/GxIO_SPI.h>
#include <GxIO/GxIO.h>
GxIO_Class io(SPI, /*CS=5*/ SS, /*DC=*/ 17, /*RST=*/ 16); // arbitrary selection of 17, 16
GxEPD_Class display(io, /*RST=*/ 16, /*BUSY=*/ 4); // arbitrary selection of (16), 4
#include <Fonts/FreeMonoBold9pt7b.h>
#include <Fonts/FreeMonoBold12pt7b.h>
#include <Fonts/FreeMonoBold18pt7b.h>
#include <Fonts/FreeMonoBold24pt7b.h>


// #######################################################################################################################################################
void setup() {
  Serial.begin(115200);
  display.init();
  delay(1000);
  String DisplayText = "-";
  DisplayText = Line1 + "\n\n" + Line2;
  showFont(DisplayText);
}


// #######################################################################################################################################################
void loop() {
  // not used
}


// #######################################################################################################################################################
// Write text to the display:
void showFont(String text)
{
  display.fillScreen(GxEPD_WHITE);
  display.setTextColor(GxEPD_BLACK);
  display.setRotation(3);
  display.setCursor(0, 0);
  display.setFont(&FreeMonoBold18pt7b);
  display.println();
  display.println(text);
  display.update();
}
