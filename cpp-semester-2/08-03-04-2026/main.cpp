#include <iostream>
#include <functional>

//using FunctionKey = std::function<int(int)>;

// template<typename T>
// std::function<bool(T, T)>
template<typename T>
using Comparer = std::function<bool(T, T)>;

/////-----------
template<typename TIn, typename TOut>
using Convertor = std::function<TOut(TIn)>;

template<typename T>
using Array = std::function<bool(T, 10)>;

template<typename T>
Convertor<>

////-------------------

int keyAbs(int x);
int keyDigitCount(int x);
int keySumOfDigits(int x);
int keyLastDigit(int x);
int keyModulo(int x, int n);

template<typename T, size_t left, size_t right>
void display(const T* arr);
//void bubbleSort(int* const arr, int left, int right, bool order);

template<typename T, typename U, typename FunctionKey>
void bubbleSort(T* const arr, int left, int right, FunctionKey key);

template<typename T>
void bubbleSort(T* const arr, int left, int right, Comparer<T> comprer);

//todo
// template<typename T, typename U>
// void bubbleSort(T* const arr, int left, int right, U* key);

void bubbleSortByValueAsc(int* const arr, int left, int right);
void bubbleSortByValueDesc(int* const arr, int left, int right);
void bubbleSortByAbs(int* const arr, int left, int right);
void bubbleSortByDigitCount(int* const arr, int left, int right);
void bubbleSortBySumOfDigits(int* const arr, int left, int right);
void bubbleSortByLastDigit(int* const arr, int left, int right);

int main() {
    constexpr int data[] = { -34, 70, 12, -3, 50, 51, -100, 42, 98 };
    constexpr int n = sizeof data / sizeof data[0];

    int array[n];

    auto copyFromData = [&]() {
        for (int i = 0; i < n; i++)
            array[i] = data[i];
    };

    copyFromData();
    bubbleSort<int, int, int (*) (int)>(array, 0, n - 1, keyAbs);
    display<int,0,n-1>(array);

    copyFromData();
    int l{4};
    bubbleSort<int, int, std::function<int(int)>>(array, 0, n - 1, [l](int x) { return ((x % l) + l) % l; });
    display<int,0,n-1>(array);

    copyFromData();
    std::cout << "Using comparer:" << std::endl;
    bubbleSort<int>(array, 0, n - 1, [](int x, int y){return abs(x) < abs(y);});
    display<int,0,n-1>(array);

    copyFromData();
    std::cout << "Using comparer:" << std::endl;
    bubbleSort<int>(array, 0, n - 1, [](int x, int y){return abs(x) > abs(y);});
    display<int,0,n-1>(array);

    copyFromData();
    std::cout << "Using comparer:" << std::endl;
    bubbleSort<int>(array, 0, n - 1, [](int x, int y){return std::to_string(x)[1] < std::to_string(y)[1];});
    display<int,0,n-1>(array);

    copyFromData();
    std::cout << "Using std::sort:" << std::endl;
    std::sort(array, array + n, [](int x, int y){return std::to_string(x)[1] > std::to_string(y)[1];});
    display<int, 0, n-1>(array);
    //-----------------------------

    constexpr double data1[] = { -34.5, 7.34, 12.2, -3.12, 0, 5, -100, 42, 9.1234 };
    constexpr int n1 = sizeof data1 / sizeof data1[0];

    double array1[n1];

    auto copyFromData1 = [&]() {
        for (int i = 0; i < n1; i++)
            array1[i] = data1[i];
    };

    copyFromData1();
    bubbleSort<double,char, std::function<char(double)>>(array1, 0, n1 - 1, [](double x){return std::to_string(x)[0];});
    display<double, 0,n1 - 1>(array1);

    copyFromData1();
    bubbleSort<double,std::string, std::function<std::string(double)>>(array1, 0, n1 - 1, [](double x){return std::to_string(x) + "$";});
    display<double, 0,n1 - 1>(array1);

    copyFromData1();
    std::cout << "Using std::sort:" << std::endl;
    std::sort(array1, array1 + n1);
    display<double, 0, n1-1>(array1);
    return 0;
}

template<typename T, size_t left, size_t right>
void display(const T* arr)
{
    for (int i = left; i <= right; ++i)
        std::cout << arr[i] << ' ';
    std::cout << '\n';
}

// --- Вспомогательные функции для ключей сортировки ---

int keyAbs(int x) { return std::abs(x); }

int keyDigitCount(int x)
{
    if (x == 0) return 1;
    int n = 0;
    int t = std::abs(x);
    while (t) { t /= 10; ++n; }
    return n;
}

int keySumOfDigits(int x)
{
    int t = std::abs(x);
    int s = 0;
    while (t) { s += t % 10; t /= 10; }
    return s;
}

int keyLastDigit(int x) { return std::abs(x % 10); }

// Остаток от деления на N (нормализованный для отрицательных)
int keyModulo(int x, int n) { return ((x % n) + n) % n; }

// 1. Обычная сортировка по значению (сравнение «меньше» / «больше»)
void bubbleSort(int* const arr, int left, int right, bool order)
{
    for (int i{ left }; i < right; i++)
    {
        for (int j{ right }; j > i; j--)
        {
            if (order) {
                if (arr[j] < arr[j - 1])
                    std::swap(arr[j], arr[j - 1]);
            }
            else {
                if (arr[j] > arr[j - 1])
                    std::swap(arr[j], arr[j - 1]);
            }
        }
    }
}

// --- Много вариантов самой сортировки (критерий «зашит» в коде) — затем сворачиваются в одну с настройкой ---

void bubbleSortByValueAsc(int* const arr, int left, int right)
{
    for (int i{ left }; i < right; i++)
        for (int j{ right }; j > i; j--)
            if (arr[j] < arr[j - 1])
                std::swap(arr[j], arr[j - 1]);
}

template<typename T, typename U, typename FunctionKey>
void bubbleSort(T* const arr, int left, int right, FunctionKey key)
{
    int n = right - left + 1;
    U* keys = new U[n];

    for (int i{ 0 }; i < n; i++) {
        keys[i] = key(arr[i + left]);
    }

    for (int i{ 0 }; i < n; i++)
        for (int j{ n - 1 }; j > i; j--)
            if (keys[j] < keys[j - 1]) {
                std::swap(keys[j], keys[j - 1]);
                std::swap(arr[j + left], arr[j - 1 + left]);
            }

    delete [] keys;
}

template<typename T>
void bubbleSort(T* const arr, int left, int right, Comparer<T> comparer) {
    for (int i{ left }; i < right; i++)
        for (int j{ right }; j > i; j--)
            if (comparer(arr[j], arr[j - 1]))
                std::swap(arr[j], arr[j - 1]);
}
