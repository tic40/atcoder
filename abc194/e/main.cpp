#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)
using ll = long long;
const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9+7;

int main() {
  int n,m;
  cin >> n >> m;
  vector<vector<int>> p(n);
  REP(i,n) {
    int a; cin >> a;
    p[a].push_back(i); // 数値aが出現する位置リストを持っておく
  }

  // 0から順番に試していく。見つかったらそれが答え
  REP(i,n) {
    int pre = -1; // 前に出現した位置
    p[i].push_back(n); // 最後に入れておく. 出現しなかった場合はこれが答え
    for(int j: p[i]) {
      // j: iの出現位置. j-pre が m より大きければそれが答え
      if (j - pre > m) {
        cout << i << endl;
        return 0;
      }
      pre = j;
    }
  }

  cout << n << endl;
  return 0;
}