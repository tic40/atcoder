#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using P = pair<int,int>;

int main() {
  int n,d; cin >> n >> d;
  vector<P> v;
  REP(i,n) {
    int t,l; cin >> t >> l;
    v.emplace_back(t,l);
  }

  for(int i = 1; i <= d; i++) {
    vector<int> w;
    REP(j,n) w.push_back(v[j].first * (v[j].second + i));
    sort(w.begin(),w.end());
    cout << w.back() << endl;
  }
  return 0;
}