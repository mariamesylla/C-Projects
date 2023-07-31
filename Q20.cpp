#include<iostream>
#include<vector>

using namespace std;


void getData(vector<string>& names, vector<int>& scores) {
	while (true) {
		string name;
		int score;
		cin >> name >> score;

		if (name == "NoName" && score == 0) {
			break;
		}

		names.push_back(name);
		scores.push_back(score);
	}
}

void getScore(vector<string> names, vector<int> scores)
{
	string name;
	cout << "Enter name: ";
	cin >> name;

	for (int i = 0; i < names.size(); i++)
	{
		if (names[i] == name)
		{
			cout << "Score: " << scores[i] << endl;
			return;
		}
	}
	cout << "Name not found" << endl;
}
int main() {
	cout << "enter a set of name-and-value pairs separated with space" << endl;
	vector<string> names;
	vector<int> scores;

	getData(names, scores);

	for (int i = 0; i < names.size(); i++) {
		cout << names[i] << " " << scores[i] << endl;
	}
	getScore(names, scores);


	return 0;
}