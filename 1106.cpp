#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    int C, N;
    cin >> C >> N;

    vector<pair<int, int>> promotion(N);
    vector<int> cost(C + 101, INT_MAX);
    
    for (int i = 0; i < N; i++) {
        cin >> promotion[i].first >> promotion[i].second;
    }

    cost[0] = 0;

    for (int i = 0; i <= C; i++) {
        if (cost[i] == INT_MAX) continue;
        for (int j = 0; j < N; j++) {
            int price = promotion[j].first;
            int customer = promotion[j].second;
            if (i + customer < cost.size()) {
                cost[i + customer] = min(cost[i + customer], cost[i] + price);
            }
        }
    }

    int result = INT_MAX;
    for (int i = C; i < cost.size(); i++) 
        result = min(result, cost[i]);
    
    cout << result;
    
    return 0;
}