#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)

int n,m;
vector<string> a;

int check(char a, char b) {
  // 0: draw, 1: win, -1: lose

  if (a == b) return 0;
  if (a == 'G' && b == 'C') return 1;
  if (a == 'C' && b == 'P') return 1;
  if (a == 'P' && b == 'G') return 1;
  return -1;
}

void solve() {
  int n2 = 2*n;
  vector<pair<int,int>> rank(n2); // 勝数, 人番号
  REP(i,n2) rank[i] = {0,-i};

  REP(i,m) {
    for (int j = 0; j < n2; j+=2) {
      auto x = rank[j];
      auto y = rank[j+1];

      int r = check( a[-x.second][i], a[-y.second][i] );
      if (r == 1) rank[j].first++;
      if (r == -1) rank[j+1].first++;
    }
    sort(rank.rbegin(), rank.rend());
  }

  REP(i,n2) cout << -(rank[i].second-1) << endl;
  return;
}

int main() {
  cin >> n >> m;
  a.resize(2*n);
  REP(i,2*n) cin >> a[i];

  solve();
  return 0;
}