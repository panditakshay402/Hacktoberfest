// Designed by Abhinav Singh (inspired online)
// Date:- 20 April,2022
#include <iostream>
using namespace std;
void board();
int winner();
char position[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

int i = -1;

// This is the main function. Game is started here only.
int main()
{
    int choice, player = 1, mark;
    board();
    do
    {

        player = (player % 2) ? 1 : 2;
        cout << "Player " << player << " Enter your choice:- ";
        cin >> choice;
        mark = (player == 1) ? 'X' : 'O';
        if (choice == 1 && position[1] == '1')
            position[1] = mark;
        else if (choice == 2 && position[2] == '2')
            position[2] = mark;
        else if (choice == 3 && position[3] == '3')
            position[3] = mark;
        else if (choice == 4 && position[4] == '4')
            position[4] = mark;
        else if (choice == 5 && position[5] == '5')
            position[5] = mark;
        else if (choice == 6 && position[6] == '6')
            position[6] = mark;
        else if (choice == 7 && position[7] == '7')
            position[7] = mark;
        else if (choice == 8 && position[8] == '8')
            position[8] = mark;
        else if (choice == 9 && position[9] == '9')
            position[9] = mark;
        else
        {
            cout << "Invalid Input \n";
            system("pause");
            player--;
        }
        player++;
        board();
        i = winner();
        if (i == 1)
        {
            cout << "Player " << --player << " Has won the game";
        }
        else if (i == 0)

        {
            cout << "Game over. No winner";
        }
        else
            continue;

    } while (i == -1);
    return 0;
}

int winner()
{

    if (position[1] == position[2] && position[2] == position[3])
        return 1;

    else if (position[1] == position[4] && position[4] == position[7])
        return 1;

    else if (position[1] == position[5] && position[5] == position[9])
        return 1;

    else if (position[2] == position[5] && position[5] == position[8])
        return 1;

    else if (position[3] == position[6] && position[6] == position[7])
        return 1;

    else if (position[3] == position[5] && position[5] == position[7])
        return 1;

    else if (position[4] == position[5] && position[5] == position[6])
        return 1;

    else if (position[7] == position[8] && position[8] == position[9])
        return 1;
    else if (position[1] != '1' && position[2] != '2' && position[3] != '3' && position[4] != '4' && position[5] != '5' && position[6] != '6' && position[7] != '7' && position[8] != '8' && position[9] != '9')
        return 0;

    else
        return -1;
}

// This is the function to create board.

void board()
{
    system("cls");
    cout << "Player 1 ='X' and Player 2 = 'O'\n\n";
    cout << "       |       |       \n";
    cout << "   " << position[1] << "   |   " << position[2] << "   |   " << position[3] << "\n";
    cout << "       |       |       \n";
    cout << "-------|-------|-------\n";
    cout << "       |       |       \n";
    cout << "   " << position[4] << "   |   " << position[5] << "   |   " << position[6] << "\n";

    cout << "       |       |       \n";
    cout << "-------|-------|-------\n";
    cout << "       |       |       \n";
    cout << "   " << position[7] << "   |   " << position[8] << "   |   " << position[9] << "\n";

    cout << "       |       |       \n";
}
