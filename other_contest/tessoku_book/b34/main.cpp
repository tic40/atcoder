#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  int n,x,y; cin >> n >> x >> y;
  vector<ll> a(n);
  REP(i,n) cin >> a[i];

  vector<int> grundy(5);
  REP(i,5) {
    vector<bool> mex(3);
    if (i-x >= 0) mex[grundy[i-x]] = true;
    if (i-y >= 0) mex[grundy[i-y]] = true;

    for(int j = 0; j < 3; j++) {
      if (!mex[j]) break;
      grundy[i]++;
    }
  }

  int xsum = 0;
  REP(i,n) xsum ^= grundy[a[i]%5];
  cout << (xsum > 0 ? "First" : "Second") << endl;
  return 0;
}