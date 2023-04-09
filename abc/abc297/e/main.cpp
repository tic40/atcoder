#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  int n,k; cin >> n >> k;
  vector<ll> a(n);
  REP(i,n) cin >> a[i];

  set<ll> st;
  priority_queue<ll, vector<ll>, greater<ll>> q;
  REP(i,n) q.push(a[i]);

  while(q.size() && (int)st.size() <= k) {
    ll v = q.top(); q.pop();
    if (st.count(v)) continue;
    st.insert(v);
    REP(i,n) q.push(v+a[i]);
  }

  auto it = st.begin();
  advance(it, k-1);
  cout << *it << endl;
  return 0;
}