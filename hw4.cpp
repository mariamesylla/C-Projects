#include <iostream>

using namespace std;

int main()
{
	int val1 = 0;
	int val2 = 0;
	cout << "Please enter first integer value: ";
	cin >> val1;	
	cout << "Please enter second integer value: ";
	cin	>> val2;

	if (val1 < val2) cout << val1 << " is the smallest and "<< val2 <<"is the largest" << "\n";
	if (val1 > val2) cout << val2 << " is the smallestand " << val1 << "is the largest" << "\n";

	cout << "The sum of " << val1 << " and " << val2 << " is: " << val1 + val2 << "\n";
	cout << "The difference of " << val1 << " and " << val2 << " is: " << val1 - val2 << "\n";
	cout << "The product  of " << val1 << " and " << val2 << " is: " << val1 * val2 << "\n";
	cout << "The ratio  of " << val1 << " and " << val2 << " is: " << val1 / val2 << "\n";
	return 0;
}