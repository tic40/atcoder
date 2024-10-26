#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
const int INF = 1e9;

int op(int a, int b) { return min(a,b); }
int e() { return INF; }

int main() {
  int n,m; string s; cin >> n >> m >> s;

  segtree<int,op,e> seg(n+1);
  seg.set(0,0);
  for(int i = 1; i <= n; i++) if (s[i] == '0') {
    int now = seg.prod(max(0,i-m),i);
    if (now != INF) seg.set(i,now+1);
  }

  if (seg.get(n) == INF) { cout << -1 << endl; return 0; }

  vector<int> ans;
  int i = n;
  while(i) {
    for(int j = min(m,i); j >= 1; j--) {
      if (seg.get(i-j) == seg.get(i)-1) {
        ans.push_back(j);
        i -= j;
        break;
      }
    }
  }
  reverse(ans.begin(),ans.end());
  for(auto v: ans) cout << v << " ";
  return 0;
}