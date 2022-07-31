#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'

bool dp[2][16005][16005];

int main() {
  string s; cin >> s;
  int x,y; cin >> x >> y;

  int cnt = 0;
  vector<int> c;
  for(char v: s) {
    if (v == 'F') { cnt++; continue; }
    c.push_back(cnt);
    cnt = 0;
  }
  c.push_back(cnt);

  dp[0][0][8000] = 1;
  dp[1][0][8000] = 1;
  int d = 0;
  vector<int> dcnt(2);

  REP(i, (int)c.size()) {
    dcnt[d]++;
    REP(j,16001) {
      if ( dp[d][dcnt[d] - 1][j] ) {
        if (j + c[i] <= 16000) dp[d][ dcnt[d] ][ j + c[i] ] = true;
        // i == 0 のときは右を向いているため i > 0 のみ処理する
        if (i > 0 && j - c[i] >= 0) dp[d][ dcnt[d] ][ j - c[i] ] = true;
      }
    }
    d ^= 1;
  }

  bool ok = dp[0][dcnt[0]][x + 8000] && dp[1][dcnt[1]][y + 8000];
  cout << (ok ? "Yes" : "No") << endl;
  return 0;
}