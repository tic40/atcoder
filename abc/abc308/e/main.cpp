#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
using P = pair<int,int>;

int main() {
  int n; cin >> n;
  vector<int> a(n);
  REP(i,n) cin >> a[i];
  string s; cin >> s;

  vector<int> m(3);
  map<P,ll> e;
  ll ans = 0;
  REP(i,n) {
    if (s[i] == 'M') m[a[i]]++;
    if (s[i] == 'E') REP(j,3) e[{j,a[i]}] += m[j];
    if (s[i] == 'X') {
      for(auto [k,v]: e) {
        vector<bool> mex(4);
        mex[k.first] = mex[k.second] = mex[a[i]] = true;
        REP(j,4) if (!mex[j]) { ans += (ll)j * v; break; }
      }
    }
  }
  cout << ans << endl;
  return 0;
}