#include <main.h>

int main() {
  srand(time(NULL));  // Seed the RNG

  debugger::setDebug(true);
  debugger::logIgnore("Starting...");
  // create sim
  s = sim();

  // p1 - me
  p1 = entity(0, 1, 18, 11);
  p1.addAction(action(roll(1, 20), roll(1, 8, +2)));
  p1.addAction(action(roll(1, 20), roll(1, 8, +2)));
  p1.addAction(action(roll(1, 20), roll(1, 4, +2)));
  p1.addAction(action(roll(1, 20), roll(1, 10, +5)));
  s.addToEntityList(&p1);

  // p2 - fire snake
  p2 = entity(1, 1, 22, 14, 200);
  p2.addAction(action(roll(1, 4, 1), roll(1, 6)));
  p2.addAction(action(roll(1, 4, 1), roll(1, 6)));
  s.addToEntityList(&p2);

  int res = s.doEncounter();
  debugger::logIgnore("Winner is team " + std::to_string(res));

  return 0;
}
