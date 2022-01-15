#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)

int main() {
  int n; cin >> n;
  vector<int> h(n);
  REP(i,n) cin >> h[i];

  REP(i,n-1) {
    bool ok = h[i] < h[i+1];
    if (!ok) {
      cout << h[i] << endl;
      return 0;
    }
  }

  cout << h.back() << endl;
  return 0;
}