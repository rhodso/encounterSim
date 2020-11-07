#include <main.h>

int main() {
  srand(time(NULL));  // Seed the RNG

  debugger::setDebug(false);
  debugger::logIgnore("Starting...");
  // create sim
  s = sim();

  int simulations = 500;

  // p1 - me
  p1 = entity(0, 1, 18, 11);
  p1.setTeam(0);
  p1.addAction(new action(roll(1, 20), roll(1, 8)));
  p1.addAction(new action(roll(1, 20), roll(1, 8)));
  p1.addAction(new action(roll(1, 20), roll(1, 4)));
  p1.addAction(new action(roll(1, 20), roll(1, 10, +5)));
  entityList.push_back(p1);

  // p2 - fire snake
  p2 = entity(1, 2, 22, 14, 200);
  p2.setTeam(1);
  p2.addAction(new action(roll(1, 20), roll(1, 4, 1)));
  p2.addAction(new action(roll(1, 20), roll(1, 4, 1)));
  entityList.push_back(p2);

  debugger::logIgnore("Starting encounter simulation...");
  int total = 0;

  // Simloop
  for (int i = 0; i < simulations; i++) {
    //Reset sim
    s.clearEntityList();
    s.clearTeamsList();
    std::vector<entity> tmpEntityList;

    //Create copy of entityList
    for (int i = 0; i < entityList.size(); i++) {
      tmpEntityList.push_back(entityList[i]);
    }

    //Add entites to sim
    for (int i = 0; i < entityList.size(); i++) {
      s.addToEntityList(&tmpEntityList[i]);
    }

    //Run the sim
    int res = s.doEncounter();
    if (res == 0) {
      total++;
    }

    tmpEntityList.clear();
  }
  debugger::logIgnore("Simulation complete, team 0 won " +
                      std::to_string(total) + " times");

  return 0;
}
