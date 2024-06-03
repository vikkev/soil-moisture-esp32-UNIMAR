#define AOUT_PIN 2 // ESP32 pin GPIO36 (ADC0) that connects to AOUT pin of moisture sensor
#define THRESHOLD 1920 // CHANGE YOUR THRESHOLD HERE

void setup() {
  Serial.begin(9600);
}

void loop() {
  int value = analogRead(AOUT_PIN); // read the analog value from sensor

  if (value > THRESHOLD)
    Serial.print("O solo está: SECO (");
  else
    Serial.print("O solo está: ÚMIDO (");

  Serial.print(value);
  Serial.println(")");


  delay(500);
}
