
#include "modes.h"

void Modes_Init()
{
  operation_mode=MENU_MODE;
  previous_operation_mode=MENU_MODE;

  Menu_Init();
}

void Click_Handler()
{
  switch (operation_mode) {
    case MENU_MODE:
        Click_Handler_Menu();
      break;
    case TEXT_MODE:
        operation_mode = MENU_MODE;
      break;
  }

  click=0;
}

void Click_Handler_Menu()
{
  switch (menu_current_position) {
    case OPEN_POSITION:
        operation_mode = TEXT_MODE;
      break;
    default:
        operation_mode = MENU_MODE;
      break;
  }
}

void Mode_Handler()
{
  switch (operation_mode) {
    case MENU_MODE:
        if(previous_operation_mode==MENU_MODE)
          Update_Menu();
        else
          Menu_Reinit();
      break;

    case TEXT_MODE:
        if(previous_operation_mode==TEXT_MODE)
          Text_Processing();
          //Update_Text();
        else
          Text_Init();
      break;

    case SLEEP_MODE:

      break;

    case CONNECT_MODE:

      break;

    default:
        Menu_Reinit();
        operation_mode=MENU_MODE;
      break;
  }
  previous_operation_mode=operation_mode;
}
