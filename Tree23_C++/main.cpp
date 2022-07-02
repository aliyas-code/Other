#include "Tree23.h"
#include <iostream>
#include <math.h>
namespace TestEffect
{
    void test_rand(int n);
    void test_sort(int n);
    typedef unsigned long long INT_64;
    INT_64 lrand() { return rand() << 16 | rand(); }
}
//---------------------------------------------------------------------------
//Меню
int main() {
    T23<int, int> tree;
    T23<int, int>::Iterator it = T23<int, int>::Iterator(&tree);
    setlocale(LC_ALL,"RUS");
    while(true)
    {
        cout<<"1. Просмотр дерева"<<endl;
        cout<<"2. Очистка дерева"<<endl;
        cout<<"3. Проверка на пустоту"<<endl;
        cout<<"4. Поиск данных с заданным ключом"<<endl;
        cout<<"5. Добавление данных с заданным ключом"<<endl;
        cout<<"6. Удаление данных с заданным ключом"<<endl;
        cout<<"7. Опрос размера дерева"<<endl;
        cout<<"8. Итератор"<<endl;
        cout << "9. Тестирование (случайное)" << endl;
        cout << "10. Тестирование (вырожденное)" << endl;
        int n = 0;
        int t;
        int value, key;
        cin>>t;
        switch(t)
        {
            case 1:
                tree.Show();
                break;
            case 2:
                tree.Clear();
                break;
            case 3:
                cout<< tree.IsEmpty() <<endl;
                break;
            case 4:
                cin >> key;
                try
                {
                    cout << tree.GetData(key) << endl;
                }
                catch (TreeException e)
                {
                    cerr << e.What() << endl;
                }
                break;
            case 5:
                cin>>key;
                cin>>value;
                cout << tree.Insert(key, value) << endl;
                break;
            case 6:
                cin>>key;
                cout << tree.Delete(key) << endl;
                break;
            case 7:
                cout<<tree.GetSize() << endl;
                break;
            case 8: {
                system("cls");
                bool exit=false;
                while (!exit) {
                    cout<<"1. Просмотр текущего"<<endl;
                    cout<<"2. Установка на первый"<<endl;
                    cout<<"3. Установка на послендний"<<endl;
                    cout<<"4. Следующий"<<endl;
                    cout<<"5. Предыдущий"<<endl;
                    cout<<"6. Проверка состояния"<<endl;
                    cout<<"7. Изменение данных"<<endl;

                    int it_t;
                    cin>>it_t;
                    switch(it_t) {
                        case 1:
                            try
                            {
                                cout<< *it <<endl;
                            }
                            catch (TreeException e)
                            {
                                cerr << e.What() << endl;
                            }
                            break;
                        case 2:
                            it.beg();
                            break;
                        case 3:
                            it.end();
                            break;
                        case 4:
                            it.next();
                            break;
                        case 5:
                            it.prev();
                            break;
                        case 6:
                            cout<< it.IsOff() << endl;
                            break;
                        case 7:
                            cin>>value;
                            try {
                                *it = value;
                            }
                            catch(TreeException e)
                            {
                                cerr << e.What() << endl;
                            }
                            break;
                        default:
                            exit=true;
                            system("cls");
                            break;
                    }
                }
            }
                break;
            case 9:
                int n;
                cout << "Введите размер дерева:" << endl;
                cin >> n;
                TestEffect::test_rand(n);
                break;
            case 10:
                cout << "Введите размер дерева:" << endl;
                cin >> n;
                TestEffect::test_sort(n);
                break;
            default:
                exit(0);
        }
    }
    return 0;
}
void TestEffect::test_rand(int n)
{
    T23<INT_64, int> tree;

    INT_64* m = new INT_64[n];

    for (int i = 0; i < n; i++)
    {
        m[i] = lrand();
        tree.Insert(m[i], 1);
    }
    tree.getCountNodesView();
    cout << "Размер дерева до: " << tree.GetSize() << endl;

    double I = 0;
    double D = 0;
    double S = 0;

    for (int i = 0; i < n / 2; i++)
        if (i % 10 == 0)
        {
            tree.Delete(lrand());
            D += tree.getCountNodesView();
            tree.Insert(m[rand() % n], 1);
            I += tree.getCountNodesView();
            try
            {
                tree.GetData(lrand());
                S += tree.getCountNodesView();
            }
            catch (TreeException&) { S += tree.getCountNodesView(); }
        }
        else
        {
            int ind = rand() % n;
            tree.Delete(m[ind]);
            D += tree.getCountNodesView();
            INT_64 key = lrand();
            tree.Insert(key, 1);
            I += tree.getCountNodesView();
            m[ind] = key;
            try {
                tree.GetData(m[rand() % n]);
                S += tree.getCountNodesView();
            }
            catch (TreeException&) { S += tree.getCountNodesView(); }

        }


    cout << "Размер дерева после: " << tree.GetSize() << endl;
    cout << "log2(n)=" << (log((double)n) / log(2.0)) << endl;
    cout << "log3(n)=" << (log((double)n) / log(3.0)) << endl;
    cout << "Вставка: " << I / (n / 2) << endl;
    cout << "Удаление: " << D / (n / 2) << endl;
    cout << "Поиск: " << S / (n / 2) << endl;
    delete[] m;
}

void TestEffect::test_sort(int n)
{
    T23<INT_64, int> tree;
    INT_64* m = new INT_64[n];

    for (int i = 0; i < n; i++) {
        m[i] = i * 1000;
        tree.Insert(m[i], 1);
    }
    tree.getCountNodesView();
    double I = 0;
    double D = 0;
    double S = 0;
    cout << "Размер дерева до: " << tree.GetSize() << endl;
    for (int i = 0; i < n / 2; i++)
    {
        if (i % 10 == 0)
        {
            INT_64 k = lrand() % (1000 * n);
            k = k + !(k % 2);
            tree.Delete(k);
            D += tree.getCountNodesView();
            tree.Insert(m[rand() % n], 1);
            I += tree.getCountNodesView();
            k = lrand() % (1000 * n);
            k = k + !(k % 2);
            try {
                tree.GetData(k);
                S += tree.getCountNodesView();
            }
            catch (TreeException&) { S += tree.getCountNodesView(); }
        }
        else
        {
            int ind = rand() % n;
            try
            {
                tree.GetData(m[rand() % n]);
                S += tree.getCountNodesView();
            }
            catch (TreeException&) { S += tree.getCountNodesView(); }
            tree.Delete(m[ind]);
            D += tree.getCountNodesView();
            int k = lrand() % (1000 * n);
            k = k + k % 2;
            tree.Insert(k, 1);
            I += tree.getCountNodesView();
            m[ind] = k;

        }
    }
    cout << "Размер дерева после: " << tree.GetSize() << endl;
    cout << "log2(n)=" << (log((double)n) / log(2.0)) << endl;
    cout << "log3(n)=" << (log((double)n) / log(3.0)) << endl;
    cout << "Вставка: " << I / (n / 2) << endl;
    cout << "Удаление: " << D / (n / 2) << endl;
    cout << "Поиск: " << S / (n / 2) << endl;
    delete[] m;
}
