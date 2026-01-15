#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int N, M;
vector<pair<int, int>> houses;
vector<pair<int, int>> chickens;
int minDistance = INT_MAX;

void calculate(vector<pair<int, int>> &selected, int start, int depth) {
    if (depth == M) {
        int current = 0;
        for (int i = 0; i < houses.size(); i++) {
            int minDist = INT_MAX;
            for (int j = 0; j < selected.size(); j++) { 
                int dist = abs(houses[i].first - selected[j].first) + abs(houses[i].second - selected[j].second);
                minDist = min(minDist, dist);
            }
            current += minDist;
        }
        minDistance = min(minDistance, current);
        return;
    }

    for (int i = start; i < chickens.size(); i++) {
        selected.push_back(chickens[i]);
        calculate(selected, i + 1, depth + 1);
        selected.pop_back();
    }
}

int main() {
    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            int type;
            cin >> type;
            if (type == 1) houses.push_back({i, j});
            else if (type == 2) chickens.push_back({i, j});
        }
    }

    vector<pair<int, int>> selected;
    calculate(selected, 0, 0);

    cout << minDistance << endl;

    return 0;
}