#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
using ll = long long;

int main() {
  ll n,k; cin >> n >> k;

  string sk = to_string(k);
  reverse(sk.begin(),sk.end());
  ll rk = stoll(sk);

  if (rk < k) {
    cout << 0 << endl;
    return 0;
  }

  set<ll> st;
  for (auto v: {k,rk}) {
    while(v <= n) {
      st.insert(v);
      v *= 10;
    }
  }

  cout << st.size() << endl;
  return 0;
}
