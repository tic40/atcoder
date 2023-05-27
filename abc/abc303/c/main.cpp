#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using P = pair<int,int>;

map<char,P> mp {
  {'R', {1,0}},
  {'L', {-1,0}},
  {'U', {0,1}},
  {'D', {0,-1}}
};

int main() {
  int n,m,h,k; cin >> n >> m >> h >> k;
  string s; cin >> s;

  set<P> st;
  REP(i,m) {
    int x,y; cin >> x >> y;
    st.emplace(x,y);
  }

  int nx = 0, ny = 0;
  bool ok = true;
  REP(i,n) {
    auto [dx,dy] = mp[s[i]];
    nx += dx, ny += dy;
    h--;
    if (h < 0) { ok = false; break; }
    if (st.count({nx,ny}) && (h < k)) {
      h = k;
      st.erase({nx,ny});
    }
  }

  cout << (ok ? "Yes" : "No") << endl;
  return 0;
}