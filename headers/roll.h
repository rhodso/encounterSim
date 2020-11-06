//Header file auto-generated using CPP-Getter-Setter-Generator
#ifndef ROLL_H
#define ROLL_H

//Includes
#include <debugger.h>
#include <roll.h>

class roll {
	public:
		//Constructor and Destructor
		roll();
		roll(int _diceToRoll, int _diceType); //Modifier defaults to 0 if left unspecified
		roll(int _diceToRoll, int _diceType, int _modifier);
		~roll();

		//Getters and Setters
		int getDiceToRoll();
		int getDiceType();
		int getModifier();

		void setDiceToRoll( int _diceToRoll );
		void setDiceType( int _diceType );
		void setModifier( int _modifier );

		//Other methods
		int rtd();
		
		//Methods to roll the dice without creating object. Modifier defaults to 0 if left unspecified
		static int _rtd(int _diceToRoll, int _diceType);
		static int _rtd(int _diceToRoll, int _diceType, int _modifier);

	private:
		//Variables
		int diceToRoll;
		int diceType;
		int modifier;
};
#endif