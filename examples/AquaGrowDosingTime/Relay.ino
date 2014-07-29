void setRelay(){
  for( byte i=0;i <  RELAYCHANNELS; i++){
    boolean rState = findState(i);
    
    if(digitalRead(relayPIN[i])!=rState){
      digitalWrite(relayPIN[i],rState);
      lcd.setCursor(12+i,0); 
      if(rState==1){
        lcd.print(F("O"));
      }else{
        lcd.print(F("X")); 
      } 
    }
  }
}

boolean findState(byte cNum){
  int curIndex=0;
  
  for(byte n=0;n<RELAYTIMES;n++){
    if(relays[cNum][n].time < rtc.daystamp){
      curIndex=n;
    }
  }
  
  return relays[cNum][curIndex].state;
}
