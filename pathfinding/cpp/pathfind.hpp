#ifndef PATHFIND_HPP
#define PATHFIND_HPP

#include<vector>
#include "grid.hpp"

class PathFind
{
    public:
        PathFind(const GridPosition& start, const GridPosition& goal, Grid& grid);

        virtual bool search(Grid& grid) = 0;

        void constructPath(Grid& grid);
        bool goalReached();

    private:
        bool m_goalReached;
        GridPosition m_start;
        GridPosition m_goal;
        GridPosition m_current;
        std::vector<Tile*> m_path;
};

#endif 

