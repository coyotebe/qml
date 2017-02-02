#include <iostream>

using namespace std;

//////////////////// const
class MyConst{
public:
    MyConst(int old){mOld = old;}
    int getOld(){return mOld;}
    void setOld(int val){mOld = val;}
    void print(){}
    static printSt();
    void finalFunction() const{
        cout << "say ahihi";
        //print(); error
        cout << mOld; // ok
        //mOld = 20; // error
        printSt();
    }
private:
    int mOld;
};
int main_const(int argc, char *argv[])
{
    char *p = "hello";
    char * const  * pp = &p;
    cout << "p:" << p << endl;
    cout << "Hello World!" << endl;
    return 0;
}



///////////////////// function pointer
int printSum(int a, int b){
    cout << a << " + " << b << " = " << (a+b) << endl;
    return (a+b);
}

class FuncClass{
public:
    int printSum(int a, int b){
        cout << "[Object] " << a << " + " << b << " = " << (a+b) << endl;
        return a + b;
    }
};

int main(int argc, char* argv[]){
    // function pointer normal
    int (*func)(int, int);
    func = printSum;
    (*func)(10, 20); // ~~ func(10,20);

    // object function normal
    int (FuncClass::*funcObj)(int, int) = &FuncClass::printSum;
    FuncClass obj;
    (obj.*funcObj)(10,20);


    cout << "main end!";
    return 0;
}
