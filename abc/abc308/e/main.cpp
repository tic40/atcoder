#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  int n; cin >> n;
  vector<int> a(n);
  REP(i,n) cin >> a[i];
  string s; cin >> s;

  auto mex = [](int x, int y, int z) {
    vector<bool> mex(3);
    mex[x] = mex[y] = mex[z] = true;
    REP(i,3) if (!mex[i]) return i;
    return 3;
  };

  vector<int> m(3);
  vector e(3,vector<ll>(3));
  ll ans = 0;
  REP(i,n) {
    if (s[i] == 'M') m[a[i]]++;
    if (s[i] == 'E') REP(j,3) e[j][a[i]] += m[j];
    if (s[i] == 'X') {
      REP(j,3) REP(k,3) ans += mex(j,k,a[i]) * e[j][k];
    }
  }
  cout << ans << endl;
  return 0;
}