#include <bits/stdc++.h>
using namespace std;
#define ALL(x) (x).begin(),(x).end()
#define COUT(x) cout<<(x)<<"\n"
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define REP(i,n) for(int i=0;i<n;i++)
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
template<class T>bool chmax(T &a,const T &b) {if(a<b){a=b; return 1;} return 0;}
template<class T>bool chmin(T &a,const T &b) {if(b<a){a=b; return 1;} return 0;}
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

vector<int> split(int i) {
  vector<int> v(10);
  v[i%10]++;
  while(i/10) {
    i/=10;
    v[i%10]++;
  }
  return v;
}

bool solve(string s) {
  int n = s.size();

  if (n == 1) return s == "8";
  if (n == 2) {
    if (stoi(s) % 8 == 0) return true;
    swap(s[0], s[1]);
    return stoi(s) % 8 == 0;
  }

  vector<int> m(10);
  REP(i,n) m[s[i]-'0']++;

  for (int i=104; i<1000; i+=8) {
    vector<int> nums = split(i);
    int ok = true;

    REP(j, 10) if (m[j] < nums[j]) { ok = false; break; }
    if (ok) return true;
  }

  return false;
}

int main() {
  IOS;
  string s; cin >> s;
  Yes(solve(s));
  return 0;
}