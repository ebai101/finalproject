#include "SolenoidControl.h"
#include "Button.h"
#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioInputI2S            i2s1;           //xy=141,72
AudioAnalyzeNoteFrequency notefreq;      //xy=330,91
AudioConnection          patchCord1(i2s1, 0, notefreq, 0);
AudioControlSGTL5000     audioShield;     //xy=217,198
// GUItool: end automatically generated code

bool scanning;
Button btn(36, 1);
SolenoidControl solenoidControl(37, 38, 39); // turns midi notes into solenoid hits

void setup() {
  Serial.begin(9600);
  startPitchTracker();
  btn.pressHandler(onPress);
  btn.releaseHandler(onRelease);
}

void loop() {
  btn.process();
  if(scanning) {
    scanPitchTracker();
  }
}

void startPitchTracker() {
  // set up the pitch tracker
  AudioMemory(30);
  audioShield.enable();
  audioShield.inputSelect(AUDIO_INPUT_MIC);
  audioShield.micGain(36);
  notefreq.begin(.15);
}

void onPress(int btnName) {
  scanning = 1;
}

void onRelease(int btnName) {
  scanning = 0;
}

void scanPitchTracker() {
  // scan pitch tracker. if probability is high enough, send the pitch to note controller
  if (notefreq.available()) {
    float note = notefreq.read();
    float prob = notefreq.probability();
    if(prob >= 0.9) {
      solenoidControl.checkNote(pitchToMidi(note));
    }
  }
}

int pitchToMidi(float pitch) {
  // converts pitch to midi
  float log2 = log(pitch / 440.0) / log(2);
  float midiVal = 69 + (12 * log2);
  Serial.println((int)midiVal);
  return (int)midiVal;
}


