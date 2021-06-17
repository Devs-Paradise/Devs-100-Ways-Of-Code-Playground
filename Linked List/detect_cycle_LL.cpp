#include<iostream>
using namespace std;

class node{
    public : 
        int data;
        node* next;

        node(int val){
            data = val;
            next = NULL;
        }
};

// This function Displays our Linked List
void display(node* head){    
    node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

//This function Detects Cycle
// return 1 if cycle detected 
// else returns 0
bool detectCycle(node* &head){
    node* fast = head;
    node* slow = head;

    while(fast != NULL && fast->next != NULL){
        // fast will take 2 steps each time 
        // slow will take 1 step each time
        fast = fast->next->next; 
        slow = slow->next;

        //If fast and slow meets at some point
        // It means they are traversing in Cycle
        // so it will return true (i.e. Cycle is present)
        if (fast == slow)       
            return true;
        
    }
    // If fast and slow meets nowhere and fast hits the NULL
    // It means no cycle is present.
    return false;
}


//This function Will remove the cycle present in the Linked List
void removeCycle(node* &head){
    node* fast = head;
    node* slow = head;

    do{
        fast = fast->next->next;
        slow = slow->next;
    }while(fast != slow);
    
    fast = head;
    while(fast->next != slow->next){
        fast = fast->next;
        slow = slow->next;
    }

    slow->next = NULL;
}

int main(){
    node* head = new node(1);
    head->next = new node(2);
    head->next->next = new node(3);
    head->next->next->next = new node(4);
    head->next->next->next->next = new node(5);
    head->next->next->next->next->next = new node(6);
   // Linked List : 1 -> 2 -> 3 -> 4 -> 5 -> 6


    head->next->next->next->next->next->next = head->next->next;
    /* This will make a Cycle in our Linked List : 1 -> 2 -> 3 -> 4
                                                             ^    ^          
                                                              \    \
                                                               6 <- 5
                                                        
    */
   // Displaying Linked list with cycle will led to INFINITE LOOP 
                                                        
    cout<<detectCycle(head)<<endl; // Output : 1
    // This function detects the cycle in our Linked list. (1 : Cycle detected , 0 : cycle is not present)

    if(detectCycle(head))
        removeCycle(head);
    // This function will remove the cycle present in our LinkedList.

    display(head);
    // Display Linked List after removing cycle : 1 -> 2 -> 3 -> 4 -> 5 -> 6
    
}