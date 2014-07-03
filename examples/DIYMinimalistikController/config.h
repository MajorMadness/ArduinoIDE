#define PUMPCOUNTS 4      // Number Pumps
#define LIGHT_CHANEL 8    
#define LIGHT_VALUES 8
#define KEYPADI2C 0x20
#define LCD_ADR 0x27
#define LED_DRV 0x40


  // PIN MAPPING NICHT ÄNDERN!!!
// Pin Mapping für Nano
  #define PIN_TEMP 4  // Temperatur
  #define DOSE1 6      // Dosierpumpe 
  #define DOSE2 7      // Dosierpumpe 
  #define DOSE3 8      // Dosierpumpe 
  #define DOSE4 9      // Dosierpumpe 
  #define DOSE5 10      // PWM PIN    // Dosierpumpe 
  #define DOSE6 12  // Dosierpumpe 
  #define PIN_PWM 11  // PWM PIN    // Lüfter

// Temperatur ab Wann Lüfter an gehen (Ganzzahl)
const int coolingTemp = 40;
const float cTemp = 60;
// Geschwindigkeit der Lüfter -> 0 Aus, 255 Maximale Geschwindigkeit
const int pwmValue = 255;
// Größe Vorratsflaschen Dünger in ml
const int dose_val = 100;

// Neu zuordnung der Pins für Dosierung
const int dosingPins[]={DOSE1,DOSE2,DOSE3,DOSE4};

// Pumpen Einstellungen
// Uhrzeit, Aktive, Name, Pin Adresse (von array oben), Status (ignorieren, nur wichtig für Programm), Milliliter per minute, Milliliter pro Dosierungconst 
PUMP dosing[] = {  
{get_ts(10,0,0),1,"D1",dosingPins[0],60,5},
{get_ts(11,0,0),1,"D2",dosingPins[1],60,6},
{get_ts(11,25,0),0,"D3",dosingPins[2],60,3},
{get_ts(11,26,0),0,"D4",dosingPins[3],60,3},
//{get_ts(11,23,0),0,"D3",dosingPins[2],60,3},
//{get_ts(11,28,0),0,"D1",dosingPins[0],60,5},
};

boolean dosingState[PUMPCOUNTS];

// Licht Einstellungen immer paar aus Uhrzeit und % angabe. Je reihe Zahl von LIGHT_VALUES, so viele Reihen wie in LIGHT_CHANEL
LIGHT light_channels[LIGHT_CHANEL][LIGHT_VALUES] ={
        {{get_ts(0,1,0),0},{get_ts(10,0,0),0},{get_ts(11,30,0),100},{get_ts(19,0,0),100},{get_ts(20,0,0),0},{get_ts(21,30,0),0},{get_ts(23,30,0),0},{get_ts(23,32,0),0}},
        {{get_ts(0,1,0),0},{get_ts(9,0,0),0},{get_ts(11,0,0),100},{get_ts(19,0,0),100},{get_ts(21,0,0),0},{get_ts(21,30,0),0},{get_ts(23,30,0),0},{get_ts(23,32,0),0}},
        {{get_ts(0,1,0),0},{get_ts(10,0,0),0},{get_ts(11,30,0),100},{get_ts(19,0,0),100},{get_ts(20,0,0),0},{get_ts(21,30,0),0},{get_ts(23,30,0),0},{get_ts(23,32,0),0}},
        {{get_ts(0,1,0),0},{get_ts(9,0,0),0},{get_ts(11,0,0),100},{get_ts(19,0,0),100},{get_ts(21,0,0),0},{get_ts(21,30,0),0},{get_ts(23,30,0),0},{get_ts(23,32,0),0}},
        {{get_ts(10,30,0),0},{get_ts(11,30,0),0},{get_ts(12,30,0),0},{get_ts(13,30,0),0},{get_ts(14,30,0),0},{get_ts(15,30,0),0},{get_ts(16,30,0),0},{get_ts(17,30,0),0}},
        {{get_ts(10,30,0),0},{get_ts(11,30,0),0},{get_ts(12,30,0),0},{get_ts(13,30,0),0},{get_ts(14,30,0),0},{get_ts(15,30,0),0},{get_ts(16,30,0),0},{get_ts(17,30,0),0}},
        {{get_ts(0,1,0),0},{get_ts(8,30,0),0},{get_ts(9,0,0),20},{get_ts(9,30,0),0},{get_ts(20,0,0),0},{get_ts(20,30,0),70},{get_ts(21,0,0),0},{get_ts(23,30,0),0}}, //Rot
        {{get_ts(8,30,0),5},{get_ts(9,30,0),0},{get_ts(20,30,0),0},{get_ts(21,0,0),40},{get_ts(21,30,0),20},{get_ts(21,50,0),10},{get_ts(21,55,20),10},{get_ts(23,55,20),5}}  // Blau
      };

// Dies nicht ändern!!!
LIGHT dimming[LIGHT_CHANEL] ={{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}};
