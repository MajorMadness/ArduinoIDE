void setLight(){
    for( byte i=0;i <  LIGHT_CHANEL; i++){
        uint16_t c_PWM = PWM_Licht(i);
        
        if(temperatur>float(cTemp)){
          c_PWM= 4095;
        }          
        setLED(i,uint16_t(c_PWM));
    }
}


void setLED(uint8_t channel, uint16_t Value){
          
    word n_PWM;  
	Value=4095-Value;
    n_PWM = pgm_read_word(&pwmtable[Value]);
    if (n_PWM<=0)	{
        ledDriver.setLEDOn(channel*2);
        ledDriver.setLEDOn(channel*2+1);
    } else if (n_PWM>=4095) {
        ledDriver.setLEDOff(channel*2);
        ledDriver.setLEDOff(channel*2+1);
    } else {
        ledDriver.writeLED(channel*2,0, n_PWM);
        ledDriver.writeLED(channel*2+1,0, n_PWM);
    }
    printLightVal(channel, n_PWM);
}

int PWM_Licht(int lightIndex){
  
  int curIndex=0;
//  String lightTime;
  
  for(byte n=0;n<LIGHT_VALUES;n++){
    if(light_channels[lightIndex][n].time < rtc.daystamp){
      curIndex=n;
    }
  }
  
  long Max,Min,pwm=4095;
  float dimTime,f,p;
  float pastSeconds;
  uint32_t Start,Ende;
  byte oMin,oMax;
  
    if(curIndex ==(LIGHT_VALUES-1) ){
        Start = light_channels[lightIndex][7].time;
        Ende = light_channels[lightIndex][0].time;
        oMin = light_channels[lightIndex][7].level;
        oMax = light_channels[lightIndex][0].level;
        
        pastSeconds = rtc.daystamp-Start+0.5;    // vergangene Sekunden ~1616Sek ~ 27min
        dimTime= get_ts(24,0,0) - Start + Ende;
      
    }else if(curIndex>=1 || light_channels[lightIndex][0].time < rtc.daystamp){
        Start = light_channels[lightIndex][curIndex].time;
        Ende = light_channels[lightIndex][curIndex+1].time;
        oMin = light_channels[lightIndex][curIndex].level;
        oMax = light_channels[lightIndex][curIndex+1].level;
        
        pastSeconds = rtc.daystamp-Start+0.5;    // vergangene Sekunden ~1616Sek ~ 27min
        dimTime=Ende - Start;
    }else{
		Start = light_channels[lightIndex][7].time;
		Ende = light_channels[lightIndex][0].time;
		oMin = light_channels[lightIndex][7].level;
		oMax = light_channels[lightIndex][0].level;

		pastSeconds = get_ts(24,0,0)-Start + rtc.daystamp+0.5; 
		dimTime= get_ts(24,0,0)-Start + Ende;
	}

	Min=(pwm- (pwm*oMin/100));  // 0%=4095-(4095/100*0) = 
	Max=(pwm- (pwm*oMax/100)); // 80% von 4095-(4095/100*80) sind 819

	if(Min==Max){
		return Min;
	}  
	f= dimTime/(Max-Min);    // 1800/2800=0,64
	p = pastSeconds/f;    // 1616 / 0,64=2525   
	pwm=Min+p;

    return pwm;    // Im Nofall ausschalten...
}
