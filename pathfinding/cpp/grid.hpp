#ifndef GRID_HPP
#define GRID_HPP

#include <vector>

#include "tile.hpp"

struct GridPosition
{
    int row;
    int col;

    GridPosition() : row(0), col(0) {}
    GridPosition(int r, int c) : row(r), col(c) {}

    bool operator== (const GridPosition& gp)
    {
        //std::cout << "GridPosition function operator==\n";
        //std::cout << "gp.row: " << gp.row << ", gp.col: " << gp.col << "\n";
        //std::cout << "row:    " << row << ", col:   " << col << "\n";
        return row == gp.row && col == gp.col;
    }

    bool operator!= (const GridPosition& gp)
    {
        return row != gp.row || col != gp.col;
    }

};


class Grid
{
    public:
        Grid(int rows, int cols, int tileSize);

    
        Grid& operator=(const Grid& rhs) = delete;  // disallow assignment
        Grid (const Grid& g) = delete;              // disallow copy
        Grid (const Grid&& g) = delete;             // disallow move


        // getters
        TILE_STATE tileState(const GridPosition& gp) const;
        int rows() const;
        int cols() const;
        bool visited(const GridPosition& gp) const;
        Tile* parent(const GridPosition& gp) const;


        // setters
        void setTileColor(const GridPosition& gp, TILE_STATE tstate);
        void setVisited(const GridPosition& gp, bool visited);
        void setParent(const GridPosition& gp, const GridPosition& parent);

        
        /* Set
            m_visited = false
            m_state = OPEN
            m_parent = nullptr
        
        */
        void reset();
        
        // returns row, col locations of valid neighbors 
        std::vector<GridPosition> getNeighbors(GridPosition gp);

        
        void draw(sf::RenderWindow& window);

        void printTileInfo(const GridPosition& current);

    private:

        int m_rows;
        int m_cols;
        int m_tileSize;
        std::vector<std::vector<Tile>> m_data;

    private:
        void init();
};

#endif 