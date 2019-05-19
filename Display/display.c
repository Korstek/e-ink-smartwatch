/**
  ******************************************************************************
  * @file           : display.c
  * @author         : Karol Gutowski
  * @brief          : This file contains funcitons for display operation.
  ******************************************************************************
  */

#include "display.h"

void Display_Init()
{

  EPD_Init(lut_full_update);
  EPD_Clear();
  DEV_Delay_ms(500);

  UWORD Imagesize = ((EPD_WIDTH % 8 == 0)? (EPD_WIDTH / 8 ): (EPD_WIDTH / 8 + 1)) * EPD_HEIGHT;
  if((BlackImage = (UBYTE *)malloc(Imagesize)) == NULL) {
      return -1;
  }
  Paint_NewImage(BlackImage, EPD_WIDTH, EPD_HEIGHT, 270, WHITE);
  Paint_SelectImage(BlackImage);
  Paint_Clear(WHITE);

  #if 0
      /*show image for array*/
      Paint_SelectImage(BlackImage);
      Paint_Clear(WHITE);
      Paint_DrawBitMap(gImage_2in9);

      EPD_Display(BlackImage);

      Paint_Clear(WHITE);
      Display_Text();
      DEV_Delay_ms(2000);
      EPD_Display(BlackImage);
  #endif

  Menu_Init();
}

void Display()
{
  Update_Menu();
  action=0;
}

/*
 * Function: Display_Text
 * ----------------------------
 *   Displays long text with proper usage of new lines.
 *
 *   (in future) text_pointer: char pointer to text, that will be displayed
 *
 *   (in future) returns: pointer to the last character that was displayed
 */
void Display_Text()
{
  int pointer_text = 0;
  int start = 0;
  int finish = 0;
  int max_break = 0;
  int max_space = 0;
  int pointerx=1;
  int pointery=1;
  static char* text = "Prologue\n Light rapidly faded away as the darkness began to swallow him. Hajime Nagumos face twisted in terror as he stared at the vanishing light above him. He desperately shot out his hand, grasping at the light he knew he could never truly grab hold of. He felt his nether regions tense up as he fell freely through the darkness.\n The chasm hed fallen into was so deep that it seemed almost as if he was falling down to the pits of hell. And the light he was staring at was the portal to the world of the living. Hed fallen down a massive tear in the earth while hed been exploring a dungeon. The hole was so deep that he kept falling long after the tiny pinprick of light had shrunk to nothing. His entire life flashed before his eyes, with nothing but the sound of wind rushing past accompanying his plunge to the hellish depths below.\n Let us turn back the clock a bit and recount how a young Japanese boy found himself in a world that was far too cruel and heartless for the word fantasy to be an accurate descriptor. After all, the harsh and unfair events hed experienced, and was still experiencing, were a bit too bereft of the wonderful hopes and dreams one imagined when they heard that word.\n Monday. Quite possibly the most depressing day of the week. Most people were, without a doubt, sighing heavily as they lamented the beginning of the week and the end of their glorious weekend. Hajime Nagumo was no exception. However, in his case, his depression was multiplied by the fact that school was not just a pain, but a veritable hell.";

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
