void setup()
{
  pinMode(42, OUTPUT);
  pinMode(43, OUTPUT);
  pinMode(44, OUTPUT);
}

void loop()
{
  digitalWrite(42, 1); 
  digitalWrite(43, 1); 
  digitalWrite(44, 1); 
  delay(1000);                      
  digitalWrite(42, 1); 
  digitalWrite(43, 1); 
  digitalWrite(44, 0); 
  delay(1000);                      
  digitalWrite(42, 1); 
  digitalWrite(43, 0); 
  digitalWrite(44, 0); 
  delay(1000);                        
  digitalWrite(42, 0); 
  digitalWrite(43, 1); 
  digitalWrite(44, 1); 
  delay(1000);    
  digitalWrite(42, 0); 
  digitalWrite(43, 0); 
  digitalWrite(44, 1); 
  delay(1000);          
}