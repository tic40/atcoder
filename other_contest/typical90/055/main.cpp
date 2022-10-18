#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'
using ll = long long;

int n; ll p,q;
vector<int> a(100);

int dfs(int i, ll now, int cnt) {
  if (cnt == 5) return now % p == q ? 1 : 0;
  if (i == n) return 0;

  int res = 0;
  res += dfs(i+1, now, cnt);
  res += dfs(i+1, (now*a[i])%p, cnt+1);
  return res;
}

int main() {
  cin >> n >> p >> q;
  REP(i,n) cin >> a[i];
  cout << dfs(0,1,0) << endl;
  return 0;
}