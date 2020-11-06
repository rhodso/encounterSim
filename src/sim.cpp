//Source file auto-generated using CPP-Getter-Setter-Generator

//Includes
#include <sim.h>

//Constructor and Destructor
sim::sim(){}
sim::sim(std::vector<entity*> _entityList){
    debugger::log("Started buidling teams");

    //Build teams list from entityList
    int numberOfTeams = 0;
    for(entity* e : entityList){
        if(numberOfTeams < e->getTeam()){
            numberOfTeams = e->getTeam();
        }
    }

    //Add teams to vector
    for(int i = 0; i < numberOfTeams; i++){
        std::vector<entity*> tmp;
        teams.push_back(tmp);
    }

    //Sort entities into team vector
    for(entity* e : entityList){
        teams[e->getTeam()].push_back(e);
    }

    debugger::log("Finished buidling teams");

}
sim::~sim(){}

//Getters and Setters
std::vector<entity*> sim::getEntityList(){ return entityList; }
std::vector<std::vector<entity*>> sim::getTeams(){ return teams; }

void sim::setEntityList( std::vector<entity*> _entityList){ entityList = _entityList; }
void sim::setTeams( std::vector<std::vector<entity*>> _teams){ teams = _teams; }

//Other methods
void sim::addToEntityList(entity* _e){
    entityList.push_back(_e);
}
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
int sim::doEncounter(){
    debugger::log("Started encounter");
    rollInitiative();
    while(teamWon == -1){
        debugger::log("Check if anyone's won");
        //Check for win
        int teamsLeft = teams.size();
        for(std::vector<entity*> team : teams){
            bool isDead = true;
            for(entity* e : team){
                if(e->getHp() > 0){
                    isDead = false;
                    break;
                }
            }
            if(isDead){
                teamsLeft--;
            }
        }
        if(teamsLeft == 1){
            //Need to find winner
            for(std::vector<entity*> team : teams){
                int testTeam = -1;
                for(entity* e : team){
                    if(e->getHp() > 0){
                        testTeam = e->getTeam();
                        break;
                    }
                }
            debugger::log("They have");
            return testTeam;
        }
        } else {
            debugger::log("They haven't, calculating damage");
            //Do damage
            for(entity* e : entityList){
                if(e->getHp() > 0){
                    e->attack(teams);
                }
            }
        }
    }
    //This shouldn't happen, but in case it does then it's here to prevent the bad things from happening
    return -1;
}
