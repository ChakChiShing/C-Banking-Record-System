#include <iostream>
#include <fstream>

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

void add_record(){
    // ask for user input 
    std::cout << "Enter Account Number: ";
    std::string number;
    std::cin >> number; 
    std::cout << "Enter Full Name: ";
    std::string name;
    std::cin >> name;
    std::cout << "Enter Balance: ";
    std::string balance;
    std::cin >> balance;

    // create / open a file 
    std::ofstream outfile("record.txt");

    // write to the file
    outfile << number << name << balance << std::endl;
    
    // close the file 
    outfile.close();
}

void show_record(){
    std::ifstream inFile;
    inFile.open("record.txt");
    if(!inFile){
        std::cerr << "unable to open file!\n";
    }
    else{

    }
    exit(1);
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
            break;

            case 3:
            break;

            case 4:
            break;

            case 5:
            break;
        
            case 6:
            exit(0);
        }
    }
}