#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

int h,w,a,b;

void solve() {
  REP(i,h) {
    REP(j,w) {
      if (i < b && j < a) cout << 0;
      else if(i >= b && j >= a) cout << 0;
      else cout << 1;
    }
    cout << endl;
  }

  return;
}

int main() {
  cin >> h >> w >> a >> b;

  solve();
  return 0;
}