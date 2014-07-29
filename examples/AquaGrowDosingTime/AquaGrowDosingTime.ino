#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <RTClib.h>
#include <Timer.h>
#include <MemoryFree.h>
#include <Keypad.h>  
#include <Keypad_I2C.h>  
#include <EEPROM.h>
#include "writeAnything.h" 
#include "structs.h"
#include "config.h"


Timer t;
RTC_DS1307 rtc;
LiquidCrystal_I2C lcd(LCD_ADR,2,1,0,4,5,6,7,3,POSITIVE);   // Set the LCD I2C address

boolean pumpReset=false;


boolean manualRelay=false;
unsigned long last_print = 0;
String inputString = "";
boolean stringComplete = false;


const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
//define the cymbols on the buttons of the keypads
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {0, 1, 2, 3}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {4, 5, 6, 7}; //connect to the column pinouts of the keypad

char holdKey;
unsigned long t_hold;

//initialize an instance of class NewKeypad
Keypad_I2C keypad = Keypad_I2C( makeKeymap(keys), rowPins, colPins, ROWS, COLS, KEYPADI2C );


void setup() {

  Wire.begin();
  rtc.begin();
  keypad.begin( );  
  keypad.addEventListener(keypadEvent); // Add an event listener for this keypad
  
  
  Serial.begin(9600);

  lcd.begin(16, 2);

  for (int n=0;n<=(sizeof(dosingPins)/sizeof(DOSE1));n++){
    pinMode(dosingPins[n], OUTPUT);
  }
  for (int i=0;i<=(sizeof(relayPIN)/sizeof(RELAY1));i++){
    pinMode(relayPIN[i], OUTPUT);
  }
  inputString.reserve(20);
  
}

void loop() {
  rtc.now();
  t.update();
  char key = keypad.getKey();
  
  
    if(!manualRelay){
      setRelay();
    }
  // print the string when a newline arrives:
  if (stringComplete) {
    serialHandler(inputString);
    inputString = "";
    stringComplete = false;
  }

  if (millis() - last_print > 1000) {
    last_print = millis();
    
    Serial.println(retTime());
//    Serial.println(freeMemory());
    
    setDosing();
    
    lcd.setCursor(0,0);  
    lcd.print(retTime());
    lcd.setCursor(9,0);  

  }            
}

