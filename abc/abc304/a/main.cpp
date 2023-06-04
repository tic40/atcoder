#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n; cin >> n;
  vector<string> s(n);
  vector<int> a(n);
  REP(i,n) cin >> s[i] >> a[i];
  int now = min_element(a.begin(),a.end()) - a.begin();
  REP(i,n) {
    cout << s[now] << endl;
    now += 1;
    now %= n;
  }
  return 0;
}