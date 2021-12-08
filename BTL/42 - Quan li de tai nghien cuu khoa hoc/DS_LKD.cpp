#include <bits/stdc++.h>
using namespace std;
struct NODE{
    int data;
    NODE *next;
};
int main(){
    NODE *head = new NODE();
    head->data = 1;
    head->next = NULL;

    NODE *second = new NODE();
    second->data = 2;
    head->next = NULL;

    NODE *third = new NODE();
    third->data = 3;
    head->next = NULL;
    //liên kết các node lại với nhau
    head->next = second;
    second->next = third;
    //truy cập phần tử
    int data = head->data;
    cout<<data<<endl;
    //truy cập đến tất cả các phần tử trong NODE
    NODE *p = head;
    while(p!=NULL){
        data = p->data;
        p=p->next;
        cout<<data<<"->";
    }
    cout<<endl;
}
