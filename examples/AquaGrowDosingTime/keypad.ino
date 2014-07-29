// Taking care of some special events.
void keypadEvent(KeypadEvent key){
  int chanel;
  boolean s_Light=false;
    switch (keypad.getState()){
    case PRESSED:
        if (key == '1') {
          lcd.setCursor(15,1); 
          lcd.print(F("M"));
          manualRelay=true;
          lcd.setCursor(12,0); 
          if(digitalRead(relayPIN[0])==HIGH){
            digitalWrite(relayPIN[0],LOW);
            lcd.print(F("X"));
          }else{
            digitalWrite(relayPIN[0],HIGH);
            lcd.print(F("O"));
          }
          Serial.println(digitalRead(relayPIN[0]));
          manualRelay=true;
        }else if (key == '2') {
          lcd.setCursor(15,1); 
          lcd.print(F("M"));
          manualRelay=true;
          lcd.setCursor(13,0); 
          if(digitalRead(relayPIN[1])==HIGH){
            digitalWrite(relayPIN[1],LOW);
            lcd.print(F("X"));
          }else{
            digitalWrite(relayPIN[1],HIGH);
            lcd.print(F("0"));
          }
          Serial.println(digitalRead(relayPIN[1]));
          manualRelay=true;
        }else if (key == '3') {
          lcd.setCursor(15,1); 
          lcd.print(F("M"));
          manualRelay=true;
          lcd.setCursor(14,0); 
          if(digitalRead(relayPIN[2])==HIGH){
            digitalWrite(relayPIN[2],LOW);
            lcd.print(F("X"));
          }else{
            digitalWrite(relayPIN[2],HIGH);
            lcd.print(F("0"));
          }
          Serial.println(digitalRead(relayPIN[2]));
          manualRelay=true;
        }else if (key == '4') {
          lcd.setCursor(15,1); 
          lcd.print(F("M"));
          manualRelay=true;
          lcd.setCursor(15,0); 
          if(digitalRead(relayPIN[3])==HIGH){
            digitalWrite(relayPIN[3],LOW);
            lcd.print(F("X"));
          }else{
            digitalWrite(relayPIN[3],HIGH);
            lcd.print(F("0"));
          }
          Serial.println(digitalRead(relayPIN[3]));
        }else if (key == '5') {
        }else if (key == '6') {
        }else if (key == '7') {
        }else if (key == '8') {
        }else if (key == '9') {
          manualRelay=false;
          lcd.setCursor(15,1); 
          lcd.print(F("A"));
        }else if (key == 'A') {
          t.pulse(dosingPins[0],60000 / dosingMlMin[0], LOW);
//      Serial.print(F("DOSINGA"));
//      Serial.println(key);
          writeLCD(0,1);
        }else if (key == 'B') {
          t.pulse(dosingPins[1],60000 / dosingMlMin[1], LOW);
          writeLCD(1,1);
        }else if (key == 'C') {
          t.pulse(dosingPins[2],60000 / dosingMlMin[2], LOW);
          writeLCD(2,1);
        }else if (key == 'D') {
          t.pulse(dosingPins[3],60000 / dosingMlMin[3], LOW);
          writeLCD(3,1);
        }else if (key == '*' && PUMPCOUNTS>4) {
          t.pulse(dosingPins[4],60000 / dosingMlMin[4], LOW);
          writeLCD(4,1);
        }else if (key == '#' && PUMPCOUNTS>5) {
          t.pulse(dosingPins[5],60000 / dosingMlMin[5], LOW);
          writeLCD(5,1);
        }
        break;
        
        
    case HOLD:
      if (key == 'A') {
          EEPROM_writeAnything(100, dose_val);
        }else if (key == 'B') {
          EEPROM_writeAnything(102, dose_val);
        }else if (key == 'C') {
          EEPROM_writeAnything(104, dose_val);
        }else if (key == 'D') {
          EEPROM_writeAnything(106, dose_val);
        }else if (key == '*') {
          EEPROM_writeAnything(108, dose_val);
        }else if (key == '#') {
          EEPROM_writeAnything(110, dose_val);
        }
        break;
    } 
}

void switch_holdKey(char* key){
  if(strcmp(key,"A")==0 || strcmp(key,"B")==0 || strcmp(key,"C")==0 || strcmp(key,"D")==0 || strcmp(key,"#")==0 || strcmp(key,"*")==0)return;
  
}
