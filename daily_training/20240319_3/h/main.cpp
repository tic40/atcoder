#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  int n,k; cin >> n >> k;
  vector<int> a(n);
  REP(i,n) cin >> a[i];
  set<ll> st = {0};

  REP(i,k) {
    ll x = *st.begin();
    st.erase(x);
    REP(i,n) st.insert(x+a[i]);
  }
  ll ans = *st.begin();
  cout << ans << endl;
  return 0;
}