#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using P = pair<int,int>;

int main() {
  int d; cin >> d;
  vector<int> c(26);
  REP(i,26) cin >> c[i];
  vector s(d,vector<int>(26));
  REP(i,d) REP(j,26) cin >> s[i][j];
  REP(i,d) {
    P mx = {0,0};
    REP(j,26) {
      if (mx.first < s[i][j]) mx = {s[i][j],j};
    }
    int idx = mx.second;
    cout << idx+1 << endl;
  }
  return 0;
}