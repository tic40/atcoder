#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  int n,q; cin >> n >> q;
  vector<ll> a(n);
  unordered_set<int> st;
  ll s = 0;
  REP(i,q) {
    int x; cin >> x;
    x--;
    if (st.count(x)) {
      a[x] += s;
      st.erase(x);
    } else {
      a[x] -= s;
      st.insert(x);
    }
    s += st.size();
  }

  for(auto v: st) a[v] += s;
  REP(i,n) cout << a[i] << " ";
  return 0;

}