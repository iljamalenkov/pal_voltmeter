#include <TVout.h>
#include <fontALL.h>


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
}

void loop() {
   int sensorValue = analogRead(A0);
   TV.clear_screen();
   Serial.println(sensorValue,DEC);
   TV.set_cursor(25,30);
   TV.print("V:");
   TV.println(sensorValue*0.03062,4);
   TV.set_cursor(25,40);
   TV.print("T  IN:");
   TV.println(" C");
   TV.set_cursor(25,50);
   TV.print("T OUT:");
   TV.println(" C");
   TV.delay(2500);
  
}


