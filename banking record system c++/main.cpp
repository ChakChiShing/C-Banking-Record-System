#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// system interface to get user choice
int system(){
    std::cout << "############Account Information System############\n----------------------------------------\n";
    std::cout << "Select one option Below\n";
    std::cout << "1. Add record to file\n";
    std::cout << "2. Show record from file\n";
    std::cout << "3. Search record from file\n";
    std::cout << "4. Update record\n";
    std::cout << "5. Delete Record\n";
    std::cout << "6. Quit\n";
    std::cout << "Enter your choice: ";
    int choice;
    std::cin >> choice;
    return choice;
}

// function 1 --> add record
void add_record(){
    // ask for user input 
    std::cout << "Enter Account Number: ";
    std::string number;
    std::cin >> number; 
    std::cout << "Enter Name: ";
    std::string name;
    std::cin >> name;
    std::cout << "Enter Balance: ";
    std::string balance;
    std::cin >> balance;
    // create / open a file 
    std::ofstream outfile;
    // the std::ofstream::app is not to overwrite
    // and append the input to the file
    outfile.open("record.txt", std::ofstream::app);
    // write to the file
    outfile << number << " ";
    outfile << name << " ";
    outfile << balance <<'\n';
    // close the file 
    outfile.close();
}

//function 2 --> show all records
void show_record(){
    std::ifstream inFile;
    // open record file
    inFile.open("record.txt");
    if(!inFile){
        std::cerr << "unable to open file!\n"; // error for file not find
    }
    else{
        // print out all the record inside the file
        std::string a, b, c;
        while(inFile >> a >> b >> c){
            cout << "The account number is " << a << endl;
            cout << "The name is " << b << endl;
            cout << "The total balance is " << c << endl;
            cout << endl;
        }
    }
    // close the file
    inFile.close();
}

void search(){
    cout << "Enter the account number you wanna search: ";
    int input;
    cin >> input;
    std::ifstream inFile;
    // open record file
    inFile.open("record.txt");
    if(!inFile){
        std::cerr << "unable to open file!\n"; // error for file not find
    }
    else{
        // print out all the record inside the file
        std::string a, b, c;
        while(inFile >> a >> b >> c){
            if (stoi(a) == input) {
                cout << "The account number is " << a << endl;
                cout << "The name is " << b << endl;
                cout << "The total balance is " << c << endl << endl;
            }
        }
    }
    // close the file
    inFile.close();
}

void update(){
    cout << "Enter the account number you wanna update\n";
    int input;
    cin >> input;
    std::cout << "Enter Name: ";
    std::string name;
    std::cin >> name;
    std::cout << "Enter Balance: ";
    std::string balance;
    std::cin >> balance;
    // create / open a file 
    std::fstream outfile;
    // the std::ofstream::app is not to overwrite
    // and append the input to the file
    outfile.open("record.txt");

    std::ofstream oufile;
    oufile.open("tem.txt");
    // write to the file
    if(!oufile){
        std::cerr << "unable to open file!\n"; // error for file not find
    }
    else {
        std::string a, b, c;
        while (outfile >> a >> b >> c){

            if(stoi(a) == input){
                oufile << input << " ";
                oufile << name << " ";
                oufile << balance <<'\n';
                continue;
            }
            oufile << a << " ";
            oufile << b << " ";
            oufile << c <<'\n';
        }
    }
    // close the file 
    outfile.close();
    oufile.close();
    remove("record.txt");
    rename("tem.txt", "record.txt");
}

void del(){
    cout << "Enter the account number you wanna delete\n" ;
    int input;
    cin >> input;
    // create / open a file 
    std::fstream outfile;
    outfile.open("record.txt");

    std::ofstream oufile;
    oufile.open("tem.txt");
    // write to the file
    if(!oufile){
        std::cerr << "unable to open file!\n"; // error for file not find
    }
    else {
        std::string a, b, c;
        while (outfile >> a >> b >> c){
            if(stoi(a) == input){
                continue;
            }
            oufile << a << " ";
            oufile << b << " ";
            oufile << c <<'\n';
        }
    }
    // close, remove and rename the file 
    outfile.close();
    oufile.close();
    remove("record.txt");
    rename("tem.txt", "record.txt");
}

int main() {
    int choice = 0;
    while ( choice != 6){
        choice = system();
        switch (choice){
            case 1:
            add_record();
            break;
            case 2:
            show_record();
            break;
            case 3:
            search();
            break;
            case 4:
            update();
            break;
            case 5:
            del();
            break;
            case 6:
            exit(0);
        }
    }
    system("pause");
    return 0;
}