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

void getNames(vector<string> names, vector<int> scores)
{
    int score;
    cout << "Enter score: ";
    cin >> score;
    bool found = false;

    // check if score is found
    for (int i = 0; i < scores.size(); i++)
    {
        // if score is found, print name
        if (scores[i] == score)
        {
            cout << "Name: " << names[i] << endl;
            found = true;
        }
    }
    // if score is not found, print error message
    if (!found)
    {
        cout << "Score not in system" << endl;
    }
}
int main() {
    cout << "Enter a set of name-and-value pairs separated with space" << endl;
    vector<string> names;
    vector<int> scores;

    getData(names, scores);

    for (int i = 0; i < names.size(); i++) {
        cout << names[i] << " " << scores[i] << endl;
    }

    getNames(names, scores);

    return 0;
}



