#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

int main(){
    int a, i= 0;
    string text, old, password1, password2, pass, name, password0, age, user, word, word1;
    string creds[2], cp[2];

    cout << "-------------------------"<<endl;
    cout << "|    Security System    |"<<endl;
    cout << "-------------------------"<<endl;
    cout << endl;
    cout << "-------------------------"<<endl;
    cout << "|    1. Register        |"<<endl;
    cout << "|    2. Login           |"<<endl;
    cout << "|    3. Change Password |"<<endl;
    cout << "|    4. End Program     |"<<endl;
    cout << "-------------------------"<<endl;
    do {
        cout << endl;
        cout << "Enter your Choice : ";
        cin >> a;
       
        switch (a) {
            case 1:{
                cout << "-----------------------"<<endl;
                cout << "|      Register       |"<<endl;
                cout << "-----------------------"<<endl;
                cout << "Please Enter your UserName: ";
                cin >> name;
                cout << "Please enter the password: ";
                cin >> password0;
                cout << "Please enter your age: ";
                cin >> age;
                ofstream of1;
                of1.open("file.txt");
                if(of1.is_open()){
                    of1<<name<<"\n";
                    of1<<password0;
                    cout << "Registration Successfull"<<endl;
                }
                of1.close();
                break;
            }
            case 2:{
                i =0;
                cout << "-----------------------"<<endl;
                cout << "|        Login        |"<<endl;
                cout << "-----------------------"<<endl;


                ifstream of2;
                of2.open("file.txt");
                cout << "please Enter UserName : ";
                cin >> user;
                cout << "Please Enter Password: ";
                cin >> pass;

                if(of2.is_open()){
                    while(!of2.eof()){
                        while(getline(of2, text)){
                            istringstream iss(text);
                            iss>>word;
                            creds[i] = word;
                            i++;
                        }

                        if(user == creds[0] && pass == creds[1]){
                            cout << "--Logging Suceessfull--";
                            cout << endl<<endl;
                            cout << "Details: "<<endl;

                            cout << "UserName: "+user<<endl;
                            cout << "Password: "+ pass<<endl;
                            cout << "Age: "<<age<<endl;
                        }
                        else{
                            cout << "incorrect username/password"<<endl;;
                            cout << "  1. Press 2 for login   "<<endl;
                            cout << "  2. Press 3 to change password"<<endl;

                            break;
                        }
                    }
                }
                of2.close();
                break;
            }
            case 3:{
                i = 0;
                cout << "-----------------------"<<endl;
                cout << "|  Change Password    |"<<endl;
                cout << "-----------------------"<<endl;


                ifstream of0;
                of0.open("file.txt");
                cout << "Enter the Old Password: ";
                cin >> old;

                if(of0.is_open()){
                    while (!of0.eof()){
                        while(getline(of0, text)){
                            istringstream iss(text);
                            iss >> word1;
                            cp[i] = word1;
                            i++;
                        }
                        if(old == cp[1]){
                            
                            of0.close();
                            ofstream of1;
                            of1.open("file.txt");
                            if(of1.is_open()){
                                cout << "Enter the new Password: ";
                                cin >> password1;
                                cout << "Enter the new Password again: ";
                                cin >> password2;
                                if(password1 == password2){
                                    of1<<cp[0] << "\n";
                                    of1<<password1;
                                    cout << "Password changed Sucessfully"<<endl;
                                }
                                else{
                                    of1 << cp[0]<< "\n";
                                    of1 <<old;
                                    cout << "Password Does not match"<<endl;
                                }
                            }
                        }
                        else{
                            cout << "Please Enter the valid password"<<endl;
                            break;
                        }

                    }
                }
                break;
            }
            case 4:{
                cout << "----------ThankYou----------"<<endl;
                break;
            }

            default:
                cout << "Enter the Valid code ";
        }
    }while(a!=4);
    
}