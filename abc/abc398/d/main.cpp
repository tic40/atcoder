#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using P = pair<int,int>;

int main() {
  int n,r,c; cin >> n >> r >> c;
  string s; cin >> s;
  map<char,P> mp;
  mp['N'] = {-1,0};
  mp['W'] = {0,-1};
  mp['S'] = {1,0};
  mp['E'] = {0,1};

  set<P> st;
  int ni = 0, nj = 0;
  st.emplace(ni,nj);
  REP(i,n) {
    auto [di,dj] = mp[s[i]];
    ni -= di; nj -= dj;
    st.emplace(ni,nj);
    cout << st.count({ni+r,nj+c});
  }
  return 0;
}
