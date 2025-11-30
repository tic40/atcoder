#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int x,n; cin >> x >> n;
  vector<int> w(n);
  REP(i,n) cin >> w[i];
  int q; cin >> q;
  REP(_,q) {
    int p; cin >> p; p--;
    x += w[p];
    w[p] = -w[p];
    cout << x << endl;
  }
  return 0;
}