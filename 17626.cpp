#include <iostream>
#include <vector>
#include <cmath>

long long solution(long long n) {
    long long answer = 0;
    if(sqrt(n)==(int)sqrt(n)) answer = 1;
    else answer = -1;
    return answer;
}

using namespace std;

int main() {
    int n;
    cin >> n;

    vector <int> nums(n + 1);

    for (int i = 1; i <= n; i++ ){
        if (solution(i) ==1) 
            nums[i] = 1;
        else if (solution(i - 1) == 1)
            nums[i] = 2;
        else {
            int min = 5;
            for (int j = 1; j <= i - 1; j++) {
                int num = nums[j] + nums[i - j];
                if (min > num) 
                    min = num;
            }
            nums[i] = min;
        }
    }

    cout << nums[n] << "\n";
}