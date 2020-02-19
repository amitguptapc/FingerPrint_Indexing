#include<vector>
#include<algorithm>
#include "bitmap.hpp"
#include<iostream>
#include<fstream>
using namespace std;

typedef vector<int>::iterator iter;

class WaveTreeSucc {
public:
// s is total no of elements
vector<vector<int> > C; int s;
// sigma : distinct elements
  WaveTreeSucc(vector<int> &A, int sigma) : C(sigma*2), s(sigma) {
    build(A.begin(), A.end(), 0, s-1, 1);
  }

  void build(iter b, iter e, int L, int U, int u) {
    if (L == U)
      return;
    int M = (L+U)/2;

    C[u].reserve(e-b+1); C[u].push_back(0);
    for (iter it = b; it != e; ++it)
      C[u].push_back(C[u].back() + (*it<=M));

    iter p = stable_partition(b, e, [=](int i){return i<=M;});

    build(b, p, L, M, u*2);
    build(p, e, M+1, U, u*2+1);
  }

   int rank(int c, int i) const {
     i++;
    int L = 0, U = s-1, u = 1, M, r;
    while (L != U) {
      M = (L+U)/2;
      r = C[u][i]; u*=2;
      if (c <= M)
        i = r, U = M;
      else
        i -= r, L = M+1, ++u;
    }
    return i;
  }

};


int main(){
vector<int> arr;
ifstream fin("imageMatrix.txt" , ios::in);
char ch;
fin>>ch;
while(ch!='+'){
  if(ch=='0'){
    arr.push_back(0);
  }else{
    arr.push_back(1);
  }
  fin>>ch;
}
fin.close();
vector<int> :: iterator it1 = arr.begin();
vector<int> :: iterator it2 = arr.end();
WaveTreeSucc* v = new WaveTreeSucc(arr , 2);
cout<<"size of array "<<arr.size()<<endl;
cout<<"size of main matrix   "<<v->C.size()<<" "<<v->C[1].size()<<endl;
cout<<v->rank(135,1)<<endl;
}
