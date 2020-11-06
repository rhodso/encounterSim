//Header file auto-generated using CPP-Getter-Setter-Generator
#ifndef SIM_H
#define SIM_H

//Includes
#include <entity.h>
#include <debugger.h>
#include <algorithm>

class sim {
	public:
		//Constructor and Destructor
		sim();
		sim(std::vector<entity*> _entityList);
		~sim();

		//Getters and Setters
		std::vector<entity*> getEntityList();
		std::vector<std::vector<entity*>> getTeams();

		void setEntityList( std::vector<entity*> _entityList );
		void setTeams( std::vector<std::vector<entity*>> _teams );

		//Other methods
		void rollInitiative();
		int startEncounter();

	private:
		//Variables
		std::vector<entity*> entityList;
		std::vector<std::vector<entity*>> teams;

};
#endif