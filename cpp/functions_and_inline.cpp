#include<iostream>

int f(int x, int y){
    return x + y;
}

int f(int p, int x, int y = 10){ //always right to left works for default argument setting
    return x + y;
}

// int f(int x=10, int y, float p){ //ths is not allowed
//     return x + y;
// }

int fun(int x, int y=10); //put in header is fine
int fun(int x, int y){ //we shouldn't define again in .cpp otherwise will get redefinition of default argument
    return x + y;
}


int cval = 10;
int fun(int x = cval){ //It will compile but shouldn't do we must assign const variable
    return x + 5;
}


/// inline ////////////

inline int square(int x){ //fine
    return x*x;
}
/*
without inline 
int y = square(5); // function call

with inline
int y = 5*5
*/


/// macro vs inline ////
#define SQ(x) x*x // can be dangerous

// SQ(2+3); // 2+3*2+3
//inline safe for this case



int main(){
    
    return 0;
}

/*
KEY FINDS:
Q1: Are inline functions always inlined?

👉 No, compiler decides

Q2: Why use inline?

👉 Reduce function call overhead + allow header definitions

Q3: Why default args must be trailing?

👉 To avoid ambiguity in function calls

Q4: Inline vs macro?

👉 Inline is type-safe, macro is not

🔥 Key Takeaways
Default args → reduce overloads
Inline → performance + linkage behavior
Inline ≠ guaranteed inlining
Default args + overloading → danger zone

*/