#include <RTClib.h>

  #include <MaxMatrix.h>
  #include<stdio.h>
  #include<stdlib.h>
  #include <Wire.h>

  RTC_DS3231 rtc;

  /*
        8x8 LED Matrix MAX7219 Example 01
    by Dejan Nedelkovski, www.HowToMechatronics.com
    Based on the following library:
    GitHub | riyas-org/max7219  https://github.com/riyas-org/max7219
  */

  int DIN = 7;   // DIN pin of MAX7219 module // yellow wire in the picture
  int CLK = 6;   // CLK pin of MAX7219 module  // Blue wire in the picture
  int CS = 5;    // CS pin of MAX7219 module  // Orange wire in the picture
  int maxInUse = 1; 
  MaxMatrix m(DIN, CS, CLK, maxInUse); 
  // Mouli: You can view the characters, as if they are rotated by 90 deg in clockwise direction
  char A[] = {4, 8,
              B01111110,
              B00010001,
              B00010001,
              B01111110,
            };
  char B[] = {4, 8,
              B01111111,
              B01001001,
              B01001001,
              B00110110,
            };
  char smile01[] = {8, 8,
                    B00111100,
                    B01000010,
                    B10010101,
                    B10100001,
                    B10100001,
                    B10010101,
                    B01000010,
                    B00111100
                  };
  char smile02[] = {8, 8,
                    B00111100,
                    B01000010,
                    B10010101,
                    B10010001,
                    B10010001,
                    B10010101,
                    B01000010,
                    B00111100
                  };
  char smile03[] = {8, 8,
                    B00111100,
                    B01000010,
                    B10100101,
                    B10010001,
                    B10010001,
                    B10100101,
                    B01000010,
                    B00111100
                  };
  char num1_A[] = {3,2,
                    B10,
                    B00,
                    B00
                  };
  char num2[] = {3,2,
                    B10,
                    B10,
                    B00
                  };
  char num3[] = {3,2,
                    B11,
                    B00,
                    B00
                  };
  char num4[] = {3,2,
                    B11,
                    B01,
                    B00
                  };
  char num5[] = {3,2,
                    B10,
                    B01,
                    B00
                  };
  char num6[] = {3,2,
                    B11,
                    B10,
                    B00
                  };
  char num7[] = {3,2,
                    B11,
                    B11,
                    B00
                  };
  char num8[] = {3,2,
                    B10,
                    B11,
                    B00
                  };
  char num9[] = {3,2,
                    B01,
                    B10,
                    B00
                  };
  char num0[] = {3,2,
                    B01,
                    B11,
                    B00
                  };
  char num_M[] = {3,2,
                    B10,
                    B00,
                    B00
                  };
  char num_P[] = {3,2,
                    B11,
                    B10,
                    B10
                  };
  char num_HASH[] = {3,2,
                    B01,
                    B01,
                    B11
                  };
  int timeZoneHours = 0;
  int timeZoneMinutes = 25;
  void setup() {
    Serial.begin(9600);
    m.init(); // MAX7219 initialization
    m.setIntensity(8); // initial led matrix intensity, 0-15
    Wire.begin();
    rtc.begin();

  }
  void loop() {
    // Seting the LEDs On or Off at x,y or row,column position
    /*for (int i=0; i<8; i++){
      m.setDot(i,i,true);
      delay(300);
    }*/
    DateTime now = rtc.now();

    int second = now.second();
    int minute = now.minute();
    int hour = now.hour();

    Serial.println(second);
    Serial.println(hour);
    Serial.println(minute);
    int second_0 = second%10;
    int second_1 = second/10;
    int hour_0 = hour%10;
    int hour_1 = hour/10;
    int minute_0 = minute%10;
    int minute_1 = minute/10;

    // Displaying the character at x,y (upper left corner of the character)  
    
    m.writeSprite(0,6, dectobr(hour_1));
    m.writeSprite(0,4, dectobr(hour_0));
    m.writeSprite(0,2, dectobr(minute_1));
    m.writeSprite(0,0, dectobr(minute_0));
    m.writeSprite(5,4, dectobr(second_1));
    m.writeSprite(5,2, dectobr(second_0));
    delay(1000);
  /* for (int i=0; i<8; i++){
      m.shiftLeft(false,false);
      delay(300);
    }*/
   
    m.clear();
  }

  int bcdToDec(int bcdValue) {
    return ((bcdValue / 16) * 10) + (bcdValue % 16);
  }

  char* dectobr(int num){
    if(num==0)
    return num0;
    else if(num==1)
    return num1_A;
    else if(num==2)
    return num2;
    else if(num==3)
    return num3;
    else if(num==4)
    return num4;
    else if(num==5)
    return num5;
    else if(num==6)
    return num6;
    else if(num==7)
    return num7;
    else if(num==8)
    return num8;
    else if(num==9)
    return num9;
  }