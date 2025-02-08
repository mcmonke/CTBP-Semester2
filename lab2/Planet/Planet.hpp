#include <fstream>
//using namespace std;

namespace planet {
    class Planet {
        private:
            char* name;
            int diamiter;
            int life;
            int satelites;
            static int total;
            int id;
            
        public:
            Planet();
            Planet(const char* newName, int diamiter, int life, int satelites);
            Planet(const Planet &p);
            ~Planet();
            
            char* getName();
            int getDiamiter();
            int getLife();
            int getSatelites();
            static int getTotal();
            int getId();
            void setName(const char* newName);
            void setDiamiter(int newDiamiter);
            void setLife(int newLife);
            void setSatelites(int newSatelites);
            void setId();
            void changeId(int id_);
            static void reduceTotal();
            static void raiseTotal();
            void clearmem();

            static int FindPlanetId(Planet* arr, int curSize, const char* targetName);
            static int readDbFromFile(const char *filename, Planet *&arr, int& maxtotal);
            static void writeDbToFile(const char *filename, Planet* arr);
            static void sortByName(Planet* arr);
            static void addObjToDB(Planet*& arr, int maxSize, const char* name, int diamiter, int life, int satelites, int& maxtotal);
            static void deleteByName(Planet*& arr, const char* targetName, int& maxtotal);
            static void updateDb(Planet* arr, const char* targetName, const char* name, int diamiter, int life, int satelites);
            static void printDb(Planet* arr);

            Planet& operator = (const Planet& p2);
            friend std::ostream& operator << (std::ostream& out, const Planet& planet);
            friend std::istream& operator >> (std::istream& in,  Planet& planet);
            friend bool operator < (const Planet& planet1, const Planet& planet2);
            friend bool operator > (const Planet& planet1, const Planet& planet2);
            friend bool operator == (const Planet& planet1, const Planet& planet2);
    };
}