
//IOs
int Pload=0;
int ClockEnable=3;  
int DataIn=2;
int ClockIn=1;
int LP=4; //Salida para el LED

void setup() 
{
  pinMode(Pload, OUTPUT);
  pinMode(ClockEnable, OUTPUT);
  pinMode(ClockIn, OUTPUT);
  pinMode(DataIn,INPUT);
  pinMode(LP,OUTPUT);

  digitalWrite(LP,HIGH);
  delay(2000);
  digitalWrite(LP,LOW);
  delay(1000);
}

void loop() 
{
 //Pulso al Load pin
 digitalWrite(Pload,LOW);
 delayMicroseconds(5);
 digitalWrite(Pload,HIGH);
 delayMicroseconds(5);

 //Get data from 74HC165
 digitalWrite(ClockIn,HIGH);
 digitalWrite(ClockEnable, LOW);
 byte Entradas=shiftIn(DataIn,ClockIn,LSBFIRST);
 digitalWrite(ClockEnable, HIGH);

 for (int x=0; x<8; x++)
 {
  if(bitRead(Entradas,x)==0)
  {
    for(int y=-1;y<x;y++)
    {
      digitalWrite(LP,HIGH);
      delay(500);
      digitalWrite(LP,LOW);
      delay(500);
    }

  }

 }
}
