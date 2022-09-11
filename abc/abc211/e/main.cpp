#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'
using P = pair<int,int>;

const vector<P> moves = {{1,0}, {-1,0}, {0,1}, {0,-1}};
int n,k,ans = 0;

void dfs(vector<string> s, int cnt) {
  if (cnt == k) { ans++; return; }

  REP(i,n) REP(j,n) {
    if (s[i][j] != '.') continue;

    bool ok = false;
    if (cnt > 0) {
      for(auto [x,y]: moves) {
        int ni = i+x, nj = j+y;
        if (ni < 0 || n <= ni || nj < 0 || n <= nj) continue;
        if (s[ni][nj] == '@') ok = true;
      }
    } else {
      ok = true;
    }

    if (!ok) continue;
    s[i][j] = '@'; // 今の場所を赤マスに
    dfs(s,cnt+1);
    s[i][j] = '#'; // 見終わったので今の場所を黒マスに
    dfs(s,cnt);
    return;
  }
  return;
}

int main() {
  cin >> n >> k;
  vector<string> s(8);
  REP(i,n) cin >> s[i];

  dfs(s,0);

  cout << ans << endl;
  return 0;
}