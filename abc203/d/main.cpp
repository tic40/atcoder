#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
const int INF = 1e9;

int n,k;
int a[805][805], s[805][805];

int binary_search(int key) {
  auto check = [&](int mid) {
    REP(i,n) REP(j,n) s[i+1][j+1] = a[i][j] > mid ? 1 : 0;
    REP(i,n+1) REP(j,n) s[i][j+1] += s[i][j];
    REP(i,n) REP(j,n+1) s[i+1][j] += s[i][j];

    REP(i,n-k+1) REP(j,n-k+1) {
      int now = s[i+k][j+k];
      now -= s[i][j+k];
      now -= s[i+k][j];
      now += s[i][j];

      if (now < key) return true;
    }
    return false;
  };

  int ok = INF;
  int ng = -1;
  while(abs(ok-ng) > 1) {
    int mid = (ok+ng)/2;
    check(mid) ? ok = mid : ng = mid;
  }

  return ok;
}

int main() {
  cin >> n >> k;
  REP(i,n) REP(j,n) cin >> a[i][j];

  int med = k * k / 2 + 1;
  cout << binary_search(med) << endl;
  return 0;
}