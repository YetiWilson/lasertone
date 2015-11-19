// EXAMPLE USAGE
// Plays a melody - Connect small speaker to analog pin A0
#include "notes.h"

int speakerPinX = D0;
int speakerPinY = D1;
int laser_pin = D6;
int show_pin = A0;
int laser_toggle_delay = 20;
int val = HIGH;
int notePace = 2;

void laser_on();
void laser_off();
void play_tones();
void play_dual();
void hold();

// notes in the melody:
//int melodyX[] = {220,246,196,97,146,0,0,0}; //A, B, G, G, D C4,G3,G3,A3,G3,0,B3,C4
//int melodyY[] = {220,246,196,97,146,0,0,0}; //A, B, G, G, D C4,G3,G3,A3,G3,0,B3,C4
int melodyX[] =       {nEb5,nC6,nAb5,0,nAb4,0,nEb5,nEb5,0,nFb1,nFb1,0,0,nGb1,nGb1,nGb1,nFb1,0,0,0,nBb5,nC6,0,nAb5,0,nAb4,nEb5,nEb5,nFb1,0,nFb1,nFb1,nFb1,nFb1,nFb1,nBb1,0,0,nFb1,0,nBb5,nC6,nAb5,0,nAb4,0,nEb5,nEb5,0,0,nBb5,nC6,nAb5,nAb4,nEb5,nEb5,0,0,nBb5,nC6,nAb5,nAb1,nEb2,nEb2,0,0,nBb5,nC6,nAb5,nAb4,nEb5}; 
int noteDurations[] = {6,   6,  6,   6,6,   6,1,   4,   1,2,   8,   8,4,4,   4,   4,   8,   8,2,1,6,   6,  6,6,   6,6,   1,   4,   4,   8,8,   8,   8,   8,   8,   8,   8,8,8,   2,8,   4,  8,   8,8,   4,1,   4,   4,2,8,   8,  8,   8,   2,   4,   4,2,8,   8,  8,   8,   2,   3,   3,3,8,   8,  8,   8,   2};
//int melodyY[] = {0,0,0,0,0,0,0,}; //A, B, G, G, D C4,G3,G3,A3,G3,0,B3,C4
int dualX[] =        {0,0,nGb5,nDb6,nG5,nD6,nGs5,nD6,nE6,nC6,nC6,nC6,nFs5,nCs6,nDs6,nB6,nB6,nFs5,nF5,nF5,nB4};
int dualY[] =        {0,0,nGb2,nDb3,nG2,nD3,nGs2,nD3,nE3,nC3,nC3,nC3,nFs2,nCs3,nDs3,nB2,nB1,nFs2,nF2,nF2,nB1};
int dualDuration[] = {1,1,5,   5,   5,  5,  5,   6,  6,  6,  6,  6,  6,   4,   4,   4,  4,  4,   4,  4,  4};
// note durations: 4 = quarter note, 8 = eighth note, etc.:


void setup() {
  // iterate over the notes of the melody:
  Particle.publish("notifyr/announce", "Baldie Close Encounters Laser Show!");
  pinMode(laser_pin, OUTPUT);
  pinMode(show_pin, INPUT_PULLUP);
  laser_on();
  
}
void loop() {
    val = digitalRead(show_pin);
    if (val == LOW) {
        play_tones();
        play_dual();
        val = HIGH;
    }
    //play_tones();
    //play_dual();
    delay(1000);
}
void laser_on()
{
  hold(laser_toggle_delay);
  digitalWrite(laser_pin, HIGH);
}

void laser_off()
{
  hold(laser_toggle_delay);
  digitalWrite(laser_pin, LOW);
}

void play_tones()
{
    for (int thisNote = 0; thisNote < 71; thisNote++) {

        // to calculate the note duration, take one second
        // divided by the note type.
        //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
        int noteDuration = (1000*notePace)/noteDurations[thisNote];
        tone(speakerPinX, melodyX[thisNote],noteDuration);
        tone(speakerPinY, melodyX[thisNote],noteDuration);
        // to distinguish the notes, set a minimum time between them.
        // the note's duration + 30% seems to work well:
        int pauseBetweenNotes = noteDuration * 1.30;
        delay(pauseBetweenNotes);
        // stop the tone playing:
        noTone(speakerPinX);
        noTone(speakerPinY);
    }
    
}
void play_dual()
{
    for (int thisNote = 0; thisNote < 21; thisNote++) {

        // to calculate the note duration, take one second
        // divided by the note type.
        //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
        int noteDuration = (1000*notePace)/dualDuration[thisNote];
        tone(speakerPinX, dualX[thisNote],noteDuration);
        tone(speakerPinY, dualY[thisNote],noteDuration);
        // to distinguish the notes, set a minimum time between them.
        // the note's duration + 30% seems to work well:
        int pauseBetweenNotes = noteDuration * 1.30;
        delay(pauseBetweenNotes);
        // stop the tone playing:
        noTone(speakerPinX);
        noTone(speakerPinY);
    }
    
}

void hold(long length)
{
    long loop2 = 0;
        length = length * 2;  
       
        while (loop2 < length)
        {
            delay (1); //we'v messed with timers - so this is a bunch smaller than 1ms delay
            loop2 ++;
        }
}
