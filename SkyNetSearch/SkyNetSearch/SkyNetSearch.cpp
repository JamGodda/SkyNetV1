// SkyNetSearch.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream> // the in and the out stream
#include <cstdlib> // this is where we get the random number generator from
#include <ctime> // we use this for the seeding of the random number geneator. The are based on a calculation which means...
// somthing has to chaange each time and since time is changing the random number generated is changed each time also.

using namespace std; // basically the libary that this draws from allows us to use simple commads instead of typing evverything out each time.

int main() // this is the start of the overall program
{
	srand(static_cast<unsigned int>(time(0))); //  Seed random number generator so that its not the same every time.
											   //  By using the time on the computer the numbers change based on time

	int TargetLoaction = rand() % 64 + 1; // Random number between 1 and 64
	int tries = 0; // Number of tries to find the target
	int Search; // Holds the number they guessed

	cout << "\tWelcome to SkyNet the bots are out searching please run the program to see location \n\n";
	system("pause");
	int low = 0; // this defines the starting low number for the equation that the computer will run
	int high = 64; // this defines the starting high number for the equation that the computer will run
	int targetLocationPrediction; // this is the holder for each guess and will change each time until it is equal to the target location
	
	do // The do while loop forces the program to run at least once and then again and again until the computer finds the right number

	{
		// Its a little different than what was done in class but it works and is less typing.
		//Basically the high is added to the low and then divided by two each time, the high or low is increased or decreased respectivly if the guess is two high or low.
		// During the next run though the number is either lower or higher depending on if the pervious guess was to high or to low.
		targetLocationPrediction = ((high + low) / 2); // the equation has () in it to make sure the computer does the equation correctly instead of just reading right to left.
		
		++tries; // Counts the number of tries the computer takes to get the right number. it is added to during each loop cycle
		cout << "\nSearching Sector: \n";
		cout << targetLocationPrediction;
		cout << "\n";
		system("pause"); // pauses the game each time so that the player can see what the guess was and cotinue to the next guess
		if (targetLocationPrediction > TargetLoaction) // compares the guess to the real number and decides if it is to high and runs the loop again
		{
			cout << "The enemy is not here better search lower.\n\n";
			high = targetLocationPrediction; // changes the high number to the guess number that was to high
		}
		else if (targetLocationPrediction < TargetLoaction) // compares the guess to the real number and decides if it is to low and runs the loop again
		{
			cout << "The enemy is not here better search higher.\n\n";
			low = targetLocationPrediction; // changes the low number to the guess number that was to low
		}
		else // do this if the guess is not to high or to low
		{
			cout << "\nTarget found missiles firing........";
			cout << "\nTries to find target: " << tries << "\n";
		}

	} while (targetLocationPrediction != TargetLoaction); // forces the loop to go again and again until the the targetLocationPrediction is the same as TargetLoaction
	system("pause"); // pauses the system so that else statment can be read instead of immideatly exiting the program

	return 0; // returns an int to main since that what the type is.
}
