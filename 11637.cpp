#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        int n;
        cin >> n;

        int totalVotes = 0;
        int maxVotes = 0;
        int maxCandidate = 0;
        bool uniqueMax = true;

        for (int i = 1; i <= n; i++) {
            int votes;
            cin >> votes;
            totalVotes += votes;

            if (votes > maxVotes) {
                maxVotes = votes;
                maxCandidate = i;
                uniqueMax = true;
            } else if (votes == maxVotes) {
                uniqueMax = false;
            }
        }

        if (uniqueMax && maxVotes > totalVotes / 2) {
            cout << "majority winner " << maxCandidate << "\n";
        } else if (uniqueMax) {
            cout << "minority winner " << maxCandidate << "\n";
        } else {
            cout << "no winner\n";
        }
    }

    return 0;
}
