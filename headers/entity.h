//Header file auto-generated using CPP-Getter-Setter-Generator
#ifndef ENTITY_H
#define ENTITY_H

//Includes
#include <debugger.h>
#include <action.h>
#include <roll.h>
#include <vector>

class entity {
	public:
		//Constructor and Destructor
		entity();
		entity(int _team, int _cr, int _hp, int _ac);
		entity(int _team, int _cr, int _hp, int _ac, int _xp);
		entity(int _team, int _cr, int _hp, int _ac, int _xp, int _str, int _dex, int _con, int _wis, int _cha);
		~entity();

		//Operators
		bool operator< (const entity &other) const {
			return initiative < other.initiative;
		}

		//Getters and Setters
		int getTeam();
		int getInitiative();
		int getCr();
		int getHp();
		int getAc();
		int getXp();
		int getStr();
		int getDex();
		int getCon();
		int getWis();
		int getCha();

		void setTeam( int _team);
		void setCr( int _cr );
		void setHp( int _hp );
		void setAc( int _ac );
		void setXp( int _xp );
		void setStr( int _str );
		void setDex( int _dex );
		void setCon( int _con );
		void setWis( int _wis );
		void setCha( int _cha );

		//Other methods
		void rollInitiative();
		void addAction(action _a);
		int rollHP(int _diceToRoll, int _diceType, int _modifier);
		int attack(std::vector<std::vector<entity*>> teams);

	private:
		//Variables
		int team; //members of the same team won't attack eachother
		int initiative;
		int cr;
		int hp;
		int ac;
		int xp;
		int str;
		int dex;
		int con;
		int wis;
		int cha;
		std::vector<action> actions;
};
#endif