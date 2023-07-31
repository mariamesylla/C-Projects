#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

vector<int> countChars(vector<string> strings) {
    vector<int> result;
    for (string s : strings) {
        result.push_back(s.size());
    }
    return result;
}

int main() {

    vector<string> strings;
    cout << "Please enter a set of string enter q to end " <<endl;
    string name = "a";
    while (name !="q") {
        cin >> name;
        strings.push_back(name);
    }
    strings.pop_back();

    vector<int> charCounts = countChars(strings);


    int longestIndex = max_element(strings.begin(), strings.end(), [](string const& a, string const& b) { return a.size() < b.size(); }) - strings.begin();
    int shortestIndex = min_element(strings.begin(), strings.end(), [](string const& a, string const& b) { return a.size() < b.size(); }) - strings.begin();
    string first = *min_element(strings.begin(), strings.end());
    string last = *max_element(strings.begin(), strings.end());

    cout << "The number of character in each word: ";
    for (int i : charCounts) {
        cout << i << " ";
    }
    cout << endl;
    cout << "The longest string is: " << strings[longestIndex] << endl;
    cout << "The shortest string is : " << strings[shortestIndex] << endl;
   
    cout << "First string lexicographically: " << first << endl;
    cout << "Last string lexicographically: " << last << endl;

    return 0;
}