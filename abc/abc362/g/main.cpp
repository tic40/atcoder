#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  string s; cin >> s;
  int q; cin >> q;
  int n = s.size();

  auto sa = suffix_array(s);

  auto f = [&](string t) {
    int m = t.size();
    int ng = -1, ok = n;

    while(ng+1 < ok) {
      int wj = (ok+ng) / 2;
      if (s.substr(sa[wj],m) >= t) ok = wj;
      else ng = wj;
    }
    return ok;
  };

  REP(_,q) {
    string t; cin >> t;
    int ans = f(t + '~') - f(t);
    cout << ans << endl;
  }
  return 0;
}