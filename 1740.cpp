#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    vector <long long> number;

    long long N;
    cin >> N;

    while (N >= 1) {
        number.push_back(N % 2);
        N /= 2;
    }

    long long result = 0;
    long long num = 1;
    for (int i = 0; i < number.size(); i ++) {
        if (number[i] == 1) result += num;
        num *= 3;
    }
    
    cout << result << endl;
    return 0;
}