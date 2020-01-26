#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
typedef long long ll;

int main() {
  ll ans=0;
  int n,x,a,b=0;
  cin >> n >> x;
  REP(i,n) {
    cin >> a;
    int over = max(0, a+b-x);
    ans += over; b = a-over;
  }
  cout << ans << endl;
}