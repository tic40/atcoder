#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,t,p; cin >> n >> t >> p;
  vector<int> l(n);
  REP(i,n) cin >> l[i];

  int now = 0;
  REP(i,101) {
    now = 0;
    REP(j,n) if (l[j] + i >= t) now++;
    if (now >= p) { cout << i << endl; return 0; }
  }
  return 0;
}