#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,x,y; cin >> n >> x >> y;
  vector<int> a(n);
  REP(i,n) cin >> a[i];

  vector<int> grundy(1e5+1);
  REP(i,1e5+1) {
    vector<bool> mex(3);
    if (i-x >= 0) mex[grundy[i-x]] = true;
    if (i-y >= 0) mex[grundy[i-y]] = true;

    for(int j = 0; j < 3; j++) {
      if (!mex[j]) break;
      grundy[i]++;
    }
  }

  int xsum = 0;
  REP(i,n) xsum ^= grundy[a[i]];
  cout << (xsum > 0 ? "First" : "Second") << endl;
  return 0;
}