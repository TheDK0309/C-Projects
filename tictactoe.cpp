#include <iostream>
using namespace std;

char board[10] = {'o','1','2','3','4','5','6','7','8','9'};

int checkwin();
void playing_board();

int main()
{
	int player = 1,i,choice;

    char mark;
    do
    {
        playing_board();
        player=(player%2)?1:2;

        cout << "Player " << player << ", enter a number:  ";
        cin >> choice;

        mark=(player == 1) ? 'X' : 'O';

        if (choice == 1 && board[1] == '1')

            board[1] = mark;
        else if (choice == 2 && board[2] == '2')

            board[2] = mark;
        else if (choice == 3 && board[3] == '3')

            board[3] = mark;
        else if (choice == 4 && board[4] == '4')

            board[4] = mark;
        else if (choice == 5 && board[5] == '5')

            board[5] = mark;
        else if (choice == 6 && board[6] == '6')

            board[6] = mark;
        else if (choice == 7 && board[7] == '7')

            board[7] = mark;
        else if (choice == 8 && board[8] == '8')

            board[8] = mark;
        else if (choice == 9 && board[9] == '9')

            board[9] = mark;
        else
        {
            cout<<"Invalid move ";

            player--;
            cin.ignore();
            cin.get();
        }
        i=checkwin();

        player++;
    }while(i==-1);
    playing_board();
    if(i==1)

        cout<<"==>\aPlayer "<<--player<<" win ";
    else
        cout<<"==>\aGame draw";

    cin.ignore();
    cin.get();
    return 0;
}

int checkwin()
{
    if (board[1] == board[2] && board[2] == board[3])

        return 1;
    else if (board[4] == board[5] && board[5] == board[6])

        return 1;
    else if (board[7] == board[8] && board[8] == board[9])

        return 1;
    else if (board[1] == board[4] && board[4] == board[7])

        return 1;
    else if (board[2] == board[5] && board[5] == board[8])

        return 1;
    else if (board[3] == board[6] && board[6] == board[9])

        return 1;
    else if (board[1] == board[5] && board[5] == board[9])

        return 1;
    else if (board[3] == board[5] && board[5] == board[7])

        return 1;
    else if (board[1] != '1' && board[2] != '2' && board[3] != '3' 
                    && board[4] != '4' && board[5] != '5' && board[6] != '6' 
                  && board[7] != '7' && board[8] != '8' && board[9] != '9')

        return 0;
    else
        return -1;
}

void playing_board()
{
    system("cls");
    cout << "\n\n\tTic Tac Toe\n\n";

    cout << endl;

    cout << "     |     |     " << endl;
    cout << "  " << board[1] << "  |  " << board[2] << "  |  " << board[3] << endl;

    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;

    cout << "  " << board[4] << "  |  " << board[5] << "  |  " << board[6] << endl;

    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;

    cout << "  " << board[7] << "  |  " << board[8] << "  |  " << board[9] << endl;

    cout << "     |     |     " << endl << endl;
}