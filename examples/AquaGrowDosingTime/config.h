#define PUMPCOUNTS 4      // Number Pumps
#define RELAYCHANNELS 4
#define RELAYTIMES 6
#define KEYPADI2C 0x20
#define LCD_ADR 0x27


  // PIN MAPPING NICHT ÄNDERN!!!
  #define RELAY1 2
  #define RELAY2 3
  #define RELAY3 4
  #define RELAY4 5
  #define DOSE4 9      // Dosierpumpe 
  #define DOSE3 10      // Dosierpumpe 
  #define DOSE2 11     // Dosierpumpe 
  #define DOSE1 12     // Dosierpumpe 

// Größe Vorratsflaschen Dünger in ml
const int dose_val = 100;

// Neu zuordnung der Pins für Dosierung
const byte dosingPins[]={DOSE1,DOSE2,DOSE3,DOSE4};
// Milliliter per minute in Reihenfolge wie Pumpen oben Achtung Maximum 255ml/Minute
const byte dosingMlMin[]={60,60,60,60};

// Pumpen Einstellungen
// Uhrzeit, Aktive, Name, Pin Adresse (von array oben 0 ist erste Pumpe "Dose1"), Status (ignorieren, nur wichtig für Programm), Milliliter pro Dosierungconst 
PUMP dosing[] = {  
{get_ts(10,0,0),1,"D1",0,5},
{get_ts(11,0,0),1,"D2",1,6},
{get_ts(11,25,0),0,"D3",2,3},
{get_ts(11,26,0),0,"D4",3,3},
//{get_ts(11,23,0),0,"D3",2,3},
//{get_ts(11,28,0),0,"D1",0,5},
};

// Wird verwendet um zu sehen ob schon dosiert wurde. Nicht Ändern!!!
boolean dosingState[PUMPCOUNTS];

const byte relayPIN[]= {RELAY1,RELAY2,RELAY3,RELAY4};
RELAY relays[RELAYCHANNELS][RELAYTIMES] = { 
  {{get_ts(0,0,0),1},{get_ts(17,10,0),0},{get_ts(17,15,0),1},{get_ts(17,20,0),0},{get_ts(17,25,0),1},{get_ts(17,30,0),0}},
  {{get_ts(0,0,0),0},{get_ts(10,0,0),1},{get_ts(11,30,0),0},{get_ts(19,0,0),1},{get_ts(20,0,0),0},{get_ts(21,30,0),0}},
  {{get_ts(0,0,0),0},{get_ts(10,0,0),1},{get_ts(11,30,0),0},{get_ts(19,0,0),1},{get_ts(20,0,0),0},{get_ts(21,30,0),0}},
  {{get_ts(0,0,0),0},{get_ts(10,0,0),1},{get_ts(11,30,0),0},{get_ts(19,0,0),1},{get_ts(20,0,0),0},{get_ts(21,30,0),0}}
};

