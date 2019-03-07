#include <bits/stdc++.h>

using namespace std;

template< typename T>
using string_map = map<string,T>;
string_map<int> mymap;

int main(){
	string a = "Virat";
	string b = a;
	cout << a<< endl;
	cout << b << endl;
	mymap["a"]++;

	vector<int> myvec(5,6);
	cout << myvec.at(5) << endl; // throws range error unlike [] operator
	return 0;
}