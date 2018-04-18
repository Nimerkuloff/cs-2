//
// Created by nimerkuloff on 17/04/18.
//

#include "listLogic.h"

void search(list *head, string input) {
    int x = stoi(input, nullptr ,16);
    struct list *current = head;  // Initialize current
    while (current != NULL) {
        if (current->val == x){
            cout<<endl<<"Yeah. It is in list"<<endl;
            return ; }
        current = current->next;
    }
    cout<<endl<<"There is no this number in list"<<endl;
    return ;
}

void addNumber(list *&ph) {//позиция строки в тексте не сохраняется - Вызвав addNumber 2 раза, получаем одно число
    char     check;
    bool   isItEnd=false;
    int      current=0;
    ifstream fillListStream;

    fillListStream.open("filefile");

    //Файл не создан (не открыт) - возвращаемся в место вызова функции
    if (!fillListStream.is_open()) {
        cout << "Error opening file" << endl;
        return;
    }

    do {
        fillListStream >> hex >> current;
        addFirst(ph, current);

        cout << "More? (y/n)" << endl;
        cin >> check;
        switch (check) {
            case 'y':
                break;
            case 'n':
                isItEnd = true;
                break;
            default:
                cout << "Not a Valid Choice. \n";
                cout << "Choose again.\n";
                cin >> check;
                break;
        }
    }
    while (!isItEnd);
    fillListStream.close();
    return;
}
/*
void fillList(list *&ph){//добавляем элементы в голову списка

    ifstream fillListStream;
    fillListStream.open("filefile");

    //Файл не создан (не открыт) - возвращаемся в место вызова функции
    if (!fillListStream.is_open()) {
        cout << "Error opening file" << endl;
        return ;
    }
    int current =0;
    for (int i = 0; i < 555; i++) {
        fillListStream >> hex >> current;
        addFirst(ph,current);//
    }
    fillListStream.close();

};
*/
// Исключение из очереди и стека – удаление первого элемента списка
int removeFirst(list *&ph) {
    if (ph == nullptr) return -1;
    list *q = ph;            // запомнить текущий
    ph = ph->next;          // сдвинуться к следующему
    int v = q->val;        //
    delete q;             // удалить текущий
    return v;
}

// Включение в начало списка - помещение в стек
void addFirst(list *&ph, int v) {
    list *q = new list;
    q->next = nullptr;
    q->val = v;
    q->next = ph;            // следующий за новым - бывший первый
    ph = q;
}

void print(list *&ph) {
   list* saveHeadPos=ph;
    while (ph) {
        cout << hex << "[" << ph->val << "] ";
        ph = ph->next;
    }
    ph=saveHeadPos;
}
