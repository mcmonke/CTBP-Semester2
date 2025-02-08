#include <fstream>
using namespace std;

namespace appl {
    class Appl {
        private:
            char* name;
            int old;
            int staj;
            int zp;
            static int total;
            int id;
            
        public:
            Appl();
            Appl(const char* newName, int old, int staj, int zp);
            Appl(const Appl &p);
            ~Appl();
            
            char* getName();
            int getOld();
            int getStaj();
            int getZp();
            static int getTotal();
            int getId();
            void setName(const char* newName);
            void setOld(int newOld);
            void setStaj(int newStaj);
            void setZp(int newZp);
            void setId();
            static void reduceTotal();
            static void raiseTotal();
            void clearmem();

            static int FindApplId(Appl* arr, int curSize, const char* targetName);
            static int readDbFromFileAppl(const char *filename, Appl *arr);
            static void writeDbToFileAppl(const char *filename, Appl* arr);
            static void sortByNameAppl(Appl* arr);
            static void addObjToDbAppl(Appl* arr, int maxSize);
            static void deleteByNameAppl(Appl* arr);
            static void updateDbAppl(Appl* arr);
            static void printDbAppl(Appl* arr);

            Appl& operator = (const Appl& p2);
            friend ostream& operator << (ostream& out, const Appl& appl);
            friend istream& operator >> (istream& in,  Appl& Appl);
            friend bool operator < (const Appl& appl1, const Appl& appl2);
            friend bool operator > (const Appl& appl1, const Appl& appl2);
            friend bool operator == (const Appl& appl1, const Appl& appl2);
    };
}