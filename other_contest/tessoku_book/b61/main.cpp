#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,m; cin >> n >> m;
  vector<int> deg(n);
  REP(i,m) {
    int a,b; cin >> a >> b;
    a--; b--;
    deg[a]++;
    deg[b]++;
  }
  int mx = *max_element(deg.begin(),deg.end());
  int ans = find(deg.begin(),deg.end(),mx) - deg.begin() + 1;
  cout << ans << endl;

  return 0;
}