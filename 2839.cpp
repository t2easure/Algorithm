#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int sugar_delivery(int n){
    int max_5kg = n / 5;
    while(max_5kg >= 0){
        int remaining_kgs = n - (5 * max_5kg);
        if(remaining_kgs % 3 == 0){
            return max_5kg + (remaining_kgs / 3);
        }

        max_5kg--;
    }

    return -1;
}

int main(){
    int N;
    cin >> N;

    int result = sugar_delivery(N);
    cout << result << "\n";

    return 0;
}