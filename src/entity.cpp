// Source file auto-generated using CPP-Getter-Setter-Generator

// Includes
#include <entity.h>

// Constructor and Destructor
entity::entity() {
  // Base constructor is always called, update count here
  updateCount();
}
entity::entity(int _team, int _cr, int _hp, int _ac) {
  team = _team;
  cr = _cr;
  hp = _hp;
  ac = _ac;
  xp = 0;
  str = 0;
  dex = 0;
  con = 0;
  wis = 0;
  cha = 0;
}
entity::entity(int _team, int _cr, int _hp, int _ac, int _xp) {
  team = _team;
  cr = _cr;
  hp = _hp;
  ac = _ac;
  xp = _xp;
  str = 0;
  dex = 0;
  con = 0;
  wis = 0;
  cha = 0;
}
entity::entity(int _team, int _cr, int _hp, int _ac, int _xp, int _str,
               int _dex, int _con, int _wis, int _cha) {
  team = _team;
  cr = _cr;
  hp = _hp;
  ac = _ac;
  xp = _xp;
  str = _str;
  dex = _dex;
  con = _con;
  wis = _wis;
  cha = _cha;
}
entity::~entity() {}

void entity::updateCount() {
  this->id = count;
  count++;
}

// Getters and Setters
int entity::getID() { return id; }
int entity::getTeam() { return team; }
int entity::getCr() { return cr; }
int entity::getHp() { return hp; }
int entity::getAc() { return ac; }
int entity::getXp() { return xp; }
int entity::getStr() { return str; }
int entity::getDex() { return dex; }
int entity::getCon() { return con; }
int entity::getWis() { return wis; }
int entity::getCha() { return cha; }

void entity::setTeam(int _team) { team = _team; }
void entity::setCr(int _cr) { cr = _cr; }
void entity::setHp(int _hp) { hp = _hp; }
void entity::setAc(int _ac) { ac = _ac; }
void entity::setXp(int _xp) { xp = _xp; }
void entity::setStr(int _str) { str = _str; }
void entity::setDex(int _dex) { dex = _dex; }
void entity::setCon(int _con) { con = _con; }
void entity::setWis(int _wis) { wis = _wis; }
void entity::setCha(int _cha) { cha = _cha; }

// Other methods
std::string entity::getID_S() { return std::to_string(id); }
void entity::rollInitiative() { initiative = roll::_rtd(1, 20); }
void entity::addAction(action _a) { actions.push_back(_a); }
int entity::rollHP(int _diceToRoll, int _diceType, int _modifier) {
  debugger::log("Rolling to hit");
  return roll::_rtd(_diceToRoll, _diceType, _modifier);
}
void entity::attack(std::vector<std::vector<entity*>> teams) {
  debugger::log("I am on team " + std::to_string(this->getTeam()));
  std::vector<entity*> targets;
  // For all the teams
  for (std::vector<entity*> t : teams) {
    // If the entity is on my team, then don't target them
    if (t.size() == 0) {  // Skip team if empty for some reason
      debugger::log("Team is empty");
      continue;
    }
    if (t[0]->getTeam() == this->getTeam()) {
      debugger::log("Team skipped due to it being the same team");
      continue;
    } else {  // Else add to a list of targets
      for (entity* e : t) {
        if (e->getHp() > 0) {  // Only target entities if not dead
          debugger::log("Found a valid target");
          targets.push_back(e);
        }
      }
    }
  }
  if (targets.size() < 1) {
    debugger::log("0 targets found");
  }

  debugger::log("Got list of targets, size = " +
                std::to_string(targets.size()));

  entity* target;
  if (targets.size() < 2) {
    debugger::log("Targets less than 2, choosing the first available target");
    target = targets[0];
  } else {
    // Choose a random target
    target = targets[roll::_rtd(1, targets.size())];
  }

  debugger::log("Target found, team " + std::to_string(target->getTeam()));
  // Get a list of valid actions
  std::vector<action*> validActions;
  for (action a : actions) {
    if (a.getUseCount() == 0) {
      continue;
    } else {
      validActions.push_back(&a);
    }
  }

  // Select action
  action* selectedAction;
  if (actions.size() < 2) {
    selectedAction = validActions[0];
  } else {
    selectedAction = validActions[roll::_rtd(1, validActions.size())];
  }
  // Select an action at random
  // selectedAction->decrementUseCount();
  debugger::log("Action selected");

  // Roll to hit
  if (selectedAction->rollHit() >= target->getAc()) {
    debugger::log("Attack hits, rolling damage");
    int dmg = selectedAction->rollDamage();
    debugger::log("Attack does " + std::to_string(dmg));
    target->setHp(target->getHp() - dmg);
  } else {
    debugger::log("Attack misses");
  }
}
