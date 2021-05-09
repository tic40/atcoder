#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;

int n;
vector<int> a;

void solve() {
  map<int, int> m;
  REP(i,n) {
    a[i] %= 200;
    m[a[i]]++;
  }

  ll ans = 0;
  REP(i,n) ans += max(0, m[a[i]]-1);
  ans /= 2;

  cout << ans << endl;
  return;
}


int main() {
  cin >> n;
  a.resize(n);
  REP(i,n) cin >> a[i];

  solve();
  return 0;
}