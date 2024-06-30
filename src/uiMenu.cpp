#include "uiMenu.h"
#include <iostream>
#include <ctime>
#include "SerieACalendarGenerator.h"
#include <algorithm>
#include "coreGameplay.h"
#include <string>
#define GRID_SIZE 10// Adjust the grid size as needed
#define IMAGE_SIZE 50 // Adjust the image size as needed
#define SPACING_FACTOR 2.8f // Adjust the spacing factor as needed
#define SPEED 1100.0f    // Adjust the animation speed as needed
  Vector2  positions[GRID_SIZE * GRID_SIZE];
int UIMenu::currentRound = 0;

UIMenu::UIMenu(SerieACalendarGenerator& calendarGenerator,CoreGameplay& gameplay) : choice(0), spacing(40), fontSize(20), calendarGenerator(calendarGenerator) , gameplay(gameplay){
    srand(static_cast<unsigned>(time(0)));
    SetConfigFlags(FLAG_WINDOW_UNDECORATED);
    int loadinit = 0;
    InitWindow(800, 600, "roba v0.1.0");
    if(loadinit != 2){
        loadinit = 1;
    }
    if(loadinit = 1 && loadinit != 2){
      backgroundImage = LoadTexture("grafica/sfondo.png");
      ball = LoadTexture("grafica/ball1.png");
     for (int i = 0; i < 20; i++) {
      //char filename[20];
      //sprintf(filename, "CurrentKitsPack/image%d.png", i + 1);

      switch (i) {
        case 0: images[i] = LoadTexture( "CurrentKitsPack/image1.png"); break;
        case 1: images[i] = LoadTexture( "CurrentKitsPack/image2.png"); break;
        case 2: images[i] = LoadTexture( "CurrentKitsPack/image3.png"); break;
        case 3: images[i] = LoadTexture( "CurrentKitsPack/image4.png"); break;
        case 4: images[i] = LoadTexture( "CurrentKitsPack/image5.png"); break;
        case 5: images[i] = LoadTexture( "CurrentKitsPack/image6.png"); break;
        case 6: images[i] = LoadTexture( "CurrentKitsPack/image7.png"); break;
        case 7: images[i] = LoadTexture( "CurrentKitsPack/image8.png"); break;
        case 8: images[i] = LoadTexture( "CurrentKitsPack/image9.png"); break;
        case 9: images[i] = LoadTexture( "CurrentKitsPack/image10.png"); break;
        case 10: images[i] = LoadTexture( "CurrentKitsPack/image11.png"); break;
        case 11: images[i] = LoadTexture( "CurrentKitsPack/image12.png"); break;
        case 12: images[i] = LoadTexture( "CurrentKitsPack/image13.png"); break;
        case 13: images[i] = LoadTexture( "CurrentKitsPack/image14.png"); break;
        case 14: images[i] = LoadTexture( "CurrentKitsPack/image15.png"); break;
        case 15: images[i] = LoadTexture( "CurrentKitsPack/image16.png"); break;
        case 16: images[i] = LoadTexture( "CurrentKitsPack/image17.png"); break;
        case 17: images[i] = LoadTexture( "CurrentKitsPack/image18.png"); break;
        case 18: images[i] = LoadTexture( "CurrentKitsPack/image19.png"); break;
        case 19: images[i] = LoadTexture( "CurrentKitsPack/image20.png"); break;

      }

    }
      SerieA = LoadTexture("grafica/SerieAlogo.png");
      CoppaItalia = LoadTexture("grafica/CoppaItalialogo.png");
      Tutorial = LoadTexture("grafica/Tutorial/mouse-scroll-wheel-icon.png");
      menuImage = LoadTexture("grafica/roba.png");
      image = LoadImage("grafica/roba2.png");
      ImageResize(&image, IMAGE_SIZE, IMAGE_SIZE);
      texture = LoadTextureFromImage(image);
      footballPitch[0] = LoadTexture("grafica/1.png");
      footballPitch[1] = LoadTexture("grafica/2.png");
      footballPitch[2] = LoadTexture("grafica/3.png");
        loadinit = 2;
    }

    for (int i = 0; i < GRID_SIZE * GRID_SIZE; ++i) {
        positions[i] = {(i % GRID_SIZE) * IMAGE_SIZE * SPACING_FACTOR, (i / GRID_SIZE) * IMAGE_SIZE * SPACING_FACTOR};
    }
    menu = 0;
    menu1 = 0;
    menu2 = 0;
    rec.x = -20;
    rec.y = 250;
    rec.width = 300;
    rec.height = 20;
    OptionColor = LIGHTGRAY;
    fullscreen = 0;
}

UIMenu::~UIMenu() {
    UnloadTexture(backgroundImage);
    for (int i = 0; i < 8; i++) {
    UnloadTexture(images[i]);
    }
    CloseWindow();
}



// Add this to the UIMenu class implementation
void UIMenu::setMenuState(MenuState state) {
    menuState = state;
}
// Define a variable to store the timer start time
double timerStartTime = 0.0;
// Define a variable to store the timer duration (in seconds)
float loadingTimer = 2.0f; // Adjust the duration as needed
int loadingText = 0;


int UIMenu::displayMenu() {
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        drawBackground();







        if (menu2 == 0) {
          //DrawText("v0.1.4", GetScreenWidth()/5+400, 200, fontSize, WHITE);
            DrawTextEx(font,"v0.1.4", {static_cast<float>(GetScreenWidth()/5+400), 200}, 20, 2, WHITE);
            DrawTextureEx(menuImage, (Vector2){static_cast<float>(GetScreenWidth()/5+20), 20}, 0, 0.25f, WHITE);
            DrawRectangleRounded(rec, 2, 8, Fade(LIGHTGRAY, 0.5f));              // Draw rectangle with rounded edges
            DrawRectangleRoundedLines(rec, 2, 3, 5,BLUE);
          /*  DrawRectangle(0, 250, 400 - 20, 30, YELLOW);
            DrawRectangleLines(0 - 2, 250 - 2, 400 + 4 - 20, 30 + 4, RED);
            DrawRectangleLines(0 - 1, 250 - 1, 400 + 2 - 20, 30 + 2, RED);
            DrawRectangleLines(0, 250, 400 - 20, 30, RED);*/
            //DrawText("GIOCA", 20, 250, fontSize, BLACK);
            DrawTextEx(font,"GIOCA", { 20 , 250 }, 20, 2, BLACK);

        /*    DrawRectangle(0, 350, 400 - 20, 30, YELLOW);
            DrawRectangleLines(0 - 2, 350 - 2, 400 + 4 - 20, 30 + 4, RED);
            DrawRectangleLines(0 - 1, 350 - 1, 400 + 2 - 20, 30 + 2, RED);
            DrawRectangleLines(0, 350, 400 - 20, 30, RED);*/
            DrawRectangleRounded({-20,350,300,20}, 2, 8, Fade(LIGHTGRAY, 0.5f));              // Draw rectangle with rounded edges
            DrawRectangleRoundedLines({-20,350,300,20}, 2, 3, 5,BLUE);
          //  DrawText("OPZIONI", 20, 350, fontSize, BLACK);
            DrawTextEx(font,"OPZIONI", { 20 , 350 }, 20, 2, BLACK);

        /*  DrawRectangle(0, 450, 400 - 20, 30, YELLOW);
            DrawRectangleLines(0 - 2, 450 - 2, 400 + 4 - 20, 30 + 4, RED);
            DrawRectangleLines(0 - 1, 450 - 1, 400 + 2 - 20, 30 + 2, RED);
            DrawRectangleLines(0, 450, 400 - 20, 30, RED);*/
            DrawRectangleRounded({-20,450,300,20}, 2, 8, Fade(LIGHTGRAY, 0.5f));              // Draw rectangle with rounded edges
            DrawRectangleRoundedLines({-20,450,300,20}, 2, 3, 5,BLUE);
          //DrawText("QUIT", 20, 450, fontSize, BLACK);
            DrawTextEx(font,"QUIT", { 20 , 450 }, 20, 2, BLACK);
            // Check if the button is pressed
            if (CheckCollisionPointRec(Vector2{ static_cast<float>(GetMouseX()), static_cast<float>(GetMouseY()) },
                                       Rectangle{ 0, 250, 400 - 20, 30 })) {
                if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                    // Set the timer start time
                    timerStartTime = GetTime();
                    std::cout << "gioca" << '\n';
                    loadingText = 1;
                }
                    DrawRectangleRounded(rec, 2, 8, Fade(LIGHTGRAY, 0.5f));

                    //DrawText("GIOCA", 20, 250, fontSize, BLACK);
                    DrawTextEx(font,"GIOCA", { 20 , 250 }, 20, 2, BLACK);

            }

            // Check if the timer is still running
            if (loadingText == 1 && (GetTime() - timerStartTime) < loadingTimer) {
                // Display "loading..." during the timer
                DrawText("Loading...", GetScreenWidth() / 2 - MeasureText("Loading...", fontSize) / 2, 300, fontSize, WHITE);
            } else if (loadingText == 1) {
                // Execute subsequent actions after the timer expires
                menu2 = 1;
                menu1 = 0;
                choice = 0;
                loadingText = 0; // Reset loadingText for the next cycle
            }
            if (CheckCollisionPointRec(Vector2{ static_cast<float>(GetMouseX()), static_cast<float>(GetMouseY()) },
                                       Rectangle{ 0, 350, 400 - 20, 30 })) {
                if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                    // Set the timer start time

                    std::cout << "OPZIONI" << '\n';
                    menu2 = 2;
                }
                DrawRectangleRounded({-20,350,300,20}, 2, 8, Fade(LIGHTGRAY,0.5f));
              //DrawText("QUIT", 20, 450, fontSize, BLACK);
                DrawTextEx(font,"OPZIONI", { 20 , 350 }, 20, 2, BLACK);
            }
            if (CheckCollisionPointRec(Vector2{ static_cast<float>(GetMouseX()), static_cast<float>(GetMouseY()) },
                                       Rectangle{ 0, 450, 400 - 20, 30 })) {
                if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                    // Set the timer start time

                    std::cout << "QUIT" << '\n';
                    CloseWindow();
                }
                DrawRectangleRounded({-20,450,300,20}, 2, 8, Fade(LIGHTGRAY,0.5f));
              //DrawText("QUIT", 20, 450, fontSize, BLACK);
                DrawTextEx(font,"QUIT", { 20 , 450 }, 20, 2, BLACK);
            }
            int imageSize = 200;
            float scale = 0.22f; // Adjust the scaling factor as needed
            for (int i = 0; i < 20; i++)
            {
                int row = i / 5;
                int col = i % 5;
                int x = col * (imageSize * scale + 10) + 10;
                int y = row * (imageSize * scale + 10) + 370;

                DrawTextureEx(images[i], (Vector2){static_cast<float>(x)+470, static_cast<float>(y)}, 0, scale, WHITE);
            }
                DrawTextureEx(SerieA, (Vector2){20, 497}, 0, 0.046f, WHITE);
                DrawTextureEx(CoppaItalia, (Vector2){100, 500}, 0, 0.040f, WHITE);
              //DrawText("PACCHETTO KITS 2023/2024: ", 480, 350, fontSize, WHITE);
                DrawTextEx(font,"PACCHETTO KITS 2023/2024:", { 485 , 350 }, 20, 2, WHITE);
        }

          if(menu2 == 2){
            MainMenuOptions();



          }

        if(menu2 == 1){


          if( menu1 == 6){

            drawPlayerStatusById();

          }
          if( menu1 == 5){

            drawPlayerStatus();

          }
          if( menu1 == 4){

            drawStandings();

          }
          if( menu1 == 3){

            drawCurrentCalendar();

          }
          if( menu1 == 2){

        //    gameplay.simulateRound();
            gameplay.simulateRound(calendarGenerator, *this);
          }
          if( menu1 == 1){

            drawGeneratedCalendar();

          }
            //  drawGeneratedCalendar();
          // Move EndDrawing inside the if block

              if( menu1 == 0){
                drawMenuOptions();
                handleMouseInput();
                //choice = 0;
              }



        }

            EndDrawing();  // Move EndDrawing inside the else block


        if (choice != 0) {
            break;
        }
    }

    return choice;
}

    Camera2D camera = { 0 };
void UIMenu::MainMenuOptions(){


    DrawTextEx(font,TextFormat("OPZIONI", startingYear - 1, startingYear), { 310 , 40 }, 20, 2, YELLOW);
  //DrawText("Torna al menu principale", 400, 80, fontSize, BLACK);
  DrawRectangleRounded({400,80,440,30}, 2, 8, Fade(LIGHTGRAY, 0.5f));
  DrawRectangleRoundedLines({400,80,440,30}, 2, 3, 5,BLUE);
    DrawTextEx(font,"Torna al menu principale", { 400 , 80 }, 20, 2, BLACK);

    DrawRectangleRounded({100,100,40,30}, 2, 8, Fade(OptionColor, 0.5f));
    DrawRectangleRoundedLines({100,100,40,30}, 2, 3, 5,BLUE);
    DrawTextEx(font,"SCHERMO INTERO", { 140 , 100 }, 20, 2, WHITE);
  // Check for interaction with the "Torna al menu principale" text
  if (CheckCollisionPointRec(Vector2{ static_cast<float>(GetMouseX()), static_cast<float>(GetMouseY()) },
                             Rectangle{ 100, 100, 40, 30 })) {
      if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {


            ToggleFullscreen();
            if(fullscreen == 0) {
                    fullscreen = 1;
            }else{
                    fullscreen = 0;
            }





      }

      DrawRectangleRounded({100,100,40,30}, 2, 8, Fade(LIGHTGRAY, 0.5f));
  }
  if (fullscreen == 1){
              OptionColor = GREEN;
  }else{
              OptionColor = LIGHTGRAY;
  }
  if (CheckCollisionPointRec(Vector2{ static_cast<float>(GetMouseX()), static_cast<float>(GetMouseY()) },
                             Rectangle{ 400, 80, 400 - 20, 30 })) {
      if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
          menu2 = 0;
          menu1 = 0;
          choice = 0;
      }
      DrawRectangleRounded({400,80,440,30}, 2, 8, Fade(LIGHTGRAY, 0.5f));
  }


}
void UIMenu::drawGeneratedCalendar() {
  camera.offset = { 0, 0 };
  camera.rotation = 0.0f;
  camera.zoom = 1.0f;
    int c = 0;
    int x = 0;
    int x1 = 70;
    int x2 = 40;
    int y = 0;
    int verticalSpacing = 40; // Initial vertical spacing
    int scrollY = 0;

    // Step 1: Calculate total height and visible height
    int totalHeight = verticalSpacing * calendarGenerator.calendar.size();
    int visibleHeight = GetScreenHeight() - 100; // Adjust this value as needed

    // Handle scrolling based on mouse input
    int mouseY = GetMouseY();

    // Create a Camera2D for scrolling

          BeginMode2D(camera);
  //  camera.target = { 0, static_cast<float>(scrollY) };


    // Check for mouse wheel input
    camera.target.y -= GetMouseWheelMove() * 20.0f;

    // Check for collision with the scrollbar
  /*  if (CheckCollisionPointRec(Vector2{ static_cast<float>(GetMouseX()), static_cast<float>(mouseY) },
                               Rectangle{ 400-40, 40, 80, 800 })) {
        if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
            // Update scrollY based on mouse input
            scrollY = static_cast<int>((static_cast<float>(mouseY - 40) / (visibleHeight - 30)) * (totalHeight - visibleHeight));
            camera.target.y = static_cast<float>(scrollY);
        }
    }*/

    // Begin the 2D drawing mode with the camera


    // Step 2: Calculate scroll percentage
    float scrollPercentage = static_cast<float>(scrollY) / static_cast<float>(totalHeight - visibleHeight);

    // Step 3: Calculate the starting index based on the scroll percentage
    int startIndex = static_cast<int>(scrollPercentage * calendarGenerator.calendar.size());

    // Step 4: Draw matches with the adjusted starting index


    //DrawText(TextFormat("Round: %d------------------",c+1), 10, x1-20, 20, YELLOW);
    DrawTextEx(font,TextFormat("Round: %d------------------",c+1), { 10 , static_cast<float>(x1-20) }, 20, 2, YELLOW);
    for (int i = startIndex; i < calendarGenerator.calendar.size(); ++i) {
        const Match& match = calendarGenerator.calendar[i];

        if (x == 0) {
            c = c + 1;
        }



        //DrawText((match.homeTeam + " vs. " + match.awayTeam).c_str(), 10, x1, 20, WHITE);
        DrawTextEx(font,(match.homeTeam + " vs. " + match.awayTeam).c_str(), { 10 , static_cast<float>(x1) }, 20, 2, WHITE);

        y = y + 1;
        x1 = x1 + 20;

        x = x + 1;

        if (x == 10) {
            x2 = x1;
            x1 = x1 + 20;
            //DrawText(TextFormat("Round: %d------------------",c+1), 10, x1-20, 20, YELLOW);
              DrawTextEx(font,TextFormat("Round: %d------------------",c+1), { 10 , static_cast<float>(x1-20) }, 20, 2, YELLOW);


            x = 0;
        }

        // Check if the visible area is filled
        if (verticalSpacing > visibleHeight) {
            break;
        }
    }

    // Draw scrollbar
    EndMode2D();
/*DrawRectangle(400, 80, 400 - 20, 30, YELLOW);
    DrawRectangleLines(400 - 2, 80 - 2, 400 + 4 - 20, 30 + 4, RED);
    DrawRectangleLines(400 - 1, 80 - 1, 400 + 2 - 20, 30 + 2, RED);
    DrawRectangleLines(400, 80, 400 - 20, 30, RED);*/
    DrawRectangleRounded({400,80,440,30}, 2, 8, Fade(LIGHTGRAY, 0.5f));
    DrawRectangleRoundedLines({400,80,440,30}, 2, 3, 5,BLUE);
    DrawTextureEx(Tutorial, (Vector2){400, 120}, 0, 0.2f, WHITE);
    // Calculate scrollbar position based on scroll percentage
    float scrollbarY = 40 + (visibleHeight - 30) * scrollPercentage;
    //DrawRectangle(400-20, scrollbarY, 20, 80, GRAY);

    // Draw additional UI elements
    //DrawText(TextFormat("  Calendario Generato anno: %d/%d ", startingYear - 1, startingYear), 310, 10, fontSize, WHITE);
      DrawTextEx(font,TextFormat("  Calendario Generato anno: %d/%d ", startingYear - 1, startingYear), { 310 , 10 }, 20, 2, YELLOW);
    //  DrawText(TextFormat("  roba v0.1.0", startingYear - 1, startingYear), 310, 40, fontSize, WHITE);
      DrawTextEx(font,TextFormat("  roba v0.1.0", startingYear - 1, startingYear), { 310 , 40 }, 20, 2, YELLOW);
    //DrawText("Torna al menu principale", 400, 80, fontSize, BLACK);
      DrawTextEx(font,"Torna al menu principale", { 400 , 80 }, 20, 2, BLACK);

    // Check for interaction with the "Torna al menu principale" text
    if (CheckCollisionPointRec(Vector2{ static_cast<float>(GetMouseX()), static_cast<float>(mouseY) },
                               Rectangle{ 400, 80, 400 - 20, 30 })) {
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            menu1 = 0;
            choice = 0;
        }
        DrawRectangleRounded({400,80,440,30}, 2, 8, Fade(LIGHTGRAY, 0.5f));
    }

    // End the 2D drawing mode

}

void UIMenu::drawCurrentCalendar() {
  camera.offset = { 0, 0 };
  camera.rotation = 0.0f;
  camera.zoom = 1.0f;
    int c = 0;
    int x = 0;
    int x1 = 70;
    int x2 = 40;
    int y = 0;
    int verticalSpacing = 40; // Initial vertical spacing
    int scrollY = 0;

    // Step 1: Calculate total height and visible height
    int totalHeight = verticalSpacing * calendarGenerator.calendar.size();
    int visibleHeight = GetScreenHeight() - 100; // Adjust this value as needed

    // Handle scrolling based on mouse input
    int mouseY = GetMouseY();

    // Create a Camera2D for scrolling

          BeginMode2D(camera);
  //  camera.target = { 0, static_cast<float>(scrollY) };


    // Check for mouse wheel input
    camera.target.y -= GetMouseWheelMove() * 20.0f;

    // Check for collision with the scrollbar
  /*  if (CheckCollisionPointRec(Vector2{ static_cast<float>(GetMouseX()), static_cast<float>(mouseY) },
                               Rectangle{ 400-40, 40, 80, 800 })) {
        if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
            // Update scrollY based on mouse input
            scrollY = static_cast<int>((static_cast<float>(mouseY - 40) / (visibleHeight - 30)) * (totalHeight - visibleHeight));
            camera.target.y = static_cast<float>(scrollY);
        }
    }*/

    // Begin the 2D drawing mode with the camera


    // Step 2: Calculate scroll percentage
    float scrollPercentage = static_cast<float>(scrollY) / static_cast<float>(totalHeight - visibleHeight);

    // Step 3: Calculate the starting index based on the scroll percentage
    int startIndex = static_cast<int>(scrollPercentage * calendarGenerator.calendar.size());

    // Step 4: Draw matches with the adjusted starting index


    //DrawText(TextFormat("Round: %d------------------",c+1), 10, x1-20, 20, YELLOW);
      DrawTextEx(font,TextFormat("Round: %d------------------",c+1), { 10 , static_cast<float>(x1-20) }, 20, 2, YELLOW);
    for (int i = startIndex; i < calendarGenerator.calendar.size(); ++i) {
        const Match& match = calendarGenerator.calendar[i];

        if (x == 0) {
            c = c + 1;
        }



      //DrawText((match.homeTeam + " vs. " + match.awayTeam).c_str(), 10, x1, 20, WHITE);
        DrawTextEx(font,(match.homeTeam + " vs. " + match.awayTeam).c_str(), { 10 , static_cast<float>(x1) }, 20, 2, WHITE);

        y = y + 1;
        x1 = x1 + 20;

        x = x + 1;

        if (x == 10) {
            x2 = x1;
            x1 = x1 + 20;
            //DrawText(TextFormat("Round: %d------------------",c+1), 10, x1-20, 20, YELLOW);
            DrawTextEx(font,TextFormat("Round: %d------------------",c+1), { 10 , static_cast<float>(x1-20) }, 20, 2, YELLOW);


            x = 0;
        }

        // Check if the visible area is filled
        if (verticalSpacing > visibleHeight) {
            break;
        }
    }

    // Draw scrollbar
    EndMode2D();
    /*DrawRectangle(400, 80, 400 - 20, 30, YELLOW);
    DrawRectangleLines(400 - 2, 80 - 2, 400 + 4 - 20, 30 + 4, RED);
    DrawRectangleLines(400 - 1, 80 - 1, 400 + 2 - 20, 30 + 2, RED);
    DrawRectangleLines(400, 80, 400 - 20, 30, RED);*/
    DrawRectangleRounded({400,80,440,30}, 2, 8, Fade(LIGHTGRAY, 0.5f));
    DrawRectangleRoundedLines({400,80,440,30}, 2, 3, 5,BLUE);
    DrawTextureEx(Tutorial, (Vector2){400, 120}, 0, 0.2f, WHITE);
    // Calculate scrollbar position based on scroll percentage
    float scrollbarY = 40 + (visibleHeight - 30) * scrollPercentage;
    //DrawRectangle(400-20, scrollbarY, 20, 80, GRAY);

    // Draw additional UI elements
    //DrawText(TextFormat("  Calendario Corrente anno: %d/%d ", startingYear - 1, startingYear), 310, 10, fontSize, WHITE);
      DrawTextEx(font,TextFormat("  Calendario Generato anno: %d/%d ", startingYear - 1, startingYear), { 310 , 10 }, 20, 2, YELLOW);
    //DrawText(TextFormat("  roba v0.1.0", startingYear - 1, startingYear), 310, 40, fontSize, WHITE);
      DrawTextEx(font,TextFormat("  roba v0.1.0", startingYear - 1, startingYear), { 310 , 40 }, 20, 2, YELLOW);
    //DrawText("Torna al menu principale", 400, 80, fontSize, BLACK);
      DrawTextEx(font,"Torna al menu principale", { 400 , 80 }, 20, 2, BLACK);

    // Check for interaction with the "Torna al menu principale" text
    if (CheckCollisionPointRec(Vector2{ static_cast<float>(GetMouseX()), static_cast<float>(mouseY) },
                               Rectangle{ 400, 80, 400 - 20, 30 })) {
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            menu1 = 0;
            choice = 0;
        }
        DrawRectangleRounded({400,80,440,30}, 2, 8, Fade(LIGHTGRAY, 0.5f));
    }

    // End the 2D drawing mode

}
int sortedTeams= 0;
void UIMenu::drawStandings() {


    // Clear the background


    // Assuming you have a font loaded, set font size, and position
    // Load your font and set its size
    // Font font = LoadFontEx("your_font.ttf", font_size, 0, 250);

    // Draw the standings title
    DrawTextEx(font,"-----Classifica-----", {static_cast<float>(GetScreenWidth() / 2 - MeasureText("-----Classifica-----", 20) / 2), 20}, 20, 2, WHITE);

    DrawTextEx(font,"roba v0.1.0", {static_cast<float>(GetScreenWidth() / 2 + 140), 20}, 20, 2, WHITE);

    // Assuming teams is an array or vector of SerieATeam
    if(sortedTeams=0){
      std::sort(calendarGenerator.teams.begin(), calendarGenerator.teams.end(), [](const SerieATeam& a, const SerieATeam& b) {
          return a.points > b.points;
          sortedTeams = 1;
      });

    }
    /*DrawRectangle(400, 80, 400 - 20, 30, YELLOW);
    DrawRectangleLines(400 - 2, 80 - 2, 400 + 4 - 20, 30 + 4, RED);
    DrawRectangleLines(400 - 1, 80 - 1, 400 + 2 - 20, 30 + 2, RED);
    DrawRectangleLines(400, 80, 400 - 20, 30, RED);*/
    DrawRectangleRounded({400,80,440,30}, 2, 8, Fade(LIGHTGRAY, 0.5f));
    DrawRectangleRoundedLines({400,80,440,30}, 2, 3, 5,BLUE);
  //DrawText("Torna al menu principale", 400, 80, fontSize, BLACK);
    DrawTextEx(font,"Torna al menu principale", { 400 , 80 }, 20, 2, BLACK);

    // Draw standings
    for (size_t i = 0; i < calendarGenerator.teams.size(); i++) {
        // Convert points to a string
        std::string pointsString = std::to_string(calendarGenerator.teams[i].points);

        // Display team name and points
        DrawTextEx(font,TextFormat("%d  ",i+1), {20, static_cast<float>(50 + i * 22)}, 20, 2, WHITE);
        DrawTextEx(font,calendarGenerator.teams[i].name.c_str(), {50, static_cast<float>(50 + i * 22)}, 20, 2, WHITE);
        DrawTextEx(font,("Points: " + pointsString).c_str(), {200, static_cast<float>(50 + i * 22)}, 20, 2, WHITE);
    }
    if (CheckCollisionPointRec(Vector2{ static_cast<float>(GetMouseX()), static_cast<float>(GetMouseY()) },
                               Rectangle{ 400, 80, 400 - 20, 30 })) {
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            menu1 = 0;
            choice = 0;
        }
        DrawRectangleRounded({400,80,440,30}, 2, 8, Fade(LIGHTGRAY, 0.5f));
    }

    // Unload your font
    // UnloadFont(font);


}
#define MAX_INPUT_CHARS     20
char name[MAX_INPUT_CHARS + 1] = "\0";    // Assuming a maximum team name length of 255 characters
int letterCount = 0;
void UIMenu::drawPlayerStatus() {
    // Clear the screen

    camera.offset = { 0, 0 };
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;
    // Draw Player Status for Each Team
    DrawTextEx(font,"Stato di tutti i giocatori:", {400, 10}, 20, 2, WHITE);
    DrawTextEx(font,TextFormat("roba v0.1.0", startingYear - 1, startingYear), {400, 40}, 20, 2, WHITE);
    /*DrawRectangle(400, 80, 400 - 20, 30, YELLOW);
    DrawRectangleLines(400 - 2, 80 - 2, 400 + 4 - 20, 30 + 4, RED);
    DrawRectangleLines(400 - 1, 80 - 1, 400 + 2 - 20, 30 + 2, RED);
    DrawRectangleLines(400, 80, 400 - 20, 30, RED);*/
    DrawRectangleRounded({400,80,440,30}, 2, 8, Fade(LIGHTGRAY, 0.5f));
    DrawRectangleRoundedLines({400,80,440,30}, 2, 3, 5,BLUE);
    DrawTextEx(font,"Torna al menu principale", {400, 80}, 20, 2, BLACK);
    BeginMode2D(camera);
//  camera.target = { 0, static_cast<float>(scrollY) };


// Check for mouse wheel input
    camera.target.y -= GetMouseWheelMove() * 20.0f;
    int teamNameOffset = 70;
    int playerInfoOffset = 100; // Initial offset for player information

    for (const std::string& teamName : calendarGenerator.originalTeamNames) {
        auto teamIt = std::find_if(calendarGenerator.teams.begin(), calendarGenerator.teams.end(), [&teamName](const SerieATeam& team) {
            return team.name == teamName;
        });

        if (teamIt != calendarGenerator.teams.end()) {
            const SerieATeam& team = *teamIt;
            std::string teamInfo = team.name + ":";
            DrawTextEx(font,teamInfo.c_str(), {10, static_cast<float>(teamNameOffset)}, 20, 2, WHITE);

            for (const Player& player : team.players) {
                std::string playerInfo = "Player " + std::to_string(player.id) + " (" + player.name + ") status: " + std::to_string(player.status);
                DrawTextEx(font,playerInfo.c_str(), {10, static_cast<float>(playerInfoOffset)}, 20, 2, WHITE);
                playerInfoOffset += 30; // Adjust the spacing between players

                // Add extra space after a specific player ID (e.g., 11)
                if (player.id == 11) {
                    playerInfoOffset += 40;
                }
            }



            // Add extra space between teams
            playerInfoOffset += 20;
            teamNameOffset = playerInfoOffset-30; // Update team name offset for the next team
        }
    }

    EndMode2D();

    Rectangle textBox = { GetScreenWidth()/2.0f + 20, 350, 340, 50 };
    bool mouseOnText = false;
    int framesCounter = 0;
    if (CheckCollisionPointRec(GetMousePosition(), textBox)) mouseOnText = true;
    else mouseOnText = false;
    if (mouseOnText)
    {
        // Set the window's cursor to the I-Beam
        SetMouseCursor(MOUSE_CURSOR_IBEAM);

        // Get char pressed (unicode character) on the queue
        int key = GetCharPressed();

        // Check if more characters have been pressed on the same frame
        while (key > 0)
        {
            // NOTE: Only allow keys in range [32..125]
            if ((key >= 32) && (key <= 125) && (letterCount < MAX_INPUT_CHARS))
            {
                name[letterCount] = (char)key;
                name[letterCount+1] = '\0'; // Add null terminator at the end of the string.
                letterCount++;
            }

            key = GetCharPressed();  // Check next character in the queue
        }

        if (IsKeyPressed(KEY_BACKSPACE))
        {
            letterCount--;
            if (letterCount < 0) letterCount = 0;
            name[letterCount] = '\0';
        }
    }
    else SetMouseCursor(MOUSE_CURSOR_DEFAULT);

    if (mouseOnText) framesCounter++;
    else framesCounter = 0;

    // Check for search input
    DrawTextEx(font,"Ricerca Team\nInserisci nome Team\nPremi invio per confermare", {440, 250}, 20, 2, WHITE);
    DrawRectangleRec(textBox, LIGHTGRAY);
    if (mouseOnText) DrawRectangleLines((int)textBox.x, (int)textBox.y, (int)textBox.width, (int)textBox.height, RED);
    else DrawRectangleLines((int)textBox.x, (int)textBox.y, (int)textBox.width, (int)textBox.height, DARKGRAY);

    DrawTextEx(font,name, {static_cast<float>((int)textBox.x + 5), static_cast<float>((int)textBox.y + 8)}, 40, 2, MAROON);

    //DrawText(TextFormat("INPUT CHARS: %i/%i", letterCount, MAX_INPUT_CHARS), 540, 300, 20, DARKGRAY);


    for(int i = 0; i < 20; i++){
          if(name == calendarGenerator.teamNames[i] && IsKeyPressed(KEY_ENTER)){
            //std::cout << calendarGenerator.teamNames[i] << '\n';
            camera.target.y =370*i;
            for(int x = 0; x < MAX_INPUT_CHARS+1;x++){
            letterCount--;
            if (letterCount < 0) letterCount = 0;
            name[x]=  '\0';
            }
          }

    }


    if (mouseOnText)
    {
        if (letterCount < MAX_INPUT_CHARS)
        {
            // Draw blinking underscore char
            if (((framesCounter/20)%2) == 0) DrawTextEx(font,"_", {static_cast<float>((int)textBox.x + 8 + MeasureText(name, 40)), static_cast<float>((int)textBox.y + 12)}, 40, 2, MAROON);
        }
        else DrawTextEx(font,"Press BACKSPACE to delete chars...", {230, 400}, 20, 2, GRAY);
    }
    DrawTextureEx(Tutorial, (Vector2){400, 120}, 0, 0.2f, WHITE);
    if (CheckCollisionPointRec(Vector2{ static_cast<float>(GetMouseX()), static_cast<float>(GetMouseY()) },
                               Rectangle{ 400, 80, 400 - 20, 30 })) {
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            menu1 = 0;
            choice = 0;
            camera.target.y = 0;
        }
        DrawRectangleRounded({400,80,440,30}, 2, 8, Fade(LIGHTGRAY, 0.5f));
    }

    // End drawing

}
bool UIMenu::IsAnyKeyPressed()
{
    bool keyPressed = false;
    int key = GetKeyPressed();

    if ((key >= 32) && (key <= 126)) keyPressed = true;

    return keyPressed;
}
int UIMenu::GetIntInput() {
    int input = 0;
    while (true) {
        input = GetKeyPressed();
        if (input >= KEY_ZERO && input <= KEY_NINE) {
            break;
        }
    }
    return input - KEY_ZERO;
}
void UIMenu::drawPlayerStatusById() {
    // Clear the screen


    // Draw Player Status by ID
    DrawTextEx(font,"Enter Team ID:", {10, 10}, 20, 2, WHITE);
    int teamID = GetIntInput();

    DrawTextEx(font,"Enter Player ID:", {10, 40}, 20, 2, WHITE);
    int playerID = GetIntInput();

    // Draw Player Information
    DrawTextEx(font,"Player Status by ID:", {10, 80}, 20, 2, WHITE);

    // Print player information based on the provided indices
    calendarGenerator.printPlayerById(teamID, playerID);

    // Draw a button
    DrawRectangle(400, 150, 400 - 20, 30, YELLOW);
    DrawRectangleLines(400 - 2, 150 - 2, 400 + 4 - 20, 30 + 4, RED);
    DrawRectangleLines(400 - 1, 150 - 1, 400 + 2 - 20, 30 + 2, RED);
    DrawRectangleLines(400, 150, 400 - 20, 30, RED);
    DrawTextEx(font,"Back to Main Menu", {400, 150}, 20, 2, WHITE);

    // Handle user input
    if (CheckCollisionPointRec(Vector2{ static_cast<float>(GetMouseX()), static_cast<float>(GetMouseY()) },
                               Rectangle{ 400, 150, 400 - 20, 30 })) {
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            // Handle the desired action when the button is pressed
            // For example, go back to the main menu
            menu1 = 0;
            choice = 0;
        }
    }

    // End drawing

}
float Lerp(float start, float end, float t) {
    return start + t * (end - start);
}

int xPosition = 0;
int n2 = 0;
float easeOutQuad(float t) {
    return 1.0f - (1.0f - t) * (1.0f - t);
}

void UIMenu::drawBackground() {
    ClearBackground((Color){0x24, 0x24, 0x24, 0xFF});

    // Get the time elapsed since the last frame
    float deltaTime = GetFrameTime();

    // Increase the SPEED value for faster movement


    // Update positions for movement based on delta time
    for (int i = 0; i < GRID_SIZE * GRID_SIZE; ++i) {
        // Calculate the target position
        float targetX = positions[i].x + SPEED * deltaTime;
        float targetY = positions[i].y - SPEED * deltaTime;

        // Use easing function to smooth the movement
        float t = easeOutQuad(deltaTime);
        positions[i].x = Lerp(positions[i].x, targetX, t);
        positions[i].y = Lerp(positions[i].y, targetY, t);

        // Reset positions when images move out of the screen
        if (positions[i].x > GetScreenWidth() + 440) {
            positions[i].x -= GRID_SIZE * IMAGE_SIZE * SPACING_FACTOR + 10; // Move to the leftmost side
        }
        if (positions[i].y < -500) {
            positions[i].y += GRID_SIZE * IMAGE_SIZE * SPACING_FACTOR + 10; // Respawn on the bottom side
        }

        // Draw the images for the entire grid
        DrawTexture(texture, positions[i].x - (i / 10) * 50, positions[i].y, WHITE);
    }
}


//int round = 0;

void UIMenu::drawMenuOptions() {

  for (int i = 1; i < 7; i++) {
      /*DrawRectangle(10, 10 + i * spacing, 280, 30, YELLOW);
      DrawRectangleLines(10 - 2, 10 - 2 + i * spacing, 280 + 4, 30 + 4, RED);
      DrawRectangleLines(10 - 1, 10 - 1 + i * spacing, 280 + 2, 30 + 2, RED);
      DrawRectangleLines(10, 10 + i * spacing, 280, 30, RED);*/
      DrawRectangleRounded({-20,static_cast<float>(10 + i * spacing),300,20}, 2, 8, Fade(LIGHTGRAY, 0.5f));              // Draw rectangle with rounded edges
      DrawRectangleRoundedLines({-20,static_cast<float>(10 - 2 + i * spacing),300,20}, 2, 3, 5,BLUE);
  }
    DrawTextEx(font,"Options: \t\t\t roba v0.1.0 \t --MENU PRINCIPALE--", {10, 10}, 20, 2, WHITE);
    DrawTextEx(font,"Genera Calendario Serie A", {10, static_cast<float>(10 + spacing)}, 20, 2, BLACK);
    DrawTextEx(font,"Simula prima partita della giornata o partita successiva", {10, static_cast<float>(10 + 2 * spacing)}, 20, 2, BLACK);
    DrawTextEx(font,"Calendario corrente", {10, static_cast<float>(10 + 3 * spacing)}, 20, 2, BLACK);
    DrawTextEx(font,"Classifica", {10, static_cast<float>(10 + 4 * spacing)}, 20, 2, BLACK);
    DrawTextEx(font,"Stato di tutti i giocatori", {10, static_cast<float>(10 + 5 * spacing)}, 20, 2, BLACK);
    //DrawText("Stato di un giocatore specifico", 10, 10 + 6 * spacing, fontSize, WHITE);
    DrawTextEx(font,"Quit", {10, static_cast<float>(10 + 6 * spacing)}, 20, 2, BLACK);





}
bool UIMenu::GuiMessageBoxYesNo(const char *title, const char *message) {
    int buttonWidth = 100;
    int buttonHeight = 30;
    int screenWidth = GetScreenWidth();
    int screenHeight = GetScreenHeight();

    Rectangle messageBoxRect = { static_cast<float>(screenWidth / 4), static_cast<float>(screenHeight / 4), static_cast<float>(screenWidth / 2), static_cast<float>(screenHeight / 2) };
    Rectangle yesButtonRect = { messageBoxRect.x + messageBoxRect.width / 4 - buttonWidth / 2, messageBoxRect.y + messageBoxRect.height - 100, static_cast<float>(buttonWidth), static_cast<float>(buttonHeight) };
    Rectangle noButtonRect = { messageBoxRect.x + 3 * messageBoxRect.width / 4 - buttonWidth / 2, messageBoxRect.y + messageBoxRect.height - 100, static_cast<float>(buttonWidth), static_cast<float>(buttonHeight) };

    bool confirm = false;

    while (!WindowShouldClose()) {
        int mouseX = GetMouseX();
        int mouseY = GetMouseY();

        bool isMouseButtonPressed = IsMouseButtonPressed(MOUSE_LEFT_BUTTON);

        BeginDrawing();
        ClearBackground(RAYWHITE);
        drawBackground();
        /*DrawRectangleRec(messageBoxRect, YELLOW);
        DrawRectangleLines(messageBoxRect.x - 2, messageBoxRect.y - 2, messageBoxRect.width + 4, messageBoxRect.height + 4, RED);
        DrawRectangleLines(messageBoxRect.x - 1, messageBoxRect.y - 1, messageBoxRect.width + 2, messageBoxRect.height + 2, RED);
        DrawRectangleLines(messageBoxRect.x, messageBoxRect.y, messageBoxRect.width,messageBoxRect.height, RED);*/
        DrawRectangleRounded({messageBoxRect.x,messageBoxRect.y,messageBoxRect.width,messageBoxRect.height}, 0.2, 28, Fade(LIGHTGRAY, 0.5f));              // Draw rectangle with rounded edges
        DrawRectangleRoundedLines({messageBoxRect.x,messageBoxRect.y,messageBoxRect.width,messageBoxRect.height}, 0.2, 28, 5,BLUE);
        DrawTextEx(font,message, {messageBoxRect.x + 20, messageBoxRect.y + 20}, 20, 2, WHITE);

      /*DrawRectangleRec(yesButtonRect, YELLOW);
        DrawRectangleLines(yesButtonRect.x - 2, yesButtonRect.y - 2, yesButtonRect.width + 4, yesButtonRect.height + 4, RED);
        DrawRectangleLines(yesButtonRect.x - 1, yesButtonRect.y - 1, yesButtonRect.width + 2, yesButtonRect.height + 2, RED);
        DrawRectangleLines(yesButtonRect.x, yesButtonRect.y, yesButtonRect.width,yesButtonRect.height, RED);*/
        DrawRectangleRounded({yesButtonRect.x,yesButtonRect.y,yesButtonRect.width,yesButtonRect.height}, 2, 8, Fade(LIGHTGRAY, 0.5f));              // Draw rectangle with rounded edges
        DrawRectangleRoundedLines({yesButtonRect.x,yesButtonRect.y,yesButtonRect.width,yesButtonRect.height}, 2, 3, 5,BLUE);
        DrawTextEx(font,"SI", {yesButtonRect.x + 20, yesButtonRect.y + 7}, 20, 2, WHITE);

      /*DrawRectangleRec(noButtonRect, YELLOW);
        DrawRectangleLines(noButtonRect.x - 2, noButtonRect.y - 2, noButtonRect.width + 4, noButtonRect.height + 4, RED);
        DrawRectangleLines(noButtonRect.x - 1, noButtonRect.y - 1, noButtonRect.width + 2, noButtonRect.height + 2, RED);
        DrawRectangleLines(noButtonRect.x, noButtonRect.y, noButtonRect.width,noButtonRect.height, RED);*/
        DrawRectangleRounded({noButtonRect.x,noButtonRect.y,noButtonRect.width,noButtonRect.height}, 2, 8, Fade(LIGHTGRAY, 0.5f));              // Draw rectangle with rounded edges
        DrawRectangleRoundedLines({noButtonRect.x,noButtonRect.y,noButtonRect.width,noButtonRect.height}, 2, 3, 5,BLUE);
        DrawTextEx(font,"NO", {noButtonRect.x + 30, noButtonRect.y + 7}, 20, 2, WHITE);

        if (CheckCollisionPointRec(Vector2{ static_cast<float>(mouseX), static_cast<float>(mouseY) }, yesButtonRect)) {
          if(isMouseButtonPressed){
            confirm = true;
            break;
          }
          DrawRectangleRounded({yesButtonRect.x,yesButtonRect.y,yesButtonRect.width,yesButtonRect.height}, 2, 8, Fade(LIGHTGRAY, 0.5f));
        }

        if (CheckCollisionPointRec(Vector2{ static_cast<float>(mouseX), static_cast<float>(mouseY) }, noButtonRect)) {
          if(isMouseButtonPressed){
            break;
          }
          DrawRectangleRounded({noButtonRect.x,noButtonRect.y,noButtonRect.width,noButtonRect.height}, 2, 8, Fade(LIGHTGRAY, 0.5f));
        }

        EndDrawing();
    }

    return confirm;
}

void UIMenu::handleMouseInput() {
    int mouseX = GetMouseX();
    int mouseY = GetMouseY();

    bool isMouseButtonPressed = IsMouseButtonPressed(MOUSE_LEFT_BUTTON);

    // Check for collision with each option
    for (int i = 1; i <= 6; ++i) {
        if (CheckCollisionPointRec(Vector2{ static_cast<float>(mouseX), static_cast<float>(mouseY) },
                                   Rectangle{ 10, static_cast<float>(10 + i * spacing), 400, 30 })) {
            if (isMouseButtonPressed) {
                choice = i;

                if (choice == 1) {
                    // Show custom confirmation pop-up
                    bool confirm = GuiMessageBoxYesNo("Generazione Calendario", "Sei sicuro di continuare?\nSe non hai simulato tutto\nil calendario l'anno verrà resettato\nSe hai simulato tutto\nil calendario verrà generato\nil calendario per l'anno successivo");

                    if (confirm) {
                        // User selected "Yes"
                        menu1 = 1;
                        startingYear = startingYear + 1;
                    } else {
                        // User selected "No" or closed the dialog
                        choice = 0;
                    }

                }
                if (choice == 3){

                    menu1 = 3;


                }
                if (choice == 4){

                    menu1 = 4;
                    sortedTeams= 0;


                }
                if (choice == 5){

                    menu1 = 5;



                }
                if (choice == 2){

                    menu1 = 2;



                }

              /*  if (choice == 6){

                    menu1 = 6;



                }*/
                std::cout << choice << '\n';
                return;  // Return immediately after setting the choice
            }
              DrawRectangleRounded({ -20, static_cast<float>(10 + i * spacing),300,20}, 2, 8, Fade(LIGHTGRAY, 0.5f));
        }
    }
    choice = 0;
}
