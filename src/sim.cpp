//Source file auto-generated using CPP-Getter-Setter-Generator

//Includes
#include <sim.h>

//Constructor and Destructor
sim::sim(){}
sim::~sim(){}

//Getters and Setters
std::vector<entity*> sim::getEntityList(){ return entityList; }
std::vector<std::vector<entity*>> sim::getTeams(){ return teams; }

void sim::setEntityList( std::vector<entity*> _entityList){ entityList = _entityList; }
void sim::setTeams( std::vector<std::vector<entity*>> _teams){ teams = _teams; }

//Other methods
void sim::rollInitiative(){}
int sim::startEncounter(){
    
}
