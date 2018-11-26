// Class_DownwardStack.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "pch.h"
#include <cassert>
#include <iostream>
#include <memory>
#include <string>

using namespace std;

const int CAP = 1000;

/*
	DownwardStack Class is a template class for a lifo stack that has the capacity of 'CAP'
*/
template<class E>
class DownwardStack {
public:
	// create empty stack
	DownwardStack() {
		n = CAP;
	}

	// adds x to top of stack
	void push(E x) {
		assert(!is_full());
		elements[CAP - n] = x;
		n--;
	}

	// removes the top element; stack must not be empty
	void pop() {
		assert(!is_empty());
		n++;
	}

	// return the value of the top element; stack must not be empty
	E peek() {
		assert(!is_empty());
		return elements[CAP - n - 1];
	}

	int size() {
		return (CAP - n);
	}

	bool is_empty() {
		return (n == CAP);
	}

	bool is_full() {
		return (n == 0);
	}

	// removes all elements
	void clear() {
		n = CAP;
		assert(is_empty());
	}

private:
	E elements[CAP] = { NULL };
	int n;
};


unique_ptr<string> reverse_string(string& s) {
	DownwardStack<char> lifo;
	unique_ptr<string> result(new string(s.length(),' '));

	unsigned int i=0;
	static unsigned int lifoSize=0;

	//push elements of s onto stack
	for (i = 0; i < s.length(); i++) {
		lifo.push(s[i]);
	}
	lifoSize = lifo.size();
	//pop elements off of stack to reverse string
	for (i = 0; i < lifoSize; i++) {
		result->at(i) = lifo.peek();
		lifo.pop();
	}
	return result;
}


//Test Class Downward Stack for functionality
int main() {

	string str1 = "HELLO",
		str2 = "WORLD",
		str3 = "Testing this stack and the reverse callback. As programmed, it can accept strings of upto 1000 chars";

	cout << str1 << endl << *reverse_string(str1) << endl << endl;
	cout << str2 << endl << *reverse_string(str2) << endl << endl;
	cout << str3 << endl << *reverse_string(str3) << endl << endl;

	/*

	3.) Big-O for DownwardStack member functions

		1: O(1)
		2: O(1)
		3: O(1)
		4: O(1)
		5: O(1)
	*/
	system("pause");
	return 0;
}
