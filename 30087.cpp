#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    vector <pair<string, string>> v;

    v.push_back({"Algorithm", "204"});
    v.push_back({"DataAnalysis", "207"});
    v.push_back({"ArtificialIntelligence", "302"});
    v.push_back({"CyberSecurity", "B101"});
    v.push_back({"Network", "303"});
    v.push_back({"Startup", "501"});
    v.push_back({"TestStrategy", "105"});

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        string input;
        cin >> input;

        for (int j = 0; j < v.size(); j++) {
            if (input == v[j].first) cout << v[j].second << endl;
        }
    }

    return 0;
}