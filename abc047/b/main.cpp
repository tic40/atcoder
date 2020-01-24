#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
typedef long long ll;

int main() {
  int w,h,n;
  cin>>w>>h>>n;
  int x,y,a;
  pair<int,int> mi(0, 0), ma(w, h);
  REP(i,n) {
    cin>>x>>y>>a;
    if (a==1) mi.first = max(x, mi.first);
    else if(a==2) ma.first = min(x, ma.first);
    else if(a==3) mi.second = max(y, mi.second);
    else ma.second = min(y, ma.second);
  }

  cout << max(0,(ma.first - mi.first)) * max(0,(ma.second - mi.second)) << endl;
}
