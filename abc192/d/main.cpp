#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;

string x;
ll m;
int d;

ll binary_search() {
  ll ok = d, ng = m+1;

  while(abs(ng-ok)>1) {
    ll mid = (ok+ng)/2;

    ll sum = 0, v = 1;
    for(char c: x) {
      // オーバーフローする場合
      if (m/mid < sum) {
        sum = m+1; break;
      } else {
        sum = sum*mid + c-'0';
      }
    }

    if (sum <= m)  ok = mid;
    else ng = mid;
  }
  return ok;
}

int main() {
  cin >> x >> m;

  // コーナーケース
  if (x.size() == 1) {
    cout << (stoi(x) <= m ? 1 : 0) << endl;
    return 0;
  }

  REP(i,x.size()) d = max(d, x[i]-'0');
  cout << binary_search() - d << endl;

  return 0;
}