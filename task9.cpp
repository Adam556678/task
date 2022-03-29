

/*
    Faculty of computers and artificial intelligence cairo university
    ID : 20210369
    Name : Mahmoud Ramadan Mohamed

*/
#include <iostream>
#include <regex>

using namespace std;

void encryption(){
    string message;
    cout << "Enter message to encrypt : ";
    getline(cin , message);
    cin.ignore();

    // removinge space from message
    message = regex_replace(message, regex("\\s+"), "");

    cout << "Enter key: ";
    int key;
    cin >> key;
    cin.ignore();

    // creating empty matrix
    char railMatrix[key][message.length()];
    for (int i = 0; i < key; i++){
        for (int j = 0; j < message.length(); j++){
            railMatrix[i][j] = '.';
        }
    }


    int row = 0;
    int check = 0;
    for (int i = 0; i < message.length(); i++){
        if (check == 0){
            railMatrix[row][i] = message[i];
            row++;
            if(row == key){
                check = 1;
                row--;
            }
        } else if (check == 1){
            row--;
            railMatrix[row][i] = message[i];
            if (row == 0){
                check = 0;
                row = 1;
            }
        }
    }

    // creating encrypted text
    string result = "";
    for (int i = 0; i < key; i++){
        for (int j = 0; j < message.length(); j++){
//            cout << railMatrix[i][j];
            result += railMatrix[i][j];
        }
//        cout << endl;
    }

    // removing '.' from encrypted Text
    result = regex_replace(result, regex("\\."), "");
    cout << "Encrypted Text: " << result;
}

void Decryption(){
    string message;
    cout << "Enter message: ";
    getline(cin , message);
    cin.ignore();

    // removing white space from message
    message = regex_replace(message, regex("\\s+"), "");

    cout << "Enter key(number of key): ";
    int key;
    cin >> key;
    cin.ignore();

    // creating empty matrix
    char railMatrix[key][message.length()];
    for (int i = 0; i < key; i++){
        for (int j = 0; j < message.length(); j++){
            railMatrix[i][j] = '.';
        }
    }


    // putting message letters one by one in rail matrix in zig-zag
    int row = 0;
    int check = 0;
    for (int i = 0; i < message.length(); i++){
        if (check == 0){
            railMatrix[row][i] = message[i];
            row++;
            if(row == key){
                check = 1;
                row--;
            }
        } else if (check == 1){
            row--;
            railMatrix[row][i] = message[i];
            if (row == 0){
                check = 0;
                row = 1;
            }
        }
    }


    int ordr = 0;
    for (int i = 0; i < key; i++){
        for (int j = 0; j < message.length(); j++){
            string temp = "";
            temp += railMatrix[i][j];
            if(regex_match(temp, regex("\\."))){
                // skipping '.'
                continue;
            } else {
                railMatrix[i][j] = message[ordr];
                ordr++;
            }

        }

    }




    string decrypText = "";
    check = 0;
    row = 0;
    for (int i = 0; i < message.length(); i++){
        if (check == 0){
            decrypText += railMatrix[row][i];
            row++;
            if (row == key){
                check = 1;
                row--;
            }
        } else if (check == 1){
            row--;
            decrypText += railMatrix[row][i];
            if (row == 0){
                check = 0;
                row = 1;
            }
        } // if else
    } // for

    // removing '.' from decrypted text
    decrypText = regex_replace(decrypText, regex("\\.+"), "");
    cout << "Decrypted Text: " << decrypText;
}

int main()
{
    cout << "1. Encryption\n2. Decryption\nChoose(1,2): ";
    int choice;
    cin >> choice;
    cin.ignore();

    if (choice == 1){
        cout << endl << "Encryption" << endl;
        encryption();

    } else if (choice == 2) {
        cout << endl << "Decryption" << endl;
        Decryption();

    } else {
        cout << endl << "Invalid Choice" << endl;
    }

    return 0;
}
