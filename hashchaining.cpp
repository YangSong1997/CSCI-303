#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;
const int TABLE_SIZE = 10;


struct Node{
    int value;
    struct Node * next;
};
    



class HashTable {
private:

    Node* table[TABLE_SIZE];

public:
    void insert(int input_number){
        int i;
        i = input_number %10;
        Node* node = new Node();
        node->value = input_number;
        node->next =  table[i];
        table[i] = node;
    }


    void output(){
        int s;
        Node* p;
        Node o;
    for(s=0;s<TABLE_SIZE;s++){
        cout << s << " ->" ;
        p = table[s];
        while (p != 0x0){
            o = *p;
            cout << o.value << " ->";
            p = o.next;
        }
        cout << "_"<<endl;
                // cout << table[s] << endl; 
    }
    }
};










/*
 * Main Contains Menu
 */
int main()
{
    
    int input_times = 1;
    int input_number = 1;

    HashTable* table = new HashTable();

        //table->output();

    cout<<"input up to ten integers terminated by a -1"<<endl;

    while(input_times <= 10 ){
        cin>>input_number;
        if (input_number == -1){
            break;
        }

        /* insert into hashtable*/
        table->insert(input_number);
        // cout << "The input is "<< input_number << endl;
        input_times++;
    }
    table->output();


    return 0;
};