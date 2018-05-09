 

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

 
 
 
byte s,x,y,w,h,c;
void setup()   {                
  Serial.begin(2000000);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3D (for the 128x64)
  pinMode(13,OUTPUT);
  display.clearDisplay();
 
  display.display();
}
void loop() {
   
  if (Serial.available()){
    
    s = (byte)Serial.read();
    
    if (s=='p'){
      x= Serial.parseInt();
      y= Serial.parseInt();
      c= Serial.parseInt();
      display.drawPixel(x,y,c);
     
      Serial.print(x);
      Serial.print(' ');
      Serial.print(y);
      Serial.print(' ');
      Serial.print(c);
      Serial.print('\n');
    }
    if (s=='r'){
      x= Serial.parseInt();
      y= Serial.parseInt();
      w= Serial.parseInt();
      h= Serial.parseInt();
      c= Serial.parseInt();

       for (int i=y;i<h;i++)
          display.drawFastHLine(x,i,w,c);
    }
    if (s=='d'){
      display.display();
    }
  }
  
}

 
