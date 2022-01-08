#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

int n;
vector<int> a;

void solve() {
  vector<ll> s(n+1);
  map<ll, int> m;
  REP(i,n) s[i+1] = s[i] + a[i];
  REP(i,n+1) m[s[i]]++;

  ll sum = 0;
  REP(i,n+1) sum += max(0, m[s[i]]-1);

  ll ans = sum/2;
  cout << ans << endl;
  return;
}

int main() {
  cin >> n;
  a.resize(n);
  REP(i,n) cin >> a[i];

  solve();
  return 0;
}