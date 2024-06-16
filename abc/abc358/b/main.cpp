#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,a; cin >> n >> a;
  int now = 0;
  REP(i,n) {
    int t; cin >> t;
    if (now <= t) now = t+a;
    else now += a;
    cout << now << endl;
  }
  return 0;
}