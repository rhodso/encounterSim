// Source file auto-generated using CPP-Getter-Setter-Generator

// Includes
#include <action.h>

// Constructor and Destructor
action::action() {}
action::action(roll _hit, roll _damage) {
  hit = _hit;
  damage = _damage;
}
action::~action() {}

// Getters and Setters
roll action::getHit() { return hit; }
roll action::getDamage() { return damage; }
int action::getUseCount() { return useCount; }

void action::setHit(roll _hit) { hit = _hit; }
void action::setDamage(roll _damage) { damage = _damage; }

// Other methods
void action::decrementUseCount() { useCount--; }
int action::rollHit() {
  debugger::log("Rolling to hit");
  return hit.rtd();
}
int action::rollDamage() {
  debugger::log("Rolling damage");
  return damage.rtd();
}