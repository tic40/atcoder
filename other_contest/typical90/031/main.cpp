#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'

int main() {
  int n; cin >> n;
  vector<int> w(n),b(n);
  REP(i,n) cin >> w[i];
  REP(i,n) cin >> b[i];

  // grundy[白色の数][青色の数] = grundy数
  // 青色の最大数は: (1+50)*50/2+50
  vector grundy(51, vector<int>(1400));

  // grundy[0][0]の状態から見ていく
  REP(i,51) REP(j,1400) {
    vector<bool> mex(1400);

    // mex: 最小除外数を求めるための集合
    // mex[i] = trueのとき、iは集合に含まれる.
    // mex[i] = false になる最小の i が最小除外数となる
    if (i >= 1) mex[grundy[i-1][j+i]] = true;

    // 操作2 [2 <= b のとき選択可能]
    // 1 以上 b/2以下の整数 k を選び、選んだ山から青石を k 個取り除く
    if (j >= 2) {
      for(int k = 1; k <= j/2; k++) mex[grundy[i][j-k]] = true;
    }
    REP(k,1400) {
      if (!mex[k]) { grundy[i][j] = k; break; }
    }
  }

  int ans = 0;
  REP(i,n) ans ^= grundy[w[i]][b[i]];
  cout << (ans == 0 ? "Second" : "First") << endl;

  return 0;
}