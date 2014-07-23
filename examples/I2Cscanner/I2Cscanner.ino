
#include <Wire.h>


void setup()
{
  Wire.begin();

  Serial.begin(9600);
  Serial.println("\nI2C Scanner");
}


void loop()
{
  byte error, address;
  int nDevices;

  Serial.println("Scanning...");

  nDevices = 0;
  for(address = 1; address < 127; address++ ) 
  {
    // The i2c_scanner uses the return value of
    // the Write.endTransmisstion to see if
    // a device did acknowledge to the address.
    Wire.beginTransmission(address);
    error = Wire.endTransmission();

    if (error == 0)
    {	
	  if(address==20){
	    Serial.print("Keypad gefunden Adresse ");
        Serial.print("0x");
        Serial.println(address,HEX);
	  }else if(address==27){
	    Serial.print("LCD gefunden Adresse ");
        Serial.print("0x");
        Serial.println(address,HEX);
	  }else if(address==40){
	    Serial.print("PWM Treiber gefunden Adresse ");
        Serial.print("0x");
        Serial.println(address,HEX);
	  }else if(address==68){
	    Serial.print("RTC gefunden Adresse ");
        Serial.print("0x");
        Serial.println(address,HEX);
	  }else if(address==70){
	    Serial.print("PWM Treiber Broadcast gefunden Adresse ");
        Serial.print("0x");
        Serial.println(address,HEX);
	  }else{
        Serial.print("I2C device gefunden mit Adresse 0x");
      if (address<16) 
        Serial.print("0");

      Serial.println("  !");
      }
      nDevices++;
    }
    else if (error==4) 
    {
      Serial.print("Unknow error at address 0x");
      if (address<16) 
        Serial.print("0");
      Serial.println(address,HEX);
    }    
  }
  if (nDevices == 0)
    Serial.println("No I2C devices found\n");
  else
    Serial.println("done\n");

  delay(5000);           // wait 5 seconds for next scan
}
