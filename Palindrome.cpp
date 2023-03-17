#include <iostream>
#include <vector>
#include <string>
#include<cctype>
using namespace std;

/*
 * Determines if a given string is a palindrome or not (if it can be read the same backwards or forwards), it does not change the original string input
 * @param the string to be checked for being a palindrome
 * @return true if the string is a palindrome
*/
bool IsPalindrome(const string& userInput);

/*
 * Receives a string, and removes its punctuation and whitespaces
 * @param the string to have its punctuation removed
 * @return a new string holding the original string without punctuation
*/
string RemovePunctuation(const string& userInput);

/*
 * Receives a string, and converts it to lowercase 
 * @param the string to turn into lowercase
 * @return a new string holding input string in all lowercases
*/
string ConvertToLower(const string& userInput);

/*
 * Receives a string, and reverses it
 * @param the string to reverse
 * @return a new string holding the reverse of the input
*/
string Reverse(const string& userInput);

/*
 * Receives a vector of strings, and displays it
 * @param the vector to be used
*/
void Display(vector<string> userStrings);



int main()
{
	vector<string> palindromes;
	vector<string> nonPalindromes;
	string uInput;
	bool palindromeString;
	
	do {
		cout << "Enter your palindrome or type quit:" << endl;
		getline(cin, uInput);
		palindromeString = IsPalindrome(uInput);
		if (palindromeString)
			palindromes.push_back(uInput);
		else if(uInput != "quit")
			nonPalindromes.push_back(uInput);


	} while (uInput != "quit");

	cout << "Palindromes:" << endl;
	Display(palindromes);
	cout << "NOT Palindromes:" << endl;
	Display(nonPalindromes);

	return 0;
}


//Determines if a string is a palindrome by making a lowercase copy of it without punctuation or spaces, and comparing it with the reversed version of that copy
//It does not change the original string
//If they are equal, returns true, else returns false
//<string>
bool IsPalindrome(const string& userInput)
{
	string inputCopy;
	string reverseCopy;

	inputCopy = RemovePunctuation(userInput);
	inputCopy = ConvertToLower(inputCopy);

	reverseCopy = Reverse(inputCopy);

	if (inputCopy == reverseCopy)
		return true;
	else
		return false;


}

//Returns a copy of a string without any punctuation
//uses the isalnum function <cctype>
string RemovePunctuation(const string& userInput)
{
	string cleanStr;
	for (int i = 0; i < userInput.length(); i++)
	{
		if (isalnum(userInput[i]))
			cleanStr += userInput[i];
	}

	return cleanStr;
}

//Returns a copy of a string in lowercase
//uses the tolower function <cctype>
string ConvertToLower(const string& userInput)
{
	string lowerStr;
	for (int i = 0; i < userInput.length(); i++)
		lowerStr += tolower(userInput[i]);

	return lowerStr;
}

//Reverses a string by copying its elements into another string from last element to first.
string Reverse(const string& userInput)
{
	string reverseStr;
	for (int i = userInput.length() - 1; i >= 0; i--)
		reverseStr += userInput[i];

	return reverseStr;
}

//Displays a vector of strings
void Display(vector<string> userStrings)
{
	for (int i = 0; i < userStrings.size(); i++)
	{
		cout << "\t" << userStrings[i] << endl;
	}

}