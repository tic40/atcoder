#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
using P = pair<int,int>;

int main() {
  int h,w; cin >> h >> w;
  vector a(h,vector<int>(w));
  REP(i,h) REP(j,w) cin >> a[i][j];

  vector<pair<P,P>> ans;
  auto f = [&](int i, int j, int ni, int nj) {
    a[i][j]--;
    a[ni][nj]++;
    ans.emplace_back(P{i+1,j+1}, P{ni+1,nj+1});
  };

  REP(i,h) REP(j,w) {
    if (a[i][j] % 2 == 0) continue;

    if (j < w-1) f(i,j,i,j+1);
    else if (i < h-1) f(i,j,i+1,j);
  }

  cout << ans.size() << endl;
  for(auto [v,nv]: ans) {
    cout << v.first << " " << v.second << " ";
    cout << nv.first << " " << nv.second << endl;
  }
  return 0;
}