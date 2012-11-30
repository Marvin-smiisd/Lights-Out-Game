#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;

class LightsOut {
  public:
     // constructor
     // Load initial game board and sets numberOn appropriately
     LightsOut();

     //public member function that loads the game board to the screen.
     void LoadToggleFile(istream& ins);

     //public accessor member functions
     int get_numberOn() const;	//returns numberOn

     // public mutator functions which changes the value of private member variables
     // this mutator calls toggle() five times (here, above, below, right, and left)
     void make_move(int r, int c);	 // when a user chooses to play at row r and column c

     int play();//Diplays intructions for playing LightsOut.

     // a useful member function
     // Will display the game board on the screen
     void display() const;

  private:
     // private member variables
     bool gameboard[5][5];	// light on=true; light off=false
     int numberOn;		// the number of lights on; the user wins game when numberOn=0

     // private member functions
     void toggle(int r, int c);
     // when called with row r and column c
     // if  ((0 <= r) && (r < 5) && (0<= c) &&  (c < 5))
     // this private mutator changes gameboard[r][c] from true to false or false to true
     // outside of these appropriate ranges, this mutator makes no change

   //check for the winner
   //bool check_for_winner();

};	// Note the need for a semicolon
