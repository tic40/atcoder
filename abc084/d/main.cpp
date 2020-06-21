#include <bits/stdc++.h>
using namespace std;
#define ALL(x) (x).begin(),(x).end()
#define COUT(x) cout<<(x)<<"\n"
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define REP(i, n) for(int i=0;i<n;i++)
#define YES(x) cout<<(x?"YES":"NO")<<"\n"
#define Yes(x) cout<<(x?"Yes":"No")<<"\n"
#define dump(x) cout<<#x<<" = "<<(x)<<"\n"
#define endl "\n"
using G = vector<vector<int>>;
using M = map<int,int>;
using P = pair<int,int>;
using PQ = priority_queue<int>;
using PQG = priority_queue<int,vector<int>,greater<int>>;
using V = vector<int>;
using ll = long long;
using edge = struct { int to; int cost; };
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

vector<int> eratosthenes(int n) {
  vector<int> primes(n+1);
  for(int i=2; i<=n; i++) {
    if(primes[i] >= 0) {
      for(int j=2*i; j<=n; j+=i) primes[j] = -1;
      primes[i] = 1;
    }
  }
  return primes;
}

int main() {
  IOS;
  int q; cin >> q;
  const int N = 100005;

  vector<int> primes = eratosthenes(N);
  vector<int> s(N,0);
  REP(i,100001) {
    s[i+1] = s[i];
    if (primes[i] > 0 && primes[(i+1)/2] > 0) {
      s[i+1]++;
    }
  }
  REP(i,q) {
    int l,r;
    cin >> l >> r;
    COUT(s[r+1] - s[l]);
  }
  return 0;
}
