#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)

int n,k;
int ans;
const int di[] = {-1,0,1,0};
const int dj[] = {0,-1,0,1};

void dfs(vector<string> s) {
  int cnt = 0; // 赤マス数

  // 赤マス数をカウント
  REP(i,n) REP(j,n) if (s[i][j] == '@') ++cnt;

  // 赤マスがk個の場合は終了
  if (cnt == k) {
    ++ans;
    return;
  }

  REP(i,n) REP(j,n) {
    // 白マスじゃなかったらスキップ
    if (s[i][j] != '.') continue;

    if (cnt > 0) {
      bool ok = false; // 上下左右で赤マスが連絡しているかどうか
      REP(v,4) {
        int ni = i+di[v];
        int nj = j+dj[v];
        if (ni < 0 || nj < 0 || ni >= n || nj >= n) continue;
        if (s[ni][nj] == '@') ok = true;
      }
      if (!ok) continue; // 赤マスが連結してないとき
    }

    s[i][j] = '@'; // 今見ている場所を赤マスに塗る
    dfs(s);
    s[i][j] = '#'; // 調べ終わったので黒マスに塗る
    dfs(s); // 再帰的に調べる
    return;
  }
  return;
}

int main() {
  cin >> n >> k;
  vector<string> s(n);
  REP(i,n) cin >> s[i];

  dfs(s);
  cout << ans << endl;
  return 0;
}