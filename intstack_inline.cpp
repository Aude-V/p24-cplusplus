#include "intstack_inline.h"

int main()
{
    int size;
    std::cin >> size;
    IntStack s(size);
    s.print(); // affichera []
    s.pop();
    std::cout << s.is_empty() << std::endl;
    s.push(1);
    std::cout << s.is_empty() << std::endl;
    s.print();
    s.push(2);
    s.push(3);
    std::cout << s.is_full() << std::endl;
    s.print();                         // affichera [1 2 3 ]
    std::cout << s.pop() << std::endl; // affichera 3
    s.print();                         // affichera [1 2 ]
    s.push(3);
    s.push(4);
    s.push(5);
    std::cout << s.is_full() << std::endl;
    s.print();
    return 0;
}