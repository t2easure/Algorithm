#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector <int> number(N);
    for (int i = 0; i < N; i++) {
        cin >> number[i];
    } 

    vector <char> op;
    int plus;
    cin >> plus;
    for (int i = 0; i < plus; i++) op.push_back('+');

    int minus;
    cin >> minus;
    for (int i = 0; i < minus; i++) op.push_back('-');

    int multiply;
    cin >> multiply;
    for (int i = 0; i < multiply; i++) op.push_back('*');

    int divided;
    cin >> divided;
    for (int i = 0; i < divided; i++) op.push_back('/');
    
    long long max_num = LLONG_MIN;
    long long min_num = LLONG_MAX;
    sort(op.begin(), op.end());
    
    do {
        vector <char> op2;
        for (int i = 0; i < op.size(); i++) {
            op2.push_back(op[i]);
        }
        long long num = number[0];
        for (int i = 1; i < N; i++) {
            if (op2[i - 1] == '+') num += number[i];
            if (op2[i - 1] == '-') num -= number[i];
            if (op2[i - 1] == '*') num *= number[i];
            if (op2[i - 1] == '/') num /= number[i];
        }
        if (max_num < num) max_num = num;
        if (min_num > num) min_num = num;
    } while (next_permutation(op.begin(), op.end()));

    cout << max_num << endl << min_num;

    return 0;
}