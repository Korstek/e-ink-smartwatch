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
#include "modes.h"

int action;
int menu_current_position;
int text_current_position;
int click;

void Keyboard_Init(void);
void Keyboard(void);
void Keyboard_Modes(int);
void Keyboard_Menu_Mode(int);
void Keyboard_Text_Mode(int);

#define keyboard_delay 100
#define keyboard_delay_after_click -600
#define KEYBOARD_UP 1
#define KEYBOARD_DOWN 2
#define KEYBOARD_MIDDLE 3

#endif /* __KEYBOARD_H */
