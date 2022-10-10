#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'

int main() {
  int t; cin >> t;
  REP(_,t) {
    int n,k; string s;
    cin >> n >> k >> s;
    vector<int> m0(n+1),m1(n+1); // 0と1それぞれの累積和
    REP(i,n) {
      m0[i+1] += m0[i] + (s[i] == '0');
      m1[i+1] += m1[i] + (s[i] == '1');
    }

    int cnt = 0;
    REP(i,n-k+1) {
      // iからi+kの区間に1をちょうどk個含むかどうかを調べる

      // iからkの間に0が含まれていたら満たさない
      if (m0[i+k] - m0[i] != 0) continue;
      // 0からi, i+kからnが全て0でなければ満たさない
      if (m1[i] != 0 || m1[n] - m1[i+k] != 0) continue;
      cnt++;
    }
    cout << (cnt == 1 ? "Yes" : "No") << endl;
  }
  return 0;
}