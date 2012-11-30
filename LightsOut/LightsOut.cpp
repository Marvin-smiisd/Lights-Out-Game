// Course: CSC 226 Introduction to Programming with C++
// Name: Marvin Yormie
// Date: March 2012
// Assignment 1: A program that allows a user to play "Lights Out" Game.
/*
   This board game uses a file which stores a five by five grid of numbers (zeros and ones) or lights. One
   means on and zero means off. A random number of these lights is switched on by default. Inputting any
   row and column numbers will toggle it and the four adjacent lights. Supported by a play menu, the goal
   of the puzzle is to switch all the lights off.
*/
#include <cstdlib>
#include <iostream>

#include "LightsOut.h"

using namespace std;

int main()
{
    LightsOut TheGame;//creates an instance of the LightsOut Class.
    TheGame.play();
    return 0;
}
