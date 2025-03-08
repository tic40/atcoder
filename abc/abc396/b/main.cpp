#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int q; cin >> q;
  vector<int> d;
  REP(i,100) d.push_back(0);
  REP(i,q) {
    int t; cin >> t;
    if (t == 1) {
      int x; cin >> x;
      d.push_back(x);
    }
    if (t == 2) {
      cout << d.back() << endl;
      d.pop_back();
    }
  }
  return 0;
}
