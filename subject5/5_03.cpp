#include <cstdlib>
#include <iostream>

/*
Модернизируйте структуру из 3.1. так, чтобы она представляла
собой элемент однонаправленного связного списка. Реализуйте те же функции,
что и в 3.2., но для связного списка.
*/

struct StudentList {
    char* name;
    char* date;
    int mark;
    StudentList* next;
};


void push_back(StudentList* sl, StudentList* elem) {
    sl->next = elem;
}

StudentList* top(StudentList* sl) {
    StudentList* current = sl;
    while (current->next != nullptr) {
        current = current->next;
    }
    return current;
}

void pop(StudentList*& sl) { // удаляет первый элемент
    StudentList* current = sl;
    sl = sl->next;
    delete[] current->name;
    delete[] current->date;
    delete current;
}

void delete_list(StudentList* sl) {
    StudentList* current = sl;
    StudentList* nextStudent;

    while (current != nullptr) {
        nextStudent = current->next;
        if (current->date) 
            delete[] current->date;
        if (current->name)
            delete[] current->name;
        delete current;
        current = nextStudent;
    }
    sl = nullptr;
}

void print(StudentList* sl) {
    StudentList* current = sl;
    std::cout << "Student list (name, mark, date):\n";
    while (current != nullptr) {
        std::cout << current->name << ' ' << current->mark << ' ' << current->date << '\n';
        current = current->next;
    }
    std::cout << '\n';
}

int main() {
    StudentList* diary = new StudentList;
    diary->name = new char[5]{"Ilya"};
    diary->date = new char[11]{"01.01.1970"};
    diary->mark = 5;
    diary->next = nullptr;

    StudentList* scnd = new StudentList;
    scnd->name = new char[5]{"Dima"};
    scnd->date = new char[11]{"01.01.1970"};
    scnd->mark = 6;
    scnd->next = nullptr;

    push_back(diary, scnd);
    print(diary);

    
    pop(diary);
    print(diary);
    pop(diary);

    delete_list(diary);
    return 0;
}