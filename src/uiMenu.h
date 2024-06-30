// uiMenu.h

#ifndef UIMENU_H
#define UIMENU_H

#include <raylib.h>
#include "SerieACalendarGenerator.h"
#include "coreGameplay.h"
class CoreGameplay;
class UIMenu {


public:
    UIMenu(SerieACalendarGenerator& calendarGenerator, CoreGameplay& gameplay);
    //UIMenu();
    ~UIMenu();
    enum class MenuState {
      MainMenu,
      GeneratedCalendar
  };
    Font font;
    int menu2;
    int menu;
    int menu1;
    int displayMenu();
    void setMenuState(MenuState state);
    void drawBackground();
    bool IsAnyKeyPressed();
    int GetIntInput();
    void drawPlayerStatusById();
    void drawPlayerStatus();
    void drawStandings();
    void drawCurrentCalendar();
    void drawGeneratedCalendar();
    void drawMenuOptions();
    void handleMouseInput();
    void MainMenuOptions();
    static int currentRound;  // Add this line
    MenuState menuState;
    int choice;
    int startingYear = 2023;
    bool GuiMessageBoxYesNo(const char *title, const char *message);
    Texture2D footballPitch[3];
    Texture2D images[20];
    Texture2D ball;
    Texture2D SerieA;
    Texture2D CoppaItalia;
private:
    SerieACalendarGenerator& calendarGenerator;
    CoreGameplay& gameplay;
    int spacing;
    int fontSize;
    Texture2D Tutorial;
    Texture2D backgroundImage;
    Image image;
    Texture2D menuImage;
    Texture2D texture;


    Rectangle rec;
    Color OptionColor;
    int fullscreen;
};

#endif // UIMENU_H
