#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
const ll LINF = numeric_limits<ll>::max();

int main() {
  ll n; cin >> n;
  string s,t; cin >> s >> t;
  int m = s.size();

  vector is(26,vector<int>());
  REP(i,m) is[s[i]-'a'].push_back(i);

  auto judge = [&](ll k) {
    ll now = 0;
    for(char c: t) {
      vector<int>& nis = is[c-'a']; // 配列コピーは重いため参照にする
      int w = nis.size();
      if (w == 0) return false;

      ll i = lower_bound(nis.begin(), nis.end(), now%m) - nis.begin();
      i += k-1;
      // (i/w)*m: 今回何周したか
      // nis[i%w]: 周回未満で今いる位置
      // now/m*m: これまでに何周進んだか
      now = (i/w)*m + nis[i%w] + now/m*m + 1;
      if (now > n*m) return false;
    }
    return true;
  };

  ll ok = 0, ng = LINF;
  while(abs(ok-ng) > 1) {
    ll mid = (ok+ng)/2;
    if (judge(mid)) ok = mid;
    else ng = mid;
  }
  cout << ok << endl;
  return 0;
}