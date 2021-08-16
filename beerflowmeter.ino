#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>
#include <Adafruit_NeoPixel.h>
#include <Fonts/TomThumb.h>   
#include <SPI.h>
#include <MFRC522.h>
#include <EEPROM.h>

#define PIN 2 // LED DISPLAY
#define RST_PIN         9           // Configurable, see typical pin layout above
#define SS_PIN          10          // Configurable, see typical pin layout above


MFRC522 mfrc522(SS_PIN);   // Create MFRC522 instance.
MFRC522::MIFARE_Key key;

Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(8, 8, 3, 3, PIN,NEO_TILE_PROGRESSIVE+NEO_TILE_BOTTOM, NEO_GRB + NEO_KHZ800);

const uint16_t colors[] = { matrix.Color(255, 0, 0), matrix.Color(255, 255, 0), matrix.Color(255, 51, 51), matrix.Color(255, 255, 0),
matrix.Color(150,150,150),matrix.Color(255,165,0) ,matrix.Color(240,230,140), matrix.Color(237, 239, 81) };

volatile double waterFlow;
unsigned long start_time;
unsigned long end_time;
int live_display_session_time = 45000;
int gotat;
int FillGlassArray[] = {14,13,12,11,10,9,8,7,6,5,4,3,2,1};  
int x = 1;
int y = 0;
int eeprom_address = 0;
int eeprom_value = 0;
int pushButton = 15;

bool showGlass = false;
bool draftStarted = false;
double barrel_status;

void showDefaultScreen() {
  /*matrix.begin();
  matrix.setFont();
  matrix.fillScreen(0);
  matrix.setCursor(0, 0);
  matrix.setTextWrap(true);  
  matrix.setTextColor(colors[5]);
  //matrix.setFont(&TomThumb);
  matrix.print(F("PRHSBeer"));
  matrix.show();  
  matrix.setFont();*/
  matrix.begin();
          matrix.fillScreen(0);
          matrix.setCursor(0, 0);
          matrix.setTextWrap(true);  
          matrix.setTextColor(colors[5]);
          matrix.print(F("Beer"));
          matrix.setTextColor(colors[4]); // set millilitres color
          matrix.print(waterFlow);
          // display glasses number and small glass
          matrix.setTextColor(colors[5]); // set gotat count color
          matrix.setCursor(0,16);
          matrix.print(eeprom_value); // print glasses number          
          smallGlass();
          matrix.show();  
          matrix.setFont();
 
}

void pulse()   //measure the quantity of square wave 
{ 
   if(start_time < 10) {
      start_time = millis();
      draftStarted = true;
    }
   waterFlow += 1.0 / 3700.0; //5880 origjinali, 4880 verzioni qe ka punu me Due edhe ESP  
   Serial.println("exing...");
} 

void smallGlass(){
matrix.drawLine(14, 22, 17, 22, colors[4]); // bottom line
matrix.drawLine(13, 21, 13, 16, colors[4]); // left border 
matrix.drawLine(18, 21, 18, 16, colors[4]); // right border
// fill with regular beer
matrix.drawLine(14, 21, 17, 21, colors[5]);
matrix.drawLine(14, 20, 17, 20, colors[5]);
matrix.drawLine(14, 19, 17, 19, colors[5]);
matrix.drawLine(14, 18, 17, 18, colors[5]);
//fill with foam
matrix.drawLine(14, 17, 17, 17, colors[6]);
matrix.drawLine(14, 16, 17, 16, colors[6]);

// draw handle
matrix.drawLine(18, 17, 19, 17, colors[4]);
matrix.drawLine(18, 19, 19, 19, colors[4]);
matrix.drawLine(20, 19, 20, 17, colors[4]);
}


//void(* resetFunc) (void) = 0; //declare reset function @ address 0

void setup() {
  pinMode(pushButton, INPUT);
  start_time = millis();
  // put your setup code here, to run once:
  Serial.begin(115200);
  //EEPROM.put(eeprom_address,eeprom_value); //- RESET GOTAT COUNTER BY UNCOMMENTING HERE
  //Serial.println('Started ...');
  //EEPROM.begin(512);
  EEPROM.get(eeprom_address,eeprom_value);
  //EEPROM.commit(); 
  waterFlow = 0;
  attachInterrupt(digitalPinToInterrupt(3), pulse, RISING);
  matrix.begin();
  matrix.setTextWrap(false);
  matrix.setBrightness(10);
  matrix.setTextColor(colors[5]);
  showDefaultScreen();
  // display glasses number and small glass
  matrix.setCursor(0,16);
  //matrix.setTextWrap(false);
  matrix.print(eeprom_value); // print glasses number
  matrix.setFont();
  smallGlass();
  matrix.show();
}

void loop() {
  // put your main code here, to run repeatedly:
   if(waterFlow > 0.33) {
    waterFlow = 0;
    draftStarted = false;
    start_time=0;    
    eeprom_value = eeprom_value + 1;
    EEPROM.put(eeprom_address,eeprom_value);
   }
    // display glasses number and small glass
    showDefaultScreen();
    matrix.setCursor(0,16);
    if(eeprom_value == -1) {
      eeprom_value = 0;
      }
    
    matrix.print(eeprom_value); // print glasses number
    matrix.setFont();
    smallGlass();
    matrix.show();     



  Serial.println(eeprom_value);
  Serial.println(waterFlow);
 
}
