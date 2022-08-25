#include<iostream>
using namespace std;

//test

int main(void){
    int i=1,j=1,k=1;
    cout << ++i || ++j && ++k;
    cout << " " << i << " " << j << " " << k;
    return 0;
} 