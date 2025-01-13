#include <iostream>
#include <vector>

class shape
{
public:
    int position_x;
    int position_y;
    shape(int x, int y) : position_x(x), position_y(y) {}
    void move(int new_x, int new_y)
    {
        position_x = new_x;
        position_y = new_y;
    }
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
    int area(rectangle r)
    {
        return r.width * r.height;
    }
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
    int area(circle c)
    {
        return 3 * c.radius * c.radius;
    }
};

shape find_at_position(int x, int y, std::vector<shape> v)
{
    for (auto s : v)
    {
        if (s.position_x == x and s.position_y == y)
        {
            return s;
        }
    }
    std::cout << "pas de forme trouvée à cette position" << std::endl;
    exit(0);
}

int main()
{
    circle c(10,20,4.5);
    rectangle r(20,30,30,60);
    std::vector<shape> shapes;
    shapes.push_back(c);
    shapes.push_back(r);
    shapes[0].move(4,6);
    shapes[1].move(2,8);
}