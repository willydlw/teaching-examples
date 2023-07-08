#include "grid.hpp"

Grid::Grid(int rows, int cols, int tileSize) : 
    m_rows(rows), 
    m_cols(cols), 
    m_tileSize(tileSize),
    m_data(std::vector<std::vector<Tile>>(m_rows, std::vector<Tile>(m_cols)))
{
    init();
}


void Grid::init()
{
    for(int r = 0; r < m_rows; r++)
    {
        for(int c = 0; c < m_cols; c++)
        {
            Location pos;
            pos.x = c * m_tileSize;
            pos.y = r * m_tileSize;
            m_data[r][c].xypos = pos;
        }
    }
}


void Grid::reset()
{
    for(int r = 0; r < m_rows; r++)
    {
        for(int c = 0; c < m_cols; c++)
        {
            m_data[r][c].visited = false;
            m_data[r][c].tileState = OPEN;
            m_data[r][c].parent = nullptr;
        }
    }
}




std::vector<GridPosition> Grid::getNeighbors(GridPosition gp)
{
    // above, right, below, left
    const GridPosition direction[4] = { {-1,0}, {0,1}, {1,0}, {0,-1}};

    std::vector<GridPosition> neighbors;

    for( const auto& d : direction)
    {
        int r = gp.row + d.row;
        int c = gp.col + d.col;

        if(r >= 0 && r < m_rows && c >= 0 && c < m_cols)
        {
            neighbors.push_back(GridPosition(r,c));
        }
    }

    return neighbors;
}



void Grid::draw(sf::RenderWindow& window)
{
        for(int r = 0; r < m_rows; r++)
        {
            for(int c = 0; c < m_cols; c++)
            {
                m_data[r][c].draw(window, m_tileSize);
            }
        }

}


void Grid::printTileInfo(const GridPosition& current)
{
    std::cout << m_data[current.row][current.col] << "\n";
}


/* Getters */

TILE_STATE Grid::tileState(const GridPosition& gp) const
{
    return m_data[gp.row][gp.col].tileState;
}

int Grid::rows() const
{
    return m_rows;
}

int Grid::cols() const
{
    return m_cols;
}

bool Grid::visited(const GridPosition& gp) const
{
    return m_data[gp.row][gp.col].visited;
}

Tile* Grid::parent(const GridPosition& gp) const
{
    return m_data[gp.row][gp.col].parent;
}

/* Setters */

void Grid::setVisited(const GridPosition& gp, bool visited)
{
    m_data[gp.row][gp.col].visited = visited;
   
}


void Grid::setTileColor(const GridPosition& gp, TILE_STATE tstate)
{
    m_data[gp.row][gp.col].tileState = tstate;
}


void Grid::setParent(const GridPosition& gp, const GridPosition& parent)
{
    m_data[gp.row][gp.col].parent = &m_data[parent.row][parent.col];
}
