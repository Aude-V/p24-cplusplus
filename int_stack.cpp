#include <iostream>
#include <stdexcept>

// constante entière pour la taille de la pile
const int SIZE{12};

// on définit un type de donnée (une classe) pour gérer une pile d'entier de taille 12 (SIZE)
class IntStack
{
private: // vos attributs pour représenter la pile d'entier
    // dans cette version toutes les piles sont de taille SIZE
    int tab[SIZE]; // initialisation de la pile
    int n = 0;     // nombre d'éléments dans la pile
public:
    bool is_empty()
    {
        // cette fonction teste si la pile est vide
        if (n == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool is_full()
    {
        // cette fonction teste si la pile est pleine
        // il y a SIZE entiers dans la pile
        if (n == SIZE)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void push(int e)
    {
        // cette fonction ajoute l'entier e dans la pile
        if (is_full())
        {
            std::cout << "la pile est pleine\n";
            exit(0);
        }
        tab[n] = e;
        n = n + 1;
    }
    int get_top()
    {
        // cette fonction retourne le dernier entier empilé
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
    int pop()
    {
        // cette fonction retourne le dernier entier empilé
        // et supprime cet entier de la pile
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
    void print()
    {
        // cette fonction affiche la pile, par exemple
        // [1 2 3 ] pour dire que 3 entiers sont dans la pile
        // le dernier empilé est 3
        std::cout << '[';
        for (int i = 0; i < n; i++)
        {
            std::cout << tab[i] << ' ';
        }
        std::cout << "]\n";
    }
};

// 1. réaliser le code pour faire fonctionner cette pile d'entier de taille fixée à la compilation
// 2. quelles sont les méthodes qui ne modifient pas l'objet sur lequel elles sont appelées
//    faites en sorte qu'elles puissent être appelées sur un objet constant
// 3. faites la fonction qui permet d'afficher un objet de type IntStack directement avec <<<
//    std::cout << s1;
//    il faut redéfinir l'operator<< en appelant la méthode print

int main()
{
    IntStack s1;
    s1.print(); // affichera [[
    s1.pop();
    std::cout << s1.is_empty() << std::endl;
    s1.push(1);
    std::cout << s1.is_empty() << std::endl;
    s1.print();
    s1.push(2);
    s1.push(3);
    std::cout << s1.is_full() << std::endl;
    s1.print();                         // affichera [1 2 3 ]
    std::cout << s1.pop() << std::endl; // affichera 3
    s1.print();                         // affichera [1 2 ]
    return 0;
}