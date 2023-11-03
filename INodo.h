#include <iostream>
#include <string>
using namespace std;

class INodo {
    public:
        int getId() {
            return id;
        }

        void setId(int pId) {
            this->id = pId;
        }
        
    protected:
        int id;
};

