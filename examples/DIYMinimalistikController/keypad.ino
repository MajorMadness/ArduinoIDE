// Taking care of some special events.
void keypadEvent(KeypadEvent key){
  byte chanel;
    switch (keypad.getState()){
    case PRESSED:
//      Serial.print(F("keypressed"));
//      Serial.println(key);
        if (key == 'A') {
          t.pulse(dosing[0].pinAddr,60000 / dosing[0].mlperminute, LOW);
//      Serial.print(F("DOSINGA"));
//      Serial.println(key);
          writeLCD(0,1);
        }else if (key == 'B') {
          t.pulse(dosing[1].pinAddr,60000 / dosing[1].mlperminute, LOW);
          writeLCD(1,1);
        }else if (key == 'C') {
          t.pulse(dosing[2].pinAddr,60000 / dosing[2].mlperminute, LOW);
          writeLCD(2,1);
        }else if (key == 'D') {
          t.pulse(dosing[3].pinAddr,60000 / dosing[3].mlperminute, LOW);
          writeLCD(3,1);
        }else if (key == '*') {
          t.pulse(dosing[4].pinAddr,60000 / dosing[3].mlperminute, LOW);
          writeLCD(4,1);
        }else if (key == '#') {
          t.pulse(dosing[5].pinAddr,60000 / dosing[3].mlperminute, LOW);
          writeLCD(5,1);
        }else if (key == '9') {
            manualLight=false;
        }else{
          char keyB = keypad.getKey();
          chanel = key-'1';
//      Serial.print(F("chanel"));
//      Serial.println(chanel);
          if(dimming[chanel].level==1){
            dimming[chanel].level=0;
            ledDriver.setLEDOff(chanel*2);
            ledDriver.setLEDOff(chanel*2+1);
            manualLight=true;
          }else if(dimming[chanel].level==0){
            dimming[chanel].level=1;
            ledDriver.setLEDOn(chanel*2);
            ledDriver.setLEDOn(chanel*2+1);
            manualLight=true;
          } 
        }
        break;
        
        
    case HOLD:
//      Serial.print(F("keyHOLD"));
//      Serial.println(key);
      if (key == 'A') {
          EEPROM_writeAnything(100, dose_val);
        }else if (key == 'B') {
          EEPROM_writeAnything(102, dose_val);
        }else if (key == 'C') {
          EEPROM_writeAnything(104, dose_val);
        }else if (key == 'D') {
          EEPROM_writeAnything(106, dose_val);
 /*       }else if (key == '*') {
          EEPROM_writeAnything(108, dose_val);
        }else if (key == '#') {
          EEPROM_writeAnything(110, dose_val);
 */       }
        break;
    }

}

void switch_holdKey(char k1){
//      Serial.print("-");
//      Serial.print(key);
//      Serial.println("-");
//      char k1 = keypad.getKey();
      Serial.println(k1);
//      if(k1==65||k1==66||k1==67||k1==68||k1=='#'||k1=='*')return;
//  if(strcmp(key,"A")==0 || strcmp(key,"B")==0 || strcmp(key,"C")==0 || strcmp(key,"D")==0 || strcmp(key,"#")==0 || strcmp(key,"*")==0)return;
  
      Serial.print(F("keySWITCH2"));
      Serial.println(k1);
  int k = k1-'1';
  //k=k-1;
  int dir = (int)dimming[k].level;
  int level = (int)dimming[k].time;
  
  if(dir==1){
    level=level + 10;
  }else if(dir==0){
    level=level - 10;
  }
  if(level>=4090){
    dir=0;
  }else if(level<=5){
    dir=1;
  }
    dimming[k].level=dir;
    dimming[k].time=level;
//    Serial.print(int(100-float(level/40.95)));
//    Serial.println(F("%"));
    setLED(k,level);
}
