#include <iostream>
#include <string>

using namespace std;


void printIntro();
string getGuessAndPrint();

int main()
{
	printIntro();

	constexpr int NUM_TURNS = 5;
	for (int i = 0; i < NUM_TURNS; i++)
	{
		getGuessAndPrint();
	}

	return 0;
}

void printIntro() {
	constexpr int WORD_LEN = 5;

	cout << "Welcome to Bulls and Cows!\n";
	cout << "This is a simple word game.\n";
	cout << "Can you guess the " << WORD_LEN << " letter isogram I'm thinking of?\n";

	return;
}

string getGuessAndPrint() {
	// get player guess
	string guess = "";
	getline(cin, guess);

	// repeat guess back
	cout << "Your guess is: " << guess << endl;

	return guess;
}