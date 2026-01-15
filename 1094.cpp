#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main(){
    int X;
    cin >> X;

    vector <int> stick;
    stick.push_back(64);

    while(accumulate(stick.begin(), stick.end(), 0) > X){
        int min_length = stick.back();
        stick.pop_back();

        stick.push_back(min_length / 2);
        if(X > accumulate(stick.begin(), stick.end(), 0)){
            stick.push_back(min_length / 2);
        }
    }

    int count = 0;
    for(int i = 0; i < stick.size(); ++i){
        if(accumulate(stick.begin(), stick.begin() + i + 1, 0) >= X){
            count = i + 1;
            break;
        }
    }

    cout << count;

    return 0;
}