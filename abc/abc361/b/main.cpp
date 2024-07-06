#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int a,b,c,d,e,f;
  int g,h,i,j,k,l;
  cin >> a >> b >> c >> d >> e >> f;
  cin >> g >> h >> i >> j >> k >> l;

  int x = max(0, min(d, j) - max(a, g));
  int y = max(0, min(e, k) - max(b, h));
  int z = max(0, min(f, l) - max(c, i));
  int vol = x * y * z;

  cout << (vol > 0 ? "Yes" : "No") << endl;
  return 0;
}