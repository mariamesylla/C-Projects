
#include <iostream>
#include <vector>

using namespace std;

void print(const string& label, const vector<int>& v)
{
	cout << label << "( ";
	for (int i = 0; i < v.size(); ++i) cout << v[i] << ' ';
	cout << ")\n";
}

void rev1(vector<int>& v)
{
	vector<int> v2;
	for (int i = v.size() - 1; 0 <= i; --i)	
		v2.push_back(v[i]);
	v = v2;
}

void rev2(vector<int>& v)
{
	for (int i = 0; i < v.size() / 2; ++i)
		swap(v[i], v[v.size() - 1 - i]);
}


int main()
{
	vector<int> val;

	cout << "Please enter a sequence of integers ending with any non-digit character: ";
	int i;
	while (cin >> i) val.push_back(i);
	print("String: ", val);
	rev1(val);
	print("First reverse: ", val);
	rev2(val);
	print("Second reverse: ", val);
}


