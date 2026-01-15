#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int M, F;
    cin >> M >> F;

    while(M != 0 && F != 0){
        cout << M + F << "\n";
        cin >> M >> F;
    }
}