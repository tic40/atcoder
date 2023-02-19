#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,k; cin >> n >> k;
  vector<int> a(n);
  REP(i,n) cin >> a[i];
  sort(a.begin(),a.end());

  int mex = 0, cnt = 0;
  REP(i,n) {
    if (mex < a[i]) break;
    if (k <= cnt) break;
    if (mex == a[i]) { mex++; cnt++; }
  }
  cout << mex << endl;
  return 0;
}