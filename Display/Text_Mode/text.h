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

  void Text_Init(void);

  extern const char text[];

  #endif /* __TEXT_H */
