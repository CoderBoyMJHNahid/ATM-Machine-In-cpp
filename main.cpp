#include <iostream>
#include <map>

using namespace std;
template <class Amount, class UserType>
class Data
{
    Amount machineAmount = 200000;

    string username = "M J H Nahid";
    int password = 1234;
    int amount = 100000;

protected:
    int userGivenPwd;

public:
    Data(void)
    {
        system("cls");
        if (machineAmount < 500)
        {
            cout << "Sorry We can't do processing right now. We don't have enough amount to process with your request.Please contact near branch if you have any query. Thank you!" << endl;
        }
        else if (machineAmount > 500)
        {
            this->pwd_process();
        };
    }
    void viewBalance()
    {
        system("cls");
        cout << "Here is your balance: " << this->amount << endl;
        fflush(stdin);
        getchar();
        viewMenu();
    }
    void withdrawMoney() {
        system("cls");
        int withdrawAmount;
        int secondOption;
        cout << "Please enter withdraw amount: " << endl;
        cin >> withdrawAmount;
        if (withdrawAmount >= 500 && withdrawAmount <= amount && withdrawAmount < machineAmount )
        {
            machineAmount -= withdrawAmount;
            amount -= withdrawAmount;

            cout << "Your withdraw has been successfully Please collect your amount from the account handler" << endl;
            fflush(stdin);
            getchar();
            cout << "Do you want to do another withdraw? " << endl
                 << "1. Yes" << endl << "0. No" << endl;
            cin >> secondOption;

            if (secondOption) withdrawMoney(); else viewMenu();

        }else{
            cout << "Please enter correct amount to withdraw like you can count your amount with 500 taka notes" << endl;
            fflush(stdin);
            getchar();
            withdrawMoney();
        }
        
    }
    void addMoney() {
        system("cls");
        int addFund;
        cout << "Please add your money to add funds in your account: ";
        cin >> addFund;
        amount += addFund;
        cout << "Your funds added to your account successfully." << endl;
        fflush(stdin);
        getchar();
        viewBalance();
    }
    void changePin() {
        system("cls");
        int changePin;
        cout << "Please write your new Pin to change : ";
        cin >> changePin;
        password = changePin;
        cout << "Your pin has been changed successfully." << endl;
        fflush(stdin);
        getchar();
        pwd_process();
    }
    void viewMenu()
    {
        int option;
        system("cls");

        cout << "1. View your balance" << endl
             << "2. Withdraw Money" << endl
             << "3. Add funds to your account" << endl
             << "4. Change your pin number" << endl
             << "Enter your option below" << endl;

        cin >> option;
        switch (option)
        {
        case 1:
            viewBalance();
            break;
        case 2:
            withdrawMoney();
            break;
        case 3:
            addMoney();
            break;
        case 4:
            changePin();
            break;

        default:
            cout << "You have selected wrong option. Please select correct option which perform you wanna do.." << endl;
            fflush(stdin);
            getchar();
            viewMenu();
            break;
        }
    };
    void pwd_process()
    {   
        system("cls");
        cout << "Please enter your pin:" << endl;
        cin >> userGivenPwd;

        if (userGivenPwd == password)
        {
            viewMenu();
        }
        else
        {
            cout << "Sorry. Incorrect pin number please try again" << endl;
            fflush(stdin);
            getchar();
            pwd_process();
        }
    }
};

int main()
{
    Data<int, string> data;

    return 0;
}