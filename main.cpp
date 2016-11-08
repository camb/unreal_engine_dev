/* This is the console executable, that makes use of the BullCow Class
This acts as the view in a MVC pattern, and is responsible for all
user interaction. For game logic see the FBullCowGame class.
*/

#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;

void printIntro();
void playGame();
FText getGuess();
bool playAgain();

FBullCowGame BCGame; // instantiate a new game


int main()
{

	printIntro();
	do {
		playGame();
	} while ( playAgain() );

	return 0;
}


void printIntro() {
	constexpr int32 WORD_LEN = 5;

	std::cout << "Welcome to Bulls and Cows!\n";
	std::cout << "This is a simple word game.\n";
	std::cout << "Can you guess the " << WORD_LEN << " letter isogram I'm thinking of?\n";

	return;
}


void playGame()
{
	BCGame.reset();
	int32 maxTries = BCGame.getMaxTries();
	std::cout << "Max Tries: " << maxTries << std::endl;

	// loop for number of turns asknig for guess
	// Change from FOR to WHILE once we are validating tries
	for (int32 i = 0; i < maxTries; i++)
	{
		int32 currentTry = BCGame.getCurrentTry();
		std::cout << "Try " << currentTry << ". What's your guess?\n";
		FText guess = getGuess(); // TODO check for valid guesses

		// Submit valid guess to the game
		FBullCowCount bullCowCount = BCGame.submitGuess(guess);
		// Print number of bulls and cows

		std::cout << "Bulls = " << bullCowCount.bulls;
		std::cout << ". Cows = " << bullCowCount.cows << std::endl;
	}

	return;
}


FText getGuess() {
	// get player guess
	FText guess = "";
	std::getline(std::cin, guess);
	return guess;
}

bool playAgain()
{
	FText answer = "";
	std::cout << "Do you want to play again? Y/N";
	std::getline(std::cin, answer);
	return (answer[0] == 'Y' || answer[0] == 'y');
}