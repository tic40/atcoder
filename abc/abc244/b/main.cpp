#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)

int main() {
  int n; string t;
  cin >> n >> t;

  int d = 0;
  vector<int> sum(4);
  REP(i,n) {
    if (t[i] == 'S') sum[d]++;
    else d = (d+1) % 4;
  }

  int x = sum[0] - sum[2];
  int y = sum[3] - sum[1];
  cout << x << " " << y << endl;
  return 0;
}