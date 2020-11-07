// Source file auto-generated using CPP-Getter-Setter-Generator

// Includes
#include <sim.h>

// Constructor and Destructor
sim::sim() {}
sim::sim(std::vector<entity *> _entityList) { entityList = _entityList; }
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
void sim::setupTeams() {
  debugger::log("Started buidling teams");

  // Build teams list from entityList
  int numberOfTeams = -1;
  for (entity *e : entityList) {
    if (numberOfTeams < e->getTeam()) {
      debugger::log("Number of teams set to " +
                    std::to_string(e->getTeam() + 1));
      numberOfTeams = e->getTeam();
    }
  }

  // Add teams to vector
  for (int i = 0; i < numberOfTeams; i++) {
    std::vector<entity *> tmp;
    teams.push_back(tmp);
  }

  // Sort entities into team vector
  for (entity *e : entityList) {
    teams[e->getTeam()].push_back(e);
  }

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
int sim::doEncounter() {
  // start encounter
  debugger::log("Started encounter");
  setupTeams();

  // Finshed setting up teams
  debugger::log("entityList size = " + std::to_string(entityList.size()));
  debugger::log("teams = " + std::to_string(teams.size() + 1));

  // Roll initiative to determine turn order
  rollInitiative();

  // Sim loop
  while (teamWon == -1) {
    debugger::log("Check if anyone's won");
    // Check for win

    // Get number of teams
    int teamsLeft = teams.size() + 1;
    debugger::log("Teams size is " + std::to_string(teams.size()));

    // For each team, determine if entire team is dead
    for (std::vector<entity *> team : teams) {
      debugger::log("Started checking next team");
      bool isDead = true;
      for (entity *e : team) {
        debugger::log("Started checking next entity");
        // For each entity in team, determine if dead
        if (e->getHp() > 0) {
          debugger::log("Entity is not dead as getHP() > 0");
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
        teamsLeft--;
      }
    }
    debugger::log("Finished checking all teams");
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
      for (entity *e : entityList) {
        if (e->getHp() > 0) {
          e->attack(teams);
        }
      }
    }
  }
  // This shouldn't happen, but in case it does then it's here to prevent the
  // bad things from happening
  return -1;
}
