#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int N, M;
int main() {
    cin >> N >> M;
    int truth;
    cin >> truth;
    set <int> knowing_people;
    for (int i = 0; i < truth; i++) {
        int person;
        cin >> person;
        knowing_people.insert(person);
    }

    vector<vector<int>> party(M + 1);
    vector<bool> cant_tell_truth(M + 1, false);

    for (int i = 1; i <= M; i++) {
        int a;
        cin >> a;
        party[i].resize(a);
        for (int j = 0; j < a; j++) {
            cin >> party[i][j];

            if (knowing_people.find(party[i][j]) != knowing_people.end()) cant_tell_truth[i] = true;
        }
    }

    bool changed = true;
    while (changed) {
        changed = false;
        for (int i = 1; i <= M; i++) {
            if (cant_tell_truth[i]) {
                for (int person : party[i]) {
                    if (knowing_people.insert(person).second) changed = true;
                }
            }
        }

        for (int i = 1; i<= M; i++) {
            if (!cant_tell_truth[i]) {
                for (int person : party[i]) {
                    if (knowing_people.find(person) != knowing_people.end()) {
                        cant_tell_truth[i] = true;
                        changed = true;
                        break;
                    }
                }
            }
        }
    }

    int parties = 0;
    for (int i = 1; i <= M; i++) {
        if (!cant_tell_truth[i]) parties += 1;
    }

    cout << parties << endl;
    return 0;
}