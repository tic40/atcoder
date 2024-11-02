#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n; cin >> n;
  vector<int> a(n);
  REP(i,n) cin >> a[i];

  unordered_map<int,int> mp;
  REP(i,n) {
    cout << (mp.find(a[i]) != mp.end() ? mp[a[i]] : -1) << " ";
    mp[a[i]] = i+1;
  }
  return 0;
}