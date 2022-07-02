#include <iostream>
#include "List.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>


using namespace std;
int Menu();
int GetNumber(int, int);
void ExitBack();


int main(){

    setlocale(LC_ALL, "Russian");
    bool done = false;

    List<int>p(10);
    List<int>::Iterator it(&p);
    while (!done) {
        switch (Menu()) {
            case 1:{
                if(p.isEmpty()){
                    cout<<"Список пуст"<<endl;
                }
                else{
                    p.Print();
                }

            }
                break;
            case 2:{
                cout << "Вы уверены, что хотите очистить список?" << endl<< "1. Да" << endl << "2. Нет" << endl;
                switch (GetNumber(1, 2)){
                        case 1: {
                            p.clear();
                            cout<<"Cписок отчищен"<<endl;
                        }
                            break;
                        case 2:
                            break;
                }

            }
                break;
            case 3:{
                if(p.isEmpty()){
                    cout<<"Список пуст"<<endl;
                }
                else{
                    cout<<"Список не пуст"<<endl;
                }

            }
                break;

            case 4:
                {
                    int l;
                    cout<<"Введите значение: "<<endl;
                    cin >>l;

                    if(p.find(l)){
                        cout<<"Существет"<<endl;
                    }
                    else{
                        cout<<"Не существет"<<endl;
                    }

                }
                break;
            case 5:
            {
                int k;
                cout<<"Введите номер:"<<endl;
                cin>>k;
                int t = p.GetValue(k);
                if(t!=-1)
                    cout<<"Значение: "<< p.arr[t].data<< endl;
                else
                    cout<<"Введен некорректный индекс"<<endl;
            }
                break;
            case 6:
            {
                int k, l;
                cout<<"Введите значение:"<<endl;
                k = GetNumber(-2147483647, 2147483647);
               // cin>>k;
                cout<<"Введите индекс:"<<endl;
                cin>>l;
                //p.Print();
                p.SetValue(k, l);

            }
                break;
            case 7:
            {
                int k;
                cout<<"Введите значение:"<<endl;
                cin>>k;
                int l = p.GetPos(k);
                if (l!=-1){
                    cout<<"Позиция: "<<l<<endl;
                }
                else {
                    cout<<"Такой позиции нет";
                }

            }
                break;
            case 8:
                {
                int k;
                    cout<<"Введите новое значение:"<<endl;
                    k = GetNumber(-2147483647, 2147483647);
                        p.add(k);

            }
                break;
            case 9://
            {
                int k, l;
                cout<<"Введите значение:"<<endl;
                k = GetNumber(-2147483647, 2147483647);
                cout<<"Введите индекс:"<<endl;
                l = GetNumber(-2147483647, 2147483647);

                p.insert(k, l);
            }
                break;
            case 10:
            {
                int k;
                cout<<"Введите значение, которое вы хотете удалить:"<<endl;
                cin>>k;
                p.remove(k);
            }

                break;
            case 11:
            {
                int k;
                cout<<"Введите индекс, значение которого вы хотите удалить:"<<endl;
                k = GetNumber(-2147483647, 2147483647);
                p.removeAt(k);
            }
                break;
            case 12:
            {
                int k;
                k = it.begin();
                if (k==-1){
                    cout<<"Ошибка"<<endl;
                }
                else{
                    cout<<"Начальное значение: "<<k<<endl;
                }

            }

                break;
            case 13:
            {
                if (it.end()==-1){             //следующее после последнего значения надо выделить специальным индексом
                    cout<<"Итератор установлен"<<endl;
                }
                else {
                    cout<<"Ошибка"<<endl;
                }
            }

                break;
            case 14:
            {
                int k;
                cout<<"Введите значение: "<<endl;
                k = GetNumber(-2147483647, 2147483647);
                //cin>>k;
                *(it) = k;
                k = -1;
                if(k ==*(it)){
                    cout<<"Ошибка"<<endl;
                    break;
                }
                p.Print();
            }
                break;
            case 15:
            {
                int k;
                k = *it;
                if (k!=-1){
                    cout<<"Значение итератора: "<<k<<endl;
                }
                else{
                    cout<<"Возникла ошибка"<<endl;
                }

            }
                break;
            case 16:
            {
                int k;
                k = it++;
                if (k!=-1){
                    cout<<"Значение переменной, на которой стоит итератор: "<<p.arr[k].data<<endl;
                }
                else
                    cout<<"Ошибка";
            }
                 break;
            case 17:
            {
                int k;
                k = it--;
                if (k!=-1){
                    cout<<"Индекс итератора: "<<k<<endl;
                }
                else
                    cout<<"Ошибка";
            }

                break;
            case 18:
            {
                cout<<"Размер списка: "<<p.L_Size()<<endl;

            }
                break;
            case 19:
            {
                cout<<"Количество просмотренных элементов операцией 4: "<<p.for_4<<endl;


            }
                break;
            case 20:
            {
                cout<<"Количество просмотренных элементов операцией 9: "<<p.for_9<<endl;


            }
                break;
            case 21:
            {
                cout<<"Количество просмотренных элементов операцией 11: "<<p.for_11<<endl;

            }
                break;
            case 0:
                cout << "Конец работы." << endl;
                done = true;
                break;
        }
    }
    return 0;

}



int Menu(){
    cout<<"\n============= Главное меню ============="<<endl;
    cout << "1. Просмотр списка" << endl;
    cout << "2. Очистка списка" << endl;
    cout << "3. Проверка списка на пустоту" << endl;
    cout << "4. Опрос наличия заданного значения" << endl;
    cout << "5. Чтение значения с заданным номером в списке" << endl;
    cout << "6. Изменение значения с заданным номером в списке" << endl;
    cout << "7. Получение позиции в списке для заданного значения" << endl;
    cout << "8. Включение нового значения" << endl;
    cout << "9. Включение нового значения в позицию с заданным номером" << endl;
    cout << "10. Удаление заданного значения из списка" << endl;
    cout << "11. Удаление значения из позиции с заданным номером" << endl;
    cout << "----------------------------------------------" << endl;
    cout << "12. Итератор на начало" << endl;
    cout << "13. Запрос неустановленного итератора end" << endl;
    cout << "14. Изменить значение на позиции итератора" << endl;
    cout << "15. Значение элемента на позиции итератора" << endl;
    cout << "16. Переход к следующему значению" << endl;
    cout << "17. Переход к предыдущему значению" << endl;
    cout << "18. Опрос размера" << endl;
    cout << "----------------------------------------------" << endl;
    cout << "19. Количество просмотренных элементов операцией 4" << endl;
    cout << "20. Количество просмотренных элементов операцией 9" << endl;
    cout << "21. Количество просмотренных элементов операцией 11" << endl;
    cout << "----------------------------------------------" << endl;
    cout << "0. Выход" << endl << endl;
    cout << "Выбор: ";

    return GetNumber(0, 21);
}

int GetNumber(int min, int max){
    int number = min - 1;
    while (true){
        cin >> number;
        if ((number>= min)&&(number<=max)&&(cin.peek() == '\n'))
            break;
        else {
            cout<<"Введите значение int"<<endl;

            cin.clear();
        }
    }
    return number;
}

void ExitBack(){
    cout<<endl<<"Нажмите Enter"<<endl;
    cin.get();
    cin.get();
}

