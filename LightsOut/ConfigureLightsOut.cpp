#include <cstdlib>
#include <iostream>

#include "LightsOut.h"

using namespace std;

//public accessor member functions
//returns numberOn
int LightsOut::get_numberOn() const
{
return numberOn;
}

//public mutator functions which changes the value of private member variables
//this mutator calls toggle() five times (here, above, below, right, and left)
//when a user chooses to play at row r and column c
void LightsOut::make_move(int r, int c)
{
toggle(r, c);//turns off the light in the middle.
toggle(r-1, c);//turns off the light on the left.
toggle(r+1, c);//turns off the light on the right.
toggle(r, c-1);//turns off the light at the top.
toggle(r, c+1);//turns off the light at the buttom.
}

//private member functions
// when called with row r and column c
//if  ((0 <= r) && (r < 5) && (0<= c) &&  (c < 5))
//this private mutator changes gameboard[r][c] from true to false or false to true
//outside of these appropriate ranges, this mutator makes no change
void LightsOut::toggle(int r, int c)
{
if  ((0 <= r) && (r < 5) && (0<= c) && (c < 5))//only lights that are on the game-board can be turned off or on.
{
if (gameboard[r][c] == true)
{
         gameboard[r][c] = false;//
                numberOn--;//turns off a light that is on
}
            else{
          gameboard[r][c] = true;
              numberOn++;//turns on a light that is off
                }
}
return;
}

//Will display the game board on the screen
void LightsOut::display() const
{
	for (int row = 0; row < 5; row ++)
{  cout<<"\t\t  ";
		for(int col = 0; col < 5; col++)
        {
		cout << " " << gameboard[row][col];//prints the game booard to the scren.
		}
		cout << endl;
}

char answer;
if (numberOn == 0){//check if the all the lights are off to end the game.
  do
  {
  cout << " \n Congratulations! You have won!!";
  cout << " Do you still want to play \n another game? Enter y/Y for yes, n/N for no: ";
  cin >> answer;
  if (answer=='y' || answer=='Y')
  {cout<<LightsOut().play();}//calls the main function if the user choses to play another game.

  else if (answer=='n' || answer=='N')
  {
  cout << " \n Thank you for playing Light-Outs - goodbye...\n\n ";
  system("Pause");
  exit(1);}
  }
while(answer=='y' || answer =='Y');}
}
