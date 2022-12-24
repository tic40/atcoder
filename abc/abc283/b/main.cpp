#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n; cin >> n;
  vector<int> a(n);
  REP(i,n) cin >> a[i];

  int q; cin >> q;
  REP(_,q) {
    int t,k; cin >> t >> k;
    k--;
    if (t == 1) {
      int x; cin >> x;
      a[k] = x;
    } else {
      cout << a[k] << endl;
    }
  }
  return 0;
}