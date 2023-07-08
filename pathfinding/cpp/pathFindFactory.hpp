#ifndef PATHFIND_FACTORY_HPP
#define PATHFIND_FACTORY_HPP

#include <memory>
#include <string>
#include "bfs.hpp"
#include "grid.hpp"

class PathFindFactory
{
public:

    static std::unique_ptr<PathFind> generateSearch(const std::string& searchType, Grid& grid)
    {
        if(searchType == "BFS")
        {
            return std::make_unique<BFS>(grid);
        }
        else 
        {
            return nullptr;
        }
        
    }
};


#endif