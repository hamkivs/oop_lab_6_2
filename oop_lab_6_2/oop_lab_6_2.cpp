#include <iostream>
#include <string>
#include <vector>

// Шаблонний клас для послідовного пошуку
template <typename T>
class SequentialSearch {
private:
    std::vector<T> array; // Масив даних
public:
    // Конструктор для ініціалізації масиву
    SequentialSearch(const std::vector<T>& arr) : array(arr) {}

    // Функція для виконання пошуку
    void findAndPrint(const T& key) const {
        bool found = false;

        for (size_t i = 0; i < array.size(); ++i) {
            if (array[i] == key) {
                std::cout << "Елемент знайдено на позиції " << i << ": " << array[i] << std::endl;
                found = true;
            }
        }

        if (!found) {
            std::cout << "Елемент з ключем " << key << " не знайдено." << std::endl;
        }
    }
};

// Шаблонний клас для роботи зі складними типами (наприклад, структурами)
template <typename T>
class SequentialSearchComplex {
private:
    std::vector<T> array; // Масив даних
public:
    // Конструктор для ініціалізації масиву
    SequentialSearchComplex(const std::vector<T>& arr) : array(arr) {}

    // Функція пошуку за вказаним полем
    template <typename KeyType>
    void findAndPrint(const KeyType& key, KeyType T::* field) const {
        bool found = false;

        for (size_t i = 0; i < array.size(); ++i) {
            if (array[i].*field == key) {
                std::cout << "Елемент знайдено на позиції " << i << ": " << array[i] << std::endl;
                found = true;
            }
        }

        if (!found) {
            std::cout << "Елемент з ключем " << key << " не знайдено." << std::endl;
        }
    }
};

// Оператор виводу для структур
struct Data {
    int id;
    std::string name;

    friend std::ostream& operator<<(std::ostream& os, const Data& data) {
        os << "{ id: " << data.id << ", name: \"" << data.name << "\" }";
        return os;
    }
};

int main() {
    // Для простих типів
    std::vector<int> intArray = { 1, 2, 3, 4, 5 };
    SequentialSearch<int> intSearch(intArray);
    intSearch.findAndPrint(3); // Знайде 3
    intSearch.findAndPrint(6); // Не знайде 6

    // Для складних типів
    std::vector<Data> dataArray = { {1, "Alice"}, {2, "Bob"}, {3, "Charlie"} };
    SequentialSearchComplex<Data> complexSearch(dataArray);

    // Пошук за id
    complexSearch.findAndPrint(2, &Data::id); // Знайде id = 2

    // Пошук за name
    complexSearch.findAndPrint(std::string("Charlie"), &Data::name); // Знайде "Charlie"
    complexSearch.findAndPrint(std::string("Dave"), &Data::name); // Не знайде "Dave"

    return 0;
}
