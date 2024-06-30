#include <iostream>
#include "SerieACalendarGenerator.h"
#include <fstream>
#include <algorithm>
#include <vector>
#include <limits>
#include <ctime>
#include <numeric>
#include <chrono>
#include <string>
#include <random>
#include <cstdlib>
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

Player::Player(int id, const std::string& name) : id(id), status(50), name(name) {}

SerieATeam::SerieATeam(const std::string& name) : name(name), points(0) {
    for (int i = 0; i < 11; ++i) {
        std::string playerName = "Player" + std::to_string(i + 1);
        players.push_back(Player(i + 1, playerName));
    }
}

void SerieATeam::resetPoints() {
    points = 0;
}
int n = 1;
int x = 0;
int a = 0;
int homeScore;
int awayScore;
int nTeams = 0;
SerieACalendarGenerator::SerieACalendarGenerator() {
    originalTeamNames = {
        "Milan", "Inter", "Juventus", "Napoli", "Roma", "Lazio", "Atalanta",
        "Fiorenzuola", "Lecce", "Bologna", "Cagliari", "Udinese", "Torino", "Genoa",
        "Empoli", "Sassuolo", "Hellas Verona", "Frosinone", "Monza", "Salernitana"
    };
    teamNames = originalTeamNames;
    numTeams = teamNames.size();

    if (numTeams % 2 != 0) {
        std::cerr << "The number of teams must be even for a balanced schedule." << std::endl;
        exit(1);
    }

    for (const std::string& teamName : teamNames) {
        teams.push_back(SerieATeam(teamName));
    }

    readPlayerNamesFromFile("player_names.txt");
}

void SerieACalendarGenerator::readPlayerNamesFromFile(const std::string& fileName) {
    std::ifstream inputFile(fileName);

 if (!inputFile.is_open()) {
        std::cerr << "Unable to open file: " << fileName << std::endl;
        exit(1);
    }

    for (SerieATeam& team : teams) {
        for (Player& player : team.players) {
            std::getline(inputFile, player.name);
        }
    }

    inputFile.close();
}

void SerieACalendarGenerator::displayPlayerStatus() {
    clearConsole();
    std::cout << "Player Status for Each Team:\n";

    for (const std::string& teamName : teamNames) {
        auto teamIt = std::find_if(teams.begin(), teams.end(), [&teamName](const SerieATeam& team) {
            return team.name == teamName;
        });

        if (teamIt != teams.end()) {
            const SerieATeam& team = *teamIt;
            std::cout << team.name << ": \n\n";

            for (const Player& player : team.players) {
                std::cout << "Player " << player.id << " (" << player.name << ") status: " << player.status << " \n\n";
            }

            std::cout << "\n";
        }
    }
    std::cout << "\n";
}


void SerieACalendarGenerator::printPlayerById(int teamIndex, int playerIndex) const {
    if (teamIndex < teams.size() && playerIndex < teams[teamIndex].players.size()) {
        const Player& player = teams[teamIndex].players[playerIndex];
        std::cout << "Player ID: " << player.id << ", Name: " << player.name << ", Status: " << player.status << "\n";
    } else {
        std::cout << "Invalid team or player index.\n";
    }
}

void SerieACalendarGenerator::generateCalendar() {
    n = 1;  // Reset the round counter to 1 when generating a new calendar  // Reset the match counter to 0
    a = 0;

    // Add teams to the vector...


    // Reset points for all teams and player statuses
    for (SerieATeam& team : teams) {
        team.resetPoints();
        for (Player& player : team.players) {
            player.status = 50; // Reset player status to 50
        }
    }
    int numTeams = teamNames.size();
    totalRounds = 38;
    int matchesPerRound = numTeams / 2;
    bool swapHomeAway = false;
    //std::vector<int> availableTeams(numTeams, 1);
    std::vector<std::vector<std::pair<std::string, std::string>>> schedule(totalRounds);
    calendar.clear();
    system("CLS");
    std::cout << "Flushing the output stream." << std::flush;
    std::srand(static_cast<unsigned int>(std::time(0)));
    std::random_shuffle(teamNames.begin(), teamNames.end());

    for (int round = 0; round < totalRounds / 2; ++round) {
      //  std::cout << "Round " << round + 1 << ":-----------------------------------------------------------------------------------------\n";
        for (int i = 0; i < numTeams / 2; ++i) {

          schedule[round].emplace_back(teamNames[i], teamNames[numTeams - i - 1]);
        }
      std::rotate(teamNames.begin() + 1, teamNames.begin() + numTeams - 1, teamNames.end());
        //ìstd::vector<int> matchOrder(matchesPerRound);
        //iota(matchOrder.begin(), matchOrder.end(), 0);  // Fill with 0, 1, 2, ..., half-1
        //std::random_shuffle(matchOrder.begin(), matchOrder.end());
        /*for (int match = 0; match < matchesPerRound; match++) {
            int homeTeamIndex = matchOrder[match];
            std::cout << homeTeamIndex<< '\n';
            int awayTeamIndex = numTeams - 1 - matchOrder[match];
            std::cout << awayTeamIndex<< '\n';


            std::string homeTeam = teamNames[homeTeamIndex];
            std::string awayTeam = teamNames[awayTeamIndex];

            calendar.push_back({homeTeam, awayTeam, -1, -1});

            std::cout << "Match " << match + 1 << ": \t" << (swapHomeAway ? awayTeam : homeTeam) << "\t vs. \t" << (swapHomeAway ? homeTeam : awayTeam) << "\n";*/
        }

        for (int round = totalRounds / 2; round < totalRounds; ++round) {
            schedule[round] = schedule[round - totalRounds / 2];
            for (auto &match : schedule[round]) {
                std::swap(match.first, match.second);
            }
        }
        for (auto &roundMatches : schedule) {
            std::shuffle(roundMatches.begin(), roundMatches.end(), std::default_random_engine(std::rand()));
        }
        for (int round = 0; round < totalRounds; ++round) {
            std::cout << "Round " << round + 1 << ":\n";
            for (const auto &match : schedule[round]) {
                std::cout << match.first << " vs " << match.second << "\n";
                calendar.push_back({match.first, match.second, -1, -1});
            }
            std::cout << "\n";
        }


        /*rotate(teamNames.begin() + 1, teamNames.begin() + matchesPerRound, teamNames.end());
        if (round == 18) {
              swapHomeAway = true;
        }*/


}
/*  do {
      homeTeamIndex = rand() % numTeams;
  } while (availableTeams[homeTeamIndex] == 0);

  availableTeams[homeTeamIndex] = 0;

  do {
      awayTeamIndex = rand() % numTeams;
  } while (availableTeams[awayTeamIndex] == 0 || homeTeamIndex == awayTeamIndex);

  availableTeams[awayTeamIndex] = 0;
*/
  //std::cout << "Match: " << round + 1 << (swapHomeAway ? teamNames[awayTeamIndex] : teamNames[homeTeamIndex]) << " vs " << (swapHomeAway ? teamNames[homeTeamIndex] : teamNames[awayTeamIndex])  << std::endl;

/*  for (int i = 0; i < numTeams; i++) {
      availableTeams[i] = 1;
  }
*/

bool SerieACalendarGenerator::simulateCalendar(int& currentRound) {
   // Reset the round counter to 1 at the beginning of the simulation

    if (a == 0) {
        currentRound = 0;
        std::cout << "Simulation of Serie A calendar:\n";
    }

    std::cout << "Round: " << n << "\n\n";

    for (int matchIndex = currentRound * (numTeams / 2); matchIndex < (currentRound + 1) * (numTeams / 2); matchIndex++) {
        if (matchIndex >= calendar.size()) {
            return false; // All rounds simulated
        }

        Match& match = calendar[matchIndex];
        std::string homeTeam = match.homeTeam;
        std::string awayTeam = match.awayTeam;

/*        homeScore = rand() % 5;
        awayScore = rand() % 5;

        for (int j = 0; j < 10; j++) {
            match.homeScore[j] = homeScore;
            match.awayScore[j] = awayScore;
        }
          */
        // Update team points based on the match result
    /*    for (SerieATeam& team : teams) {
            if (team.name == homeTeam) {
                if (homeScore > awayScore) {
                    team.points += 3; // Home team wins
                } else if (homeScore == awayScore) {
                    team.points += 1; // Draw
                }
            } else if (team.name == awayTeam) {
                if (awayScore > homeScore) {
                    team.points += 3; // Away team wins
                } else if (awayScore == homeScore) {
                    team.points += 1; // Draw
                }
            }
        }*/

        std::cout << homeTeam << " " << homeScore << " - " << awayScore << " " << awayTeam << "\n\n";
    }

    currentRound = currentRound + 1;
    n = n + 1;
    a = 1;

    return true; // Continue simulation
}


void SerieACalendarGenerator::displayCalendar() {
    clearConsole();
    std::cout << "Current Calendar:\n";

    int c = 0;
    for (const Match& match : calendar) {
        if (x == 0) {
            std::cout << "Round " << c + 1 << ":-----------------------------------------------------------------------------------------\n";
            c = c + 1;
        }
        std::cout << match.homeTeam << " vs. " << match.awayTeam << "\n";
        x = x + 1;
        if (x == 10) {
            x = 0;
        }
    }

    std::cout << "\n";
}

void SerieACalendarGenerator::displayStandings() {
  clearConsole();
  std::cout << "Serie A Standings:\n";
  std::sort(teams.begin(), teams.end(), [](const SerieATeam& a, const SerieATeam& b) {
      return a.points > b.points;
  });

  for (size_t i = 0; i < teams.size(); i++) {
      std::cout << teams[i].name << ": " << teams[i].points << " points\n";
  }
}



void SerieACalendarGenerator::clearConsole() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}
