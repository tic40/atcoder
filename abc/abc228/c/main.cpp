#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)

int main() {
  int n,k;
  cin >> n >> k;
  vector<int> m(n);
  REP(i,n) {
    int a,b,c;
    cin >> a >> b >> c;
    m[i] = a+b+c;
  }
  vector<int> sorted = m;
  sort(sorted.rbegin(),sorted.rend());

  REP(i,n) {
    bool ok = sorted[k-1] <= m[i]+300;
    cout << (ok ? "Yes" : "No") << endl;
  }

  return 0;
}