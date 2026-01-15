#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N;
    cin >> N;

    int M, K;
    cin >> M >> K;

    vector <int> CTPmem(N);
    for(int i = 0; i < N; i++){
        cin >> CTPmem[i];
    }

    int penNum = M * K;

    sort(CTPmem.begin(), CTPmem.end(), greater<int>());
    
    int sum = 0;
    int num = 0;
    for(int i = 0; i < CTPmem.size(); i++){
        sum += CTPmem[i];
        num += 1;
        if(sum >= penNum){
            cout << num;
            break;
        }
    }

    if(sum < penNum){
        cout << "STRESS";
    }

    return 0;
}