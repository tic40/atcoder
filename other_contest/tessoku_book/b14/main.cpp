#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  int n,k; cin >> n >> k;
  vector<int> a(n);
  REP(i,n) cin >> a[i];

  vector<ll> p;
  REP(bit,1<<n/2) {
    ll now = 0;
    REP(i,n/2) if (bit>>i & 1) now += a[i];
    p.push_back(now);
  }

  unordered_set<ll> st;
  REP(bit,1<<(n-n/2)) {
    ll now = 0;
    REP(i,(n-n/2)) if (bit>>i & 1) now += a[i+n/2];
    st.insert(now);
  }

  for(auto v: p) {
    if (st.count(k-v)) {
      cout << "Yes" << endl;
      return 0;
    }
  }

  cout << "No" << endl;
  return 0;
}