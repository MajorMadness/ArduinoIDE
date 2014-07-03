#include <Wire.h>
#include <RTClib.h>
RTC_DS1307 rtc;
unsigned long last_print = 0;
void setup() {

  
  Serial.begin(9600);    // Ausgabe am PC
  
  Wire.begin();           // Wire must be started!
  rtc.begin();
//  delay(2000);
//  rtc.adjust(2014,1,23,23,57,0);
}

void loop() {
  rtc.now();
  if (millis() - last_print > 1000) {
    last_print = millis();
  Serial.println(retTime());
    }      
}
String retTime(){
//  Serial.println(rtc.daystamp);
  uint32_t t = rtc.daystamp;
//  Serial.println(t);
 int ss = t % 60;
//  Serial.println(ss);
    t /= 60;
 int   mm = t % 60;
//  Serial.println(mm);
    t /= 60;
 int   hh = t % 24;
//  Serial.println(hh);

  String sReturn;
  
    sReturn = "";
    sReturn += hh;
    sReturn += ":";
  if (mm < 10) {      // correct minute if necessary
    sReturn += "0";
    sReturn += mm;
  }else{
    sReturn += mm;
  }
    sReturn += ":";
  if (ss < 10) {      // correct second if necessary
    sReturn += "0";
    sReturn += ss;
  }else{
    sReturn += ss;
  }
  return sReturn;
}
