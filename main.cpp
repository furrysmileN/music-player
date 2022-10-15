#include <Arduino.h>
#include "pitches.h"
#define BUZZZER_PIN 18
int listentime;
unsigned long stoptime;
unsigned long starttime;
unsigned long nowtime; // Set up basic parameters
int notenumber;
int menuChoice;
int Note;
int Song[];
int Duration[];
int SongOne[] = {
    NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4}; //  Set up each song's notes pitches and durations
int DurationOne[] = {
    1000 / 4, 1000 / 8, 1000 / 8, 1000 / 4, 1000 / 4, 1000 / 4, 1000 / 4, 1000 / 4};
int SongTwo[] = {
    NOTE_D3, NOTE_D3, NOTE_E3, NOTE_F3, NOTE_F3, NOTE_E3, NOTE_D3, NOTE_C3, NOTE_B3, NOTE_B3,
    NOTE_C3, NOTE_D3, NOTE_D3, NOTE_C3, NOTE_C3};
int DurationTwo[] = {
    1000 / 4, 1000 / 4, 1000 / 4, 1000 / 4, 1000 / 4, 1000 / 4, 1000 / 4, 1000 / 4, 1000 / 4, 1000 / 4,
    1000 / 4, 1000 / 4, 1000 / 4 + 1000 / 8, 1000 / 8, 1000 / 2};
int SongThree[] = {
    NOTE_D3, NOTE_DS3, NOTE_F3, NOTE_D3, NOTE_DS3, NOTE_F3};
int DurationThree[] = {
    1000 / 4, 1000 / 4, 1000 / 4, 1000 / 4, 1000 / 4, 1000 / 4};
int SongFour[] = {
    NOTE_D3, NOTE_F3, NOTE_D4, NOTE_D3, NOTE_F3, NOTE_D4};
int DurationFour[] = {
    1000 / 16, 1000 / 16, 1000 / 4, 1000 / 16, 1000 / 16, 1000 / 4};
void setup()
{
  Serial.begin(9600); // start the Serial monitor and initialize the serial port
  delay(500);
}
void loop()
{
  Serial.println("esp32 program started"); // print out a sentence to show the program is working
  while (Serial.available())               ////  the serial received data and read it
  {
    Serial.read();                         
  }
  while (Serial.available() == 0)         //make sure there is no bytes in serial port
  {
  }
  menuChoice = Serial.parseInt();         //input 'which song' from serial monitor 
  Serial.print("you shoose to listen song ");
  Serial.println(menuChoice);
  while (Serial.available())
  {
    Serial.read();
  }
  while (Serial.available() == 0) // repeat stage above, make sure there is no bytes in serial port
  {
  }
  listentime = Serial.parseInt(); // input 'how long' from serial monitor
  Serial.print("you want to listen ");
  Serial.print(listentime);
  Serial.println(" s");
  delay(1000);
  switch (menuChoice)
  {
  case 1:
    notenumber = 8;  // for each song, its original length and notes are different
    for ( Note = 0; Note < 8; Note++) //set up song information for each song
    {
      Song[Note] = SongOne[Note];
      Duration[Note] = DurationOne[Note];
    }
    break;
  case 2:
    notenumber = 16;
    for (Note = 0; Note < 16; Note++)
    {
      Song[Note] = SongTwo[Note];
      Duration[Note] = DurationTwo[Note];
    }
    break;

  case 3:
    notenumber = 6;
    for (Note = 0; Note < 6; Note++)
    {
      Song[Note] = SongThree[Note];
      Duration[Note] = DurationThree[Note];
    }
    break;

  case 4:
    notenumber = 6;
    for (Note = 0; Note < 6; Note++)
    {
      Song[Note] = SongTwo[Note];
      Duration[Note] = DurationThree[Note];
    }
    break;

  default:
    Serial.println("Please choose a valid selection"); //if input valid number, print out warning message
    break;
  }
  Serial.print(" ");
  starttime = millis();                               //use 'time' function to record the strating time and ending time
  stoptime = listentime * 1000 + starttime;            
  for (int thisNote = 0; thisNote < notenumber; thisNote++)
  {
    tone(BUZZZER_PIN, Song[thisNote], Duration[thisNote]);   // play each note one by one
    for (nowtime = millis(); nowtime > stoptime;)            // if the time's up, stop playing
    {
      goto nemo;
    }
    int pauseBetweenNotes = DurationOne[thisNote] * 1.30; // pause between notes makes the song more rhythmical
    delay(pauseBetweenNotes);
    for (; thisNote == notenumber-1;)                     // if the song plays to the end but still have time, replay from the beginning
    {
      thisNote = 0;
    }
  }

  noTone(BUZZZER_PIN);                                   // stop the tone playing
nemo:
  noTone(BUZZZER_PIN);
}
