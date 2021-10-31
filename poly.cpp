//******************************************
// Jared Truitt
// Poly.cpp
// Implementation of a Polynomial data type
// CS255
// 28 October 2021
//******************************************

#include "Poly.h"
#include <cmath>
#include <iostream>

//**********************************************************************
// Function Name: Poly
// Description: Constructor for the Poly class to initialize array to 0
// Incoming Parameters: None
// Outgoing Parameters: None
// Return Type: None
//**********************************************************************
Poly::Poly(){
    for(int i=0; i<MAX; i++){ //initializing array to 0
        terms[i] = 0;
    }
}

//*************************************************************
// Function Name: >> input operator
// Description: Takes in a polynomial from the user
// Incoming Parameters: istream is, Poly p
// Outgoing Parameters: istream is, Poly p
// Return Type: istream
//*************************************************************
istream& operator>>(istream& is, Poly& p){
    char g,x,e; // ending, variable x, ^ symbol
    int coef,deg;
    is>>g;
    while(g!='>'){  //guard to check if '>' ending input char is entered
        is>>coef;
        is>>x;
        is>>e;
        is>>deg;
        p.terms[deg] = coef; //puts entered coef in the degree index of array
        is>>g;
    }
    return is;
}

//************************************************************************
// Function Name: << ouput operator
// Description: Prints out the elements of the terms array, aka polynomial
// Incoming Parameters: ostream os, Poly p
// Outgoing Parameters: ostream os, Poly p
// Return Type: ostream
//************************************************************************
ostream& operator<<(ostream& os, const Poly& p){
    os << "<";
    for (int i=MAX-1; i>=0; i--){
        if (p.terms[i] != 0) {
            if(p.terms[i] != 1 || i == 0){ // ensures X is only printed when 1X is inputed and 1 is printed when 1x^0 is inputted
                os << p.terms[i];
            }
            if(i > 0){ // ensures X to only be printed when the degree is not 0
                os<<'X';
            }
            if(i > 1){  // ensures the degree is 2 or more to output ^ and degree
                os<<'^'<<i;
            }
            for(int j=i-1; j>=0; j--){ //starts at i-1 to check if there's another coef in the array
                if(p.terms[j] != 0){ 
                    os<<'+';
                    break;
                }
            }
        }
    }
    os<<">";
    return os;
}

//*************************************************************
// Function Name: Reset
// Description: Resets the terms array to 0
// Incoming Parameters: None
// Outgoing Parameters: None
// Return Type: None
//*************************************************************
void Poly::Reset(){
    for(int i=0; i<MAX; i++){ //resets the array to 0
        terms[i] = 0;
    }
}

//*************************************************************
// Function Name: Eval
// Description: Evaluates a polynomial at an inputted X vaule
// Incoming Parameters: double x
// Outgoing Parameters: None
// Return Type: double
//*************************************************************
double Poly::Eval(double x){
    double temp = 0;
    for(int i=MAX-1; i>=0; i--){
        if(terms[i] != 0){
            temp += terms[i] * pow(x,i);  //raising x to the i power and multiplying by coef
        } 								  //and the adding it to the sum of all elements in array
    }
    return temp;
}

//*************************************************************
// Function Name: + Addition
// Description: Adds two polynomials together
// Incoming Parameters: Poly p1, Poly p2
// Outgoing Parameters: Poly p1, Poly p2
// Return Type: Poly
//*************************************************************
Poly operator+(const Poly& p1, const Poly& p2){
    Poly p3;
    for(int i=0; i<MAX-1; i++){
        if(p1.terms[i] != 0 || p2.terms[i] != 0){    // either p1 or p2 with a coef. works bc anything + 0 will still
            p3.terms[i] = p1.terms[i] + p2.terms[i]; // initialize to new poly array
        }
    }
    return p3;
}

//*************************************************************
// Function Name: * Multiplication
// Description: Multiplies two polynomials together
// Incoming Parameters: Poly p1, Poly p2
// Outgoing Parameters: Poly p1, Poly p2
// Return Type: Poly
//*************************************************************
Poly operator*(const Poly& p1, const Poly& p2){
    Poly p3, temp;
    for(int i=MAX-1; i>=0; i--){  //going backwards through the array
        if(p1.terms[i] != 0){
            for(int j=MAX-1; j>=0; j--){ // two for loops to reverse twice
                if(p3.terms[i+j] == 0 && p2.terms[j] != 0){
                    p3.terms[i+j] = p1.terms[i] * p2.terms[j]; //finds the next term to multiply by (foils)jh
                }
                else if(p3.terms[i+j] != 0 && p2.terms[j] != 0){
                    temp.terms[i+j] = p1.terms[i] * p2.terms[j]; //find the next term to multipy by (foils)
                    p3.terms[i+j] += temp.terms[i+j];
                }
            }
        }
    }
    return p3;
}

//*************************************************************
// Function Name: += operatorj
// Description: Adds the calling object to 
// Incoming Parameters: Poly p
// Outgoing Parameters: Poly p
// Return Type: None
//*************************************************************
void Poly::operator+=(const Poly& p){
    *this = *this + p; // one liner
}

//**********************************************************************
// Function Name: Derivative
// Description: Finds the derivative of a polynomial with the power rule
// Incoming Parameters: None
// Outgoing Parameters: None
// Return Type: None
//**********************************************************************
void Poly::Derivative(){
    for(int i=0; i<MAX; i++){
        if(terms[i] != 0){
            terms[i-1] = terms[i] * i; //power rule algorithm
            terms[i] = 0;
        }
    }
}

