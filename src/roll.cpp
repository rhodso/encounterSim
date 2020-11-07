// Source file auto-generated using CPP-Getter-Setter-Generator

// Includes
#include <roll.h>

#include <random>

// Constructor and Destructor
roll::roll() {}
roll::roll(int _diceToRoll, int _diceType) {
  diceToRoll = _diceToRoll;
  diceType = _diceType;
  modifier = 0;
}
roll::roll(int _diceToRoll, int _diceType, int _modifier) {
  diceToRoll = _diceToRoll;
  diceType = _diceType;
  modifier = _modifier;
}
roll::~roll() {}

// Getters and Setters
int roll::getDiceToRoll() { return diceToRoll; }
int roll::getDiceType() { return diceType; }
int roll::getModifier() { return modifier; }

void roll::setDiceToRoll(int _diceToRoll) { diceToRoll = _diceToRoll; }
void roll::setDiceType(int _diceType) { diceType = _diceType; }
void roll::setModifier(int _modifier) { modifier = _modifier; }

// Other methods
int roll::rtd() {
  // Create number to store the result
  int result = 0;
  debugger::log("Rolling...");
  debugger::log("diceToRoll = " + std::to_string(diceToRoll) +
                " diceType = " + std::to_string(diceType) +
                " modifier = " + std::to_string(modifier));
  for (int i = 0; i < diceToRoll; i++) {  // Add rolls to result sequentially
    if (diceType == 0) {
      debugger::log("diceType is 0, returning 0");
      return 0 + modifier;
    } else if (diceType == 1) {
      debugger::log("diceType is 1, returning 0");
      return 0 + modifier;
    } else {
      int r = (rand() % diceType) + 1;
      result += r;
      debugger::log("Roll: " + std::to_string((i + 1)) + ": " +
                    std::to_string(r));
    }
  }
  // Get result, and add the modifier
  debugger::log("Result = " + std::to_string(result) + " + " +
                std::to_string(modifier) + " makes " +
                std::to_string((result + modifier)));
  return result + modifier;
}
int roll::_rtd(int _diceToRoll, int _diceType) {
  // Create a temporary object to roll
  debugger::log("Created temporary object to roll, diceType = " +
                std::to_string(_diceType));
  roll r = roll(_diceToRoll, _diceType, 0);
  return r.rtd();
}
int roll::_rtd(int _diceToRoll, int _diceType, int _modifier) {
  // Create a temporary object to roll
  roll r = roll(_diceToRoll, _diceType, _modifier);
  return r.rtd();
}