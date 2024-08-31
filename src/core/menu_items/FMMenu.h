#ifndef __FM_MENU_H__
#define __FM_MENU_H__

#include "MenuItemInterface.h"


class FMMenu : public MenuItemInterface {
public:
    void optionsMenu(void);
    void draw(void);
    String getName(void);

private:
    String _name = "FM";

    void configMenu(void);
};

#endif
