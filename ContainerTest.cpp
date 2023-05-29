#include "gtest/gtest.h"
#include "Containers.h"


// 1 вставка элементов в конец
TEST(ContainerTest, AddLastTest)
{
    SequentialContainer<int> container;

    container.add(0);
    container.add(1);
    container.add(2);

    int lastValue = 55;
    container.addLast(lastValue);

    EXPECT_EQ(container.size(), 4);
    EXPECT_EQ(container[container.size()-1], lastValue);
}

// 2 вставка элементов в начало
TEST(ContainerTest, AddFirstTest)
{
    SequentialContainer<int> container;

    container.add(0);
    container.add(1);
    container.add(2);

    int firstValue = 66;
    container.addFirst(firstValue);

    EXPECT_EQ(container.size(), 4);
    EXPECT_EQ(container[0], firstValue);
}

// 3 вставка элементов в середину
TEST(ContainerTest, AddMiddleTest)
{
    SequentialContainer<int> container;

    container.add(0);
    container.add(1);
    container.add(2);

    int middleValue = 66;
    int middle = container.size()/2;
    container.addMiddle(middleValue);

    EXPECT_EQ(container.size(), 4);
    EXPECT_EQ(container[middle], middleValue);
}

// 4 вставка элементов по индексу
TEST(ContainerTest, Insert)
{
    SequentialContainer<int> container;

    container.add(0);
    container.add(1);
    container.add(2);

    int value = 66;
    int index = 1;
    container.insert(index,value);

    EXPECT_EQ(container.size(), 4);
    EXPECT_EQ(container[index], value);
}

// 5 удаление элементов по индексу
TEST(ContainerTest, DeleteIndexTest)
{
    SequentialContainer<int> container;

    container.add(0);
    container.add(1);
    container.add(2);

    int delIndex = 1;
    container.removeAt(delIndex);

    EXPECT_EQ(container.size(), 2);
}

// 6 получение элемента по индексу
TEST(ContainerTest, IndexTest)
{
    SequentialContainer<int> container;

    int findData = 77;
    int index = 2;

    container.add(0);
    container.add(1);
    container.add(findData);
    container.add(3);
    container.add(4);

    EXPECT_EQ(container.size(), 5);
    EXPECT_EQ(container[index], findData);
}

// 7 получение элементов из контейнера
TEST(ContainerTest, ElementsTest)
{
    SequentialContainer<int> container;

    std::vector<int> elementsVector = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    size_t size = elementsVector.size();

    for ( auto element : elementsVector) {
        container.add(element);
    }


    EXPECT_EQ(container.size(), size);
    for ( size_t i = 0; i < container.size(); i++) {
        EXPECT_EQ(container[i], elementsVector[i]);
    }
}

// 8 получение размера контейнера (фактическое количество элементов)
TEST(ContainerTest, SizeTest)
{
    SequentialContainer<int> container;

    container.add(10);
    container.add(20);
    container.add(30);

    EXPECT_EQ(container.size(), 3);
}

// 9 копирование контейнера
TEST(ContainerTest, CopyTest)
{
    SequentialContainer<int> container;
    SequentialContainer<int> copyContainer;

    container.add(10);
    container.add(20);
    container.add(30);
    container.add(34);
    container.add(32);

    copyContainer = container;

    EXPECT_EQ(container.size(), copyContainer.size());
    for (int i = 0; i < container.size(); i++) {
        EXPECT_EQ(container[i], copyContainer[i]);
    }
}

// 10 удаление элементов из конца
TEST(ContainerTest, DeleteLastTest)
{
    SequentialContainer<int> container;

    container.add(0);
    container.add(1);
    container.add(2);
    container.add(22);
    container.add(54);
    container.add(34);

    container.removeLast();

    EXPECT_EQ(container.size(), 5);
}
