#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int a,b; cin >> a >> b;
  REP(i,10) if (i != a+b) { cout << i << endl; break; }
  return 0;
}