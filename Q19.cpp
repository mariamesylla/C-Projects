#include <iostream>
#include <vector>

using namespace std;

void getData(vector<string> & names, vector<int> & scores) {
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

int main() {
    cout << "enter a set of name-and-value pairs separated with space" <<endl;
    vector<string> names;
    vector<int> scores;

    getData(names, scores);

    for (int i = 0; i < names.size(); i++) {
        cout << names[i] << " " << scores[i] << endl;
    }

    return 0;
}