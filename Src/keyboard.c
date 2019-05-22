/**
******************************************************************************
* @file           : keyboard.c
* @author         : Karol Gutowski
* @brief          : This file contains funcitons for keyboard.
******************************************************************************
*/

#include "keyboard.h"

int up, down, middle;
int min_menu_current_position;
int max_menu_current_position;

void Keyboard_Init()
{
  up=0;
  down=0;
  middle=0;
  min_menu_current_position=0;
  max_menu_current_position=2;
}

void Keyboard()
{
  if(HAL_GPIO_ReadPin(BT_UP_GPIO_Port,BT_UP_Pin)==0)
  {
    if(up>=keyboard_delay)
    {
      Keyboard_Modes(KEYBOARD_UP);
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
          Keyboard_Modes(KEYBOARD_DOWN);
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
            Keyboard_Modes(KEYBOARD_MIDDLE);
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

void Keyboard_Modes(int button)
{
  switch (operation_mode) {
    case MENU_MODE:
        Keyboard_Menu_Mode(button);
      break;
    case TEXT_MODE:
        Keyboard_Text_Mode(button);
      break;
    case SLEEP_MODE:

      break;
    case CONNECT_MODE:

      break;
  }
}

void Keyboard_Menu_Mode(int button)
{
  switch (button) {
    case KEYBOARD_UP:
        if(menu_current_position>min_menu_current_position)
          menu_current_position--;
      break;
    case KEYBOARD_DOWN:
        if(menu_current_position<max_menu_current_position)
          menu_current_position++;
      break;
    case KEYBOARD_MIDDLE:
        click=1;
      break;
  }
}

void Keyboard_Text_Mode(int button)
{
  switch (button) {
    case KEYBOARD_UP:
        if(text_current_position>0)
          text_current_position--;
      break;
    case KEYBOARD_DOWN:
        text_current_position++;
      break;
    case KEYBOARD_MIDDLE:
        click=1;
      break;
  }
}
