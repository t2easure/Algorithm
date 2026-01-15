#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<size_t, size_t> memo;
size_t N, P, Q;

size_t number(size_t num) {
    if (num == 0) return 1;
    if (memo.count(num) > 0) return memo[num];

    memo[num] = number(num / P) + number(num / Q);
    return memo[num];
}

int main() {
    cin >> N >> P >> Q;
    cout << number(N) << endl;
    
    return 0;
}