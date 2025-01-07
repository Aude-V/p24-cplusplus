#include <iostream>
#include <vector>

class shape
{
protected:
    int position_x;
    int position_y;
    std::string color;
    void move(int new_x, int new_y)
    {
        position_x = new_x;
        position_y = new_y;
    }
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
};

class rectangle : public shape
{
    int width;
    int height;
    int area(rectangle r)
    {
        return r.width * r.height;
    }
};

class square : public shape
{
    int side;
    int area(square s)
    {
        return s.side * s.side;
    }
};

class circle : public shape
{
    int radius;
    int area(circle c)
    {
        return 3 * c.radius * c.radius;
    }
};

int main() {}