// Copyright [2016] <Nickolas Pais>
// COP3503 Project 3
// PA3.h
// Using link list as stack because it seemed easier to implement
// Just my opinion
#ifndef PA3_H
#define PA3_H
#include <iostream>
#include "stdio.h"
#include <string>
using namespace std;


class Stack {
private:
	int sizeOfStack;
	typedef struct node {
		string info;
		node *next;
		bool available;
}
	* pointer;
	pointer topOfStack;
	pointer inUse;
	pointer temporary;

public:
	Stack();
	void push(string addinfo);
	string pop();
	bool exists();
	bool emptyCheck();
	bool contains(string info);
	int size();
	void print();
	string top();
};
// linklist constructor
Stack::Stack() {
	topOfStack = NULL;
	inUse = NULL;
	temporary = NULL;
	sizeOfStack = 0;
}




string Stack::pop(){
	inUse = topOfStack;
	string result;
bool temporaryVar = false;
 while (inUse->next != NULL){
    temporary = inUse;
    inUse = inUse->next;
    if(inUse->info == "") {
     temporaryVar = true;
     break;
 }
}
	if (temporaryVar) {
   result = temporary->info;
   temporary->info = "";
}
	else {
   result = inUse->info;
   inUse->info = "";
 }
	sizeOfStack--;
	return result;
}




void Stack::push(string addinfo){
	//adds string to top of link list
	pointer n = new node;
	n->info = addinfo;
	n->next = NULL;
	if (topOfStack != NULL) {
		inUse = topOfStack;
		while (inUse->next != NULL) {
			inUse = inUse->next;
 }
		inUse->next = n;
}
	else {
		topOfStack = n;
 }
	sizeOfStack++;
}




bool Stack::contains(string sign) {
	if (sizeOfStack != 0) {
		inUse = topOfStack;
		while (inUse->next != NULL) {
			if(inUse->info == sign) {
				return true;
    }
			inUse = inUse->next;
    }
		if(inUse->info == sign) {
			return true;
  }
		return false;
 }
	return false;
}




bool Stack::emptyCheck() {
	if (sizeOfStack == 0) {
		return true;
}
	else {
		return false;
 }
}




void Stack::print(){
  if (sizeOfStack != 0) {
    while (sizeOfStack != 0) {
     cout << " " << pop();
  }
 }
}
Stack checkTheFile(string fileName);
#endif
