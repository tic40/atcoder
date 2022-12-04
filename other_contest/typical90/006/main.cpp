#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'

int main() {
  int n,k; string s;
  cin >> n >> k >> s;

  vector m(n+1, vector<int>(26,n));
  for(int i = n-1; i >= 0; i--) REP(j,26) {
    if (s[i]-'a' == j) m[i][j] = i;
    else m[i][j] = m[i+1][j];
  }

  string ans;
  int pos = 0;
  REP(i,k) REP(j,26) {
    int nextPos = m[pos][j];
    if (k - i <= n - nextPos) {
      ans += 'a' + j;
      pos = nextPos + 1;
      break;
    }
  }
  cout << ans << endl;
  return 0;
}