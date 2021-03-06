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
     void double_insert(int input_number){
           int i,j,k,l;
           int counter[TABLE_SIZE];
           
           int q;
           for (q=0;q<TABLE_SIZE;q++){

               counter[q] = 0;
           }

           i = input_number % 10;
           j = input_number % 10;

           k = 7-(input_number%7);

           l = 1;
	       while (table[j] != 0){
                if (counter[j] != 0){
                    cout << input_number << " cannot be inserted"<<endl;
                    return;
                } 

                counter[j] = 1;
                j = (i+l*k)%10;
                l++;
           }

           table[j] = input_number;

      }



      void output(){
           int s;
           for(s=0;s<TABLE_SIZE;s++){
                if (table[s] == 0)
                     cout << s << endl;
                else
                     cout << s << " " << table[s] << endl ; 
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
        table->double_insert(input_number);

        input_times++;
    }
    
    table->output();


    return 0;
}