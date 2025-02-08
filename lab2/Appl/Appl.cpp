#include <cstring>
#include "Appl.hpp"
#include <iostream>

using namespace std;

namespace appl{

    //Конструкторы & Деструктор (классика + 2.2 и 2.3 задания)

    Appl::Appl(){
        name = new char[1];
        name[0] = '\0';
        old = 0;
        staj = 0;
        zp = 0;
        id = 0;
    }

    Appl::Appl(const char* name_, int old_, int staj_, int zp_){
        name = new char[strlen(name_)+1];
        strcpy(name, name_);
        old = old_;
        staj = staj_;
        zp = zp_;

        total++; //увеличить счетчик объектов
        id = total; //id равен текущему значению total
        cout << "Создание ID " << id << endl;
    }

    Appl::Appl(const Appl &p){
        name = new char[strlen(p.name)+1];
        strcpy(name, p.name);
        old = p.old;
        staj = p.staj;
        zp = p.zp;
    }

    Appl::~Appl() {
        delete[] name;

        total--;

    }

    // Ниже описаны функции, возвращающие значения параметров планеты:

    char* Appl::getName() {
        return name;
    }
    int Appl::getOld() {
        return old;
    }
    int Appl::getStaj() {
        return staj;
    }
    int Appl::getTotal() {
        return total;
    }
    int Appl::getId(){
        return id;
    }
    int Appl::getZp() {
        return zp;
    }

    // Ниже описаны функции для изменения значений параметров планеты:

    void Appl::setName(const char* newName) {
        delete[] name;
        name = new char[strlen(newName)+1];
        std::strcpy(name, newName);
    }
    void Appl::setOld(int newOld) {
        old = newOld;
    }
    void Appl::setStaj(int newStaj) {
        staj = newStaj;
    }
    void Appl::setZp(int newZp) {
        zp = newZp;
    }
    void Appl::setId(){
        id = total;
    }
    void Appl::reduceTotal(){
        total -= 1;
    }
    void Appl::raiseTotal(){
        total += 1;
    }
    void Appl::clearmem(){
        delete[] name;
    }

    // Ниже описаны функции из задания 1.4:

    int Appl::FindApplId(Appl* arr, int curSize, const char* targetName)
    {
        for (int i = 0; i < curSize; i++){
            if (strcmp(arr[i].getName(), targetName) == 0){
                return arr[i].getId();
            }
        }
        return -1;
    }

    int Appl::readDbFromFileAppl(const char *filename, Appl *arr){

        ifstream fin(filename, ios::in);
        Appl::total = 0;
        if (!fin) {
            cout << "Heт файла " << filename << endl;
            return 1;
        }

        int count;
        fin >> count;

        if (count > 100) {
            std::cout << "Переполнение БД. Количество объектов в файле = " << count << std::endl;
            return 1;
        }

        for (int i = 0; i < count; i++){
            fin >> arr[i];
            Appl::raiseTotal();
            arr[i].setId();
        }

        fin.close();
        cout << "----------Файл " << filename << " успешно прочтён----------\n";
        return 0;
    }

    void Appl::writeDbToFileAppl(const char *filename, Appl* arr){
        int n = Appl::getTotal();
        ofstream fout;
        fout.open(filename, ios::binary);

        if (!fout) {
            cout << "Ошибка открытия файла" << std::endl;
            return;
        }

        fout << n;

        for (int i = 0; i < n; i++){
            fout << arr[i];
        }

        fout.close();
        cout << "----------БД успешно записана в файл----------\n";
    }

    void Appl::sortByNameAppl(Appl* arr){
        int curSize = Appl::getTotal();
        int cntr = 0;
        for (int i = 0; i < curSize; i++){
            for (int j = i + 1; j < curSize; j++){
                if (arr[i] > arr[j]){
                    swap(arr[i], arr[j]);
                    Appl::total += 1;
                }
            }
        }
        cout << "----------БД успешно отсортирована----------\n";
    }

    void Appl::addObjToDbAppl(Appl* arr, int maxSize){
        int curSize = Appl::getTotal();

        Appl tmp;
        std::cout << "Введите: ФИО (слитно), Возраст, стаж работы (кол-во полных лет), ожидаемую зарплату (руб)\n";
        std::cin >> tmp;
        if (curSize >= maxSize){
            std::cout << "База данных заполенена\n";
            return;
        }
        arr[curSize] = tmp;
cout<<"this is total before :"<<Appl::getTotal()<<endl;
        Appl::raiseTotal();
        cout<<"this is total:"<<Appl::getTotal()<<endl;
        arr[curSize].setId();
        cout<<"this is id6:"<<arr[5]<<endl;
        Appl::raiseTotal();

        cout << "----------Заявление успешно добавлен----------\n";
    }

    void Appl::deleteByNameAppl(Appl* arr){
        int curSize = Appl::getTotal();

        char targetName[100];
        cout << "Ведите ФИО (слитно) человека, чьё заявление хотите удалить";
        cin >> targetName;
        int targetId = Appl::FindApplId(arr, curSize, targetName);
        targetId -= 1;

        if (targetId == -1){
            cout << "Человек не найдена!\n";
            return;
        }

        for (int i = targetId; i < curSize; i++)
            arr[i] = arr[i+1];

        int idtoclear = Appl::getTotal();
        arr[idtoclear].clearmem();
        Appl::reduceTotal();

        cout << "Заявка " << targetName << " успешно удалена!\n";
    }

    void Appl::updateDbAppl(Appl* arr){
        char targetName[80];
        cout << "Введите ФИО (слитно) человека, чью заявку отредактировать";
        cin >> targetName;
        int curSize = Appl::getTotal();
        int targetId = Appl::FindApplId(arr, curSize, targetName);
        targetId -=1;
        if (targetId == -1){
            cout << "Заявление не найдено\n";
            return;
        }
        
        cout << "Введите фио(слитно), возраст, стаж, желаемую зп (на что заменить?)";
        char name[80];
        int old;
        int staj;
        int zp;
        cin >> name >> old >> staj >> zp;

        if (strcmp(name, "") != 0) { arr[targetId].setName(name); }
        if (old != -1) { arr[targetId].setOld(old); }
        if (staj != -1) { arr[targetId].setStaj(staj); }
        if (zp != -1) { arr[targetId].setZp(zp); }
        cout << "----------Заявление " << targetName << " успешно отредактировано----------\n";
    }

    void Appl::printDbAppl(Appl* arr){
        int n = Appl::getTotal();
        cout<<"this is new total:"<<n<<endl;
        cout << "   ФИО                                 | Возраст |  Стаж  | Ожидаемая зарплата|\n";
        cout << "---------------------------------------|---------|--------|-------------------|\n";
        for(int i = 0; i < n; i++){
            cout << i + 1 << ". " << arr[i].getName() << std::setw(30 - strlen(arr[i].getName()) + 9)
            << arr[i].getOld() << std::setw(11) << arr[i].getStaj() 
            << setw(12) << arr[i].getZp() << "  " << std::endl;
        }
        cout << '\n';
    }


    //Задание 2.2:

    Appl& Appl::operator = (const Appl& p2) { 
        if (this != &p2){
            delete[] this->name;
            this->name = new char[strlen(p2.name)+1];
            strcpy(this->name, p2.name);
            this->old = p2.old; 
            this->staj = p2.staj; 
            this->zp = p2.zp;
        }
        return *this;
    } 

    // Задание 2.4 и 2.5:

    ostream& operator << (ostream &out, const Appl& appl){
        out << appl.name << ' ' << appl.old << ' ' << appl.staj << ' ' << appl.zp << std::endl;
        return out;
    }

    istream& operator >> (istream &in,  Appl& appl){
        char tmp[50];
        in >> tmp >> appl.old >> appl.staj >> appl.zp;
        appl.setName (tmp);
        return in;
    }

    //Задание 3.1:

    bool operator < (const Appl& appl1, const Appl& appl2){
        return strcmp(appl1.name, appl2.name) < 0;
    }

    bool operator == (const Appl& appl1, const Appl& appl2){
        return strcmp(appl1.name, appl2.name) == 0;
    }

    //Задание 3.2:

    bool operator > (const Appl& appl1, const Appl& appl2){
        return strcmp(appl1.name, appl2.name) > 0;
    }
}