#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

int main(){
    int n; cin >> n;
    deque <double> drink(n);

    for(int i = 0; i < n; i++){
        cin >> drink[i];
    }

    sort(drink.begin(), drink.end());

    for(int i = 0; i < n - 1; i++){
        drink.back() += drink[0] / 2;
        drink.pop_front();
    }

    cout << drink[0] << endl;

    return 0;
}