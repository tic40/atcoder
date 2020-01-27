#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
typedef unsigned long long ll;

int main() {
  ll h,ans=0;
  cin >> h;
  if (h == 1) { cout << 1 << endl; return 0; }
  ll height = log2(h);
  REP(i,height+1) { ans += pow(2,i); }
  cout << ans << endl;
}