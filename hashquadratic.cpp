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

      void quad_insert(int input_number){
           int i,j,k,l;
           i = input_number %10;
           j = input_number %10;

           // make a counter array
           int counter[TABLE_SIZE];
           // initialize to 0
           for (k=0;k<TABLE_SIZE;k++){
                counter[k]=0;
           }
          
          
          l = 1;
          while (table[j] != 0){
              if (counter[j] == 1){
                  cout << input_number << " cannot be inserted"<<endl;
                  return;
              }
              
              counter[j] = 1;
              j = (int) (i + pow(l,2)) % 10;
              l++;
          }

          
          
           table[j] = input_number;
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
        table->quad_insert(input_number);

        input_times++;
    }
    table->output();

    return 0;
}