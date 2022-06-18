#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)

const int mx = 200005;
int main() {
  int n; cin >> n;
  vector<int> m(mx);
  REP(i,n) {
    int l,r; cin >> l >> r;
    m[l]++; m[r]--;
  }

  REP(i, mx) m[i+1] += m[i];

  for(int i = 1; i <= mx; i++) {
    if (m[i-1] == 0 && m[i] > 0) cout << i << " ";
    else if (m[i-1] > 0 && m[i] == 0) cout << i << endl;
  }

  return 0;
}