#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {
    long long N, M, B;

    cin >> N >> M >> B;

    vector<vector<int>> blocks(N, vector<int>(M));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> blocks[i][j];
        }
    }

    int minTime = INT_MAX;
    int bestHeight = -1;

    for (int h = 0; h <= 256; h++) {
        long long add = 0;
        long long remove = 0;
        for (int j = 0; j < N; j++) {
            for (int a = 0; a < M; a++) {
                int height = blocks[j][a];
                if (height < h)
                    add += h - height;
                else if (height > h)
                    remove += height - h;
            }
        }

        long long usedBlocks = B + remove - add;
        if (usedBlocks >= 0) {
            int currentTime = add + remove * 2;
            if (currentTime < minTime || (currentTime == minTime && h > bestHeight)) {
                minTime = currentTime;
                bestHeight = h;
            }
        }
    }

    cout << minTime << " " << bestHeight << endl;

    return 0;
}
