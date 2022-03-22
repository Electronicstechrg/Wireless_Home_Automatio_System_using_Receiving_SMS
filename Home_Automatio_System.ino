#define Fan 7
#define Light 9
#define TV 10
#define bulb 4
#define ldr 8
int temp=0,i=0;
int led=13;
char str[15];

void setup()
{
inilize_system();
}

void loop()
{
GSM_system();
void serialEvent();
void check();
LDR_system();
}

void inilize_system()
{
  pinMode(led, OUTPUT);
  pinMode(Fan, OUTPUT);
  pinMode(Light, OUTPUT);
  pinMode(TV, OUTPUT);
  pinMode(bulb, OUTPUT);
  pinMode(ldr,INPUT);
  Serial.begin(9600);

  Serial.println("AT+CNMI=2,2,0,0,0");
  delay(500);
  Serial.println("AT+CMGF=1");
  delay(1000);
}

void GSM_system()
{ 
  if(temp==1)
  {
    check();
    temp=0;
    i=0;
    delay(1000);
  }
}
 void serialEvent() 
 {
  while(Serial.available()) 
  {
    if(Serial.find("#A."))
    {
      digitalWrite(led, HIGH);
      delay(1000);
      digitalWrite(led, LOW);
      while (Serial.available()) 
      {
      char inChar=Serial.read();
      str[i++]=inChar;
      if(inChar=='*')
      {
        temp=1;
        return;
      } 
      } 
    }
   }
 }

void check()
{
   if(!(strncmp(str,"tv on",5)))
    {
      digitalWrite(TV, HIGH);
    }  
   else if(!(strncmp(str,"tv off",6)))
    {
      digitalWrite(TV, LOW);             
    }
  if(!(strncmp(str,"bulb on",7)))
    {
      digitalWrite(bulb, HIGH);    
    }   
   else if(!(strncmp(str,"bulb off",7)))
    {
      digitalWrite(bulb, LOW);  
    }
    else if(!(strncmp(str,"fan on",6)))
    {
      digitalWrite(Fan, HIGH);
    } 
    else if(!(strncmp(str,"fan off",7)))
    {
      digitalWrite(Fan, LOW);
    }     
        else if(!(strncmp(str,"all on",6)))
    {
      digitalWrite(Fan, HIGH);
      digitalWrite(TV, HIGH);
      digitalWrite(bulb, HIGH);    
    }
    else if(!(strncmp(str,"all off",7)))
    {
      digitalWrite(Fan, LOW);
      digitalWrite(TV, LOW);
      digitalWrite(bulb, LOW); 
    }   
}

void LDR_system()
{
  int temp=digitalRead(ldr);
  if(temp==HIGH)                 
digitalWrite(Light,HIGH);  
else
digitalWrite(Light,LOW);
}
