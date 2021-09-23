#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

int main() {
  int n,a,b;
  cin >> n >> a >> b;
  vector<string> s(n);
  REP(i,n) cin >> s[i];

  cout << (s[a][b] == 'o' ? "Yes" : "No") << endl;
  return 0;
}