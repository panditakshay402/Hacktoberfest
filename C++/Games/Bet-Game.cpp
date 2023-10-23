#include <iostream>
#include <stdlib.h>
using namespace std;
void play();

int main()
{
    char menu;
    cout << "######################### INFO #########################\n";
    cout << "1.You will have only 3 try\n2.If you will win, you will recieve 10 times the amount you bet\n\n";
    cout << "Press Y to start the game or press N to exit:- \n";
    cin >> menu;
    if (menu == 'Y' || menu == 'y')
    {
        play();
    }
    else
    {
        cout << "Exiting game.......\n";
        exit;
    }
}

void play()

{
game:
    char name[20], again;
    int trial, amount, bet, balance, guess = 5, user_guess;
    // cout << "Enter your first name:-";
    // cin >> name;
    cout << "Enter the amount you want to add to your account:- ";
    cin >> amount;
    trial = 3;

    while (trial >= 1)
    {
        if (amount > 0)
        {
        inproperbet:
            cout << "Amount = " << amount << "\nEnter the amount you want to bet:- ";
            cin >> bet;
            if (bet > amount)
            {
                cout << "Invalid input!!! Bet amount is greater than the total amount you have\n";
                goto inproperbet;
            }
            else
            {
            validguess:
                cout << "Guess any number between 1 to 10:- ";
                cin >> user_guess;
                if (user_guess >= 1 && user_guess <= 10 && user_guess == guess)
                {
                    cout << "Congrats you have won the bet\n";
                    cout << "You have won " << bet * 10 << "\nSo your total amount is " << amount + (bet * 10);
                    break;
                }
                else if (user_guess >= 1 && user_guess <= 10)
                {
                    cout << "You have guessed the wrong number\n";
                    amount = amount - bet;
                }
                else
                {
                    cout << "Please enter valid input\n";
                    goto validguess;
                }
            }
            trial = trial - 1;
            cout << "Trials left = " << trial << "\n";
        }
        else
        {
            cout << "You don't have money to bet\n";
            break;
        }
    }

    cout << "Do you want to play again:- \nPress 'y' for yes and 'n' for no :-\n";
    cin >> again;
    if (again == 'y' || again == 'y')
    {
        goto game;
    }
}
