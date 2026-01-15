#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <deque>

using namespace std;

bool flag[100001];
deque <int> dq;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n; cin >> n;
    for(int i = 0; i < n; i++){
        cin >> flag[i];
    }

    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        if(flag[i] == 0){
            dq.push_back(x);
        }
    }

    int m; cin >> m;
    for(int i = 0; i < m; i++){
        int y;
        cin >> y;
        dq.push_front(y);
        cout << dq.back() << " ";
        dq.pop_back();
    }
}
