#include<iostream>
using namespace std;

int main()
{
    int a[]={10,25,87,100,4};
    int i, maximum, minimum;
    minimum=a[i];
    maximum=a[i];
    for(i=0;i<5;i++){
        if(minimum>a[i])
            minimum=a[i];
        else if(maximum<a[i])
            maximum=a[i];
    }

    cout<<"Maximum:"<<maximum<<endl;
    cout<<"Minimum:"<<minimum<<endl;
}
