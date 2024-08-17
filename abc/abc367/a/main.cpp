#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int a,b,c; cin >> a >> b >> c;
  REP(i,24) {
    int t = (c+1+i) % 24;
    if (t == b) break;
    if (t == a) { cout << "Yes" << endl; return 0; }
  }
  cout << "No" << endl;
  return 0;
}