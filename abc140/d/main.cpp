#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;

int n,k;
string s;

void solve() {
  int ans = n-1, cnt = 0;
  REP(i,n-1) if (s[i+1] != s[i]) cnt++;

  ans -= max(0, cnt - k*2);
  cout << ans << endl;
  return;
}

int main() {
  cin >> n >> k >> s;

  solve();
  return 0;
}