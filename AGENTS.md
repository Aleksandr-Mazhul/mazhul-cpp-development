# AGENTS.md — Руководство для AI-Агентов

Этот файл содержит важную информацию о структуре, соглашениях и лучших практиках репозитория `mazhul-cpp-development` для эффективной работы AI-агентов.

## 📋 Структура Проекта

- **`cpp-semester-1/`** — Процедурное программирование, алгоритмы, указатели (базовый уровень)
- **`cpp-semester-2/`** — ООП, Templates, STL, Design Patterns, современный C++ (продвинутый уровень)
- **`cpp-semester-2/labsV6/`** — Систематизированный набор лабораторных работ с unit-тестами
- **Важные папки**: `counter`, `pizza`, `queue`, `Array`, `balanced-brackets-validator` — примеры паттернов

## 🛠 Технологический Стек

| Компонент | Использование |
|-----------|---|
| **Язык** | C++20 (совместимость с C++11/14/17) |
| **Сборка** | CMake 3.16+ |
| **IDE** | JetBrains CLion |
| **Компиляторы** | GCC, Clang, MSVC (кроссплатформа) |

## 📝 Соглашения Кода

### Header Guard и Include
```cpp
// ✅ ПРАВИЛЬНО: используй #pragma once или IFNDEF
#pragma once
#include <iostream>
#include <vector>
#include <string>

// ИЛИ:
#ifndef MAZHUL_CPP_DEVELOPMENT_COUNTER_H
#define MAZHUL_CPP_DEVELOPMENT_COUNTER_H
```

### Пространство Имён и Стиль
```cpp
// ✅ ПРАВИЛЬНО: using namespace std; допускается в small projects
using namespace std;

// ✅ ПРАВИЛЬНО: для файлов .h header-only — можно без using namespace
// Используй явные std::

class Pizza { /* ... */ };
std::ostream& operator<<(std::ostream& os, const Pizza& pizza);
```

### Инициализация Членов Класса
```cpp
// ✅ ПРАВИЛЬНО: default member initializers в классе
class Array {
  private:
    size_t capacity{4};      // явная инициализация
    size_t growFactor{2};    // с use braces initialization
    size_t length{1};
};

// ✅ ПРАВИЛЬНО: member initializer list в конструкторе
Counter(int c, int mn, int mx, int st)
    : current(c), min(mn), max(mx), step(st), initial(current) {}
```

### Методы и Доступ
```cpp
// ✅ ПРАВИЛЬНО: const методы должны быть помечены
int getCurrent() const { return current; }
void printSequence() const { /* ... */ }

// ✅ ПРАВИЛЬНО: private данные, public методы
class Counter {
  public:
    void increment();
    int getCurrent() const;
  private:
    int current, min, max;
};
```

### Исключения и Валидация
```cpp
// ✅ ПРАВИЛЬНО: выбрасывай std::invalid_argument для ошибок входных данных
if (min > max) {
    throw invalid_argument("ERROR: The minimum cannot be greater than the maximum");
}
```

### Move Semantics и Copy Constructor
```cpp
// ✅ ПРАВИЛЬНО: реализуй все четыре специальные члены (Rule of Five)
class Counter {
  public:
    Counter(const Counter &other) : /* copy init */ {}
    Counter(Counter &&other) noexcept : /* move init */ {}
    Counter& operator=(const Counter &other);
    Counter& operator=(Counter &&other) noexcept;
    ~Counter() = default;  // explicit если нужно
};
```

### Шаблоны (Templates)
```cpp
// ✅ ПРАВИЛЬНО: шаблонные функции для полиморфизма типов
template<typename T>
void bubbleSort(T* arr, int size, function<int(const T&)> keyExtractor) {
    // реализация
}

// ✅ ПРАВИЛЬНО: шаблонные классы с явно определённым поведением
template<typename T, size_t Size>
class Queue {
  private:
    T buffer[Size];
    // ...
};
```

### Функциональное Программирование
```cpp
// ✅ ПРАВИЛЬНО: используй std::function для callback'ов
#include <functional>
using Predicate = std::function<bool(const int&)>;

// ✅ ПРАВИЛЬНО: принимай лямбды и функторы
void filterByPredicate(const int* arr, int size, Predicate pred) {
    // ...
}

// Вызов:
filterByPredicate(arr, 10, [](const int& x) { return x > 5; });
```

### Design Patterns
#### Builder Pattern (Fluent Interface)
```cpp
// ✅ ПРАВИЛЬНО: метод chaining для построения сложных объектов
class Pizza::Builder {
  public:
    Builder& setSize(const string& size);
    Builder& setDough(const string& dough);
    Pizza build();
};

// Использование:
Pizza pizza = Pizza::Builder()
    .setSize("large")
    .setDough("thick")
    .build();
```

### Комментирование
```cpp
// ✅ ПРАВИЛЬНО: комментируй сложную логику, НЕ очевидные решения
if (current + step < max) {  // гарантируем, что не переполним верхнюю границу
    current += step;
}

// ✅ НЕПРАВИЛЬНО: очевидные комментарии
int x = 5;  // установить x в 5
current++;  // увеличить текущее значение
```

## 🔨 Команды Сборки и Тестирования

```bash
# Стандартная сборка всего проекта
cd /Users/alexandermazhul/CLionProjects/mazhul-cpp-development
mkdir -p build && cd build
cmake ..
cmake --build .

# Сборка конкретного таргета (например, counter)
cmake --build . --target counter

# Быстрая компиляция одного файла (без CMake)
g++ -std=c++20 -o main main.cpp counter.cpp
clang++ -std=c++20 -o main main.cpp
```

## 📂 Типовая Структура Проекта

Каждый значимый проект содержит:

```
project-name/
├── CMakeLists.txt          # конфигурация сборки
├── README.md               # описание проекта
├── main.cpp                # entry point
├── MyClass.h               # header файл
├── MyClass.cpp             # реализация
└── (опционально) tests/    # unit-тесты
```

## 🎯 Паттерны для Быстрого Понимания

### Pattern 1: Простой класс с инкапсуляцией (Counter)
Найди: `cpp-semester-2/04-25-02-2026/counter/`
**Суть**: Демонстрирует инкапсуляцию, конструкторы копирования/перемещения, исключения.

### Pattern 2: Builder Pattern (Pizza)
Найди: `cpp-semester-2/09-10-04-2026/pizza/`
**Суть**: Fluent Interface, nested Builder class, красивая конструкция объектов.

### Pattern 3: Динамический контейнер (Array)
Найди: `cpp-semester-2/08-01-04-2026/`
**Суть**: Переиспользуемый вектор с динамическим расширением, capacity и growFactor.

### Pattern 4: Шаблонная очередь (Queue)
Найди: `cpp-semester-2/04-25-02-2026/queue/`
**Суть**: Template класс, элементы, циклический буфер.

### Pattern 5: Функциональное программирование
Найди: `cpp-semester-2/06-18-03-2026/task/`
**Суть**: Higher-order functions, std::function, предикаты, лямбды.

## 🤖 Рекомендации для AI-Агентов (Экономия Токенов)

### Быстрое Ориентирование

1. **Не читай весь README.md**, используй `tree` для структуры:
   ```bash
   tree -L 2 cpp-semester-2/
   ```

2. **Для нового проекта смотри сразу на CMakeLists.txt**:
   - Какие файлы участвуют в сборке
   - Зависимости и флаги компиляции

3. **Проверь соответствующий `README.md` в папке проекта** перед написанием кода.

### Стратегия Анализа Кода

1. **Сначала**: Структура класса в `.h` файле (10-30 строк обычно)
2. **Потом**: Основная реализация в `.cpp` (если она есть)
3. **Пропусти**: Детали в `main.cpp` пока не требуется реализация

### Типовые Ошибки (Избегай)

| Ошибка | Примечание |
|--------|-----------|
| Забыл `const` на getter методе | ✗ `int getCurrent() { return current; }` |
| Не реализовал Rule of Five | ✗ Move-семантика не сработает |
| Используешь `std::cout` без `#include <iostream>` | ✗ Проверь includes |
| `using namespace std;` только в `.cpp` для больших проектов | Для `.h` лучше `std::` |
| Не выбрасываешь исключения для невалидных состояний | ✗ Нарушаешь контракт класса |
| Magic numbers без `const` | ✗ Используй `const size_t DEFAULT_CAPACITY{4};` |

### Оптимальный Шаблон Новой Реализации

```cpp
// 1. Заголовочный файл (.h) — 20-40 строк
#pragma once
#include <necessary_headers>

class MyClass {
  public:
    MyClass(/* параметры */);
    MyClass(const MyClass& other);
    MyClass(MyClass&& other) noexcept;
    MyClass& operator=(const MyClass& other);
    MyClass& operator=(MyClass&& other) noexcept;
    
    // Public API
    void publicMethod();
    int getState() const;
    
  private:
    // Private members
    int state{0};
};

// 2. Реализация (.cpp) — прямолинейная
#include "MyClass.h"

MyClass::MyClass(int val) : state(val) {
    if (state < 0) throw invalid_argument("State cannot be negative");
}

// 3. Main (.cpp) — примеры использования
int main() {
    MyClass obj(42);
    cout << obj.getState() << endl;
    return 0;
}
```

## 📊 Метрики Качества

**Для каждого класса проверь:**
- ✅ Есть ли конструктор с параметрами?
- ✅ Есть ли copy/move конструкторы?
- ✅ Помечены ли const методы?
- ✅ Есть ли валидация входных параметров?
- ✅ Есть ли `#pragma once` или header guard?

## 🚀 Сокращение Времени Анализа

| Задача | Как делать быстро |
|--------|---|
| Найти пример класса | Поиск в `cpp-semester-2/` по дате, затем посмотри `.h` |
| Понять стиль кода | Прочитай `counter.h` (100 строк) и `Pizza.h` (30 строк) |
| Проверить соглашения | Посмотри 3 последних коммита в git |
| Найти тесты | Иди в папку, поиск `test`, `unittest` или файлы в `labsV6/` |

## 🔗 Быстрые Ссылки на Ключевые Файлы

```
cpp-semester-2/
├── 04-25-02-2026/counter/counter.h         → Example: Encapsulation + Rule of Five
├── 04-25-02-2026/queue/main.cpp            → Example: Template class usage
├── 08-01-04-2026/Array.h                   → Example: Dynamic container
├── 09-10-04-2026/pizza/Pizza.h             → Example: Builder pattern
├── 06-18-03-2026/task/                     → Example: Functional programming
└── labsV6/                                 → Example: Unit tests
```

---

**Последнее обновление**: 2026-05-13  
**Версия CMake**: 3.16+  
**Стандарт C++**: 20 (с поддержкой C++11/14/17)
