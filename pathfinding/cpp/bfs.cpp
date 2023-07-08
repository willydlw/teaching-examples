#include "bfs.hpp"


BFS::BFS(const GridPosition& start, const GridPosition& goal, Grid& grid) :
    PathFind(start, goal, grid)   
{
    m_queue.push(start);
}


bool BFS::search(Grid& grid)
{
    if(m_goalReached )
    {
        std::cout << "\n******** GOAL REACHED *********\n";
        return true;
    }
    
    if(m_queue.empty())
    {
        std::cout << "\n ------- Queue Empty ---------\n";
        return false;
    }

    if(m_current != m_start && m_current != m_goal)
    {
        grid.setTileColor(m_current, VISITED);
    }
    
    
    m_current = m_queue.front();
    m_queue.pop();


    if(m_current != m_goal && m_current != m_start)
    {
        grid.setTileColor(m_current, CURRENT);
    }
    

    if(m_current == m_goal)
    {
        std::cout << "m_current == m_goal\n";
        m_goalReached = true;
    }
    else 
    {
        // add unvisted neighbors
        std::vector<GridPosition> neighborList;
        neighborList = grid.getNeighbors(m_current);

        for(auto n : neighborList)
        {
            if(!grid.visited(n))
            {
                grid.setVisited(n, true);
                grid.setParent(n, m_current);  
                m_queue.push(n);

                if(n != m_goal)
                {
                    grid.setTileColor(n, FRONTIER);
                 
                }
            }
            else
            {
                if(n != m_start && n != m_goal)
                {
                    grid.setTileColor(n, VISITED);
                }
            }
        }
    }

    return m_goalReached;
}


bool BFS::goalReached()
{
    return m_goalReached;
}


void BFS::constructPath(Grid& grid)
{
    Tile* current = grid.parent(m_goal);
    while( current->parent != nullptr)
    {
        m_path.push_back(current);
        current->tileState = PATH;
        current = current->parent;
    }
}