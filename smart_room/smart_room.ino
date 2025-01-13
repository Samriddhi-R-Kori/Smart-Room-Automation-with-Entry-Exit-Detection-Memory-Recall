//ble has the code for reset switch

#include <EEPROM.h>

int l1;
int l2;
int ll;
int f;

char Incoming_value = 0;

float c;

int IR1 = 9;
int IR2 = 10; 

int light_1 = 2; 
int light_2 = 5; 
int LED_light = 4; 
int fanr = 3;

int enl = 11; //enter LED green
int exl = 12; //exit LED red

int r = 8; //reset switch

void setup() 
{

  pinMode(IR1, INPUT);
  pinMode(IR2, INPUT);
  pinMode(13, OUTPUT);

  pinMode(light_1, OUTPUT);
  pinMode(light_2, OUTPUT);
  pinMode(LED_light, OUTPUT);
  pinMode(fanr, OUTPUT);

  Serial.begin(9600);
  c = 0;

  status();

  digitalWrite(light_1 , l1);
  digitalWrite(light_2 , l2);
  digitalWrite(LED_light , ll);
  digitalWrite(fanr , f);

}

void loop() 
{
  ble();

  delay(1000);

  while (digitalRead(IR1))
  ble();
    ;
  while (digitalRead(IR2))
  ble();
    ;
  enter();
}

void enter() 
{
  digitalWrite(enl, HIGH);
  delay(1000);
  digitalWrite(enl, LOW);
  c += 1;
  Serial.print("enter ");
  Serial.println(c);
  delay(1000);

  if (c==1)
  {
    light1();
    light2();
    fan();
    delay(2000);
  }

  while (digitalRead(IR2)) 
  {
    ble();
    if (digitalRead(IR1) == 0) 
    {
      while (digitalRead(IR2))
      ble();
        ;
      enter();
      c += 1;
      Serial.print("enter ");
      Serial.println(c);
    }
  }
  while (digitalRead(IR1))
  ble();
    ;
  exit();
}

void exit() 
{
  digitalWrite(exl, HIGH);
  delay(1000);
  digitalWrite(exl, LOW);
  c -= 1;
  Serial.print("exit ");
  Serial.println(c);
  delay(1000);

  if(c<0)
  {
    c = 0;
  }

  if(c==0)
  {
    light1f();
    light2f();
    ledlightf();
    fanf();
    digitalWrite(13,LOW);
    delay(2000);

  }

  while (digitalRead(IR1)) 
  {
    ble();
    if (digitalRead(IR2) == 0) 
    {
      while (digitalRead(IR1))
      ble();
        ;
      exit();
      c -= 1;
      Serial.print("exit ");
      Serial.println(c);
    }
  }
  while (digitalRead(IR2))
  ble();
    ;
  enter();
}

void ble()
{
  //Serial.println("ble");
 if(digitalRead(r)==0)
 {
  Serial.println("c=0");
  c=0;
  light1f();
  light2f();
  ledlightf();
  fanf();
  delay(2000);
 }
}

//ON ON ON ON ON ON ON ON ON ON ON ON ON ON ON ON ON ON ON ON

void light1()
{
  Serial.println("light 1 is on");
  digitalWrite(light_1, LOW);
  EEPROM.update(0, LOW);
}

void light2()
{
  Serial.println("light 2 is on");
  digitalWrite(light_2, LOW);
  EEPROM.update(1, LOW);
}

void ledlight()
{
  Serial.println("LED light is on");
  digitalWrite(LED_light, LOW);
  EEPROM.update(2, LOW);
}

void fan()
{
  Serial.println("fan is on");
  digitalWrite(fanr, LOW);
  EEPROM.update(3, LOW);
}

// OFF OFF OFF OFF OFF OFF OFF OFF OFF OFF OFF OFF OFF OFF OFF OFF 

void light1f()
{
  Serial.println("light 1 is off");
  digitalWrite(light_1, HIGH);
  EEPROM.update(0, HIGH);
}

void light2f()
{
  Serial.println("light 2 is off");
  digitalWrite(light_2, HIGH);
  EEPROM.update(1, HIGH);
}

void ledlightf()
{
  Serial.println("LED light is off");
  digitalWrite(LED_light, HIGH);
  EEPROM.update(2, HIGH);
}

void fanf()
{
  Serial.println("fan is off");
  digitalWrite(fanr, HIGH);
  EEPROM.update(3, HIGH);
}

void status()
{
  l1 = EEPROM.read(0);
  l2 = EEPROM.read(1);
  ll = EEPROM.read(2);
  f = EEPROM.read(3);
}

