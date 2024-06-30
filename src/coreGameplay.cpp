#include "coreGameplay.h"
#include "uiMenu.h"
#include <iostream>
#include <ctime>
#include "SerieACalendarGenerator.h"
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <thread>
#include <chrono>
#include <random>
CoreGameplay::CoreGameplay(SerieACalendarGenerator& calendarGenerator){

std::cout << "working directory: " << GetWorkingDirectory() << '\n';
homeScore=0;
awayScore=0;

round = 0;
randTurn = 0;
 n = 1;
 n2 = 0;
 n1 = 0;
 n3 = 0;
x2 = 0;
x1 = 0;
i2 = 0;
  matchCounter = 0;
  matchTime = 0;
   currentTime = 0;  // Update currentTime on every frame
   elapsedTime = 0;
   startTime = GetTime();
   matchEvent2 = 0;
   footballPitch1 = 0;
   footballPitch2 = 0;
   homeKit = 0;
   awayKit = 0;
   placedKits = 0;
   placedFootballPitch = 1;
   playersHome1 = 0;
   playersAway1 = 0;
   homeChoice = 0;
   awayChoice = 0;
   startPlay = 0;
   startPlay1 = 0;
   i2test = 0;
   goalScoredHome = 0;
   goalScoredAway = 0;
   goalScored1 = 0;
   goalScored2 = 0;
    goalText[0] = 10;
    goalText2[0] = 10;
    goalTrue = 0;
    goalTrue1 = 0;
}

// Add a member variable to store the index of the clicked rectangle




int clickedRectangleIndex[20]; // Initialize with an invalid index
std::vector<Color> rectangleColors(20, LIGHTGRAY); // Store the color for each rectangle

void CoreGameplay::simulateRound(SerieACalendarGenerator& calendarGenerator, UIMenu& uiMenu) {
    int c = 0;
    int x = 0;
    int x1 = 70;
    int y = 0;
    int i1 = 30;
    int c1 = 0;
    srand(static_cast<unsigned>(time(0)));
    // Assuming you have a font loaded, set font size, and position
    // Load your font and set its size
    // Font font = LoadFontEx("your_font.ttf", font_size, 0, 250);
    const Match& match = calendarGenerator.calendar[0];
    // Draw the standings title
    if(n1 != 11){
      DrawTextEx(uiMenu.font, TextFormat("Giornata %d", round), {static_cast<float>(GetScreenWidth() / 2 - MeasureText("-----Classifica-----", 20) / 2), 20}, 40, 4, YELLOW);
      DrawTextEx(uiMenu.font, "PLAYER-1", {static_cast<float>(50), 20}, 40, 4, GREEN);
      DrawTextEx(uiMenu.font, "PLAYER-2", {static_cast<float>(GetScreenWidth() - 250), 20}, 40, 4, RED);
      DrawRectangleRounded({static_cast<float>(20), static_cast<float>(300), 100, 20}, 2, 8, Fade(LIGHTGRAY, 0.5f));
      DrawRectangleRoundedLines({static_cast<float>(20), static_cast<float>(300), 100, 20}, 2, 3, 5, BLUE);
      DrawTextEx(uiMenu.font, "SKIP", {static_cast<float>(20), static_cast<float>(300)}, 20, 4, BLACK);
      if (CheckCollisionPointRec(Vector2{static_cast<float>(GetMouseX()), static_cast<float>(GetMouseY())}, {static_cast<float>(20), static_cast<float>(300), 100, 20}) &&
          IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            x2 = 0;
            n1 = 11;


            }





    // Initialize rectangleColors outside the loop
  /*  if (rectangleColors.empty()) {
        rectangleColors = std::vector<Color>(20, LIGHTGRAY);
    }*/

    if (n == 0) {
        randTurn = std::rand() % 2;
        n = 1;
    }

    for (int i = 0; i < 20; ++i) {
        const Match& match = calendarGenerator.calendar[i+i2];
        Rectangle rectangle;

        if (i < 10) {
            rectangle = {static_cast<float>(GetScreenWidth() / 2 - 230), static_cast<float>(x1 + i1), 30, 20};
        } else {
            rectangle = {static_cast<float>(GetScreenWidth() / 2 + 200), static_cast<float>(x1 + i1 - 422), 30, 20};
        }


        if (randTurn == 0 && n1 != 10) {

            if (CheckCollisionPointRec(Vector2{static_cast<float>(GetMouseX()), static_cast<float>(GetMouseY())}, rectangle) &&
                IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && n2 == 0) {

                  if ( i < 10){
                    clickedRectangleIndex[i] = i;
                    std::cout << clickedRectangleIndex[i] << '\n';
                    if(clickedRectangleIndex[i]==n1){

                      rectangleColors[i] = GREEN;
                      rectangleColors[i+10] = RED;

                      clickedRectangleIndex[i+10] = i+10;
                      n2 = 1;
                      n1 = n1 +1;

                    }


                  }
                  if ( i >= 10){
                    clickedRectangleIndex[i] = i;
                    std::cout << clickedRectangleIndex[i] << '\n';
                    if(clickedRectangleIndex[i]==n1+10){

                      rectangleColors[i] = GREEN;
                      rectangleColors[i-10] = RED;

                      clickedRectangleIndex[i-10] = i-10;
                      n2 = 1;
                      n1 = n1 +1;
                    }


                  }







            }

            if (clickedRectangleIndex[i] == i) {
                DrawRectangleRounded(rectangle, 2, 8, Fade(rectangleColors[i], 0.5f));
                // Handle click logic for randTurn == 0
            } else {
                DrawRectangleRounded(rectangle, 2, 8, Fade(LIGHTGRAY, 0.5f));
            }
        } else {
            if (CheckCollisionPointRec(Vector2{static_cast<float>(GetMouseX()), static_cast<float>(GetMouseY())}, rectangle) &&
                IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && n2 == 0) {
//std::cout << clickedRectangleIndex[i] << '\n';
                if( i < 10){
                  clickedRectangleIndex[i] = i;
                  std::cout << clickedRectangleIndex[i] << '\n';
                  if(clickedRectangleIndex[i]==n1){
                    rectangleColors[i] = RED;
                    rectangleColors[i+10] = GREEN;

                    clickedRectangleIndex[i+10] = i+10;
                    n2 = 1;
                    n1 = n1 +1;
                  }

                }


                if ( i >= 10 ){
                  clickedRectangleIndex[i] = i;
                  std::cout << clickedRectangleIndex[i] << '\n';
                  if(clickedRectangleIndex[i]==n1+10){
                    rectangleColors[i] = RED;
                    rectangleColors[i-10] = GREEN;

                    clickedRectangleIndex[i-10] = i-10;
                    n2 = 1;
                    n1 = n1 +1;
                  }


                }


            }

            if (clickedRectangleIndex[i] == i) {
                DrawRectangleRounded(rectangle, 2, 8, Fade(rectangleColors[i], 0.5f));
                // Handle click logic for randTurn != 0
            } else {
                DrawRectangleRounded(rectangle, 2, 8, Fade(LIGHTGRAY, 0.5f));
            }
        }

        DrawRectangleRoundedLines(rectangle, 2, 3, 5, BLUE);
        if (n2 == 1 && n1 != 10) {
              DrawTextEx(uiMenu.font, "PROSSIMO TURNO", {static_cast<float>(280), static_cast<float>(GetScreenHeight() - 100)}, 20, 4, BLACK);
              DrawRectangleRounded({static_cast<float>(280), static_cast<float>(GetScreenHeight() - 100), 200, 20}, 2, 8, Fade(LIGHTGRAY, 0.5f));
              DrawRectangleRoundedLines({static_cast<float>(280), static_cast<float>(GetScreenHeight() - 100), 200, 20}, 2, 3, 5, BLUE);
              if (CheckCollisionPointRec(Vector2{static_cast<float>(GetMouseX()), static_cast<float>(GetMouseY())}, {static_cast<float>(280), static_cast<float>(GetScreenHeight() - 100), 200, 20}) &&
                  IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                      n = 0;
                      n2 = 0;
                  }
        }
        if (i < 10) {
            DrawTextEx(uiMenu.font, (match.homeTeam + " vs. " + match.awayTeam).c_str(), {static_cast<float>(GetScreenWidth() / 2 - 180), static_cast<float>(x1 + i1)}, 30, 2, WHITE);
        }

        i1 = i1 + 20;
        y = y + 1;
        x1 = x1 + 20;
        x = x + 1;

        if (x == 10) {
            x1 = x1 + 20;
            x = 0;
        }
    }
    if (randTurn == 0 && n1 != 10) {
        DrawTextEx(uiMenu.font, "PLAYER-1 TURN", {static_cast<float>(20), static_cast<float>(GetScreenHeight() - 100)}, 40, 4, GREEN);
    } else {
      if( n1 != 10){
          DrawTextEx(uiMenu.font, "PLAYER-2 TURN", {static_cast<float>(GetScreenWidth() - 350), static_cast<float>(GetScreenHeight() - 100)}, 40, 4, RED);

      }

    }

}


    if ( n1 == 10){

      DrawRectangleRounded({static_cast<float>(280), static_cast<float>(GetScreenHeight() - 100), 200, 20}, 2, 8, Fade(LIGHTGRAY, 0.5f));
      DrawRectangleRoundedLines({static_cast<float>(280), static_cast<float>(GetScreenHeight() - 100), 200, 20}, 2, 3, 5, BLUE);
      DrawTextEx(uiMenu.font, "START", {static_cast<float>(40+280), static_cast<float>(GetScreenHeight() - 100)}, 20, 4, BLACK);
      if (CheckCollisionPointRec(Vector2{static_cast<float>(GetMouseX()), static_cast<float>(GetMouseY())}, {static_cast<float>(280), static_cast<float>(GetScreenHeight() - 100), 200, 20}) &&
          IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            x2 = 0;
            n1 = 11;


            }

        }

    if(n1 == 11){
      simulateMatch(calendarGenerator, uiMenu);


    }

}

float lerp(float start, float end, float t) {
    return start + t * (end - start);
}
void CoreGameplay::simulateMatch(SerieACalendarGenerator& calendarGenerator, UIMenu& uiMenu) {

      Match& match = calendarGenerator.calendar[matchCounter+i2];


      //std::cout << (matchCounter+i2) << '\n';

      std::random_device rd;  // obtain a random number from hardware
      std::mt19937 eng(rd()); // seed the generator
      std::mt19937 eng1(rd()); // seed the generator
      std::uniform_int_distribution<int> distribution(0, 99);
      std::uniform_real_distribution<float> xDistribution(220.0f, 500.0f);
      std::uniform_real_distribution<float> yDistribution(140.0f, 320.0f);
      std::uniform_int_distribution<int> randomPlayersHomeDistribution(0, 10);
      std::uniform_int_distribution<int> randomPlayersAwayDistribution(0, 10);
      std::uniform_int_distribution<int> playerDistribution(0, 2);
      std::uniform_int_distribution<int> choiceDistribution(0, 2);
      std::uniform_real_distribution<float> XHomeDistribution(220.0f, 500.0f);
      std::uniform_real_distribution<float> YHomeDistribution(140.0f, 320.0f);
      std::uniform_int_distribution<int> goalDistribution(0, 1);

  if (x2 >= 10){

    DrawRectangleRounded({static_cast<float>(280), static_cast<float>(GetScreenHeight() - 200), 200, 20}, 2, 8, Fade(LIGHTGRAY, 0.5f));
    DrawRectangleRoundedLines({static_cast<float>(280), static_cast<float>(GetScreenHeight() - 200), 200, 20}, 2, 3, 5, BLUE);
    DrawTextEx(uiMenu.font, "CONTINUA ROUND", {static_cast<float>(40+280), static_cast<float>(GetScreenHeight() - 200)}, 20, 4, BLACK);
    if (CheckCollisionPointRec(Vector2{static_cast<float>(GetMouseX()), static_cast<float>(GetMouseY())}, {static_cast<float>(280), static_cast<float>(GetScreenHeight() - 200), 200, 20}) &&
        IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {

            i2 = i2 + 10;
            x2 = 0;
            matchCounter = x2;
            n1 = 0;

          }
  }else{


    DrawTextEx(uiMenu.font, TextFormat("Match %d", x2+1), {20, 20}, 40, 4, YELLOW);
    if(placedFootballPitch == 1){
      DrawRectangle(static_cast<float>(185), static_cast<float>(100), 410, 323+20, BLACK);
      DrawTextureEx(uiMenu.footballPitch[1], (Vector2){static_cast<float>(190), 100 +10}, 0, 1.0f, WHITE);

    }

    DrawTextEx(uiMenu.font, TextFormat("%s %d - %d %s", match.homeTeam.c_str(), homeScore, awayScore, match.awayTeam.c_str()),
               {static_cast<float>(GetScreenWidth() / 2 - 180), static_cast<float>(80)}, 30, 2, WHITE);
               int teamNameOffset = 70;
               int playerInfoOffset = 100;
               int  teamNameOffset2 = 70;
               int playerInfoOffset2 = 100;

            //   for (const std::string& teamName : calendarGenerator.originalTeamNames) {
              //     auto teamIt = std::find_if(calendarGenerator.teams.begin(), calendarGenerator.teams.end(), [&teamName](const SerieATeam& team) {
                      //team.name == match.homeTeam;
                //   });

            //       if (teamIt != calendarGenerator.teams.end()) {
                  //   const SerieATeam& team = *teamIt;

                    auto teamIt = std::find_if(calendarGenerator.teams.begin(), calendarGenerator.teams.end(),
                                               [&match](const SerieATeam& team) {
                                                   return team.name == match.homeTeam;
                                               });

                                               if (teamIt != calendarGenerator.teams.end()) {
                                                   const SerieATeam& team = *teamIt;

                                                   // Set padding values for each field



                                                   std::string teamInfo = match.homeTeam + ":";
                                                   DrawTextEx(uiMenu.font, teamInfo.c_str(), {10, static_cast<float>(teamNameOffset)}, 20, 2, WHITE);

                                                   for (const Player& player : team.players) {
                                                       // Format player info with fixed width for each field
                                                      // std::to_string(player.id);
                                                       std::string playerInfo =  "(" + player.name + ") ";
                                                       std::string playerInfo2 = ": " + std::to_string(player.status);
                                                       DrawTextEx(uiMenu.font, playerInfo.c_str(), {10, static_cast<float>(playerInfoOffset)}, 16, 2, WHITE);
                                                       DrawTextEx(uiMenu.font, playerInfo2.c_str(), {140, static_cast<float>(playerInfoOffset)}, 16, 2, WHITE);
                                                       playerInfoOffset += 30; // Adjust the spacing between players

                                                       playersHome[playersHome1] = player.name;
                                                       playersHome1++;
                                                       // Add extra space after a specific player ID (e.g., 11)
                                                       if (player.id == 11) {
                                                           playerInfoOffset += 40;
                                                       }
                                                   }

                                                   // Add extra space between teams
                                                   playersHome1 = 0;
                                                   playerInfoOffset += 20;
                                                   teamNameOffset = playerInfoOffset - 30; // Update team name offset for the next team
                                               }




                     auto teamIt2 = std::find_if(calendarGenerator.teams.begin(), calendarGenerator.teams.end(),
                                                [&match](const SerieATeam& team) {
                                                    return team.name == match.awayTeam;
                                                });

                     if (teamIt2 != calendarGenerator.teams.end()) {
                         const SerieATeam& team2 = *teamIt2;

                         std::string teamInfo2 = match.awayTeam + ":";
                         DrawTextEx(uiMenu.font, teamInfo2.c_str(), {static_cast<float>(GetScreenWidth()-200), static_cast<float>(teamNameOffset2)}, 20, 2, WHITE);

                         for (const Player& player : team2.players) {
                             std::string playerInfo2 = std::to_string(player.status) + " : (" + player.name + ") ";
                             //std::to_string(player.id);

                               playersAway[playersAway1] = player.name;
                               playersAway1++;

                             DrawTextEx(uiMenu.font, playerInfo2.c_str(), {static_cast<float>(GetScreenWidth()-200), static_cast<float>(playerInfoOffset2)}, 16, 2, WHITE);
                             playerInfoOffset2 += 30; // Adjust the spacing between players

                             // Add extra space after a specific player ID (e.g., 11)
                             if (player.id == 11) {
                                 playerInfoOffset2 += 40;
                             }
                         }



                        // Add extra space between teams
                        playersAway1 = 0;
                        playerInfoOffset2 += 20;
                        teamNameOffset2 = playerInfoOffset2-30;
                      }






                      if(n3 !=1){
                        DrawRectangleRounded({520,20,440,30}, 2, 8, Fade(LIGHTGRAY, 0.5f));
                        DrawRectangleRoundedLines({520,20,440,30}, 2, 3, 5,BLUE);
                      //DrawText("Torna al menu principale", 400, 80, fontSize, BLACK);
                        DrawTextEx(uiMenu.font,"Torna al menu principale", { 520 , 20 }, 20, 2, BLACK);
                        if (CheckCollisionPointRec(Vector2{ static_cast<float>(GetMouseX()), static_cast<float>(GetMouseY()) },
                                                   Rectangle{ 520, 20, 400 - 20, 30 })) {
                            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                                uiMenu.menu1 = 0;
                                uiMenu.choice = 0;
                            }
                            DrawRectangleRounded({520,20,440,30}, 2, 8, Fade(LIGHTGRAY, 0.5f));
                        }
                      }

                        if(n3 !=1){
                          DrawRectangleRounded({static_cast<float>(280), static_cast<float>(GetScreenHeight() - 100), 200, 20}, 2, 8, Fade(LIGHTGRAY, 0.5f));
                          DrawRectangleRoundedLines({static_cast<float>(280), static_cast<float>(GetScreenHeight() - 100), 200, 20}, 2, 3, 5, BLUE);
                          DrawTextEx(uiMenu.font, "INIZIA PARTITA", {static_cast<float>(280), static_cast<float>(GetScreenHeight() - 100)}, 20, 4, BLACK);
                          if (CheckCollisionPointRec(Vector2{static_cast<float>(GetMouseX()), static_cast<float>(GetMouseY())}, {static_cast<float>(280), static_cast<float>(GetScreenHeight() - 100), 200, 20}) &&
                              IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {

                                n3 = 1;

                                x1 = 1;

                                }

                        }

                           // Move the startTime variable outside the block

                        if (n3 == 1) {
                            if (x1 == 1 ) {

                                currentTime = GetTime();  // Update currentTime on every frame
                                elapsedTime = currentTime - startTime;
                                //std::cout << "startTime : " << startTime << '\n';
                                //std::cout << "currentTime : " << currentTime << '\n';
                                //std::cout << "elapsedTime : " << elapsedTime << '\n';
                                DrawTextEx(uiMenu.font, TextFormat("%d", matchTime), {static_cast<float>(GetScreenWidth() / 2 - 180), static_cast<float>(20)}, 30, 2, WHITE);
                                if(goalScoredHome == 1){



                                  for (int i = 0; i < goalScored1; i++) {
                                    DrawTextEx(uiMenu.font,TextFormat("%s - %d ",playersHomeGoal[i].c_str(), matchTime1[i]), {static_cast<float>(200), static_cast<float>(GetScreenHeight() - 160 + goalText[i] )}, 20, 4, WHITE);
                                    goalText[i+1] = goalText[i] + 20;
                                  }


                                }
                                if(goalScoredAway == 1){
                                  for (int i = 0; i < goalScored2; i++) {
                                    DrawTextEx(uiMenu.font,TextFormat("%s - %d ",playersAwayGoal[i].c_str(), matchTime2[i]), {static_cast<float>(450), static_cast<float>(GetScreenHeight() - 160 + goalText2[i])}, 20, 4, WHITE);
                                    goalText2[i+1] = goalText2[i] + 20;
                                  }

                                }

                                if(matchEvent2 == 0){
                                  if (elapsedTime >= 1.0 && matchEvent < 90) {  // Update every 1 second
                                    matchTime++;
                                    startTime = currentTime;  // Reset the start time
                                  //srand(static_cast<unsigned>(time(0)));
                                  if (matchTime >= 90 ){
                                    matchTime = 90;
                                  }
                                  if(matchTime < 90){
                                    matchEvent = distribution(eng);
                                    std::cout << matchEvent << '\n';
                                  }

                                  }

                                }
                                if(matchEvent >= 90){
                                  if(matchEvent2 == 0){
                                    std::uniform_int_distribution<int> distribution1(0, 1);
                                    matchEvent1 = distribution1(eng1);

                                  }



                                  if(matchEvent1==0){
                                    std::cout << "home : " << matchEvent1 << "  "<< matchTime << '\n';
                                    if(footballPitch2 == 0){
                                      std::uniform_int_distribution<int> distribution2(0, 1);
                                       footballPitch1 = distribution2(eng1);
                                       for (int i1 = 0; i1 < 20; i1++) {
                                         if (calendarGenerator.originalTeamNames[i1] == match.homeTeam){
                                            homeKit = i1;

                                         }
                                         if (calendarGenerator.originalTeamNames[i1] == match.awayTeam){
                                            awayKit = i1;
                                        }

                                       }
                                          footballPitch2 = 1;
                                     }



                                    if(footballPitch2 == 1){

                                          DrawTextureEx(uiMenu.footballPitch[footballPitch1], (Vector2){static_cast<float>(190), 100 +10}, 0, 1.0f, WHITE);
                                          placedFootballPitch = 0;
                                          if (footballPitch1 == 0) {


                                            if(placedKits==0  ){
                                              for (int i = 0; i < 3; i++) {
                                                  randomXHome[i] = xDistribution(eng1);
                                                  randomYHome[i] = yDistribution(eng1);
                                                  randomXAway[i] = xDistribution(eng1);
                                                  randomYAway[i] = yDistribution(eng1);
                                                  randomPlayer = playerDistribution(eng1);
                                                  // For randomPlayersHome
                                                  int tempRandomPlayersHome;
                                                  bool isHomeDuplicate;

                                                  do {
                                                      isHomeDuplicate = false;
                                                      tempRandomPlayersHome = randomPlayersHomeDistribution(eng1);

                                                      // Check if the generated number already exists in the array
                                                      for (int j = 0; j < i; j++) {
                                                          if (tempRandomPlayersHome == randomPlayersHome[j]) {
                                                              isHomeDuplicate = true;
                                                              break;
                                                          }
                                                      }
                                                  } while (isHomeDuplicate);

                                                  randomPlayersHome[i] = tempRandomPlayersHome;

                                                  // For randomPlayersAway
                                                  int tempRandomPlayersAway;
                                                  bool isAwayDuplicate;

                                                  do {
                                                      isAwayDuplicate = false;
                                                      tempRandomPlayersAway = randomPlayersAwayDistribution(eng1);

                                                      // Check if the generated number already exists in the array
                                                      for (int j = 0; j < i; j++) {
                                                          if (tempRandomPlayersAway == randomPlayersAway[j]) {
                                                              isAwayDuplicate = true;
                                                              break;
                                                          }
                                                      }
                                                  } while (isAwayDuplicate);

                                                  randomPlayersAway[i] = tempRandomPlayersAway;
                                              }

                                              placedKits = 1;
                                            }
                                            for (int i = 0; i < 3; i++) {
                                              float deltaTime = 0.016f; // Example time step, adjust according to your frame rate

                                              // Update randX and randY towards XHome and YHome

                                              if(homeAwayChoice[0] == 0  &&  homeChoice == 2 && startPlay == 1){
                                                randomXHome[randomPlayer] = lerp(randomXHome[randomPlayer], XHome, 0.02f); // Adjust the interpolation factor (0.1f) for the desired speed
                                                randomYHome[randomPlayer] = lerp(randomYHome[randomPlayer], YHome, 0.02f);
                                                float threshold = 2.0f; // Adjust the threshold for the desired precisionS
                                                  // Check if the difference between the current and target values is within the threshold
                                                    if (abs(randomXHome[randomPlayer] - XHome) < threshold && abs(randomYHome[randomPlayer] - YHome) < threshold) {
                                                      homeChoice = 0;

                                                    }
                                              }








                                        //      std::cout << "randomXHome" << randomXHome[randomPlayer] << '\n';
                                        //      std::cout << "randomYHome" << randomYHome[randomPlayer] << '\n';



                                              DrawTextureEx(uiMenu.images[homeKit], (Vector2){static_cast<float>(randomXHome[i]), randomYHome[i]}, 0, 0.2f, WHITE);
                                              DrawTextureEx(uiMenu.images[awayKit], (Vector2){static_cast<float>(randomXAway[i]), randomYAway[i]}, 0, 0.2f, WHITE);
                                              DrawTextEx(uiMenu.font, playersHome[randomPlayersHome[i]].c_str(), {static_cast<float>(randomXHome[i]), static_cast<float>(randomYHome[i]+20)}, 20, 4, BLACK);
                                              DrawTextEx(uiMenu.font, playersAway[randomPlayersAway[i]].c_str(), {static_cast<float>(randomXAway[i]), static_cast<float>(randomYAway[i]+20)}, 20, 4, BLACK);
                                              DrawTextureEx(uiMenu.images[awayKit], (Vector2){static_cast<float>(370), 140}, 0, 0.2f, WHITE);
                                              DrawTextEx(uiMenu.font, playersAway[0].c_str(), {static_cast<float>(370), static_cast<float>(140+20)}, 20, 4, BLACK);
                                              if (homeAwayChoice[0] != 1 && homeAwayChoice[0] != 2){
                                                  DrawTextureEx(uiMenu.ball, (Vector2){static_cast<float>(randomXHome[randomPlayer]), randomYHome[randomPlayer]+20}, 0, 0.2f, WHITE);
                                                  XBall = randomXHome[randomPlayer];
                                                  YBall = randomYHome[randomPlayer]+20;

                                              }
                                                if ( homeAwayChoice[0] == 1 &&  homeChoice == 1 ){

                                                  XBall = lerp(XBall, 370, 0.02f); // Adjust the interpolation factor (0.1f) for the desired speed
                                                  YBall = lerp(YBall, 140+20, 0.02f);
                                                  DrawTextureEx(uiMenu.ball, (Vector2){static_cast<float>(XBall), static_cast<float>(YBall)}, 0, 0.2f, WHITE);
                                              //    std::cout << "XBall " << XBall << '\n';
                                              //    std::cout << "YBall " << YBall << '\n';
                                              //    std::cout << "randomXHome" << randomXHome[randomPlayer] << '\n';
                                              //    std::cout << "randomYHome" << randomYHome[randomPlayer] << '\n';
                                              //    std::cout << "2 " <<'\n';
                                                  float threshold = 200.0f; // Adjust the threshold for the desired precisionS
                                                  if (abs(XBall - 370) < threshold && abs(YBall - 140+20) < threshold) {
                                                    if(goalTrue1 == 0){
                                                      goalTrue = goalDistribution(eng1);
                                                      std::cout << "goalTrue" << goalTrue << '\n';
                                                      goalTrue1 = 1;
                                                    }
                                                    if(goalTrue == 0){
                                                      if(startPlay == 1){
                                                        startPlay = 2;
                                                      }
                                                    }

                                                    if(goalTrue == 1){

                                                      if(startPlay == 1){
                                                            XBall = lerp(XBall, 370, 0.02f); // Adjust the interpolation factor (0.1f) for the desired speed
                                                            YBall = lerp(YBall, 80, 0.02f);

                                                        float threshold1 = 80.0f;
                                                        if (abs(XBall - 370) < threshold1 && abs(YBall - 80) < threshold1){

                                                            homeScore = homeScore + 1;
                                                            std::cout << "homeScore " << match.homeScore[matchCounter] << '\n';
                                                            //homeChoice = 4;
                                                            goalScoredHome = 1;
                                                            goalScored1 = goalScored1 + 1;
                                                            playersHomeGoal[goalScored1-1] = playersHome[randomPlayersHome[randomPlayer]];
                                                            matchTime1[goalScored1-1] = matchTime;
                                                            startPlay = 2;

                                                        }


                                                      }

                                                    }


                                                      //homeChoice = 5;

                                                  }
                                              }

                                              if ( homeAwayChoice[0] == 2 &&  homeChoice == 2 ){

                                              //  XBall = lerp(XBall, randomXHome[randomPlayerPass], 0.02f); // Adjust the interpolation factor (0.1f) for the desired speed
                                              //  YBall = lerp(YBall, randomYHome[randomPlayerPass], 0.02f);
                                                XBall = static_cast<float>(XBall + 0.02 * (randomXHome[randomPlayerPass] - XBall));
                                                YBall = static_cast<float>(YBall + 0.02 * (randomYHome[randomPlayerPass] - YBall));
                                            //  XBall = XBall + 2;
                                            //  YBall = YBall - 2;
                                                DrawTextureEx(uiMenu.ball, (Vector2){static_cast<float>(XBall), static_cast<float>(YBall)}, 0, 0.2f, WHITE);
                                            //    std::cout << "XBall " << XBall << '\n';
                                            //    std::cout << "YBall " << YBall << '\n';
                                            //    std::cout << "randomXHome" << randomXHome[randomPlayer] << '\n';
                                            //    std::cout << "randomYHome" << randomYHome[randomPlayer] << '\n';
                                            //    std::cout << "2 " <<'\n';
                                                std::cout << "XBall " << XBall << '\n';
                                                std::cout << "YBall " << YBall << '\n';
                                                std::cout << "randomXHome[randomPlayerPass] " << randomXHome[randomPlayerPass] << '\n';
                                                std::cout << "randomYHome[randomPlayerPass] " << randomYHome[randomPlayerPass] << '\n';
                                                std::cout << "result XBall" << XBall + 0.02 * (randomXHome[randomPlayerPass] - XBall) << '\n';
                                                std::cout << "result YBall" << YBall + 0.02 * (randomYHome[randomPlayerPass] - YBall) << '\n';
                                                std::cout << "i2 " << i2test << '\n';
                                                i2test++;
                                              //  XBall = static_cast<float>(XBall + 0.02 * (randomXHome[randomPlayerPass] - XBall));
                                              //  YBall = static_cast<float>(YBall + 0.02 * (randomYHome[randomPlayerPass] - YBall));
                                                float threshold = 2.0f; // Adjust the threshold for the desired precisionS
                                              //  if (CheckCollisionPointRec(Vector2{static_cast<float>(XBall), static_cast<float>(YBall)}, {static_cast<float>(randomXHome[randomPlayerPass]), static_cast<float>(randomYHome[randomPlayerPass]), 20, 20})) {
                                              if(abs(XBall - randomXHome[randomPlayerPass] ) < threshold || abs(YBall - randomYHome[randomPlayerPass]) < threshold){
                                                      randomPlayer = randomPlayerPass;
                                                      homeChoice = 0;
                                                    //homeChoice = 4;


                                                  }

                                                    //homeChoice = 5;


                                            }
                                              std::cout << "homeChoice " << homeAwayChoice[0]  << '\n';

                                            }
                                            if (startPlay == 0) {
                                              DrawRectangleRounded({static_cast<float>(280), static_cast<float>(GetScreenHeight() - 200), 200, 20}, 2, 8, Fade(LIGHTGRAY, 0.5f));
                                              DrawRectangleRoundedLines({static_cast<float>(280), static_cast<float>(GetScreenHeight() - 200), 200, 20}, 2, 3, 5, BLUE);
                                              DrawTextEx(uiMenu.font, "INIZIA AZIONE", {static_cast<float>(280), static_cast<float>(GetScreenHeight() - 200)}, 20, 4, BLACK);
                                              matchEvent2 = 1;
                                              if (CheckCollisionPointRec(Vector2{static_cast<float>(GetMouseX()), static_cast<float>(GetMouseY())}, {static_cast<float>(280), static_cast<float>(GetScreenHeight() - 200), 200, 20}) &&
                                                  IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                                                      startPlay = 1;

                                                    }
                                            }

                                            if(homeChoice == 0 && startPlay == 1){
                                              homeAwayChoice[0] = choiceDistribution(eng1);
                                              std::cout << "homeAwayChoice " << homeAwayChoice[0] << '\n';

                                              homeChoice = 1;

                                            }


                                            if(homeAwayChoice[0] == 0  &&  homeChoice == 1 && startPlay == 1){
                                              XHome = XHomeDistribution(eng1);
                                              YHome = YHomeDistribution(eng1);
                                        //      std::cout << "XHome " << XHome << '\n';
                                        //      std::cout << "YHome " << YHome << '\n';
                                        //      std::cout << "1 " <<'\n';
                                        //      std::cout << "randomXHome" << randomXHome[randomPlayer] << '\n';
                                        //      std::cout << "randomYHome" << randomYHome[randomPlayer] << '\n';
                                        //      for (int i = 0; i < 3; i++) {
                                                //std::cout << "XHome " << i << " " << XHome << '\n';
                                                //std::cout << "YHome " << i << " " << YHome << '\n';
                                        //      }
                                              XBall = randomXHome[randomPlayer];
                                              YBall = randomYHome[randomPlayer]+20;


                                                  homeChoice = 2;



                                              //homeAwayChoice[0] = 1;


                                            }
                                          //  if(homeChoice == 5 && startPlay == 1){

                                          //  }



                                          if(homeAwayChoice[0] == 2  &&  homeChoice == 1 && startPlay == 1){
                                            randomPlayerPass = playerDistribution(eng1);
                                      //      XAway = XHomeDistribution(eng1);
                                      //      YAway = YHomeDistribution(eng1);
                                      //      std::cout << "XHome " << XHome << '\n';
                                      //      std::cout << "YHome " << YHome << '\n';
                                      //      std::cout << "1 " <<'\n';
                                      //      std::cout << "randomXHome" << randomXHome[randomPlayer] << '\n';
                                      //      std::cout << "randomYHome" << randomYHome[randomPlayer] << '\n';
                                      //      for (int i = 0; i < 3; i++) {
                                              //std::cout << "XHome " << i << " " << XHome << '\n';
                                              //std::cout << "YHome " << i << " " << YHome << '\n';
                                      //      }
                                              if(randomPlayerPass != randomPlayer){
                                                XBall = randomXHome[randomPlayer];
                                                YBall = randomYHome[randomPlayer]+20;


                                                homeChoice = 2;
                                            }




                                            //homeAwayChoice[0] = 1;


                                          }



                                          }
                                          if (footballPitch1 == 1) {
                                            if(placedKits==0){
                                              for (int i = 0; i < 3; i++) {
                                                randomXHome[i] = xDistribution(eng1);
                                                randomYHome[i] = yDistribution(eng1);
                                                randomXAway[i] = xDistribution(eng1);
                                                randomYAway[i] = yDistribution(eng1);
                                                randomPlayer = playerDistribution(eng1);
                                                  // For randomPlayersHome
                                                  int tempRandomPlayersHome;
                                                  bool isHomeDuplicate;

                                                  do {
                                                      isHomeDuplicate = false;
                                                      tempRandomPlayersHome = randomPlayersHomeDistribution(eng1);

                                                      // Check if the generated number already exists in the array
                                                      for (int j = 0; j < i; j++) {
                                                          if (tempRandomPlayersHome == randomPlayersHome[j]) {
                                                              isHomeDuplicate = true;
                                                              break;
                                                          }
                                                      }
                                                  } while (isHomeDuplicate);

                                                  randomPlayersHome[i] = tempRandomPlayersHome;

                                                  // For randomPlayersAway
                                                  int tempRandomPlayersAway;
                                                  bool isAwayDuplicate;

                                                  do {
                                                      isAwayDuplicate = false;
                                                      tempRandomPlayersAway = randomPlayersAwayDistribution(eng1);

                                                      // Check if the generated number already exists in the array
                                                      for (int j = 0; j < i; j++) {
                                                          if (tempRandomPlayersAway == randomPlayersAway[j]) {
                                                              isAwayDuplicate = true;
                                                              break;
                                                          }
                                                      }
                                                  } while (isAwayDuplicate);

                                                  randomPlayersAway[i] = tempRandomPlayersAway;
                                              }

                                              placedKits = 1;
                                            }
                                            for (int i = 0; i < 3; i++) {

                                              DrawTextureEx(uiMenu.images[homeKit], (Vector2){static_cast<float>(randomXHome[i]), static_cast<float>(randomYHome[i])}, 0, 0.2f, WHITE);
                                              DrawTextureEx(uiMenu.images[awayKit], (Vector2){static_cast<float>(randomXAway[i]), static_cast<float>(randomYAway[i])}, 0, 0.2f, WHITE);
                                              DrawTextEx(uiMenu.font, playersHome[randomPlayersHome[i]].c_str(), {static_cast<float>(randomXHome[i]), static_cast<float>(randomYHome[i]+20)}, 20, 4, BLACK);
                                              DrawTextEx(uiMenu.font, playersAway[randomPlayersAway[i]].c_str(), {static_cast<float>(randomXAway[i]), static_cast<float>(randomYAway[i]+20)}, 20, 4, BLACK);
                                              DrawTextureEx(uiMenu.ball, (Vector2){static_cast<float>(randomXHome[randomPlayer]), randomYHome[randomPlayer]+20}, 0, 0.2f, WHITE);
                                              startPlay = 2;
                                            }
                                          }
                                    }





                                    if(startPlay == 2){
                                      DrawRectangleRounded({static_cast<float>(280), static_cast<float>(GetScreenHeight() - 200), 200, 20}, 2, 8, Fade(LIGHTGRAY, 0.5f));
                                      DrawRectangleRoundedLines({static_cast<float>(280), static_cast<float>(GetScreenHeight() - 200), 200, 20}, 2, 3, 5, BLUE);
                                      DrawTextEx(uiMenu.font, "FINE AZIONE", {static_cast<float>(280), static_cast<float>(GetScreenHeight() - 200)}, 20, 4, BLACK);
                                      matchEvent2 = 1;
                                      std::cout << "goalTrue" << goalTrue << '\n';
                                      if(goalTrue == 1){
                                        for (int i = 0; i < 3; i++) {
                                          randomXHome[i] = lerp(randomXHome[i], 350, 0.01f);
                                          randomYHome[i] = lerp(randomYHome[i], 200, 0.01f);
                                          float threshold = 2.0f;
                                          if(abs(randomXHome[i] - 350) < threshold && abs(  randomYHome[i] - 200) < threshold){
                                                  goalTrue = 0;


                                              }

                                        }
                                      }
                                      if (CheckCollisionPointRec(Vector2{static_cast<float>(GetMouseX()), static_cast<float>(GetMouseY())}, {static_cast<float>(280), static_cast<float>(GetScreenHeight() - 200), 200, 20}) &&
                                          IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                                              goalTrue = 0;
                                              goalTrue1 = 0;
                                              matchEvent = 0;
                                              matchEvent2 = 0;
                                              footballPitch2 = 0;
                                              placedKits = 0;
                                              placedFootballPitch = 1;
                                              homeChoice = 0;
                                              awayChoice = 0;
                                              homeAwayChoice[0] = 0;
                                              startPlay = 0;

                                            }



                                    }

                                    }

                                  if(matchEvent1==1){
                                    std::cout << "away : " << matchEvent1 << "  "<< matchTime << '\n';
                                    if(footballPitch2 == 0){
                                      std::uniform_int_distribution<int> distribution2(1, 2);
                                       footballPitch1 = distribution2(eng1);
                                       for (int i1 = 0; i1 < 20; i1++) {
                                         if (calendarGenerator.originalTeamNames[i1] == match.awayTeam){
                                            awayKit = i1;

                                         }
                                         if (calendarGenerator.originalTeamNames[i1] == match.homeTeam){
                                            homeKit = i1;
                                        }

                                       }
                                          footballPitch2 = 1;
                                     }


                                    if(footballPitch2 == 1){

                                          DrawTextureEx(uiMenu.footballPitch[footballPitch1], (Vector2){static_cast<float>(190), 100 +10}, 0, 1.0f, WHITE);
                                          placedFootballPitch = 0;
                                          if (footballPitch1 == 2) {
                                            if(placedKits==0){
                                              for (int i = 0; i < 3; i++) {
                                                randomXHome[i] = xDistribution(eng1);
                                                randomYHome[i] = yDistribution(eng1);
                                                randomXAway[i] = xDistribution(eng1);
                                                randomYAway[i] = yDistribution(eng1);
                                                randomPlayer = playerDistribution(eng1);
                                                  // For randomPlayersHome
                                                  int tempRandomPlayersHome;
                                                  bool isHomeDuplicate;

                                                  do {
                                                      isHomeDuplicate = false;
                                                      tempRandomPlayersHome = randomPlayersHomeDistribution(eng1);

                                                      // Check if the generated number already exists in the array
                                                      for (int j = 0; j < i; j++) {
                                                          if (tempRandomPlayersHome == randomPlayersHome[j]) {
                                                              isHomeDuplicate = true;
                                                              break;
                                                          }
                                                      }
                                                  } while (isHomeDuplicate);

                                                  randomPlayersHome[i] = tempRandomPlayersHome;

                                                  // For randomPlayersAway
                                                  int tempRandomPlayersAway;
                                                  bool isAwayDuplicate;

                                                  do {
                                                      isAwayDuplicate = false;
                                                      tempRandomPlayersAway = randomPlayersAwayDistribution(eng1);

                                                      // Check if the generated number already exists in the array
                                                      for (int j = 0; j < i; j++) {
                                                          if (tempRandomPlayersAway == randomPlayersAway[j]) {
                                                              isAwayDuplicate = true;
                                                              break;
                                                          }
                                                      }
                                                  } while (isAwayDuplicate);

                                                  randomPlayersAway[i] = tempRandomPlayersAway;
                                              }

                                              placedKits = 1;
                                            }
                                            for (int i = 0; i < 3; i++) {


                                              float deltaTime = 0.016f; // Example time step, adjust according to your frame rate

                                              // Update randX and randY towards XHome and YHome

                                              if(homeAwayChoice[0] == 0  &&  awayChoice == 2 && startPlay == 1){
                                                randomXAway[randomPlayer] = lerp(randomXAway[randomPlayer], XAway, 0.02f); // Adjust the interpolation factor (0.1f) for the desired speed
                                                randomYAway[randomPlayer] = lerp(randomYAway[randomPlayer], YAway, 0.02f);
                                                float threshold = 2.0f; // Adjust the threshold for the desired precisionS
                                                  // Check if the difference between the current and target values is within the threshold
                                                    if (abs(randomXAway[randomPlayer] - XAway) < threshold && abs(randomYAway[randomPlayer] - YAway) < threshold) {
                                                      awayChoice = 0;

                                                    }
                                              }
                                              DrawTextureEx(uiMenu.images[homeKit], (Vector2){static_cast<float>(randomXHome[i]), randomYHome[i]}, 0, 0.2f, WHITE);
                                              DrawTextureEx(uiMenu.images[awayKit], (Vector2){static_cast<float>(randomXAway[i]), randomYAway[i]}, 0, 0.2f, WHITE);
                                              DrawTextEx(uiMenu.font, playersAway[randomPlayersAway[i]].c_str(), {static_cast<float>(randomXAway[i]), static_cast<float>(randomYAway[i]+25)}, 20, 4, BLACK);
                                              DrawTextEx(uiMenu.font, playersHome[randomPlayersHome[i]].c_str(), {static_cast<float>(randomXHome[i]), static_cast<float>(randomYHome[i]+25)}, 20, 4, BLACK);
                                              DrawTextureEx(uiMenu.images[homeKit], (Vector2){static_cast<float>(370), 350}, 0, 0.2f, WHITE);
                                              DrawTextEx(uiMenu.font, playersHome[0].c_str(), {static_cast<float>(370), static_cast<float>(350+20)}, 20, 4, BLACK);
                                              if (homeAwayChoice[0] != 1 && homeAwayChoice[0] != 2 ){
                                                DrawTextureEx(uiMenu.ball, (Vector2){static_cast<float>(randomXAway[randomPlayer]), randomYAway[randomPlayer]+20}, 0, 0.2f, WHITE);
                                                  XBall = randomXAway[randomPlayer];
                                                  YBall = randomYAway[randomPlayer]+20;

                                              }
                                                if ( homeAwayChoice[0] == 1 &&  awayChoice == 1 ){

                                                  XBall = lerp(XBall, 371, 0.02f); // Adjust the interpolation factor (0.1f) for the desired speed
                                                  YBall = lerp(YBall, 350, 0.02f);
                                                  DrawTextureEx(uiMenu.ball, (Vector2){static_cast<float>(XBall), static_cast<float>(YBall)}, 0, 0.2f, WHITE);
                                              //    std::cout << "XBall " << XBall << '\n';
                                              //    std::cout << "YBall " << YBall << '\n';
                                              //    std::cout << "randomXHome" << randomXHome[randomPlayer] << '\n';
                                              //    std::cout << "randomYHome" << randomYHome[randomPlayer] << '\n';
                                              //    std::cout << "2 " <<'\n';
                                                  float threshold = 200.0f; // Adjust the threshold for the desired precisionS
                                                  if (abs(XBall - 371) < threshold && abs(YBall - 350) < threshold) {
                                                    if(goalTrue1 == 0){
                                                      goalTrue = goalDistribution(eng1);
                                                      std::cout << "goalTrue" << goalTrue << '\n';
                                                      goalTrue1 = 1;
                                                    }
                                                    if(goalTrue == 0){
                                                      if(startPlay == 1){
                                                        startPlay = 2;
                                                      }
                                                    }

                                                    if(goalTrue == 1){

                                                      if(startPlay == 1){
                                                            XBall = lerp(XBall, 370, 0.02f); // Adjust the interpolation factor (0.1f) for the desired speed
                                                            YBall = lerp(YBall, 400, 0.02f);

                                                        float threshold1 = 80.0f;
                                                        if (abs(XBall - 370) < threshold1 && abs(YBall - 400) < threshold1){

                                                            awayScore = awayScore + 1;
                                                            std::cout << "awayScore " << match.awayScore[matchCounter] << '\n';
                                                            //homeChoice = 4;
                                                            goalScoredAway = 1;
                                                            goalScored2 = goalScored2 + 1;
                                                            playersAwayGoal[goalScored2-1] = playersAway[randomPlayersAway[randomPlayer]];
                                                            matchTime2[goalScored2-1] = matchTime;
                                                            startPlay = 2;

                                                        }


                                                      }

                                                    }


                                                      //homeChoice = 5;

                                                  }


                                                      //homeChoice = 5;


                                              }

                                              if ( homeAwayChoice[0] == 2 &&  awayChoice == 2 ){

                                              //  XBall = lerp(XBall, randomXAway[randomPlayerPass], 0.02f); // Adjust the interpolation factor (0.1f) for the desired speed
                                              //  YBall = lerp(YBall, randomYAway[randomPlayerPass], 0.02f);
                                                XBall = XBall + 0.02 * (randomXAway[randomPlayerPass] - XBall);
                                                YBall = YBall + 0.02 * (randomYAway[randomPlayerPass] - YBall);
                                                DrawTextureEx(uiMenu.ball, (Vector2){static_cast<float>(XBall), static_cast<float>(YBall)}, 0, 0.2f, WHITE);
                                            //    std::cout << "XBall " << XBall << '\n';
                                            //    std::cout << "YBall " << YBall << '\n';
                                            //    std::cout << "randomXHome" << randomXHome[randomPlayer] << '\n';
                                            //    std::cout << "randomYHome" << randomYHome[randomPlayer] << '\n';
                                            //    std::cout << "2 " <<'\n';
                                                float threshold = 2.0f; // Adjust the threshold for the desired precisionS
                                                    std::cout << "XBall " << XBall << '\n';
                                                    std::cout << "YBall " << YBall << '\n';
                                                    std::cout << "randomXAway[randomPlayerPass] " << randomXAway[randomPlayerPass] << '\n';
                                                    std::cout << "randomYAway[randomPlayerPass] " << randomYAway[randomPlayerPass] << '\n';
                                                    std::cout << "result XBall" << XBall + 0.02 * (randomXAway[randomPlayerPass] - XBall) << '\n';
                                                    std::cout << "result YBall" << YBall + 0.02 * (randomYAway[randomPlayerPass] - YBall) << '\n';
                                                    std::cout << "i2 " << i2test << '\n';
                                                    i2test++;

                                                //if (CheckCollisionPointRec(Vector2{static_cast<float>(XBall), static_cast<float>(YBall)}, {static_cast<float>(randomXAway[randomPlayerPass]), static_cast<float>(randomYAway[randomPlayerPass]), 20, 20})) {
                                                  if(abs(XBall - randomXAway[randomPlayerPass] ) < threshold || abs(YBall - randomYAway[randomPlayerPass]) < threshold){
                                                      randomPlayer = randomPlayerPass;
                                                      awayChoice = 0;
                                                    //homeChoice = 4;


                                                  }

                                                    //homeChoice = 5;


                                            }
                                              std::cout << "awayChoice " << homeAwayChoice[0]  << '\n';







                                            }
                                            if (startPlay == 0) {
                                              DrawRectangleRounded({static_cast<float>(280), static_cast<float>(GetScreenHeight() - 200), 200, 20}, 2, 8, Fade(LIGHTGRAY, 0.5f));
                                              DrawRectangleRoundedLines({static_cast<float>(280), static_cast<float>(GetScreenHeight() - 200), 200, 20}, 2, 3, 5, BLUE);
                                              DrawTextEx(uiMenu.font, "INIZIA AZIONE", {static_cast<float>(280), static_cast<float>(GetScreenHeight() - 200)}, 20, 4, BLACK);
                                              matchEvent2 = 1;
                                              if (CheckCollisionPointRec(Vector2{static_cast<float>(GetMouseX()), static_cast<float>(GetMouseY())}, {static_cast<float>(280), static_cast<float>(GetScreenHeight() - 200), 200, 20}) &&
                                                  IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                                                      startPlay = 1;

                                                    }
                                            }

                                            if(awayChoice == 0 && startPlay == 1){
                                              homeAwayChoice[0] = choiceDistribution(eng1);
                                              std::cout << "homeAwayChoice " << homeAwayChoice[0] << '\n';

                                              awayChoice = 1;

                                            }


                                            if(homeAwayChoice[0] == 0  &&  awayChoice == 1 && startPlay == 1){
                                              XAway = XHomeDistribution(eng1);
                                              YAway = YHomeDistribution(eng1);
                                        //      std::cout << "XHome " << XHome << '\n';
                                        //      std::cout << "YHome " << YHome << '\n';
                                        //      std::cout << "1 " <<'\n';
                                        //      std::cout << "randomXHome" << randomXHome[randomPlayer] << '\n';
                                        //      std::cout << "randomYHome" << randomYHome[randomPlayer] << '\n';
                                        //      for (int i = 0; i < 3; i++) {
                                                //std::cout << "XHome " << i << " " << XHome << '\n';
                                                //std::cout << "YHome " << i << " " << YHome << '\n';
                                        //      }
                                              XBall = randomXAway[randomPlayer];
                                              YBall = randomYAway[randomPlayer]+20;


                                                  awayChoice = 2;



                                              //homeAwayChoice[0] = 1;


                                            }
                                            if(homeAwayChoice[0] == 2  &&  awayChoice == 1 && startPlay == 1){
                                              randomPlayerPass = playerDistribution(eng1);
                                        //      XAway = XHomeDistribution(eng1);
                                        //      YAway = YHomeDistribution(eng1);
                                        //      std::cout << "XHome " << XHome << '\n';
                                        //      std::cout << "YHome " << YHome << '\n';
                                        //      std::cout << "1 " <<'\n';
                                        //      std::cout << "randomXHome" << randomXHome[randomPlayer] << '\n';
                                        //      std::cout << "randomYHome" << randomYHome[randomPlayer] << '\n';
                                        //      for (int i = 0; i < 3; i++) {
                                                //std::cout << "XHome " << i << " " << XHome << '\n';
                                                //std::cout << "YHome " << i << " " << YHome << '\n';
                                        //      }
                                                if(randomPlayerPass != randomPlayer){
                                                  XBall = randomXAway[randomPlayer];
                                                  YBall = randomYAway[randomPlayer]+20;


                                                  awayChoice = 2;
                                              }




                                              //homeAwayChoice[0] = 1;


                                            }









                                        }
                                          if (footballPitch1 == 1) {
                                            if(placedKits==0){
                                              for (int i = 0; i < 3; i++) {
                                                randomXHome[i] = xDistribution(eng1);
                                                randomYHome[i] = yDistribution(eng1);
                                                randomXAway[i] = xDistribution(eng1);
                                                randomYAway[i] = yDistribution(eng1);
                                                randomPlayer = playerDistribution(eng1);
                                                  // For randomPlayersHome
                                                  int tempRandomPlayersHome;
                                                  bool isHomeDuplicate;

                                                  do {
                                                      isHomeDuplicate = false;
                                                      tempRandomPlayersHome = randomPlayersHomeDistribution(eng1);

                                                      // Check if the generated number already exists in the array
                                                      for (int j = 0; j < i; j++) {
                                                          if (tempRandomPlayersHome == randomPlayersHome[j]) {
                                                              isHomeDuplicate = true;
                                                              break;
                                                          }
                                                      }
                                                  } while (isHomeDuplicate);

                                                  randomPlayersHome[i] = tempRandomPlayersHome;

                                                  // For randomPlayersAway
                                                  int tempRandomPlayersAway;
                                                  bool isAwayDuplicate;

                                                  do {
                                                      isAwayDuplicate = false;
                                                      tempRandomPlayersAway = randomPlayersAwayDistribution(eng1);

                                                      // Check if the generated number already exists in the array
                                                      for (int j = 0; j < i; j++) {
                                                          if (tempRandomPlayersAway == randomPlayersAway[j]) {
                                                              isAwayDuplicate = true;
                                                              break;
                                                          }
                                                      }
                                                  } while (isAwayDuplicate);

                                                  randomPlayersAway[i] = tempRandomPlayersAway;
                                              }

                                              placedKits = 1;
                                            }
                                            for (int i = 0; i < 3; i++) {

                                              DrawTextureEx(uiMenu.images[homeKit], (Vector2){static_cast<float>(randomXHome[i]), static_cast<float>(randomYHome[i])}, 0, 0.2f, WHITE);
                                              DrawTextureEx(uiMenu.images[awayKit], (Vector2){static_cast<float>(randomXAway[i]), static_cast<float>(randomYAway[i])}, 0, 0.2f, WHITE);
                                              DrawTextEx(uiMenu.font, playersAway[randomPlayersAway[i]].c_str(), {static_cast<float>(randomXAway[i]), static_cast<float>(randomYAway[i]+20)}, 20, 4, BLACK);
                                              DrawTextEx(uiMenu.font, playersHome[randomPlayersHome[i]].c_str(), {static_cast<float>(randomXHome[i]), static_cast<float>(randomYHome[i]+20)}, 20, 4, BLACK);
                                              DrawTextureEx(uiMenu.ball, (Vector2){static_cast<float>(randomXAway[randomPlayer]), randomYAway[randomPlayer]+20}, 0, 0.2f, WHITE);
                                              startPlay = 2;
                                            }
                                        }
                                    }




                                    if(startPlay == 2){
                                      DrawRectangleRounded({static_cast<float>(280), static_cast<float>(GetScreenHeight() - 200), 200, 20}, 2, 8, Fade(LIGHTGRAY, 0.5f));
                                      DrawRectangleRoundedLines({static_cast<float>(280), static_cast<float>(GetScreenHeight() - 200), 200, 20}, 2, 3, 5, BLUE);
                                      DrawTextEx(uiMenu.font, "FINE AZIONE", {static_cast<float>(280), static_cast<float>(GetScreenHeight() - 200)}, 20, 4, BLACK);
                                      matchEvent2 = 1;
                                      std::cout << "goalTrue" << goalTrue << '\n';
                                      if(goalTrue == 1){
                                        for (int i = 0; i < 3; i++) {
                                          randomXAway[i] = lerp(randomXAway[i], 200, 0.01f);
                                          randomYAway[i] = lerp(randomYAway[i], 350, 0.01f);
                                          float threshold = 2.0f;
                                          if(abs(randomXAway[i] - 200) < threshold && abs(  randomYAway[i] - 350) < threshold){
                                                  goalTrue = 0;


                                              }

                                        }
                                      }
                                      if (CheckCollisionPointRec(Vector2{static_cast<float>(GetMouseX()), static_cast<float>(GetMouseY())}, {static_cast<float>(280), static_cast<float>(GetScreenHeight() - 200), 200, 20}) &&
                                          IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                                              goalTrue = 0;
                                              goalTrue1 = 0;
                                              matchEvent = 0;
                                              matchEvent2 = 0;
                                              footballPitch2 = 0;
                                              placedKits = 0;
                                              placedFootballPitch = 1;
                                              homeChoice = 0;
                                              awayChoice = 0;
                                              homeAwayChoice[0] = 0;
                                              startPlay = 0;


                                            }

                                    }



                                  }



                                }

                            }
                                  if (matchTime == 90){

                                  DrawRectangleRounded({static_cast<float>(280), static_cast<float>(GetScreenHeight() - 200), 200, 20}, 2, 8, Fade(LIGHTGRAY, 0.5f));
                                  DrawRectangleRoundedLines({static_cast<float>(280), static_cast<float>(GetScreenHeight() - 200), 200, 20}, 2, 3, 5, BLUE);
                                  DrawTextEx(uiMenu.font, "CONTINUA", {static_cast<float>(40+280), static_cast<float>(GetScreenHeight() - 200)}, 20, 4, BLACK);
                                  if (CheckCollisionPointRec(Vector2{static_cast<float>(GetMouseX()), static_cast<float>(GetMouseY())}, {static_cast<float>(280), static_cast<float>(GetScreenHeight() - 200), 200, 20}) &&
                                      IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                                        for (SerieATeam& team : calendarGenerator.teams) { {
                                               if (team.name == match.homeTeam) {
                                                   if (homeScore > awayScore) {
                                                       team.points += 3; // Home team wins
                                                   } else if (homeScore == awayScore) {
                                                       team.points += 1; // Draw
                                                   }
                                               } else if (team.name == match.awayTeam) {
                                                   if (awayScore > homeScore) {
                                                       team.points += 3; // Away team wins
                                                   } else if (awayScore == homeScore) {
                                                       team.points += 1; // Draw
                                                   }
                                               }
                                        }


                                      }
                                          goalScoredHome = 0;
                                          goalScoredAway = 0;
                                          goalScored1 = 0;
                                          goalScored2 = 0;
                                          goalText[0] = 10;
                                          goalText2[0] = 10;
                                          match.homeScore[matchCounter] = homeScore;
                                          match.awayScore[matchCounter] = awayScore;
                                          matchTime = 0;
                                          matchEvent = 0;
                                          matchEvent1 = 0;
                                          matchEvent2 = 0;
                                          x2 = x2 + 1;
                                          matchCounter = x2;
                                          homeScore = 0;
                                          awayScore = 0;
                                          n3 = 0;
                                          x1 = 0;

                                        }
                                }





                                }


  }
//  DrawTextEx(uiMenu.font, (match.homeTeam + " vs. " + match.awayTeam).c_str(), {static_cast<float>(GetScreenWidth() / 2 - 180), static_cast<float>(200)}, 30, 2, WHITE);

  // Simulate the match (add your simulation logic here)
  // For example, you can generate random scores for home and away teams


  // Display the match result

  // Update match counter for the next match
  //matchCounter++;

    // Draw match information

    // Add any additional logic you need for the match simulation
}



CoreGameplay::~CoreGameplay() {
    // Destructor implementation
}
