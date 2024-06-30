

#ifndef COREGAMEPLAY_H
#define COREGAMEPLAY_H


#include <raylib.h>
#include "SerieACalendarGenerator.h"
#include "uiMenu.h"

class UIMenu;
class CoreGameplay {
public:
  CoreGameplay(SerieACalendarGenerator& calendarGenerator);
  //UIMenu();
  ~CoreGameplay();
  enum ButtonState {
      NORMAL,
      HOVERED,
      PRESSED
  };

  ButtonState buttonState1 = NORMAL; // Add this for the first button
  ButtonState buttonState2 = NORMAL; // Add this for the second button
    std::vector<int> teamNamesPlayer1;
    std::vector<int> teamNamesPlayer2;
    void simulateRound(SerieACalendarGenerator& calendarGenerator, UIMenu& uiMenu);
    void simulateMatch(SerieACalendarGenerator& calendarGenerator, UIMenu& uiMenu);
    int round;
    int randTurn;
    int n;
    int n1;
    int n2;
    int n3;
    int x2;
    int x1;
    int i2;
    int y2;
    Rectangle rectangle;
    int matchCounter;
    int matchTime;
    int matchTime1[100];
    int matchTime2[100];
    int  homeScore;
    int  awayScore;
    double currentTime;  // Update currentTime on every frame
    double elapsedTime;
    double startTime;
    int matchEvent;
    int matchEvent1;
    int matchEvent2;
    int footballPitch1;
    int footballPitch2;
    int homeKit;
    int awayKit;
    int placedKits;
    int placedFootballPitch;
    float randomXHome[3];
    float randomYHome[3];
    float randomXAway[3];
    float randomYAway[3];
    std::string playersHome[11];
    std::string playersAway[11];
    std::string playersHomeGoal[100];
    std::string playersAwayGoal[100];
    int playersHome1;
    int playersAway1;
    int randomPlayersHome[3];
    int randomPlayersAway[3];


    int randomPlayer;
    int randomPlayerPass;
    float XHome;
    float YHome;
    float XAway;
    float YAway;
    float XBall;
    float YBall;
    int homeAwayChoice[2];
    int homeChoice;
    int awayChoice;
    int startPlay;
    int startPlay1;
    int i2test;
    int goalScoredHome;
    int goalScoredAway;
    int goalScored1;
    int goalScored2;
    int goalText[100];
    int goalText2[100];
    int goalTrue;
    int goalTrue1;
    double currentTime1;  // Update currentTime on every frame
    double elapsedTime1;
    double startTime1;
    int goalTime;
private:

};

#endif
