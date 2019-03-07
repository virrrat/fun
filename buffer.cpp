#include <bits/stdc++.h>

using namespace std;

template <typename T,int N>
struct Buffer{
    T elem[N];
    int sz = N;
}; 

int main(){
	Buffer<int,6> buff;
    for(int i=0;i<buff.sz;i++){
        cout << buff.elem[i] << endl;
    }
	return 0;
}