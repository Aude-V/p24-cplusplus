#include <iostream>
#include <stdexcept>

// on définit un type de donnée (une classe) pour gérer une pile d'entier de taille SIZE
class IntStack
{
private: // vos attributs pour représenter la pile d'entier
    int n;     // nombre d'éléments dans la pile
    int SIZE;
    int* tab; // initialisation de la pile (tab est l'adresse du premier entier de la pile, donc c'est ce qu'on appelle un tableau en c++)
public:
    IntStack(int s):n(0),SIZE(s){ //constructeur(param) : initialisation des paramètres
        if (SIZE<0){
            std::cout<<"taille non valide"<<std::endl;
            exit(0);
            }
        else {
            tab=new int[SIZE]; //crée un tableau dans la mémoire dynamique
        }
    }
    ~IntStack(){ //destructeur pour nettoyer la mémoire après son utilisation
        delete [] tab;
    }
    IntStack(const IntStack& r):n(r.n),SIZE(r.SIZE){ //constructeur pour copier un IntStack
        tab=new int[SIZE];
        for (int i=0;i<n;i++){
            tab[i]=r.tab[i]; //on ne peut pas mettre tab=r.tab car sinon tab deviendra l'adresse du premier tableau r (celui qu'on veut copier) et non du deuxième (celui qu'on cherche à créer)
        }                    // là si on modifie tab on ne modifie pas r (alors qu'en faisant tab=r.tab ce ne serait pas le cas)
    }
    IntStack & operator=(const IntStack &r){ //on ne rend pas void mais IntStack& car sinon on ne pourrait pas chaîner : t1=t2=t3
        // t1=t2 <=> t1.operator=(t2)
        if (this != &r){
            delete [] tab;
            tab=new int[r.SIZE];
            for (int i=0;i<n;i++){
                tab[i]=r.tab[i];
            }
        }
        return *this;
    }
    bool is_empty()
    {
        // cette fonction teste si la pile est vide
        return n==0;
    }

    bool is_full()
    {
        // cette fonction teste si la pile est pleine
        // il y a SIZE entiers dans la pile
        return n==SIZE;
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
    int size;
    std::cin>>size;
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