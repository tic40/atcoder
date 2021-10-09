#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define ALL(x) x.begin(), x.end()

int n,l,r;
int ans = 0;
void dfs(int cur, int cnt) {
  if (r < cur) return;
  if (cnt == n) {
    ans++;
    return;
  }

  for(int i = cur+1; i <= r; i++) dfs(i,cnt+1);
  return;
}

int main() {
  cin >> n >> l >> r;

  for(int i = l; i <= r; i++) dfs(i,1);
  cout << ans << endl;
  return 0;
}