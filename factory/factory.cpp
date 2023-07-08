/* Factory Method Design pattern

    Purpose: Quickly prototype the factory method design pattern for
    different search algorithms.
*/

#include <string>
#include <iostream>


/*
    The GenericSearch class interface declares the operations that
    all search algorithms must implement.
*/
class GenericSearch{
    public:
        virtual ~GenericSearch(){ std::cout << __FUNCTION__ << " destructs\n"; }
        virtual std::string FindPath() const = 0;
};

/*
    The following classes provide various implementations of the GenericSearch interface.
*/
class BFS : public GenericSearch
{
    public:
        ~BFS() { std::cout << "BFS destructor\n";}
        std::string FindPath() const override
        {
            return "Breadth First Search\n";
        }
};

class DFS : public GenericSearch
{
    public:
        ~DFS() { std::cout << "DFS destructor\n";}
        std::string FindPath() const override
        {
            return "Depth First Search\n";
        }
};

class Astar : public GenericSearch
{
    public:
        ~Astar() { std::cout << "A* destructor\n";}
        std::string FindPath() const override 
        {
            return "Astar\n";
        }
};


/* The Factory class declars the factory method that returns
    an object of a GenericSearch class.

*/

class Factory
{
    public:
        virtual ~Factory() {std::cout << "class Factory desctructor\n";}

        virtual GenericSearch* FactoryMethod() const = 0;

        std::string SearchOperation() const {
            // Call the factory method to create a GenericSearch object.

            std::cout << "Call the factory method to create a GenericSearch object\n";
            GenericSearch* genSearch = this->FactoryMethod();
            std::cout << "next instruction: delete genSearch\n";

            std::string result = "returning this string as the result\n";
            delete genSearch;
            return result;
        }
};

/* Search Factories override the factory method to change the resulting search type
*/
class BFSFactory : public Factory 
{
    public:
        GenericSearch* FactoryMethod() const override
        {
            std::cout << "entering class BFSFactory function " << __FUNCTION__ << "\n";
            std::cout << "returning new BFS() object\n";
            return new BFS();
        }
};


class DFSFactory : public Factory 
{
    public:
        GenericSearch* FactoryMethod() const override
        {
            std::cout << "entering class DFSFatcory fucntion " << __FUNCTION__ << "\n";
            return new DFS();
        }
};

class AstarFactory : public Factory 
{
    public:
        GenericSearch* FactoryMethod() const override
        {
            std::cout << "entering class AstarFactory fucntion " << __FUNCTION__ << "\n";
            return new Astar();
        }
};


void ClientCode(const Factory* factory)
{
    std::cout << "entering function: " << __FUNCTION__
        << ", calling SearchOperation\n"
        << factory->SearchOperation() << std::endl;

    std::cout << "exiting function: " << __FUNCTION__ << "\n";
}

int main()
{
    std::cout << "Launching search application with BFS\n";
    Factory* factory = new BFSFactory();
    ClientCode(factory);
    std::cout << "calling delete factory from function: " << __FUNCTION__ << "\n";
    delete factory;
    factory = nullptr;
    std::cout << "\n";

    /*
    std::cout << "Lauching search application with DFS\n";
    factory = new DFSFactory();
    ClientCode(factory);
    delete factory;
    factory = nullptr;
    std::cout << "\n";

    std::cout << "Lauching search application with Astar\n";
    factory = new AstarFactory();
    ClientCode(factory);
    delete factory;
    factory = nullptr;
    std::cout << "\n";
    */

    return 0;
}
