//
//  maze.cpp
//  Sam Kujovich
//  Created by samuel a kujovich on 3/11/14.
//
//


#include <stack>
#include "cell.h"

#define l(x) (x-1)
#define r(x) (x+1)
#define u(x, r) (x-r)
#define d(x, r) (x+r)

bool all_neighbors(Cell*);

int main()
{
    int size, i = 0;
    Cell* graph;
    Cell* current;
    int visited,random, count;
    Cell* temp[4];
    bool goal_reached = false;
    srand(time(NULL));
    
    cout<< "What would you like the size to be?" << endl;
    cin>> size;
    
    graph = new Cell [size*size];
    
    stack<int> CellStack;
    current = &graph[0];
    visited = 1;
    
    
    while (visited < size*size)
    {
        if (current->get_DFS() == -1)
            if(!goal_reached)
            {
                current->set_DFS(visited-1);
            }
        for (int j = 0; j<4; j++)
        {
            temp[j] = NULL;
        }
        
        count = 0;
        
        if (i % size != 0 && all_neighbors(&graph[l(i)]))
        {
            temp[0] = &graph[l(i)];
            count++;
        }
        if (i % size != size-1 && all_neighbors(&graph[r(i)]))
        {
            
            temp[1] = &graph[r(i)];
            count++;
            
        }
        if (i - size >= 0 && all_neighbors(&graph[u(i, size)]))
        {
            temp[2] = &graph[u(i,size)];
            count++;
        }
        if (i+size < size*size && all_neighbors(&graph[d(i,size)]))
        {
            temp[3] = &graph[d(i, size)];
            count++;
        }
        if (count > 0 )
        {
            while(1)
            {
                random = rand() % 4;
                if (temp[random] != NULL)
                    break;
            }
            CellStack.push(i);
            if (!goal_reached)
            {
                current->set_chosen(true);
                if (i == (size*size) -1 )
                {
                    goal_reached = true;
                }
            }
            //demolishing left
            if (random == 0)
            {
                current->set_left(temp[0]);
                temp[0]->set_right(current);
                i = l(i);
            }
            //right
            else if (random == 1)
            {
                current->set_right(temp[1]);
                temp[1]->set_left(current);
                i = r(i);
            }
            //up
            else if (random ==2)
            {
                current->set_up(temp[2]);
                temp[2]->set_down(current);
                i = u(i, size);
                
            }
            //down
            else
            {
                current->set_down(temp[3]);
                temp[3]->set_up(current);
                i = d(i, size);
            }
            current = temp[random];
            visited++;
        }
        else
        {
            i = CellStack.top();
            CellStack.pop();
            current->set_chosen(false);
            current = &graph[i];
        }
    }
   cout << endl << endl << "best path:" <<endl;
    while (!CellStack.empty())
    {
        cout<<CellStack.top() << endl;
       CellStack.pop();

    }
    cout << endl << endl << "empty maze:" <<endl;
    //Print empty maze
    i = 0;
    for (int j = 0; j< (2*size) +1 ;j++)
    {
        if (j==0)
        {
            cout << "+ +";
            for (int a = 0; a<size -1 ; a++)
            {
                cout<< "-+";
            }
            cout << endl;
        }
        else if (j == 2*size)
        {
            for (int a = 0; a<size -1 ; a++)
            {
                cout<< "+-";
            }
            cout << "+ +";
            cout << endl;
        }
        else if (j%2 ==1)
        {
            for (int a = 0; a<size; a++)
            {
                if (graph[i+a].get_left() == NULL)
                    cout << "| " ;
                else
                    cout << "  ";
            }
            cout << "|" << endl;
        }
        else if (j%2 == 0)
        {
            for (int a = 0; a<size; a++)
            {
                cout << "+";
                if (graph[i+a].get_down() == NULL)
                    cout << "-" ;
                else
                {
                    cout << " ";
                }
            }
            cout<< "+" << endl;
            i+=size;
        }
    }
    cout << endl << endl << "DFS :" << endl;
    //print maze DFS Case
    i=0;
    for (int j = 0; j< (2*size) +1 ;j++)
    {
        if (j==0)
        {
            cout << "+ +";
            for (int a = 0; a<size -1 ; a++)
            {
                cout<< "-+";
            }
            cout << endl;
        }
        else if (j == 2*size)
        {
            for (int a = 0; a<size -1 ; a++)
            {
                cout<< "+-";
            }
            cout << "+ +";
            cout << endl;
        }
        else if (j%2 ==1)
        {
            for (int a = 0; a<size; a++)
            {
                if (graph[i+a].get_DFS() > -1)
                {
                    if (graph[i+a].get_left() == NULL)
                        cout << "|";
                    else
                        cout << " ";
                    cout << graph[i+a].get_DFS()%10;
                    
                }
                else if (graph[i+a].get_left() == NULL)
                    cout << "| " ;
                
                else
                    cout << "  ";
            }
            cout << "|" << endl;
        }
        else if (j%2 == 0)
        {
            for (int a = 0; a<size; a++)
            {
                cout << "+";
                if (graph[i+a].get_down() == NULL)
                    cout << "-" ;
                else
                {
                    cout << " ";
                }
            }
            cout<< "+" << endl;
            i+=size;
        }
    }

    cout<< endl << endl << "Best Path:" << endl;
    //print maze best path
    i=0;
    for (int j = 0; j< (2*size) +1 ;j++)
    {
        if (j==0)
        {
            cout << "+ +";
            for (int a = 0; a<size -1 ; a++)
            {
                cout<< "-+";
            }
            cout << endl;
        }
        else if (j == 2*size)
        {
            for (int a = 0; a<size -1 ; a++)
            {
                cout<< "+-";
            }
            cout << "+ +";
            cout << endl;
        }
        else if (j%2 ==1)
        {
            for (int a = 0; a<size; a++)
            {
                if (graph[i+a].get_chosen() == true)
                {
                    if (graph[i+a].get_left() == NULL)
                        cout << "|";
                    else
                        cout << " ";
                    cout << "#";
                    
                }
                else if (graph[i+a].get_left() == NULL)
                    cout << "| " ;
                
                else
                    cout << "  ";
            }
            cout << "|" << endl;
        }
        else if (j%2 == 0)
        {
            for (int a = 0; a<size; a++)
            {
                cout << "+";
                if (graph[i+a].get_down() == NULL)
                    cout << "-" ;
                else
                {
                    cout << " ";
                }
            }
            cout<< "+" << endl;
            i+=size;
        }
    }
    
    return 0;
}
bool all_neighbors(Cell *test)
{
    if (test->get_left() == NULL && test->get_right() == NULL && test->get_up() == NULL && test->get_down() == NULL)
    {
        return true;
    }
    else
        return false;
}
