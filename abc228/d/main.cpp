#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define ALL(x) x.begin(), x.end()
using ll = long long;
const int INF = 1e9;

int q;
ll n = 1048576; // 2^20 = 1048576
vector<ll> a(n,-1);

int main() {
  cin >> q;

  set<int> st;
  REP(i,n+1) st.insert(i);

  REP(i,q) {
    int t;
    ll x;
    cin >> t >> x;
    if (t == 1) {
      ll h = x % n;
      auto it = st.lower_bound(h);
      if (*it < n) {
        a[*it] = x;
        st.erase(*it);
      } else {
        h = 0;
        auto it = st.lower_bound(h);
        a[*it] = x;
        st.erase(*it);
      }
    } else {
      cout << a[x%n] << endl;
    }
  }

  return 0;
}