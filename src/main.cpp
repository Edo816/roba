#include <iostream>
#include "uiMenu.h"
#include "SerieACalendarGenerator.h"
#include "robaEditor.h"
int main() {

    SerieACalendarGenerator generator;
    CoreGameplay gameplay(generator);
    robaFileFormat editor;
    UIMenu uiMenu(generator,gameplay, editor);
    uiMenu.font = LoadFontEx("grafica/Fonts/Font.ttf",40,0,0);
    int choice = 0;
    int currentRound = 0;
    SetTargetFPS(60);
    while ((choice = uiMenu.displayMenu() ) ) {
        switch (choice) {
            case 1:
                generator.generateCalendar();
                //uiMenu.setMenuState(UIMenu::MenuState::GeneratedCalendar);
                gameplay.i2 = 0;
                gameplay.x2 = 0;
                gameplay.n1 = 0;
                gameplay.matchCounter = 0;
                uiMenu.choice = 0;
                break;
            case 2:
                generator.clearConsole();
                generator.simulateCalendar(currentRound);
                uiMenu.choice = 0;
                gameplay.round = gameplay.round + 1;
                break;
            case 3:
                generator.clearConsole();
                std::cout << "  " << std::flush;
                std::cout << "Current Calendar:\n";
                generator.displayCalendar();
                uiMenu.choice = 0;
                break;
            case 4:
                generator.displayStandings();
                uiMenu.choice = 0;
                break;
            case 5:
                generator.displayPlayerStatus();
                uiMenu.choice = 0;
                break;
            case 6:
            uiMenu.menu2 = 0;
            uiMenu.choice = 0;
            break;
          //  case 6:

              /*  int teamIndex, playerIndex;
                generator.clearConsole();
                std::cout << "Inserisci indirizzo squadra:\n"
                                              "Milan: 1\n"
                                              "Inter: 2\n"
                                              "Jumerdus: 3\n"
                                              "Napoli: 4\n"
                                              "Roma: 5\n"
                                              "Lazio: 6\n"
                                              "Atalanta: 7\n"
                                              "Fiorenzuola: 8\n"
                                              "Lecce: 9\n"
                                              "Bologna: 10\n"
                                              "Cagliari: 11\n"
                                              "Udinese: 12\n"
                                              "Torino: 13\n"
                                              "Genoa: 14\n"
                                              "Empoli: 15\n"
                                              "Sassuolo: 16\n"
                                              "Hellas Verona: 17\n"
                                              "Frosinone: 18\n"
                                              "Monza: 19\n"
                                              "Salernitana: 20\n";
                // Simulate the input based on mouse click
                teamIndex = 1;  // You can replace this with the appropriate team index
                playerIndex = 1; // You can replace this with the appropriate player index

                std::cout << "\n\n ";
                generator.printPlayerById(teamIndex, playerIndex);
                std::cout << "\n\n ";*/
                break;
            default:
                choice = 0;
                // No action needed for default
                break;
        }
        choice = 0;
    }

    std::cout << "Exiting the program.\n";
    UnloadFont(uiMenu.font);

    return 0;
}
