#include<iostream>
#include<memory>

using namespace std;

template <class T>
class myvec{
    // std::unique_ptr<T> data;
    unique_ptr<T[]> data;
    public:
    int size;
    int capacity;
    myvec():data{nullptr},size(0),capacity(0){}
    ~myvec(){}
    void push_back(T val){
        if((size == capacity)){
            capacity = (capacity == 0)? 1 : capacity; 
            std::unique_ptr<T[]>tdata = std::make_unique<T[]>(capacity);
            // T* tdata = new T[capacity];
            for(int i=0;i < size; ++i){
                tdata[i] = data[i];
            }
            data = std::move(tdata); 
            // delete [] data;   
            // data = tdata;      
        }
        data[size]=val;
        ++size;
    }
    int getSize() const{
        return size;
    }
    void print_vec(){
        cout << "vector elements are : ";
        for(int i=0; i < size;++i){
            cout << data[i] << " ";
        }
        cout << endl;
    }

    void pop_back(){
        cout << "pop back value is : " << data[size-1] << endl;
        std::unique_ptr<T[]>tdata = std::make_unique<T[]>(capacity-1);
        size -= 1;
        // T* tdata = new T[capacity];
        for(int i=0;i < size ; ++i){
            tdata[i] = data[i];
        }
        data = std::move(tdata);
    }

    T front(){
        return data[0];
    }
};

int main(){
    myvec<int> vect;
    vect.push_back(10);
    vect.push_back(20);

    cout << "My vector size is : " << vect.getSize() << endl;
    vect.print_vec();
    vect.pop_back();
    cout << "My vector size is : " << vect.getSize() << endl;
    vect.print_vec();
    cout << "My vector front contains : " << vect.front() << endl;

    // Char vector

    myvec<char> arrvect;
    arrvect.push_back('A');
    arrvect.push_back('B');

    cout << "My vector size is : " << arrvect.getSize() << endl;
    arrvect.print_vec();
    arrvect.pop_back();
    cout << "My vector size is : " << arrvect.getSize() << endl;
    arrvect.print_vec();
    cout << "My vector front contains : " << arrvect.front() << endl;


    return 0;
}