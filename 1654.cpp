#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int K, N;
    cin >> K >> N;

    vector <long long> lan(K);
    for (int i = 0; i < K; i++) 
        cin >> lan[i];

    long long low = 1;
    long long high = *max_element(lan.begin(), lan.end());
    long long max_len = 0;

    while (low <= high) {
        long long mid = (low + high) / 2;
        long long num = 0;

        for (int i = 0; i < K; i++)
            num += lan[i] / mid;
        
        if (N <= num) {
            max_len = mid;
            low = mid + 1;
        } else  
            high = mid - 1;
    }

    cout << max_len;

    return 0;
}