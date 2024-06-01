#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,m; cin >> n >> m;
  vector<int> a(m);
  REP(i,m) cin >> a[i];
  vector<int> b(m);
  REP(i,n) REP(j,m) {
    int x; cin >> x;
    b[j] += x;
  }

  bool ok = true;
  REP(i,m) if (a[i] > b[i]) ok = false;
  cout << (ok ? "Yes" : "No") << endl;
  return 0;
}