#include <string>
#include <vector>
#include "FindPalindrome.hpp"

//------------------- HELPER FUNCTIONS -----------------------------------------

// non-class helper functions go here, should be declared as "static" so that
// their scope is limited

/** Helper function to convert string to lower case */
static std::string convertToLowerCase(std::string value)
{
	std::string result;
	
	for (int i=0; i<value.size(); i++) {
		result[i] = tolower(value[i]);
	}

	return result;
}

//------------------- PRIVATE CLASS METHODS ------------------------------------

void FindPalindrome::recursiveFindPalindromes(std::vector<std::string>
        candidateSentence, std::vector<std::string> remainingWords)
{
	// Base Case: no words left -> test sentence
	if(remainingWords.empty()){
		std::string sentence;

		for(int i=0; i<candidateSentence.size(); i++){
			sentence += candidateSentence[i];
		}

		if(isPalindrome(sentence)){
			palindromes.push_back(candidateSentence);
		}

		return;
	}

	// Recursive Case: still need to add to candidateSentence
	for(int i=0; i<remainingWords.size(); i++){
		// Create new vectors to pass to next call
		std::vector<std::string> newCandidates = candidateSentence;
		std::vector<std::string> newRemaining = remainingWords;

		// Add the next word from remaining to candidates, and remove it from remaining
		newCandidates.push_back(remainingWords[i]);
		newRemaining.erase(newRemaining.begin() + i);

		// call function again with new candidates & remaining
		recursiveFindPalindromes(newCandidates, newRemaining);
	}
}

bool FindPalindrome::isPalindrome(std::string testString) const
{
	// make sure that the string is lower case
	convertToLowerCase(testString);
	// see if the characters are symmetric
	int stringLength = testString.size();
	for (int i=0; i<stringLength/2; i++) {
		if (testString[i] != testString[stringLength - i - 1]) {
			return false;
		}
	}
	return true;
}

//------------------- PUBLIC CLASS METHODS -------------------------------------

FindPalindrome::FindPalindrome()
{
	// TODO
}

FindPalindrome::~FindPalindrome()
{
	// TODO 
}

int FindPalindrome::number() const
{
	return palindromes.size();
}

void FindPalindrome::clear()
{
	words.clear();
	palindromes.clear();
}

bool FindPalindrome::cutTest1(const std::vector<std::string> & wordVector)
{
	// TODO 
	return false;
}

bool FindPalindrome::cutTest2(const std::vector<std::string> & wordVector1,
                              const std::vector<std::string> & wordVector2)
{
	// TODO 
	return false;
}

bool FindPalindrome::add(const std::string & newWord)
{
	// Check if word exists
	if(newWord.length() == 0){
		return false;
	}

	// Ensure word is only comprised of letters a-z (regardless of case)
	std::string lowercaseWord = convertToLowerCase(newWord);

	for(int i=0; i<newWord.length(); i++){
		if(!isalpha(newWord[i])){
			return false;
		}
	}

	// Ensure word is unique
	for(int i=0; i<words.size(); i++){
		if(lowercaseWord == convertToLowerCase(words[i])){
			return false;
		}
	}

	words.push_back(newWord);
	palindromes.clear();
	recursiveFindPalindromes({}, words);

	return true;
}

bool FindPalindrome::add(const std::vector<std::string> & wordVector)
{
	// TODO 
	return false;
}

std::vector< std::vector<std::string> > FindPalindrome::toVector() const
{
	return palindromes;
}

