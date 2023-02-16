// 0.0 testiBoardeko programa egokitzen. //// linea hasieran baldinbadu ezabatzeke egongo da eta
//                                       /* artean dagoena */ ezabatzeke egongo da
// momentuz bertsio honetan ez da ezer ezabatu
// 0.1 lehengo bertsioko zati asko jada eliminaturik
// 1.1 lehengo bertsioko Structure mantentzen da
// 1.2 Structure kendu eta arrayak bakarrik erabiltzen dira
// 1.4 Hurekin saiatzen baina ez dabil
// 1.5 ni saiatzen
// 1.5 akoplatzen3
// 1.6 transmititzen du ASCIIn eta komatxoaz 

// 1.0 jada programatzen
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

//Declaremos los pines CE y el CSN
#define CE_PIN 18
#define CSN_PIN 17

#include "MapFloat.h"
#include <elapsedMillis.h>

elapsedMillis sincePrint;

#define columnNumberR 32 // arrayen dimentsioa
#define columnNumberG 32 // arrayen dimentsioa
#define columnNumberB 32 // arrayen dimentsioa
#define fileNumber 18 // arrayen dimentsioa
#define DEBUG(a) Serial.println(a);

// Bounce debouncer = Bounce(); // Instantiate a Bounce object
byte direccion[5] = {'c', 'a', 'n', 'a', 'l'};
RF24 radio(CE_PIN, CSN_PIN);
float readingR[fileNumber][columnNumberR];
float readingG[fileNumber][columnNumberG];
float readingB[fileNumber][columnNumberB];
int datosControl[3];
int delayTime = 0;

boolean enR = HIGH;
boolean enG = HIGH;
boolean enB = HIGH;

int frames = 10;
int count = 1;

boolean printing = 0;

const char STX = '\x002';
const char ETX = '\x003';

int red = (analogRead (A0));
int green = (analogRead (A1));
int blue = (analogRead (A2));

int colourR = 0;
int colourG = 0;
int colourB = 0;


void setup() {
  Serial.begin(115200);
  radio.begin();
  radio.openWritingPipe(direccion);
  //debouncer.attach(BUTTON_PIN, INPUT_PULLUP); // sakagailua PIN 2 eta masa artean konektaturik dago
  //debouncer.interval(25); // Use a debounce interval of 25 milliseconds
  //f0 = HIGH;

  // for RGB columns
  pinMode (0, OUTPUT);
  digitalWrite (0, LOW);
  pinMode (1, OUTPUT);
  digitalWrite (1, LOW);
  pinMode (2, OUTPUT);
  digitalWrite (2, LOW);
  pinMode (3, OUTPUT);
  digitalWrite (3, LOW);
  pinMode (4, OUTPUT);
  digitalWrite (4, LOW);

  // for files
  pinMode (5, OUTPUT);
  digitalWrite (5, LOW);
  pinMode (6, OUTPUT);
  digitalWrite (6, LOW);
  pinMode (7, OUTPUT);
  digitalWrite (7, LOW);
  pinMode (8, OUTPUT);
  digitalWrite (8, LOW);
  pinMode (9, OUTPUT);
  digitalWrite (9, LOW);

  // deuseztatzen baditut pinModeak balioak baxuagoak ematen ditu
  //pinMode (14, INPUT);
  //pinMode (15, INPUT);
  //pinMode (16, INPUT);

  pinMode (21, OUTPUT);
  digitalWrite (21, 0);
  pinMode (22, OUTPUT);
  digitalWrite (22, 0);
  pinMode (23, OUTPUT);
  digitalWrite (23, 0);

  enR = HIGH;
  enG = HIGH;
  enB = HIGH;

  /*Serial.println ("lest go");
    Serial.println ("goazen");
    Serial.println ("");
    Serial.println ("");*/
  delay (1000);


  ////attachInterrupt(digitalPinToInterrupt(21), buttomf5, FALLING);
  ////f5_1_testingButtons ();
}


void loop() {
  //mountaketaFrogak ();
  delay (1000);
  readingSensorsRed ();
  readingSensorsGreen ();
  readingSensorsBlue ();
  //debuging ();
  /*Serial.println ("");
    Serial.println ("");
    Serial.print ("frames N: ");
    Serial.println (count);
    Serial.println ("");
    delay (1000);
    count ++;*/
}

void   mountaketaFrogak () {
  red = (analogRead (A0));
  green = (analogRead (A1));
  blue = (analogRead (A2));
  colourR = map (analogRead (A0), 0, 1023, 0, 3);
  colourG = map (analogRead (A1), 0, 1023, 0, 3);
  colourB = map (analogRead (A2), 0, 1023, 0, 3);
  Serial.print ("A0: ");
  Serial.print (red);
  Serial.print ("   ");
  Serial.println (colourR);
  Serial.print ("A1: ");
  Serial.print (green);
  Serial.print ("   ");
  Serial.println (colourG);
  Serial.print ("A2: ");
  Serial.print (blue);
  Serial.print ("   ");
  Serial.println (colourB);
  Serial.println ("");

}
void readingSensorsRed () {
  enR = LOW;
  for (int i = 0; i < fileNumber   ; i++) { //18
    datosControl[0] = i + 1;
    datosControl[1] = 'R'; // 82 ACII
    //Serial.print("Datos enviados: ");
    Serial.println("");
    //Serial.write(datosControl[0]);
    Serial.print(datosControl[0]);
    Serial.print(" , ");
    //Serial.write(datosControl[1]);
    Serial.print(datosControl[1]);
    Serial.print(" , ");
    //Serial.println("");
    bool ok = radio.write(datosControl, sizeof(datosControl));
    if (1) {
      for (int k = 0; k < columnNumberR   ; k++) {
        //muxFileNumber(i);
        //muxRGB (k);
        red = (analogRead (A0));
        colourR = map (analogRead (A0), 0, 1023, 0, 255);
        //Serial.print ("colourR");
        //Serial.write (colourR);
        Serial.print (colourR);
        Serial.print(" , ");
        //-----------------------------
        delay(frames);
      }
      //-----------------------------
    }
    else
    {
      Serial.println("no se ha podido enviar datosControl RED");
    }
  }
  enR = HIGH;
}

void readingSensorsGreen () {
  enG = LOW;
  for (int i = 0; i < fileNumber   ; i++) { //18
    datosControl[0] = i + 1;
    datosControl[1] = 'G'; // ? ACII
    //Serial.print("Datos enviados: ");
    Serial.println("");
    //Serial.write(datosControl[0]);
    Serial.print(datosControl[0]);
    Serial.print(" , ");
    //Serial.write(datosControl[1]);
    Serial.print(datosControl[1]);
    Serial.print(" , ");
    //Serial.println("");
    bool ok = radio.write(datosControl, sizeof(datosControl));
    if (1) {
      for (int k = 0; k < columnNumberG   ; k++) {
        //muxFileNumber(i);
        //muxRGB (k);
        green = (analogRead (A1));
        colourG = map (analogRead (A1), 0, 1023, 0, 255);
        //Serial.print ("colourG");
        //Serial.write (colourG);
        Serial.print (colourG);
        Serial.print(" , ");
        //-----------------------------
        delay(frames);
      }
      //-----------------------------
    }
    else
    {
      Serial.println("no se ha podido enviar datosControl Green");
    }
  }
  enG = HIGH;
}

void readingSensorsBlue () {
  enB = LOW;
  for (int i = 0; i < fileNumber   ; i++) { //18
    datosControl[0] = i + 1;
    datosControl[1] = 'B'; // ? ACII
    //Serial.print("Datos enviados: ");
    Serial.println("");
    //Serial.write(datosControl[0]);
    Serial.print(datosControl[0]);
    Serial.print(" , ");
    //Serial.write(datosControl[1]);
    Serial.print(datosControl[1]);
    Serial.print(" , ");
    //Serial.println("");
    bool ok = radio.write(datosControl, sizeof(datosControl));
    if (1) {
      for (int k = 0; k < columnNumberB   ; k++) {
        //muxFileNumber(i);
        //muxRGB (k);
        blue = (analogRead (A2));
        colourB = map (analogRead (A2), 0, 1023, 0, 255);
        //Serial.print ("colourB");
        //Serial.write (colourB);
        Serial.print (colourB);
        Serial.print(" , ");
        //-----------------------------
        delay(frames);
      }
      //-----------------------------
    }
    else
    {
      Serial.println("no se ha podido enviar datosControl Blue");
    }
  }
  enB = HIGH;
}


void muxRGB (int muxRGB) {
  digitalWrite (0, bitRead(muxRGB, 0));
  digitalWrite (1, bitRead(muxRGB, 1));
  digitalWrite (2, bitRead(muxRGB, 2));
  digitalWrite (3, bitRead(muxRGB, 3));
  digitalWrite (4, bitRead(muxRGB, 4));

  if (printing == HIGH) {
    Serial.print (bitRead(muxRGB, 4));
    Serial.print (bitRead(muxRGB, 3));
    Serial.print (bitRead(muxRGB, 2));
    Serial.print (bitRead(muxRGB, 1));
    Serial.println (bitRead(muxRGB, 0));
  }
}

void muxFileNumber(int muxFileNumber) {
  digitalWrite (5, bitRead(muxFileNumber, 0));
  digitalWrite (6, bitRead(muxFileNumber, 1));
  digitalWrite (7, bitRead(muxFileNumber, 2));
  digitalWrite (8, bitRead(muxFileNumber, 3));
  digitalWrite (9, bitRead(muxFileNumber, 4));

  if (printing == HIGH) {
    Serial.print (bitRead(muxFileNumber, 4));
    Serial.print (bitRead(muxFileNumber, 3));
    Serial.print (bitRead(muxFileNumber, 2));
    Serial.print (bitRead(muxFileNumber, 1));
    Serial.println (bitRead(muxFileNumber, 0));
  }
}

void   debuging () {
  if (sincePrint > 100) {      // "sincePrint" auto-increases
    sincePrint = 0;
    //Serial.println("Print 0.1 segundoro");
  }
}
