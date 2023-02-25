#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
const int MOD = 2147483647;

int main() {
  int n,q; cin >> n >> q;
  string s; cin >> s;

  vector<ll> power100(n+1);
  power100[0] = 1;
  REP(i,n) power100[i+1] = 100LL * power100[i] % MOD;

  vector<ll> h(n+1);
  REP(i,n) h[i+1] = (100LL * h[i] + (s[i]-'a'+1)) % MOD;

  auto hash_value = [&](int l, int r) {
    ll val = h[r] - (h[l-1] * power100[r-l+1] % MOD);
    if(val < 0) val += MOD;
    return val;
  };

  REP(_,q) {
    int a,b,c,d; cin >> a >> b >> c >> d;
    ll hash1 = hash_value(a,b);
    ll hash2 = hash_value(c,d);
    cout << (hash1 == hash2 ? "Yes" : "No") << endl;
  }
  return 0;
}