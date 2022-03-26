#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)

int main() {
  int a,b,c,d;
  cin >> a >> b >> c >> d;
  int x = a*60*60 + b*60;
  int y = c*60*60 + d*60 + 1;

  if (x < y) cout << "Takahashi" << endl;
  else cout << "Aoki" << endl;
  return 0;
}
