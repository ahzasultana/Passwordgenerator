#include <iostream>
#include <ctime>
#include <cstdlib>
#include <limits>
#include <cstring>

using namespace std;

class Password
{
public:
    void easy(int val);
    void normal(int val);
    void strong(int val);
    void mainfun();
};

void Password::easy(int val) 
{
    const char input[] = "abcdefghijklmnopqrstuvwxyz"
                         //"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                         "1234567890";
                         //"!@$%^&*()_"; //+-={}:><?|\.#
    cout << "Your generated password: ";
    for (int i = 0; i < val; i++) 
	{
        cout << input[rand() % (strlen(input))]; 
    }
    cout << endl;
}

void Password::normal(int val) 
{
    const char input[] = "abcdefghijklmnopqrstuvwxyz"
                         "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                         "1234567890";
                         //"!@$%^&*()_/+-="; //{}:><?|\.#
    cout << "Your generated password: ";
    for (int i = 0; i < val; i++) 
	{
        cout << input[rand() % (strlen(input))];
    }
    cout << endl;
}

void Password::strong(int val) 
{
    const char input[] = "abcdefghijklmnopqrstuvwxyz"
                         "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                         "1234567890"
                         "!@$%^&*()_/{}:><?|#";
    cout << "Your generated password: ";
    for (int i = 0; i < val; i++) 
	{
        cout << input[rand() % (strlen(input))];
    }
    cout << endl;
}

void Password::mainfun() 
{
    int r;

    while (true) 
	{
        cout << "\nEnter the length of your password (4-32): ";
        while (!(cin >> r) || r < 4 || r > 32)
		{ 
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            cout << "Invalid input. Please enter a number between 4 and 32: ";
        }
        cout << "Enter the choice of what kind of password you want:" << endl;
        cout << "1. Weak" << endl;
        cout << "2. Normal" << endl;
        cout << "3. Strong" << endl;
        int choice;
        cin >> choice;

        switch (choice) 
		{
            case 1:
                easy(r);
                break;
            case 2:
                normal(r);
                break;
            case 3:
                strong(r);
                break;
            default:
                cout << "Invalid choice, please try again." << endl;
                continue; 
        }

        break; 
    }
}

int main() 
{
	cout<<"Hi! My friend having difficulties in creating password? Let me help you :)"<<endl;
	cout<<"Can you please give me the following details:"<<endl;
	cout << "Do you have a specific password in mind? (yes/no): ";
    string p;
    cin >> p;

    if (p == "yes" || p == "Yes" || p == "YES") 
	{
        string userPassword;
        cout << "Please enter your password: ";
        cin >> userPassword; 
        cout << "Your entered password is: " << userPassword << endl;
        cout<<"Thats's a great one! Let me also create one for you:)"<<endl;
    }
    
    srand(static_cast<unsigned int>(time(0))); 
    Password s;
	
    do 
	{
        s.mainfun(); 

        cout << "Do you want to regenerate the password? (yes/no): ";
        string response;
        cin >> response;

        if (response != "yes" && response != "Yes" && response != "YES" &&
            response != "Yeah" && response != "yeah") 
		{
			cout<<"Feel free to reach me again when you want to generate a password!"<<endl;
			cout<<"Thank You for using me :)"<<endl;
            break; 
        }
    } while (true); 

    return 0; 
}

