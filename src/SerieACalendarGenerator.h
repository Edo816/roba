#ifndef SERIEA_CALENDAR_GENERATOR_H
#define SERIEA_CALENDAR_GENERATOR_H

#include <string>
#include <vector>

class Player {
public:
    Player(int id, const std::string& name);

    int id;
    int status;      // Player status value (0 to 100)
    std::string name; // Player name
};

class SerieATeam {
public:
    SerieATeam(const std::string& name);

    void resetPoints();

    std::string name;
    int points;
    std::vector<Player> players; // List of players for the team
};

struct Match {
    std::string homeTeam;
    std::string awayTeam;
    int homeScore[10];
    int awayScore[10];
};

class SerieACalendarGenerator {
public:
    SerieACalendarGenerator();

    void readPlayerNamesFromFile(const std::string& fileName);

    void displayPlayerStatus();
    void printPlayerById(int teamIndex, int playerIndex) const;

    void generateCalendar();
    bool simulateCalendar(int& currentRound);
    void displayCalendar();
    void displayStandings();

private:


public:
    int totalRounds;
    int numTeams;
    std::vector<std::string> teamNames;
    std::vector<std::string> originalTeamNames; // Store the original order of team names
    std::vector<Match> calendar;
    std::vector<SerieATeam> teams;
    void clearConsole();
};

#endif // SERIEA_CALENDAR_GENERATOR_H
