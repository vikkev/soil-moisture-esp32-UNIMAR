#define AOUT_PIN 2 // ESP32 pin GPIO36 (ADC0) that connects to AOUT pin of moisture sensor
#define THRESHOLD 1920 // Threshold value separating dry and moist soil readings
#define DRY_THRESHOLD 450 // Threshold value for completely dry soil

void setup() {
    Serial.begin(9600);
}

void loop() {
    int sensorValue = analogRead(AOUT_PIN); // Read analog value from sensor

    // Calculate moisture percentage
    float moisturePercentage = calculateMoisturePercentage(sensorValue);

    Serial.print("O solo está: ");
    if (moisturePercentage > 0.5) {
        Serial.print("ÚMIDO (");
    } else {
        Serial.print("SECO (");
    }
    Serial.print(moisturePercentage * 100);
    Serial.println("%");

    delay(500);
}

// Function to calculate moisture percentage
float calculateMoisturePercentage(int sensorValue) {
    if (sensorValue > THRESHOLD) {
        return 0.0; // Dry soil
    } else if (sensorValue <= DRY_THRESHOLD) {
        return 1.0; // Completely wet soil
    } else {
        // Map the value between DRY_THRESHOLD and THRESHOLD to a percentage between 0 and 1
        float moistureRange = THRESHOLD - DRY_THRESHOLD;
        float percentage = (sensorValue - DRY_THRESHOLD) / moistureRange;
        return percentage;
    }
}
