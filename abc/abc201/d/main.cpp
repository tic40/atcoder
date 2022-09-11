#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'
const int INF = numeric_limits<int>::max();

int h,w;
vector s(2000, vector<int>(2000));
vector memo(2000, vector<int>(2000,-INF));

int f(int i, int j) {
  if (i == h-1 && j == w-1) return 0;
  if (memo[i][j] != -INF) return memo[i][j];

  // 次は相手のターンなので、 -f(i+1,j) する
  if (i+1 < h) memo[i][j] = max(memo[i][j], s[i+1][j] - f(i+1,j));
  if (j+1 < w) memo[i][j] = max(memo[i][j], s[i][j+1] - f(i,j+1));
  return memo[i][j];
}

int main() {
  cin >> h >> w;
  vector<string> a(h);
  REP(i,h) cin >> a[i];
  REP(i,h) REP(j,w) s[i][j] = a[i][j] == '+' ? 1 : -1;

  int score = f(0,0);
  if (0 < score) cout << "Takahashi" << endl;
  else if (score == 0) cout << "Draw" << endl;
  else cout << "Aoki" << endl;
  return 0;
}