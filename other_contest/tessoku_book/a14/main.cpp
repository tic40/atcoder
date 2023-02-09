#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  int n,k; cin >> n >> k;
  vector<int> a(n), b(n), c(n), d(n);
  REP(i,n) cin >> a[i];
  REP(i,n) cin >> b[i];
  REP(i,n) cin >> c[i];
  REP(i,n) cin >> d[i];

  vector<int> p;
  REP(i,n) REP(j,n) p.push_back(a[i]+b[j]);
  unordered_set<int> st;
  REP(i,n) REP(j,n) st.insert(c[i]+d[j]);

  for(auto v: p) {
    if (st.count(k-v)) { cout << "Yes" << endl; return 0; }
  }
  cout << "No" << endl;
  return 0;
}