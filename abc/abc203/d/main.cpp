#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
const int INF = 1e9;

int n,k;
int a[810][810], s[810][810];

int binary_search() {
  int num = k*k/2+1; // 何番目に高い中央値か
  auto check = [&](int mid) {
    // 二次元累積和
    REP(i,n) REP(j,n) {
      s[i+1][j+1] = a[i][j] > mid ? 1 : 0;
      s[i+1][j+1] += s[i+1][j];
      s[i+1][j+1] += s[i][j+1];
      s[i+1][j+1] -= s[i][j];
    }
    // 取りうる池の配置をすべて試す
    REP(i,n-k+1) REP(j,n-k+1) {
      int now = s[i+k][j+k];
      now -= s[i+k][j];
      now -= s[i][j+k];
      now += s[i][j];
      // mid以下の中央値を取れるマスの選び方が一つでもあればtrueを返す
      if (now < num) return true;
    }
    return false;
  };

  // ok: ok値より小さい中央値の解が存在する
  int ok = INF; // 解が存在する値
  int ng = -1; // 解が存在しない値
  while(abs(ok-ng) > 1) {
    int mid = (ok+ng)/2;
    check(mid) ? ok = mid : ng = mid;
  }

  return ok;
}

int main() {
  cin >> n >> k;
  REP(i,n) REP(j,n) cin >> a[i][j];

  cout << binary_search() << endl;
  return 0;
}