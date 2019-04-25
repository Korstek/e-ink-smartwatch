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
      DEV_Delay_ms(2000);
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
