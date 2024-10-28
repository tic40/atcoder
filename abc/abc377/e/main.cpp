#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int powmod(ll x, ll k, int mod) {
  if (k == 0) return 1 % mod;
  ll res = powmod(x,k/2,mod);
  res = (res*res) % mod;
  if (k%2 == 1) res = (res*x)%mod;
  return res;
}

int main() {
  int n; ll k; cin >> n >> k;
  vector<int> p(n);
  REP(i,n) { cin >> p[i]; p[i]--; }

  vector<int> ans(n);
  vector<bool> used(n);
  REP(i,n) if (!used[i]) {
    int v = i;
    vector<int> vs;
    while(!used[v]) {
      used[v] = true;
      vs.push_back(v);
      v = p[v];
    }
    int c = vs.size();
    int m = powmod(2,k,c);
    REP(i,c) ans[vs[i]] = vs[(i+m)%c];
  }
  for(auto v: ans) cout << v+1 << " ";
  return 0;
}