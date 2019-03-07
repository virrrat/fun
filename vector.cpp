#include <bits/stdc++.h>

using namespace std;

template <typename T>
class Vector{
private:
    T *elem;
    int sz;
    int cp;
public:
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

    Vector(int s,int value){
    	if(s<0)
    		throw runtime_error{"Negative Size"};
    	elem = new T[s];
    	sz = s;
    	cp = s;
    	for(int i=0;i<sz;i++){
    		elem[i] = value;
    	}
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

    bool operator==(const Vector<T>& b){
    	if(sz != b.size())
    		return false;
    	for(int i=0;i<sz;i++){
    		if(elem[i]!=b[i])
    			return false;
    	}
    	return true;
    }

    bool operator!=(const Vector<T>& b){
    	return !(*this==b);
    }

    ~Vector(){
        delete[] elem;
    }
};




int main(){
    Vector<int> myvec {{1},{2},{3}};
    Vector<int> myvec2{myvec};
    // myvec2.push_back({5});

    cout << (myvec != myvec2) << endl;
   

    Vector<int> ans = nullptr;
    ans = myvec+myvec2;

    
    return 0;
}