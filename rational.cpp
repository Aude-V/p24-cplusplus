#include <iostream>

class Rational {
    friend Rational operator +(const Rational&,const Rational&); //la fonction amie peut accéder au privé
                                                                 // const => dans la fonction, l'objet est non modifiable
                                                                 // on prend la référence du rationnel pour éviter de copier la valeur du rationnel
    private:
        int num;
        int denom;
    public:
        Rational(int n=0,int m=1):

            num{n}, denom{m}{
                if (m==0) {std::cout<<"un rationnel ne peut pas avoir 0 au dénominateur"<<std::endl; throw 0;}
            }

        void print() const //afficher la fraction
                           // const => indique que la fonction ne modifie rien donc on peut l'appeler sur des objets constants (sinon erreur)
        {
            std::cout<<num<<'/'<<denom<<std::endl;
        }

        float eval(){ //afficher la valeur du rationnel en flottant
            return static_cast<float>(num)/denom;
        }

};

std::ostream & operator << (std::ostream& os, Rational r1) { //pour pouvoir utiliser std::cout
    r1.print();
    return os;
}

Rational operator +(const Rational& r1, const Rational& r2){ //somme de rationnels : on redéfinit l'opérateur +
    int num=r1.num*r2.denom+r1.denom*r2.num;
    int denom=r1.denom*r2.denom;
    return Rational(num,denom);
}



int main(){
    Rational r1; // 0/1
    Rational r2(1); // 1/1
    Rational r3(4,6); // 4/6
    Rational r4(1,2);
    r1.print();
    r2.print();
    r3.print();
    std::cout << r3.eval() <<std::endl;
    Rational r5=r3+r4;
    std::cout << r3 << '+' << r4 << '=' << r5 << std::endl;
}