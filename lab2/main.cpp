#include <iostream>
#include <fstream>
#include "Planet/Planet.hpp"
#include "Appl/Appl.hpp"

using namespace std;
using namespace planet;
using namespace appl;

int menu() {
    std::cout << " --------------------- МЕНЮ ---------------------\n";
    std::cout << "1 - чтение БД из файла" << std::endl;
    std::cout << "2 - запись БД в файл" << std::endl;
    std::cout << "3 - сортировка БД" << std::endl;
    std::cout << "4 - добавление нового объекта в БД" << std::endl;
    std::cout << "5 - удаление объекта из БД" << std::endl;
    std::cout << "6 - редактирование элементы объекта БД" << std::endl;
    std::cout << "7 - вывод БД на экран" << std::endl;
    std::cout << "8 - выход" << std::endl;
    std::cout << "Введите номер команды от 1 до 8:" << std::endl;
    int choicemenu;
    std::cin >> choicemenu;
    std::cin.clear();
    std::cin.ignore(10, '\n');
    return choicemenu;
}

int Planet::total = 0;
int Appl::total = 0;

int main(){
    int maxtotal = 2;
    Planet* planetsArray = new Planet[maxtotal];
    
    cout << "\n";
    cout << "----------Начинаем чтение из файла----------\n";
    cout << "\n";
    Planet::readDbFromFile("sourcePlanet.txt", planetsArray, maxtotal);
    cout << "\n";
    Planet::printDb(planetsArray);

    cout << "----------Добавляем объект----------\n";
    Planet::addObjToDB(planetsArray, maxtotal, "Venus", 12103, 0, 0, maxtotal);
    cout << "\n";
    Planet::printDb(planetsArray);

    cout << "----------Удаляем объект----------\n";
    cout << "\n";
    Planet::deleteByName(planetsArray, "Earth", maxtotal);
    cout << "\n";
    Planet::printDb(planetsArray);

    cout << "----------Добавляем планету----------\n";
    Planet::addObjToDB(planetsArray, maxtotal, "Earth2", 12742*2, 1, 1*2, maxtotal);
    cout << "\n";
    Planet::printDb(planetsArray);

    cout << "----------Редактируем объект----------\n";
    cout << "\n";
    Planet::updateDb(planetsArray, "Mars", "Mars_updated", 10, 1, -1);
    cout << "\n";
    Planet::printDb(planetsArray);

    cout << "----------Сортируем БД----------\n\n";
    Planet::sortByName(planetsArray);
    cout << "\n";
    Planet::printDb(planetsArray);

    cout << "----------Записываем БД в файл----------\n";
    cout << "\n";
    Planet::writeDbToFile("resultPlanet.txt", planetsArray);

    cout << "\n\n";

    cout << "\n\nИнтерактивное взаимодействие с классом 'Заявки на выполнение работ'\n\n";
    const int maxtotalappl = 100;
    Appl* applArray = new Appl[maxtotalappl];

    while (true) {
        switch (menu()) {
            case 1: 
            Appl::readDbFromFileAppl("sourceAppl.txt", applArray);
                break; 
            case 2: 
            Appl::writeDbToFileAppl("resulAppl.txt", applArray);
                break;
            case 3:
            Appl::sortByNameAppl(applArray);
                break;
            case 4:
            Appl::addObjToDbAppl(applArray, maxtotalappl);
                break; 
            case 5:
            Appl::deleteByNameAppl(applArray);
                break;
            case 6:
            Appl::updateDbAppl(applArray);
                break;
            case 7:
            Appl::printDbAppl(applArray);
                break;
            case 8:
                return 0;
            default:
                cout << " Недопустимый номер операции!" << endl;
                break;
        }
    }

    return 0;
}