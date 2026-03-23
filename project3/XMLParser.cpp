#include "XMLParser.hpp"

XMLParser::XMLParser()
{
	tokenizedInputVector.clear();
} 

bool XMLParser::tokenizeInputString(const std::string &inputString)
{
	tokenizedInputVector.clear();
	
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

			// invalid content cases
			if(content.length() == 0){
				return false; // case: empty content
			}
			if(content.find('<') != std::string::npos){
				return false; // case: nested tags
			}

			TokenStruct token;

			// declaration
			if(content[0] == '?'){
				token.tokenType = DECLARATION;
				if(content.back() == '?'){
					token.tokenString = content.substr(1, content.length() - 2);
				} else{
					token.tokenString = content.substr(1);
				}
			} 
			else if(content[0] == '/'){
				std::string inside = content.substr(1);

				if(inside.length() == 0 || isspace(inside[0])){
					return false;
				}

				token.tokenType = END_TAG;
				token.tokenString = inside;
			}
			// empty tag
			else if(content.back() == '/'){
				std::string inside = content.substr(0, content.length() - 1);

				int space = inside.find(' ');
				if(space != std::string::npos){
					inside = inside.substr(0,space);
				}

				if(inside.length() == 0 || isspace(inside[0])){
					return false;
				}

				token.tokenType = EMPTY_TAG;
				token.tokenString = inside;
			}
			// start tag
			else {
				std::string inside = content;

				int space = inside.find(' ');
				if(space != std::string::npos){
					inside = inside.substr(0,space);
				}
				if(inside.length() == 0 || isspace(inside[0])){
					return false;
				}

				token.tokenType = START_TAG;
				token.tokenString = inside;
			}
			
			tokenizedInputVector.push_back(token);
			i = end + 1;
		} 
		// case 2: content
		else {
			int next = inputString.find('<', i);
			std::string content;

			if(next == std::string::npos){
				content = inputString.substr(i);
				i = inputString.length();
			} else {
				content = inputString.substr(i, next - i);
				i = next;
			}

			bool empty = true;
			for(int i=0; i<content.length(); i++){
				if(!isspace(content[i])){
					empty = false;
					break;
				}
			}

			if(content.length() != 0 && !empty){
				TokenStruct token;
				token.tokenType = CONTENT;
				token.tokenString = content;
				tokenizedInputVector.push_back(token);
			}
		}
	}

	return true;
} 

bool XMLParser::parseTokenizedInput()
{
	// return false if no tokens
	if(tokenizedInputVector.empty()){
		return false;
	}

	// clear previous parses
	parseStack.clear();
	elementNameBag.clear();

	// bools to track if start/end of tags is reached
	bool startRoot = false;
	bool endRoot = false;

	for(int i=0; i<tokenizedInputVector.size(); i++){
		TokenStruct token = tokenizedInputVector[i];

		switch(token.tokenType){
			case START_TAG:
				if(endRoot){
					return false; // case: finished root
				}

				parseStack.push(token.tokenString);
				elementNameBag.add(token.tokenString);

				if(!startRoot){
					startRoot = true; // case: first start tag
				}

				break;
			case END_TAG:
				// check for open tag
				if(parseStack.isEmpty()){
					return false;
				}
				
				// check if closing tag matches open tag
				if(parseStack.peek() != token.tokenString){
					return false;
				}

				parseStack.pop();

				// if nothing left, root has been closed
				if(parseStack.isEmpty()){
					endRoot = true;
				}

				break;
			case EMPTY_TAG:
				if(endRoot){
					return false; //case: finished root
				}
			
				elementNameBag.add(token.tokenString);

				break;
			case CONTENT:
				if(parseStack.isEmpty()){
					return false;
				}

				break;
			case DECLARATION:
				if(startRoot){
					return false;
				}
				break;
		}
	}

	return true;
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

