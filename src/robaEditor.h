#ifndef ROBA_EDITOR_H
#define ROBA_EDITOR_H
#include <iostream>
#include <fstream>
#include <memory>
#include <vector>
#include <raylib.h>

class robaFileFormat{
public:
  robaFileFormat();
  ~robaFileFormat();

  std::string fileName;
  float version;

  int messageCount;
  bool fileCheck (const std::string& name);
  void CreateFile();
  void saveFile();
  void drawUi(Font& font);
  void updateUi(int& menu2, int& menu1, int& choice);
};



#endif
