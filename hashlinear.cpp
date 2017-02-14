#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;
const int TABLE_SIZE = 10;


class HashTable {
private:
      int table[TABLE_SIZE];
  public:
      void linear_insert(int input_number){
           int i;
           i = input_number % 10;

	    while (table[i] != 0){
                i = (i+1)%10;
           }
           table[i] = input_number;
      }


      void output(){
           int s;
           for(s=0;s<TABLE_SIZE;s++){
                if (table[s]==0)
                     cout << s <<endl;
                else
                     cout << s << " " << table[s] << endl ; 
           }
      }
};


/*
 * Main Contains Menu
 */
int main(){
    int input_times = 1;
    int input_number = 1;
    HashTable* table = new HashTable();



    cout<<"input up to ten integers terminated by a -1"<<endl;
    while(input_times <= 10 ){
        cin>>input_number;
        if (input_number == -1){
            break;
        }

        /* insert into hashtable*/
        table->linear_insert(input_number);

        input_times++;
    }
    table->output();

    

    return 0;
}