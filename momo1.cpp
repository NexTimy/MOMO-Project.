//include libraries
#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

//initialize global variables
string customerName;
int customerPin = 0000;
double customerBalance = 1000.0;
int wrongPinCounter = 0;

//function to authenticate customer
bool authenticate(int pin) {
  if (customerPin == pin) {
    return true;
  } else {
    wrongPinCounter++;
    if (wrongPinCounter == 3) {
      cout << "Maximum attempts reached. Exiting program." << endl;
      exit(0);
    } else {
      cout << "Incorrect pin. Please try again." << endl;
      return false;
    }
  }
}

//function to reset/change customer pin
void resetPin() {
  int newPin;
  cout << "Enter new pin: ";
  cin >> newPin;
  customerPin = newPin;
  cout << "Pin successfully changed." << endl;
}

//function to check customer balance
void checkBalance() {
  cout << "Your balance is: " << customerBalance << endl;
}

//function to send money to another user
void sendMoney() {
  int recipientPin;
  double amount;
  cout << "Enter recipient's pin: ";
  cin >> recipientPin;
  if (authenticate(recipientPin)) {
    cout << "Enter amount: ";
    cin >> amount;
    if (amount <= customerBalance) {
      customerBalance -= amount;
      cout << "Transaction successful. " << amount << " has been sent to the recipient." << endl;
    } else {
      cout << "Insufficient funds." << endl;
    }
  }
}

//function to withdraw money
void withdrawMoney() {
  double amount;
  cout << "Enter amount to withdraw: ";
  cin >> amount;
  if (amount <= customerBalance) {
    customerBalance -= amount;
    cout << "Transaction successful. " << amount << " has been withdrawn." << endl;
  } else {
    cout << "Insufficient funds." << endl;
  }
}

//function to pay bill
void payBill() {
  string billType;
  double amount;
  cout << "Enter bill type: ";
  cin >> billType;
  cout << "Enter amount: ";
  cin >> amount;
  if (amount <= customerBalance) {
    customerBalance -= amount;
    cout << "Transaction successful. " << amount << " has been paid for " << billType << "." << endl;
  } else {
    cout << "Insufficient funds." << endl;
  }
}

//function to buy airtime
void buyAirtime() {
  double amount;
  cout << "Enter amount to recharge: ";
  cin >> amount;
  if (amount <= customerBalance) {
    customerBalance -= amount;
    cout << "Transaction successful. " << amount << " airtime has been credited to your phone." << endl;
  } else {
    cout << "Insufficient funds." << endl;
  }
}

//main function
int main() {
  int option;
  int pin;
  
  cout << "Welcome to Mobile Money Service." << endl;
  cout << "Please enter your name: ";
  getline(cin, customerName);

  do {
    cout << "Enter your pin: ";
    cin >> pin;
  } while (!authenticate(pin));

  do {
cout << endl;
cout << "Select an option: " << endl;
cout << "1. Reset/change pin" << endl;
cout << "2. Check balance" << endl;
cout << "3. Send money" << endl;
cout << "4. Withdraw money" << endl;
cout << "5. Pay bill" << endl;
cout << "6. Buy airtime" << endl;
cout << "7. Exit" << endl;
cout << "Option: ";
cin >> option;

switch(option) {
  case 1:
    resetPin();
    break;
  case 2:
    checkBalance();
    break;
  case 3:
    sendMoney();
    break;
  case 4:
    withdrawMoney();
    break;
  case 5:
    payBill();
    break;
  case 6:
    buyAirtime();
    break;
  case 7:
    cout << "Exiting program. Goodbye, " << customerName << "." << endl;
    exit(0);
    break;
  default:
    cout << "Invalid option. Please try again." << endl;
    break;
}
} while (true);

return 0;
}
