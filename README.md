# Сортировка

Сортировка массивов — одна из базовых задач в программировании.\
Существует множество алгоритмов сортировки, отличающихся по эффективности, сложности и принципу работы.

## Пузырьковая сортировка

**Пузырьковая сортировка** — один из самых простых алгоритмов сортировки, который последовательно сравнивает\
соседние элементы массива и меняет их местами, если они расположены в неправильном порядке.\
Процесс повторяется до тех пор, пока массив не будет полностью отсортирован.

**Принцип работы**

1. Проход по массиву: Алгоритм проходит по массиву, сравнивая каждую пару соседних элементов.

2. Обмен местами: Если текущий элемент больше следующего (arr[j] > arr[j + 1]), они меняются местами.

3. Повторение: Процесс повторяется, пока за весь проход не будет выполнено ни одного обмена (массив отсортирован).

**Визуализация**

Рассмотрим массив [5, 3, 8, 4, 2]:

1. Первый проход:
   - [5, 3, 8, 4, 2] → [3, 5, 8, 4, 2] (5 > 3, меняем)
   - [3, 5, 8, 4, 2] → [3, 5, 4, 8, 2] (8 > 4, меняем)
   - [3, 5, 4, 8, 2] → [3, 5, 4, 2, 8] (8 > 2, меняем)
     
2. Второй проход:
   - [3, 5, 4, 2, 8] → [3, 4, 5, 2, 8] (5 > 4, меняем)
   - [3, 4, 5, 2, 8] → [3, 4, 2, 5, 8] (5 > 2, меняем)
   - Результат после 2-го прохода: [3, 4, 2, 5, 8]

3. Третий проход:
   - [3, 4, 2, 5, 8] → [3, 2, 4, 5, 8] (4 > 2, меняем)
   - Результат после 3-го прохода: [3, 2, 4, 5, 8]

4. Четвертый проход:
   - [3, 2, 4, 5, 8] → [2, 3, 4, 5, 8] (3 > 2, меняем)
   - Результат после 4-го прохода: [2, 3, 4, 5, 8]

**Реализация на C++**

```
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}
```
Недостаток: Даже если массив уже отсортирован, алгоритм все равно выполнит все проходы.

**Оптимизированная версия (с флагом)**

```
void bubbleSortOptimized(int arr[], int n) {
    bool swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;  // Если обменов не было, массив отсортирован
    }
}
```

Плюс: Если массив уже отсортирован, алгоритм завершится за O(n) (один проход).

**Сложность алгоритма**

![image](https://github.com/user-attachments/assets/bc59d6b8-059a-4725-aa03-1454208337aa)

**Плюсы и минусы**

✅ Преимущества:

- Простота реализации.
- Не требует дополнительной памяти.
- Хорошо работает на почти отсортированных массивах (с оптимизацией).

❌ Недостатки:

 - Очень медленный для больших массивов.
 - Даже в оптимизированной версии в худшем случае O(n²).

**Когда использовать?**

- Учебные цели (для понимания основ сортировки).
- Небольшие массивы (до 1000 элементов).
- Частично отсортированные данные (с оптимизацией).

**Пример полного кода**

```
#include <iostream>
#include <algorithm>

void bubbleSortOptimized(int arr[], int n) {
    bool swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

int main() {
    int arr[] = {5, 3, 8, 4, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    bubbleSortOptimized(arr, n);

    std::cout << "Отсортированный массив: ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    return 0;
}
```

**Вывод**

Пузырьковая сортировка — хороший пример для изучения основ алгоритмов,\
но на практике применяется редко из-за низкой эффективности.\
Оптимизация с флагом swapped ускоряет работу на частично упорядоченных данных.


## Сортировка выбором

Сортировка выбором — это алгоритм сортировки, который на каждом шаге находит минимальный (или максимальный) элемент\
в неотсортированной части массива и помещает его в конец отсортированной части.

**Принцип работы**

1. Разделение массива:

   - Массив делится на две части: отсортированную (слева) и неотсортированную (справа).
   - В начале отсортированная часть пуста.

2. Поиск минимума:
   
   - На каждом шаге алгоритм ищет минимальный элемент в неотсортированной части.
     
3. Обмен элементами:

   - Найденный минимальный элемент меняется местами с первым элементом неотсортированной части.
   - Теперь этот элемент считается частью отсортированной последовательности.

4. Повторение:

   - Процесс повторяется, пока неотсортированная часть не станет пустой.
  
**Визуализация**

1. Рассмотрим массив [64, 25, 12, 22, 11]:

   - Первый проход (ищем минимум в [64, 25, 12, 22, 11]):
   - Минимум = 11 (индекс 4).
   - Меняем 64 и 11:   [11, 25, 12, 22, 64]
   - Теперь отсортированная часть = [11], неотсортированная = [25, 12, 22, 64].

2. Второй проход (ищем минимум в [25, 12, 22, 64]):
 
   - Минимум = 12 (индекс 2).
   - Меняем 25 и 12: [11, 12, 25, 22, 64]
   - Отсортированная часть = [11, 12], неотсортированная = [25, 22, 64].
  
3. Третий проход (ищем минимум в [25, 22, 64]):

   - Минимум = 22 (индекс 3).
   - Меняем 25 и 22: [11, 12, 22, 25, 64]
   - Отсортированная часть = [11, 12, 22], неотсортированная = [25, 64].

4. Четвертый проход (ищем минимум в [25, 64]):

   - Минимум = 25 (уже на своем месте).
   - Обмен не требуется.
   - Отсортированная часть = [11, 12, 22, 25], неотсортированная = [64].


**Реализация на C++**

1. Базовая версия
```
   void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;  // Индекс минимального элемента
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        std::swap(arr[i], arr[minIndex]);
    }
}
```

2. Версия с сортировкой по убыванию
```
void selectionSortDescending(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int maxIndex = i;  // Индекс максимального элемента
        for (int j = i + 1; j < n; j++) {
            if (arr[j] > arr[maxIndex]) {
                maxIndex = j;
            }
        }
        std::swap(arr[i], arr[maxIndex]);
    }
}
```

**Сложность алгоритма**

![image](https://github.com/user-attachments/assets/9536f982-3deb-4bf7-9a9b-d59e87742a12)


**Плюсы и минусы**

✅ Преимущества:

 - Простота реализации.
 - Минимум перестановок (всего n-1 обмен).
 - Работает быстрее пузырьковой сортировки на практике (меньше операций swap).

❌ Недостатки:

 - Всегда работает за O(n²), даже если массив уже отсортирован.
 - Нестабильный (может менять порядок одинаковых элементов).

**Когда использовать?**

 - Небольшие массивы (до 1000 элементов).
 - Когда количество обменов критично (например, сортировка данных на SSD).
 - В учебных целях (для понимания принципов сортировки).

**Пример полного кода**

```
#include <iostream>
#include <algorithm>

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        std::swap(arr[i], arr[minIndex]);
    }
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    selectionSort(arr, n);

    std::cout << "Отсортированный массив: ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    return 0;
}
```

Сортировка выбором — простой, но неэффективный алгоритм для больших данных.\
Основное преимущество — минимальное количество обменов.


## Сортировка вставками

Сортировка вставками — это простой алгоритм сортировки, который строит итоговый массив по одному элементу за раз,\
вставляя каждый новый элемент в правильную позицию в уже отсортированной части массива.

**Принцип работы**

1. Разделение массива:

   - Массив условно делится на отсортированную (слева) и неотсортированную (справа) части.
   - В начале отсортированная часть состоит из одного элемента (первого).

2. Выбор элемента:

   - Берётся первый элемент из неотсортированной части.

3. Вставка в правильную позицию:

   - Выбранный элемент последовательно сравнивается с элементами отсортированной части справа налево.
   - Все элементы, которые больше текущего, сдвигаются вправо.
   - Когда находится правильная позиция (элемент меньше или равен текущему), элемент вставляется.

4. Повторение:

   - Процесс повторяется, пока неотсортированная часть не станет пустой.
  
**Визуализация**

Рассмотрим массив [12, 11, 13, 5, 6]:

1. Первый проход:

   - Отсортированная часть: [12]
   - Неотсортированная: [11, 13, 5, 6]
   - Вставляем 11:  11 < 12 → сдвигаем 12 вправо → [11, 12, 13, 5, 6]

2. Второй проход:

   - Отсортированная: [11, 12]
   - Неотсортированная: [13, 5, 6]
   - Вставляем 13:  13 > 12 → остаётся на месте → [11, 12, 13, 5, 6]

3. Третий проход:

   - Отсортированная: [11, 12, 13]
   - Неотсортированная: [5, 6]
   - Вставляем 5:
       - 5 < 13 → сдвигаем 13 → [11, 12, 13, 13]
       - 5 < 12 → сдвигаем 12 → [11, 12, 12, 13]
       - 5 < 11 → сдвигаем 11 → [11, 11, 12, 13]
       - Вставляем 5 в начало → [5, 11, 12, 13, 6]

4. Четвёртый проход:

   - Отсортированная: [5, 11, 12, 13]
   - Неотсортированная: [6]
   - Вставляем 6:
     - 6 < 13 → сдвигаем 13 → [5, 11, 12, 13, 13]
     - 6 < 12 → сдвигаем 12 → [5, 11, 12, 12, 13]
     - 6 < 11 → сдвигаем 11 → [5, 11, 11, 12, 13]
     - 6 > 5 → вставляем после 5 → [5, 6, 11, 12, 13]
    

**Реализация на C++**

1. Базовая версия
   
```
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];  // Текущий элемент для вставки
        int j = i - 1;
        
        // Сдвигаем элементы больше key вправо
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;  // Вставляем key в правильную позицию
    }
}
```

2. Версия с бинарным поиском (оптимизация)

```
int binarySearch(int arr[], int item, int low, int high) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (item == arr[mid])
            return mid + 1;
        else if (item > arr[mid])
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low;
}

void insertionSortBinary(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int pos = binarySearch(arr, key, 0, i - 1);
        
        // Сдвиг элементов
        for (int j = i - 1; j >= pos; j--) {
            arr[j + 1] = arr[j];
        }
        arr[pos] = key;
    }
}
```

**Сложность алгоритма**

![image](https://github.com/user-attachments/assets/cff64811-ae8f-42e1-9eca-9d28817bbe21)


**Плюсы и минусы**

✅ Преимущества:

 - Простота реализации.
 - Эффективен для небольших массивов (n ≤ 1000).
 - Стабильный (не меняет порядок одинаковых элементов).
 - Адаптивный — работает быстрее на частично отсортированных данных (O(n+k), где k — число инверсий).

❌ Недостатки:

- Медленный для больших массивов (O(n²) в худшем случае).
- Много операций сдвига.

**Когда использовать?**

- Небольшие или почти отсортированные массивы (лучше, чем QuickSort при n ≤ 10).
- Онлайн-сортировка (когда данные поступают последовательно).
- Как часть более сложных алгоритмов (например, в TimSort).

**Пример полного кода**

```
#include <iostream>
#include <algorithm>

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main() {
    int arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    insertionSort(arr, n);

    std::cout << "Отсортированный массив: ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    return 0;
}
```

Сортировка вставками — один из самых простых и понятных алгоритмов, который хорошо подходит для небольших или частично упорядоченных данных.\ 
Однако для больших массивов его производительность недостаточна.

Оптимизации:

 - Использовать бинарный поиск для нахождения позиции вставки (уменьшает число сравнений, но не сдвигов).
 - Применять гибридные алгоритмы (например, TimSort), которые используют сортировку вставками для маленьких блоков.



## Быстрая сортировка

Быстрая сортировка — это эффективный алгоритм сортировки, использующий стратегию "разделяй и властвуй".\
Разработан Тони Хоаром в 1960 году. В среднем работает за O(n log n), что делает его одним из самых быстрых алгоритмов сортировки.

**Принцип работы**


1. Выбор опорного элемента (pivot):

  - Один из элементов массива выбирается как опорный (pivot).

    *Частые стратегии выбора:*

       - Первый/последний элемент (просто, но может привести к O(n²) на уже отсортированных данных)
       - Средний элемент (arr[(left + right) / 2])
       - Случайный элемент (хорошо для избежания худшего случая)

2. Разделение (partitioning):

   - Массив перестраивается так, что:
     - Все элементы меньше pivot перемещаются левее него.
     - Все элементы больше pivot перемещаются правее.
   - Pivot встаёт на свою окончательную позицию.

3. Рекурсивная сортировка:

 - Алгоритм рекурсивно применяется к левой и правой частям массива.

**Визуализация**

Рассмотрим массив [10, 7, 8, 9, 1, 5] с выбором pivot как последний элемент.

1. Первое разделение (pivot = 5)

   - Индекс i идёт слева, j справа.
   - i ищет элемент ≥ 5, j ищет элемент ≤ 5.
   - Меняем 10 и 1 → [1, 7, 8, 9, 10, 5]
   - Когда i и j пересекаются, меняем arr[i] и pivot → [1, 5, 8, 9, 10, 7]
   - Теперь pivot (5) на своём месте.
  
2. Рекурсия для левой ([1]) и правой ([8, 9, 10, 7]) частей

    - Левая часть уже отсортирована.
    - Правая часть: pivot = 7 → [7, 9, 10, 8] → рекурсия продолжается.
  
**Реализация на C++**

1. Классическая версия (с выбором последнего элемента как pivot)

```
int partition(int arr[], int low, int high) {
    int pivot = arr[high];  // Опорный элемент
    int i = low - 1;        // Индекс для элементов меньше pivot

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);  // Ставим pivot на место
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);  // Индекс pivot
        quickSort(arr, low, pi - 1);   // Сортировка левой части
        quickSort(arr, pi + 1, high);  // Сортировка правой части
    }
}
```

2. Оптимизированная версия (случайный pivot)

```
#include <cstdlib>
#include <ctime>

int partitionRandom(int arr[], int low, int high) {
    srand(time(NULL));
    int random = low + rand() % (high - low);
    std::swap(arr[random], arr[high]);  // Случайный pivot
    return partition(arr, low, high);
}
```

**Сложность алгоритма**

![image](https://github.com/user-attachments/assets/02ade9a1-8215-4882-99c2-8c0f845c07c0)


**Плюсы и минусы**

✅ Преимущества:

 - Очень быстрый в среднем случае (обычно быстрее MergeSort и HeapSort).
 - Сортировка на месте (не требует дополнительной памяти, в отличие от MergeSort).
 - Хорошо работает с кешем (из-за локальности данных).

❌ Недостатки:

 - Нестабильный (может менять порядок одинаковых элементов).
 - Худший случай O(n²) (например, если массив уже отсортирован, а pivot — первый/последний элемент).
 - Рекурсия может привести к переполнению стека на очень больших массивах.

**Когда использовать?**

 - Общего назначения (один из самых популярных алгоритмов).
 - Когда важна скорость (в среднем быстрее MergeSort).
 - Для массивов в памяти (не подходит для внешней сортировки).

Не используйте, если:

 - Требуется стабильность (выберите MergeSort).
 - Данные уже почти отсортированы (лучше Insertion Sort или TimSort).


Пример полного кода

```
#include <iostream>
#include <algorithm>

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    quickSort(arr, 0, n - 1);

    std::cout << "Отсортированный массив: ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    return 0;
}
```

**Оптимизации QuickSort**

- Выбор медианы трёх (первый, средний, последний элементы) как pivot.
- Рандомизированный pivot (избегает худшего случая).
- Переход на Insertion Sort для маленьких подмассивов (n ≤ 10).
- Итеративная реализация (избегает рекурсии).

QuickSort — один из самых эффективных алгоритмов сортировки, но требует аккуратной реализации.\
В C++ std::sort обычно использует гибрид QuickSort + Insertion Sort.


## Бинарный поиск

Бинарный поиск — это алгоритм поиска элемента в отсортированном массиве, который работает за O(log n).\
Он значительно быстрее линейного поиска (O(n)), но требует предварительной сортировки данных.

**Принцип работы**

1 . Делим массив пополам:

   - Находим средний элемент (mid).

2. Сравниваем с искомым значением (target):

   - Если arr[mid] == target → элемент найден.
   - Если arr[mid] < target → ищем в правой половине.
   - Если arr[mid] > target → ищем в левой половине.

3. Повторяем, пока не найдём элемент или не убедимся, что его нет.

**Визуализация**

Массив: [2, 5, 8, 12, 16, 23, 38, 56, 72, 91]\
Ищем: 23

Шаг 1:

  - left = 0, right = 9 → mid = 4 (16)
  - 16 < 23 → ищем справа (left = 5)

Шаг 2:

  - left = 5, right = 9 → mid = 7 (56)
  - 56 > 23 → ищем слева (right = 6)

Шаг 3:

  - left = 5, right = 6 → mid = 5 (23)
  - 23 == 23 → найден на позиции 5!


**Реализация на C++**

1. Итеративная версия

```
int binarySearch(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;  // Защита от переполнения

        if (arr[mid] == target) {
            return mid;  // Элемент найден
        } else if (arr[mid] < target) {
            left = mid + 1;  // Ищем в правой половине
        } else {
            right = mid - 1;  // Ищем в левой половине
        }
    }
    return -1;  // Элемент не найден
}
```

Рекурсивная версия

```
int binarySearchRecursive(int arr[], int left, int right, int target) {
    if (left > right) {
        return -1;  // Базовый случай: элемент не найден
    }

    int mid = left + (right - left) / 2;

    if (arr[mid] == target) {
        return mid;
    } else if (arr[mid] < target) {
        return binarySearchRecursive(arr, mid + 1, right, target);
    } else {
        return binarySearchRecursive(arr, left, mid - 1, target);
    }
}
```

**Сложность алгоритма**

![image](https://github.com/user-attachments/assets/7d99a52c-3c91-48c5-851f-5d16f3e6fe00)

**Плюсы и минусы**

✅ Преимущества:

 - Очень быстрый (на больших данных в тысячи раз быстрее линейного поиска).
 - Прост в реализации.

❌ Недостатки:

 - Работает только с отсортированными массивами.
 - Неэффективен для очень маленьких массивов (из-за накладных расходов).

**Пример использования**

```
#include <iostream>

int main() {
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 23;

    int result = binarySearch(arr, size, target);

    if (result != -1) {
        std::cout << "Элемент найден на позиции: " << result << std::endl;
    } else {
        std::cout << "Элемент не найден!" << std::endl;
    }
    return 0;
}
```

Бинарный поиск — один из самых полезных алгоритмов в программировании.\
Он крайне эффективен для поиска в отсортированных данных и часто используется в\
реальных приложениях (базы данных, системы рекомендаций и др.).

