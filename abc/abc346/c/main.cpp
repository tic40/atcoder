#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  int n,k; cin >> n >> k;
  vector<int> a(n);
  REP(i,n) cin >> a[i];

  ll ans = (ll)(1+k)*k/2;
  unordered_set<int> st;
  REP(i,n) if (a[i] <= k) st.insert(a[i]);
  for(auto v: st) ans -= v;
  cout << ans << endl;
  return 0;
}