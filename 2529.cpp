#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    int k;
    cin >> k;

    vector <char> A(k);
    for (int i = 0; i < k; i++) cin >> A[i];

    string maximum = "";
    for (int i = 0; i < k + 1; i++) maximum += '9' - i;    

    for (int i = 0; i < k; i++) {
        if (A[i] == '>' && maximum[i] < maximum[i + 1]) {
            int j = i + 1;
            while (j < k && A[j] == '>') j++;
            reverse(maximum.begin() + i, maximum.begin() + j + 1);
        } else if (A[i] == '<' && maximum[i] > maximum[i + 1]) {
            int j = i + 1;
            while (j < k && A[j] == '<') j++;
            reverse(maximum.begin() + i, maximum.begin() + j + 1);
        }
    }

    cout << maximum << endl;

    string minimum = "";
    for (int i = 9; i >= 9 - k; i--) minimum += '9' - i;

    for (int i = 0; i < k; i++) {
        if (A[i] == '<' && minimum[i] > minimum[i + 1]) {
            int j = i + 1;
            while (j < k && A[j] == '<') j++;
            reverse(minimum.begin() + i, minimum.begin() + j + 1);
        } else if (A[i] == '>' && minimum[i] < minimum[i + 1]) {
            int j = i + 1;
            while (j < k && A[j] == '>') j++;
            reverse(minimum.begin() + i, minimum.begin() + j + 1);
        }
    }

    cout << minimum << endl;

    return 0;
}