#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  int n,m; cin >> n >> m;
  vector<int> l(n);
  REP(i,n) cin >> l[i];

  auto check = [&](ll x) {
    ll row = 1, col = 0;
    REP(i,n) {
      if (col + l[i] <= x) col += l[i] + 1;
      else { row++; col = l[i] + 1; }
    }
    return row;
  };

  int mx = *max_element(l.begin(),l.end());
  ll ok = 1e18, ng = mx-1;
  while(ok-ng > 1) {
    ll mid = (ok+ng) / 2;
    if (check(mid) <= m) ok = mid;
    else ng = mid;
  }
  cout << ok << endl;
  return 0;
}