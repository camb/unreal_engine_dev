/* This is the console executable, that makes use of the BullCow Class
This acts as the view in a MVC pattern, and is responsible for all
user interaction. For game logic see the FBullCowGame class.
*/
#pragma once

#include <iostream>
#include <string>
#include "FBullCowGame.h"

// to make unreal friendly
using FText = std::string;
using int32 = int;

// function prototypes outside of a class
void printIntro();
void playGame();
FText getValidGuess();
bool playAgain();

FBullCowGame BCGame; // instantiate a new game, re-used across plays


int main()
{

	printIntro();
	do {
		playGame();
	} while ( playAgain() );

	return 0;
}


void printIntro() {
	std::cout << "\n\nWelcome to Bulls and Cows!\n";
	std::cout << "This is a simple word game.\n";
	std::cout << "             .=     ,        =.\n";
	std::cout << "     _  _   /'/    )\\,/,/(_   \\ \\\n";
	std::cout << "      `//-.|  (  ,\\\\)\\//\\)\\/_  ) |\n";
	std::cout << "      //___\\   `\\\\\\/\\\\/\\/\\\\///'  /\n";
	std::cout << "   ,-~`-._ `\"--'_   `\"\"\"` _ \\`'\"~-,_\n";
	std::cout << "   \\       `-.  '_`.      .'_` \\ ,-\"~`/\n";
	std::cout << "    `.__.-'`/   (-\\        /-) |-.__,'\n";
	std::cout << "      ||   |     \\O)  /^\\ (O/  |\n";
	std::cout << "      `\\\\  |         /   `\\    /\n";
	std::cout << "        \\\\  \\       /      `\\ /\n";
	std::cout << "         `\\\\ `-.  /' .---.--.\\\n";
	std::cout << "           `\\\\/`~(, '()      ('\n";
	std::cout << "            /(O) \\\\   _,.-.,_)\n";
	std::cout << "           //  \\\\ `\\'`      /\n";
	std::cout << "          / |  ||   `\"\"\"\"~\"`\n";
	std::cout << "        /'  |__||\n";
	std::cout << "              `o \n";
	std::cout << "Can you guess the " << BCGame.getHiddenWordLength();
	std::cout << " letter isogram I'm thinking of?\n";
	return;
}
 

// plays a single game to completion
void playGame()
{
	BCGame.reset();
	int32 maxTries = BCGame.getMaxTries();
	std::cout << "Max Tries: " << maxTries << "\n\n";

	// loop asking for guesses while the game
	// is NOT won and there are still tries remaining
	while (!BCGame.isGameWon() && BCGame.getCurrentTry() <= maxTries)
	{
		FText guess = getValidGuess();

		// Submit valid guess to the game
		FBullCowCount bullCowCount = BCGame.submitValidGuess(guess);

		std::cout << "Bulls = " << bullCowCount.bulls;
		std::cout << ". Cows = " << bullCowCount.cows << "\n\n";
	}
	BCGame.printGameSummary();

	return;
}


// loop continually until the user gives a valid guess
FText getValidGuess() {
	EGuessStatus status = EGuessStatus::invalid;
	FText guess = "";
	do
	{
		// get player guess
		std::cout << "Try " << BCGame.getCurrentTry() << "/" << BCGame.getMaxTries() << ". What's your guess?\n";
		std::getline(std::cin, guess);

		status = BCGame.checkGuessValidity(guess);
		switch (status)
		{
		case EGuessStatus::wrong_length:
			std::cout << "Please enter a " << BCGame.getHiddenWordLength() << " letter word.\n\n";
			break;
		case EGuessStatus::not_isogram:
			std::cout << "Please enter an isogram-- a word with no repeating letters.\n\n";
			break;
		case EGuessStatus::not_lowercase:
			std::cout << "Please enter a lowercase guess.\n\n";
			break;
		default:
			break;
		}
	} while (status != EGuessStatus::ok); // loop until we get no errors
	return guess;
}


bool playAgain()
{
	FText answer = "";
	std::cout << "Do you want to play again with the same word? Y/N ";
	std::getline(std::cin, answer);
	return (answer[0] == 'Y' || answer[0] == 'y');
}
