#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

// Function that initialize table 
void initTable(int table[5][5]){
    for ( int i = 0 ; i < 5 ; i++ ){
        for ( int j = 0 ; j < 5 ; j++ ){
            table[i][j] = 0;
        }
    }
}
int randomIJ(int table[5][5]){
    int i, j = 0;
    for (;;){
        i = rand()%5;
        j = rand()%5;

        if (table[i][j] == 0) {
            table[i][j] = 2;
            break;
        }
    }
}

void printBoard(int table[5][5]){
    for ( int i = 0 ; i < 5 ; i++ ){
        for ( int j = 0 ; j < 5 ; j++ ){
            cout <<"[" << table[i][j] << "] \t";
        }
        cout << "\n";
    }
    cout << "\n\n\n" ;
}

int main() {
    srand (time(NULL));
    int table[5][5];
    int currentTable[5][5];
    char move ;

    initTable(table);
    printBoard(table);

    for(;;){
        randomIJ(table);
        printBoard(table);
        cin >> move;
        switch(move){
            case 'a':
                for ( int i = 0 ; i < 5 ; i++ ){
                    for ( int j = 0 ; j < 5 ; j++ ){
                        int subI = i;
                        int subJ = j;
                        if (table[subI][subJ] != 0 && subJ >= 0){
                            //table[subI][subJ] = 99;
                            while (true){
                                subJ-=1;
                                if (table[i][subJ] == 0 && subJ >= 0) {
                                    int anotherJ = subJ+1;
                                    cout << table[i][subJ] << " :: " << table[i][anotherJ] << endl;
                                    if (table[i][subJ] == table[i][anotherJ]){
                                        table[i][subJ] = 99;
                                        table[i][anotherJ] = 0;
                                        break;
                                    }
                                    table[i][subJ] = table[i][anotherJ];
                                    table[i][anotherJ] = 0;
                                } else break;
                            };
                        }
                    };
                };
                break;
            case 'd':
                break;
            case 's':
                break;
            case 'w':
                break;


        };
    }

    return 0;
}
