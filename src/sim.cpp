//Source file auto-generated using CPP-Getter-Setter-Generator

//Includes
#include <sim.h>

//Constructor and Destructor
sim::sim(){}
sim::sim(std::vector<entity*> _entityList){
    
}
sim::~sim(){}

//Getters and Setters
std::vector<entity*> sim::getEntityList(){ return entityList; }
std::vector<std::vector<entity*>> sim::getTeams(){ return teams; }

void sim::setEntityList( std::vector<entity*> _entityList){ entityList = _entityList; }
void sim::setTeams( std::vector<std::vector<entity*>> _teams){ teams = _teams; }

//Other methods
void sim::rollInitiative(){
    debugger::log("Started rolling intiative");
    
    //Everyone rolls initiative
    for(entity* e : entityList){
        e->rollInitiative();
    }

    //Make a copy of the entityList
    std::vector<entity*> entityList_copy = entityList;

    //Sort by initiatve
    //hanleded with < operator override in entity class (header file)
    std::sort(entityList_copy.begin(), entityList_copy.end());
    entityList = entityList_copy;

    debugger::log("Finished rolling intiative");
}
int sim::startEncounter(){

}
