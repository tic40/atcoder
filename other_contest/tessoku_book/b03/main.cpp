#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int n;
vector<int> a(100);
bool dfs(int i, int cnt, int now) {
  if (cnt == 3 && now == 1000) return true;
  if (i >= n || cnt > 3) return false;
  return dfs(i+1,cnt,now) || dfs(i+1,cnt+1,now+a[i]);
}

int main() {
  cin >> n;
  REP(i,n) cin >> a[i];
  cout << (dfs(0,0,0) ? "Yes" : "No") << endl;
  return 0;
}