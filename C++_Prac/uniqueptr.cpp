#include<iostream>
#include<memory>

struct point{
    int x;
    int y;
};

int main()
{
    auto uniq_ptr= std::make_unique<point>(point{3,5});

    std::cout<< uniq_ptr->x << " and " << uniq_ptr->y << std::endl;

}