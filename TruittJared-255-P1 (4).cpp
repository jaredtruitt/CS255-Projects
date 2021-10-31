//******************************************************************************
// Name: Jared Truitt
// File: TruittJared-255-P1.cpp
// Description: Fraction Application that has calculator, 
//                       fraction practice, and fraction equivalence practice
// CS255
// October 5, 2021
//******************************************************************************
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Fraction.h"

int menu();

void calculator();

void practiceFraction();

void fractionEquivalence();

void fractionIncrements();

void fractionGuess(Fraction);

void equivalenceGuess(bool, char);

Fraction calculateFractions(Fraction, Fraction, char);

Fraction generateRandom();
	
int main() {
	srand(time(NULL));
	int choice; //user choice from menu
	
	choice = menu();
	
	if(choice == 1){
		calculator();
	}
	else if(choice == 2){
		practiceFraction();
	}
	else if(choice == 3){
		fractionEquivalence();
	}
	else if(choice == 4){
		fractionIncrements();
	}
	else{
		cout<<"NOT A VALID INPUT."<<endl;
	}
	
	return 0;
}

//**********************************************************************************
// Function Name: Menu
// Brief Function Description: Displays the first menu with description and options
// Return Value: int
// Incoming Parameters: None
// Outgoing Parameters: None
//**********************************************************************************
// Time of Completion: 15 minutes
int menu(){
	int choice = 0;
	cout<<"*************************************************************"<<endl;
	cout<<"******************* FRACTION APPLICATION ********************"<<endl;
	cout<<"*************************************************************"<<endl;
	cout<<"**  This is a fraction application that has a few useful  ***"<<endl;
	cout<<"**    options for calculating and practicing fractions.   ***"<<endl;
	cout<<"*************************************************************"<<endl;
	cout<<"********************* ENTER AN OPTION ***********************"<<endl;
	cout<<"*************************************************************"<<endl;
	cout<<"** [1] - Fraction Calculator ********************************"<<endl;
	cout<<"** [2] - Fraction Practice Problems *************************"<<endl;
	cout<<"** [3] - Fraction Equivalence *******************************"<<endl;
	cout<<"** [4] - Adding/Subtracting Fraction's by 1 Practice ********"<<endl;
	cout<<"*************************************************************"<<endl;
	cin>>choice;
	
	return choice;
}

//**********************************************************************************
// Function Name: Calculator
// Brief Function Description: Calculator that calculates fraction problems from user
// Return Value: None
// Incoming Parameters: None
// Outgoing Parameters: None
//**********************************************************************************
// Time of Completion: 30 minutes
void calculator(){
	Fraction f1, f2, f3;
	char g;
	int quit = 1;
	cout<<"*************************************************************"<<endl;
	cout<<"******************** FRACTION CALCULATOR ********************"<<endl;
	cout<<"*************************************************************"<<endl;
	cout<<"** Enter two fraction's in the form (n/d) with an operand. **"<<endl;
	cout<<"*************************************************************"<<endl;
	while(quit != 0){
		cin>>f1>>g>>f2;
		cout<<"RESULT: ";
		f3 = calculateFractions(f1, f2, g);
		cout<<f3<<endl;
		cout<<"ENTER 1 TO CONTINUE, 0 TO QUIT"<<endl;
		cin>>quit;
	}
}

//**********************************************************************************
// Function Name: practiceFraction
// Brief Function Description: Function that outputs two random fractions with an operand
// Return Value: None
// Incoming Parameters: None
// Outgoing Parameters: None
//**********************************************************************************
// Time of Completion: 30 minutes
void practiceFraction(){
	Fraction f1, f2, f3;
	char g;
	int quit = 1;
	cout<<"*************************************************************"<<endl;
	cout<<"****************** FRACTION PRACTICE PROBLEMS ***************"<<endl;
	cout<<"*************************************************************"<<endl;
	cout<<"**              Enter the answer to the problem.           **"<<endl;
	cout<<"*************************************************************"<<endl;
	while(quit != 0){
		f1 = generateRandom();
		f2 = generateRandom();
		g = "+-*/"[rand() % 4]; //didn't know you could do this, found on stackoverflow
		
		switch(g){ //outputs random fraction with operand
			case '+':
				cout << f1 << " + " << f2 << " = ";
				f3 = calculateFractions(f1, f2, g); //goes to calculate respected problem
				fractionGuess(f3); //goes to check equivalence of user and real answer
				break;
			case '-':
				cout<< f1 << " - " << f2 << " = ";
				f3 = calculateFractions(f1, f2, g);
				fractionGuess(f3);
				break;
			case '*':
				cout<< f1 << " * " << f2 << " = ";
				f3 = calculateFractions(f1, f2, g);
				fractionGuess(f3);
				break;
			case '/':
				cout<< f1 << " / " << f2 << " = ";
				f3 = calculateFractions(f1, f2, g);
				fractionGuess(f3);
				break;
		}
		cin>>quit;
	}
}

//**********************************************************************************
// Function Name: fractionEquivalence
// Brief Function Description: Outputs two random fractions with some inequality/equality sign
// Return Value: None
// Incoming Parameters: None
// Outgoing Parameters: None
//**********************************************************************************
// Time of Completion: 40 minutes
void fractionEquivalence(){
	Fraction f1, f2, f3;
	char g;
	char guess;
	bool result;
	int quit = 1;
	cout<<"*************************************************************"<<endl;
	cout<<"**************** FRACTION EQUIVALENCE PRACTICE **************"<<endl;
	cout<<"*************************************************************"<<endl;
	cout<<"**            Enter 't' for TRUE or 'f' for FALSE          **"<<endl;
	cout<<"*************************************************************"<<endl;
	while(quit != 0){
		f1 = generateRandom();
		f2 = generateRandom();
		g = "abcdef"[rand() % 6];
		
		switch(g){
			case 'a':
				cout << f1 << " <= " << f2 << endl;
				cin>>guess; //gets 't' or 'f' from user
				result = (f1 <= f2); //finds boolean result
				equivalenceGuess(result, guess); //finds equivalence in the user and real answer
				break;
			case 'b':
				cout<< f1 << " < " << f2 << endl;
				cin>>guess;
				result = (f1 < f2);
				equivalenceGuess(result, guess);
				break;
			case 'c':
				cout<< f1 << " > " << f2 << endl;
				cin>>guess;
				result = (f1 > f2);
				equivalenceGuess(result, guess);
				break;
			case 'd':
				cout<< f1 << " >= " << f2 << endl;
				cin>>guess;
				result = (f1 >= f2);
				equivalenceGuess(result, guess);
				break;
			case 'e':
				cout<< f1 << " != " << f2 << endl;
				cin>>guess;
				result = (f1 != f2);
				equivalenceGuess(result, guess);
				break;
			case 'f':
				cout<< f1 << " = " << f2 << endl;
				cin>>guess;
				result = (f1 == f2);
				equivalenceGuess(result, guess);
				break;
		}
		cin>>quit;
	}
}

//**********************************************************************************
// Function Name: fractionIncrements
// Brief Function Description: Outputs a random fraction with either +1 or -1
// Return Value: None
// Incoming Parameters: None
// Outgoing Parameters: None
//**********************************************************************************
// Time of Completion: 35 minutes
void fractionIncrements(){
	cout<<"*************************************************************"<<endl;
	cout<<"************** ADDING/SUBTRACTING BY 1 PRACTICE *************"<<endl;
	cout<<"*************************************************************"<<endl;
	cout<<"**             Enter the answer to the problem             **"<<endl;
	cout<<"*************************************************************"<<endl;
	Fraction f1, f2, guess;
	char g;
	bool result;
	int quit = 1;
	while(quit != 0){
		f1 = generateRandom();
		f2 = 1;
		g = "ab"[rand() % 2];
	
		switch(g){
			case 'a':
				cout<<f1<<" + 1"<<endl; 
				f2 = f1++; //finds fraction + 1
				fractionGuess(f2); //finds equivalence of user and real answer
				break;
			case 'b':
				cout<<f1<<" - 1"<<endl;
				f2 = --f1;
				fractionGuess(f2);
				break;
		}
		cin>>quit;
	}
}

//**********************************************************************************
// Function Name: fractionGuess
// Brief Function Description: Takes a user's answers and sees if the correct answer
//                             is the same as the user's answer
// Return Value: none
// Incoming Parameters: Fraction f3
// Outgoing Parameters: None
//**********************************************************************************
// Time of Completion: 10 minutes
void fractionGuess(Fraction f3){
	Fraction guess;
	cin>>guess;
	if(guess == f3 || isExact(guess, f3)){
		cout<<"CORRECT!"<<endl;
		cout<<"ENTER 1 TO GO AGAIN."<<endl;
		
	}
	else{
		cout<<"INCORRECT!"<<endl;
		cout<<"ANSWER IS: "<<f3<<endl;
		cout<<"ENTER 1 TO TRY AGAIN."<<endl;
	}
	
	
}

//**********************************************************************************
// Function Name: equivalenceGuess
// Brief Function Description: Takes in a user's answer with a boolean result of the correct
//                             answer from the equality praction option. Check's if the
//                             the user's answer is correct and outputs statements accordingly
// Return Value: None
// Incoming Parameters: bool result, char guess
// Outgoing Parameters: None
//**********************************************************************************
// Time of Completion: 10 minutes
void equivalenceGuess(bool result, char guess){
	if(guess == 't' && result){
		cout<<"CORRECT!"<<endl;
		cout<<"ENTER 1 TO CONTINUE, 0 TO QUIT"<<endl;
	}	
	else if(guess == 'f' && !result){
		cout<<"CORRECT!"<<endl;
		cout<<"ENTER 1 TO CONTINUE, 0 TO QUIT"<<endl;
	}
	else{
		cout<<"INCORRECT!"<<endl;
		cout<<"ENTER 1 TO CONTINUE, 0 TO QUIT"<<endl;
	}
}

//**********************************************************************************
// Function Name: calculateFractions
// Brief Function Description: takes in two fractions and uses a switch statement to
//                             calculate the user input OR the fraction generated
// Return Value: 
// Incoming Parameters: Fraction f1, Fraction f2, char g
// Outgoing Parameters: None
//**********************************************************************************
// Time of Completion: 15 minutes
Fraction calculateFractions(Fraction f1, Fraction f2, char g){
	Fraction f3;
	switch(g){
		case '+':
			f3 = f1 + f2; //calculates respected fraction
			f3.reduce(); //reduces the fraction
			return f3; //returns new fraction
			break;
		case '-':
			f3 = f1 - f2;
			f3.reduce();
			return f3;
			break;
		case '/':
			f3 = f1 / f2;
			f3.reduce();
			return f3;
			break;
		case '*':
			f3 = f1 * f2;
			f3.reduce();
			return f3;
			break;
	}
}

//**********************************************************************************
// Function Name: generateRandom
// Brief Function Description: generates random fraction by calling SetNum and SetDen
// Return Value: Fraction
// Incoming Parameters: None
// Outgoing Parameters: None
//**********************************************************************************
// Time of Completion: 5 minutes
Fraction generateRandom(){
	Fraction f1;
	f1.SetNum(rand() % 20 + 1); //gets random numerator
	f1.SetDen(rand() % 20 + 1); //gets random denominator
	f1.reduce();
	
	return f1; //returns random fraction
}
