#include <iostream>

void swap (float * x, float * y)
{
    float t=(*x);
    (*x)=(*y);
    (*y)=t;
}

int main ()
{
    float a{2.56};
    float b{3.45};
    swap(&a,&b);
    std::cout<<"a = "<<a<<" et b = "<<b<<std::endl;
}