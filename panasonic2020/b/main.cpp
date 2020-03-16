#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
  ll h,w; cin >> h >> w;
  ll ans;
  if (h==1 || w==1) { cout << 1 << endl; return 0; }
  if (h%2==0){
    ans = w*h/2;
  } else {
    if (w%2==0) {
      ans = w*(h-1)/2+w/2;
    } else {
      ans = w*((h-1)/2)+w/2+1;
    }
  }
  cout << ans << endl;
  return 0;
}