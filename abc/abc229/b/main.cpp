#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)
using ll = long long;
const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9+7;

int main() {
  string a,b;
  cin >> a >> b;

  reverse(a.begin(),a.end());
  reverse(b.begin(),b.end());
  REP(i, min((int)a.size(), (int)b.size())) {
    int x = a[i] - '0';
    int y = b[i] - '0';
    if (x + y >= 10) {
      cout << "Hard" << endl;
      return 0;
    }
  }
  cout << "Easy" << endl;
  return 0;
}