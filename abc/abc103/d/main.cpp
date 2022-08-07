#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'
using P = pair<int,int>;

int main() {
  int n,m; cin >> n >> m;
  vector<P> p(m);
  REP(i,m) {
    int a,b; cin >> a >> b;
    a--; b--;
    p[i] = {b,a};
  }
  sort(p.begin(),p.end());

  int ans = 0, last = -1;
  REP(i,m) {
    if (p[i].second < last) continue;
    last = p[i].first;
    ans++;
  }
  cout << ans << endl;
  return 0;
}