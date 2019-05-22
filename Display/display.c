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

  Modes_Init();
}

void Display()
{
  if(click==1)
    Click_Handler();

  Mode_Handler();

  action=0;
}
