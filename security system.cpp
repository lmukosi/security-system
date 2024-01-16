#include<iostream>
#include<fstream>
#include<sstream>
#include<string>

using namespace std;

int main()
{

	int a, i = 0;
	string text, old, password1, password2, pass, name, password0, age, user, word, word1;
	string creds[2], cp[2];

	cout << "       Security System    " << endl;

	cout << "\t\t\t____________________________________________\n" << endl;
	cout << "\t\t\t|              1. Register					" << endl;
	cout << "\t\t\t|              2. Login						" << endl;
	cout << "\t\t\t|              3. Change password			" << endl;
	cout << "\t\t\t|              4. End Program				" << endl;
	cout << "\t\t\t____________________________________________	" << endl << endl;

	do {
		cout << endl << endl;
		cout << "\t\t\tEnter your choice: ";
		cin >> a;
		switch (a)
		{

		case 1:
		{
			
			cout << "\t\t\t____________________________________________" << endl << endl;
			cout << "\t\t\t|--------------Register--------------------|" << endl;
			cout << "\t\t\t____________________________________________" << endl << endl;
			cout << "\t\t\tPlease enter username: ";
			cin >> name;
			cout << "\t\t\tPlease enter the password: ";
			cin >> password0;
			cout << "\t\t\tPlease enter you age: ";
			cin >> age;

			ofstream of1;
			of1.open("file.txt");
			if (of1.is_open())
			{
				of1 << name << "\n";
				of1 << password0;
				cout << "\n\t\t\tRegistration successfully.." << endl;
			}
			break;
			
		}
		
		case 2:
		{
			i = 0;

			cout << "\t\t\t____________________________________________" << endl << endl;
			cout << "\t\t\t|-----------------Login--------------------|" << endl;
			cout << "\t\t\t____________________________________________" << endl << endl;

			ifstream of2;
			of2.open("file.txt");
			cout << "\t\t\tPlease enter the username: ";
			cin >> user;
			cout << "\t\t\tPlease enter the password: ";
			cin >> pass;

			if (of2.is_open())
			{
				while (!of2.eof())
				{
					while (getline(of2, text)) {
						istringstream iss(text);
						iss >> word;
						creds[i] = word;
						i++;
					}

					if (user == creds[0] && pass == creds[1])
					{
						cout << "\t\t\t---Log in successfully---";
						cout << endl << endl;

						cout << "\t\t\t Details: ";

						cout << "\t\t\tusername: " + name << endl;
						cout << "\t\t\tpassword: " + pass << endl;
						cout << "\t\t\tage: " + age << endl;


					}

					else
					{
						cout << endl << endl;
						cout << "\t\t\tIncorrect Credentials !!" << endl;
						cout << "\t\t\t|    1. Press 2 to login			" << endl;
						cout << "\t\t\t|    2. Press 3 to change password " << endl;
						break;


					}
				}

			}
			break;
		}

		case 3:
		{
			i = 0;
			cout << "\t\t\t-----------Change password-----------" << endl;

			ifstream of0;
			of0.open("file.txt");
			cout << "\t\t\tEnter the old password: ";
			cin >> old;
			if (of0.is_open())
			{
				while (of0.eof())
				{
					istringstream iss(text);
					iss >> word1;
					cp[i] = word1;
					i++;

				}
				if (old == cp[1])
				{

					of0.close();

					ofstream of1;
					if (of1.is_open())
					{

						cout << "\t\t\tEnter your new password: ";
						cin >> password1;
						cout << "\t\t\tEnter your password again: ";
						cin >> password2;


					}
					if (password1 == password2)
					{
						of1 << cp[0] << "\n";
						of1 << password1;
						cout << "\t\t\tPassword changed successfully.." << endl;

					}
					else
					{
						of1 << cp[0] << "\n";
						of1 << old;
						cout << "\t\t\tPassword do not match !!" << endl;
					}
				}


				else
				{
					cout << "\t\t\tPlease enter a valid password " << endl;
					break;
				}

			}
			break;

		}
		case 4:
		{
			cout << "\t\t\t______________Thank you!_______________";
			break;
		}

		default:
			cout << "\t\t\tEnter a valid choice ";

		} 
	}
	while (a!=4);
	return 0;

}
		