#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,m; cin >> n >> m;
  vector g(m,vector<int>());
  REP(i,n) {
    int a,b; cin >> a >> b;
    a--;
    g[a].push_back(b);
  }
  REP(i,m) {
    int s = accumulate(g[i].begin(),g[i].end(),0);
    double ave = s / (double)(g[i].size());
    printf("%.10f\n", ave);    
  }
  return 0;
}