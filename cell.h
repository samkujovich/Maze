//
//  cell.h
//  
//
//  Created by samuel a kujovich on 3/11/14.
//
//

#include <iostream>
using namespace std;


class Cell
{
    public:
        Cell();
        //Accessors
        Cell* get_left();
        Cell* get_right();
        Cell* get_up();
        Cell* get_down();
        int get_DFS();
        bool get_chosen();
        //Mutators
        void set_left(Cell*);
        void set_right(Cell*);
        void set_up(Cell *);
        void set_down(Cell*);
        void set_DFS(int);
        void set_chosen(bool);
    private:
        Cell* left;
        Cell* right;
        Cell* up;
        Cell* down;
        int DFS;
        bool chosen;
};
Cell::Cell()
{
    left = NULL;
    right = NULL;
    up = NULL;
    down = NULL;
    chosen = false;
    DFS = -1;
}
Cell* Cell::get_left()
{
    return left;
}
Cell* Cell::get_right()
{
    return right;
}
Cell* Cell::get_up()
{
    return up;
}
Cell* Cell::get_down()
{
    return down;
}
void Cell::set_left(Cell* new_cell)
{
    left = new_cell;
}
void Cell::set_right(Cell* new_cell)
{
    right = new_cell;
}
void Cell::set_up(Cell* new_cell)
{
    up = new_cell;
}
void Cell::set_down(Cell* new_cell)
{
    down = new_cell;
}
int Cell::get_DFS()
{
    return DFS;
}
void Cell::set_DFS(int x)
{
    DFS = x;
}
bool Cell::get_chosen()
{
    return chosen;
}
void Cell::set_chosen(bool a)
{
    chosen = a;
}
