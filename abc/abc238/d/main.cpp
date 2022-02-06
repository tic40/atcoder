#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)
using ll = long long;

int t;
vector<ll> a,s;

// x + y = (x XOR y) + 2*(x AND y) であることを利用する解法
void solve1() {
  REP(i,t) {
    bool ok = false;
    // x + y = (x XOR y) + 2*(x AND y)
    // x + y = s, x AND y = a より、
    // s = (x XOR y) + 2*a

    ll diff = s[i] - 2*a[i];
    if (0 <= diff) { // マイナスになるケースを考慮
      if ( (diff & a[i]) == 0) ok = true;
    }
    cout << (ok ? "Yes" : "No") << endl;
  }

  return;
}

map<pair<ll, ll>, bool> mp;
bool f(ll a, ll s) {
  if (s == 0) return a == 0;

  auto p = make_pair(a,s);
  if (mp.count(p)) return mp[p];

  // 1の位を全部試す
  REP(x,2) REP(y,2) {
    // AND側の条件
    // x&y がaのひとけた目と一致している必要
    if ( (x & y) != (a & 1) ) continue;
    if (s-x-y < 0) continue;
    if ( ((s-x-y) & 1) != 0) continue;
    if ( f(a>>1, (s-x-y)>>1) ) return mp[p] = true;
  }
  return mp[p] = false;
};

// 桁DP解法
void solve2() {
  REP(i,t) {
    mp = map<pair<ll, ll>, bool>(); // mapをクリアする
    cout << (f(a[i],s[i]) ? "Yes" : "No") << endl;
  }
  return;
}

int main() {
  cin >> t;
  a.resize(t); s.resize(t);
  REP(i,t) cin >> a[i] >> s[i];

  // solve1();
  solve2();
  return 0;
}