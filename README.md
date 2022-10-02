# music-player
旋律的循环部分无法正常工作；
即
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
在不考虑计时造成的跳出语句，该循环只会进行一次，原因未知
