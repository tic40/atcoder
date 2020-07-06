#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	ll l, r; cin >> l >> r;
	int ans = 2019;

  for (ll i = l; i < r; i++) {
    for (ll j = i + 1; j <= r; j++) {
      ans = min(ans, (int)(i*j%2019));
      if (ans == 0){ cout << 0 << endl; return 0; }
    }
  }
  cout << ans << endl;
  return 0;
}