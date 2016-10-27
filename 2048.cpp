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
        system("clear");
        randomIJ(table);
        printBoard(table);
        cin >> move;
        switch(move){
            case 'a':
                for ( int i = 0 ; i < 5 ; i++ ){
                    for ( int j = 0 ; j < 5 ; j++ ){
                        if (table[i][j] != 0 ){
                            int tempJ = j - 1;
                            for (; tempJ >= 0 ; tempJ--){
                                int tempJplus = tempJ + 1;
                                if ( table[i][tempJ] == 0 ){
                                    table[i][tempJ] = table[i][tempJplus];
                                    table[i][tempJplus] = 0;
                                } else if ( table[i][tempJ] != 0 && table[i][tempJ] == table[i][tempJplus] ){
                                    table[i][tempJ] = table[i][tempJ]*table[i][tempJ];
                                    table[i][tempJplus] = 0;
                                }
                            }
                        }
                    };
                };
                break;
            case 'd':
                for ( int i = 0 ; i < 5 ; i++ ){
                    for ( int j = 0 ; j < 5 ; j++ ){
                        if (table[i][j] != 0 ){
                            int tempJ = j + 1;
                            for (; tempJ < 5 ; tempJ++){
                                int tempJplus = tempJ - 1;
                                if ( table[i][tempJ] == 0 ){
                                    table[i][tempJ] = table[i][tempJplus];
                                    table[i][tempJplus] = 0;
                                } else if ( table[i][tempJ] != 0 && table[i][tempJ] == table[i][tempJplus] ){
                                    table[i][tempJ] = table[i][tempJ]*table[i][tempJ];
                                    table[i][tempJplus] = 0;
                                }
                            }
                        }
                    };
                };
                break;
            case 's':
                break;
            case 'w':
                break;


        };
    }

    return 0;
}
