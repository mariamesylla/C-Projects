#include <iostream>

using namespace std;

int main() {

	string operation;
	double op1 = 0;
	double op2 = 0;	
	double sol = 0;

	cout << "Please enter an operation (Plus, Minus, Mul, Div, +, -, *, /) followed by two operands values separated by space : ";
	
	cin >> operation >> op1 >> op2;

	if (operation == "plus" || operation == "+") {
		sol = op1 + op2;
	}
	else if (operation == "minus" || operation == "-") {
		sol = op1 - op2;
	}
	else if (operation == "mul" || operation == "*") {
		sol = op1 * op2;
	}
	else if (operation == "div" || operation == "/") {
		sol = op1 / op2;
		
	}
	else {
		cout << "Please try again: ";
	}


	cout << op1 << operation << op2 << " = " << sol << '\n';

	return 0;

	}