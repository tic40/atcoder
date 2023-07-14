#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,m; cin >> n >> m;
  vector<int> a(m),b(m);
  REP(i,m) {
    cin >> a[i] >> b[i];
    a[i]--; b[i]--;
  }

  vector<int> c(n);
  REP(i,n) cin >> c[i];

  dsu uf(n);
  REP(i,m) if (c[a[i]] != c[b[i]]) uf.merge(a[i],b[i]);
  REP(i,m) {
    if (c[a[i]] == c[b[i]] && uf.same(a[i],b[i])) {
      cout << "Yes" << endl; return 0;
    }
  }
  cout << "No" << endl;
  return 0;
}