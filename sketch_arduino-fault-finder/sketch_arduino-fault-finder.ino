const int analogPin = A0;

void setup() 
{
  Serial.begin(9600);
  Serial.println("Transmission Line Fault Finder Initialized.");
}

void loop() 
{
  int adcValue = analogRead(analogPin);


  float voltage = adcValue * (5.0 / 1023);
  
  Serial.println("ADC: ");
  Serial.print(adcValue);
  Serial.print(" | Voltage: ");
  Serial.print(voltage);
  Serial.print("V | Status: ");


  if (adcValue > 950)
  {
    Serial.println("Grid Normal (No Faults Detected).");
  }
  else if (adcValue < 100) 
  {
    Serial.println("CRITICAL: Fault at Zone 1 (Substation | Distance: 0km).");
  }
  else if (adcValue >= 450 && adcValue <= 550) 
  {
    Serial.println("Fault detected at Zone 2 (Distance: 10km).");
  }
  else if (adcValue >= 630 && adcValue <= 720)
  {
    Serial.println("Fault detected at Zone 3 (Distance 20km).");
  }
  else if (adcValue >= 730 && adcValue <= 790)
  {
    Serial.println("Fault detected at Zone 4 (Distance 30km).");
  }
  else if (adcValue >= 791 && adcValue <= 860)
  {
    Serial.println("Fault detected at Zone 5 (Distance 40km).");
  }


  delay(1000);
}
