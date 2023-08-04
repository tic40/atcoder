#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  ll n,b; cin >> n >> b;
  auto f = [&](ll x) {
    ll res = 1;
    while (x) {
      res *= x%10;
      x/=10;
    }
    return res;
  };

  ll ans = 0;
  // 10種類(0-9) から重複を許して 11 個選ぶのは n+r-1 C r = 10+11-1 C 11
  auto dfs = [&](auto self, string str, int nex) {
    if (str.size() == 11) {
      ll x = stoll(str);

      ll goal = b + f(x);
      if (goal < 1 || goal > n) return;
      // x を goal にできるか？ 出現する数の個数が一致すれば ok
      auto sg = to_string(goal);
      auto xs = to_string(x);
      sort(sg.begin(),sg.end());
      if (xs == sg) ans++;
      return;
    }
    for (int i = nex; i <= 9; i++) {
      self(self, str+char('0'+i), i);
    }
  };

  dfs(dfs,"",0);

  // 上のdfs では 0 を含むケースが考慮されていない。
  // 0 を含むケースを最後に足す
  string tb = to_string(b);
  bool flag = false;
  for(auto v: tb) if (v == '0') flag = true;
  if (flag && n >= b) ans++;
  cout << ans << endl;
  return 0;
}