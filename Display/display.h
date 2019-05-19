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
  #include "menu.h"

  //Image cache
  UBYTE *BlackImage;

  void Display_Init(void);
  void Display(void);

  void Display_Text(void);

  #endif /* __DISPLAY_H */
