#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;
const int mod = 100000;

int digit_sum(int x) {
  int res = 0;
  while(x > 0) {
    res += x%10;
    x /= 10;
  }
  return res;
}

int n;
ll k;

void solve() {
  vector<int> visited(100000, -1);
  int pos = n, cnt = 0;
  while(visited[pos] == -1) {
    visited[pos] = cnt;
    pos = (pos + digit_sum(pos)) % mod;
    cnt++;
  }

  // visited[pos] がサイクルに入るまでの回数
  int cycle = cnt - visited[pos];
  if (visited[pos] <= k) {
    k = (k-visited[pos]) % cycle;
    k += visited[pos];
  }

  REP(i, 100000) {
    if (visited[i] == k) {
      cout << i << endl;
      return;
    }
  }

  return;
}

int main() {
  cin >> n >> k;
  solve();
  return 0;
}