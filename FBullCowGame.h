/* This is the header file for our FBullCowGame class.
This is the game logic for a simple word guess game.*/
#pragma once

#include <string>
#include <iostream>

// to make unreal friendly
using FString = std::string;
using int32 = int;

struct FBullCowCount {
	int32 bulls = 0;
	int32 cows = 0;
};

enum class EGuessStatus {
	invalid,
	ok,
	not_isogram,
	not_lowercase,
	wrong_length
};


class FBullCowGame {
public:
	FBullCowGame(); // constructor

	int32 getHiddenWordLength() const;
	int32 getMaxTries() const;
	int32 getCurrentTry() const;
	int32 getIsogramLen() const;
	EGuessStatus checkGuessValidity(FString) const;
	bool isGameWon() const;

	void reset();

	// counts bulls and cows and increase try number and assumes valid guess
	FBullCowCount submitValidGuess(FString);
	void printGameSummary();

private:
	// see constructor for initialization
	int32 myCurrentTry;
	int32 myMaxTries;
	FString myHiddenWord;
	bool bIsGameWon;

	bool isIsogram(const FString) const;
	bool isLower(FString) const;
};