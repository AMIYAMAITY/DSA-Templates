#include<iostream>

int main(){
    int a = 4;
    float b = 3.14f;
    double c = 3.14;
    char d = 'A';
    bool e = false;
    void* f = nullptr;


    //integer type
    // int, long , short, long long, unsigned int etc
    std::cout<<"int sizeof: "<<sizeof(int)<<std::endl;
    std::cout<<"long sizeof: "<<sizeof(long)<<std::endl;
    std::cout<<"short sizeof: "<<sizeof(short)<<std::endl;
    std::cout<<"long long sizeof: "<<sizeof(long long)<<std::endl;
    std::cout<<"unsigned int sizeof: "<<sizeof(unsigned int)<<std::endl;

    //floating type
    // float, double, long double
    std::cout<<"float sizeof: "<<sizeof(float)<<std::endl;
    std::cout<<"double sizeof: "<<sizeof(double)<<std::endl;
    std::cout<<"long double sizeof: "<<sizeof(long double)<<std::endl;

    //character types
    // char, wchar_t, char16_t, char32_t
    std::cout<<"char sizeof: "<<sizeof(char)<<std::endl;
    std::cout<<"wchar_t sizeof: "<<sizeof(wchar_t)<<std::endl;
    std::cout<<"char16_t sizeof: "<<sizeof(char16_t)<<std::endl;

    //boolean
    // bool

    //void
    // void

    //User define data type
    struct MyStruct
    {
        int x;
    };

    class MyClass{
        private:
            int x;
    };

    enum class User{ADMIN, NORMAL};

    using ll = long long;


    int* p; //pointer variable
    int& r = a; //reference
    int arr[10];

    //STL
    std::string s;
    std::vector<int> vc; 


    /*
    KEY FINDS:
    Q1: Why not compare floats with ==?
    👉 Precision errors

    Q2: Why is double default?
    👉 Better precision, negligible extra cost

    Q3: What is IEEE 754?
    👉 Standard for floating-point representation

    🔥 Key Takeaways
    Floating points ≠ exact values
    double is default choice
    Precision > range matters
    Comparisons are tricky
    long double is platform-dependent

    
    Q1: Why not use char for Unicode?
    👉 UTF-8 may need multiple bytes

    Q2: Why avoid wchar_t?
    👉 Platform dependent size

    Q3: Best modern choice?
    👉 std::string (UTF-8) in most cases

    🔥 Key Takeaways
    char = 1 byte, not full Unicode char
    wchar_t = legacy, avoid
    char16_t = UTF-16
    char32_t = UTF-32 (simplest but large)
    Encoding matters more than type


    Q1: Difference between pointer and reference?
    👉 Pointer = address, Reference = alias

    Q2: Can reference be null?
    👉 ❌ No

    Q3: Can pointer be reassigned?
    👉 ✅ Yes

    Q4: Why arrays decay to pointer?
    👉 For efficiency (no copy)

    🔥 Key Takeaways
    Pointer = holds address
    Reference = alias
    Array = contiguous memory
    Arrays → decay to pointers
    Reference = safer than pointer
    */
    return 0;
}