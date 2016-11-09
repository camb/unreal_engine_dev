#pragma once
#include <string>

using FString = std::string;
using int32 = int;

struct FBullCowCount {
	int32 bulls = 0;
	int32 cows = 0;
};

enum class EWordStatus {
	ok,
	not_isogram
};

class FBullCowGame {
public:
	FBullCowGame(); // constructor

	int32 getHiddenWordLength() const;
	int32 getMaxTries() const;
	int32 getCurrentTry() const;
	int32 getIsogramLen() const;
	void isGameWon() const;
	EWordStatus checkGuessValidity() const;

	void reset(); // TODO make a more rich return value.
	FString getIsogram(); // TODO decide if this is useful to keep
	void setNewIsogram(FString isogram); // TODO is this within scope of assignment?

	// counts bulls and cows and increase try number and assumes valid guess
	FBullCowCount submitGuess(FString guess);

private:
	// see constructor for initialization
	int32 myCurrentTry;
	int32 myMaxTries;
	FString myHiddenWord;
};