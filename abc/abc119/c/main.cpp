#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'

int n,a,b,c;
vector<int> l(8);
int ans = 1e9;

void dfs(int t, int ta, int tb, int tc, int mp) {
  if (t == n) {
    if (ta == 0 || tb == 0 || tc == 0) return;
    mp += abs(ta - a) + abs(tb - b) + abs(tc - c);
    ans = min(ans,mp);
    return;
  }

  dfs(t+1, ta, tb, tc, mp);
  dfs(t+1, ta+l[t], tb, tc, ta == 0 ? mp : mp+10);
  dfs(t+1, ta, tb+l[t], tc, tb == 0 ? mp : mp+10);
  dfs(t+1, ta, tb, tc+l[t], tc == 0 ? mp : mp+10);
  return;
}

int main() {
  cin >> n >> a >> b >> c;
  REP(i,n) cin >> l[i];
  dfs(0,0,0,0,0);
  cout << ans << endl;
  return 0;
}