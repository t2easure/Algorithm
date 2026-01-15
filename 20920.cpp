#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

bool compare(pair <string, int> a, pair <string, int> b) {
    if (a.second == b.second && a.first.length() != b.first.length()) {
        return a.first.length() > b.first.length();
    } else if (a.second == b.second && a.first.length() == b.first.length()){
        return a.first < b.first;
    }
    return a.second > b.second;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    map<string, int> word_map;

    for (int i = 0; i < N; i++) {
        string word;
        cin >> word;
        if (word.length() >= M) {
            word_map[word]++;
        }
    }

    vector <pair<string, int>> wordlist(word_map.begin(), word_map.end());
    
    sort(wordlist.begin(), wordlist.end(), compare);

    for (int i = 0; i < wordlist.size(); i++) {
        cout << wordlist[i].first << '\n';
    }

    return 0;
}