#include <iostream>

#include "Containers.h"

using namespace std;

int main()
{
    // Последовательный контейнер
    {
        std::cout << "SequentialContainer" << endl;
        // создание объекта контейнера для хранения объектов типа int
        SequentialContainer<int> container;
        // добавление в контейнер десяти элементов (0, 1 … 9)
        container.add(0);
        container.add(1);
        container.add(2);
        container.add(3);
        container.add(4);
        container.add(5);
        container.add(6);
        container.add(7);
        container.add(8);
        container.add(9);

        // вывод содержимого контейнера на экран
        std::cout << "Container elements: ";
        container.print();

        // удаление третьего (по счёту), пятого и седьмого элементов
        container.removeAt(2);
        container.removeAt(4);
        container.removeAt(6);
        // вывод содержимого контейнера на экран
        std::cout << "Container remove index 3,5,7; elements: ";
        container.print();

        // добавление элемента 10 в начало контейнера
        std::cout << "Container addFirst 10; elements: ";
        container.addFirst(10);
        container.print();

        // добавление элемента 20 в середину контейнера
        std::cout << "Container addMiddle 20; elements: ";
        container.addMiddle(20);
        container.print();

        // добавление элемента 30 в конец контейнера
        std::cout << "Container addLast 30; elements: ";
        container.addLast(30);
        container.print();

        // добавление элемента 100 по индексу 3
        std::cout << "Container insert 100 at 3 index; elements: ";
        container.insert(3, 100);
        container.print();

        // вывод элимента
        std::cout << "Element at index 5; element: " << container[5] << std::endl;

        // удаление последнего элемента
        std::cout << "Container remove last; Elements: ";
        container.removeLast();
        container.print();

        // вывод размера контейнера на экран
        std::cout << "Container size: " << container.size() << std::endl;
    }

    std::cout << "-----------------------------------------------------------" << endl;

    // Контейнер спискового типа
    {        
        // создание объекта контейнера для хранения объектов типа int
        LinkedListContainer<int> container;
        // добавление в контейнер десяти элементов (0, 1 … 9)
        container.add(0);
        container.add(1);
        container.add(2);
        container.add(3);
        container.add(4);
        container.add(5);
        container.add(6);
        container.add(7);
        container.add(8);
        container.add(9);

        // вывод содержимого контейнера на экран
        std::cout << "Container elements: ";
        container.print();

        // удаление третьего (по счёту), пятого и седьмого элементов
        container.remove(3);
        container.remove(5);
        container.remove(7);
//         вывод содержимого контейнера на экран
        std::cout << "Container remove value 3,5,7; elements: ";
        container.print();

        // добавление элемента 10 в начало контейнера
        std::cout << "Container addFirst 10; elements: ";
        container.addFirst(10);
        container.print();

        // добавление элемента 20 в середину контейнера
        std::cout << "Container addMiddle 20; elements: ";
        container.addMiddle(20);
        container.print();

        // добавление элемента 30 в конец контейнера
        std::cout << "Container addLast 30; elements: ";
        container.addLast(30);
        container.print();

        // добавление элемента 100 по индексу 3
        std::cout << "Container insert 100 at 3 index; elements: ";
        container.insert(3, 100);
        container.print();

        // вывод размера контейнера на экран
        std::cout << "Container size: " << container.size() << std::endl;
    }
    return 0;
}
