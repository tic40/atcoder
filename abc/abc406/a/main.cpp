#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int a,b,c,d; cin >> a >> b >> c >> d;
  cout << (a*60+b > c*60+d ? "Yes" : "No") << endl;
  return 0;
}