#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)

int main() {
  int n,x;
  cin >> n >> x;
  vector<int> a(n);
  REP(i,n) if (0<i) cin >> a[i];

  int cnt = 0;
  while(1) {
    cnt++;
    if (a[x] == 0) break;
    x = a[x];
  }

  cout << cnt << endl;
  return 0;
}