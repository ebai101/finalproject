
//Pin connected to ST_CP of 74HC595
int latchPin = 37;
//Pin connected to SH_CP of 74HC595
int clockPin = 38;
////Pin connected to DS of 74HC595
int dataPin = 39;

int count = 0;

void setup() {
  //set pins to output so you can control the shift register
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(13, OUTPUT);
  digitalWrite(13, 1);
  delay(1000);
  digitalWrite(13, 0);
}

void loop() {
  
  long shift = setShift(count);
  
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, 0b11111111);
  shiftOut(dataPin, clockPin, MSBFIRST, 0b11111111);
  digitalWrite(latchPin, HIGH);
  Serial.println(count);
  delay(20);

  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, 0);
  shiftOut(dataPin, clockPin, MSBFIRST, 0);
  digitalWrite(latchPin, HIGH);
  delay(20);

  count++;
  if(count > 15)
    count = 0;
}

long setShift(int count) {
  return (uint16_t) 1 << count;
}

