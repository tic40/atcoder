#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
const int MOD = 2147483647;

int main() {
  int n,q; cin >> n >> q;
  string s; cin >> s;

  string sr = s;
  reverse(sr.begin(),sr.end());

  vector<ll> power(n+1);
  power[0] = 1;
  REP(i,n) power[i+1] = 100LL * power[i] % MOD;

  vector<ll> h(n+1);
  REP(i,n) h[i+1] = (100LL * h[i] + (s[i]-'a'+1)) % MOD;

  vector<ll> hr(n+1);
  REP(i,n) hr[i+1] = (100LL * hr[i] + (sr[i]-'a'+1)) % MOD;

  // 左から読んだときのハッシュ計算
  auto hash_value = [&](int l, int r) {
    ll val = h[r] - ((h[l-1] * power[r-l+1]) % MOD);
    if (val < 0) val += MOD;
    return val;
  };

  // 右から読んだときのハッシュ計算
  auto hash_value_r = [&](int l, int r) {
    int nl = n+1-r, nr = n+1-l;
    ll val = hr[nr] - ((hr[nl-1] * power[nr-nl+1]) % MOD);
    if (val < 0) val += MOD;
    return val;
  };

  REP(_,q) {
    int l,r; cin >> l >> r;
    cout << (hash_value(l,r) == hash_value_r(l,r) ? "Yes" : "No") << endl;
  }
  return 0;
}