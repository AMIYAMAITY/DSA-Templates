#include<iostream>
#include<vector>

void fun(int v){
    std::cout<<"Normal fun: "<<v<<std::endl;
}

void fun(std::initializer_list<int> v){
    for(int i : v)
        std::cout<<"v: "<<i<<std::endl;
}

void fun2(std::initializer_list<int>& v){
    for(int i : v)
        std::cout<<"v: "<<i<<std::endl;
    
    // v[1] = 44; // this is not valid, because values are const
}

std::initializer_list<int> get(){
    return {33,4,5}; // this is dangerous
}

class MyClass{
    public:
        MyClass(std::initializer_list<int> list){
            for(auto x : list){
                std::cout<<"x: "<<x<<std::endl;
            }
        }
};

int main(){
    int a{10};
    double d{3.45};
    std::vector<int> v{1,2,3,4,5}; // this is direct initializer
    std::vector<int> vv = {1,2,3,4,5}; // this is copy initializer
    std::vector<int> vt(5,2); //This is not same, this has 5 elements all the values are 2

    std::cout<<a<<" "<<d<<std::endl;

    fun(5); //this is normal function
    fun({3,2,1}); // this is initializer_list

    std::initializer_list<int> t{11,3,4,5};
    fun2(t); // this is initializer_list

    int arr[]{1,2,3}; //this also fine


    //auto trap
    auto p = {1,2,3,4}; //this is not vector, this is initializer_list<int>

    std::initializer_list<int> r = get();
    for(int i : r){
        std::cout<<"R:"<<i<<std::endl; //This is not valid dangerous, returning address of local temporary object
    }

    MyClass myclass{44,55,66,77};
    return 0;

    /*
    KEY FIND
    - {} → may create initializer_list
    - initializer_list → const + fixed + temporary-backed
    - {} → can change constructor behavior
    */
}