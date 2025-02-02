#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
const int INF = numeric_limits<int>::max();

int main() {
  int n,w; cin >> n >> w;
  vector<int> x(n),y(n);
  REP(i,n) { cin >> x[i] >> y[i]; x[i]--; }
  vector<int> idx(n);
  REP(i,n) idx[i] = i;
  sort(idx.begin(),idx.end(),[&](int i, int j){ return y[i] < y[j]; });

  vector<int> r(n),num(w);
  for(int i: idx) {
    r[i] = num[x[i]];
    num[x[i]]++;
  }
  vector<int> d(n,INF);
  {
    vector blocks(n,vector<int>());
    REP(i,n) blocks[r[i]].push_back(i);
    REP(i,n) {
      if ((int)blocks[i].size() != w) continue;
      int mx = 0;
      for(int j: blocks[i]) mx = max(mx,y[j]-1);
      d[i] = mx+1;
    }
  }
  int q; cin >> q;
  REP(i,q) {
    int t,a; cin >> t >> a; a--;
    cout << (d[r[a]] > t ? "Yes" : "No") << endl;
  }
  return 0;
}