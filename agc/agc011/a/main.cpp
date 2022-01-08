#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)

int n,c,k;
vector<int> t;

void solve() {
  sort(t.begin(), t.end());
  int ans = 0, i = 0;

  while(1) {
    if (i == n) break;
    ans++;
    int start = i;
    while(i < n && t[i] - t[start] <= k && i - start < c) i++;
  }

  cout << ans << endl;
  return;
}

int main() {
  cin >> n >> c >> k;
  t.resize(n);
  REP(i,n) cin >> t[i];

  solve();
  return 0;
}