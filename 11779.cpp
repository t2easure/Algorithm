#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>

int n, m;

using namespace std;

int main() {
    cin >> n >> m;
    vector <vector<pair<int, int>>> stops(n + 1);
    for (int i = 0; i < m; i++) {
        int start, end, cost;
        cin >> start >> end >> cost;
        stops[start].push_back({end, cost});
    } 
    int start, end;
    cin >> start >> end;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(n + 1, numeric_limits<int>::max());
    dist[start] = 0;
    pq.push({0, start});
    vector<int> previous(n + 1, -1);

    while (!pq.empty()) {
        int distance = pq.top().first;
        int current = pq.top().second;
        pq.pop();

        if (distance > dist[current]) continue;

        for (int i = 0; i < stops[current].size(); i++) {
            int vertex = stops[current][i].first;
            int cost = stops[current][i].second;

            if (dist[vertex] > dist[current] + cost) {
                dist[vertex] = dist[current] + cost;
                previous[vertex] = current;
                pq.push({dist[vertex], vertex});
            }
        }
    }

    cout << dist[end] << endl;
    vector <int> result;
    while (end != -1) {
        result.push_back(end);
        end = previous[end];
    }
    reverse(result.begin(), result.end());

    cout << result.size() << endl;
    for (int i = 0; i < result.size(); i++) cout << result[i] << " ";

    return 0;
}