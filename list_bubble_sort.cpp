/******************************************************************************

*******************************************************************************/

#include <iostream>

using namespace std;
#define DATA( node ) (node->data)
#define NEXT( node ) (node=node->next)
struct Node {
    string data;
    Node *next;
    Node (string adata ): data( adata ), next(NULL) { }
};

Node *head=NULL;
void insert(string str) {
    if ( head == NULL ) {
        head = new Node(str); 
    } else {
        Node *new_node=new Node(str);
        new_node->next=head;
        head=new_node;
    }
}

void swap_strings( string &str1, string &str2 ) {
    string temp=str1;
    str1=str2;
    str2=temp;
}

void sort_list( ) {
    Node *lptr=NULL;
    bool swapped=false;
    Node *curr = head;
    do {
        swapped = false;
        curr = head;
        while ( curr->next != lptr ) {
                if ( DATA(curr) > DATA(curr->next) ) {
                    swapped = true;
                    swap_strings( DATA( curr ), DATA( curr->next ) );
                }
                NEXT( curr );
        }
        lptr=curr;
        
    } while ( swapped );
    
}

void print_list( ) {
    Node *curr=head;
    while ( curr ) {
        cout<<DATA( curr )<<"-->";
        NEXT(curr);
    }
    cout<<"NULL"<<endl;
}

int main()
{
    insert("31");
    insert("12");
    insert("55");
    insert("15");
    print_list();
    sort_list();
    print_list();
    return 0;
}
