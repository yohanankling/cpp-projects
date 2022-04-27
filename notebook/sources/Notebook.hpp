#include <iostream>
#include<unordered_map>
#include "string"
#include "Direction.hpp"
using namespace std;
using namespace ariel;
namespace ariel {
    class Notebook {
        private:
        unordered_map<int,unordered_map<int,char[100]>>notebook;
        unordered_map<int,int>max;
    public:
            Notebook() {}
                void write(int page, int row, int column, ariel::Direction, string phrases);

                string read(int page, int row, int column, ariel::Direction, int length);

                void erase(int page, int row, int column, ariel::Direction, int length);

                void show(int page);

            ~Notebook() = default;;
    };
}