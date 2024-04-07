#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using P = pair<int,int>;

int main() {
  int n; cin >> n;
  vector<int> x(n),y(n);
  REP(i,n) cin >> x[i] >> y[i];

  REP(i,n) {
    P mx = {-1,-1};
    REP(j,n) {
      int dx = x[i]-x[j], dy = y[i]-y[j];
      int now = dx*dx+dy*dy;
      if (now > mx.first) mx = {now,j};
    }
    cout << mx.second+1 << endl;
  }
  return 0;
}