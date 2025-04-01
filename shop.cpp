#include <iostream>
#include <stdio.h>

void print(int a[], long size) {
    for (int i = 0; i < size; i++) {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;
}

void gen(int a[], long size) {

    for (int i = 0; i < size; i++) {
        a[i] = 100 - rand() % 200;
    }    
}

// Вставки
void insertSort(int a[], long size) {
    int  temp;
    int count{};
    for (int i = 0; i < size; i++) {
        temp = a[i];
        int j;
        for (j = i - 1; j >= 0 && a[j] > temp; j--, count++)
            a[j + 1] = a[j];

        a[j + 1] = temp;
    }
    std::cout << "Count (insert) = " << count << std::endl;
}

// Метод выбором
void selectSort(int a[], long size) {

    for (int i = 0; i < size; i++) {
        int min_index = i;

        for (int j = i + 1; j < size; j++)
            if (a[j] < a[min_index])
                min_index = j;

        if (min_index != i)
            std::swap(a[min_index], a[i]);
    }
}


// Метод выбором поломанный
/*
Отсортировать по возрастанию только положительные элементы массива

const int SIZE = 10;
int arr[SIZE] {-1,7,2,8,-3,-6,0,9,4,3};
*/
void selectSort_break(int a[], long size) {

    for (int i = 0; i < size; i++) {

        if (a[i] < 0)
            continue;

        int min_index = i;

        for (int j = i + 1; j < size; j++)
            if (a[j] >= 0  && a[j] < a[min_index])
                min_index = j;

        if (min_index != i)
            std::swap(a[min_index], a[i]);
    }
}

// Быстрая сортировка
void quickSort(int mas[], int first, int last, int& count) {

    //static int count{};

    int mid;
    int f = first, l = last;
    mid = mas[(f + l) / 2];
    do {
        while (mas[f] < mid) f++;
        while (mas[l] > mid) l--;

        if (f <= l) {
            std::swap(mas[f], mas[l]);
            f++;
            l--;
            count++;
        }

    } while (f < l);

    if (first < l) quickSort(mas, first, l, count);
    if (f < last) quickSort(mas, f, last, count);
}

int BinarySearch(int A[], int start, int end, int Key) {

    if (start > end)
        return -1;

    int M = (start + end) / 2;

    if (Key < A[M])
        return BinarySearch(A, start, M - 1, Key);

    if (Key > A[M])
        return BinarySearch(A, M + 1, end, Key);

    return M;
}


int BinarySearch_v2(int A[], int size, int Key) {
    int M;
    int start = 0;
    int end = size - 1;
    int count = 0;
    while (true) {
        M = (start + end) / 2;

        if (Key < A[M]) {
            end = M - 1;
            count++;
        }
        else
            if (Key > A[M]) {
                start = M + 1;
                count++;
            }
            else {
                std::cout << "Count (BinarySearch) = " << count << std::endl;
                return M;
            }

        if (start > end) {
            std::cout << "Count (BinarySearch) = " << count << std::endl;
            return -1;
        }
    }
}


int main_for_sort() {

    srand(time(NULL));

    const int SIZE = 10;
    //int arr[SIZE]{ -1,7,2,8,-3,-6,0,9,4,3 };
    int arr[SIZE]{};
    gen(arr, SIZE);


    print(arr, SIZE);

    selectSort_break(arr, SIZE);

    print(arr, SIZE);


    /*const int SIZE = 40;
    int arr[SIZE];
    
    gen(arr, SIZE);    
    
    int count = 0;
    quickSort(arr, 0, SIZE - 1, count);

    print(arr, SIZE);

    int key;

    std::cout << "Enter key ";
    std::cin >> key;

    int ind = BinarySearch_v2(arr, SIZE, key);

    if (ind != -1) {

        std::cout << "Element index = " << ind << std::endl;
    }
    else {
        std::cout << "Element not found!" << std::endl;
    }*/



    /*int arr2[SIZE];

    for (int i = 0; i < SIZE; i++)
        arr2[i] = arr[i];
       
    
    insertSort(arr, SIZE);
    
    int count = 0;
    quickSort(arr2, 0, SIZE-1, count);    
    std::cout << "Count (quickSort) = " << count << std::endl;
    

    print(arr, SIZE);*/
    
    return 0;
}



#include <chrono>
#include <thread>


/*
#include <windows.h>

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
    std::cout << "Этот текст красный" << std::endl;

// Сброс к стандартному цвету
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
*/

#define BLACK   "\033[30m"      /* Black */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */


// ANSI коды для цветов текста
#define RESET   "\033[0m"
#define RED     "\033[31m"      /* Red */

const int size = 6;
int board[size][size]{};

int steps[8][2]{ {-1,2},{1,2},{1,-2},{-1,-2},{-2,1},{2,1},{-2,-1},{2,-1} };

void print_board() {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++)
            std::cout << board[i][j] << "\t";
        std::cout << std::endl;
    }
}


void print_board(int count_move) {
    system("cls");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (board[i][j] == count_move)
                std::cout << MAGENTA << board[i][j] << RESET << "\t";
            else
                std::cout << board[i][j] << "\t";
        }
        std::cout << std::endl;
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(300));
}


bool is_valid_step(int x, int y) {
    return (x >= 0 && x < size && y >= 0 && y < size && board[x][y] == 0);
}

bool move(int x, int y, int count_move) {

    if (count_move == size * size)
        return true;

    for (int i = 0; i < 8; i++) {

        int new_x = x + steps[i][0];
        int new_y = y + steps[i][1];

        if (is_valid_step(new_x, new_y)) {
            board[new_x][new_y] = count_move + 1;

            // Для иллюстрации вывода работы алгоритма
            print_board(count_move+1);

            if (move(new_x, new_y, count_move + 1)) {
                return true;
            }
            board[new_x][new_y] = 0;
        }
    }
    return false;
}

int main_chess() {
    setlocale(LC_ALL, "");

    int start_x, start_y;
    std::cout << "Введите координаты начальной точки коня от 0 до 5(через пробел)" << std::endl;
    std::cin >> start_x >> start_y;

    if (start_x < 0 || start_x >= size || start_y < 0 || start_y >= size) {
        std::cout << "Неверные координаты!" << std::endl;
        return 0;
    }

    board[start_x][start_y] = 1;

    if (move(start_x, start_y, 1)) {
        std::cout << "Путь найден!" << std::endl;
        print_board();
    }
    else
        std::cout << "Путь не найден! " << std::endl;

    return 0;
}


union Test {

    int v1;
    double v2;
    char v3;
};

union Test2 {
    int v1;
    unsigned char v2[4];
};

struct Date {
    unsigned short day:2;
    unsigned short month:2;
    unsigned short year:2;
};


int main() {

    using namespace std;

    /*cout << sizeof(Test) << endl;

    Test t;

    t.v2 = 3497.5675;

    cout << " v1 = " << t.v1 << endl;
    cout << " v2 = " << t.v2 << endl;
    cout << " v3 = " << t.v3 << endl;*/

   /* Test2 t;

    t.v1 = 456256;

    cout << " v1 = " << t.v1 << endl;
    cout << " v2[0] = " << (int)t.v2[0] << endl;
    cout << " v2[1] = " << (int)t.v2[1] << endl;
    cout << " v2[2] = " << (int)t.v2[2] << endl;
    cout << " v2[3] = " << (int)t.v2[3] << endl;*/



    cout << sizeof(Date) << endl;

    Date d;
    d.day = 63;
    d.month = 12;
    d.year = 99;

    printf("%d.%d.%d", d.day, d.month, d.year);

    return 0;
}
