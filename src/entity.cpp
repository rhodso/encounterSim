//Source file auto-generated using CPP-Getter-Setter-Generator

//Includes
#include <entity.h>

//Constructor and Destructor
entity::entity(){}
entity::entity(int _team, int _cr, int _hp, int _ac){
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
entity::entity(int _team, int _cr, int _hp, int _ac, int _xp){
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
entity::entity(int _team, int _cr, int _hp, int _ac, int _xp, int _str, int _dex, int _con, int _wis, int _cha){
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
entity::~entity(){}

//Getters and Setters
int entity::getTeam(){ return team; }
int entity::getCr(){ return cr; }
int entity::getHp(){ return hp; }
int entity::getAc(){ return ac; }
int entity::getXp(){ return xp; }
int entity::getStr(){ return str; }
int entity::getDex(){ return dex; }
int entity::getCon(){ return con; }
int entity::getWis(){ return wis; }
int entity::getCha(){ return cha; }

void entity::setTeam( int _team){ team = _team; }
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
void entity::rollInitiative(){
    initiative = roll::_rtd(1,20);
}
void entity::addAction(action _a){ actions.push_back(_a); }
int entity::rollHP(int _diceToRoll, int _diceType, int _modifier){ debugger::log("Rolling to hit"); return roll::_rtd(_diceToRoll, _diceType, _modifier); }
int entity::attack(std::vector<std::vector<entity*>> teams){
    debugger::log("I am on team " + std::to_string(this->getTeam()));

    std::vector<entity*> targets;
    //For all the teams
    for(std::vector<entity*> t : teams){
        //If the entity is on my team, then don't target them
        if(t[0]->getTeam() == this->getTeam()){
            continue;
        } else { //Else add to a list of targets
            for( entity* e : t){
                targets.push_back(e);
            }
        }
    }

    //Choose a random target
    entity* target = targets[roll::_rtd(1, targets.size())];
    debugger::log("Target found, team" + std::to_string(target->getTeam()));

    //Get a list of valid actions 
    std::vector<action*> validActions;
    for(action a : actions){
        if(a.getUseCount() == 0){
            continue;
        } else {
            validActions.push_back(&a);
        }
    }

    //Select an action at random
    action* selectedAction = validActions[roll::_rtd(1,validActions.size())];
    selectedAction->decrementUseCount();
    debugger::log("Action selected. Decremented useCount");
    
    //Roll to hit
    if(selectedAction->rollHit() > target->getAc()){
        debugger::log("Attack hits, rolling damage");
        int dmg = selectedAction->rollDamage();
        debugger::log("Attack does " + std::to_string(dmg));
        return dmg;        
    } else {
        debugger::log("Attack misses");
        return 0;
    }
}
