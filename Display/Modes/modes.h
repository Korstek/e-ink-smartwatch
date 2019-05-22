
  #ifndef __MODES_H
  #define __MODES_H

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
  int operation_mode;
  int previous_operation_mode;

  #define MENU_MODE 1
  #define TEXT_MODE 2
  #define SLEEP_MODE 3
  #define CONNECT_MODE 4

  void Modes_Init(void);
  void Click_Handler(void);
  void Click_Handler_Menu(void);
  void Mode_Handler(void);


  #endif /* __MODES_H */
