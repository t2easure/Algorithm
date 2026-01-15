#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <deque>

using namespace std;

int main(){
    int N;
    cin >> N;

    int count = 0;

    for(int i = 0; i < N; i++){
        string word;
        cin >> word;

        vector <bool> visited(26, false);
        bool is_group = true;

        for(int j = 0; j < word.length(); j++){
            if(visited[word[j] - 'a'] == true){
                if(j > 0 && word[j - 1] != word[j]){
                    is_group = false;
                    break;
                }
            }
            else{
                visited[word[j] - 'a'] = true;
            }
        }

        if(is_group){
            count ++;
        }
    }

    cout << count << "\n";

    return 0;
}