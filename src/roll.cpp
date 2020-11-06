//Source file auto-generated using CPP-Getter-Setter-Generator

//Includes
#include <roll.h>
#include <random>

//Constructor and Destructor
roll::roll(){
    srand(time(NULL)); // Seed the RNG
}
roll::roll(int _diceToRoll, int _diceType){
    srand(time(NULL)); //Seed the RNG
    diceToRoll = _diceToRoll;
    diceType = _diceType;
    modifier = 0;
}
roll::roll(int _diceToRoll, int _diceType, int _modifier){
    srand(time(NULL)); // Seed the RNG
    diceToRoll = _diceToRoll;
    diceType = _diceType;
    modifier = _modifier;
}
roll::~roll(){}

//Getters and Setters
int roll::getDiceToRoll(){ return diceToRoll; }
int roll::getDiceType(){ return diceType; }
int roll::getModifier(){ return modifier; }

void roll::setDiceToRoll( int _diceToRoll){ diceToRoll = _diceToRoll; }
void roll::setDiceType( int _diceType){ diceType = _diceType; }
void roll::setModifier( int _modifier){ modifier = _modifier; }

//Other methods
int roll::rtd(){
    //Create number to store the result
    int result = 0;
    debugger::log("Rolling...");
    for(int i = 0; i < diceToRoll; i++){ //Add rolls to result sequentially
        int r = (rand() % diceType) + 1;
        result += r;
        debugger::log("Roll: " + std::to_string((i+1)) + ": " + std::to_string(r));
    }
    //Get result, and add the modifier
    debugger::log("Result = " + std::to_string(result) + " + " + std::to_string(modifier) + " makes " + std::to_string((result + modifier)));
    return result + modifier;
}

int roll::_rtd(int _diceToRoll, int _diceType){
    //Create a temporary object to roll
    roll r = roll(_diceToRoll, _diceType, 0);
    return r.rtd();
}
int roll::_rtd(int _diceToRoll, int _diceType, int _modifier){
    //Create a temporary object to roll
    roll r = roll(_diceToRoll, _diceType, _modifier);
    return r.rtd();
}