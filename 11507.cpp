#include <iostream>
#include <string>
#include <set>

using namespace std;

int main() {
    string str;
    cin >> str;

    set<string> cardSet; 
    int cardCount[4] = {13, 13, 13, 13};
    for (int i = 0; i < str.length(); i += 3) {
        string card = str.substr(i, 3);
        
        if (cardSet.find(card) != cardSet.end()) { 
            cout << "GRESKA\n";
            return 0;
        }
        
        cardSet.insert(card);
        
        char shape = card[0];
        int num = stoi(card.substr(1));

        if (shape == 'P') {
            cardCount[0]--;
        } else if (shape == 'K') {
            cardCount[1]--;
        } else if (shape == 'H') {
            cardCount[2]--;
        } else if (shape == 'T') {
            cardCount[3]--;
        }
    }

    for (int i = 0; i < 4; i++) {
        cout << cardCount[i] << " ";
    }

    return 0;
}
