#include <UTFT.h>
#include <URTouch.h>
#include <Arduino.h>
#include<stdlib.h>
#include <Eeprom24C32_64.h>

UTFT myGLCD(SSD1963_480,38,39,40,41);
URTouch  myTouch( 6, 5, 4, 3, 2);

//Schriften Einbinden
extern uint8_t SmallFont[];
extern uint8_t hallfetica_normal[];
extern unsigned short icom[];

//Timer
unsigned long startMillis; 
unsigned long currentMillis;
const unsigned long period = 250;//refreshzeit Nummerikanzeigen+Graphen in millisekunden

unsigned long startpeakMillis1; 
unsigned long currentpeakMillis1;
const unsigned long peakperiod1 = 100;//refreshzeit Nummerikanzeigen+Graphen in millisekunden

unsigned long startpeakMillis2; 
unsigned long currentpeakMillis2;
const unsigned long peakperiod2 = 100;//refreshzeit Nummerikanzeigen+Graphen in millisekunden

unsigned long startdebounceMillis; 
unsigned long currentdebounceMillis;
const unsigned long debounceperiod = 250;//refreshzeit Nummerikanzeigen+Graphen in millisekunden

//EEPROM///
#define EEPROM_ADDRESS 0x57
static Eeprom24C32_64 eeprom(EEPROM_ADDRESS);
////////////////

//Touch
int x,y;

  
byte rgbtable_big[128][3]{
  {0,255,0},{0,255,0},{0,255,0},{0,255,0},{0,255,0},{0,255,0},{0,255,0},{0,255,0},{0,255,0},{0,255,0},{0,255,0},{0,255,0},{0,255,0},{0,255,0},{0,255,0},{0,255,0},{0,255,0},{0,255,0},{0,255,0},{0,255,0},{0,255,0},{0,255,0},{0,255,0},{0,255,0},
  {0,255,0},{0,255,0},{0,255,0},{0,255,0},{0,255,0},{0,255,0},{0,255,0},{0,255,0},{0,255,0},{0,255,0},{0,255,0},{0,255,0},{0,255,0},{0,255,0},{0,255,0},{0,255,0},{0,255,0},{0,255,0},{0,255,0},{0,255,0},{0,255,0},{0,255,0},{0,255,0},{0,255,0},//grün54,24
  {16,255,0},
  {16,255,0},
  {32,255,0},
  {32,255,0},
  {48,255,0},
  {48,255,0},
  {64,255,0},
  {64,255,0},
  {80,255,0},
  {80,255,0},
  {96,255,0},
  {96,255,0},
  {112,255,0},
  {112,255,0},
  {128,255,0},
  {128,255,0},
  {144,255,0},
  {144,255,0},
  {160,255,0},
  {160,255,0},
  {176,255,0},
  {176,255,0},
  {192,255,0},
  {192,255,0},
  {208,255,0},
  {208,255,0},
  {224,255,0},
  {224,255,0},
  {240,255,0},
  {240,255,0},
  {255,255,0},
  {255,255,0},
  {255,240,0},
  {255,240,0},
  {255,224,0},
  {255,224,0},
  {255,208,0},
  {255,208,0},
  {255,192,0},
  {255,192,0},
  {255,176,0},
  {255,176,0},
  {255,160,0},
  {255,160,0},
  {255,144,0},
  {255,144,0},
  {255,128,0},
  {255,128,0},
  {255,112,0},
  {255,112,0},
  {255,96,0},
  {255,96,0},
  {255,80,0},
  {255,80,0},
  {255,64,0},
  {255,64,0},
  {255,48,0},
  {255,48,0},
  {255,32,0},
  {255,32,0},
  {255,16,0},
  {255,16,0},
  {255,0,0},{255,0,0},{255,0,0},{255,0,0},{255,0,0},{255,0,0},{255,0,0},{255,0,0},{255,0,0},
  {255,0,0},{255,0,0},{255,0,0},{255,0,0},{255,0,0},{255,0,0},{255,0,0},{255,0,0},{255,0,0},};


   //Variablen

  bool tx_state;
  bool tx_state_old;
  bool txl_state;
  bool txl_state_old;
  bool rx_tx;
  bool refresh_tx_disp;

  bool pwr_on;
  bool pwr_on_stat;
  bool touch_press;

  bool tune;
  bool tune_wait;
  bool tune_state;
  bool tune_state_old;
  bool refresh_tune_disp;

  bool fault_state;
  bool fault_state_old;
  bool refresh_fault_disp; 

  //*****Meter+++++++++
  byte me1;
  byte me1_graph;    
  byte me1_graph_old;


  
  byte me2;
  byte me2_graph;
  byte me2_graph_old;  
    
  byte ic_bnd;
  byte ya_bnd;
  byte ic_ya;
  byte band;
  byte band_old;
  byte automode;
  //***Meter***
  byte ME1;
  byte MS1;
  byte ME2;
  byte MS2;
  byte me1_multi;
  byte me2_multi;
  byte Meter_old;

int operate_mode;
int options_mode;

  //**********Pin-Zuweisung****************

const byte txl_in = 11;
const byte tune_wait_in = 12;
const byte fault_in = 13;
  
const byte prol_sw = 42;
const byte temp_sw = 43;

const byte tx_in = 44;
const byte tx_out = 45;

const byte ic_d = 46;
const byte pson = 47;
const byte ic_c = 48;
const byte ic_b = 49;

const byte ic_bnd_v = 54;
const byte ic_bnd_ref = 55;

const byte me1_v = 56;
const byte me2_v = 57;

const byte swr_sw = 58;
const byte vc_sw = 59;
const byte po_sw = 60;

//const byte reserve = 61;

const byte a_y = 62;
const byte b_y = 63;
const byte c_y = 64;
const byte d_y = 65;
bool a;
bool b;
bool c;
bool d;

const byte band_v = 66;
const byte band_ref = 67;

const byte lin = 69;
const byte tun = 68;
 

void setup(){

startMillis = millis();  //initial start time
startpeakMillis1 = millis();  
startpeakMillis2 = millis();  
//Meters setup

pinMode(prol_sw,OUTPUT);
digitalWrite(prol_sw,LOW);

pinMode(temp_sw,OUTPUT);
digitalWrite(temp_sw,LOW);


pinMode(swr_sw,OUTPUT);
digitalWrite(swr_sw,LOW);


pinMode(vc_sw,OUTPUT);
digitalWrite(vc_sw,LOW);

pinMode(po_sw,OUTPUT);
digitalWrite(po_sw,LOW);

//********************************

pinMode(txl_in,INPUT);
digitalWrite(txl_in,INPUT_PULLUP);

pinMode(tune_wait_in,INPUT);
digitalWrite(tune_wait_in,INPUT_PULLUP);

pinMode(fault_in,INPUT);
digitalWrite(fault_in,INPUT_PULLUP);

pinMode(lin,OUTPUT);   //lin
digitalWrite(lin,LOW);

pinMode(tun,OUTPUT);   //tun
digitalWrite(tun,LOW);

pinMode(tx_in,INPUT_PULLUP);   //TX IN

pinMode(tx_out,OUTPUT);   //TX OUT
digitalWrite(tx_out,LOW);

pinMode(pson,OUTPUT);   //PS ON 
digitalWrite(pson,LOW);

pinMode(ic_d,INPUT_PULLUP);   //Bandata from IC-4KL
pinMode(ic_c,INPUT_PULLUP);   //Bandata from IC-4KL
pinMode(ic_b,INPUT_PULLUP);   //Bandata from IC-4KL

pinMode(a_y,INPUT_PULLUP);   //Band A
pinMode(b_y,INPUT_PULLUP);   //Band B
pinMode(c_y,INPUT_PULLUP);   //Band C
pinMode(d_y,INPUT_PULLUP);   //Band D

pinMode(band_ref,OUTPUT);   //Band reference voltage to IC-4KL
analogWrite(band_ref,255);
pinMode(band_v,OUTPUT);     //Band voltage to IC-4KL
analogWrite(band_v,50);

   //LCD Start
      myGLCD.InitLCD();
      myGLCD.clrScr();
      myGLCD.setBackColor(VGA_TRANSPARENT);
      myGLCD.drawBitmap(80,55,320,162,icom);
      myGLCD.setFont(hallfetica_normal);
      myGLCD.setColor(VGA_GRAY);
      myGLCD.print("IC-4KL",320,215);
      myGLCD.setFont(SmallFont);    
      myGLCD.print("by dj1yr",415,245);
      myGLCD.print("built on " __DATE__ " at " __TIME__,225,260);
      delay(2000);
   //Touch Start   
      myTouch.InitTouch();
      myTouch.setPrecision(PREC_MEDIUM);

//start Serial
Serial.begin(19200);

////EEPROM_32KB/////////////
   eeprom.initialize();

}//END OF SETUP
