#include <cstring>
#include "Planet.hpp"
#include <iostream>
#include <string.h>

using namespace std;

namespace planet{

    //Конструкторы & Деструктор (классика + 2.2 и 2.3 задания)

    Planet::Planet(){
        name = new char[1];
        name[0] = '\0';
        diamiter = 0;
        life = 0;
        satelites = 0;
        id = 0;
    }

    Planet::Planet(const char* Name_, int diamiter_, int life_, int satelites_){
        name = new char[strlen(Name_)+1];
        strcpy(name, Name_);
        diamiter = diamiter_;
        life = life_;
        satelites = satelites_;

        total++; //увеличить счетчик объектов
        id = total; //id равен текущему значению total
    }

    Planet::Planet(const Planet &p){
        name = new char[strlen(p.name)+1];
        strcpy(name, p.name);
        diamiter = p.diamiter;
        life = p.life;
        satelites = p.satelites;
        id=p.id;
    }

    Planet::~Planet() {
        delete[] name;
        if (id != 0){
            total--; //уменьшить счетчик объектов
        }
    }

    // Ниже описаны функции, возвращающие значения параметров планеты:

    char* Planet::getName() {
        return name;
    }
    int Planet::getDiamiter() {
        return diamiter;
    }
    int Planet::getLife() {
        return life;
    }
    int Planet::getTotal() {
        return total;
    }
    int Planet::getId(){
        return id;
    }
    int Planet::getSatelites() {
        return satelites;
    }

    // Ниже описаны функции для изменения значений параметров планеты:

    void Planet::setName(const char* newName) {
        delete[] name;
        name = new char[strlen(newName)+1];
        std::strcpy(name, newName);
    }
    void Planet::setDiamiter(int newDiamiter) {
        diamiter = newDiamiter;
    }
    void Planet::setLife(int newLife) {
        life = newLife;
    }
    void Planet::setSatelites(int newSatelites) {
        satelites = newSatelites;
    }
    void Planet::setId(){
        id = total;
    }
    void Planet::changeId(int id_){
        id = id_;
    }
    void Planet::reduceTotal(){
        total -= 1;
    }
    void Planet::raiseTotal(){
        total += 1;
    }
    void Planet::clearmem(){
        delete[] name;
    }

    // Ниже описаны функции из задания 1.4:

    int Planet::FindPlanetId(Planet* arr, int curSize, const char* targetName)
    {
        for (int i = 0; i < curSize; i++){
            if (strcmp(arr[i].getName(), targetName) == 0){
                return arr[i].getId();
            }
        }
        return -1;
    }

    int Planet::readDbFromFile(const char *filename, Planet *& arr, int& maxtotal){

        ifstream fin(filename, ios::in);
        if (!fin) {
            cout << "Heт файла " << filename << endl;
            return 1;
        }

        int count;
        fin >> count;
        int buf=maxtotal;

        while(count >= maxtotal) {
            maxtotal*=2;
        }
        delete[] arr;
        arr = new Planet [maxtotal];

        for (int i = 0; i < count; i++){
            fin >> arr[i];
            Planet::raiseTotal();
            arr[i].setId();
        }

        fin.close();
        cout << "----------Файл " << filename << " успешно прочтён----------\n";
        return 0;
    }

    void Planet::writeDbToFile(const char *filename, Planet* arr){
        int n = Planet::getTotal();
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

    void Planet::sortByName(Planet* arr){
        int curSize = Planet::getTotal();
        for (int i = 0; i < curSize; i++){
            for (int j = i + 1; j < curSize; j++){
                if (arr[i] > arr[j]){
                    swap(arr[i], arr[j]);
                    Planet::raiseTotal();
                }
            }
        }
        cout << "----------БД успешно отсортирована----------\n";
    }

    void Planet::addObjToDB(Planet*& arr, int maxSize, const char* name, int diamiter, int life, int satelites, int& maxtotal){
        int curSize = Planet::getTotal();

        int buf=maxtotal;

        while(Planet::getTotal() >= maxtotal) {
            maxtotal*=2;
        }
        Planet* tempr = new Planet [buf];
        for (int i = 0; i < buf; i++){
            tempr[i] = arr[i];
            tempr[i].changeId(arr[i].getId());
            if(tempr[i].getId()!=0){
                Planet::raiseTotal();
            }
        }

        delete[] arr;
        arr = new Planet [maxtotal];
        for (int i = 0; i < buf; i++){
            arr[i] = tempr[i];
            arr[i].changeId(tempr[i].getId());
            if(arr[i].getId()!=0){
                Planet::raiseTotal();
            }
        }
        delete[] tempr;

        arr[curSize] = Planet(name, diamiter, life, satelites);
        Planet::total += 1;
        arr[curSize].setId();
        cout << "----------Объект " << name << " успешно добавлен----------\n";
    }

    void Planet::deleteByName(Planet*& arr, const char* targetName, int& maxtotal){
        int curSize = Planet::getTotal();
        int targetId = Planet::FindPlanetId(arr, curSize, targetName);
        targetId -= 1;
        if (targetId == -1){
            cout << "Планета не найдена!\n";
            return;
        }

        for (int i = targetId; i < curSize; i++){
            arr[i] = arr[i+1];
        }
        
        arr[Planet::getTotal()].changeId(0);
        Planet::reduceTotal();

        int buf=maxtotal;

        while((Planet::getTotal()*2) < maxtotal) {
            maxtotal = (maxtotal/2)+1;
        }

        Planet* tempr = new Planet [buf];
        for (int i = 0; i < buf; i++){
            tempr[i] = arr[i];
            tempr[i].changeId(arr[i].getId());
            if(tempr[i].getId()!=0){
                Planet::raiseTotal();
            }
        }
        delete[] arr;
        
        arr = new Planet [maxtotal];
        for (int i = 0; i < maxtotal; i++){
            arr[i] = tempr[i];
            arr[i].changeId(tempr[i].getId());
            if(arr[i].getId()!=0){
                Planet::raiseTotal();
            }
        }
        delete[] tempr;

        cout << "Планета " << targetName << " успешно удалена!\n";
    }

    void Planet::updateDb(Planet* arr, const char* targetName, const char* name = "", int diamiter = -1, int life = -1, int satelites = -1){
        int curSize = Planet::getTotal();
        int targetId = Planet::FindPlanetId(arr, curSize, targetName);
        targetId -=1;
        if (targetId == -1){
            cout << "Планета не найдена\n";
            return;
        }

        if (strcmp(name, "") != 0) { arr[targetId].setName(name); }
        if (diamiter != -1) { arr[targetId].setDiamiter(diamiter); }
        if (life != -1) { arr[targetId].setLife(life); }
        if (satelites != -1) { arr[targetId].setSatelites(satelites); }
        cout << "----------Объект " << targetName << " успешно отредактирован----------\n";
    }

    void Planet::printDb(Planet* arr){
        int n = Planet::getTotal();
        cout << "   Название    | Диаметр | Жизнь | Спутники |\n";
        cout << "---------------|---------|-------|----------|\n";
        for(int i = 0; i < n; i++){
            cout << i + 1 << ". " << arr[i].getName() << std::setw(15 - strlen(arr[i].getName()) + 6)
            << arr[i].getDiamiter() << std::setw(8) << arr[i].getLife() 
            << setw(11) << arr[i].getSatelites() << "  " << std::endl;
        }
        cout << '\n';
    }


    //Задание 2.2:

    Planet& Planet::operator = (const Planet& p2) { 
        if (this != &p2){
            delete[] this->name;
            this->name = new char[strlen(p2.name)+1];
            strcpy(this->name, p2.name);
            this->diamiter = p2.diamiter; 
            this->life = p2.life; 
            this->satelites = p2.satelites;
        }
        return *this;
    } 

    // Задание 2.4 и 2.5:

    ostream& operator << (ostream &out, const Planet& planet){
        out << planet.name << ' ' << planet.diamiter << ' ' << planet.life << ' ' << planet.satelites << endl;
        return out;
    }

    istream& operator >> (istream &in,  Planet& planet){
        char tmp[50];
        in >> tmp >> planet.diamiter >> planet.life >> planet.satelites;
        planet.setName (tmp);
        return in;
    }

    //Задание 3.1:

    bool operator < (const Planet& planet1, const Planet& planet2){
        return strcmp(planet1.name, planet2.name) < 0;
    }

    bool operator == (const Planet& planet1, const Planet& planet2){
        return strcmp(planet1.name, planet2.name) == 0;
    }

    //Задание 3.2:

    bool operator > (const Planet& planet1, const Planet& planet2){
        return strcmp(planet1.name, planet2.name) > 0;
    }
}