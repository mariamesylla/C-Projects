#include <iostream>

using namespace std;

int main() {

	double num1 = 0;
	double num2 = 0;
	char operation = 0;
	double result = 0;
	cout << "please enter two numbers separated by one of the operator  + - * or / : ";

	cin >> num1 >> operation >> num2;

	string oper;


	switch (operation) {

		case '+':
			oper = "sum of ";
			result = num1 + num2;
			break;
		case '-':
			oper = "substraction between ";
			result = num1 - num2;
			break;
		case '*':
			oper = "product of ";
			result = num1 * num2;
			break;
		case '/':
			oper = "ratio of ";
			result = num1 / num2;
			break;

		default:
			cout<< "Wrong Input ";
		}

	cout << oper << num1 << " and " << num2 << " is " << result << '\n';


	return 0;
	}