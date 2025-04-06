#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
const int mx = 1000001;

int main() {
  int q; cin >> q;
  // a は平方数
  // 10^6 までの数の素因数の個数を全列挙する
  // cnt[i] := 数 i の素因数の個数
  vector<int> cnt(mx);
  for(int i = 2; i < mx; i++) if (cnt[i] == 0) {
    for(int j = i; j < mx; j+=i) cnt[j]++;
  }
  vector<ll> vec;
  for(int i = 2; i < mx; i++) if (cnt[i] == 2) {
    vec.push_back((ll)i*i);
  }

  REP(_,q) {
    ll a; cin >> a;
    auto it = upper_bound(vec.begin(),vec.end(),a);
    it--;
    cout << *it << endl;
  }
  return 0;
}
