#include <iostream>
#include <stdexcept>

template <typename T, int s>

class Stack
{
private:
    int n; // nombre d'éléments dans la pile
    T *tab;     // initialisation de la pile
public:
Stack();
~Stack();
bool is_empty();
bool is_full();
void push(T);
T get_top();
T pop();
void print();
};



template<typename T,int s>
Stack<T,s>::Stack(){ //constructeur
    if (s<0){
        std::cout<<"taille non valide"<<std::endl;
        exit(0);
        }
    else {
        n=0;
        tab=new T[s];
    }
}

template<typename T,int s>
Stack<T,s>::~Stack(){ //destructeur
    delete [] tab;
}

template<typename T,int s>
bool Stack<T,s>::is_empty()
{
    // cette fonction teste si la pile est vide
    return n==0;
}

template<typename T,int s>
bool Stack<T,s>::is_full()
{
    // cette fonction teste si la pile est pleine
    return n==s;
}

template<typename T,int s>
void Stack<T,s>::push(T e)
{
    // cette fonction ajoute e dans la pile
    if (is_full())
    {
        std::cout << "la pile est pleine\n";
        exit(0);
    }
    tab[n] = e;
    n = n + 1;
}

template<typename T,int s>
T Stack<T,s>::get_top()
{
    // cette fonction retourne le dernier objet empilé
    if (is_empty())
    {
        std::cout << "la pile est vide\n";
        return 0;
    }
    else
    {
        return tab[n - 1];
    }
}

template<typename T,int s>
T Stack<T,s>::pop()
{
    // cette fonction retourne le dernier objet empilé
    // et supprime cet objet de la pile
    if (is_empty())
    {
        std::cout << "la pile est vide\n";
        return 0;
    }
    else
    {
        T elem = tab[n - 1];
        n = n - 1;
        return elem;
    }
}

template<typename T,int s>
void Stack<T,s>::print()
{
    // cette fonction affiche la pile
    std::cout << '[';
    for (int i = 0; i < n; i++)
    {
        std::cout << tab[i] << ' ';
    }
    std::cout << "]\n";
}


int main()
{
    Stack<int, 5> s;
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