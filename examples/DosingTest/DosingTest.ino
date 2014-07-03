
  #define DOSE4 8      // Dosierpumpe 
  #define DOSE3 9      // Dosierpumpe 
  #define DOSE2 10      // PWM PIN    // Dosierpumpe 
  #define DOSE1 11  // Dosierpumpe 
  #define PIN_PWM 12  // PWM PIN    // Lüfter
  
void setup() {       
  Serial.begin(9600);         
  
  pinMode(DOSE1, OUTPUT); 
  pinMode(DOSE2, OUTPUT); 
  pinMode(DOSE3, OUTPUT); 
  pinMode(DOSE4, OUTPUT);     
}

// the loop routine runs over and over again forever:
void loop() {
  digitalWrite(DOSE1, HIGH); 
  Serial.println("Dosierung1");
  delay(5000);
  digitalWrite(DOSE1, LOW);
  delay(2000); 
  digitalWrite(DOSE2, HIGH); 
  Serial.println("Dosierung2");
  delay(5000);
  digitalWrite(DOSE2, LOW);
  delay(2000); 
  digitalWrite(DOSE3, HIGH);
  Serial.println("Dosierung3");
  delay(5000);
  digitalWrite(DOSE3, LOW);
  delay(2000); 
  digitalWrite(DOSE4, HIGH);
  Serial.println("Dosierung4");
  delay(5000);
  digitalWrite(DOSE4, LOW);
  delay(2000); 
  for(int fadeValue = 0 ; fadeValue <= 255; fadeValue +=5) { 
    analogWrite(PIN_PWM, fadeValue);   
  Serial.print("Lüfter ");
  Serial.println(fadeValue);        
    delay(300);                            
  } 
  for(int fadeValue = 255 ; fadeValue >= 0; fadeValue -=5) { 
    analogWrite(PIN_PWM, fadeValue);     
  Serial.print("Lüfter ");
  Serial.println(fadeValue);                 
    delay(300);                            
  } 
}
