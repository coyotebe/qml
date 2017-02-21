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
int ex_printSum(int a, int b){
    return printSum(a,b);
}

class FuncClass{
public:
    int printSum(int a, int b){
        cout << "[Object] " << a << " + " << b << " = " << (a+b) << endl;
        return a + b;
    }
};
typedef enum _MENUM{
    EVAL_1
    , EVAL_2
    , EVAL3
} MENUM;

/***
 * For ARGS variable in macro and functions
 * **/

#define PRINT_FMT_STRING(fm,args...) printf(fm,##args)
#include <stdarg.h>

int average ( int num, ... )
{
  va_list arguments;                     // A place to store the list of arguments
  int sum = 0;

  va_start ( arguments, num );           // Initializing arguments to store all values after num
  for ( int x = 0; x < num; x++ )        // Loop until all numbers are added
    sum += va_arg ( arguments, int ); // Adds the next value in argument list to sum.
  va_end ( arguments );                  // Cleans up the list
  cout << "num: " << num << ", sum:" << sum << endl;
  return sum / num;                      // Returns the average
}
void PrintFError ( const char * format, ... )
{
  char buffer[256];
  va_list args;
  va_start (args, format);
  vsprintf (buffer,format, args);
  cout << buffer;
  va_end (args);
}

void checkEndOfArgsList(const char *fm, ...){
    va_list args;
    int val = -1;
    va_start(args,fm);
    while(true){
        val = va_arg(args, int);
        if(!val)
            break;
        cout << "val:" << val << endl;
    }
    va_end(args);
}

/***
 * End for ARGS variable in macro and functions
 * **/
int main(int argc, char* argv[]){
    // function pointer normal
    int (*func)(int, int);
    func = printSum;
    (*func)(10, 20); // ~~ func(10,20);

    // object function normal
    int (FuncClass::*funcObj)(int, int) = &FuncClass::printSum;
    FuncClass obj;
    (obj.*funcObj)(10,20);
    const char * func_str = "printSum(30, 20)";

    cout << endl;
    cout << "main end!" << endl;
    PRINT_FMT_STRING("name:%s, age:%d\n", "Nguyen Chi Tue", 28);
    cout << average(3, 1, 2 , 30);

    PrintFError("\nname: %s, old: %d, addr: %s\n", "Nguyen Chi Tue", 28, "Bac Ninh City");

    checkEndOfArgsList("%d,%d", 1, 2 ,3 ,4 ,5 ,6, 7, 8);
    printf("\n %s", "Hello_fucking_sign");

    return 0;
}
