/*
  Hello This is me Hashtag .....
  This is my Personal Home Project, I use this project
  in my room for sensing my Room Enviroment and display 
  it over the IS2 based LCD 16x2 display.
  Name: Aniket Chowdhury [Hashtag]
  Email: micro.aniket@gmail.com
  GitHub: https://github.com/itzzhashtag
  Instagram: https://instagram.com/itzz_hashtag
  LinkedIn: https://www.linkedin.com/in/itzz-hashtag/
*/

//Change Values and Data before using the code -> LIne No : 36, 37


//===================================================================================================================
// --- Libraries Used ---
//===================================================================================================================
#include <Wire.h>
#include <DHT.h>
#include <LiquidCrystal_I2C.h>
#define DHTPIN 7                    // what pin DHT22 is connected to                <----------------------------------
#define DHTTYPE DHT22

//===================================================================================================================
// --- Variables and Constants ---
//===================================================================================================================
int led_R = 9;                      //red led point                                  <----------------------------------
int led_G = 10;                     //Green led point                                <----------------------------------
int led_B = 11;                     //blue led point                                 <----------------------------------
LiquidCrystal_I2C lcd1(0x27, 16, 2);
LiquidCrystal_I2C lcd2(0x23, 16, 2);
DHT dht(DHTPIN, DHTTYPE);     //// Initialize DHT sensor for normal 16mhz Arduino
int h;                        //Stores humidity value
float t;                      //Stores temperature value
int threshold1 = 60;          //Threshold level for Air Quality(Medium)  <-------------
int threshold2 = 120;         //Threshold level for Air Quality(DANGER)  <-------------
const int aqsensor = A0;      //output of mq135 connected to A0 pin of Arduino


//===================================================================================================================
// --- Custum Character for LCD ---
//===================================================================================================================
byte Skull[8] = {
  0b00000,
  0b01110,
  0b10101,
  0b11011,
  0b01110,
  0b01110,
  0b00000,
  0b00000
};
byte ok[8] = {
  B00000,
  B00000,
  B00000,
  B00001,
  B00001,
  B00111,
  B00111,
  B00111,
};
byte st1[8] = {
  B00011,
  B00011,
  B00011,
  B00011,
  B00011,
  B00011,
  B00011,
  B00011,
};
byte st2[8] = {
  B11000,
  B11000,
  B11000,
  B11000,
  B11000,
  B11000,
  B11000,
  B11000,
};
byte lt1[8] = {
  B00000,
  B00011,
  B00001,
  B11111,
  B11111,
  B00001,
  B00011,
  B00000,
};
byte lt2[] = {
  B00000,
  B11000,
  B10000,
  B11111,
  B11111,
  B10000,
  B11000,
  B00000,
};
byte dg[8] = {
  B00010,
  B00101,
  B00010,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
};
byte Heart[8] = {
  0b00000,
  0b01010,
  0b11111,
  0b11111,
  0b01110,
  0b00100,
  0b00000,
  0b00000
};
byte Heart2[8] = {
  B00000,
  B01010,
  B11111,
  B11111,
  B11111,
  B01110,
  B00100,
  B00000,
};
byte Bell[8] = {
  0b00100,
  0b01110,
  0b01110,
  0b01110,
  0b11111,
  0b00000,
  0b00100,
  0b00000
};
int  sleepyFace[2][16] = {
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0}
};
int  happyFace[2][16] = {
  {0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0},
  {0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0}
};
int happyFaceLips[2][16] = {
  {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0}
};
int  normalFace[2][16] = {
  {0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0},
  {0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0}
};
int  normalFaceLips[2][16] = {
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0}
};
int clk = 3590;

//===================================================================================================================
// --- Setup ---
//===================================================================================================================
void setup()
{
  Serial.begin (9600);      //begin serial communication with baud rate of 9600
  pinMode(led_R, OUTPUT);
  pinMode(led_G, OUTPUT);
  pinMode(led_B, OUTPUT);
  digitalWrite(led_R, HIGH);
  digitalWrite(led_G, HIGH);
  digitalWrite(led_B, HIGH);
  pinMode (aqsensor, INPUT); // MQ135 is connected as INPUT to arduino
  dht.begin();
  lcd1.init();             //initialize the lcd
  lcd1.backlight();
  lcd2.init();
  lcd2.backlight();        // consider 16,2 lcd

  lcd2.createChar(1, Skull);
  lcd2.createChar(2, Heart);
  lcd1.createChar(0, Heart2);
  lcd1.createChar(3, dg);
  lcd2.createChar(4, Bell);
  lcd2.createChar(5, ok);
  lcd1.createChar(6, st1);
  lcd1.createChar(7, st2);
  lcd1.createChar(8, lt1);
  lcd1.createChar(9, lt2);

  lcd1.setCursor(3, 0);
  lcd1.print("Booting. ");
  delay(500);
  lcd1.setCursor(3, 0);
  lcd1.print("Booting.. ");
  delay(500);
  lcd1.setCursor(3, 0);
  lcd1.print("Booting... ");
  delay(500);
  lcd1.setCursor(3, 0);
  lcd1.print("Booting.... ");
  delay(500);
  lcd1.setCursor(0, 0);
  lcd1.print("-----******-----");
  delay(500);
  lcd1.setCursor(3, 1);
  lcd1.print(" Live  OS ");
  delay(1500);
  lcd2.setCursor(0, 0);
  lcd2.print("-> Booting... <-");
  lcd2.setCursor(1, 1);
  delay(800);
  lcd2.write(byte(2));
  lcd2.print("  Complete  ");
  lcd2.write(byte(2));
  delay(2000);
  lcd1.clear();
  lcd2.clear();
  lcd1.setCursor(0, 0);
  lcd1.print("    Welcome ");
  lcd1.write(byte(4));
  lcd1.print("   ");
  delay(1300);
  faces();

}

//===================================================================================================================
// --- Loop ---
//===================================================================================================================
void loop()
{
  if (clk < 3600)
  {
    clk += 1;
    Serial.print("CLOCK : ");
    Serial.println(clk);

    int ppm = analogRead(aqsensor);  //read MQ135 analog outputs at A0 and store it in ppm
    Serial.print("Air Quality: ");   //print message in serail monitor
    Serial.println(ppm);             //print value of ppm in serial monitor

    lcd2.setCursor(0, 0);            // set cursor of lcd to 1st row and 1st column
    lcd2.print("Air Quality: ");     // print message on lcd
    lcd2.print(ppm);                 // print value of MQ135
    lcd2.print(" ") ;

    if (ppm > threshold1 && ppm < threshold2)  // check is ppm is greater than threshold or not
    {
      lcd2.setCursor(0, 1);        //jump here if ppm is greater than threshold
      lcd2.print(" AQ Level HIGH ");
      Serial.println("AQ Level HIGH");
      lcd2.write(byte(4));
      lcd2.print("  ");
      lcd2.setCursor(0, 1);
      digitalWrite(led_R, LOW);
      digitalWrite(led_G, LOW);
      digitalWrite(led_B, HIGH);
    }
    else if (ppm > threshold2)
    {
      lcd2.setCursor(1, 1);        //jump here if ppm is greater than threshold
      lcd2.print("AQ Lvl DANGER ");
      lcd2.write(byte(1));
      lcd2.print("  ");
      Serial.println("AQ Level DANGER");
      lcd2.setCursor(0, 1);
      //tone(led_R,1000,200);         //blink led with turn on time 1000mS, turn off time 200mS
      digitalWrite(led_R, LOW);
      digitalWrite(led_G, HIGH);
      digitalWrite(led_B, HIGH);

    }
    else
    {
      //digitalWrite(led,LOW);   //jump here if ppm is not greater than threshold and turn off LED
      lcd2.setCursor(0, 1);
      lcd2.print (" AQ Level Good ");
      lcd2.write(byte(2));
      lcd2.print("  ") ;
      Serial.println("AQ Level Good");
      digitalWrite(led_R, HIGH);
      digitalWrite(led_G, LOW);
      digitalWrite(led_B, HIGH);
    }
    h = (dht.readHumidity())-5; //Read data and store it to variables h (humidity) and t (temperature)
    t = (dht.readTemperature()) - 3; // Reading temperature or humidity takes about 250 milliseconds!
    //Print temp and humidity values to serial monitor
    Serial.print("Humidity: ");
    Serial.print(h);
    Serial.print(" %, Temp: ");
    Serial.print(t);
    Serial.println(" ° Celsius");
    //Print temp and humidity values to LCD Display
    lcd1.setCursor(0, 0);
    lcd1.print(" ");
    lcd1.write(byte(6));
    //lcd1.write(byte(8));
    lcd1.print(" LIVE Stats ");  // <--------------------
    //lcd1.write(byte(9));
    lcd1.write(byte(7));
    lcd1.print(" ");
    lcd1.setCursor(0, 1);
    lcd1.print("T:");
    lcd1.print(t);
    lcd1.write(byte(3));
    lcd1.print("C");
    lcd1.setCursor(11, 1);
    lcd1.print("H:");
    lcd1.print(h);
    lcd1.print("%");

    delay(1000); //Delay 1 sec.
  }
  else
  {
    clk = 0;
    lcd1.clear();
    lcd2.clear();
    faces();
    lcd1.clear();
    lcd2.clear();
  }
}

//===================================================================================================================
// --- Face Animation for LCD 16*2  ---
//===================================================================================================================
void faces()
{
  printFace(sleepyFace);
  delay(1500);
  printFace(normalFace);
  delay(400);
  printFace(sleepyFace);
  delay(60);
  printFace(normalFace);
  delay(1000);
  printFace(sleepyFace);
  delay(60);
  printFace(normalFace);
  delay(600);
  printFaceLips(normalFaceLips);
  delay(1000);

  printFace(happyFace);
  printFaceLips(happyFaceLips);
  delay(1000);

  lcd2.setCursor(15, 1);
  lcd2.write(byte(5));
  delay(5000);
}
void printFace(int emo[][16])
{
  lcd1.clear();
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 16; j++) {
      lcd1.setCursor(j, i);
      if (emo[i][j] == 1) {
        lcd1.write(255);
      }
    }
  }
}
void printFaceLips(int emo[][16])
{
  lcd2.clear();
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 16; j++) {
      lcd2.setCursor(j, i);
      if (emo[i][j] == 1) {
        lcd2.write(255);
      }
    }
  }
}
//===================================================================================================================
// --- End ---
//===================================================================================================================
