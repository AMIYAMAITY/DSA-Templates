#include<iostream>

namespace A{
    int x = 10;
    int sq(){return 5*5;}
}

namespace B{
    int x = 5;
    int sq(){return 10*10;}
}

namespace N{ 
    namespace NS{
        int x = 8;
    }
}

namespace NM::NS { // modern c++ we can directly write c++17
    int x = 5;
}

namespace { //Anonymous
    int r = 10;
}

//For Anonymous namespace usecases
// file1.cpp
// namespace { int x = 10; }

// file2.cpp
// namespace { int x = 20; }
// These are different variables, not shared

// file1.cpp
namespace { int p = 10; }

// file2.cpp
extern int p; // cannot access
//avoid linker conflicts

int main(){
    int a = A::sq();
    int b = B::sq();
    int x = N::NS::x;
    //without namespace same name will get error


    // using std::cout; //it just populate cout only basically symbol of cout
    // using namespace std; //we shouldn't do, it's import everything

    // alias 
    namespace v = N::NS;
    int x2 = v::x;

    //using namespace std;
    //int cout = 5;// conflict


    return 0;
}


/*
KEY FINDS:
Q1: What is a namespace?

👉 Scope to avoid name collisions

Q2: Difference between using and using namespace?
using std::cout; → one symbol
using namespace std; → everything
Q3: What is anonymous namespace?

👉 Gives internal linkage (file-only visibility)

Q4: What is ADL?

👉 Compiler searches function in argument’s namespace

🔥 Key Takeaways
Namespace = scope management
Prevents name collisions
std is just a namespace
Avoid global using namespace
ADL can call functions without qualification
Anonymous namespace = file-private scope
Prevents linker conflicts
Better than static
Each .cpp gets its own copy
❌ Never use in headers
*/