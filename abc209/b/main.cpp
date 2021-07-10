#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)

int main() {
  int n,x;
  cin >> n >> x;
  REP(i,n) {
    int a; cin >> a;
    x -= a;
    x += (i+1) % 2 == 0;
  }

  cout << (0 <= x ? "Yes" : "No") << endl;
  return 0;
}