#include <iostream>
using namespace std;

int N, M;
bool visited[9];
int arr[9];

void dfs(int num, int cnt){
    if(cnt == M){
        for(int i = 0; i < M; i++){
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }

    for(int i = num; i <= N; i++){
        if(!visited[i]){
            arr[cnt] = i;
            dfs(i, cnt + 1);
        }
    }
}

int main(){
    cin >> N >> M;
    dfs(1, 0);
}