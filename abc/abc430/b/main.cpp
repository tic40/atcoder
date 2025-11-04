#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,m; cin >> n >> m;
  vector<string> s(n);
  REP(i,n) cin >> s[i];

  auto f = [&](int x, int y) {
    int bit = 0;
    REP(i,m) REP(j,m) if (s[x+i][y+j] == '#') bit += 1<<(i*m+j);
    return bit;
  };

  set<int> st;
  REP(i,n-m+1) REP(j,n-m+1) st.insert(f(i,j));
  cout << st.size() << endl;
  return 0;
}