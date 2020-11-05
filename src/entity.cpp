//Source file auto-generated using CPP-Getter-Setter-Generator

//Includes
#include <entity.h>

//Constructor and Destructor
entity::entity(){}
entity::~entity(){}

//Getters and Setters
int entity::getCr(){ return cr; }
int entity::getHp(){ return hp; }
int entity::getAc(){ return ac; }
int entity::getXp(){ return xp; }
int entity::getStr(){ return str; }
int entity::getDex(){ return dex; }
int entity::getCon(){ return con; }
int entity::getWis(){ return wis; }
int entity::getCha(){ return cha; }

void entity::setCr( int _cr){ cr = _cr; }
void entity::setHp( int _hp){ hp = _hp; }
void entity::setAc( int _ac){ ac = _ac; }
void entity::setXp( int _xp){ xp = _xp; }
void entity::setStr( int _str){ str = _str; }
void entity::setDex( int _dex){ dex = _dex; }
void entity::setCon( int _con){ con = _con; }
void entity::setWis( int _wis){ wis = _wis; }
void entity::setCha( int _cha){ cha = _cha; }

//Other methods
int entity::rollHP(int _diceToRoll, int _diceType, int _modifier){ debugger::log("Rolling to hit"); roll::_rtd(_diceToRoll, _diceType, _modifier); }
int entity::attack(){}
