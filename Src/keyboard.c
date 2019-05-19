/**
  ******************************************************************************
  * @file           : keyboard.c
  * @author         : Karol Gutowski
  * @brief          : This file contains funcitons for keyboard.
  ******************************************************************************
  */

  #include "keyboard.h"

  int up=0, down=0, middle=0;
  int min_current_position=0;
  int max_current_position=2;

  void Keyboard()
  {
    if(HAL_GPIO_ReadPin(BT_UP_GPIO_Port,BT_UP_Pin)==0)
    {
      if(up>=keyboard_delay)
      {
        if(current_position>min_current_position)
          current_position--;
        action = 1;
        up=keyboard_delay_after_click;
      }
      else
      {
        up++;
      }
      down=keyboard_delay_after_click;
      middle=keyboard_delay_after_click;
    }
    else
    {
        if(HAL_GPIO_ReadPin(BT_DOWN_GPIO_Port,BT_DOWN_Pin)==0)
        {
          if(down>=keyboard_delay)
          {
            if(current_position<max_current_position)
              current_position++;
            action = 1;
            down=keyboard_delay_after_click;
          }
          else
          {
            down++;
          }
          up=keyboard_delay_after_click;
          middle=keyboard_delay_after_click;
        }
        else
        {
          if(HAL_GPIO_ReadPin(BT_MIDDLE_GPIO_Port,BT_MIDDLE_Pin)==0)
          {
            if(middle>=keyboard_delay)
            {
              click=1;
              action = 1;
              middle=keyboard_delay_after_click;
            }
            else
            {
              middle++;
            }
            up=keyboard_delay_after_click;
            down=keyboard_delay_after_click;
          }
          else
          {
            action = 0;
            if(up>0)
              up=0;
            else
              up++;
            if(down>0)
              down=0;
            else
              down++;
            if(middle>0)
              middle=0;
            else
              middle++;
          }
        }
    }
  }
