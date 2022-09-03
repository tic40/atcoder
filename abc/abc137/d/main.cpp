#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'

int main() {
  int n,m; cin >> n >> m;
  vector<vector<int>> g(m+1);
  REP(i,n) {
    int a,b; cin >> a >> b;
    if (a <= m) g[a].push_back(b);
  }

  int ans = 0;
  priority_queue<int> que;
  // 後ろから見ていく
  for (int i = m-1; 0 <= i; i--) {
    // 残り日数で報酬をもらえるバイトをpriority_queに入れる
    for(int v: g[m-i]) que.push(v);

    if (que.size()) continue;
    // queから最大の報酬のバイトを選ぶ
    ans += que.top();
    que.pop();
  }

  cout << ans << endl;
  return 0;
}