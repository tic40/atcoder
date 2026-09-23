#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using P = pair<int,int>;

int main() {
  int n,m; cin >> n >> m;
  set<P> st;
  int ans = 0;
  REP(i,m) {
    int r,c; cin >> r >> c; r--; c--;
    bool ng =
      st.count({r,c}) ||
      st.count({r+1,c}) ||
      st.count({r,c+1}) ||
      st.count({r+1,c+1});

    if (!ng) {
      st.emplace(r,c);
      st.emplace(r+1,c);
      st.emplace(r,c+1);
      st.emplace(r+1,c+1);
      ans++;
    }
  }

  cout << ans << endl;
  return 0;
}
