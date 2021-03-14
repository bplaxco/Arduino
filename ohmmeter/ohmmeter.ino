int raw = 0;
int vin = 5;
float r1 = 10000;
float r2 = 0;
float buffer = 0;
float vout = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  raw = analogRead(0);

  if (raw) {
    vout = (raw * vin) / 1024.0;
    r2 = r1 * ((vin / vout) - 1);
    
    Serial.print("Raw: ");
    Serial.println(raw);
    Serial.print("Vout: ");
    Serial.println(vout);
    Serial.print("R2: ");
    Serial.println(r2);
    
    delay(1000);
  }
}
