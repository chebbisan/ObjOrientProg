#include <cstdlib>
#include <iostream>

/*
Создайте программу, которая позволяет осуществлять
взаимодействия с оценками из 3.1., а именно:
1. Добавлять записи //push_back
2. Добавлять записи по заданному индексу //insert
3. Удалять записи //erase
4. Редактировать записи //void edit
5. Перемещать запись по заданному индексу //move
6. Менять местами две записи //swap
7. Сортировать записи по ФИО //sortName
8. Сортировать записи по дате //sortDate
9. Отображать весь список //display
10.Отображать список по запросу (только по определенному имени/дате)
//displaySelName, displaySelDate
Если у вас четный номер по списку группы, то программа реализуется на основе
массива указателей. Если у вас нечетный номер по списку группы, то
программа реализуется на основе связного списка.
*/

struct StudentList {
    char* name;
    char* date;
    int mark;
    StudentList* next;
};


void push_back(StudentList*& sl, StudentList* elem) {
    StudentList* current = sl;
    while (current->next != nullptr) {
        current = current->next;
    }
    current->next = elem;
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

void display(StudentList* sl) {
    StudentList* current = sl;
    std::cout << "Student list (name, mark, date):\n";
    while (current != nullptr) {
        std::cout << current->name << ' ' << current->mark << ' ' << current->date << '\n';
        current = current->next;
    }
    std::cout << '\n';
}

void insert(StudentList*& sl, StudentList* elem, size_t index) {
    if (index == 0) {
        elem->next = sl;
        sl = elem;
        return;
    }
    StudentList* tmp = sl;
    for (size_t i = 1; i < index && tmp->next != nullptr; ++i) {
        tmp = tmp->next;
    }

    StudentList* after = nullptr;
    if (tmp->next != nullptr) {
        after = tmp->next;
    }
    tmp->next = elem;
    elem->next = after;
}

void erase(StudentList*& sl, size_t index) {
    if (index == 0) {
        StudentList* to_del = sl;
        sl = sl->next;
        delete[] to_del->date;
        delete[] to_del->name;
        delete to_del;
        return;
    }

    StudentList* tmp = sl;
    for (size_t i = 1; i < index && tmp->next->next != nullptr; ++i) {
        tmp = tmp->next;
    }

    StudentList* to_del = tmp->next;
    tmp->next = tmp->next->next;
    
    delete[] to_del->date;
    delete[] to_del->name;
    delete to_del;
}

void edit(StudentList*& sl, size_t index) {
    if (index == 0) {
        char opt;
        std::cout << "Choose field to edit:\tn - name, m - mark, d - date\n";
        std::cin >> opt;
        switch (opt)
        {
        case 'n':
            std::cout << "Write a new name:\n";
            std::cin >> sl->name;
            break;
        case 'm':
            std::cout << "Write a new mark:\n";
            std::cin >> sl->mark;
            break;
        case 'd':
            std::cout << "Write a new date:\n";
            std::cin >> sl->date;
            break;
        default:
            std::cout << "Unknown field\n";
            break;
        }
        std::cout << '\n';
        return;
    }

    StudentList* tmp = sl;
    for (size_t i = 1; i < index && tmp->next->next != nullptr; ++i) {
        tmp = tmp->next;
    }

    char opt;
    std::cout << "Choose field to edit:\tn - name, m - mark, d - date\n";
    std::cin >> opt;
    switch (opt)
    {
    case 'n':
        std::cout << "Write a new name:\n";
        std::cin >> tmp->name;
        break;
    case 'm':
        std::cout << "Write a new mark:\n";
        std::cin >> tmp->mark;
        break;
    case 'd':
        std::cout << "Write a new date:\n";
        std::cin >> tmp->date;
        break;
    default:
        std::cout << "Unknown field\n";
        break;
    }
    std::cout << '\n';
}

void sort_date(StudentList*& sl);

void sort_name(StudentList*& sl);

void swap(size_t indexA, size_t indexB);

void displayName(StudentList* sl) {
    StudentList* current = sl;
    std::cout << "Student list (name, mark, date):\n";
    while (current != nullptr) {
        std::cout << current->name << '\n';
        current = current->next;
    }
    std::cout << '\n';
}

void displayDate(StudentList* sl) {
    StudentList* current = sl;
    std::cout << "Student list (name, mark, date):\n";
    while (current != nullptr) {
        std::cout << current->date << '\n';
        current = current->next;
    }
    std::cout << '\n';
}

int main() {
    StudentList* diary = new StudentList;
    diary->name = new char[25]{"Ilya"};
    diary->date = new char[11]{"01.01.1970"};
    diary->mark = 5;
    diary->next = nullptr;

    StudentList* scnd = new StudentList;
    scnd->name = new char[25]{"Dima"};
    scnd->date = new char[11]{"01.01.1970"};
    scnd->mark = 6;
    scnd->next = nullptr;

    StudentList* thrd = new StudentList;
    thrd->name = new char[25]{"Foo"};
    thrd->date = new char[11]{"01.01.1970"};
    thrd->mark = 7;
    thrd->next = nullptr;

    StudentList* frth = new StudentList;
    frth->name = new char[25]{"Bar"};
    frth->date = new char[11]{"01.01.1970"};
    frth->mark = 8;
    frth->next = nullptr;

    push_back(diary, scnd);
    push_back(diary, thrd);
    push_back(diary, frth);
    display(diary);

    erase(diary, 0);
    display(diary);

    delete_list(diary);
    return 0;
}
