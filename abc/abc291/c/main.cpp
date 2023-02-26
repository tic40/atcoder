#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using P = pair<int,int>;

int main() {
  int n; string s;
  cin >> n >> s;

  set<P> st;
  st.emplace(0,0);
  int x = 0,y = 0;
  bool ok = false;

  REP(i,n) {
    if (s[i] == 'L') x--;
    else if (s[i] == 'R') x++;
    else if (s[i] == 'U') y++;
    else if (s[i] == 'D') y--;

    if (st.count({x,y})) { ok = true; break; }
    st.insert({x,y});
  }

  cout << (ok ? "Yes" : "No") << endl;
  return 0;
}