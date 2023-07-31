#include <iostream>

using namespace std;

int main()
{
	int integer1 = 0;
	int integer2 = 0;
	int integer3 = 0;

	int smallest = 0;
	int mid = 0;
	int largest = 0;

	cout << "Please enter three integers separated by space ";
	cin >> integer1 >> integer2 >> integer3;


	if (integer1 <= integer2 && integer1 <= integer3) {
		smallest = integer1;
		if (integer2 <= integer3) {
			mid = integer2;
			largest = integer3;
		}
		else {
			mid = integer3;
			largest = integer2;
		}
	}
	else if (integer2 <= integer1 && integer2 <= integer3) {
		smallest = integer2;
		if (integer1 <= integer3) {
			mid = integer1;
			largest = integer3;
		}
		else {
			mid = integer3;
			largest = integer1;
		}
	}
	else {	
		smallest = integer3;
		if (integer1 <= integer2) {
			mid = integer1;
			largest = integer2;
		}
		else {
			mid = integer2;
			largest = integer1;
		}
	}

	cout << "The values entered are sorted as : " << smallest << ", " << mid << ", " << largest << '\n';


	return 0;


}