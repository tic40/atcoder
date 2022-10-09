#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'

int main() {
  int n,m; cin >> n >> m;
  // t[i][j] := 人iが舞踏会jに参加していればtrue
  vector t(n,vector<bool>(m));
  REP(i,m) {
    int k; cin >> k;
    REP(j,k) {
      int a; cin >> a; a--;
      t[a][i] = true;
    }
  }

  REP(i,n) for(int j = i+1; j < n; j++) {
    bool ok = false; // 人iが全ての人と一度は舞踏会に参加したかどうか
    REP(k,m) ok |= t[i][k] && t[j][k];
    if (!ok) { cout << "No" << endl; return 0; }
  }

  cout << "Yes" << endl;
  return 0;
}