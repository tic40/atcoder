#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)

int memo[1000][1000][4]; // 0: 左, 1: 上, 2: 斜め左上 3: 斜め右上 6マス８以内に何個の黒を含んでいるかを累積和する
int main() {
  int n; cin >> n;
  vector<string> s(n);
  REP(i,n) cin >> s[i];

  REP(i,n) REP(j,n) {
    REP(k,4) memo[i][j][k] = s[i][j] == '#';

    // 左
    if (j-1 >= 0) {
      memo[i][j][0] += memo[i][j-1][0];
      if (j-6 >= 0 && s[i][j-6] == '#') memo[i][j][0]--;
    }

    // 上
    if (i-1 >= 0) {
      memo[i][j][1] += memo[i-1][j][1];
      if (i-6 >= 0 && s[i-6][j] == '#') memo[i][j][1]--;
    }

    // 左上
    if (i-1 >= 0 && j-1 >= 0) {
      memo[i][j][2] += memo[i-1][j-1][2];
      if (i-6 >= 0 && j-6 >= 0 && s[i-6][j-6] == '#') memo[i][j][2]--;
    }

    // 右上
    if (i-1 >= 0 && j+1 < n) {
      memo[i][j][3] += memo[i-1][j+1][3];
      if (i-6 >= 0 && j+6 < n && s[i-6][j+6] == '#') memo[i][j][3]--;
    }
  }


  REP(i,n) REP(j,n) {
    bool ok = false;
    if (5 <= j && memo[i][j][0] >= 4) ok = true;
    if (5 <= i && memo[i][j][1] >= 4) ok = true;
    if (5 <= i && 5 <= j && memo[i][j][2] >= 4) ok = true;
    if (5 <= i && 5 <= n-1-j && memo[i][j][3] >= 4) ok = true;
    if (ok) {
      cout << "Yes" << endl;
      return 0;
    }
  }

  cout << "No" << endl;
  return 0;
}