#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool isPrefix(const string& prefix, const string& word) {
    // prefix : 비교할 접두사 문자열, word : 비교 대상이 되는 문자열
    if (prefix.length() > word.length()) return false;
    return word.compare(0, prefix.length(), prefix) == 0;
    // prefix가 word의 접두사면 true, 그렇지 않으면 false 반환
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<string> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }   

    vector<string> result(M);
    for (int i = 0; i < M; i++) {
        cin >> result[i];
    }

    sort(arr.begin(), arr.end()); // 이진 탐색을 위한 정렬

    int num = 0;
    
    for (int i = 0; i < M; i++) {
        auto it = lower_bound(arr.begin(), arr.end(), result[i]);
        // lower_bound 함수 사용해 result[i]와 같거나 큰 첫번째 요소 찾음 [이진 탐색]
        if (it != arr.end() && isPrefix(result[i], *it)) {
            // isPrefix 함수 사용해 찾은 요소가 result[i]의 접두사인지 확인
            // it가 arr.end()가 아니면 배열 안에서 result[i]를 찾은 것
            num += 1;
        }
        if (it != arr.begin()) {
            it -= 1; // it을 하나 감소시켜 이전 요소 가리키도록 함
            if (isPrefix(result[i], *it)) {
                num += 1; // 접두사 관계 확인
            }
        }
    }

    cout << num << endl;

    return 0;
}