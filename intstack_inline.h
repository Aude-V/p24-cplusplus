#pragma once

#include <iostream>

namespace pile
{

    class IntStack
    {
    private:
        int n;
        int SIZE;
        int *tab;

    public:
        IntStack(int);

        ~IntStack();

        IntStack(const IntStack &r) : n(r.n), SIZE(r.SIZE)
        {
            tab = new int[SIZE];
            for (int i = 0; i < n; i++)
            {
                tab[i] = r.tab[i];
            }
        }
        IntStack &operator=(const IntStack &r)
        {
            if (this != &r)
            {
                delete[] tab;
                tab = new int[r.SIZE];
                for (int i = 0; i < n; i++)
                {
                    tab[i] = r.tab[i];
                }
            }
            return *this;
        }

        bool is_empty();
        bool is_full();
        void push(int);
        int get_top();
        int pop();
        void print();
    };

    inline IntStack::IntStack(int s) : n(0), SIZE(s)
    {
        if (SIZE < 0)
        {
            std::cout << "taille non valide" << std::endl;
            exit(0);
        }
        else
        {
            tab = new int[SIZE];
        }
    }

    inline IntStack::~IntStack()
    {
        delete[] tab;
    }

    inline bool IntStack::is_empty()
    {
        return n == 0;
    }

    inline bool IntStack::is_full()
    {
        return n == SIZE;
    }

    inline void IntStack::push(int e)
    {
        if (is_full())
        {
            std::cout << "la pile est pleine\n";
            exit(0);
        }
        tab[n] = e;
        n = n + 1;
    }

    inline int IntStack::get_top()
    {
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

    inline int IntStack::pop()
    {
        if (is_empty())
        {
            std::cout << "la pile est vide\n";
            return 0;
        }
        else
        {
            int elem = tab[n - 1];
            n = n - 1;
            return elem;
        }
    }

    inline void IntStack::print()
    {
        std::cout << '[';
        for (int i = 0; i < n; i++)
        {
            std::cout << tab[i] << ' ';
        }
        std::cout << "]\n";
    }

}