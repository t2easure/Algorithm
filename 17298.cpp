#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

    int N;
    cin >> N;

    vector<int> numbers(N);
    for(int i = 0; i < N; i++){
        cin >> numbers[i];
    }

    vector<int> result(N, -1); 
    stack<int> s; 

    for (int i = 0; i < N; i++) {
        while (!s.empty() && numbers[s.top()] < numbers[i]) {
            result[s.top()] = numbers[i];
            s.pop();
        }
        s.push(i);
    }

    for(int i = 0; i < N; i++){
        cout << result[i] << " ";
    }

    return 0;
}
