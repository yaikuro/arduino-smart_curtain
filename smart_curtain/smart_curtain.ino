#include <Servo.h>

Servo servo;
Servo servo2;

const int ledPin = 13;
const int ledPin2= 12;
const int ldrPin = A0;
const int ldrPin2= A1;


void setup() 
{
  servo.attach(8);
  servo2.attach(9);
  servo.write(165);
  servo2.write(15);

Serial.begin(9600);

pinMode(ledPin, OUTPUT);
pinMode(ledPin2, OUTPUT);
pinMode(ldrPin, INPUT);
pinMode(ldrPin2, INPUT);

}

void loop() 
{

int ldrStatus = analogRead(ldrPin);
int ldrStatus2 = analogRead(ldrPin2);

delay(15);
// < 500 = NYALA
// > 500 = MATI


// a) SIANG || LAMPU NYALA = TUTUP
if (ldrStatus <= 500 
&& ldrStatus2 > 500
) 
{ 
  digitalWrite(ledPin, HIGH);
  Serial.print("Siang : ");
  Serial.print(ldrStatus);
  Serial.println();

  digitalWrite(ledPin2, LOW);
  Serial.print("Mati : ");
  Serial.print(ldrStatus2);
  Serial.println();

  servo.write(15);
  servo2.write(165);
  Serial.print("TUTUP");
  Serial.println();
  Serial.println();

} 

// b) SIANG || LAMPU MATI = BUKA
if (ldrStatus <= 500 && ldrStatus2 <= 500) 
{ 
  digitalWrite(ledPin, HIGH);
  Serial.print("Siang : ");
  Serial.print(ldrStatus);
  Serial.println();

  digitalWrite(ledPin2, HIGH);
  Serial.print("Nyala : ");
  Serial.print(ldrStatus2);
  Serial.println();
  
  servo.write(165);
  servo2.write(15);
  Serial.print("BUKA");
  Serial.println();
  Serial.println();
} 

// c) MALAM || LAMPU MATI = TUTUP
if (ldrStatus > 500 && ldrStatus2 <= 500) 
{ 
  digitalWrite(ledPin, LOW);
  Serial.print("Malam : ");
  Serial.print(ldrStatus);
  Serial.println();

  digitalWrite(ledPin2, HIGH);
  Serial.print("Nyala : ");
  Serial.print(ldrStatus2);
  Serial.println();

  servo.write(15);
  servo2.write(165);
  Serial.print("TUTUP");
  Serial.println();
  Serial.println();
} 


// d) MALAM || LAMPU NYALA = BUKA
else if (ldrStatus > 500 
&& ldrStatus2 > 500
) 
{ 
  digitalWrite(ledPin, LOW);
  Serial.print("Malam : ");
  Serial.print(ldrStatus);
  Serial.println();

  digitalWrite(ledPin2, LOW);
  Serial.print("Mati : ");
  Serial.print(ldrStatus2);
  Serial.println();

  servo.write(165);
  servo2.write(15);
  Serial.print("BUKA");
  Serial.println();
  Serial.println();
} 
delay(500);

}
