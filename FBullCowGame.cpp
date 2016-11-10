/* This is the implementation file for our FBullCowGame class. */
#pragma once

#include "FBullCowGame.h"
#include <map>
#define TMap std::map // to make unreal friendly

int32 FBullCowGame::getHiddenWordLength() const { return myHiddenWord.length(); }
int32 FBullCowGame::getCurrentTry() const { return myCurrentTry; }
int32 FBullCowGame::getIsogramLen() const { return 0; }
bool FBullCowGame::isGameWon() const { return bIsGameWon; }

int32 FBullCowGame::getMaxTries() const
{
	TMap<int32, int32> wordLengthToMaxTries{ {3, 4}, {4,7}, {5,10}, {6,16}, {7,20} };
	return wordLengthToMaxTries[getHiddenWordLength()];
}

FBullCowGame::FBullCowGame()
{
	reset();
}

void FBullCowGame::reset()
{
	const FString HIDDEN_WORD = "earth"; // this MUST be an isogram!
	myHiddenWord = HIDDEN_WORD;

	myCurrentTry = 1;
	bIsGameWon = false;

	return;
}

EGuessStatus FBullCowGame::checkGuessValidity(FString guess) const
{
	if (!isIsogram(guess))	// if the guess isn't an isogram
	{
		return EGuessStatus::not_isogram;
	}
	else if (!isLower(guess)) // if guess isn't all lowercase
	{
		return EGuessStatus::not_lowercase;
	}
	else if (guess.length() != getHiddenWordLength()) // if length is wrong
	{
		return EGuessStatus::wrong_length;
	}
	else
	{
		return EGuessStatus::ok;
	}
}

// received a valid guess, increments turn, and returns count
FBullCowCount FBullCowGame::submitValidGuess(FString guess)
{
	myCurrentTry++;
	FBullCowCount bullCowCount;

	// loop through all letters in guess
	int32 wordLength = myHiddenWord.length(); // assuming the guess and hidden word as the same length
	for (int32 i = 0; i < wordLength; i++)
	{
		// compare letters against the guess
		for (int32 j = 0; j < wordLength; j++)
		{
			if (guess[i] == myHiddenWord[j])
			{
				if ( i == j )
				{
					// if they're in the same place increment bulls
					bullCowCount.bulls++;
				}
				else
				{
					// if they're in different places increment cows
					bullCowCount.cows++;
				}
			}
		}
	}

	if (bullCowCount.bulls == wordLength)
	{
		bIsGameWon = true;
	}
	else
	{
		bIsGameWon = false;
	}

	return bullCowCount;
}

void FBullCowGame::printGameSummary()
{
	if (bIsGameWon)
	{
		std::cout << "Congrats! You've won the game!\n";
	}
	else
	{
		std::cout << "You lose! Better luck next time!\n";
	}

	std::cout << "Total tries: " << getCurrentTry() << std::endl;
	std::cout << "Max tries: " << getMaxTries() << "\n\n\n";
}

bool FBullCowGame::isIsogram(const FString word) const
{
	// treat 0 and 1 letter strings as isograms
	if (word.length() < 2)
	{
		return true;
	}

	TMap<char, bool> letterSeen; // setup hash table
	for (auto letter : word) // for letters in word
	{
		letter = tolower(letter); // handle mixed-case
		if (letterSeen[letter])
		{ 
			return false;
		}
		else
		{
			letterSeen[letter] = true;
		}
	}

	return true;
}

bool FBullCowGame::isLower(FString word) const
{
	for (auto letter : word)
	{
		if (!islower(letter))
		{
			return false;
		}
	}
	return true;
}
