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
  current_position = 1;
  click = 0;
  action = 0;
  menu_text = malloc(sizeof(char *)*menu_length);
  *menu_text = "Open";
  *(menu_text+1) = "Connect";
  *(menu_text+2) = "Options";

  if(EPD_Init(lut_full_update) != 0) {
      printf("e-Paper init failed\r\n");
  }
  EPD_Clear();
  DEV_Delay_ms(500);

  UWORD Imagesize = ((EPD_WIDTH % 8 == 0)? (EPD_WIDTH / 8 ): (EPD_WIDTH / 8 + 1)) * EPD_HEIGHT;
  if((BlackImage = (UBYTE *)malloc(Imagesize)) == NULL) {
      printf("Failed to apply for black memory...\r\n");
      return -1;
  }
  printf("Paint_NewImage\r\n");
  Paint_NewImage(BlackImage, EPD_WIDTH, EPD_HEIGHT, 270, WHITE);
  Paint_SelectImage(BlackImage);
  Paint_Clear(WHITE);

  #if 1
      /*show image for array*/
      printf("show image for array\r\n");
      Paint_SelectImage(BlackImage);
      Paint_Clear(WHITE);
      Paint_DrawBitMap(gImage_2in9);

      EPD_Display(BlackImage);

      Paint_Clear(WHITE);
      Display_Text();
      DEV_Delay_ms(20000);
  #endif

  EPD_Init(lut_partial_update);
  Paint_Clear(WHITE);
  for(int i=0;i<menu_length;i++)
  {
    if(current_position==i)
    {
      Display_Draw_Menu_Box(i,0,1);
      menu_text_usage[i]=1;
    }
    else
    {
      Display_Draw_Menu_Box(i,0,0);
      menu_text_usage[i]=0;
    }
  }
  EPD_Display(BlackImage);
}

void Display()
{
  for(int i=0;i<menu_length;i++)
  {
    if(current_position==i)
    {
      if(menu_text_usage[i]==0)
        Partial_Display_Draw_Menu_Box(i,0,1);
      menu_text_usage[i]=1;
    }
    else
    {
      if(menu_text_usage[i]==1)
        Partial_Display_Draw_Menu_Box(i,0,0);
      menu_text_usage[i]=0;
    }
  }
  EPD_Display(BlackImage);
  action=0;

}

void Display_Draw_Menu_Box(int position, int level, int select)
{
  if(select==0)
  {
    Paint_DrawRectangle(2, 2+22*position, 110, 24+22*position, BLACK, DRAW_FILL_EMPTY, DOT_PIXEL_2X2);
    Paint_DrawString_EN(3, 3+22*position, *(menu_text+position), &Font20, WHITE, BLACK);
  }
  else
  {
    Paint_DrawRectangle(2, 2+22*position, 110, 24+22*position, BLACK, DRAW_FILL_FULL, DOT_PIXEL_2X2);
    Paint_DrawString_EN(3, 3+22*position, *(menu_text+position), &Font20, BLACK, WHITE);
  }
}

void Partial_Display_Draw_Menu_Box(int position, int level, int select)
{
  Paint_ClearWindows(2, 2+22*position, 110, 24+22*position, WHITE);
  if(select==0)
  {
    Paint_DrawRectangle(2, 2+22*position, 110, 24+22*position, BLACK, DRAW_FILL_EMPTY, DOT_PIXEL_2X2);
    Paint_DrawString_EN(3, 3+22*position, *(menu_text+position), &Font20, WHITE, BLACK);
  }
  else
  {
    Paint_DrawRectangle(2, 2+22*position, 110, 24+22*position, BLACK, DRAW_FILL_FULL, DOT_PIXEL_2X2);
    Paint_DrawString_EN(3, 3+22*position, *(menu_text+position), &Font20, BLACK, WHITE);
  }
}

void Display_Text()
{
  int temp0 = 0;
  int temp1 = 0;
  int temp2 = 0;
  int pointerx=1;
  int pointery=1;
  static char* text = "Prologue\n Light rapidly faded away as the darkness began to swallow him. Hajime Nagumos face twisted in terror as he stared at the vanishing light above him. He desperately shot out his hand, grasping at the light he knew he could never truly grab hold of. He felt his nether regions tense up as he fell freely through the darkness.\n The chasm hed fallen into was so deep that it seemed almost as if he was falling down to the pits of hell. And the light he was staring at was the portal to the world of the living. Hed fallen down a massive tear in the earth while hed been exploring a dungeon. The hole was so deep that he kept falling long after the tiny pinprick of light had shrunk to nothing. His entire life flashed before his eyes, with nothing but the sound of wind rushing past accompanying his plunge to the hellish depths below.\n Let us turn back the clock a bit and recount how a young Japanese boy found himself in a world that was far too cruel and heartless for the word fantasy to be an accurate descriptor. After all, the harsh and unfair events hed experienced, and was still experiencing, were a bit too bereft of the wonderful hopes and dreams one imagined when they heard that word.\n Monday. Quite possibly the most depressing day of the week. Most people were, without a doubt, sighing heavily as they lamented the beginning of the week and the end of their glorious weekend. Hajime Nagumo was no exception. However, in his case, his depression was multiplied by the fact that school was not just a pain, but a veritable hell.";

  while(pointery<EPD_WIDTH-Font12.Height)
  {
    for(int j=temp0;j<temp0+EPD_HEIGHT/Font12.Width;j++)
    {
      if(text[j]=='\n')
      {
        temp1++;
        break;
      }
      Paint_DrawChar(pointerx, pointery, text[j], &Font12, WHITE, BLACK);
      pointerx+=Font12.Width;
      temp1++;
    }
    temp0=temp1;
    pointery+=Font12.Height+1;
    pointerx=1;
  }
  /*while(pointery<EPD_WIDTH)
  {
    for(int i=temp0;i<EPD_HEIGHT/Font12.Width;i++)
    {
      if(text[i+temp0]==' ')
        temp2=i;
      if(text[i+temp0]=='\n')
      {
        temp1=i;
        break;
      }
    }
    if(temp2>temp1)
      temp2=temp1;
    else
      temp1=temp2;
    for(int j=temp0;j<temp2;j++)
    {
      Paint_DrawChar(pointerx, pointery, text[j], &Font12, WHITE, BLACK);
      pointerx+=Font12.Width;
    }
    temp0=temp2;
    pointerx=1;
    pointery+=13;
  }*/
  EPD_Display(BlackImage);
}
