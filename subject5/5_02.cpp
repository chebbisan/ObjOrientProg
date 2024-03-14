#include <iostream>
#include <cstdlib>

/*
Создайте структуру Container, отражающую массив указателей и
содержащую следующие данные (элементом контейнера является структура из 3.1.)
{
    Указатель на первый элемент
    Размер контейнера
    Количество текущих элементов
}
Создайте следующие функции:
1. Увеличение размера массива в два раза с сохранением текущих элементов
и количества текущих элементов //void resize(Containter*)
2. Добавление элемента в конейнер // void push_back(Elem)
3. Удаление элемента из контенера // void erase(unsigned int index)
*/

struct StudentAssessment {
    char name[50];
    char date[20];
    int mark;
};


struct Container {
    StudentAssessment** head;
    size_t capacity;
    size_t size;
};

void resize(Container* c) {
    size_t new_capacity = c->capacity * 2;
    StudentAssessment** new_head = new StudentAssessment*[new_capacity];
    for (size_t i = 0; i < c->size; ++i) {
        new_head[i] = c->head[i];
    }
    delete[] c->head;
    c->head = new_head;
}

void push_back(Container* c, StudentAssessment* elem) {
    if (c->size == c->capacity) {
        resize(c);
    }
    c->head[c->size] = elem;
    c->size += 1;
}

void erase(Container* c, size_t index) {
    if (index > c->size) {
        return;
    }
    c->head[index] = nullptr;
    c->size -= 1;
}

void make_container(Container* c) {
    c->capacity = 2;
    c->size = 0;
    c->head = new StudentAssessment*[c->capacity];
}

void delete_container(Container* c) {
    c->capacity = 0;
    c->size = 0;
    delete[] c->head;
}
