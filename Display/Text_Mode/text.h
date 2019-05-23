/**
  ******************************************************************************
  * @file           : text.h
  * @author         : Karol Gutowski
  * @brief          : Header for text.c file.
  *                   This file contains defines for dispalying text.
  ******************************************************************************
  */

  #ifndef __TEXT_H
  #define __TEXT_H

  #include "EPD_2in9.h"
  #include "DEV_Config.h"
  #include "GUI_Paint.h"
  #include "ImageData.h"
  #include <stdlib.h>

  #include "keyboard.h"
  #include "example.h"

  int text_pointer;
  int previous_text_pointer;

  extern const char text[];

  void Text_Init(void);
  void Text_Processing(void);

  #endif /* __TEXT_H */
