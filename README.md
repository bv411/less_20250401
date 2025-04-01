# Сортировка

Сортировка массивов — одна из базовых задач в программировании.\
Существует множество алгоритмов сортировки, отличающихся по эффективности, сложности и принципу работы.

##Пузырьковая сортировка

**Пузырьковая сортировка** — один из самых простых алгоритмов сортировки, который последовательно сравнивает\
соседние элементы массива и меняет их местами, если они расположены в неправильном порядке.\
Процесс повторяется до тех пор, пока массив не будет полностью отсортирован.

**Принцип работы**

1. Проход по массиву: Алгоритм проходит по массиву, сравнивая каждую пару соседних элементов.

2. Обмен местами: Если текущий элемент больше следующего (arr[j] > arr[j + 1]), они меняются местами.

3. Повторение: Процесс повторяется, пока за весь проход не будет выполнено ни одного обмена (массив отсортирован).
