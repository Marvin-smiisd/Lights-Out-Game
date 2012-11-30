#include <cstdlib>
#include <iostream>
#include <fstream>

#include "LightsOut.h"

int LightsOut::play(){

using namespace std;

    LightsOut mygame;//creates an instance of the LightsOut Class.
          char InputFile[21];//pointer to store input file name.
               ifstream InputStream;//input file stream.
                       int row, col;//variable to store two diamentional array values.

    cout << " \n Please enter the name of the input file (maximun of 21 characters): ";
    cin >> InputFile;
    cout << " \n";

    InputStream.open(InputFile);//open the input file.
    if (InputStream.fail())//validates the input file name.
    {cout << "Input file opening failed!!"; return 0;cout<<"\n\n";}//prints an error message to the screen if the validation fails.

    mygame.LoadToggleFile(InputStream);//calls the LoadToggleFile to load the initial gameboard from a file.

    InputStream.close();//closses the input file after sucessfullly loading the gamboard to the array and then to the screen.

    cout << " \n If you enter a row and colmn number other than those in the instructions below,\n no lights will be turned ON or"
            " OFF. You must turn all the lights off to win \n this game (1 means ON and 0 means OFF). \n";

    while (mygame.get_numberOn()>0)//a ligh is on on the game-board, so keep on playing.
    {
    cout<< " \n Instructions for the game-board's lights positions: \n\n";//Instructions for playing the game
    cout << "\t\t|"<<"---|---|---|---|---|\n"
         << "\t\t|"<<"0 0" << "|" << "0 1" << "|" << "0 2" << "|" << "0 3" << "|" << "0 4" << "|\n"
         << "\t\t|"<<"---|---|---|---|---|\n"
         << "\t\t|"<<"1 0" << "|" << "1 1" << "|" << "1 2" << "|" << "1 3" << "|" << "1 4" << "|\n"
         << "\t\t|"<<"---|---|---|---|---|\n"
         << "\t\t|"<<"2 0" << "|" << "2 1" << "|" << "2 2" << "|" << "2 3" << "|" << "2 4" << "|\n"
         << "\t\t|"<<"---|---|---|---|---|\n"
         << "\t\t|"<<"3 0" << "|" << "3 1" << "|" << "3 2" << "|" << "3 3" << "|" << "3 4" << "|\n"
         << "\t\t|"<<"---|---|---|---|---|\n"
         << "\t\t|"<<"4 0" << "|" << "4 1" << "|" << "4 2" << "|" << "4 3" << "|" << "4 4" << "|\n"
         << "\t\t|"<<"---|---|---|---|---|\n";

    cout <<  " \n For each play, type a pair of number, in the order in which they appear in the cells"
             " above.\n It and the four adjacent lights will be toggled. Please enter the row and column"
             " numbers. You\n may enter SEVEN (7) to exit :";
    cin >> row;
    if(row==7){cout<<" \n Thank you for playing Lights-Out.\n\n";return 0;}
    cin>> col;
    mygame.make_move(row, col);cout<<endl;//calls make_move function, which also class toggle function to turn lights off or on.
    cout<<" \n Current status of the game-board: \n\n";
    mygame.display();//calls the print function to display the board om the screen.
    }
return 0;
}
