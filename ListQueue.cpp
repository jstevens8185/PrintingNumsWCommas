#include <iostream>

using namespace std;

/*****************************************************************************************
 * Node
 * 
 * Holds a char, keeps track of its position in the queue and points to the next node and prev node
 * 
 * Can be passed a character to store.
 ******************************************************************************************/

struct Node{
    Node* next;
    Node* prev;
    int position;
    char data;
    Node(){
        next = NULL;
        position = 0;
        data = '0';
    }
    Node(char d){
        next = NULL;
        prev = NULL;
        position = 0;
        data = d;
    }
};

/**********************************************************************************************
 * ListQueue
 * 
 * Holds our nodes and connects them in a linked list.
 * 
 **********************************************************************************************/

class ListQueue{
    private:
        Node* front;
        Node* rear;
        int size;
    public:
        ListQueue(){
            front = nullptr;
            rear = nullptr;
            size = 0;
        }

        void push(char x){
            if (!front){
                rear = front = new Node(x);
                size = rear->position = 1;
            }else{
                rear->next = new Node(x);
                rear = rear->next;
                size++;
                rear->position = size;
            }
        }

        void print(){
            Node* current = front;
            while(current != nullptr){
                //cout << " position is: " << current->position << endl;
                cout << current->data;
                if((current->position-1) % 3 == 0 && current->next != nullptr){
                    cout << ",";
                }
                current = current->next;

            }
            //cout << endl << "Size is: " << size;
        };
};

int main(){
    ListQueue list;
    list.push('1');
    list.push('2');
    list.push('3');
    list.push('4');
    list.push('5');
    list.push('6');
    list.push('7');
    list.print();
}


