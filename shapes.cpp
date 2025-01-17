#include <iostream>
#include <vector>

class shape
{
protected:
    int position_x;
    int position_y;

public:
    shape(int x, int y) : position_x(x), position_y(y) {} // si on met le constructeur en protected, on ne pourra pas créer de shape simple dans le main
    void move(int new_x, int new_y)
    {
        position_x = new_x;
        position_y = new_y;
    }
    int x() { return position_x; }
    int y() { return position_y; }
    virtual void print_class() { std::cout << "shape" << std::endl; }
    virtual int area() =0; // on met virtual pour que si on déclare un cercle comme shape, c++ ira chercher la méthode area de la class circle et non de la class shape
};

class rectangle : public shape
{
private:
    int width;
    int height;

public:
    rectangle(int x, int y, int w, int h) : shape(x, y), width(w), height(h)
    {
        if (width < 0 or height < 0)
        {
            std::cout << "taille non valide" << std::endl;
            exit(0);
        }
    }
    int area()
    {
        return width * height;
    }
    void print_class() { std::cout << "rectangle" << std::endl; }
};

class circle : public shape
{
private:
    int radius;

public:
    circle(int x, int y, int r) : shape(x, y), radius(r)
    {
        if (radius < 0)
        {
            std::cout << "rayon non valide" << std::endl;
            exit(0);
        }
    }
    int area()
    {
        return 3 * radius * radius;
    }
    void print_class() { std::cout << "circle" << std::endl; }
};

shape *find_at_position(int x, int y, std::vector<shape *> &v) // v est un vecteur d'adresses de shape (si on mettait juste shape, on perdrait des infos comme le radius par ex)
{                                                              // on passe v par référence pour éviter de copier tout le vecteur
    for (auto s : v)
    {
        if (s->x() == x and s->y() == y) // s->x() sert à appliquer la méthode x à l'objet dont s est l'adresse
        {
            s->print_class();
            return s;
        }
        // on pourrait aussi définir une méthode bool is_at_position(int x,int y) dans la class shape puis l'utiliser dans find_at_position
    }
    std::cout << "pas de forme trouvée à cette position" << std::endl;
    return nullptr; // renvoie l'adresse vide car n'a pas trouvé de shape à cette position
}

int main()
{
    circle c(10, 20, 4);
    circle *pc = &c;
    rectangle r(20, 30, 30, 60);
    rectangle *pr = &r;
    std::vector<shape *> shapes;
    shapes.push_back(pc);
    shapes.push_back(pr);
    shapes[0]->move(4, 6);
    shapes[1]->move(2, 8);
    find_at_position(5, 6, shapes);
    find_at_position(2, 8, shapes);
    std::cout<<r.area()<<std::endl;;
    std::cout<<c.area()<<std::endl;
}