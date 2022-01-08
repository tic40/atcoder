#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
typedef long long ll;

int main() {
  int h,a,ans=0;
  cin >> h >> a;
  while(h>0) {
    h-=a;
    ans++;
  }
  cout << ans << endl;
}