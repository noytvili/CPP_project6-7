#include <iostream>
using namespace std;

class Pair{
    private:
        int i;
        int j;
        
    public:
        Pair(int x, int y);
        int get_i();
        int get_j();
        Pair& operator= (const Pair& p);
};
