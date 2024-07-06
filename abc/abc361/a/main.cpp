#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,k,x; cin >> n >> k >> x;
  REP(i,n) {
    int a; cin >> a;
    cout << a << " ";
    if (i == k-1) cout << x << " ";
  }
  return 0;
}