#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N, M;
    cin >> N >> M;

    unordered_map<string, string> passwordMap;

    for(int i = 0; i < N; i++){
        string site, password;
        cin >> site >> password;
        passwordMap[site] = password;
    }

    for(int i = 0; i < M; i ++){
        string siteName;
        cin >> siteName;

        if (passwordMap.count(siteName)) {
            cout << passwordMap[siteName] << "\n";
        }
    }

    return 0;
}