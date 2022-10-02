#include <Arduino.h>
#include "pitches.h"
#define BUZZZER_PIN 18
int listentime;
unsigned long stoptime;
unsigned long starttime;
unsigned long nowtime;
int menuChoice;
int SongOne[] = {
    NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4};
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
  Serial.begin(9600);
  delay(500);
}
int StrToHex(char str[])
{
  return (int)strtol(str, 0, 16);
}
void loop()
{
  Serial.println("");
  Serial.println("program started");
  Serial.println("which song do you want to listen ? ");
  while (Serial.available())
  {
    Serial.read();
  }
  while (Serial.available() == 0)
  {
  }
  menuChoice = Serial.parseInt();
  Serial.print("you shoose to listen song ");
  Serial.println(menuChoice);
  Serial.println("How long do you want to listen? (/s)");
  while (Serial.available())
  {
    Serial.read();
  }
  while (Serial.available() == 0)
  {
  }
  listentime = Serial.parseInt();
  Serial.print("you want to listen ");
  Serial.print(listentime);
  Serial.println(" s");
  delay(1000);
  while (Serial.available())
  {
    Serial.read();
  }
  switch (menuChoice)
  {
  case 1:
    starttime = millis();
    stoptime = listentime * 1000 + starttime;
    for (int thisNote = 0; thisNote < 8; thisNote++)
    {
      tone(BUZZZER_PIN, SongOne[thisNote], DurationOne[thisNote]);
      for (nowtime = millis(); nowtime > stoptime;)
      {
        goto nemo;
      }
      int pauseBetweenNotes = DurationOne[thisNote] * 1.30;
      delay(pauseBetweenNotes);
      for (; thisNote == 8;)
      {
        thisNote = 0;
      }
    }
  // stop the tone playing:
    noTone(BUZZZER_PIN);
    break;

  case 2:
    // humidity sensor code goes here
    Serial.println("You choose 2");
    Serial.println("Then I will play song 2");
    starttime = millis();
    stoptime = listentime * 1000 + starttime;
    for (int thisNote2 = 0; thisNote2 < 16; thisNote2++)
    {

        for (nowtime = millis(); nowtime > stoptime;)
        {
          goto nemo;
        }
        // to calculate the note duration, take one second divided by the note type.
        // e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
        tone(BUZZZER_PIN, SongTwo[thisNote2], DurationTwo[thisNote2]);
        // to distinguish the notes, set a minimum time between them.
        // the note's duration + 30% seems to work well:
        int pauseBetweenNotes = DurationTwo[thisNote2] * 1.30;
        delay(pauseBetweenNotes);
        // stop the tone playing:
        noTone(BUZZZER_PIN);
        for (; thisNote2 == 8;)
        {
          thisNote2 = 0;
        }
      }
    break;

  case 3:
    // pressure sensor code goes here
    Serial.println("You choose 3");
    Serial.println("Then I will play song 3");
    starttime = millis();
    stoptime = listentime * 1000 + starttime;
    for (int thisNote3 = 0; thisNote3 < 6; thisNote3++)
    {
      for (nowtime = millis(); nowtime > stoptime;)
      {
        goto nemo;
      }
      // to calculate the note duration, take one second divided by the note type.
      // e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
      tone(BUZZZER_PIN, SongThree[thisNote3], DurationThree[thisNote3]);
      // to distinguish the notes, set a minimum time between them.
      // the note's duration + 30% seems to work well:
      int pauseBetweenNotes = DurationThree[thisNote3] * 1.30;
      delay(pauseBetweenNotes);
      for (; thisNote3 == 6;)
      {
        thisNote3 = 0;
      }
      // stop the tone playing:
      noTone(BUZZZER_PIN);
    }
    break;

  case 4:
    // humidity sensor code goes here
    Serial.println("You choose 4");
    Serial.println("Then I will play song 4");
    starttime = millis();
    stoptime = listentime * 1000 + starttime;
    for (int thisNote4 = 0; thisNote4 < 6; thisNote4++)
    {
      for (nowtime = millis(); nowtime > stoptime;)
      {
        goto nemo;
      }
      // to calculate the note duration, take one second divided by the note type.
      // e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
      tone(BUZZZER_PIN, SongFour[thisNote4], DurationFour[thisNote4]);
      // to distinguish the notes, set a minimum time between them.
      // the note's duration + 30% seems to work well:
      int pauseBetweenNotes = DurationFour[thisNote4] * 1.30;
      delay(pauseBetweenNotes);
      // stop the tone playing:
      noTone(BUZZZER_PIN);
      for (; thisNote4 == 6;)
      {
        thisNote4 = 0;
      }
    }
    break;

  default:
    Serial.println("Please choose a valid selection");
    break;
  }
nemo:
  noTone(BUZZZER_PIN);
}
