#include<iostream>
#include<cstdint>
#include<typeinfo>

int main(){
    int x = 10; // x is a variable name referring to a memory location that currently holds the value 10; it can store values of type int
    std::cout<<"x:"<<x<<std::endl;

    float y = 3; // it stores floating-point values (the integer 3 is implicitly converted to 3.0f)
    std::cout<<"y:"<<y<<std::endl;

    auto z = 12;
    auto z2 = 12.5; // floating-point literals are double by default
    auto z3 = 12.2f; // 'f' makes it a float literal explicitly; otherwise it would be double
    std::cout<<"z:"<<z<<" z2:"<<z2<<" type:"<<typeid(z2).name()<<" "<<typeid(z3).name()<<std::endl;

    auto l = 10000000000; // deduced as long long (or a wider integer type), not int
    auto l1 = 10000000000LL; // long long

    /////////////////////
    //initialization
    int a = 10; //copy initialization
    int a1(10); // direct initialization
    int a2{10}; // uniform initialization
    int a3 = {10}; //copy list initialization


    // int v = 3.7; // allowed, but becomes 3 due to truncation (silent data loss)
    // int v2{3.7}; //compile ERROR

    //////////////////////
    unsigned int t1 = 10;
    int t2 = -1;
    if(t1 > t2){  // false: t2 is converted to unsigned int, so -1 becomes a large positive value; this happens only during comparison

        std::cout<<"True  and t2:"<<t2<<std::endl;
    }else{
        std::cout<<"False  and t2:"<<t2<<std::endl; // t2 is still -1 because conversion happens only during comparison
    }
    // so basically it's happening internally this: if(t1 > static_cast<unsigned int>(t2))


    ///////////////////////
    //Normal code:
    int age = 24;
    double salary = 70000.00;

    //Production code:
    std::int32_t id = 10001; // fixed-size 32-bit signed integer
    std::uint64_t big = 1e9;

    auto value = 3.14; //type deduction

    // std::int32_t is not necessarily the same as int; it is guaranteed to be exactly 32 bits

    //std::size_t
    //An unsigned integer type and Can never be negative, Must support large memory sizes


    /*
    KEY POINTS
    - Variables
    Variable = named memory location with a type
    Always initialize variables (avoid garbage/UB)
    Scope matters (local vs global vs static)
    - Types
    Type defines size, range, and operations
    Common: int, float, double, char, bool
    Signed vs unsigned → very important difference
    Prefer brace initialization {} to avoid data loss
    Use auto when type is obvious
    Use fixed-width types (int32_t, etc.) when size must be exact
    - Conversions (Critical)
    Mixing signed & unsigned → bugs
    Signed value may convert to unsigned → unexpected results
    Conversions happen during expression, not stored
    - size_t
    Unsigned type used for sizes and indexing
    Returned by sizeof() and container .size()
    Cannot be negative
    - size_t Pitfalls
    Mixing int and size_t → dangerous
    -1 becomes huge positive when converted to size_t
    Reverse loop with size_t → infinite loop risk
    - Best Practices
    Use int for general logic
    Use size_t for indexing/size
    Avoid mixing signed & unsigned
    Prefer range-based loops when possible
    
    
    
    */
    return 0;
}