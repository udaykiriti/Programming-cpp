#include <bits/stdc++.h>
using namespace std;

/*class Node
{
public:
    T x;
    Node *x;
    Node(t x0){
        x = 0;
        next = NULL;
    }
};
*/

struct Node{    
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = nullptr;
    }
};

void _insert(Node*& head , int val){
    Node* tmp = new Node(val);
    tmp -> next = head;
    head = tmp;
}

void _printerr(){
    cout << "Out of scope" << '\n';
}

void ins_ert(Node*& head , int val , int posi){
    Node* newnode = new Node(val);

    if(0 == posi){
      _insert(head,val);
      return;  
    } 

    Node* tmp = head;

    for (int i = 0; i < posi - 1; ++i) {
        if(tmp == nullptr){
            _printerr();
            delete newnode;
            return;
        }
        tmp = tmp -> next;
    }

    if(tmp == nullptr){
        _printerr();
        delete newnode;
        return;
    }

    newnode -> next = tmp -> next;
    tmp -> next = newnode;
}

void insert_(Node*& head , int val){
   Node* newnode = new Node(val);

   if(head == nullptr){
    head = newnode;
    return;
   }
   // try to code i u r way...
   Node* temp = head;
   for( ; temp -> next!= nullptr ; temp = temp->next);
   temp->next = newnode;
}


void _delete(Node*& head){
    if(nullptr == head){
        cout << "Ohhh ll is mt..." << '\n';
        return;
    }
    Node* temp = head;
    head = head -> next;
    delete temp;
    // temp = nullptr;
}

void del_ete(Node*& head , int posi){

    if(nullptr == head){
        _printerr();
        return;
    }

    if(0 == posi){
        _delete(head);
        return;
    }

    Node* temp = head;

    for(int i = 0 ; i < posi - 1 ;i++){
        if(nullptr == temp -> next){
            cout << "Out of range" << '\n';
            return;
        }
        temp = temp -> next;
    }
    //del node
    Node* rm = temp -> next;

    if(nullptr == rm){
        cout << "posi out of rng" << '\n';
        return;
    }
    temp -> next = rn -> next;
    delete rm;
}

void delete_(Node*& head) {
    if (head == nullptr) {
        cout << "ll is mt" << '\n';
        return;
    }

    if (nullptr == head->next) {
        delete head;
        head = nullptr;
        return;
    }

    Node* temp = head;

    while (temp->next->next != nullptr) {
        temp = temp->next;
    }

    delete temp->next;
    temp->next = nullptr;
}
    
void printlist(Node* head){
    Node* tmp = head;
    /*
    while(tmp -> next){
        cout << tmp-> data << " ";
        tmp = tmp -> next;
    } cout << tmp -> data << '\n';
    */
    Node* some; //for to print last node data...
    for(const Node* tmp = head; tmp->next != nullptr ; tmp = tmp->next){
        cout << tmp->data << ' ';
        some = tmp -> next;
    }
    cout << some -> data << '\n';
}

int main(int argc, char const *argv[])
{
    Node *tmp = new Node(30);
    Node* head = new Node(10);
    Node* second = new Node(20);
    head -> next = second;
    head -> next -> next = tmp;
    printlist(head);
    _insert(head , 5);
    printlist(head);
    insert_(head, 4);
    printlist(head);
    ins_ert(head , 3 , 1);
    printlist(head);
}