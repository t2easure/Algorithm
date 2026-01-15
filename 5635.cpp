#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

typedef struct{
    string name;
    int day;
    int month;
    int year;
} student;

bool Compare(const student &a, const student &b){
    if(a.year == b.year){
        if(a.month == b. month){
            return a.day > b.day;
        }

        else{
            return a.month > b.month;
        }
    }

    return a.year > b.year;
}

int main(){
    int n;
    cin >> n;

    vector <student> birthday(n);
    for(int i = 0; i < n; i++){
        cin >> birthday[i].name >> birthday[i].day >> birthday[i].month >> birthday[i].year;
    }

    sort(birthday.begin(), birthday.end(), Compare);

    cout << birthday[0].name << "\n" << birthday[n-1].name;

    return 0;
}