#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  auto solve = []() {
    int n; cin >> n;
    int n2 = 1<<n;
    vector<int> p(n2);
    REP(i,n2) cin >> p[i];

    for(int w = 1; w < n2; w *= 2) {
      for(int l = 0; l < n2; l += w*2) {
        if (p[l] > p[l+w]) {
          REP(i,w) swap(p[l+i],p[l+w+i]);
        }
      }
    }
    REP(i,n2) cout << p[i] << " ";
    cout << endl;
  };
  int t; cin >> t;
  REP(_,t) solve();
  return 0;
}