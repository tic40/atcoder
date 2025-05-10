#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using P = pair<int,int>;
const vector<int> di = {0,1,0,-1};
const vector<int> dj = {1,0,-1,0};
const string arrow = "<^>v";

int main() {
  int h,w; cin >> h >> w;
  vector<string> s(h);
  REP(i,h) cin >> s[i];
  queue<P> q;
  REP(i,h) REP(j,w) if (s[i][j] == 'E') q.emplace(i,j);

  while(q.size()) {
    auto [i,j] = q.front(); q.pop();
    REP(k,4) {
      int ni = i+di[k];
      int nj = j+dj[k];
      if (ni < 0 || nj < 0 || ni >= h || nj >= w) continue;
      if (s[ni][nj] != '.') continue;
      s[ni][nj] = arrow[k];
      q.emplace(ni,nj);
    }
  }

  REP(i,h) cout << s[i] << endl;
  return 0;
}