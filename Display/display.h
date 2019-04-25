/**
  ******************************************************************************
  * @file           : display.h
  * @author         : Karol Gutowski
  * @brief          : Header for display.c file.
  *                   This file contains defines for display.
  ******************************************************************************
  */

  #ifndef __DISPLAY_H
  #define __DISPLAY_H

  #include "EPD_2in9.h"
  #include "DEV_Config.h"
  #include "GUI_Paint.h"
  #include "ImageData.h"
  #include <stdlib.h>

  #include "keyboard.h"

  //Image cache
  UBYTE *BlackImage;
  static char ** menu_text;
  #define menu_length 3
  int menu_text_usage[menu_length];
  static char ** options_menu_text;
  #define options_menu_length 3
  int current_position;
  int click;

  void Display_Init(void);
  void Display(void);

  void Display_Draw_Menu_Box(int,int,int);
  void Partial_Display_Draw_Menu_Box(int,int,int);

  #endif /* __DISPLAY_H */
