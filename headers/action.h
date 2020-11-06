// Header file auto-generated using CPP-Getter-Setter-Generator
#ifndef ACTION_H
#define ACTION_H

// Includes
#include <debugger.h>
#include <roll.h>

class action {
 public:
  // Constructor and Destructor
  action();
  action(roll _hit, roll _damage);
  ~action();

  // Getters and Setters
  roll getHit();
  roll getDamage();
  int getUseCount();

  void setHit(roll _hit);
  void setDamage(roll _damage);
  void setUseCount();

  // Other methods
  void decrementUseCount();
  int rollHit();
  int rollDamage();

 private:
  // Variables
  roll hit;
  roll damage;
  int useCount;
};
#endif