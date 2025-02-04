#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
const int INF = numeric_limits<int>::max();

int main() {
  int n,w; cin >> n >> w;
  vector<int> x(n),y(n);
  REP(i,n) { cin >> x[i] >> y[i]; x[i]--; y[i]--; }
  vector<int> idx(n);
  REP(i,n) idx[i] = i;
  // y の昇順に並び替え
  sort(idx.begin(),idx.end(),[&](int i, int j){ return y[i] < y[j]; });

  // r[i] := i 番目のブロックがその列で下から何個目か
  vector<int> r(n),num(w);
  for(int i: idx) {
    r[i] = num[x[i]];
    num[x[i]]++;
  }

  // d[i] := 下から i 番目のブロックが消える時刻
  vector<int> d(n,INF);
  // blocks[i][j] := 下から i 番目の列にあるブロックの集合
  vector blocks(n,vector<int>());
  REP(i,n) blocks[r[i]].push_back(i);
  REP(i,n) if ((int)blocks[i].size() == w) { // 一列揃う場合だけ
    d[i] = 0;
    for(int j: blocks[i]) d[i] = max(d[i],y[j]);
  }

  int q; cin >> q;
  REP(i,q) {
    int t,a; cin >> t >> a; a--;
    cout << (d[r[a]] >= t ? "Yes" : "No") << endl;
  }
  return 0;
}