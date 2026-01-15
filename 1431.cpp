#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

bool Compare(string a, string b){
    if(a.length() == b.length()){
        int Asum = 0; int Bsum= 0;
        for(int i = 0; i < a.length(); i++){
            if(a[i] >= '0' && a[i] <= '9'){
                Asum += a[i] - '0';
            }
        } 
        for(int i = 0; i < b.length(); i ++){
            if(b[i] >= '0' && b[i] <= '9'){
                Bsum += b[i] - '0';
            }
        }
        if(Asum != Bsum){
            return Asum < Bsum;
        }
        else {
            return a < b;
        }
    }

    return a.length()< b.length();
}

int main(){
    int N;
    cin >> N;

    vector <string> v(N);
    for(int i = 0; i < N; i++){
        cin >> v[i];
    }

    sort(v.begin(), v.end(), Compare);

    for(int i = 0; i < v.size(); i++){
        cout << v[i] << "\n";
    }

    return 0;
}