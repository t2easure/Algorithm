#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M;
bool visited[9];
int arr[9];


void dfs(int cnt, vector <int> &arr2){
    if(cnt == M){
        for(int i = 0; i < M; i++){
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }

    for(int i = 0; i < N; i++){
        if(!visited[i]){

            arr[cnt] = arr2[i];
            dfs(cnt + 1, arr2);

        }
    }
}

int main(){
    cin >> N >> M;
    vector <int> arr2(N);
    for(int i = 0; i < N; i++){
        cin >> arr2[i];
    }

    sort(arr2.begin(), arr2.end());

    dfs(0, arr2);
}