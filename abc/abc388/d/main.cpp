#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n; cin >> n;
  vector<int> a(n);
  REP(i,n) cin >> a[i];

  vector<int > s(n+1);
  REP(i,n) {
    a[i] += s[i];
    s[i+1]++;
    s[min(n,i+a[i]+1)]--;
    a[i] = max(0,a[i]-(n-1-i));
    s[i+1] += s[i];
    cout << a[i] << " ";
  }
  return 0;
}