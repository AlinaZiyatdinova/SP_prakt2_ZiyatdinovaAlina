
#include <iostream>
#include "prakt2.h"
using namespace std;

void writeTo1Array(int array[], int size)
{
    srand(time(0));
    for (int i = 0; i < size; i++)
    {
        array[i] = rand() % 201 - 100;
    }
}
void outputArray(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << endl;
    }
}
int searchSecondNumMax(int array[], int size)
{
    int secondNum_max = INT_MIN;
    int firstNum_max = INT_MIN;

    for (int i = 0; i < size; i++)
    {
        if (array[i] > firstNum_max)
        {
            secondNum_max = firstNum_max;
            firstNum_max = array[i];
        }
        else if (array[i] > secondNum_max && array[i] < firstNum_max)
        {
            secondNum_max = array[i];
        }
    }
    return secondNum_max;
}
void zd1()
{
    //  Найдите второй по величине элемент в одномерном массиве.
    const int size = 10;
    int array[size];
    writeTo1Array(array, size);
    outputArray(array, size);
    int secondMaxNum = searchSecondNumMax(array, size);
    cout << "Второй по величине элемент в одномерном массиве: " << secondMaxNum << endl;
}
void writeToMatrixArray(int array[][4][5], int x, int y, int z)
{
    srand(time(0));
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            for (int k = 0; k < z; k++)
            {
                array[i][j][k] = rand() % 201 - 100;
            }
        }
    }

}
void outputMatrixArray(int array[][4][5], int x, int y, int z
)
{
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            for (int k = 0; k < z; k++)
            {
                cout << array[i][j][k] << "\t";
            }
            cout << endl;
        }
        cout << endl;
    }
}
void countNegativeElements(int array[][4][5], int x, int y, int z)
{
    for (int i = 0; i < x; i++)
    {
        cout << "Подмассив " << i+1<<": " << endl;
        for (int j = 0; j < y; j++)
        {
            int count = 0;
            for (int k = 0; k <z; k++)
            {
                if (array[i][j][k] < 0)
                {
                    count++;

                }
            }
            cout << "Количество отрицательных элементов в строке: " << j + 1 << ":"<<count << endl;
        }
        cout << endl;
    }
}
void zd2()
{
    //Посчитайте количество отрицательных элементов в каждом двумерном подмассиве.
    const int x = 3;
    const int y = 4;
    const int z = 5;
    int array_matrix[x][y][z];
    writeToMatrixArray(array_matrix, x, y, z);
    outputMatrixArray(array_matrix, x, y, z);
    countNegativeElements(array_matrix, x,y,z);
}
struct Product {
    char name[100];
    float price;
};
Product writetToProductInfo()
{
    Product product;
    char name_entryUser[100];
    float price_entryUser;

    cout << "Введите название продукта" << endl;
    cin >> name_entryUser;

    cout << "Введите стоимость продукта" << endl;
    cin >> price_entryUser;

    strcpy_s(product.name, name_entryUser);
    product.price = price_entryUser;

    cout << "Добавлен продукт -'" << name_entryUser << "' - " << price_entryUser << "руб."<<endl;
    return product;
}
void zd3()
{
    //Создайте структуру "Product" с полями "name" (массив символов) и "price" (вещественное число). Напишите программу на C++, которая выводит информацию о продукте и рассчитывает скидку на продукт.
    Product product = writetToProductInfo();
    int discount = 0
        ;
    if (product.price >= 1000.0)
    {
        discount = 5.0;
    }
    else if (product.price >= 2000.0)
    {
        discount = 10.0;
    }
    float amountDiscount = product.price * (discount / 100.0);
    float discountPrice = product.price - amountDiscount;
    cout << "Цена со скидкой: " << discountPrice << endl;
    
}
class Book
{
private: 
    char title[100];
private:
    char author[100];
private:
    int year;

    public:
    void outputInfoBook()
    {
        cout << "Название книги: " << title << endl << "Автор: " << author <<endl << "Год: " << year<<endl;
    }

    public: 
    void setBookInfo(const char* newTitle, const char* newAuthor, int newYear)
    {
        strcpy_s(title, newTitle);
        strcpy_s(author, newAuthor);
        year = newYear;
    }
};
Book writeToBookInfo()
{
    Book book;
    char title[100];
    char author[100];
    int year;
    cout << "Введите название книги" << endl;
    cin >> title;

    cout << "Введите автора" << endl;
    cin >> author;

    cout << "Введите год" << endl;
    cin >> year;

    book.setBookInfo(title, author, year);
    
    return book;
}
void zd4()
{
    Book book = writeToBookInfo();
    book.outputInfoBook();
}

int main()
{
    setlocale(LC_ALL, "rus");
    int num_zd = 0;

    cout << "Выберите задание - 1,2,3,4." << endl;
    cin >> num_zd;
    switch (num_zd)
    {
        case 1:
            zd1();
            break;
        case 2:
            zd2();
            break;
        case 3:
            zd3();
            break;
        case 4:
            zd4();
            break;
        default: break;
    }
}
