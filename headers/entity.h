//Header file auto-generated using CPP-Getter-Setter-Generator
#ifndef ENTITY_H
#define ENTITY_H

//Includes
#include <debugger.h>
#include <action.h>
#include <roll.h>

class entity {
	public:
		//Constructor and Destructor
		entity();
		~entity();

		//Getters and Setters
		int getTeam();
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
		int rollHP(int _diceToRoll, int _diceType, int _modifier);
		int attack();

	private:
		//Variables
		int team; //members of the same team won't attack eachother
		int cr;
		int hp;
		int ac;
		int xp;
		int str;
		int dex;
		int con;
		int wis;
		int cha;

};
#endif