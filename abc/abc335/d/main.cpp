#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

const vector<int> di = {-1,0,1,0};
const vector<int> dj = {0,1,0,-1};

int main() {
  int n; cin >> n;
  vector ans(n,vector<int> (n,-1));

  auto dfs = [&](auto self, int i, int j, int d, int cnt) -> void {
    if (i == n/2 && j == n/2) return;

    ans[i][j] = cnt;
    int ni = i+di[d], nj = j+dj[d];
    bool ok = (ni >= 0 && nj >= 0 && ni < n && nj < n) && (ans[ni][nj] == -1);
    if (ok) {
      self(self,ni,nj,d,cnt+1);
    } else {
      self(self,i,j,(d+1)%4,cnt); // 90 度方向転換
    }
  };
  dfs(dfs,0,0,1,1);

  REP(i,n) {
    REP(j,n) {
      if (ans[i][j] == -1) cout << "T" << " ";
      else cout << ans[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}