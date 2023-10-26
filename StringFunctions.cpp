#include "StdAfx.h"
#include <vector>
#include "StringFunctions.h"

using namespace std;


//class StringFunctions{
	
int StringFunctions::GetPalindromeErrIndex(string word){
	size_t checkPoint = word.size() / 2;
	size_t currentPoint = 0;
	
	
	while (currentPoint != checkPoint){
		size_t endPoint = (word.size() - 1) - currentPoint;
		if (word[currentPoint] != word[endPoint]) {
			return currentPoint;	
		}
		
		currentPoint++;
	}
	
	return -1;
}	

int StringFunctions::GetPalindromeErrIndexFromMap(std::map<int,char> charMap){
	size_t checkPoint = charMap.size() / 2;
	size_t currentPoint = 0;
	std::map<int, char>::iterator it = charMap.begin();
	std::map<int, char>::reverse_iterator rit = charMap.rbegin();
	
	while (currentPoint != checkPoint){
		size_t endPoint = (charMap.size() - 1) - currentPoint;
		if (it->second != rit->second){
			return it->first;
		}

		rit++;
		it++;
		currentPoint++;
	}
	
	return -1;
}

/*string*/ std::map<int,char> StringFunctions::ToAlphaCharMap(string input){
	std::map<int,char> alphaCharMap;
	//string newInput = "";
	int size;
	int i = 0;
	//int newI = 0;

	size = input.size();

	do {
		if (isalpha(input[i])){
			//newInput += input[i];
			alphaCharMap[i]=input[i];
			//newI++;
		}
		i++;

	} while (i <= size - 1);

	//return newInput;
	return alphaCharMap;
}

/*string*/ std::map<int,char> StringFunctions::ToAlphaNumCharMap(string input){
	std::map<int,char> alphaNumCharMap;
	//string newInput = "";
	int size;
	int i = 0;
	//int newI = 0;

	size = input.size();

	do {
		if (isalnum(input[i]) ){
			//newInput += input[i];
			alphaNumCharMap[i]=input[i];
			//newI++;
		}
		i++;

	} while (i <= size - 1);

	//return newInput;
	return alphaNumCharMap;
}

/*string*/ std::map<int,char> StringFunctions::ToNonNumCharMap(string input){
	std::map<int,char> nonNumCharMap;
	//string newInput = "";
	int size;
	int i = 0;
	//int newI = 0;

	size = input.size();

	do {
		if (!isdigit(input[i]) ){
			//newInput += input[i];
			nonNumCharMap[i]=input[i];
			//newI++;
		}
		i++;

	} while (i <= size - 1);

	//return newInput;
	return nonNumCharMap;
}

std::map<int,char> StringFunctions::ToCharMap(string input){
	std::map<int,char> charMap;
	//string newInput = "";
	int size;
	int i = 0;
	//int newI = 0;

	size = input.size();

	do {
		//if (!isdigit(input[i]) ){
			//newInput += input[i];
			charMap[i]=input[i];
			//newI++;
		//}
		i++;

	} while (i <= size - 1);

	//return newInput;
	return charMap;
}

std::map<int,char> StringFunctions::CharMapToLower(std::map<int,char> charMap) {
	char c;
	std::map<int,char> CharMapLower;

  for (std::map<int ,char>::iterator it=charMap.begin(); it!=charMap.end(); ++it){
		c= it->second;
		CharMapLower[it->first] = (tolower(c));
  }
  
  return CharMapLower;
}

string StringFunctions::StringToLower(string word) {
	char c;
	std::vector<char> str (word.begin(), word.end() );
	string newWord = "";

  for (std::vector<char>::iterator it = str.begin(); it != str.end(); ++it){
		c= *it;
		newWord += (tolower(c));
	}
  
  return newWord;
}


//*******************************************************
//*******************************************************
//*******************************************************


std::string StringFunctions::trim_right_copy(const std::string& s, const std::string& delimiters )
{
  return s.substr( 0, s.find_last_not_of( delimiters ) + 1 );
}

std::string StringFunctions::trim_left_copy(const std::string& s, const std::string& delimiters)
{
  return s.substr( s.find_first_not_of( delimiters ) );
}

std::string StringFunctions::trim_copy(const std::string& s, const std::string& delimiters)
{
  return trim_left_copy( trim_right_copy( s, delimiters ), delimiters );
}



std::string& StringFunctions::trim_right_inplace(std::string& s, const std::string& delimiters)
{
  return s.erase( s.find_last_not_of( delimiters ) + 1 );
}

std::string& StringFunctions::trim_left_inplace(std::string& s, const std::string& delimiters)
{
  return s.erase( 0, s.find_first_not_of( delimiters ) );
}

std::string& StringFunctions::trim_inplace(std::string& s, const std::string& delimiters)
{
  return trim_left_inplace( trim_right_inplace( s, delimiters ), delimiters );
}



//}
