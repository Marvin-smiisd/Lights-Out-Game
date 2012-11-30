#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;

#include "LightsOut.h"

LightsOut::LightsOut()
{
numberOn = 25; int row, col;

for (row = 0; row < 5; row ++)//the game-board has five rows.
{
    for(col = 0; col < 5; col++)//the game-board has five columns.
    {
    gameboard[row][col]=true;//the game-board has lights on.
    }
  }
}

//public member function that prints the initially loaded game board to the screen.
void LightsOut::LoadToggleFile(istream& ins)
{
numberOn=0;//initializes the number of lights on to be zero so as to cout the number of ligh that are on appropriately.
     int row, col;//stores values in the rows and columns of two diamentaional array.

	for (row = 0; row < 5; row ++)//the aray has rows.
	{
		for(col = 0; col < 5; col++)//the array  has 5 columns.
		{
           ins >> gameboard[row][col];//loads game-board from a file to the two diamentional array.
           cout <<" " << gameboard[row][col];//prints the game-board ot the screen.

           if (gameboard[row][col] == true)//if the board printed to the screen has light/lightn on -
		{
        numberOn++;//count the number of light/lights that are laready on.
        }
		}
cout << endl;
	}

 //int answer1;//stores user response
	if (numberOn==0)//if the game-board loaded from a file have numbers that are all zeros, echo a message and quit the program.
	{
    cout << " \n No lights are on - this game is already done. \n ";//
    system("Pause");
    exit(1);
    }
}
