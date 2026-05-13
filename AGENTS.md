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

## 💡 Типовые Сценарии AI-Работы

### Сценарий 1: Реализовать новый класс
```
1. Прочитай AGENTS.md (этот файл) → 5 минут
2. Посмотри counter.h как пример → 5 минут
3. Напиши свой класс с:
   - ✅ default member initializers
   - ✅ Copy + Move конструкторы
   - ✅ Валидация в конструкторе (throw)
   - ✅ const методы помечены
4. Тестирование: g++ -std=c++20 -o test MyClass.h main.cpp
```

### Сценарий 2: Создать Builder (Fluent Interface)
```
1. Посмотри Pizza.h и Pizza.cpp → примеры шаблона
2. Создай nested Builder класс внутри основного
3. Каждый setter возвращает Builder& для chaining
4. Финальный метод build() возвращает готовый объект
```

### Сценарий 3: Реализовать шаблонный контейнер
```
1. Используй template<typename T> или template<typename T, size_t Size>
2. Помещай всю реализацию в .h файл (header-only)
3. Для сложных операций используй std::function
4. Проверь constexpr и if constexpr для compile-time решений
```

### Сценарий 4: Добавить новый проект в корень
```
1. Создай папку: cpp-semester-2/ДД-ММ-ГГ-формат/project-name/
2. Добавь файлы: main.cpp, MyClass.h, MyClass.cpp, CMakeLists.txt, README.md
3. Обнови корневой CMakeLists.txt: add_subdirectory("cpp-semester-2/...")
4. Проверь сборку: cmake .. && cmake --build . --target project-name
```

## 🐛 Отладка и Диагностика

### Проблема: Компилятор не находит header
```bash
# Проверь:
1. #pragma once или #ifndef в начале .h файла
2. #include "MyClass.h" (кавычки для локальных, угловые скобки для std)
3. Путь файла в CMakeLists.txt корректен
4. Перепостри проект: rm -rf build && mkdir build && cd build && cmake ..
```

### Проблема: Ошибка линковки (undefined reference)
```bash
# Это значит:
- Забыл добавить .cpp файл в CMakeLists.txt
- ИЛИ объявил функцию в .h но не реализовал в .cpp
- ИЛИ реализация находится в неправильном файле

# Решение:
add_executable(myapp main.cpp MyClass.cpp)  ← добавь все .cpp файлы
```

### Проблема: "Операция неоднозначна" при перегрузке операторов
```cpp
// ❌ НЕПРАВИЛЬНО:
class Pizza {
  public:
    Pizza operator=(const Pizza& other);      // Member function
};
Pizza p1, p2;
p1 = p2;  // Ambiguous: p1.operator=(p2) or p2 = p1?

// ✅ ПРАВИЛЬНО:
class Pizza {
  public:
    Pizza& operator=(const Pizza& other);     // возвращай ссылку
};
```

## 📊 Чек-лист перед Commit'ом

```
[ ] Компилируется без ошибок и warning'ов
[ ] Все классы имеют конструкторы и деструкторы
[ ] const методы помечены const
[ ] Нет magic numbers (используй #define или const)
[ ] Исключения выбрасываются для невалидных входов
[ ] CMakeLists.txt обновлён, если добавлены новые файлы
[ ] README.md описывает проект (если это корневой проект)
[ ] Функции помечены [[nodiscard]] если результат важен
[ ] Move semantics работает (Rule of Five реализована)
[ ] Тесты проходят (если есть)
```

## 🎓 Обучающие Ресурсы (в репозитории)

| Файл | Для изучения | Сложность |
|------|---|---|
| `counter.h` | Инкапсуляция, Copy/Move, исключения | ⭐⭐ |
| `Pizza.h` | Builder pattern, Nested classes | ⭐⭐ |
| `Array.h` | Динамическая память, capacity | ⭐⭐⭐ |
| `queue/main.cpp` | Template классы, циклический буфер | ⭐⭐⭐ |
| `labsV6/lab6` | Higher-order functions, std::function | ⭐⭐⭐ |

## 🎯 Метрика: Когда Вызвать Агента Снова

**Используй агента для:**
- ✅ Новой функциональности (класс, функция, алгоритм)
- ✅ Рефакторинга (улучшение структуры)
- ✅ Багов (тестирование, отладка)
- ✅ Интеграции (добавление в CMakeLists.txt)
- ✅ Документации (README, комментарии)

**НЕ используй агента для:**
- ❌ Мелких опечаток (исправляй сам)
- ❌ Переименований через IDE (используй refactor)
- ❌ Перемещения файлов (используй git mv)

---

**Последнее обновление**: 2026-05-13  
**Версия CMake**: 3.16+  
**Стандарт C++**: 20 (с поддержкой C++11/14/17)
**Статус**: ✅ Production-ready guide для AI-агентов
