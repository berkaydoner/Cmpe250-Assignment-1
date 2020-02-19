/*
Student Name: Berkay Döner
Student Number: 2017400117
Project Number: 1
Compile Status: [SUCCESS]
Running Status: [SUCCESS]
Notes: Anything you want to say about your code that will be helpful in the grading process.
*/

#include "Restaurant.h"

using namespace std;

void Restaurant::execute(const vector<string>& operations) {
    for (const string& op : operations){
        cout << "Operation: " << op << "\t"; 
            if((op.compare("N"))==0){ //Checks if the symbol is N
                for(int i=0;i<tables.size();i++){//Loops through the tables starting from the beginning.
                    if(!tables[i].isOccupied()){//Looks for an empty table
                        tables[i].occupy();
                        break;//Since an empty table is found, no need to traverse anymore.
                    }
                }
            }
            else if((op.compare("S")==0)){//Checks if the symbol is S
                for(int i=tables.size()-1;i>=0;i--){//Loops through the tables starting from the end.
                    if(!tables[i].isOccupied()){//Looks for an empty table
                        tables[i].occupy();
                        break;//No need to traverse more.
                    }
                }
            }
            else{//If symbol is not N or S, then it should be a number.
                tables[stoi(op)-1].empty();//Updates the corresponding table's status as empty.
                //We subtract 1 since table numbers start from 1 but indexing starts from 0.
            }
		/* YOU NEED TO IMPLEMENT THIS PART */

        cout << "State: " << *this << endl;
    }
}

Restaurant::Restaurant(unsigned int N)
	: tables{N}
{
    cout << "-Starting- \tState: " << *this << endl;
}

ostream &operator<<(ostream &out, Restaurant &restaurant) {
    for (Table table : restaurant.tables) {
        out << table.isOccupied();
    }
	return out;
}

