
#include <iostream>	

#include <vector>


using namespace std;
/*
	An example input would be
		2
		1 2 3 4 |
	and an example of corresponding output
		the sum of the first 2 numbers (1 2) is 3
*/


int main(){
	int sum = 0;

	cout << "Please enter the number of values you want to sum, starting with the first: ";
	int n = -1;	// initializing to a negative number means that a failed read will be handled by the check of the value
	cin >> n;
	if (n < 1) cout << "Please enter some integers (press '|' to stop): ";


	vector<int> v;
	int x;
	while (cin >> x) v.push_back(x);	

	if (v.size() < n) {
		int sum = 0;
	}
	for (int i = 0; i < n; ++i) sum += v[i];

	cout << "The sum of the first " << n << " numbers ( ";
	for (int i = 0; i < n; ++i) cout << v[i] << ' ';
	cout << ") is " << sum << '\n';

}

