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

  display_mode=MENU_MODE;
  display_previous_mode=MENU_MODE;

  Menu_Init();
}

void Display()
{
  if(click==1)
  {
    switch (current_position) {
      case OPEN_POSITION:
          display_mode = TEXT_MODE;
        break;
      default:
          display_mode = MENU_MODE;
        break;
    }
    click=0;
  }
  switch (display_mode) {
    case MENU_MODE:
        if(display_previous_mode==MENU_MODE)
          Update_Menu();
        else
          Menu_Reinit();
      break;

    case TEXT_MODE:
        if(display_previous_mode==TEXT_MODE)
          Text_Init();
          //Update_Text();
        else
          Text_Init();
      break;

    case SLEEP_MODE:

      break;

    case CONNECT_MODE:

      break;

    default:
        Menu_Reinit();
        display_mode=MENU_MODE;
      break;
  }
  display_previous_mode=display_mode;
  action=0;
}
