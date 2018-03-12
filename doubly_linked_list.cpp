#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node *prev;
};

Node *head = NULL;
Node *tail = NULL;

void add_node_front(int data){
    Node *new_node = new Node();
    new_node->data = data;

    new_node->next = head;
    new_node->prev = NULL;

    if(head != NULL){
        head->prev = new_node;
    }

    if(tail == NULL){tail = new_node;}  
    head = new_node;
}

void add_node_end(int data){
    Node *new_node = new Node();
    new_node->data = data;

    new_node->prev = tail;
    new_node->next = NULL;
    tail->next = new_node;

    if(tail == NULL){
        tail = head = new_node;
        return;
    }
    tail = new_node;
}

void add_node_at(int pos, int data){
    int pos_ = 1;
    if(pos == 1){
        add_node_front(data);
        return;
    }

    Node *n = head;
    while(n != NULL){
        if(pos_ == pos - 1){
            Node *temp = n->next;

            Node *new_node = new Node();
            new_node->data = data;
            
            n->next = new_node;
            new_node->prev = n;

            new_node->next = temp;
            temp->prev = new_node;
            break;
        }
        pos_++;
        n = n->next;
    }
}

void reverse(){
    Node *temp = NULL;

    Node *n = head;
    while(n != NULL){
        temp = n->prev;
        n->prev = n->next;
        n->next = temp;
        n = n->prev;
    }

    if(temp != NULL){
        temp = head;
        head = tail;
        tail = temp;
    }
}

int list_length(Node *n){
    int len = 0;
    while(n != NULL){
        len++;
        n = n->next;
    }
    return len;
}

int delete_at(int pos){
    if(pos > list_length(head)){return -1;}

    if(pos == 1){
        int data = head->data;
        head = head->next;
        head->prev = NULL;
        return data;
    }

    if(pos == list_length(head)){
        int data = tail->data;
        tail = tail->prev;
        tail->next = NULL;
        return data;
    }

    int data;
    int pos_ = 1;
    Node *n = head;
    while(n != NULL){
        if(pos_ == pos-1){
            data = n->next->data;
            n->next = n->next->next;
            n->next->prev = n;
            break;
        }
        pos_++;
        n = n->next;
    }
    return data;

}

void print_list(Node *n){
    cout << "NULL<-->";
    while(n != NULL){
        cout << n->data << "<-->";
        n = n->next;
    }
    cout << "NULL" << endl;
}

int main(int argc, char *argv[]){
    int items[] = {23,34,56,78,97,7};
    for(int i=0;i<(sizeof(items)/sizeof(items[0]));i++){
        add_node_front(items[i]);
    }
    print_list(head);
    add_node_at(2, 33);
    print_list(head);

    add_node_end(44);
    print_list(head);
    delete_at(8);
    print_list(head);

    return 0;
}
