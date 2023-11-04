#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  vector a(9,vector<int>(9));
  REP(i,9) REP(j,9) cin >> a[i][j];
  bool ok = true;
  REP(i,9) {
    vector<int> num(10);
    REP(j,9) num[a[i][j]] = 1;
    if (accumulate(num.begin(),num.end(),0) != 9) ok = false;
  }
  REP(j,9) {
    vector<int> num(10);
    REP(i,9) num[a[i][j]] = 1;
    if (accumulate(num.begin(),num.end(),0) != 9) ok = false;
  }
  REP(i,3) REP(j,3) {
    int ni = i*3;
    int nj = j*3;
    vector<int> num(10);
    REP(k,3) REP(l,3) num[a[ni+k][nj+l]] = 1;
    if (accumulate(num.begin(),num.end(),0) != 9) ok = false;
  }
  cout << (ok ? "Yes" : "No") << endl;
  return 0;
}