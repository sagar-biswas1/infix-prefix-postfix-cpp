
#include<bits/stdc++.h>
using namespace std;


template <typename T>
class Node
{
public:
    T value;
    Node *next;
    Node *pre;
    Node(T val)
    {

        value= val;
        next=NULL;
        pre=NULL;
    }

};


template <typename T>
class Stack
{
    Node<T> *head;
    Node<T> *top;
    int count=0;
public:
    Stack(){
    top=head=NULL;
    }
    void push(T val)
    {

        Node <T>*newNode =new Node<T>(val);
        if(head==NULL)
        {
            head = top= newNode;
            count++;
            return;
        }
        top->next=newNode ;

        newNode->pre=top;
        top = newNode;
        count++;
    }

    T pop()
    {
        Node <T>*delNode;
        delNode = top;
        T val;
        if(head==NULL)
        {
            cout<< "no element in the stack"<<endl;

            return val;
        }
        if(top==head)
        {
            top=head=NULL;

        }
        else
        {

            top= delNode->pre;
            top->next= NULL;
        }
        val = delNode->value;
        delete delNode;
        count--;
        return val;

    }

    bool empty()
    {
        if(head==NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    T Top(){
        T check;
     if(top==NULL)
        {
            return check;
        }
        else
        {
            return top->value;
        }


    }
    int size(){
    return count;
    }
};

