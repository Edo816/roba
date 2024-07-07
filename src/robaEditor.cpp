
#include "robaEditor.h"


robaFileFormat::robaFileFormat(){

  #ifdef _WIN32
  fileName = "CurrentKitsPack\\kits-pack.roba";
  #else
  fileName = "CurrentKitsPack/kits-pack.roba";
  #endif

  version = 1.0;
  messageCount = 0;

}


bool robaFileFormat::fileCheck (const std::string& name) {
    std::ifstream f(name.c_str());
    return f.good();
}

void robaFileFormat::CreateFile(){
  #ifdef _WIN32
  std::ofstream outfile ("CurrentKitsPack\\kits-pack.roba");
  #else
  std::ofstream outfile ("CurrentKitsPack/kits-pack.roba");
  #endif
  outfile << "my text here!" << std::endl;

  outfile.close();

}

void robaFileFormat::drawUi(Font& font){
    DrawTextEx(font,TextFormat("ROBA EDITOR - WIP", GetScreenWidth()/2, 20), { 310 , 40 }, 20, 2, YELLOW);
    DrawRectangleRounded({400,80,440,30}, 2, 8, Fade(LIGHTGRAY, 0.5f));
    DrawRectangleRoundedLines({400,80,440,30}, 2, 3, 5,BLUE);
    DrawTextEx(font,"Torna al menu principale", { 400 , 80 }, 20, 2, BLACK);
}

void robaFileFormat::updateUi(int& menu2, int& menu1, int& choice){


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

robaFileFormat::~robaFileFormat() {
    // Destructor implementation
}
