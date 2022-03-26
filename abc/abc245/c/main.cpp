#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)

int main() {
  int n,k; cin >> n >> k;
  vector<int> a(n),b(n);
  REP(i,n) cin >> a[i];
  REP(i,n) cin >> b[i];

  set<int> st = { a[0], b[0] };
  REP(i,n-1) {
    set<int> nst;
    for(auto v: st) {
      if ( abs(v-a[i+1]) <= k ) nst.insert(a[i+1]);
      if ( abs(v-b[i+1]) <= k ) nst.insert(b[i+1]);
    }
    swap(st,nst);
  }

  cout << (st.size() ? "Yes" : "No") << endl;
  return 0;
}
