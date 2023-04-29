#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,a,b; cin >> n >> a >> b;
  REP(i,n) {
    int c; cin >> c;
    if (c == a+b) { cout << i+1 << endl; return 0; }
  }
  return 0;
}