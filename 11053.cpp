#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int N;
  cin >> N;

  vector<int> v(N + 1);
  vector<int> dp(N + 1, 1);

  for (int i = 1; i <= N; i++) {
    cin >> v[i];
  }

  for (int i = 1; i <= N; i++) {
    for (int j = 1; j < i; j++) {
      if (v[i] > v[j]) {
        dp[i] = max(dp[i], dp[j] + 1);
      }
    }
  }

  int max = dp[0];
  for (int i = 1; i <= N; i++) {
    if (max <= dp[i]) {
      max = dp[i];
    }
  }

  cout << max;
}