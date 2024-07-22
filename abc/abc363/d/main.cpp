#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  ll n; cin >> n;
  if (n == 1) { cout << 0 << endl; return 0; }
  n--;

  // 1 桁から数えていく
  for(int keta = 1;; keta++) {
    ll num = 9; // num: その桁数の回文数がいくらあるか
    REP(i,(keta+1)/2-1) num *= 10;
    // n がまだ残っていたら次の桁へ進む
    if (n > num) { n -= num; continue; }

    n += num/9 - 1;
    // s: 前半部分の数, rs: 後半部分の数
    string s = to_string(n);
    string rs = s;
    reverse(rs.begin(),rs.end());
    if (keta%2 == 1) s.pop_back();
    s += rs;
    cout << s << endl;
    return 0;
  }
  return 0;
}