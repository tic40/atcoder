#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)

int n,m;
vector<int> x,y;
void solve() {
  vector<int> red(n);
  vector<int> tot(n,1);
  red[0] = 1;

  REP(i,m) {
    tot[x[i]]--;
    tot[y[i]]++;
    if (red[x[i]]) {
      red[y[i]] = 1;
    }
    if (tot[x[i]] == 0) {
      red[x[i]] = 0;
    }
  }

  int ans = 0;
  REP(i,n) ans += red[i];
  cout << ans << endl;
  return;
}

int main() {
  cin >> n >> m;
  x.resize(m);
  y.resize(m);
  REP(i,m) {
    cin >> x[i] >> y[i];
    x[i]--, y[i]--;
  }

  solve();
  return 0;
}