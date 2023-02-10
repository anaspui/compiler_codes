#include <iostream>
using namespace std;

int factorial(int n){
    if(n==0)
        return 1;
    else
        return(n * factorial(n-1));
}

int main(){
    int fac=1, num, i;

    cout<<"Input the number : ";
    cin>>num;

    for(i=1;i<=num;i++){
        fac=fac*i;
    }
    cout<<"The Factorial of "<< num << " using loop is " << fac <<endl;

    fac= factorial(num);
    cout<<"The Factorial of "<< num << " using recursion is " << fac;

}
