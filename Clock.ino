//Code Written By RAJDEEP BARUAH

#include<LiquidCrystal.h>
#define buzzer 9
#define sw1 6
#define sw2 7
#define sw3 8 

int select,increase,decrease;
unsigned long int sec=0,minute=0,hr=0,ad1=0,ad2=0;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(buzzer,OUTPUT);
  pinMode(light,OUTPUT);
  pinMode(sw1,INPUT);
  pinMode(sw2,INPUT);
  pinMode(sw3,INPUT);
  lcd.begin(16, 2);
  // Print a message to the LCD.
  
  
}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.setCursor(0,0);
  lcd.print(" MY SMART CLOCK");
  


  sec=millis()/1000;
  minute=sec/60+ad1;
  hr=minute/60+ad2;

  select=digitalRead(sw1);
  decrease=digitalRead(sw2);
  increase=digitalRead(sw3);
  Serial.print(select);
  Serial.print(':');
  Serial.print(decrease);
  Serial.print(':');
  Serial.print(increase);
  Serial.println();
  
  if(select==HIGH)
  {
    if(increase==HIGH)
    {
      ad1++;
    }
    if(decrease==HIGH)
    {
      ad1--;
    }
    delay(200);
  }
  else
  {
    if(increase==HIGH)
    {
      ad2++;
    }
    if(decrease==HIGH)
    {
      ad2--;
    }
    delay(200);
  }
  
    lcd.setCursor(0,1);
    lcd.setCursor(5,1);
    lcd.print(hr%24);
    lcd.print(':');
    lcd.print(minute%60);
    lcd.print(':');
    lcd.print(sec%60);

  if(hr%24==0 && minute%60==1)
  {
    lcd.setCursor(0,0);
    lcd.print("  Good Morning ");
    digitalWrite(buzzer, HIGH);
    delay(500);
    digitalWrite(buzzer, LOW);
    delay(100);  
  }

  if(hr%24==18 && minute%60==0)
  {
    lcd.setCursor(0,0);
    lcd.print("  Good Evening ");
    delay(1000);  
  }

  if(hr%24==23 && minute%60==0)
  {
    lcd.setCursor(0,0);
    lcd.print("  Bed Time :)");  
    delay(1000);
  }
  
 
}
