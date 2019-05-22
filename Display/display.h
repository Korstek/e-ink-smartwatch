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
  #include "text.h"
  #include "menu.h"

  //Image cache
  UBYTE *BlackImage;
  int display_mode;
  int display_previous_mode;

  #define MENU_MODE 1
  #define TEXT_MODE 2
  #define SLEEP_MODE 3
  #define CONNECT_MODE 4

  void Display_Init(void);
  void Display(void);

  void Display_Text(void);

  #endif /* __DISPLAY_H */
