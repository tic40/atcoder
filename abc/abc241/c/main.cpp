#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using P = pair<int,int>;
const vector<int> di = {-1,-1,0,1,1,1,0,-1};
const vector<int> dj = {0,1,1,1,0,-1,-1,-1};

int main() {
  int n; cin >> n;
  vector<string> s(n);
  REP(i,n) cin >> s[i];

  auto f = [&](int i, int j, P dir) {
    int now = 0;
    REP(k,6) {
      int ni = i+dir.first*k;
      int nj = j+dir.second*k;
      if (ni < 0 || nj < 0 || ni >= n || nj >= n) { now = 0; break; }
      now += s[ni][nj] == '#' ? 1 : 0;
    }
    return now >= 4;
  };

  int ok = 0;
  REP(i,n) REP(j,n) REP(k,8) ok |= f(i,j,P(di[k],dj[k]));
  cout << (ok ? "Yes" : "No") << endl;
  return 0;
}