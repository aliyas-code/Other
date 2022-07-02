#include <iostream>
#include <stack>

using namespace std;

template<typename T>
class List {
private:
    template<typename K>
    class Node {
    public:
        int next, prev;
        K data;

        Node() : data(-1), next(-1), prev(-1) {}

        Node(K _data, int _next, int _prev) : data(_data), next(_next), prev(_prev) {}
    };


    stack<int> steck;//для дырок
    int head;


    int Size;


public:
    List(int length); // Конструктор
    ~List(); // Деструктор
    void clear(); // Очистка списка
    bool isEmpty(); // Проверка списка на пустоту
    bool find(T data); // Опрос наличия заданного значения
    T GetValue(int index); // Чтение значения с заданным номером в списке
    void SetValue(T data, int index); // Изменение значения с заданным номером в списке
    int GetPos(T data); // Получение позиции в списке для заданного значения
    int L_Size();//Просмотр размера списка
    void add(T data); // Включение нового значения
    void insert(T data, int index); // Включение нового значения в позицию с заданным номером
    void remove(T data); // Удаление заданного значения из списка
    void removeAt(int index); // Удаление значения из позиции с заданным номером
    void Print();

    int for_4;
    int for_9;
    int for_11;
    Node<T> *arr;


    class Iterator {
        List<T>* list; // Текущий список
        int node; // Элемент списка

    public:
        Iterator(List<T>* lst) // Конструктор итератора
        {
            list = lst;
            node = 1;          //дефолтное значение итератора
        }

        T begin() // Запрос прямого итератора
        {
            if(list->Size!=0) {
                node = list->head;
                return list->arr[node].data;
            }
            else return -1;
        }
        T end() // Запрос прямого итератора
        {
            if(list->Size!=0){
                node = list->head;
                for (int i = 1; i<=list->Size; i++){
                    node = list->arr[node].next;
                }
                return node;
            }
            else return 1;
        }
        T& operator *()
        {   int tmp = list->head;
            int k = -1;
            if ((list->Size != 0)&&(node!=-1)){
                if(node >list->Size){
                    node=list->Size;
                }
                for (int i = 1; i<node; i++){
                    tmp = list->arr[tmp].next;
                }
                return list->arr[tmp].data;
            }
            else
                return k;
        }


        T& operator++(int)
        {
            int tmp = list->head;
            int k= -1;
            if(list->Size==0){
                node = 1;
                return k;
            }
            else if ((list->Size > 1)&&(node!=-1)){
                if(node >list->Size){
                    node=list->Size;
                    return k;
                }
                else if (node < list->Size){
                    node++;

                    for (int i = 1; i<node; i++){
                        tmp = list->arr[tmp].next;
                    }
                    return tmp;
                }
                else{
                    node =-1;
                    return k;
                }
            }
            else
                return k;
        }

        T& operator--(int)
        {
            int k = -1;
            int tmp = list->head;

            if ((node == -1)&&(list->Size != 0)){
                node = list->Size;
                return node;
            }
            else if ((list->Size > 1)&&(node!=list->head)){
                if(node >list->Size){
                    node=list->Size;
                }
                node--;
                for (int i = 1; i<node; i++){
                    tmp = list->arr[tmp].next;
                }
                return tmp;
            }
            else
                return k;
        }

        bool operator==(T it) // перегрузка операции равенства
        {
            return list->arr[node].data == it;
        }
        bool operator!=(T it)
        {
            return list->arr[node].data != it;
        }
    };
};



template<typename T>
List<T>::List(int length)
{
    arr = new Node<T>[length];
    Size = 0;
    head = 0;
    int for_4 = 0;
    int for_9 = 0;
    int for_11 = 0;
}


template<typename T>
List<T>::~List(){
    cout<<"Деструктор List сработал";
    delete[] arr;
}

template<typename T>
bool List<T>::isEmpty() {
    if (Size == 0)
        return true;
    else
        return false;
}
template<typename T>
int List<T>::L_Size(){
    return Size;
}
template<typename T>
void List<T>::clear(){
    int tmp = head;
    for(int i = 0; i<Size; i++){
        steck.push(tmp);
        tmp = arr[tmp].next;
    }
    Size = 0;
}

template<typename K>
bool List<K>::find(K data){
    int tmp = head;
    for_4 = 0;
    for(int i = 1; i<=Size; i++){
        if (data == arr[tmp].data){
            return true;
        }
        tmp = arr[tmp].next;
        for_4++;
    }
    return false;
}



template<typename T>
T List<T>::GetValue(int index){
    int tmp = head;
    for(int i = 1; i<=Size; i++){
        if (i == index){
            return tmp;
        }
        tmp = arr[tmp].next;
    }
    return -1;
}


template<typename K>
void List<K>::SetValue(K data, int index){
    //int tmp = head;
    int tmp = GetValue(index);
    if (tmp != -1){
        arr[tmp].data = data;
        cout<<"Замена прошла успешно"<<endl;
        Print();
    }
    else
        cout<<"Введен некорректный индекс"<<endl;
}

template<typename K>
int List<K>::GetPos(K data){
    int tmp = head;
    for(int i = 1; i<=Size; i++){
        if (data == arr[tmp].data){
            return i;
        }
        tmp = arr[tmp].next;
    }
    return -1;
}


template<typename K>
void List<K>::add(K data) {


    int tmp = head;
    if (steck.empty()){
        if(Size == 0){
            arr[1] = Node<K>(data, -1, -1);
            head = 1;
            Size++;
        }
        else {
            for(int i = 1; i<Size; i++){      //найду индекс последнего элемента
                tmp = arr[tmp].next;
            }
            Size++;
            arr[Size] = Node<K>(data, -1, tmp);
            arr[tmp].next = Size;
        }
    }
    else {
        if(Size == 0){
            Size++;
            arr[steck.top()].data = data;
            arr[steck.top()].next = -1;
            arr[steck.top()].prev = -1;
            head = steck.top();
            cout<<steck.top()<<endl<<Size<<endl;
            steck.pop();
        }
        else{
            for(int i = 1; i<Size; i++){
                tmp = arr[tmp].next;
            }
            Size++;
            arr[steck.top()].data = data;
            arr[steck.top()].next = -1;
            arr[steck.top()].prev = tmp;
            arr[tmp].next = steck.top();
            cout<<steck.top()<<endl<<Size<<endl;
            steck.pop();
        }


    }
    cout<< "Значение добавлено"<<endl;
    Print();
    }




template<typename K>
void List<K>::insert(K data, int index){
    for_9 = 0;
    if ((index<=Size+1)&&(index>=1)){
    int tmp = head;
    if (steck.empty()){
        if (index==1){
            Size++;
            if(Size == 1){
                arr[1].prev = -1;
                arr[1].data = data;
                arr[1].next = -1;
                head = 1;
            }
            else {
                arr[Size] = Node<K>(data, head, -1);
                arr[head].prev = Size;
                head = Size;
            }
        }
        else if (index == Size + 1){
            for(int i = 1; i<Size; i++){
                tmp = arr[tmp].next;
                for_9++;
            }
            Size++;
            arr[Size] = Node<K>(data, -1, tmp);
            arr[tmp].next = Size;
        }
        else {
            for(int i = 1; i<=Size; i++){
                if (i == index){
                    Size++;
                    arr[Size] = Node<K>(data, tmp, arr[tmp].prev);
                    arr[arr[Size].prev].next = Size;
                    arr[tmp].prev = Size;
                    break;
                }
                for_9++;
                tmp = arr[tmp].next;
            }
        }
    }
    else{

        if (index==1){
            Size++;
            if(Size == 1){
                arr[steck.top()].prev = -1;
                arr[steck.top()].data = data;
                arr[steck.top()].next = -1;
                head = steck.top();
                steck.pop();
            }
            else {
                arr[steck.top()].prev = -1;
                arr[steck.top()].data = data;
                arr[steck.top()].next = head;
                arr[head].prev = steck.top();
                head = steck.top();
                steck.pop();
            }
        }
        else if (index == Size + 1){
            for(int i = 1; i<Size; i++){
                tmp = arr[tmp].next;
                for_9++;
            }
            Size++;
            arr[steck.top()].prev = tmp;
            arr[steck.top()].data = data;
            arr[steck.top()].next = -1;
            arr[tmp].next = steck.top();
            steck.pop();
        }
        else {
            for(int i = 1; i<=Size; i++){
                if (i == index){
                    Size++;
                    arr[steck.top()].prev = arr[tmp].prev;
                    arr[steck.top()].data = data;
                    arr[steck.top()].next = tmp;
                    arr[arr[tmp].prev].next = steck.top();
                    arr[tmp].prev = steck.top();
                    //cout<<"Стек топ: "<<steck.top()<<endl;
                    steck.pop();
                    break;
                }
                for_9++;
                tmp = arr[tmp].next;
            }
        }

    }

    Print();
    }
    else {
        cout<<"Некорректный индекс";
    }
}

template<typename K>
void List<K>::remove(K data){
    int tmp = head;
    for(int i = 1; i<=Size; i++){
        if (data == arr[tmp].data){
            removeAt(i);
            return;
        }
        tmp = arr[tmp].next;

    }
    cout<<"Введенного значения нет в списке"<<endl;
}


template<typename T>
void List<T>::removeAt(int index) {
    if ((index<=Size)&&(index>=1)){
    for_11 = 0;
    int tmp = head;
    if (index == 1){
        if (Size == 1){
            steck.push(head);
            Size--;
            head = -1;
        }
        else {
            arr[head].prev = -1;
            steck.push(head);
            Size--;
            head = arr[head].next;
        }
    }
    else if(index == Size){
        for(int i = 1; i<=Size; i++){
            if (i == Size){
                tmp = arr[tmp].prev;
            }
            else{
                tmp = arr[tmp].next;
            }
            for_11++;
        }
        steck.push(arr[tmp].next);
        arr[tmp].next=-1;
        Size--;
    }
    else{
        for(int i = 1; i<=Size; i++){
            if (i == index){
                arr[arr[tmp].prev].next = arr[tmp].next;
                arr[arr[tmp].next].prev = arr[tmp].prev;
                steck.push(tmp);
                Size--;
                break;
            }
            tmp = arr[tmp].next;
            for_11++;
        }
    }
Print();
    }
    else{
        cout<<"Введен некорректный индекс"<<endl;
    }
}



template<typename T>
void List<T>::Print(){
    int tmp = head;
    cout <<"Список: "<<endl;
    for(int i = 0; i<Size; i++){
        cout<<arr[tmp].data<<' ';
        tmp = arr[tmp].next;
    }
}


#ifndef AISD_LR1_CLASS_1_H
#define AISD_LR1_CLASS_1_H

#endif
