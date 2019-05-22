/**
  ******************************************************************************
  * @file           : text.c
  * @author         : Karol Gutowski
  * @brief          : This file contains funcitons for dispalying text.
  ******************************************************************************
  */

  #include "text.h"


  /*
   * Function: Display_Text
   * ----------------------------
   *   Displays long text with proper usage of new lines.
   *
   *   (in future) text_pointer: char pointer to text, that will be displayed
   *
   *   (in future) returns: pointer to the last character that was displayed
   */
  void Text_Init()
  {
    int pointer_text = 0;
    int start = 0;
    int finish = 0;
    int max_break = 0;
    int max_space = 0;
    int pointerx=1;
    int pointery=1;

    EPD_Init(lut_full_update);
    Paint_Clear(WHITE);

    while(pointery<EPD_WIDTH-Font12.Height)
    {
      for(int j=start;j<start+EPD_HEIGHT/Font12.Width;j++)
      {
        if(text[j]==' ')
          max_space=j;
        else
        {
          if(text[j]=='\n')
          {
            max_break=j;
            break;
          }
        }
      }
      if(max_break > max_space)
        finish = max_break;
      else
        finish = max_space;
      for(int j=start;j<finish;j++)
      {
        Paint_DrawChar(pointerx, pointery, text[j], &Font12, WHITE, BLACK);
        pointerx+=Font12.Width;
        pointer_text++;
      }
      pointer_text++;
      start=pointer_text;
      pointery+=Font12.Height+1;
      pointerx=1;
      max_break = 0;
      max_space = 0;
    }
    EPD_Display(BlackImage);
  }
