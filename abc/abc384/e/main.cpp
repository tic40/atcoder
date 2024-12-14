#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
using P = pair<int,int>;

const vector<int> di = {-1,0,1,0};
const vector<int> dj = {0,1,0,-1};

int main() {
  int h,w; ll x; cin >> h >> w >> x;
  int p,q; cin >> p >> q; p--; q--;
  vector s(h,vector<ll>(w));
  REP(i,h) REP(j,w) cin >> s[i][j];

  priority_queue<pair<ll,P>, vector<pair<ll,P>>, greater<pair<ll,P>>> pq;
  vector visited(h,vector<int>(w));
  ll power = 0;

  auto add = [&](int i, int j) {
    visited[i][j] = 1;
    power += s[i][j];
    REP(k,4) {
      int ni = i+di[k], nj = j+dj[k];
      if (ni < 0 || nj < 0 || ni >= h || nj >= w) continue;
      if (visited[ni][nj]) continue;
      pq.emplace(s[ni][nj],P{ni,nj});
    }
  };

  add(p,q);
  while(pq.size()) {
    auto [_, pa] = pq.top(); pq.pop();
    auto [i,j] = pa;
    if (visited[i][j]) continue;
    if ((double)s[i][j] >= (double)power/x) break;
    add(i,j);
  }
  cout << power << endl;
  return 0;
}