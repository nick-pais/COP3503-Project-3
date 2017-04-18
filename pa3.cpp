// Copyright [2016] <Nickolas Pais>
// COP3503 Project 3
// PA3.cpp
//Lexical Analysis
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <stdlib.h>
#include "stdio.h"
#include "pa3.h"
using namespace std;

int main(){
 Stack input;
//stack will hold input
 cout << "Please enter the name of the input file:" << endl;
 string file;
 //take in file location
 cin >> file;

//input set equal to checkTheFile stack
input = checkTheFile(file);

	// operators stack
 Stack operators;

 // keywords stack
 Stack keywords;

 // identifiers stack
 Stack idents;

 // syntax error stack
 Stack syntaxErrors;

 // constants stack
 Stack constants;

 // delimiters stack
 Stack delims;

 // Check if there is a syntax error
 bool syntaxError;

 int amountOfLoops;
 // Start count
 int countS = 0;
 // For count
 int countF = 0;
 // End Count
 int countE = 0;

 // while loop for input
 // To D0: Make while loop to go through entire stack
 while (input.emptyCheck() != true) {
  string temporary = input.pop();
  syntaxError = true;
// To Do: Make for loop
 for (unsigned int i = 0; i < temporary.length(); i++) {
   char ch;
   ch = temporary.at(i);
   string s(1, ch);
   if (s == ";" || s == ",") {
   syntaxError = false;
   if (!delims.contains(s)) {
    delims.push(s);
  }
 }
}
 for (unsigned int i = 0; i < temporary.length(); i++) {
  char ch;
  ch = temporary.at(i);
  string s(1, ch);

// checks operators
  if (temporary == "++)" || temporary == "++;" || temporary == "--)" || temporary == "--;" || s == "-" || s == "*" || s == "/" ||  s == "%" || s == "+" || s == "=") {
     if (temporary == "++)" || temporary == "++;") {
    syntaxError = false;
       if (!operators.contains("++")) {
         operators.push("++");
 }
}

  else if (temporary == "--)" || temporary == "--;") {
          syntaxError = false;
       if(!operators.contains("--")) {
          operators.push("--");
 }
}
  else {
   syntaxError = false;
    if (!operators.contains(s)) {
       operators.push(s);
   }
  }
 }
}
// checks for idents
  for (unsigned int i = 0; i < temporary.length(); i++) {
      char ch;
      ch = temporary.at(i);
      string s(1,ch);
      int index;
// To Do: check for equal sign
  //=
  if (s == "="){
    index = temporary.find("=");
    temporary = temporary.substr(0, index);
    syntaxError = false;
  if (!idents.contains(temporary)){
    idents.push(temporary);
 }
}
  // ;
  else if (s == ";"){
   index = temporary.find(";");
   temporary = temporary.substr(0, index);
   syntaxError = false;
     if (!idents.contains(temporary)) {
     idents.push(temporary);
 }
}
			// (
  else if (s == "("){
   temporary = temporary.at(1);
   syntaxError = false;
     if(!idents.contains(temporary)) {
       idents.push(temporary);
 }
}
  else if (temporary.length() == 1 && ch >= 'a' && ch <= 'z') {
    syntaxError = false;
    if (!idents.contains(temporary)) {
      idents.push(temporary);
  }
 }
}
  if (temporary == "FOR" || temporary == "BEGIN" || temporary == "END") {
    if (!keywords.contains(temporary)) {
      keywords.push(temporary);
}
  if (temporary == "FOR") {
    countF++;
}
  else if (temporary == "BEGIN") {
    countS++;
}
  else if(temporary == "END") {
    countE++;
 }
} else if(temporary.at(0) != '(' && temporary.at(temporary.length()-1) == ',') {
    if (!constants.contains(temporary.substr(0, temporary.length()-1))) {
        constants.push(temporary.substr(0, temporary.length()-1));
 }
}
// pushes to syntax error stack
  else if (syntaxError) {
   syntaxErrors.push(temporary);
 }
}
 amountOfLoops = max(max(countF, countS), countE) - 1;
  cout << "\nThe depth of nested loop(s) is: " << amountOfLoops << "\n" << endl;

//prints keywords
 cout << "Keywords:";
 keywords.print();
 cout << endl;


//prints identifers
 cout << "Identifiers:";
 idents.print();
 cout << endl;


//prints constants
 cout << "Constants:";
 constants.print();
 cout << endl;


//prints operators
 cout << "Operators:";
 operators.print();
 cout << endl;


//prints delims
 cout << "Delimiters:";
 delims.print();
 cout << endl;


//prints syntax errors
 cout << "\nSyntax Error(s):";
 syntaxErrors.print();
 cout << endl;

   return 0;
}

Stack checkTheFile(string file) {
 Stack input;
  ifstream foundInFile;
  foundInFile.open(file.c_str());
	if(foundInFile.fail()){
  cout << "Sorry! File Error, Please retry" << endl;
    exit(EXIT_FAILURE);
}
// puts file in main stack
 else {
  string word;
  while (true) {
    foundInFile >> word;
     if (foundInFile.eof())
   break;
   input.push(word);

}
//closes file
  foundInFile.close();
}
 return input;
}
