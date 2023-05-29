#ifndef CONTAINERS_H
#define CONTAINERS_H

#include <iostream>
#include <vector>

/// ##############################################################
/// @class SequentialContainer; Последовательный контейнер
/// ##############################################################
template<typename T>
class SequentialContainer
{
public:    
    SequentialContainer() {}

    void add(const T& element) { data.push_back(element); }                                  // Добавление элемента в контейнер
    void addFirst(const T& element) { data.insert(data.begin(), element); }                  // Добавление элемента в начало контейнера
    void addMiddle(const T& element) { data.insert(data.begin() + data.size()/2, element); } // Добавление элемента в середину контейнера
    void addLast(const T& element) { data.push_back(element); }                              // Добавление элемента в конец контейнера
    void insert(int index, const T& element) { data.insert(data.begin() + index, element); } // Добавление элемента по индексу контейнера

    int size() const { return data.size(); }                     // Получение размера контейнера
    T& operator[](int index) { return data[index]; }             // Перегруженный оператор доступа по индексу
    const T& operator[](int index) const { return data[index]; } // Перегруженный константный оператор доступа по индексу

    void removeAt(int index) { if (index >= 0 && index < data.size()) data.erase(data.begin() + index); } // Удаление элемента по индексу
    void removeLast() { data.pop_back(); }                                                                // Удаление последнего элемента

    // Метод вывода всех элементов контейнера
    void print() const
    {
        for (const auto& element : data) {
            std::cout << element << " ";
        }
        std::cout << std::endl;
    }

private:
    std::vector<T> data;
};


/// ##############################################################
/// @class ListContainer; Контейнер спискового типа
/// ##############################################################
template<typename T>
class ListContainer
{
public:
    ListContainer(const T& value) : data(value), next(nullptr) {}

    T data;
    ListContainer<T>* next;

};

template <typename T>
class LinkedListContainer {
private:
    ListContainer<T>* head;
    int length;

public:
    LinkedListContainer() : head(nullptr), length(0) {}

    // Добавление элемента в контейнер
    void add(const T& value) {
        ListContainer<T>* newNode = new ListContainer<T>(value);
        if ( head == nullptr ) {
            head = newNode;
        } else {
            ListContainer<T>* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
        length++;
    }

    // Добавление элемента в начало списка
    void addFirst(const T& value) {
        ListContainer<T>* newNode = new ListContainer<T>(value);
        newNode->next = head;
        head = newNode;
        length++;
    }

    // Добавление элемента в середину списка
    void addMiddle(const T& value) {
        if (length % 2 == 0) {
            insert(length / 2, value);
        } else {
            insert(length / 2 + 1, value);
        }
    }

    // Добавление элемента в конец списка
    void addLast(const T& value) {
        ListContainer<T>* newNode = new ListContainer<T>(value);
        if (head == nullptr) {
            head = newNode;
        } else {
            ListContainer<T>* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
        length++;
    }

    // Вставка элемента на заданную позицию
    void insert(int index, const T& value) {
        if (index < 0 || index > length) {
            return;
        }
        if (index == 0) {
            addFirst(value);
            return;
        }
        ListContainer<T>* newNode = new ListContainer<T>(value);
        ListContainer<T>* current = head;
        for (int i = 0; i < index - 1; i++) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
        length++;
    }

    // Удаление элемента по значению
    void remove(const T& value) {
        if (head == nullptr) {
            return;
        }
        if (head->data == value) {
            ListContainer<T>* temp = head;
            head = head->next;
            delete temp;
            length--;
            return;
        }
        ListContainer<T>* current = head;
        while (current->next != nullptr && current->next->data != value) {
            current = current->next;
        }
        if (current->next != nullptr) {
            ListContainer<T>* temp = current->next;
            current->next = current->next->next;
            delete temp;
            length--;
        }
    }

    // Получение размера списка
    int size() const {
        return length;
    }

    // Метод вывода всех элементов списка
    void print() const {
        ListContainer<T>* current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};
#endif // CONTAINERS_H
