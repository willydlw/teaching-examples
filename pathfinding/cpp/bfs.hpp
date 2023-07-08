#ifndef BFS_HPP
#define BFS_HPP

#include <queue>

#include "pathfind.hpp"


class BFS : public PathFind
{
    public:
        BFS(const GridPosition& start, const GridPosition& goal, Grid& grid);

        bool search(Grid& grid);
        void constructPath(Grid& grid);

        bool goalReached();

    private:

        bool m_goalReached;
        GridPosition m_start;
        GridPosition m_goal;
        GridPosition m_current;

        std::queue<GridPosition>  m_queue;
        std::vector<Tile*> m_path;

};

#endif 