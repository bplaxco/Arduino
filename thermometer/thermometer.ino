int DISPLAY_DIG_PINS[4] = {
  6, 8, 9, 12
};

int DISPLAY_NUM_PINS[7] = {
  2, 3, 4, 5, 7, 10, 11
};

int DISPLAY_NUM_MAP[70] {
// bl bc br ce tr tl tc
   1, 1, 1, 0, 1, 1, 1, // 0
   0, 0, 1, 0, 1, 0, 0, // 1
   1, 1, 0, 1, 1, 0, 1, // 2
   0, 1, 1, 1, 1, 0, 1, // 3
   0, 0, 1, 1, 1, 1, 0, // 4
   0, 1, 1, 1, 0, 1, 1, // 5
   1, 1, 1, 1, 0, 1, 1, // 6
   0, 0, 1, 0, 1, 0, 1, // 7
   1, 1, 1, 1, 1, 1, 1, // 8
   0, 1, 1, 1, 1, 1, 1, // 9
  
};

void displayNumber(int num) {
  for (int pos = 0; pos < 4; pos++) {
    int start = (num % 10) * 7;

    for (int dig = 0; dig < 4; dig++)
      digitalWrite(DISPLAY_DIG_PINS[dig], dig != pos);

    for (int i = 0; i < 7; i++)
      digitalWrite(DISPLAY_NUM_PINS[i], DISPLAY_NUM_MAP[start + i]);

    num = num / 10;
    delay(5);
  }
}

void setupDisplay() {
  for (int i = 0; i < 4; i++)
    pinMode(DISPLAY_DIG_PINS[i], OUTPUT);

  for (int i = 0; i < 7; i++)
    pinMode(DISPLAY_NUM_PINS[i], OUTPUT);
  
}

int readTemp() {
  float R1 = 10000;
  float c1 = 1.009249522e-03, c2 = 2.378405444e-04, c3 = 2.019202697e-07;
  int vout = analogRead(0);
  float R2 = R1 * (1023.0 / (float)vout - 1.0);
  float logR2 = log(R2);
  float T = (1.0 / (c1 + c2*logR2 + c3*logR2*logR2*logR2));
  T = T - 273.15;
  T = (T * 9.0)/ 5.0 + 32.0; 
  return (int) T;
}

void setup() {
  setupDisplay();
}

void loop() {
  int temp = readTemp();
  
  for (int d = 0; d < 100; d++) {
    displayNumber(temp);
    delay(5);
  }
}
