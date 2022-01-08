#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define ALL(x) x.begin(), x.end()
using ll = long long;
const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9+7;

vector<int> m(200001);
int main() {
  int n;
  cin >> n;
  vector<int> d;
  REP(i,n) {
    int a; cin >> a;
    m[a]++;
  }
  int x = 0, y = 0;
  for (int i = 1; i <= n; i++) {
    if (m[i] == 2) x = i;
    if (m[i] == 0) y = i;
  }

  if ( 0 < x && 0 < y) cout << x << " " << y << endl;
  else cout << "Correct" << endl;
  return 0;
}