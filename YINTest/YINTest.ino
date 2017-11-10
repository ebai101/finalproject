#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioInputI2S            i2s1;           //xy=141,72
AudioAnalyzeNoteFrequency notefreq;      //xy=330,91
AudioConnection          patchCord1(i2s1, 0, notefreq, 0);
AudioControlSGTL5000     audioShield;     //xy=217,198
// GUItool: end automatically generated code

void setup() {
  Serial.begin(9600);
  AudioMemory(30);
  audioShield.enable();
  audioShield.inputSelect(AUDIO_INPUT_MIC);
  audioShield.micGain(36);

  notefreq.begin(.15);
}

void loop() {
  if (notefreq.available()) {
    float note = notefreq.read();
    float prob = notefreq.probability();
    Serial.printf("Note: %3.2f | Probability: %.2f\n", note, prob);
  }
}
