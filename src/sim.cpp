// Source file auto-generated using CPP-Getter-Setter-Generator

// Includes
#include <sim.h>

// Constructor and Destructor
sim::sim() {}
sim::sim(std::vector<entity *> _entityList) {
  // Make a copy of the vector so that multiple simulations won't affect it
  // Also means we can mutex later
  for (int i = 0; i < _entityList.size(); i++) {
    entityList.push_back(_entityList[i]);
  }
}
sim::~sim() {}

// Getters and Setters
std::vector<entity *> sim::getEntityList() { return entityList; }
std::vector<std::vector<entity *>> sim::getTeams() { return teams; }

void sim::setEntityList(std::vector<entity *> _entityList) {
  entityList = _entityList;
}
void sim::setTeams(std::vector<std::vector<entity *>> _teams) {
  teams = _teams;
}

// Other methods
void sim::clearEntityList() { entityList.clear(); }
void sim::clearTeamsList() { teams.clear(); }
void sim::setupTeams() {
  debugger::log("Started buidling teams");

  // Build teams list from entityList
  int numberOfTeams = -1;
  for (entity *e : entityList) {
    if (numberOfTeams < e->getTeam()) {
      debugger::log("Highest team count is " + std::to_string(e->getTeam()));
      numberOfTeams = e->getTeam();
    }
  }

  debugger::log("Since team numbering starts at 0, there are " +
                std::to_string(numberOfTeams + 1) + " teams");

  // Add teams to vector
  int count = 0;
  debugger::log("Adding empty std::vector<entity*> to teams");
  for (int i = 0; i < numberOfTeams + 1; i++) {
    debugger::log("Count is " + std::to_string(count));
    std::vector<entity *> tmp;
    teams.push_back(tmp);
    count++;
  }

  // Sort entities into team vector
  for (entity *e : entityList) {
    debugger::log("Entity ID is " + e->getID_S() + ", team is " +
                  std::to_string(e->getTeam()));
    teams[e->getTeam()].push_back(e);
    debugger::log("Entity " + e->getID_S() + " sorted into team " +
                  std::to_string(e->getTeam()));
  }

  debugger::log("Listing size of each team");
  for (std::vector<entity *> team : teams) {
    debugger::log("Team size is " + std::to_string(team.size()));
  }
  debugger::log("Finished Listing size of each team");

  debugger::log("Finished buidling teams");
}
void sim::addToEntityList(entity *_e) { entityList.push_back(_e); }
void sim::rollInitiative() {
  debugger::log("Started rolling intiative");

  // Everyone rolls initiative
  for (entity *e : entityList) {
    e->rollInitiative();
  }

  // Make a copy of the entityList
  std::vector<entity *> entityList_copy = entityList;

  // Sort by initiatve
  // hanleded with < operator override in entity class (header file)
  std::sort(entityList_copy.begin(), entityList_copy.end());
  entityList = entityList_copy;

  debugger::log("Finished rolling intiative");
}
int sim::winCheck() {
  debugger::log("Check if anyone's won");
  // Check for win

  // Get number of teams
  int teamsLeft = teams.size();
  debugger::log("Teams size is " + std::to_string(teams.size()));

  // For each team, determine if entire team is dead
  for (std::vector<entity *> team : teams) {
    debugger::log("Started checking next team");
    bool isDead = true;
    for (entity *e : team) {
      debugger::log("Started checking next entity");
      debugger::log("This entity's ID is " + e->getID_S());
      // For each entity in team, determine if dead
      if (e->getHp() > 0) {
        debugger::log("Entity is not dead as hp is " +
                      std::to_string(e->getHp()));
        // if not dead, then team can still win
        isDead = false;
        break;
      } else {
        debugger::log("Entity is dead as getHP() <= 0");
      }
    }
    debugger::log("Finished checking team");
    if (isDead) {
      // If dead then decrement number of teams by 1
      debugger::log("isDead is true, reducing teamsLeft by 1");
      teamsLeft -= 1;

    } else {
      debugger::log("isDead is false");
    }
  }
  debugger::log("Finished checking all teams. TeamsLeft is " +
                std::to_string(teamsLeft));
  return teamsLeft;
}
int sim::doEncounter() {
  // start encounter
  debugger::log("Started encounter");
  setupTeams();

  // Finshed setting up teams
  debugger::log("entityList size = " + std::to_string(entityList.size()));
  debugger::log("teams = " + std::to_string(teams.size()));

  // Stop combat if less than 2 teams are detected
  if (teams.size() < 2) {
    debugger::log("Teams size is less than 2, no combat needs to take place");
    return -1;
  }

  // Roll initiative to determine turn order
  rollInitiative();

  // debugger::setDebug(true);

  debugger::log("Listing turn order");
  for (entity *e : entityList) {
    debugger::log("Entity ID is " + e->getID_S() + ", team is " +
                  std::to_string(e->getTeam()));
  }
  debugger::log("Finished listing turn order");

  // Sim loop
  turn = 0;
  while (teamWon == -1) {
    int teamsLeft = winCheck();
    if (teamsLeft == 1) {
      // Need to find winner
      for (std::vector<entity *> team : teams) {
        int testTeam = -1;
        for (entity *e : team) {
          if (e->getHp() > 0) {
            testTeam = e->getTeam();
            break;
          }
        }
        if (testTeam != -1) {
          debugger::log("They have");
          return testTeam;
        } else {
          continue;
        }
      }
    } else {
      debugger::log("They haven't, calculating damage");
      // Do damage
      if (turn == entityList.size() - 1) {
        turn = 0;
      } else {
        turn++;
      }
      if (entityList[turn]->getHp() > 0) {
        entityList[turn]->attack(teams);
      }
    }
  }

  // This shouldn't happen, but in case it does then it's here to prevent the
  // bad things from happening
  return -1;
}
