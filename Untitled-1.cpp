#include <iostream>
#include <algorithm>
#include <cstring>

template<typename T>
void find_min_and_count(const T* arr, const size_t size, T& min_value, size_t& count)
{
    // Початкова кількість повторень дорівнює 0
    count = 0;
    
    // Якщо масив порожній, повертаємо порожні значення
    if (size == 0)
    {
        min_value = T();
        return;
    }
    
    // Знаходимо мінімальне значення в масиві за допомогою функції min_element
    min_value = *std::min_element(arr, arr + size);
    
    // Обчислюємо кількість повторень мінімального значення
    for (size_t i = 0; i < size; i++)
    {
        if (strcmp(arr[i], min_value) == 0)
        {
            count++;
        }
    }
}

int main()
{
    const size_t size = 5;
    char* arr[size] = {"bbb", "aaa", "ccc", "aaa", "ddd"};
    char* min_value;
    size_t count;

    find_min_and_count(arr, size, min_value, count);

    std::cout << "Minimum value: " << min_value << std::endl;
    std::cout << "Count of minimum value: " << count << std::endl;

    return 0;
}
