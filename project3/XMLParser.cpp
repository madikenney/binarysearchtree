#include "XMLParser.hpp"

XMLParser::XMLParser()
{
	tokenizedInputVector.clear();
} 

bool XMLParser::tokenizeInputString(const std::string &inputString)
{
	if(inputString.length() == 0){
		return false;
	}

	int i = 0;
	while(i < inputString.length()) {
		// Case 1: < (start of tag)
		if(inputString[i] == '<'){
			// find closing >
			int end = inputString.find('>', i); // starting at index i

			if(end == std::string::npos){
				return false; // no closing > found
			}

			// find content of < >
			std::string content = inputString.substr(i+1, end-i-1);

			if(content.length() == 0){
				return false; // case: empty content
			} else if(content.find('<') != std::string::npos){
				return false; // case: nested tags
			}


			
		}
	}

	return false;
} 

bool XMLParser::parseTokenizedInput()
{
	// TODO
	return false;
}

void XMLParser::clear()
{
	// TODO
}

std::vector<TokenStruct> XMLParser::returnTokenizedInput() const
{
	return tokenizedInputVector;
}

bool XMLParser::containsElementName(const std::string &inputString) const
{
	// TODO
	return false;
}

int XMLParser::frequencyElementName(const std::string &inputString) const
{
	// TODO
	return -1;
}

