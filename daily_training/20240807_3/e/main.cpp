#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  const int n = 9;
  vector a(n,vector<int>(n));
  REP(i,n) REP(j,n) cin >> a[i][j];

  bool ok = true;
  vector<int> cnt(n+1);
  auto check = [&]() -> void {
    ok && n == accumulate(cnt.begin(),cnt.end(),0);
    cnt = vector<int>(n+1);
  };

  REP(i,n) {
    REP(j,n) cnt[a[i][j]] = 1;
    check();
  }
  REP(j,n) {
    REP(i,n) cnt[a[i][j]] = 1;
    check();
  }
  REP(i,n/3) REP(j,n/3) {
    REP(ni,n/3) REP(nj,n/3) cnt[a[i*3+ni][j*3+nj]] = 1;
    check();
  }

  cout << (ok ? "Yes" : "No") << endl;
  return 0;
}