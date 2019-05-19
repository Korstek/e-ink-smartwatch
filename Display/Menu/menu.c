/**
  ******************************************************************************
  * @file           : menu.c
  * @author         : Karol Gutowski
  * @brief          : This file contains funcitons for menu.
  ******************************************************************************
  */

  #include "menu.h"

  void Menu_Init()
  {
    current_position = 1;
    click = 0;
    action = 0;
    menu_text = malloc(sizeof(char *)*menu_length);
    *menu_text = "Open";
    *(menu_text+1) = "Connect";
    *(menu_text+2) = "Options";


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

  void Update_Menu()
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
  }

  /*
   * Function: Partial_Display_Draw_Menu_Box
   * ----------------------------
   *   Partialy change the displayed menu to avoid full screen refresh
   *
   *   position: one real value
   *   level: the other real value
   *   select: 0 if not selected, selected if any other value
   *
   *   returns: nothing
   */
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

  /*
   * Function: Partial_Display_Draw_Menu_Box
   * ----------------------------
   *   Partialy change the displayed menu to avoid full screen refresh
   *
   *   position: one real value
   *   level: the other real value
   *   select: 0 if not selected, selected if any other value
   *
   *   returns: nothing
   */
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
