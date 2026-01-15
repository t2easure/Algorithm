#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

typedef struct{
    int country;
    int number;
    int grade;
} student;

bool isTrue(const student &a, const student &b){
    return a.grade > b.grade;
}

int main(){
    int N;
    cin >> N;

    vector <student> v(N);
    for(int i = 0; i < N; i++){
        cin >> v[i].country >> v[i].number >> v[i].grade;
    }

    sort(v.begin(), v.end(), isTrue);

    vector <student> v2;
    for(int i = 0; i < 3; i++){
        v2.push_back(v[i]);
    }

    if(v2[0].country == v2[1].country){
        int i = 3;
        while(i< v.size() && v2[0].country == v2[2].country){
            v2.pop_back();
            v2.push_back(v[i]);
            i ++;
        }
    }

    for(int i = 0; i < 3; i++){
        cout << v2[i].country << " " << v2[i].number << "\n";
    }

    return 0;
}