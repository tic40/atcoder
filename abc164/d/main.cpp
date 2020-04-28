#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define COUT(x) cout<<(x)<<endl
#define dump(x)  cout << #x << " = " << (x) << endl;
using ll = long long;
using P = pair<int,int>;
using Graph = vector<vector<int>>;
using M = map<int,int>;
using PQ = priority_queue<int>;
using PQG = priority_queue<int, vector<int>, greater<int>>;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

const int m = 2019;

int main() {
  string s; cin >> s;
  int n=s.size();

  reverse(s.begin(), s.end());
  vector<int> cnt(m, 0);
  ll ans=0;
  int x=1, tot=0;
  REP(i,n) {
    tot += (s[i]-'0')*x;
    x = x*10%m;
    tot%=m;
    cnt[tot]++;
  }

  REP(i,m) ans += cnt[i] * (cnt[i]-1) / 2;
  COUT(ans);
  return 0;
}