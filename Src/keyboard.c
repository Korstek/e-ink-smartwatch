/**
  ******************************************************************************
  * @file           : keyboard.c
  * @author         : Karol Gutowski
  * @brief          : This file contains funcitons for keyboard.
  ******************************************************************************
  */

  #include "keyboard.h"

  void Keyboard()
  {
    if(HAL_GPIO_ReadPin(BT_UP_GPIO_Port,BT_UP_Pin)==0)
    {
      current_position--;
      action = 1;
    }
    else
    {
        if(HAL_GPIO_ReadPin(BT_DOWN_GPIO_Port,BT_DOWN_Pin)==0)
        {
          current_position++;
          action = 1;
        }
        else
        {
          if(HAL_GPIO_ReadPin(BT_MIDDLE_GPIO_Port,BT_MIDDLE_Pin)==0)
          {
            click=1;
            action = 1;
          }
          else
          {
            action = 0;
          }
        }
    }
  }
