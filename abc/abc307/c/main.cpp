#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using P = pair<int,int>;

int main() {
  vector b(3,vector<P>());
  REP(i,3) {
    int h,w; cin >> h >> w;
    REP(j,h) {
      string s; cin >> s;
      REP(k,w) if (s[k] == '#') b[i].emplace_back(j,k);
    }
  }

  set<P> ideal;
  for(auto [x,y]: b[2]) ideal.emplace(x,y);

  REP(i,20) REP(j,20) REP(k,20) REP(l,20) {
    set<P> st;
    for(auto [x,y]: b[0]) st.emplace(x+i-10,y+j-10);
    for(auto [x,y]: b[1]) st.emplace(x+k-10,y+l-10);
    if (st == ideal) { cout << "Yes" << endl; return 0; }
  }
  cout << "No" << endl;
  return 0;
}