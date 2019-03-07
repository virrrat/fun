#include <bits/stdc++.h>

using namespace std;

template <typename T>
class Vector{
private:
    T *elem;
    int sz;
    int cp;
public:
    using value_type = T;

    Vector(){
        elem = new T[2];
        sz = 0;
        cp = 2;
    }

    Vector(nullptr_t ptr){
        elem = nullptr;
        sz = 0;
        cp = 0;
    }

    explicit Vector(int s){
        if(s<0)
            throw bad_alloc{};
        elem = new T[s];
        sz = s;
        cp = s;
    }

    Vector(initializer_list<T> lst){
        elem = new T[lst.size()];
        copy(lst.begin(),lst.end(),elem);
        sz = lst.size();
        cp = lst.size();
    }

    Vector(const Vector<T>& lst){
        elem = new T[lst.capacity()];
        copy(lst.begin(),lst.end(),elem);
        sz = lst.size();
        cp = lst.capacity();
    }

    Vector& operator=(const Vector& lst){
    	delete[] elem;
        elem = new T[lst.capacity()];
        copy(lst.begin(),lst.end(),elem);
        sz = lst.size();
        cp = lst.capacity();
        return *this;
    }

    Vector(Vector<T>&& lst){
        cout << "In move constructor" << endl;
    	elem = lst.elem;
    	sz = lst.sz;
    	cp = lst.cp;

    	lst.elem = nullptr;
    	lst.sz = 0;
    	lst.cp = 0;
    }

    Vector<T>& operator=(Vector<T>&& lst){
        cout << "In move assignment" << endl;
    	delete[] elem;
	    elem = lst.elem;
        sz = lst.sz;
        cp = lst.cp;

        lst.elem = nullptr;
        lst.sz = 0;
        lst.cp = 0;
        return *this;
    }

    int size() const{
        return sz;
    }

    int capacity() const{
        return cp;
    }

    T& operator[](int i) const{
        if(i<0 or i>=sz)
            throw out_of_range{"Vector::operator[]"};
        return elem[i];
    } 

    void pop_back(){
        sz--;
    }

    T* begin() const{
        return elem;
    }

    T* end() const{
        return &elem[0]+sz;
    }

    void push_back(T val){
        if(sz<cp){
            elem[sz] = val;
            sz++;
        }
        else{
            cp *= 2;
            T* temp = new T[cp];
            copy(&elem[0],&elem[sz],temp);
            delete[] elem;
            elem = temp;
            elem[sz] = val;
            sz++;

        }
    }

    Vector<T> operator+(Vector<T>& b){
    	if(sz != b.size())
    		throw runtime_error{"Size mismatch"};

    	Vector<T> ans(sz);
    	for(int i=0;i<b.size();i++){
    		ans[i] = elem[i]+b[i];
    	}
    	return ans;
    }

    ~Vector(){
        delete[] elem;
    }
};



/*template< typename T>
typename T::value_type sum(T& Container){
    typename T::value_type value = 0;
    for(auto x:Container){
        value += x;
    }
    return value;
}*/

template<typename T,typename V>
void sum(const T& container,V& val){
    for( auto x:container){
        val += x;
    }
}



int main(){
    Vector<int> myvec {6,2,3,4,5,5};
    cout << myvec.begin() << endl;
    cout << &myvec[0] << endl;
    int value = 0;
    sum(myvec,value);
    cout << value << endl;
    sort(myvec.begin(),myvec.end());
    for(int i=0;i<myvec.size();i++){
        cout << myvec[i] << " ";
    }
    cout << endl;

    list<int> myvec2;
    unique_copy(myvec.begin(),myvec.end(),back_inserter(myvec2));
    
    for(auto& x:myvec2 ){
        cout << x << " ";
    }
    cout << endl;

    return 0;
}