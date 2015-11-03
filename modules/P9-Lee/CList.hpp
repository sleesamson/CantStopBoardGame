#include "tools.hpp"
#pragma once

template <class T>
class CList;

template <class T>
class Cell{
    friend class CList<T>;
    private:
        T* data;
        Cell* next;

        Cell(T* dt, Cell* nx = NULL): data(dt), next(nx) {}
        ~Cell() {delete data;}
};

template <class T>
class CList{
    private:
        int count;
        Cell<T> * head;
        Cell <T> * tail;
        Cell<T> * current;

    public:
        CList():count(0), head(NULL), tail(NULL), current(NULL) {}
        ~CList();

        int get_count() const {return count;}
        bool is_empty() const {return head == NULL;}

        void insert(T* data);
        T* first();
        T* next();
        void remove();
        ostream& print( ostream& out ) const;
};
//--------------------------------------------------------------------
template <class T> inline ostream& operator << (ostream& out ,const CList<T>& L){
    return L.print(out);
}

//----------------------------------------------------------------
template <class T>
CList<T>::~CList()
{
    while(head)
    {
        Cell<T>* temp = head;              //point at head
        if(temp->next == head)              //if only one item in list
        {
            head = NULL;
            tail = NULL;
            current = NULL;
            delete temp;
        }
        else{
            head = head->next;
            tail->next = head;
            delete temp;
        }
    }

}

//----------------------------------------------------------------
template <class T>
void CList<T>::insert(T* data)
{
    Cell<T> * p = new Cell<T>(data);

    if (is_empty()){
        head = p;
        head->next = head;
        current = head;
        tail = head;
    }
    else{
        p->next = head;
        tail->next = p;
        tail = p;
    }
    count++;
}

//----------------set current pointer to head---------------------
template <class T>
T* CList<T>::first() {
    if (is_empty()){
        cout << "No Players have been added to the game yet!" << endl;
    }
    else{
        current = head;
        return current->data;
    }
}

//-----------move current to next player in list------------------
template <class T>
T* CList<T>::next() {
    if(is_empty())
        cout << "No Players are in the game!" << endl;
    else{
        current = current->next;
        return current->data;
    }
}

//----------------------------------------------------------------
template <class T>
void CList<T>::remove(){
    Cell <T> * temp = current;
    if (current == head){
        if (tail == head)
        {
            tail = NULL;
            head = NULL;
            current = NULL;
        }
        else
        {
            tail->next = head->next;
            head = head->next;
            current = tail;
        }
    }
    else if (current != tail)               //current somewhere in middle
    {
        do{
            current = current->next;            //move current to previous
        }while(current->next != temp);

        current->next = temp->next;
    }
    else                                    //current @ tail
    {
        do{
            current = current->next;
        }while (current->next != temp);
        tail = current;
        current->next = temp->next;
    }
    delete temp;
    count--;
}

//-----------------------------------------------------------------
template <class T>
ostream& CList<T>::print( ostream& out) const{
    Cell<T> * q = head;

    if (is_empty())
        cout << "Nothing to print! List is empty" << endl;
    else{
        do{
            out << *q->data;
            q = q->next;
        }while(q!=head);
    }
}
