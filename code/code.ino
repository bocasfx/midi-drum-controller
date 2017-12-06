
 
int velocity = 100;       // Default velocity.
int noteON = 144;         // 144 = 10010000 in binary, note on command.
int noteOFF = 128;        // 128 = 10000000 in binary, note off command.
int padCount = 10;        // Number of pads.
int piezoThreshold = 5;   // Analog threshold for piezo sensing.
int noteDelay = 100;      // Default note delay.

void setup() {
  Serial.begin(115200);
}

void loop() {

  //from note 50 (D3) to note 69 (A4)
  for (int pad=0; pad<padCount; pad++) {

    int value = analogRead(pad);

    if (value > piezoThreshold) {
      MIDImessage(noteON, pad, velocity);      
      delay(noteDelay);
      MIDImessage(noteOFF, pad, velocity);
    }
  }
}

//send MIDI message
void MIDImessage(int command, int MIDInote, int MIDIvelocity) {
  Serial.write(command);
  Serial.write(MIDInote);
  Serial.write(MIDIvelocity);
}

