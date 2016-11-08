#include "FBullCowGame.h"

int32 FBullCowGame::getMaxTries() const { return myMaxTries; }
int32 FBullCowGame::getCurrentTry() const { return myCurrentTry; }
int32 FBullCowGame::getIsogramLen() const { return 0; }

FBullCowGame::FBullCowGame()
{
	reset();
}

void FBullCowGame::reset()
{
	constexpr int32 MAX_TRIES = 3;
	myMaxTries = MAX_TRIES;

	const FString HIDDEN_WORD = "earth";
	myHiddenWord = HIDDEN_WORD;

	myCurrentTry = 1;
	return;
}

void FBullCowGame::isGameWon() const
{
	return;
}

bool FBullCowGame::checkGuessValidity()
{
	return false;
}

FString FBullCowGame::getIsogram()
{
	return "test";
}

void FBullCowGame::setNewIsogram(FString isogram)
{
	return;
}

// received a valid guess, increments turn, and returns count
FBullCowCount FBullCowGame::submitGuess(FString guess)
{
	// increment turn number
	myCurrentTry++;

	// setup a return variable
	FBullCowCount bullCowCount;

	int32 hiddenWordLength = myHiddenWord.length();
	int32 guessLength = guess.length();
	// loop through all letters in guess
	for ( int32 i = 0; i < guessLength; i++ )
	{
		// compare letters against hidden word
		for ( int32 j = 0; j < guessLength; j++ )
		{
			// if they're in the same place increment bulls
			if ( guess[i] == myHiddenWord[i] )
			{
				bullCowCount.bulls++;
			}
			// if they're in different places increment cows
			else if ( guess[i] == myHiddenWord[j] )
			{
				bullCowCount.cows++;
			}
		}
	}

	return bullCowCount;
}
