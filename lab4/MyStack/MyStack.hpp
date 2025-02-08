// Файл MyStack.h
// Шаблонный класс MyStack на основе односвязного списка.
#ifndef MyStack_h  // защита от повторной компиляции
#define MyStack_h  // модуль подключен
#include <iostream>

// Шаблонный класс ListNode (узел односвязного списка)
template <class INF, class FRIEND>
class ListNode {  // узел списка
   private:
    INF d;                              // информационная часть узла
    ListNode *next;                     // указатель на следующий узел списка
    ListNode(void) { next = nullptr; }  // конструктор
    friend FRIEND;
};

// Шаблонный класс MyStack на основе односвязного списка.
template <class INF>
class MyStack {
    typedef class ListNode<INF, MyStack<INF> > Node;
    Node *top;

   public:
    MyStack(void) {                             //Конструктор (Стандартный)
        top = nullptr;
    }

    ~MyStack(void) {                            //Деконструктор с очисткой памяти
        while (!empty()) {
            pop();
        }
    }

    bool empty(void) {                          //Булка, отвечающая на вопрос "Стек пустой?"
        return top == nullptr;
    }

    MyStack(const MyStack &p) {                 //Конструктор, копирующий существующий стек
        top = nullptr;
        MyStack<INF> tmp1;
        Node *tmpNode = p.top;

        while (tmpNode) {
            tmp1.push(tmpNode->d);
            tmpNode = tmpNode->next;
        }

        while (!tmp1.empty()) {
            push(tmp1.top_inf());
            tmp1.pop();
        }
    }


    friend std::ostream& operator<< (std::ostream &out,MyStack &p) {    //Перегрузка оператора "<<"
        while (!(p.empty())) {
            out << p.top_inf();
            p.pop();
            if (!p.empty()) {
                std::cout << " * ";
            }
        }
        return out;
    }

    MyStack &operator=(const MyStack &p2) {     //Перегрузка оператора "="

        while (!(this->empty())) {
            this->pop();
        }

        MyStack<INF> tmp1;
        Node *tmpNode = p2.top;

        while (tmpNode) {
            tmp1.push(tmpNode->d);
            tmpNode = tmpNode->next;
        }

        top = nullptr;
        while (!tmp1.empty()) {
            this->push(tmp1.top_inf());
            tmp1.pop();
        }
        return *this;
    }

    void push(INF n) {                          //Добавление узла в вершину стека
        Node *temp = new Node;
        temp->d = n;
        temp->next = top;
        top = temp;
    }

    void pop(void) {                            //Удаление узла из вершины стека
        if (empty()) {
            std::cout << "Стек пуст, невозможно получить значение!" << std::endl;
            return;
        } else {
            Node *temp;
            temp = top;
            top = top->next;
            delete temp;
        }
    }

    INF top_inf(void) {                         //Данные узла из вершины стека
        if (empty()) {
            std::cout << "Стек пустой" << std::endl;
            return -1;
        }
        return top->d;
    }
};

#endif