/**
  ******************************************************************************
  * @file           : keyboard.h
  * @author         : Karol Gutowski
  * @brief          : Header for keyboard.c file.
  *                   This file contains defines for keyboard.
  ******************************************************************************
  */

  #ifndef __KEYBOARD_H
  #define __KEYBOARD_H

  #include "stm32l4xx_hal.h"
  #include "stm32l4xx_hal_gpio.h"
  #include "display.h"

  void Keyboard(void);
  int action;

  #endif /* __KEYBOARD_H */
