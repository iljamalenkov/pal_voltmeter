#include <TVout.h>
#include <fontALL.h>

#include <OneWire.h>
#include <DallasTemperature.h>

// Data wire is plugged into port 2 on the Arduino
#define ONE_WIRE_BUS 2
// Setup a oneWire instance to communicate with any OneWire devices (not just Maxim/Dallas temperature ICs)
OneWire oneWire(ONE_WIRE_BUS);

// Pass our oneWire reference to Dallas Temperature. 
DallasTemperature sensors(&oneWire);
DeviceAddress insideThermometer = { 0x28, 0xC8, 0xD7, 0xC7, 0x2, 0x0, 0x0, 0xDF };

TVout TV;

//int zOff = 150;
//int xOff = 0;
//int yOff = 0;
//int cSize = 50;
//int view_plane = 64;
//float angle = PI/60;


void setup() {
  TV.begin(PAL,120,96);
  TV.select_font(font8x8);
   Serial.begin(9600);
    sensors.begin();
    sensors.setResolution(insideThermometer, 9);

}

void loop() {
  
   sensors.requestTemperatures();
   float tout=sensors.getTempC(insideThermometer);
   int sensorValue = analogRead(A0);
   TV.clear_screen();
   Serial.println(sensorValue,DEC);
   TV.set_cursor(25,30);
   TV.print("V:");
   TV.println(sensorValue*0.03062,4);
   TV.set_cursor(15,40);
   TV.print("T IN:");
   TV.print(tout);
   TV.println(" C");
  // TV.set_cursor(15,50);
  // TV.print("T OUT:");
  // TV.println(" C");
   TV.delay(2500);
  delay (300);
}


