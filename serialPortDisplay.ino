
void setup()
{
  Serial.begin(9600);
  pinMode(13,OUTPUT);
}
 
byte ledstate = 0;
void loop()
{
  
  if (Serial.available() > 0)
    {
    if (Serial.peek() == 'r')
      {
      Serial.read();
      
      ledstate= Serial.parseInt();
       
      digitalWrite(13,ledstate);
        
      }
      while (Serial.available()>0)
        Serial.read();
    }
}

