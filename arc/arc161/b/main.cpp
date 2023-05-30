#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  int t; cin >> t;

  auto f = [&](ll n) -> ll {
    if (__builtin_popcountll(n) < 3) return -1;
    int cnt = 0;
    ll res = 0;
    REP(i,61) {
      if ((n >> (60-i) & 1) == 0) continue;
      cnt++;
      res += 1LL << (60-i);
      if (cnt == 3) break;
    }
    return res;
  };

  REP(_,t) {
    ll n; cin >> n;
    ll ans = -1;
    while (n >= 7) {
      ans = f(n);
      if (ans != -1) break;
      else n--;
    }
    cout << ans << endl;
  }
  return 0;
}