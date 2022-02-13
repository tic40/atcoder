#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)

// grundy[白色の数][青色の数] = grundy数
// 青色の最大数は: (1+50)*50/2+50
int grundy[55][1500];

void init() {
  REP(i,51) REP(j,1500) {
    // mex: 最小除外数(Minimum excludant) を求めるための集合
    vector<int> mex(1505);

    // 操作1 [1 <= w のとき選択可能]　選んだ山に青石を w 個加え、白石を 1 個取り除く
    if (1 <= i) mex[ grundy[i-1][j+i] ] = 1;
    // 操作2 [2 <= b のとき選択可能]　1 以上 b/2以下の整数 k を選び、選んだ山から青石を k 個取り除く
    if (2 <= j) {
      for (int k = 1; k <= (j/2); k++) mex[ grundy[i][j-k] ] = 1;
    }

    // mex を grundy[i][j] に加える
    REP(k, 1500) {
      if (mex[k] == 0) {
        grundy[i][j] = k;
        break;
      }
    }
  }
}

int main() {
  int n; cin >> n;
  vector<int> w(n),b(n);
  REP(i,n) cin >> w[i];
  REP(i,n) cin >> b[i];

  init();

  int sum_xor = 0;
  REP(i,n) sum_xor ^=  grundy[w[i]][b[i]];

  cout << (sum_xor != 0 ? "First" : "Second") << endl;
  return 0;
}