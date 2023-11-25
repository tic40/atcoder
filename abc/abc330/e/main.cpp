#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,q; cin >> n >> q;
  vector<int> a(n);
  REP(i,n) cin >> a[i];

  vector<int> bk(n+1);
  REP(i,n) if (a[i] <= n) bk[a[i]]++;
  set<int> st;
  REP(i,n) if (bk[i] == 0) st.insert(i);

  REP(_,q) {
    int i,x; cin >> i >> x;
    i--;
    if (a[i] <= n) {
      bk[a[i]]--;
      if (bk[a[i]] == 0) st.insert(a[i]);
    }
    a[i] = x;
    if (a[i] <= n) {
      bk[a[i]]++;
      if (bk[a[i]] == 1) st.erase(a[i]);
    }
    cout << *st.begin() << endl;
  }
  return 0;
}