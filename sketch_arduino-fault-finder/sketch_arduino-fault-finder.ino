//analong pin A0 initialized.
const int analogPin = A0;



void setup() 
{
  //Initializes the Arduino R3 board and program.
  Serial.begin(9600);
  Serial.println("Transmission Line Fault Finder Initialized.");
}

void loop() 
{
  //Reads ADC value at pin A0.
  int adcValue = analogRead(analogPin);

  //Converts ADC value to voltage value (0-5V).
  float voltage = adcValue * (5.0 / 1023);
  
  //Outputs ADC value, voltage value, and alerts of any faults in the line.
  Serial.println("ADC: ");
  Serial.print(adcValue);
  Serial.print(" | Voltage: ");
  Serial.print(voltage);
  Serial.print("V | Status: ");

  //If & else if statements used to determine if there is a fault and where it is located.
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

  //1 second delay between cycles.
  delay(1000);
}
