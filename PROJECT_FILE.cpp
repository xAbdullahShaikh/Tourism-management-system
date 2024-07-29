#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string.h>
#include <sstream>

using namespace std;

// functions declaration
void starter();

// classes declaration
class signup_login;
class admin_login;
class user_control;

// classes implementation
class signup_login
{
protected:
	string username;
	string password, pcheck;
	string fullname;
	string CNIC;
	string country;
	string city;
	static int total_users;

public:
	// CONSTRUCTORS AND DESTRUCTORS
	signup_login()
	{
		username = "default";
		password = "default";
		pcheck = "default";
		fullname = "default";
		CNIC = "default";
		country = "default";
		city = "default";

		total_users++;
		// sign_up();
		// login();
	}
	~signup_login() {}

	// FUNCTIONS

	// to reset all values
	void refresher()
	{
		username = "";
		password = "";
		fullname = "";
		CNIC = "";
		country = "";
		city = "";
	}

	// sign up function
	void sign_up()
	{

		system("CLS");
		cout << "\t\t\t\t\t\t\t\t\t\tWelcome To FAATM ACCOUNT CREATION, Please Fill Following Information" << endl;
	again:
		cin.sync();
		cout << "Please Enter Your Full Name? : ";
		getline(cin, fullname);
		cin.sync();

		cout << "Please Enter Your Username[Will Be Required For Login]? : ";
		getline(cin, username);
		cin.sync();

	a:
		cin.sync();
		cout << "Please Enter Your Password[Will Be Required For Login]? : ";
		getline(cin, password);
		cout << "Please Enter Your Password Again To Confirm It? : ";
		getline(cin, pcheck);
		if (password != pcheck)
		{
			cout << endl
				 << "Both Passwords Are Different , Please Retype Same Passwords Again!. ";
			goto a;
		}

		cout << "Please Enter Your CNIC? : ";
		getline(cin, CNIC);
		cin.sync();

		cout << "Please Enter Your Current Country? : ";
		getline(cin, country);
		cin.sync();

		cout << "Please Enter Your Current City? : ";
		getline(cin, city);
		cin.sync();

	confirm:
		cin.sync();
		system("CLS");
		int confirm = 0;
		cout << "USERNAME : " << username << endl
			 << "Password : " << password << endl
			 << "Full Name : " << fullname << endl
			 << "CNIC : " << CNIC << endl
			 << "Country : " << country << endl
			 << "City : " << city << endl;
		cout << "This Is The Information You Entered , Please Check If All The Information Is Correct , If Not Press 1 To Re Enter The Information , Other Wise Press 2 To Save The Information? : ";
		cin >> confirm;
		if (confirm == 1)
		{
			refresher();
			system("CLS");
			goto again;
		}
		else if (confirm == 2)
		{
			// SAVING RECORD IN FILE
			string extra = ".txt";
			ofstream insert, insertuserpw("userpass.txt", ios::app);
			string filename = username + extra;

			insert.open(filename.c_str());
			insert << username << endl
				   << password << endl
				   << "Other Data" << endl
				   << fullname << endl
				   << CNIC << endl
				   << country << endl
				   << city << endl
				   << endl;
			insert.close();

			insertuserpw << username << " " << password << endl;
			insertuserpw.close();

			refresher();

			system("CLS");
			cout << "ACCOUNT SUCCESSFULLY CREATED";
		}
		else
		{
			cout << endl
				 << "You Have Selected Wrong Option , Please Select Appropriate Option[1 Or 2]. ";
			goto confirm;
		}
	}

	// login function
	bool login()
	{
		cout << "USER";
		bool is_valid = false;
		ifstream read("userpass.txt");
		string tempuser, temppass;
		refresher();

		system("CLS");
		cout << "\t\t\t\t\t\t\t\t\t\tWelcome To FAATM LOGIN, Please Fill Following Information" << endl;
	retry:
		cin.sync();
		cout << "Please Enter Your Username? : ";
		getline(cin, username);
		cin.sync();

		cout << "Please Enter Your Password? : ";
		getline(cin, password);
		cin.sync();

		while (read.eof() != 1)
		{
			read >> tempuser >> temppass;
			if (username == tempuser && password == temppass)
			{
				is_valid = true;
			}
		}

		if (is_valid == true)
		{
			return true;
		}
		else
		{
			return false;
		}

		read.close();
	}
};

class admin_login : public signup_login
{
	string employee_code; // special access security code , only for employees
	static int total_admins;

public:
	// CONSTRUCTORS AND DESTRUCTORS
	admin_login()
	{
		employee_code = "default";
		total_admins++;
	}
	~admin_login() {}

	// FUNCTIONS
	void sign_up() {} // redefined sign_up function for admin , because I dont want anyone to signup for admin , organization will provide admin their account themself.

	bool login()
	{
		cout << "Ad";
		bool is_valid = false;
		ifstream read_ad("admin_userpasscode.txt");
		string tempuser, temppass, tempcode;
		refresher();

		system("CLS");
		cout << "\t\t\t\t\t\t\t\t\t\tWelcome To FAATM ADMIN LOGIN, Please Fill Following Information" << endl;
	retry:
		cin.sync();
		cout << "Please Enter Your Username? : ";
		getline(cin, username);
		cin.sync();

		cout << "Please Enter Your Password? : ";
		getline(cin, password);
		cin.sync();

		cout << "Please Enter Your Special Access Code Given To You Buy Your Organization? : ";
		getline(cin, employee_code);
		cin.sync();

		while (read_ad.eof() != 1)
		{
			read_ad >> tempuser >> temppass >> tempcode;
			if (username == tempuser && password == temppass && employee_code == tempcode)
			{
				is_valid = true;
			}
		}

		if (is_valid == true)
		{
			return true;
		}
		else
		{
			return false;
		}

		read_ad.close();
	}
};

class admin_control
{
private:
	string hcit, hname, hsize, hrat, hcost;

public:
	// constructors and destructors
	admin_control() {}
	~admin_control() {}

	// FUNCTIONS
	int admin_services()
	{
		char adch;
		int i = 0;

	hm:
	mai:
	amai:
		cin.sync();
		system("CLS");
		cout << "\t\t\t\tAdmin Panel! " << endl
			 << endl;
	ddde:
		cin.sync();
		cout << "A)Set Hotel System" << endl
			 << "B)Set Flight System" << endl
			 << "C)Set Attractions System" << endl
			 << "D)Hire A Employee" << endl
			 << "E)Fire A Employee" << endl
			 << "F)Back To Main Menu" << endl
			 << "G)Exit The Program" << endl;
		cout << endl
			 << "Please Select From The Given Options : ";
		cin >> adch;
		switch (adch)
		{
		case 'A':
		case 'a':
		case '1':
			char hch;
			system("CLS");
		ddd:
			cin.sync();
			cout << "SETTING HOTEL SYSTEM..." << endl
				 << endl;
			cout << "A)Add New Hotels" << endl
				 << "B)Remove Some Hotels" << endl
				 << "C)Update Existing Hotel Details" << endl
				 << "D)Back To Main Menu" << endl
				 << "E)Exit The Program";
			cout << endl
				 << "Please Select From The Given Options : ";
			cin >> hch;
			switch (hch)
			{
			case 'A':
			case 'a':
			case '1':
			{
				system("CLS");
				cout << "ADDING NEW HOTEL MENU..." << endl
					 << endl;
			addhh:
				cin.ignore();
				cout << "Enter Hotel City? : ";
				getline(cin, hcit);
				cout << "Enter Hotel Name? : ";
				getline(cin, hname);
				cout << "Enter Hotel Size[i.e DOUBLE-BED]? : ";
				getline(cin, hsize);
				cout << "Enter Hotel Rating[i.e 3.5]? : ";
				getline(cin, hrat);
				cout << "Enter Hotel Cost? : ";
				getline(cin, hcost);

				char addnew;
				system("CLS");
			reddy:
				cin.sync();
				cout << "Hotel City : " << hcit << endl
					 << "Hotel Name : " << hname << endl
					 << "Hotel Size : " << hsize << endl
					 << "Hotel Rating : " << hrat << endl
					 << "Hotel Cost : " << hcost << endl;
				cout << "Would You Like To Add This Hotel?[Y For YES , N FOR NO]? : ";
				cin >> addnew;

				switch (addnew)
				{
				case 'Y':
				case 'y':
				{
					string liner, liner2, fliner;
					int j = 1;
					char choiced1;
					ofstream hadd("hotels.txt", ios::app);
					hadd << hcit << ' ' << hname << ' ' << hsize << ' ' << hrat << ' ' << hcost << endl;
					hadd.close();
					cout << "Hotel Added Successfully" << endl
						 << endl;
					cout << "Following Is The Updated List Of Hotels , Registered With Us." << endl
						 << endl;
					ifstream remag("hotels.txt");
					j = 1;
					while (remag >> liner >> liner2 && getline(remag, fliner))
					{
						cout << j << ") " << liner2 << endl;
						j++;
					}
				reddyb:
					cin.sync();
					cout << endl
						 << endl
						 << "Now What Would You Like To Do" << endl;
					cout << "A)Add Another Hotel?" << endl
						 << "B)Back To Main Menu" << endl
						 << "C)Exit The Program";
					cout << endl
						 << "Please Select From The Given Options : ";
					cin >> choiced1;
					switch (choiced1)
					{
					case 'A':
					case 'a':
					case '1':
					{
						goto addhh;
					}
					break;

					case 'B':
					case 'b':
					case '2':
					{
						goto amai;
					}
					break;

					case 'C':
					case 'c':
					case '3':
					{
						exit(0);
					}
					break;

					default:
						system("CLS");
						cout << endl
							 << "You Have Selected Wrong Option , Please Select From The Following Options[A OR B Or C]" << endl
							 << endl;
						goto reddyb;
					}
				}
				break;

				case 'N':
				case 'n':
				{
					char choicedd;
					system("CLS");
				reddybn:
					cin.sync();
					cout << "Then What Would You Like To Do? : " << endl
						 << endl;
					cout << "A)Back To Main Menu" << endl
						 << "B)Exit The Program";
					cout << endl
						 << "Please Select From The Given Options : ";
					cin >> choicedd;
					switch (choicedd)
					{
					case 'A':
					case 'a':
					case '1':
					{
						goto amai;
					}
					break;

					case 'B':
					case 'b':
					case '2':
					{
						exit(0);
					}
					break;

					default:
						system("CLS");
						cout << endl
							 << "You Have Selected Wrong Option , Please Select From The Following Options[A OR B]" << endl
							 << endl;
						goto reddybn;
					}
				}

				break;

				default:
					system("CLS");
					cout << endl
						 << "You Have Selected Wrong Option , Please Select From The Following Options[Y OR N]" << endl
						 << endl;
					goto reddy;
				}
			}
			break;

			case 'B':
			case 'b':
			case '2':
			{
				int i = 0, j = 1, k = 1;
				string hrname, liner, liner2, fliner;
				string temp_main, temp1, temp2;

				cin.ignore();
				system("CLS");
				cout << "REMOVING HOTEL MENU..." << endl
					 << endl;
			agg:
			anot:
				cout << "Following Is The List Of Hotels , Registered With Us." << endl
					 << endl;
				j = 1;
				ifstream remag("hotels.txt");
				ofstream remt("rem.txt", ios::trunc);
				while (remag >> liner >> liner2 && getline(remag, fliner))
				{
					cout << j << ") " << liner2 << endl;
					j++;
				}
				remag.close();
				ifstream rem("hotels.txt");
				cout << endl
					 << "Enter Hotel Name You Want To Remove[CASE-SENSITIVE]? : ";
				getline(cin, hrname);

				i = 0;
				while (rem >> temp1 >> temp_main && getline(rem, temp2))
				{
					if (temp_main != hrname)
					{
						remt << temp1 << ' ' << temp_main << ' ' << temp2 << endl;
					}
					else
					{
						i++;
					}
				}
				rem.close();
				remt.close();

				string line;
				ofstream remg("hotels.txt", ios::trunc);
				ifstream remtt("rem.txt");
				while (getline(remtt, line))
				{
					remg << line << endl;
				}
				remtt.close();
				remove("rem.txt");
				remg.close();

				if (i < 1)
				{
					j = 1;
					system("CLS");
					cout << endl
						 << endl
						 << "Hotel Name You Entered Not Found. Please Try Again." << endl
						 << endl;
					goto agg;
				}
				else
				{
					system("CLS");
					cout << endl
						 << endl
						 << "Hotel[" << hrname << ']' << " Removed Successfully , Following Is The Updated List Of Hotels" << endl
						 << endl;
					k = 1;
					ifstream remagg("hotels.txt");
					while (remagg >> liner >> liner2 && getline(remagg, fliner))
					{
						cout << k << ") " << liner2 << endl;
						k++;
					}
					remagg.close();

					char choic;
				redd:
					cin.sync();
					cout << endl
						 << endl
						 << "What You Want To Do Now? : ";
					cout << endl
						 << endl
						 << "A)Remove Another Hotel?" << endl
						 << "B)Goto Main Menu" << endl
						 << "C)Exit The Program";
					cout << endl
						 << "Please Select From The Given Options : ";
					cin >> choic;

					switch (choic)
					{
					case 'A':
					case 'a':
					case '1':
					{
						goto anot;
					}
					break;

					case 'B':
					case 'b':
					case '2':
					{
						goto mai;
					}
					break;

					case 'C':
					case 'c':
					case '3':
					{
						exit(0);
					}
					break;

					default:
						system("CLS");
						cout << endl
							 << "You Have Selected Wrong Option , Please Select From The Following Options[A Or B Or C]" << endl
							 << endl;
						goto redd;
					}
				}
			}
			break;

			case 'C':
			case 'c':
			case '3':
			{
				int i = 0, j = 1, k = 1;
				string liner, liner2, cliner, liner3, rliner;
				system("CLS");
				cout << "UPDATING HOTEL DETAILS..." << endl
					 << endl;

				cin.ignore();
			aggup:
			anotu:
				cin.sync();
				cout << "Following Is The List Of Hotels , Registered With Us." << endl
					 << endl;

				ifstream upd("hotels.txt");
				j = 1;
				while (upd >> liner >> liner2 >> liner3 >> rliner >> cliner)
				{
					cout << j << ") " << liner2 << endl;
					cout << "Hotel's Cost : " << cliner << endl
						 << "Hotels Rating : " << rliner << endl
						 << endl;
					j++;
				}
				upd.close();

				string hup;
				char choicc;
				cout << "Enter Hotel Name , You Would Like To Update[CASE-SENSITIVE]? : ";
				getline(cin, hup);
				cout << "What Would You Like To Update? : " << endl
					 << endl;
				cout << "A)Hotel Cost" << endl
					 << "B)Hotel Rating" << endl;
				cout << endl
					 << "Please Select From The Given Options : ";
				cin >> choicc;

				switch (choicc)
				{
				case 'A':
				case 'a':
				case '1':
				{
					int i = 0;
					ifstream upd1("hotels.txt");
					ofstream temper("temp.txt", ios::trunc);
					string a, name, c, d, cost, ncost, liness;
					char choicu;
					cin.ignore();
					cout << endl
						 << "Enter New Cost For The Hotel[" << hup << "]? : ";
					getline(cin, ncost);
					while (upd1 >> a >> name >> c >> d >> cost)
					{
						if (hup != name)
						{
							temper << a << ' ' << name << ' ' << c << ' ' << d << ' ' << cost << endl;
						}
						else
						{
							temper << a << ' ' << name << ' ' << c << ' ' << d << ' ' << ncost << endl;
							i++;
						}
					}
					upd1.close();
					temper.close();

					ofstream upd2("hotels.txt", ios::trunc);
					ifstream temper2("temp.txt");

					while (temper2 >> a >> name >> c >> d >> cost)
					{
						upd2 << a << ' ' << name << ' ' << c << ' ' << d << ' ' << cost << endl;
					}
					upd2.close();
					temper2.close();
					remove("temp.txt");

					if (i < 1)
					{
						j = 1;
						system("CLS");
						cout << endl
							 << endl
							 << "Hotel Name You Entered Not Found. Please Try Again." << endl
							 << endl;
						goto aggup;
					}
					else
					{
						system("CLS");
						cout << endl
							 << endl
							 << "Hotel[" << hup << ']' << " Cost Updated Successfully." << endl
							 << endl;

						char choicu;
					reddur:
						cin.sync();
						cout << endl
							 << endl
							 << "What You Want To Do Now? : ";
						cout << endl
							 << endl
							 << "A)Update Another Hotel?" << endl
							 << "B)Goto Main Menu" << endl
							 << "C)Exit The Program";
						cout << endl
							 << "Please Select From The Given Options : ";
						cin >> choicu;

						switch (choicu)
						{
						case 'A':
						case 'a':
						case '1':
						{
							goto anotu;
						}
						break;

						case 'B':
						case 'b':
						case '2':
						{
							goto mai;
						}
						break;

						case 'C':
						case 'c':
						case '3':
						{
							exit(0);
						}
						break;

						default:
							system("CLS");
							cout << endl
								 << "You Have Selected Wrong Option , Please Select From The Following Options[A Or B Or C]" << endl
								 << endl;
							goto reddur;
						}
					}
				}
				break;

				case 'B':
				case 'b':
				case '2':
				{
					int i = 0;
					ifstream upd1("hotels.txt");
					ofstream temper("temp.txt", ios::trunc);
					string a, name, c, d, rat, nrat, liness;
					char choicu;
					cin.ignore();
					cout << endl
						 << "Enter New Ratings For The Hotel[" << hup << "]? : ";
					getline(cin, nrat);
					while (upd1 >> a >> name >> c >> rat >> d)
					{
						if (hup != name)
						{
							temper << a << ' ' << name << ' ' << c << ' ' << rat << ' ' << d << endl;
						}
						else
						{
							temper << a << ' ' << name << ' ' << c << ' ' << nrat << ' ' << d << endl;
							i++;
						}
					}
					upd1.close();
					temper.close();

					ofstream upd2("hotels.txt", ios::trunc);
					ifstream temper2("temp.txt");

					while (temper2 >> a >> name >> c >> rat >> d)
					{
						upd2 << a << ' ' << name << ' ' << c << ' ' << rat << ' ' << d << endl;
					}
					upd2.close();
					temper2.close();
					remove("temp.txt");

					if (i < 1)
					{
						j = 1;
						system("CLS");
						cout << endl
							 << endl
							 << "Hotel Name You Entered Not Found. Please Try Again." << endl
							 << endl;
						goto aggup;
					}
					else
					{
						system("CLS");
						cout << endl
							 << endl
							 << "Hotel[" << hup << ']' << " Rating Updated Successfully." << endl
							 << endl;

						char choicu;
					reddu:
						cin.sync();
						cout << endl
							 << endl
							 << "What You Want To Do Now? : ";
						cout << endl
							 << endl
							 << "A)Update Another Hotel?" << endl
							 << "B)Goto Main Menu" << endl
							 << "C)Exit The Program";
						cout << endl
							 << "Please Select From The Given Options : ";
						cin >> choicu;

						switch (choicu)
						{
						case 'A':
						case 'a':
						case '1':
						{
							goto anotu;
						}
						break;

						case 'B':
						case 'b':
						case '2':
						{
							goto mai;
						}
						break;

						case 'C':
						case 'c':
						case '3':
						{
							exit(0);
						}
						break;

						default:
							system("CLS");
							cout << endl
								 << "You Have Selected Wrong Option , Please Select From The Following Options[A Or B Or C]" << endl
								 << endl;
							goto reddu;
						}
					}
				}
				break;
				}
			}

			break;

			case 'D':
			case 'd':
			case '4':
				goto hm;
				break;

			case 'E':
			case 'e':
			case '5':
				exit(0);
				break;

			default:
				system("CLS");
				cout << endl
					 << "You Have Selected Wrong Option , Please Select From The Following Options[A Or B Or C Or D]" << endl
					 << endl;
				goto ddd;
			}
			break;

		case 'B':
		case 'b':
		case '2':
		{
			char hch;
			string hcit, hname, hsize, hrat, hcost;
		agair:
			cin.sync();
			system("CLS");
			cout << "SETTING FLIGHT SYSTEM..." << endl
				 << endl;
			cout << "A)Add New Flight" << endl
				 << "B)Remove Airline" << endl
				 << "C)Update Existing Airlines Price" << endl
				 << "D)Back To Main Menu" << endl
				 << "E)Exit The Program";
			cout << endl
				 << "Please Select From The Given Options : ";
			cin >> hch;

			switch (hch)
			{
			case 'A':
			case 'a':
			case '1':
			{
				system("CLS");
				cout << "ADDING NEW FLIGHT..." << endl
					 << endl;
			airhh:
				cin.ignore();
				cout << "Enter Departure City? : ";
				getline(cin, hcit);
				cout << "Enter Destination City? : ";
				getline(cin, hname);
				cout << "Enter Time[i.e 9:00-10:55]? : ";
				getline(cin, hsize);
				cout << "Enter Flight Cost? : ";
				getline(cin, hrat);
				cout << "Enter Airline Company? : ";
				getline(cin, hcost);

				char addnew;
				system("CLS");
			reddyairb:
				cin.sync();
				cout << "Departure City : " << hcit << endl
					 << " Destination City : " << hname << endl
					 << "Time : " << hsize << endl
					 << "Flight Cost : " << hrat << endl
					 << "Airline Company : " << hcost << endl;
				cout << "Would You Like To Add This Hotel?[Y For YES , N FOR NO]? : ";
				cin >> addnew;

				switch (addnew)
				{
				case 'Y':
				case 'y':
				{
					string liner, liner2, liner3, liner4, fliner;
					int j = 1;
					char choiced1;
					ofstream hadd("airlines.txt", ios::app);
					hadd << endl
						 << hcit << ' ' << hname << ' ' << hsize << ' ' << hrat << ' ' << hcost << endl;
					hadd.close();
					cout << "Flight Details Added Successfully" << endl
						 << endl;
					cout << "Following Is The Updated List Of Airlines, Registered With Us." << endl
						 << endl;
					ifstream remag("airlines.txt");
					j = 1;
					while (remag >> liner >> liner2 >> liner3 >> liner4 >> fliner)
					{
						cout << j << ") " << fliner << endl;
						j++;
					}
				reddyair:
					cin.sync();
					cout << endl
						 << endl
						 << "Now What Would You Like To Do" << endl;
					cout << "A)Add Another Airline?" << endl
						 << "B)Back To Main Menu" << endl
						 << "C)Exit The Program";
					cout << endl
						 << "Please Select From The Given Options : ";
					cin >> choiced1;
					switch (choiced1)
					{
					case 'A':
					case 'a':
					case 1:
					{
						goto airhh;
					}
					break;

					case 'B':
					case 'b':
					case 2:
					{
						goto amai;
					}
					break;

					case 'C':
					case 'c':
					case 3:
					{
						exit(0);
					}
					break;

					default:
						system("CLS");
						cout << endl
							 << "You Have Selected Wrong Option , Please Select From The Following Options[A OR B Or C]" << endl
							 << endl;
						goto reddyair;
					}
				}
				break;

				case 'N':
				case 'n':
				{
					char choicedd;
					system("CLS");
				reddybair:
					cin.sync();
					cout << "Then What Would You Like To Do? : " << endl
						 << endl;
					cout << "A)Back To Main Menu" << endl
						 << "B)Exit The Program";
					cout << endl
						 << "Please Select From The Given Options : ";
					cin >> choicedd;
					switch (choicedd)
					{
					case 'A':
					case 'a':
					case 1:
					{
						goto amai;
					}
					break;

					case 'B':
					case 'b':
					case 2:
					{
						exit(0);
					}
					break;

					default:
						system("CLS");
						cout << endl
							 << "You Have Selected Wrong Option , Please Select From The Following Options[A OR B]" << endl
							 << endl;
						goto reddybair;
					}
				}

				break;

				default:
					system("CLS");
					cout << endl
						 << "You Have Selected Wrong Option , Please Select From The Following Options[Y OR N]" << endl
						 << endl;
					goto reddyairb;
				}
			}
			break;

			case 'B':
			case 'b':
			case '2':
			{
				int i = 0, j = 1, k = 1;
				string hrname, liner, liner2, liner3, liner4, fliner;
				string temp_main, temp1, temp2;

				system("CLS");
				cout << "REMOVING AIRLINE MENU..." << endl
					 << endl;
			aggair:
			anotair:
				cin.ignore();
				cout << "Following Is The List Of Airlines , Registered With Us." << endl
					 << endl;
				j = 1;
				ifstream remag("airlines.txt");
				while (remag >> liner >> liner2 >> liner3 >> liner4 >> fliner)
				{
					cout << j << ") " << fliner << endl;
					j++;
				}
				remag.close();

				ifstream rem("airlines.txt");
				ofstream remt("rem.txt", ios::trunc);
				cout << endl
					 << endl
					 << "Enter Airline Name You Want To Remove[CASE-SENSITIVE]? : ";
				getline(cin, hrname);

				i = 0;
				while (rem >> liner >> liner2 >> liner3 >> liner4 >> fliner)
				{
					if (fliner != hrname)
					{
						remt << liner << ' ' << liner2 << ' ' << liner3 << ' ' << liner4 << ' ' << fliner << endl;
					}
					else
					{
						i++;
					}
				}
				rem.close();
				remt.close();

				if (i < 1)
				{
					j = 1;
					system("CLS");
					cout << endl
						 << endl
						 << "Airline Name You Entered Not Found. Please Try Again." << endl
						 << endl;
					goto aggair;
				}
				else
				{
					string line;
					ofstream remg("airlines.txt", ios::trunc);
					ifstream remtt("rem.txt");
					while (getline(remtt, line))
					{
						remg << line << endl;
					}
					remtt.close();
					remove("rem.txt");
					remg.close();

					system("CLS");
					cout << endl
						 << endl
						 << "Airline[" << fliner << ']' << " Removed Successfully , Following Is The Updated List Of Airlines" << endl
						 << endl;
					k = 1;
					ifstream remagg("airlines.txt");
					while (remagg >> liner >> liner2 >> liner3 >> liner4 >> fliner)
					{
						cout << k << ") " << fliner << endl;
						k++;
					}
					remagg.close();

					char choicair;
				reddair:
					cin.sync();
					cout << endl
						 << endl
						 << "What You Want To Do Now? : ";
					cout << endl
						 << endl
						 << "A)Remove Another Airline?" << endl
						 << "B)Goto Main Menu" << endl
						 << "C)Exit The Program";
					cout << endl
						 << "Please Select From The Given Options : ";
					cin >> choicair;

					switch (choicair)
					{
					case 'A':
					case 'a':
					case '1':
					{
						goto anotair;
					}
					break;

					case 'B':
					case 'b':
					case '2':
					{
						goto mai;
					}
					break;

					case 'C':
					case 'c':
					case '3':
					{
						exit(0);
					}
					break;

					default:
						system("CLS");
						cout << endl
							 << "You Have Selected Wrong Option , Please Select From The Following Options[A Or B Or C]" << endl
							 << endl;
						goto reddair;
					}
				}
			}
			break;
			case 'C':
			case 'c':
			case '3':
			{
				int i = 0, j = 1, k = 1;
				string liner, liner2, liner3, fliner, cliner;
				system("CLS");
				cin.ignore();
				cout << "UPDATING AIRLINE DETAILS..." << endl
					 << endl;

			aggair2:
			anotair2:
				cout << "Following Is The List Of Airlines , Registered With Us." << endl
					 << endl;

				ifstream upd("airlines.txt");
				j = 1;
				while (upd >> liner >> liner2 >> liner3 >> cliner >> fliner)
				{
					cout << j << ") " << fliner << endl;
					cout << "Cost : " << cliner << endl
						 << endl;
					j++;
				}
				upd.close();

				string hup, ncost;
				cout << "Enter Airline Name , You Would Like To Update The Cost[CASE-SENSITIVE]? : ";
				getline(cin, hup);
				cout << "Enter New Cost To Update The Old Flight Cost? : ";
				getline(cin, ncost);

				ifstream upd1("airlines.txt");
				ofstream rem2("rem.txt", ios::trunc);
				i = 0;
				while (upd1 >> liner >> liner2 >> liner3 >> cliner >> fliner)
				{
					if (fliner != hup)
					{
						rem2 << liner << ' ' << liner2 << ' ' << liner3 << ' ' << cliner << ' ' << fliner << endl;
					}
					else
					{
						rem2 << liner << ' ' << liner2 << ' ' << liner3 << ' ' << ncost << ' ' << fliner << endl;
						i++;
					}
				}
				upd1.close();
				rem2.close();

				if (i < 1)
				{
					j = 1;
					system("CLS");
					cout << endl
						 << endl
						 << "Airline Name You Entered Not Found. Please Try Again." << endl
						 << endl;
					goto aggair2;
				}
				else
				{
					ofstream upd2("airlines.txt", ios::trunc);
					ifstream rem3("rem.txt");

					string linesss;
					while (getline(rem3, linesss))
					{
						upd2 << linesss << endl;
					}
					upd2.close();
					rem3.close();
					remove("rem.txt");

					system("CLS");
					cout << endl
						 << endl
						 << "The Cost Of Airline[" << fliner << ']' << " Updated Successfully , Following Is The Updated List Of Airlines" << endl
						 << endl;
					k = 1;
					ifstream remagg("airlines.txt");
					while (remagg >> liner >> liner2 >> liner3 >> cliner >> fliner)
					{
						cout << j << ") " << fliner << endl;
						cout << "Cost : " << cliner << endl
							 << endl;
						k++;
					}
					remagg.close();

					char choicair2;
				reddair2:
					cin.sync();
					cout << endl
						 << endl
						 << "What You Want To Do Now? : ";
					cout << endl
						 << endl
						 << "A)Update Another Airline's Cost?" << endl
						 << "B)Goto Main Menu" << endl
						 << "C)Exit The Program";
					cout << endl
						 << "Please Select From The Given Options : ";
					cin >> choicair2;

					switch (choicair2)
					{
					case 'A':
					case 'a':
					case '1':
					{
						goto anotair2;
					}
					break;

					case 'B':
					case 'b':
					case '2':
					{
						goto mai;
					}
					break;

					case 'C':
					case 'c':
					case '3':
					{
						exit(0);
					}
					break;

					default:
						system("CLS");
						cout << endl
							 << "You Have Selected Wrong Option , Please Select From The Following Options[A Or B Or C]" << endl
							 << endl;
						goto reddair2;
					}
				}
			}
			break;

			default:
				system("CLS");
				cout << endl
					 << "You Have Selected Wrong Option , Please Select From The Following Options[A Or B Or C]" << endl
					 << endl;
				goto agair;
			}
		}
		break;

		case 'C':
		case 'c':
		case '3':
		{
			char hch;
		ddat:
			cin.sync();
			system("CLS");
			cout << "SETTING ATTRACTIONS SYSTEM..." << endl
				 << endl;
			cout << "A)Add New Attractions" << endl
				 << "B)Remove Some Attractions" << endl
				 << "D)Back To Main Menu" << endl
				 << "E)Exit The Program";
			cout << endl
				 << "Please Select From The Given Options : ";
			cin >> hch;
			switch (hch)
			{
			case 'A':
			case 'a':
			case '1':
			{
				system("CLS");
				cout << "ADDING NEW ATTRACTIONS..." << endl
					 << endl;
			addat:
				cin.ignore();
				cout << "Enter Attraction City?[i.e Swat] : ";
				getline(cin, hcit);
				cout << "Enter Attraction Name?[i.e Swat Valley] : ";
				getline(cin, hname);
				cout << "Enter Some Info About Attraction[i.e This Place Is Located In Swat]? : ";
				getline(cin, hsize);

				char addnew;
				system("CLS");
			reddyatt:
				cin.sync();
				cout << "Attraction City : " << hcit << endl
					 << "Attraction Name : " << hname << endl
					 << "About Attraction : " << hsize << endl;
				cout << "Would You Like To Add This Attraction?[Y For YES , N FOR NO]? : ";
				cin >> addnew;

				switch (addnew)
				{
				case 'Y':
				case 'y':
				{
					string liner, liner2, fliner;
					int j = 1;
					char choiced1;
					ofstream hadd("attractions.txt", ios::app);
					hadd << endl
						 << hcit << ' ' << hname << ' ' << hsize << endl;
					hadd.close();
					cout << "Attraction Added Successfully" << endl
						 << endl;
					cout << "Following Is The Updated List Of Attractions , Registered With Us." << endl
						 << endl;
					ifstream remag("attractions.txt");
					j = 1;
					while (remag >> liner >> liner2 && getline(remag, fliner))
					{
						cout << j << ") " << liner2 << endl;
						j++;
					}
				reddyat:
					cin.sync();
					cout << endl
						 << endl
						 << "Now What Would You Like To Do" << endl;
					cout << "A)Add Another Attraction?" << endl
						 << "B)Back To Main Menu" << endl
						 << "C)Exit The Program";
					cout << endl
						 << "Please Select From The Given Options : ";
					cin >> choiced1;
					switch (choiced1)
					{
					case 'A':
					case 'a':
					case '1':
					{
						goto addat;
					}
					break;

					case 'B':
					case 'b':
					case '2':
					{
						goto ddat;
					}
					break;

					case 'C':
					case 'c':
					case '3':
					{
						exit(0);
					}
					break;

					default:
						system("CLS");
						cout << endl
							 << "You Have Selected Wrong Option , Please Select From The Following Options[A OR B Or C]" << endl
							 << endl;
						goto reddyat;
					}
				}
				break;

				case 'N':
				case 'n':
				{
					char choicedd;
					system("CLS");
				reddybat:
					cin.sync();
					cout << "Then What Would You Like To Do? : " << endl
						 << endl;
					cout << "A)Back To Main Menu" << endl
						 << "B)Exit The Program";
					cout << endl
						 << "Please Select From The Given Options : ";
					cin >> choicedd;
					switch (choicedd)
					{
					case 'A':
					case 'a':
					case '1':
					{
						goto amai;
					}
					break;

					case 'B':
					case 'b':
					case '2':
					{
						exit(0);
					}
					break;

					default:
						system("CLS");
						cout << endl
							 << "You Have Selected Wrong Option , Please Select From The Following Options[A OR B]" << endl
							 << endl;
						goto reddybat;
					}
				}

				break;

				default:
					system("CLS");
					cout << endl
						 << "You Have Selected Wrong Option , Please Select From The Following Options[Y OR N]" << endl
						 << endl;
					goto reddyatt;
				}
			}
			break;

			case 'B':
			case 'b':
			case '2':
			{
				int i = 0, j = 1, k = 1;
				string hrname, liner, linern, fliner;
				string temp_main, temp1, temp2;

				system("CLS");
				cin.ignore();
				cout << "REMOVING ATTRACTIONS MENU..." << endl
					 << endl;
			aggattr:
			anotattr:
				cout << "Following Is The List Of Attractions , Registered With Us." << endl
					 << endl;
				j = 1;
				ifstream remag("attractions.txt");
				while (remag >> liner >> linern && getline(remag, fliner))
				{
					cout << j << ") " << linern << endl;
					j++;
				}
				remag.close();

				ifstream rem("attractions.txt");
				ofstream remt("rem.txt", ios::trunc);
				cout << endl
					 << endl
					 << "Enter Attraction Name You Want To Remove[CASE-SENSITIVE]? : ";
				getline(cin, hrname);

				i = 0;
				while (rem >> liner >> linern && getline(rem, fliner))
				{
					if (linern != hrname)
					{
						remt << liner << ' ' << linern << ' ' << fliner << endl;
					}
					else
					{
						i++;
					}
				}
				rem.close();
				remt.close();

				if (i < 1)
				{
					j = 1;
					system("CLS");
					cout << endl
						 << endl
						 << "Attraction Name You Entered Not Found. Please Try Again." << endl
						 << endl;
					goto aggattr;
				}
				else
				{
					string line;
					ofstream remg("attractions.txt", ios::trunc);
					ifstream remtt("rem.txt");
					while (getline(remtt, line))
					{
						remg << line << endl;
					}
					remtt.close();
					remove("rem.txt");
					remg.close();

					system("CLS");
					cout << endl
						 << endl
						 << "Attractions[" << linern << ']' << " Removed Successfully , Following Is The Updated List Of Attractions" << endl
						 << endl;
					j = 1;
					ifstream remagg("attractions.txt");
					while (remagg >> liner >> linern && getline(remagg, fliner))
					{
						cout << j << ") " << linern << endl;
						j++;
					}
					remagg.close();

					char choicair;
				reddattr:
					cin.sync();
					cout << endl
						 << endl
						 << "What You Want To Do Now? : ";
					cout << endl
						 << endl
						 << "A)Remove Another Attraction?" << endl
						 << "B)Goto Main Menu" << endl
						 << "C)Exit The Program";
					cout << endl
						 << "Please Select From The Given Options : ";
					cin >> choicair;

					switch (choicair)
					{
					case 'A':
					case 'a':
					case '1':
					{
						goto anotattr;
					}
					break;

					case 'B':
					case 'b':
					case '2':
					{
						goto mai;
					}
					break;

					case 'C':
					case 'c':
					case '3':
					{
						exit(0);
					}
					break;

					default:
						system("CLS");
						cout << endl
							 << "You Have Selected Wrong Option , Please Select From The Following Options[A Or B Or C]" << endl
							 << endl;
						goto reddattr;
					}
				}
			}
			break;
			}
		}
		break;

		case 'D':
		case 'd':
		case '4':
		{
			char optio;
			system("CLS");
		ddemp:
			cin.sync();
			cout << "EMPLOYEE HIRING MENU..." << endl
				 << endl;
			string en, ep, es;
		addemp:
			cin.ignore();
			cout << "Enter Employee Name? : ";
			getline(cin, en);
			cout << "Enter Employee Password? : ";
			getline(cin, ep);
			cout << "Enter Employee Security Code? : ";
			getline(cin, es);

			char addnewa;
		reddyattemp:
			cin.sync();
			system("CLS");
			cout << "Employee Name : " << en << endl
				 << "Employee Password : " << ep << endl
				 << "Employee Security Code : " << en << endl;
			cout << "Would You Like To Add This Employee To Our Admin Records?[Y For YES , N FOR NO]? : ";
			cin >> addnewa;

			switch (addnewa)
			{
			case 'Y':
			case 'y':
			{
				string liner, fliner;
				int i = 0, j = 1, k = 1;
				ofstream hadd("admin_userpasscode.txt", ios::app);
				hadd << endl
					 << en << ' ' << ep << ' ' << es << endl;
				hadd.close();
				cout << "Employee Registered Successfully" << endl
					 << endl;
				cout << "Following Is The Updated List Of Employees , Registered With Us." << endl
					 << endl;
				ifstream remag("admin_userpasscode.txt");
				j = 1;
				while (remag >> liner && getline(remag, fliner))
				{
					cout << j << ") " << liner << endl;
					j++;
				}

				char choiced1;
			reddyemp:
				cin.sync();
				cout << endl
					 << endl
					 << "Now What Would You Like To Do" << endl;
				cout << "A)Add Another Employee?" << endl
					 << "B)Back To Main Menu" << endl
					 << "C)Exit The Program";
				cout << endl
					 << "Please Select From The Given Options : ";
				cin >> choiced1;

				switch (choiced1)
				{
				case 'A':
				case 'a':
				case '1':
				{
					goto addemp;
				}
				break;

				case 'B':
				case 'b':
				case '2':
				{
					goto ddemp;
				}
				break;

				case 'C':
				case 'c':
				case '3':
				{
					exit(0);
				}
				break;

				default:
					system("CLS");
					cout << endl
						 << "You Have Selected Wrong Option , Please Select From The Following Options[A OR B Or C]" << endl
						 << endl;
					goto reddyemp;
				}
			}
			break;

			case 'N':
			case 'n':
			case '2':
			{
				char choicedd;
				system("CLS");
			reddybatemp:
				cin.sync();
				cout << "Then What Would You Like To Do? : " << endl
					 << endl;
				cout << "A)Back To Main Menu" << endl
					 << "B)Exit The Program";
				cout << endl
					 << "Please Select From The Given Options : ";
				cin >> choicedd;
				switch (choicedd)
				{
				case 'A':
				case 'a':
				case '1':
				{
					goto amai;
				}
				break;

				case 'B':
				case 'b':
				case '2':
				{
					exit(0);
				}
				break;

				default:
					system("CLS");
					cout << endl
						 << "You Have Selected Wrong Option , Please Select From The Following Options[A OR B]" << endl
						 << endl;
					goto reddybatemp;
				}
			}
			break;

			default:
				system("CLS");
				cout << endl
					 << "You Have Selected Wrong Option , Please Select From The Following Options[Y OR N]" << endl
					 << endl;
				goto reddyattemp;
			}
		}
		break;

		case 'E':
		case 'e':
		case '5':
		{
			int i = 0, j = 1, k = 1;
			string hrname, liner, linern, fliner;

			system("CLS");
			cin.ignore();
			cout << "FIRING EMPLOYEE MENU..." << endl
				 << endl;
		aggaemp:
		anotemp:
			cout << "Following Is The List Of Employees , Registered With Us." << endl
				 << endl;
			j = 1;
			ifstream remag("admin_userpasscode.txt");
			while (remag >> liner && getline(remag, fliner))
			{
				cout << j << ") " << liner << endl;
				j++;
			}
			remag.close();

			ifstream rem("admin_userpasscode.txt");
			ofstream remt("rem.txt", ios::trunc);
			cout << endl
				 << endl
				 << "Enter Employee Name You Want To Fire[CASE-SENSITIVE]? : ";
			getline(cin, hrname);

			i = 0;
			while (rem >> liner && getline(rem, fliner))
			{
				if (liner != hrname)
				{
					remt << liner << ' ' << fliner << endl;
				}
				else
				{
					i++;
				}
			}
			rem.close();
			remt.close();

			if (i < 1)
			{
				j = 1;
				system("CLS");
				cout << endl
					 << endl
					 << "Employee Name You Entered Not Found. Please Try Again." << endl
					 << endl;
				goto aggaemp;
			}
			else
			{
				string line;
				ofstream remg("admin_userpasscode.txt", ios::trunc);
				ifstream remtt("rem.txt");
				while (getline(remtt, line))
				{
					remg << line << endl;
				}
				remtt.close();
				remove("rem.txt");
				remg.close();

				system("CLS");
				cout << endl
					 << endl
					 << "Employee[" << liner << ']' << " Fired Successfully , Following Is The Updated List Of Employees" << endl
					 << endl;
				j = 1;
				ifstream remagg("admin_userpasscode.txt");
				while (remagg >> liner && getline(remagg, fliner))
				{
					cout << j << ") " << liner << endl;
					j++;
				}
				remagg.close();

				char choicair;
			reddemp:
				cin.sync();
				cout << endl
					 << endl
					 << "What You Want To Do Now? : ";
				cout << endl
					 << endl
					 << "A)Remove Another Employee?" << endl
					 << "B)Goto Main Menu" << endl
					 << "C)Exit The Program";
				cout << endl
					 << "Please Select From The Given Options : ";
				cin >> choicair;

				switch (choicair)
				{
				case 'A':
				case 'a':
				case '1':
				{
					goto anotemp;
				}
				break;

				case 'B':
				case 'b':
				case '2':
				{
					goto mai;
				}
				break;

				case 'C':
				case 'c':
				case '3':
				{
					exit(0);
				}
				break;

				default:
					system("CLS");
					cout << endl
						 << "You Have Selected Wrong Option , Please Select From The Following Options[A Or B Or C]" << endl
						 << endl;
					goto reddemp;
				}
			}
		}
		break;

		case 'F':
		case 'f':
		case '6':
			return 200;
			break;

		case 'G':
		case 'g':
		case '7':
			exit(0);
			break;

		default:
			system("CLS");
			cout << endl
				 << "You Have Selected Wrong Option , Please Select From The Following Options[A Or B Or C Or D Or E Or F Or G]" << endl
				 << endl;
			goto ddde;
		}
	}
};

class user_control
{
private:
	// stays
	string destination, date, persons;
	int tempdate, tempp;

	// flights
	int page[100];
	float clss;
	string deptloc, dest, dd, per, ti, classi;

	// attractions
	string destin;

	// airport taxis
	string passe; // passengers
public:
	// constructors and destructors
	user_control() {}
	~user_control() {}

	// FUNCTIONS
	int user_services()
	{
		stringstream ss;
		char choices;
		bool menu; // to go back to main menu
	otherser:
	otherser2:
		system("CLS");
	r:
		cin.sync();
		cout << "Following Are The Services We Offer : " << endl;
		cout << endl
			 << "A)Hotel Booking" << endl
			 << "B)Flight Booking" << endl
			 << "C)Attractions" << endl
			 << "D)Airport Taxis" << endl
			 << "E)Go Back To Main Menu" << endl
			 << "F)Exit The Program";
		cout << endl
			 << "Please Select From The Given Options : ";
		cin >> choices;
		switch (choices)
		{
		case 'A':
		case 'a':
		case '1':
		{
			int cdddh = stays();
			if (cdddh == 800)
			{
				system("CLS");
				goto r;
			}
		}
		break;

		case 'B':
		case 'b':
		case '2':
		{
			int cddds = flight();
			if (cddds == 700)
			{
				system("CLS");
				goto r;
			}
		}
		break;

		case 'C':
		case 'c':
		case '3':
		{
			int cddde = att();
			if (cddde == 400)
			{
				system("CLS");
				goto r;
			}
		}
		break;

		case 'D':
		case 'd':
		case '4':
		{
			int cddd = taxis();
			if (cddd == 300)
			{
				system("CLS");
				goto r;
			}
		}
		break;

		case 'E':
		case 'e':
		case '5':
			return 100;
			break;

		case 'F':
		case 'f':
		case '6':
			exit(0);
			break;

		default:
			system("CLS");
			cout << endl
				 << "You Have Selected Wrong Option , Please Select From The Following Options[A Or B Or C Or D Or E Or F Or G]" << endl
				 << endl;
			goto r;
		}
	}

	int stays()
	{
		char con;
		string n, s, r;
		int p, parray[100];
		int i = 0;

		system("CLS");
		cout << "Thank You For Trusting Us For Your Staying Place, Please Tell Us More About Yourself" << endl
			 << endl;
	red:
		cin.ignore();
		cout << "Where Are You Going? : ";
		getline(cin, destination);
		cout << "How Many Days , You Will Be Travelling? : ";
		getline(cin, date);
		cout << "How Many Persons Will Be Travelling? : ";
		getline(cin, persons);
	whywrong:
		cin.sync();
		system("CLS");
		cout << "Destination : " << destination << endl
			 << "Total Travelling Day(s) : " << date << endl
			 << "Total Person(s) Travelling : " << persons;
		cout << endl
			 << "Is This The Information You Wanted To Enter[Press Y For Yes , And N For No]? : ";
		cin >> con;

		ofstream temp("temp.txt");
		temp << date << endl
			 << persons;
		temp.close();

		ifstream tempi("temp.txt");
		tempi >> tempdate >> tempp;
		tempi.close();
		remove("temp.txt");

		ifstream h("hotels.txt");
		switch (con)
		{
		case 'Y':
		case 'y':
		{
			string tempd; // temporary destination storage
			char z;
			int x = 0;
			system("CLS");
			cout << "Following Are The Available Options For Your Destination[" << destination << "]." << endl
				 << endl;
			while (h)
			{
				while (h >> tempd)
				{
					if (destination == tempd)
					{
						i++;
						x++;
						h >> n >> s >> r >> p;
						p = p * (tempdate * tempp);
						parray[i - 1] = p;
						cout << "Package : " << i << endl
							 << endl;
						cout << "Hotel Name : " << n << " HOTEL, " << destination << endl;
						cout << "Hotel Size : " << s << endl;
						cout << "Hotel Rating : " << r << endl;
						cout << "Hotel Price[For " << date << " Days] For " << persons << " Persons : " << p << " Pkr" << endl
							 << endl;
					}
				}

				if (x > 1)
				{
					char book;
					cout << endl
						 << endl
						 << "Please Go Through The Available Packages , Then Select From The Following Options." << endl
						 << endl;
					cout << "A)Book A Hotel[Details Will Be Taken Later]" << endl
						 << "B)Hotel You Were Looking Not Found? Try Our Other Services?" << endl
						 << "C)Exit The Program.";
					cout << endl
						 << "Please Select From The Given Options : ";
					cin >> book;
					switch (book)
					{
					case 'A':
					case 'a':
					case '1':
					{
						int f = 0;
						cout << endl
							 << endl
							 << endl
							 << "Please Enter Package Number , You Want To Book? : ";
						cin >> f;
						if (f <= i)
						{
							cout << endl
								 << endl
								 << "Thank You For Using Our Service To Book Your Hotel. ";
							cout << "Your Total Bill For Package " << f << " Will Be " << parray[f - 1] << " Pkr" << endl
								 << endl;
							cout << "Note : Please Pay The Bill Amount In 24 Hours , Or Your Booking Will Be Cancelled , And Penalty Of 2% Will Be Fined." << endl;
						}
					}
					break;

					case 'B':
					case 'b':
					case '2':
						return 800;
						break;

					case 'C':
					case 'c':
					case '3':
						exit(0);
						break;
					}
					h.close();
				}
				if (x <= 0)
				{
					system("CLS");
				rs:
					cin.sync();
					cout << "Sorry!. We Are Currently Unavailable For Your Destination." << endl
						 << endl;
					cout << "A)Go Back And Re-Fill The Tour Form" << endl
						 << "B)Exit The Program" << endl
						 << "Please Select From The Options Above : ";
					cin >> z;

					switch (z)
					{
					case 'A':
					case 'a':
					case '1':
						system("CLS");
						goto red;
						break;

					case 'B':
					case 'b':
					case '2':
						exit(0);
						break;

					default:
						system("CLS");
						cout << endl
							 << "You Have Selected Wrong Option , Please Select From The Following Options[A Or B]" << endl
							 << endl;
						goto rs;
					}
				}
			}
		}

		break;

		case 'N':
		case 'n':
		{
			char o;
			system("CLS");
		rep:
			cin.sync();
			cout << "A)Re-Enter Information" << endl
				 << "B)Exit The Program" << endl;
			cout << "Please Select From The Following Options : ";
			cin >> o;
			switch (o)
			{
			case 'A':
			case 'a':
			case '1':
				goto red;
				break;

			case 'B':
			case 'b':
			case '2':
				exit(0);
				break;

			default:
				system("CLS");
				cout << endl
					 << "You Have Selected Wrong Option , Please Select From The Following Options[A Or B]" << endl
					 << endl;
				goto rep;
			}
		}
		break;

		default:
			system("CLS");
			cout << endl
				 << "You Have Selected Wrong Option , Please Select From The Following Options[Y Or N]" << endl
				 << endl;
			goto whywrong;
		}
	}

	int flight()
	{
		int tp = 0, c = 0, cd = 0, o = 0;
		char cl;
		float farray[100];
		string cur, des, t, comp;
		float pr = 0;
		ofstream temp("temp.txt");
		ifstream tempi("temp.txt");

		system("CLS");
		cout << "Thank You For Trusting Us For Your Flight Booking, Please Tell Us More About Yourself" << endl
			 << endl;

	fr:
		cin.ignore();
		cout << "Where Are You Going? : ";
		getline(cin, dest);
		cout << "Where Are You Now? : ";
		getline(cin, deptloc);
		cout << "Enter Leaving Date? : ";
		getline(cin, dd);
		cout << "Enter Leaving Time? : ";
		getline(cin, ti);
		cout << "How Many Persons Will Be Travelling? : ";
		getline(cin, per);
		temp << per;
		temp.close();
		tempi >> tp;
		tempi.close();
		remove("temp.txt");

		if (tp > 1)
		{
			while (tp != c)
			{
				c++;
				cout << endl
					 << "Enter Age For Passenger " << c << " : ";
				cin >> page[c - 1];
			}
		}
	huh:
		cin.sync();
		cout << "Enter Flight Class, You Are Looking For? [Type P For Premium,E For Economy,F For First Class] : ";
		cin >> cl;
		if (cl == 'P' || cl == 'p')
		{
			clss = 0.30;
			classi = "Premium";
		}
		else if (cl == 'E' || cl == 'e')
		{
			clss = 0.20;
			classi = "Economic";
		}
		else if (cl == 'F' || cl == 'f')
		{
			clss = 0;
			classi = "First";
		}
		else
		{
			system("CLS");
			cout << endl
				 << "You Have Selected Wrong Option , Please Select From The Following Options[P,E OR F]" << endl;
			goto huh;
		}

		char con;
		system("CLS");
		cout << endl
			 << "Current Location : " << deptloc << endl
			 << "Destination : " << dest << endl
			 << "Departure Time : " << ti << endl
			 << "Departure Date : " << dd << endl
			 << "Total Person(s) Travelling : " << per << endl
			 << "Flight Class : " << classi;
		cout << endl
			 << "Is This The Information You Wanted To Enter[Press Y For Yes , And N For No]? : ";
		cin >> con;

		switch (con)
		{
		case 'Y':
		case 'y':
		{
			ifstream air("airlines.txt");
			system("CLS");
			cout << "Following Are The Available Options For Your Flight[" << classi << " Class]" << endl
				 << endl;
			while (air)
			{
				while (air >> cur >> des >> t >> pr >> comp)
				{
					if (des == dest && cur == deptloc)
					{
						cd++;
						o++;
						cout << "Package Number : " << o << endl;
						cout << "Airline Company : " << comp << endl;
						cout << "From : " << cur << " | To : " << des << endl;
						cout << "Time : " << t << endl;
						pr = (pr * tp) + (pr * clss);
						cout << "Price For " << per << " Persons[" << classi << " Class] : " << pr << " Rs" << endl
							 << endl;
						farray[cd - 1] = pr;
					}
				}
			}

			if (cd >= 1)
			{
				char bk;
				cout << endl
					 << endl
					 << "Please Go Through The Available Packages , Then Select From The Following Options." << endl
					 << endl;
				cout << "A)Book A Flight[Details Will Be Taken Later]" << endl
					 << "B)Flight You Were Looking Not Found? Try Our Other Services?" << endl
					 << "C)Exit The Program.";
				cout << endl
					 << "Please Select From The Given Options : ";
				cin >> bk;
				switch (bk)
				{
				case 'A':
				case 'a':
				case '1':
				{
					int k = 0;
					cout << endl
						 << endl
						 << endl
						 << "Please Enter Package Number , You Want To Book? : ";
					cin >> k;
					if (k <= cd)
					{
						cout << endl
							 << endl
							 << "Thank You For Using Our Service To Book Your Hotel. ";
						cout << "Your Total Bill For Package " << k << " Will Be " << farray[k - 1] << " Pkr" << endl
							 << endl;
						cout << "Note : Please Pay The Bill Amount In 24 Hours , Or Your Booking Will Be Cancelled , And Penalty Of 2% Will Be Fined." << endl;
					}
				}
				break;

				case 'B':
				case 'b':
				case '2':
					return 700;
					break;

				case 'C':
				case 'c':
				case '3':
					exit(0);
					break;
					air.close();
				}
			}
			if (cd <= 0)
			{
				char dx;
				system("CLS");
			rel:
				cin.sync();
				cout << "Sorry!. We Are Currently Unavailable For Your Destination." << endl
					 << endl;
				cout << "A)Go Back And Re-Fill The Flight Form" << endl
					 << "B)Exit The Program" << endl
					 << "Please Select From The Options Above : ";
				cin >> dx;

				switch (dx)
				{
				case 'A':
				case 'a':
				case '1':
					system("CLS");
					goto fr;
					break;

				case 'B':
				case 'b':
				case '2':
					exit(0);
					break;

				default:
					system("CLS");
					cout << endl
						 << "You Have Selected Wrong Option , Please Select From The Following Options[A Or B]" << endl
						 << endl;
					goto rel;
				}
			}
		}
		}
	}

	int att()
	{
		string nme, cit, spec;
		ifstream att("attractions.txt");
		system("CLS");
		cout << "Discover More Of Your Destination And Make The Most Of Your Trip, Please Tell Us More About Yourself" << endl
			 << endl;

		cin.ignore();
		cout << "Enter Your Destination? : ";
		getline(cin, destin);

		cout << endl
			 << endl
			 << "Following Are The Options , You Must Visit , If You Travel To " << destin << ".";
		while (att)
		{
			while (att >> cit >> nme && getline(att, spec))
			{
				if (destin == cit)
				{
					cout << endl
						 << endl
						 << "Name Of The Attraction : " << nme << endl
						 << endl;
					cout << "About The Place : " << spec << endl;
				}
			}
		}

		char othsr;
		cout << "Would You Like To Try Our Any Other Service? Or Do You Want To Exit The Program?" << endl
			 << endl;
	backt:
		cin.sync();
		cout << "A)Try Other Services." << endl
			 << "B)Exit The Program" << endl;
		cout << endl
			 << "Please Select From The Given Options : ";
		cin >> othsr;
		switch (othsr)
		{
		case 'A':
		case 'a':
		case 1:
			return 400;
			break;

		case 'B':
		case 'b':
		case 2:
			exit(0);
			break;

		default:
			system("CLS");
			cout << endl
				 << "You Have Selected Wrong Option , Please Select From The Following Options[A Or B]" << endl
				 << endl;
			goto backt;
		}
		att.close();
	}

	int taxis()
	{
		string si, bagcap, clink;
		int passen = 0, passtemp = 0;
		float apr = 0;
		ifstream tax("taxis.txt");
		system("CLS");
		cout << "Airport Transportation Made Easy, Please Tell Us More About Yourself." << endl
			 << endl;

		cin.ignore();
		cout << "How Many Passengers? : ";
		getline(cin, passe);
		ofstream ttt("temp.txt");
		ttt << passe;
		ttt.close();
		ifstream ttti("temp.txt");
		ttti >> passtemp;
		ttti.close();
		remove("temp.txt");

		cout << endl
			 << endl
			 << "Following Are The Cab Options Available For " << passe << " Persons.." << endl
			 << endl;
		while (tax)
		{
			while (tax >> passen >> si >> bagcap >> apr >> clink)
			{
				if (passtemp <= passen)
				{
					cout << "CAB TYPE : " << si << endl;
					cout << "Passengers Capacity : 1-" << passen << endl;
					cout << "Luggage Capacity : " << bagcap << " Bags." << endl;
					cout << "Approx Price : " << apr << " Rs." << endl;
					cout << "Book By Clicking Here : " << clink << endl
						 << endl;
				}
			}
		}

		char othsr;
		cout << "Would You Like To Try Our Any Other Service? Or Do You Want To Exit The Program?" << endl
			 << endl;
	backt:
		cin.sync();
		cout << "A)Try Other Services." << endl
			 << "B)Exit The Program" << endl;
		cout << endl
			 << "Please Select From The Given Options : ";
		cin >> othsr;
		switch (othsr)
		{
		case 'A':
		case 'a':
		case 1:
			system("CLS");
			return 300;
			break;

		case 'B':
		case 'b':
		case 2:
			exit(0);
			break;

		default:
			system("CLS");
			cout << endl
				 << "You Have Selected Wrong Option , Please Select From The Following Options[A Or B]" << endl
				 << endl;
			goto backt;
		}

		tax.close();
	}
};

// GLOBAL FUNCTIONS
void starter()
{
	admin_login admin;
	signup_login user;
	char choice;

back:
	cin.sync();
x:
	cin.sync();
	system("CLS");
	cout << "\t\t\t\t\t\t\t\t\t\tWelcome To FAA TOUR MANAGEMENT." << endl;
	cout << "A)Admin" << endl
		 << "B)User" << endl
		 << "C)Exit The Program" << endl;
	cout << "Please Select Any One Option From The Given Options : ";
	cin >> choice;

	switch (choice)
	{
	case 'A':
	case 'a':
	case '1':
		char ch;
		system("CLS");
		cout << "\t\t\t\t\t\t\t\t\t\tWELCOME TO ADMIN PANEL" << endl;
	r:
		cin.sync();
		cout << "A)Login Menu" << endl
			 << "B)Return To Main Menu" << endl
			 << "C)Exit The Program" << endl;
		cout << "Please Select Any One Option From The Given Options : ";
		cin >> ch;
		switch (ch)
		{
		case 'A':
		case 'a':
		case '1':
			bool check;
		ag:
			cin.sync();
			check = admin.login();
			if (check == true)
			{
				admin_control admina;
				int adminer = admina.admin_services();
				if (adminer == 200)
				{
					system("CLS");
					goto r;
				}
			}
			else
			{
				char c;
				system("CLS");
				cout << "You Have Entered Wrong Login Details." << endl
					 << endl;
			re:
				cin.sync();
				cout << "A)Try Again[Log in]" << endl
					 << "B)Return To Main Menu" << endl
					 << "C)Exit The Program" << endl;
				cout << "Please Select Any One Option From The Given Options : ";
				cin >> c;
				switch (c)
				{
				case 'A':
				case 'a':
				case '1':
					goto ag;
					break;

				case 'B':
				case 'b':
				case '2':
					goto back;
					break;

				case 'C':
				case 'c':
				case '3':
					exit(0);

				default:
					system("CLS");
					cout << endl
						 << "You Have Selected Wrong Option , Please Select From The Following Options[A Or B Or C]" << endl;
					goto re;
				}
			}
			break;

		case 'B':
		case 'b':
		case '2':
			goto back;
			break;

		case 'C':
		case 'c':
		case '3':
			exit(0);

		default:
			system("CLS");
			cout << endl
				 << "You Have Selected Wrong Option , Please Select From The Following Options[A Or B OR C]" << endl;
			goto r;
		}
		break;

	case 'B':
	case 'b':
	case '2':
		char ch1;
		system("CLS");
		cout << "\t\t\t\t\t\t\t\t\t\tWELCOME TO USER PANEL" << endl;
	ru:
	agm:
		cin.sync();
		cout << "A)Login Menu" << endl
			 << "B)Sign-up" << endl
			 << "C)Return To Main Menu" << endl
			 << "D)Exit The Program" << endl;
		cout << "Please Select Any One Option From The Given Options : ";
		cin >> ch1;
		switch (ch1)
		{
		case 'A':
		case 'a':
		case '1':
		login:
			cin.sync();
			bool check;
		agu:
			cin.sync();
			check = user.login();
			if (check == true)
			{
				user_control user;
				int mainer = user.user_services();
				if (mainer == 100)
				{
					system("CLS");
					cout << endl
						 << endl;
					goto agm;
				}
			}
			else
			{
				char c;
				system("CLS");
				cout << "You Have Entered Wrong Login Details." << endl
					 << endl;
			reu:
				cin.sync();
				cout << "A)Try Again[Log in]" << endl
					 << "B)Return To Main Menu" << endl
					 << "C)Exit The Program" << endl;
				cout << "Please Select Any One Option From The Given Options : ";
				cin >> c;
				switch (c)
				{
				case 'A':
				case 'a':
				case '1':
					goto agu;
					break;

				case 'B':
				case 'b':
				case '2':
					goto back;
					break;

				case 'C':
				case 'c':
				case '3':
					exit(0);

				default:
					system("CLS");
					cout << endl
						 << "You Have Selected Wrong Option , Please Select From The Following Options[A Or B Or C]" << endl;
					goto reu;
				}
			}
			break;

		case 'B':
		case 'b':
		case '2':
			char log;
			user.sign_up();
			system("CLS");
		h:
			cin.sync();
			cout << "Your Account Is Created , Do You Want Login Now, Or Later?" << endl
				 << "A)Login Now" << endl
				 << "B)Go Back To Main Menu" << endl
				 << "C)Exit The Program" << endl;
			cout << "Please Select From The Given Options!. : ";
			cin >> log;
			switch (log)
			{
			case 'A':
			case 'a':
			case '1':
				goto login;
				break;

			case 'B':
			case 'b':
			case '2':
				goto x;
				break;

			case 'C':
			case 'c':
			case '3':
				exit(0);

			default:
				system("CLS");
				cout << endl
					 << "You Have Selected Wrong Option , Please Select From The Following Options[A Or B Or C]" << endl;
				goto h;
			}

			break;

		case 'C':
		case 'c':
		case '3':
			goto back;
			break;

		case 'D':
		case 'd':
		case '4':
			exit(0);
			break;

		default:
			system("CLS");
			cout << endl
				 << "You Have Selected Wrong Option , Please Select From The Following Options[A Or B Or C Or D]" << endl;
			goto ru;
		}
		break;

	case 'C':
	case 'c':
	case '3':
		exit(0);
		break;

	default:
		system("CLS");
		cout << endl
			 << "You Have Selected Wrong Option , Please Select From The Following Options[A Or B Or C]" << endl;
		goto x;
	}
}

// STATIC INITIALIZATION
int signup_login::total_users;
int admin_login::total_admins;

int main()
{
	
//	starter();
admin_control ob1 ; 
ob1.admin_services();
//signup_login ob2 ; 
//ob2.sign_up();
//ob2.login() ; 
	
	return 0;
}
