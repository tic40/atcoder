#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
using T = pair<ll,pair<int,int>>;
const vector<int> di = {-1,0,1,0};
const vector<int> dj = {0,1,0,-1};

int main() {
  int h,w,x; cin >> h >> w >> x;
  int p,q; cin >> p >> q; p--; q--;
  vector s(h,vector<ll>(w));
  REP(i,h) REP(j,w) cin >> s[i][j];

  priority_queue<T, vector<T>, greater<T>> pq;
  vector visited(h,vector<int>(w));

  ll power = 0;
  auto push = [&](int i, int j) -> void {
    visited[i][j] = 1;
    power += s[i][j];
    REP(k,4) {
      int ni = i+di[k], nj = j+dj[k];
      if (ni < 0 || nj < 0 || ni >= h || nj >= w) continue;
      if (visited[ni][nj]) continue;
      pq.emplace(s[ni][nj], P{ni,nj});
    }
  };
  push(p,q);

  while(pq.size()) {
    auto [_, pos] = pq.top(); pq.pop();
    auto [i,j] = pos;
    if (visited[i][j]) continue;
    if ((double)s[i][j] >= (double)power/x) continue;
    push(i,j);
  }
  cout << power << endl;
  return 0;
}