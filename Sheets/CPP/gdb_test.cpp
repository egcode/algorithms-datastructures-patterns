/*
g++ -g -o /tmp/gdb_test gdb_test.cpp    // Compile
gdb /tmp/gdb_test                       // enter debugger
run 5                                   // run program with argument 5
break main                              // breakpoint in first line in main
run 5                                   // run with argument 5 and it will stop on breakpoint
print argv[1]                           // prints argument
next                                    // next line
step                                    // step into function

more info here https://hackingcpp.com/cpp/tools/gdb_intro.html
*/

#include <iostream>
#include <cstdlib>

int sum_up_to(int n) {
    if (n<0) return 0;
    int sum=0;
    for (int i=0; i<n; ++i) {
        sum += i;
    }
    return sum;
}

int main(int argc, char *argv[]) {
    if (argc <2) {
        std::cout<<"Usage: "<<argv[0]<<" <n>\n";
        return 0;
    }
    int n=std::atoi(argv[1]);
    int sum=sum_up_to(n);
    std::cout<<"result: "<<sum<<'\n';
}