#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
using P = pair<int,int>;

int main() {
  int n; cin >> n;
  vector<int> h(n);
  REP(i,n) cin >> h[i];

  ll ans = 0;
  stack<P> st;
  st.emplace(0,0);
  REP(i,n) {
    int len = 0;
    while(st.size()) {
      auto [k,v] = st.top();
      if (k >= h[i]) break;
      st.pop();
      ans -= (ll)k*v;
      len += v;
    }
    st.emplace(h[i],len+1);
    ans += (ll)len * h[i];
    ans += h[i];
    cout << ans+1 << " ";
  }
  return 0;
}