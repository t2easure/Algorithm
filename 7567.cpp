#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string s;
    cin >> s;

    // 첫 번째 그릇은 무조건 10cm
    int height = 10;

    // 두 번째 문자(인덱스 1)부터 끝까지 순회
    for (int i = 1; i < s.length(); ++i) {
        // 바로 앞의 그릇(i-1)과 현재 그릇(i)이 같은 모양이면
        if (s[i] == s[i - 1]) {
            height += 5;
        }
        // 모양이 다르면
        else {
            height += 10;
        }
    }

    cout << height << endl;

    return 0;
}