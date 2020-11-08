#include <main.h>

int runSim(sim s) {
  // Reset sim
  s.clearEntityList();
  s.clearTeamsList();
  std::vector<entity> tmpEntityList;

  mtx.lock();
  // Create copy of entityList
  for (int i = 0; i < entityList.size(); i++) {
    tmpEntityList.push_back(entityList[i]);
  }
  mtx.unlock();

  // Add entites to sim
  for (int i = 0; i < entityList.size(); i++) {
    s.addToEntityList(&tmpEntityList[i]);
  }

  // Run the sim
  int res = s.doEncounter();

  if (res == 0) {
    mtx.lock();
    wins++;
    mtx.unlock();
  }

  tmpEntityList.clear();

  return res;
}

int main() {
  srand(time(NULL));  // Seed the RNG

  debugger::setDebug(false);
  debugger::logIgnore("Starting...");
  // create sim
  s = sim();

  double simulations = 10000.0;
  // double simulations = 1.0;

  // p1 - me
  p1 = entity(0, 1, 18, 11);
  p1.addAction(new action(roll(1, 20), roll(1, 8)));
  p1.addAction(new action(roll(1, 20), roll(1, 8)));
  p1.addAction(new action(roll(1, 20), roll(1, 4)));
  p1.addAction(new action(roll(1, 20), roll(1, 10, +5)));
  entityList.push_back(p1);

  // p2 - fire snake
  p2 = entity(1, 2, 22, 14, 200);
  p2.addAction(new action(roll(1, 20), roll(1, 4, 1)));
  p2.addAction(new action(roll(1, 20), roll(1, 4, 1)));
  entityList.push_back(p2);

  debugger::logIgnore("Starting encounter simulation...");
  std::time_t initTime{
      std::chrono::system_clock::to_time_t(std::chrono::system_clock::now())};
  int total = 0;

  // Start each sim in a new thread for speed
  for (int i = 0; i < simulations; i++) {
    sim aSim;
    std::thread simThread(runSim, aSim);
    simThreads.push_back(std::move(simThread));
  }

  // Wait for all threads to finish
  for (std::thread& t : simThreads) {
    if (t.joinable()) {
      t.join();
    }
  }
  std::string timeStr =
      std::to_string(std::chrono::duration_cast<std::chrono::milliseconds>(
                         std::chrono::system_clock::now() -
                         std::chrono::system_clock::from_time_t(initTime))
                         .count() /
                     1000.0f);

  debugger::logIgnore("Simulation complete, team 0 won " +
                      std::to_string(wins) + " times");
  double winRate = (wins / simulations) * 100;
  debugger::logIgnore("Win rate of " + std::to_string(winRate) + "%");
  debugger::logIgnore("Total sim time = " + timeStr + " seconds");
  return 0;
}
