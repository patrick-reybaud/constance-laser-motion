/*
  Blink
 Turns on an LED on for one second, then off for one second, repeatedly.
 
 This example code is in the public domain.
 */

// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
#define PLS 13
#define DIR 12
#define ENA 11

#define FDC 10

#define TEST 9

#define V_CAL   20
#define V_RECAL 10
#define V_LASER 1791
#define V_TEST  8

#define DISTANCE 2500000


long nb_pas  = 0;
int i        = 100;
int j        = 0;
int k        = 0;
boolean sens = 0;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(PLS, OUTPUT); 
  pinMode(DIR, OUTPUT);  
  pinMode(ENA, OUTPUT); 

  pinMode(TEST, INPUT_PULLUP); 
  pinMode(FDC, INPUT);  

  //digitalWrite(DIR, HIGH);
  digitalWrite(ENA, LOW);
}

// the loop routine runs over and over again forever:
void loop() {
  //if(digitalRead(TEST) == HIGH)
  //{
    for(k=20;k>0;k--)
    {
      delay(1000);  
      if(digitalRead(FDC) == HIGH)
      {
        digitalWrite(DIR, LOW);
        while(digitalRead(FDC) == HIGH)
        {
          digitalWrite(PLS, HIGH);   // turn the LED on (HIGH is the voltage level)
          delayMicroseconds(V_CAL);               // wait for a second
          digitalWrite(PLS, LOW);    // turn the LED off by making the voltage LOW
          delayMicroseconds(V_CAL);               // wait for a second
        } 
      }
    }
    digitalWrite(ENA, HIGH);
    //delay(600000); 
    delay(180000); 
    digitalWrite(ENA, LOW);

    digitalWrite(DIR, HIGH);

    while(nb_pas < DISTANCE)
    {
      nb_pas++;
      digitalWrite(PLS, HIGH);   // turn the LED on (HIGH is the voltage level)
      delayMicroseconds(V_LASER);               // wait for a second
      digitalWrite(PLS, LOW);    // turn the LED off by making the voltage LOW
      delayMicroseconds(V_LASER);               // wait for a second
    }

    nb_pas  = 0;

    digitalWrite(ENA, HIGH);
    //delay(600000); 
    delay(120000); 
    digitalWrite(ENA, LOW);

    digitalWrite(DIR, LOW);

    while(nb_pas < (DISTANCE - 100000))
    {
      nb_pas++;
      digitalWrite(PLS, HIGH);   // turn the LED on (HIGH is the voltage level)
      delayMicroseconds(V_RECAL);               // wait for a second
      digitalWrite(PLS, LOW);    // turn the LED off by making the voltage LOW
      delayMicroseconds(V_RECAL);               // wait for a second
    }

    digitalWrite(ENA, HIGH);
    while(1);
  //}
  else //////////////////////////////////////////////////TEST/////////////////
  {
    digitalWrite(ENA, HIGH);
    delay(1800); 
    digitalWrite(ENA, LOW);

    for(k=10;k>0;k--)
    {
      delay(1000);  
      if(digitalRead(FDC) == HIGH)
      {
        digitalWrite(DIR, LOW);
        while(digitalRead(FDC) == HIGH)
        {
          digitalWrite(PLS, HIGH);   // turn the LED on (HIGH is the voltage level)
          delayMicroseconds(V_CAL);               // wait for a second
          digitalWrite(PLS, LOW);    // turn the LED off by making the voltage LOW
          delayMicroseconds(V_CAL);               // wait for a second
        } 
      }
    }

    digitalWrite(ENA, HIGH);
    //delay(600000); 
    delay(2000); 
    digitalWrite(ENA, LOW);

    digitalWrite(DIR, HIGH);

    while(nb_pas < DISTANCE)
    {
      nb_pas++;
      digitalWrite(PLS, HIGH);   // turn the LED on (HIGH is the voltage level)
      delayMicroseconds(V_TEST);               // wait for a second
      digitalWrite(PLS, LOW);    // turn the LED off by making the voltage LOW
      delayMicroseconds(V_TEST);               // wait for a second
    }

    nb_pas  = 0;

    digitalWrite(ENA, HIGH);
    delay(1200); 
    digitalWrite(ENA, LOW);

    digitalWrite(DIR, LOW);

    while(nb_pas < (DISTANCE - 100000))
    {
      nb_pas++;
      digitalWrite(PLS, HIGH);   // turn the LED on (HIGH is the voltage level)
      delayMicroseconds(V_RECAL);               // wait for a second
      digitalWrite(PLS, LOW);    // turn the LED off by making the voltage LOW
      delayMicroseconds(V_RECAL);               // wait for a second
    }

    digitalWrite(ENA, HIGH);
    while(1);
  }
}








