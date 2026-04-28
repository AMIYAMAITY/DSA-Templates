#include<iostream>

int main(){
    int x = 5;
    if(x == 5){}
    else {}

    switch (x)
    {
    case 5:
        break;
    default:
        break;
    }

///////////////////
    switch (x)
    {
    case 5:
        std::cout << "Five\n";
        [[fallthough]] //Compiler knows it's intentional
    default:
        std::cout << "Default\n";
    }

    /*
    KEY FIND
    - Control flow = decision + repetition
    - Conditions rely on bool conversion
    - {} prevents bugs (dangling else)
    - size_t + loops → danger zone
    - Short-circuiting → safety + performance
    */
}