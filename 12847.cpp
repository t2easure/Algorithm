#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    long long int n, m;
    cin >> n >> m;

    vector<long long int> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }

    vector<long long int> prefixSum(n + 1, 0); 
    for(int i = 1; i <= n; i++){
        prefixSum[i] = prefixSum[i - 1] + v[i - 1];
    }

    long long int maxSum = 0;
    for(int i = 0; i <= n - m; i++){
        long long int sum = prefixSum[i + m] - prefixSum[i]; 
        maxSum = max(maxSum, sum);
    }

    cout << maxSum;

    return 0;
}
