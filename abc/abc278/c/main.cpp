#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'
using P = pair<int,int>;

int main() {
  int n,q; cin >> n >> q;
  set<P> st;

  REP(i,q) {
    int t,a,b;
    cin >> t >> a >> b;
    if (t == 1) st.emplace(a,b);
    if (t == 2) st.erase({a,b});
    if (t == 3) {
      bool ok = st.count({a,b}) && st.count({b,a});
      cout << (ok ? "Yes" : "No") << endl;
    }
  }
  return 0;
}