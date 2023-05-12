/*
  Melody

  Plays a melody

  circuit:
  - 8 ohm speaker on digital pin 8

  created 21 Jan 2010
  modified 30 Aug 2011
  by Tom Igoe

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/toneMelody
*/

#include "pitches.h"
byte previousState=1, presentState=1, patternNumber=0;

// notes in the melody:
int melody1[] = {
  NOTE_B5, NOTE_A5, NOTE_G5, NOTE_A5, NOTE_B5, NOTE_B5, NOTE_B5, NOTE_A5, NOTE_A5, NOTE_A5,
  NOTE_B5, NOTE_B5, NOTE_B5, NOTE_B5, NOTE_A5, NOTE_G5, NOTE_A5, NOTE_B5, NOTE_B5, NOTE_B5,
  NOTE_A5, NOTE_A5,NOTE_B5, NOTE_A5, NOTE_G5
};
int melody2[] = {
  NOTE_G5, NOTE_G5, NOTE_G5
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations1[] = {
  4, 4, 4, 4, 4, 4, 2, 4, 4, 2, 4, 4, 2, 4, 4, 4, 4, 4, 4, 2, 4, 4, 4, 4, 2
};
int noteDurations2[] = {
  4, 4, 4
};


const int buttonPin = 2;     // the number of the pushbutton pin


void setup() {
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT_PULLUP);
   Serial.begin(9600);
}

void loop() {
  presentState = digitalRead(buttonPin);

//  if(presentState == 1 && previousState == 0){
//    patternNumber++;
//    if(patternNumber>1)
//    {
//      patternNumber = 0;
//    }
//  }
   if(patternNumber==0){
     for (int thisNote = 0; thisNote < 25; thisNote++) {

      // to calculate the note duration, take one second divided by the note type.
      //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
      int noteDuration = 1000 / noteDurations1[thisNote];
      tone(8, melody1[thisNote], noteDuration);
  
      // to distinguish the notes, set a minimum time between them.
      // the note's duration + 30% seems to work well:
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);
      // stop the tone playing:
      noTone(8);
      presentState = digitalRead(buttonPin);
      if(presentState==0){
        patternNumber=1-patternNumber;
       }else {
        previousState = presentState;
       }
      
    }
   }
  
//      if(presentState == 0){
//        patternNumber++;
//        if(patternNumber>1)
//          patternNumber = 0;
//        thisNote = 25; 
  if(patternNumber==1){
    for (int thisNote = 0; thisNote < 3; thisNote++) {

      // to calculate the note duration, take one second divided by the note type.
      //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
      int noteDuration = 1000 / noteDurations2[thisNote];
      tone(8, melody2[thisNote], noteDuration);
  
      // to distinguish the notes, set a minimum time between them.
      // the note's duration + 30% seems to work well:
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);
      // stop the tone playing:
      noTone(8);
      presentState = digitalRead(buttonPin);
      if(presentState==0){
        patternNumber=1-patternNumber;

       } else {
        previousState = presentState;
       }
    }
   }
  
  delay(500);
  previousState = presentState;

}
  
   // iterate over the notes of the melody:
//  for (int thisNote = 0; thisNote < 25; thisNote++) {
//
//    // to calculate the note duration, take one second divided by the note type.
//    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
//    int noteDuration = 1000 / noteDurations1[thisNote];
//    tone(8, melody1[thisNote], noteDuration);
//
//    // to distinguish the notes, set a minimum time between them.
//    // the note's duration + 30% seems to work well:
//    int pauseBetweenNotes = noteDuration * 1.30;
//    delay(pauseBetweenNotes);
//    // stop the tone playing:
//    noTone(8);
//  }
//  delay(200);
  // no need to repeat the melody.
//}
