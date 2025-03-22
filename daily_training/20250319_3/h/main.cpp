#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using mint = modint998244353;
const vector<int> di = {-1,0,1,0};
const vector<int> dj = {0,1,0,-1};

int main() {
  int h,w; cin >> h >> w;
  int n = h*w;
  vector<string> s(h);
  REP(i,h) cin >> s[i];
  auto hash = [&](int i, int j) { return i*w+j; };

  dsu d(n);
  int redcnt = 0;
  REP(i,h) REP(j,w) {
    if (s[i][j] == '.') { redcnt++; continue; }
    if (j < w-1 && s[i][j+1] == '#') d.merge(hash(i,j),hash(i,j+1));
    if (i < h-1 && s[i+1][j] == '#') d.merge(hash(i,j),hash(i+1,j));
  }

  unordered_set<int> st;
  REP(i,h) REP(j,w) if (s[i][j] == '#') st.insert(d.leader(hash(i,j)));
  int cnt = st.size();

  mint tot = 0;
  REP(i,h) REP(j,w) if (s[i][j] == '.') {
    unordered_set<int> st2;
    REP(k,4) {
      int ni = i+di[k], nj = j+dj[k];
      if (ni < 0 || nj < 0 || ni >= h || nj >= w) continue;
      if (s[ni][nj] != '#') continue;
      st2.insert(d.leader(hash(ni,nj)));
    }
    if (st2.empty()) tot += cnt+1;
    else tot += cnt - (st2.size() - 1);
  }

  cout << (tot/redcnt).val() << endl;
  return 0;
}
