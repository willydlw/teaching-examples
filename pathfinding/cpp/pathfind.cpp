#include "pathfind.hpp"

PathFind::PathFind(const GridPosition& start, const GridPosition& goal, Grid& grid) :
    m_goalReached(false), 
    m_start(start), 
    m_goal(goal), 
    m_current(start)
{
    grid.reset();
    grid.setVisited(start, true);
    grid.setTileColor(start, START);
    grid.setTileColor(goal, GOAL);
    grid.setVisited(goal, false);
}



bool PathFind::goalReached()
{
    return m_goalReached;
}


void PathFind::constructPath(Grid& grid)
{
    Tile* current = grid.parent(m_goal);
    while( current->parent != nullptr)
    {
        m_path.push_back(current);
        current->tileState = PATH;
        current = current->parent;
    }
}