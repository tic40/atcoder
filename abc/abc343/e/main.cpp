#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

const int L = 7;
struct P {
  int x,y,z;
  P(int x, int y, int z): x(x),y(y),z(z) {}
};

// 3つの直方体が重なっている部分の面積を返す
int calcOverRapped(P p1, P p2, P p3) {
  int minX = max({p1.x, p2.x, p3.x});
  int maxX = min({p1.x, p2.x, p3.x}) + L;
  int minY = max({p1.y, p2.y, p3.y});
  int maxY = min({p1.y, p2.y, p3.y}) + L;
  int minZ = max({p1.z, p2.z, p3.z});
  int maxZ = min({p1.z, p2.z, p3.z}) + L;
  return max(0,(maxX - minX)) * max(0,(maxY - minY)) * max(0,(maxZ - minZ));
}

int main() {
  vector<int> v(3);
  REP(i,3) cin >> v[i];

  auto f = [&](int x1, int y1, int z1, int x2, int y2, int z2) {
    auto p1 = P(0,0,0); // p1 は原点に固定
    auto p2 = P(x1,y1,z1);
    auto p3 = P(x2,y2,z2);

    vector<int> nv(3);
    nv[2] = calcOverRapped(p1,p2,p3);
    // 1-2, 1-3, 2-3 それぞれの組み合わせで重なっている部分の面積の合計 - 3つ重なっている部分の面積
    nv[1] = calcOverRapped(p1,p1,p2) +  calcOverRapped(p1,p1,p3) + calcOverRapped(p2,p2,p3) - nv[2]*3;
    // 3つの合計面積 - 重なっている部分の面積
    nv[0] = (7*7*7*3) - (nv[1]*2 + nv[2]*3);
    return v == nv;
  };

  for(int i1 = -7; i1 <= 7; i1++) {
    for(int j1 = -7; j1 <= 7; j1++) {
      for(int k1 = -7; k1 <= 7; k1++) {
        for(int i2 = -7; i2 <= 7; i2++) {
          for(int j2 = -7; j2 <= 7; j2++) {
            for(int k2 = -7; k2 <= 7; k2++) {
              if (f(i1,j1,k1,i2,j2,k2)) {
                printf("Yes\n0 0 0 %d %d %d %d %d %d\n",i1,j1,k1,i2,j2,k2);
                return 0;
              }
            }
          }
        }
      }
    }
  }
  cout << "No" << endl;
  return 0;
}