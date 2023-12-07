
#include <iostream>
using namespace std;



int new_transaction;



// Initialising the balance amount as 0.

float balance_amount = 0.0;



// Function for operations in ATM Machine

void atm_machine_transaction(){

    cout << "Choices Available in the ATM Machine" << endl;

    cout << "1. Deposit Money" << endl;

    cout << "2. Withdraw Money" << endl;

    cout << "3. Balance Amount" << endl;

    cout << "\n";

    /*

        Take an appropriate option to select which operation

        you want to be performed by the ATM Machine.

    */

   

    int option;

    cout << "Your option: ";

    cin >> option;

    float withdraw_amount;

    float deposit_amount;



    switch(option)

    {

        // Case for Depositing money

        case 1:

            cout << "\nEnter the amount to deposit: ";

            cin >> deposit_amount;

            balance_amount += deposit_amount;



            cout << "Your current balance is Rs. " << balance_amount << ". Thanks for depositing!" << endl;

            cout << "Do you want a new transaction?\nPress 1 to 'proceed' and 2 to 'exit' from here\n" << endl;

            cout << "Your option: ";

            cin >> new_transaction;

            if (new_transaction == 1){

                atm_machine_transaction();

            }

        break;

       

        // Case for Money Withdrawal

        case 2:

            cout << "\nPlease enter amount to withdraw: ";

            cin >> withdraw_amount;

            if (withdraw_amount > balance_amount)

            {

                cout << "Insufficient fund! Please proceed to deposit money." << endl;

                cout << "Do you want a new transaction?\nPress 1 to 'proceed' and 2 to 'exit' from here\n" << endl;

                cout << "Your option: ";

                cin >> new_transaction;

                if (new_transaction == 1){

                    atm_machine_transaction();

                }

            }

            else

            {

                balance_amount -= withdraw_amount;

                cout << "You have withdrawn Rs. " << withdraw_amount << " and your balance is Rs. " << balance_amount << endl;

                cout << "Do you want a new transaction?\nPress 1 to 'proceed' and 2 to 'exit' from here\n" << endl;

                cout << "Your option: ";

                cin >> new_transaction;

                if (new_transaction == 1){

                    atm_machine_transaction();

                }

            }

        break;

       

        // Case for checking current bank amount

        case 3:

            cout << "Your current bank balance is: " << balance_amount << endl;

            cout << "Do you want a new transaction?\nPress 1 to 'proceed' and 2 to 'exit' from here\n" << endl;

            cout << "Your option: ";

            cin >> new_transaction;

            if (new_transaction == 1){

                atm_machine_transaction();

            }

        break;

    }

}



int main()

{

    atm_machine_transaction();

    cout << "Thank you for the visit!";

    return 0;

}