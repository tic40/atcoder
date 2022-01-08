#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)
using ll = long long;

int main() {
  int n,q; cin >> n >> q;

  vector<int> rows(n),columns(n);
  REP(i,n) rows[i] = i;
  REP(i,n) columns[i] = i;

  bool trans = false;
  REP(_, q) {
    int t,a,b;
    cin >> t;

    if (trans) {
      if (t == 1) t = 2;
      else if (t == 2) t = 1;
    }

    if (t != 3) {
      cin >> a >> b;
      a--; b--;
    }

    if (t == 1) {
      swap(rows[a], rows[b]);
    } else if (t == 2) {
      swap(columns[a], columns[b]);
    } else if (t == 3) {
      trans = !trans;
    } else {
      if (trans) swap(a,b);

      int i = rows[a];
      int j = columns[b];

      ll ans = 1LL * n * i + j;
      cout << ans << endl;
    }
  }
  return 0;
}