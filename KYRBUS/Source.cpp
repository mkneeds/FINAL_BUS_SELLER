#define _CRT_SECURE_NO_WARNINGS
#include "Menu.h"
using namespace std;
const int SIZE_ARR_OF_ACCOUNTS = 1;
const char* ADMIN_STATUS = "111";
const string FILE_OF_ACCOUNTS = "User.txt";
const string FILE_OF_TICKETS = "Ticket.txt";
const string FILE_OF_OCHET = "Otchet.txt";
const string FILE_OF_BALANCE = "Balance.txt";
const int SIZE_ARR_OF_TICKET = 100;
int account_point = 0;
char* main_loogin = new char[256];
char* main_balance = new char[256];
struct Accounts {
	string login;
	string password;
	string role; // USER-100/ADMIN-111
}ac;
struct Tickets {
	string price;
	string Number_of_route;
	string Num_of_ticket;
	string DepDate;
	string ArrDate;
	string DeparturePlace;
	string ArrivalPlace;
}tk;
struct PayMethod {
	string p_login;
	string Number_card;
	string name;
	string Surname;
	string data_card;
	string balance;
	string CCV;
};
void writeEndFileAccounts(Accounts new_account);
void writeEndFileTickets(Tickets mas_ticket);
void writeEndFileCard(PayMethod mas_ticket);

string SetLogin();
string SetPassword();
HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);

enum class color : unsigned short
{
	black, blue, green, cyan, red, magenta, brown, lightgray, darkgray,
	lightblue, lightgreen, lightcyan, lightred, lightmagenta, yellow, white
};
void set_col(color foreground, color background)
{
	SetConsoleTextAttribute(
		hout,
		((short)background << 4) | (short)foreground);

}

int main()
{
	set_col(color::green, color::black);
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "rus");
	menu::pasxx();
	primary_authorization();

}

void primary_authorization() {
	Accounts mas_of_accounts[SIZE_ARR_OF_ACCOUNTS];
	ifstream fin(FILE_OF_ACCOUNTS, ios::in);
	if (fin.peek() == EOF) {
		cout << "�� ��������� ������ ������������� ���������!" << endl;
		cout << "������� �����:" << endl;
		mas_of_accounts[0].login = SetLogin();
		cout << "������� ������:" << endl;
		mas_of_accounts[0].password = SetPassword();
		mas_of_accounts[0].role = "111";
		account_point = 1;
		writeEndFileAccounts(mas_of_accounts[0]);
		menu::authorization();
		fin.close();
	}
	else {
		menu::authorization();
		switch (checkInterval(1, 3)) {
		case 1:  auth(); break;
		case 2: signup(); break;
		case 3: exit(1);
		}
	}

}
void writeEndFileAccounts(Accounts new_account)
{
	ofstream fout(FILE_OF_ACCOUNTS, ios::app);
	fout << new_account.login << " " << new_account.password << " " << new_account.role;
	fout << endl;
	fout.close();
}
void auth() {
	memset(main_loogin, 0, sizeof(main_loogin));
	char* login = new char[256];
	char* password = new char[256];
	int controller, autho;
	int access = 0;
	autho = controller = 0;
	cout << "Login: "; cin.clear(); cin.getline(login, 256, '\n');
	strcpy(main_loogin, login);
	cout << "Password: ";
	string stroka;
	stroka = encryption();
	strcpy(password, stroka.c_str());
	cout << endl;
	ifstream fin(FILE_OF_ACCOUNTS, ios::in);
	char* checher_login = new char[256];
	char* checher_password = new char[256];
	char* checher_role = new char[256];
	fin.seekg(0, ios::beg);
	fstream clear_file(FILE_OF_OCHET, ios::out);
	clear_file.close();
	if (!fin) {
		cout << "��� ������� � �����,���������� � ������///";
	}
	else {
		while (strcmp(checher_login, login) != 0 && !fin.eof()) {
			fin >> checher_login;
			if (strcmp(login, checher_login) == 0) {
				fin >> checher_password;
				controller = 0;
			}
			else {
				controller = 1;
			}
		}
		if (strcmp(password, checher_password) != 0) {
			controller = 1;
		}
		else {
			fin >> checher_role;
		}
		if (controller == 1) {
			delete[]login;
			delete[]password;
			delete[]checher_login;
			delete[]checher_password;
			fin.close();
			cout << "����� ��� ������ ������� �������.��������� �������" << endl;
			main();
		}
		else {
			cout << "�� �����...." << endl;
			if (strcmp(checher_role, ADMIN_STATUS) == 0) {
				system("cls");
				delete[]login;
				delete[]password;
				delete[]checher_login;
				delete[]checher_password;
				delete[]checher_role;
				fin.close();
				admin_menu();
			}
			else {
				delete[]login;
				delete[]password;
				delete[]checher_login;
				delete[]checher_password;
				delete[]checher_role;
				system("cls");
				fin.close();
				user();
			}

		}
	}
}
void admin_menu() {
	system("cls");
	menu::vibor_menu();
	switch (checkInterval(1, 23)) {
	case 1: admin(); break;
	case 2: user(); break;
	case 3: primary_authorization(); break;
	case 4: exit(1);
	case 23: {
		menu::pasx();
		system("pause");
		admin_menu();
		break;
	}
	default: admin_menu(); break;
	}
}
void signup() {
	if (account_point == 0) {
		char* login = new char[256];
		int controller = 0;
		Accounts mas_of_accounts[SIZE_ARR_OF_ACCOUNTS];
		ifstream fout(FILE_OF_ACCOUNTS);
		cout << "\t\t�����������:" << endl;
		cout << "������� �����:" << endl;
		strcpy(login, SetLogin().data());

		char* login_check_povtor = new char[256];
		if (!fout.is_open()) {
			cout << "�� ������ ������� ��...���������� � ��������������" << endl;
		}
		else {
			while (!fout.eof()) {
				fout >> login_check_povtor;
				if (strcmp(login_check_povtor, login) != 0) {
					controller = 0;
				}
				else {
					controller = 1;
					break;
				}
			}
		}
		if (controller == 0) {
			mas_of_accounts[0].login = login;
			cout << "������� ������:" << endl;
			mas_of_accounts[0].password = SetPassword();
			mas_of_accounts[0].role = "100";
			account_point = 1;
			writeEndFileAccounts(mas_of_accounts[0]);
			system("cls");
			cout << "����������� ������ �������" << endl;
			primary_authorization();
		}
		else {
			delete[] login;
			delete[] login_check_povtor;
			fout.close();
			cout << "����� ����� ��� ���������� ��������� �������...." << endl;
			signup();
		}

	}
	else {
		cout << "�� ��� ������� �������...�������������" << endl;
		primary_authorization();
	}
}
string SetLogin() {
	int controller;
	char* BufForWriting = new char[100];
	char symbols[] = "QWERTYUIOPASDFGHJKLZXCVBNMqwertyuiopasdfghjklzxcvbnm._-1234567890";
	do {
		controller = 0;
		cin.clear();
		cin.getline(BufForWriting, 100, '\n');
		if (strlen(BufForWriting) < 6)
		{
			cout << "����� ������ ��������� 6 ��� ����� ��������: ";
			controller = 1;
		}
		else
		{
			for (register int i = 0; BufForWriting[i] != '\0'; i++)
			{
				controller = 2;
				for (register int j = 0; symbols[j] != '\0'; j++)
				{
					if (BufForWriting[i] == symbols[j]) { controller = 0; break; }
				}
				if (controller == 2)
				{
					cout << "����� ����� ��������� ��������� �����, ����� � ����������� �������(-._): ";
					break;
				}
			}
		}
	} while (controller != 0);
	return  BufForWriting;
	delete[] BufForWriting;
}
string SetPassword()
{
	char* BufForWriting = new char[100];
	int controller, num, alpha;
	do {
		string stroka;
		stroka = encryption();
		strcpy(BufForWriting, stroka.c_str());
		controller = 0; alpha = 0; num = 0;
		if (strlen(BufForWriting) < 8)
		{
			cout << "\n������ ������ ��������� 8 ��� ����� ��������: \n";
			controller = -1;
		}
		else
		{
			for (register int i = 0; BufForWriting[i] != '\0'; i++)
			{
				if (isspace(BufForWriting[i]))
				{
					cout << "\n������ �� ������ ��������� �������: \n";
					controller = -1;
					break;
				}
				else if (isdigit(BufForWriting[i]))
					num++;
				else if (isalpha(BufForWriting[i]))
					alpha++;
			}
			if (controller != -1 && (num == 0 || alpha == 0))
			{
				cout << "\n������ ������ ��������� ����� � �����: \n";
				controller = -1;
			}
		}
	} while (controller == -1);
	return BufForWriting;
	delete[] BufForWriting;
}

void addInformation() {
	system("cls");
	Tickets* mas_of_ticket = new Tickets[SIZE_ARR_OF_TICKET];
	cout << "\t������� ���������� ���������� ~ ���������� ������" << endl;
	int chislo;
	cin >> chislo;
	for (int i = 0; i < chislo; i++) {
		cout << "\t������� ����� �����:" << endl;
		cin >> mas_of_ticket[i].Number_of_route;
		cout << "\t������� ����� ����������� :" << endl;
		cin >> mas_of_ticket[i].DeparturePlace;
		cout << "\t������� ����� ��������:" << endl;
		cin >> mas_of_ticket[i].ArrivalPlace;
		cout << "\t������� ����� �����������:" << endl;
		cin >> mas_of_ticket[i].DepDate;
		cout << "\t������� ����� ��������:" << endl;
		cin >> mas_of_ticket[i].ArrDate;
		cout << "\t������� ���������� �������:" << endl;
		cin >> mas_of_ticket[i].Num_of_ticket;
		cout << "\t������� ����:" << endl;
		cin >> mas_of_ticket[i].price;
		writeEndFileTickets(mas_of_ticket[i]);
	}
	delete[]mas_of_ticket;
	admin();
}
void writeEndFileTickets(Tickets mas_ticket)
{
	ofstream fout(FILE_OF_TICKETS, ios::app);
	fout << mas_ticket.Number_of_route << " " << mas_ticket.DeparturePlace << " " << mas_ticket.ArrivalPlace << " " << mas_ticket.DepDate << " " << mas_ticket.ArrDate << " " << mas_ticket.Num_of_ticket << " " << mas_ticket.price;
	fout << endl;
	fout.close();
}

void changeInformation() {

	system("cls");
	ifstream fout(FILE_OF_TICKETS, ios::in);
	showInormatiom();
	cout << "\t������� ����� ����� ������� ����� ��������:" << endl;
	char* number_of_route = new char[256];
	char* number_check = new char[256];
	int counter = 0;
	int counter_check = 0;
	int counter_check_str = 0;
	int counter_check_str_first = 0;
	cin >> number_of_route;
	vector <string> vec;
	while (!fout.eof()) {
		fout >> number_check;
		counter++;
		if (counter % 8 == 0 || counter == 1) {

			if (strcmp(number_of_route, number_check) == 0) {
				counter_check_str++;
				while (counter_check <= 6) {
					vec.push_back(number_check);
					fout >> number_check;
					counter_check++;

				}
				break;
			}
			else {
				cout << "\t������ ����� ���.��������� �������" << endl;
				system("pause");
				delete[]number_check;
				delete[]number_of_route;
				admin();
			}
		}
		if (counter == 8) {
			counter = 1;
			counter_check_str++;

		}
	}
	if (counter == 1) {
		counter_check_str = 1;
	}
	else {
		counter_check_str++;
	}
	fout.seekg(0, ios::beg);
	int i_number_line_now = 0;
	string line;
	string line_file_text;

	while (getline(fout, line)) {
		i_number_line_now++;
		if (!(i_number_line_now == counter_check_str)) {
			line_file_text.insert(line_file_text.size(), line);
			line_file_text.insert(line_file_text.size(), "\r\n");
		}
	}
	fout.close();
	ofstream fz;
	fz.open(FILE_OF_TICKETS, ios::trunc | ios::binary);
	fz.write(line_file_text.c_str(), line_file_text.size());
	fz.clear();
	fz.close();
	delete[]number_check;
	delete[]number_of_route;
	Tickets* mas_of_ticket = new Tickets[SIZE_ARR_OF_TICKET];
	menu::change_tickets();
	switch (checkInterval(1, 9)) {
	case 1:
		cout << "\t������� ����� �����:" << endl;
		cin >> mas_of_ticket[0].Number_of_route;
		cout << "\t������� ����� ����������� :" << endl;
		cin >> mas_of_ticket[0].DeparturePlace;
		cout << "\t������� ����� ��������:" << endl;
		cin >> mas_of_ticket[0].ArrivalPlace;
		cout << "\t������� ����� �����������:" << endl;
		cin >> mas_of_ticket[0].DepDate;
		cout << "\t������� ����� ��������:" << endl;
		cin >> mas_of_ticket[0].ArrDate;
		cout << "\t������� ���������� �������:" << endl;
		cin >> mas_of_ticket[0].Num_of_ticket;
		cout << "\t������� ����:" << endl;
		cin >> mas_of_ticket[0].price;
		writeEndFileTickets(mas_of_ticket[0]);
		delete[]mas_of_ticket;
		break;
	case 2:
		cout << "\t������� ����� �����:" << endl;
		cin >> mas_of_ticket[0].Number_of_route;
		mas_of_ticket[0].DeparturePlace = vec[1];
		mas_of_ticket[0].ArrivalPlace = vec[2];
		mas_of_ticket[0].DepDate = vec[3];
		mas_of_ticket[0].ArrDate = vec[4];
		mas_of_ticket[0].Num_of_ticket = vec[5];
		mas_of_ticket[0].price = vec[6];
		writeEndFileTickets(mas_of_ticket[0]);
		delete[]mas_of_ticket;
		break;
	case 3:
		mas_of_ticket[0].Number_of_route = vec[0];
		cout << "\t������� ����� ����������� :" << endl;
		cin >> mas_of_ticket[0].DeparturePlace;
		mas_of_ticket[0].ArrivalPlace = vec[2];
		mas_of_ticket[0].DepDate = vec[3];
		mas_of_ticket[0].ArrDate = vec[4];
		mas_of_ticket[0].Num_of_ticket = vec[5];
		mas_of_ticket[0].price = vec[6];
		writeEndFileTickets(mas_of_ticket[0]);
		delete[]mas_of_ticket;
		break;
	case 4:
		cout << "\t������� ����� ��������:" << endl;
		cin >> mas_of_ticket[0].ArrivalPlace;
		mas_of_ticket[0].Number_of_route = vec[0];
		mas_of_ticket[0].DeparturePlace = vec[1];
		mas_of_ticket[0].DepDate = vec[3];
		mas_of_ticket[0].ArrDate = vec[4];
		mas_of_ticket[0].Num_of_ticket = vec[5];
		mas_of_ticket[0].price = vec[6];
		writeEndFileTickets(mas_of_ticket[0]);
		delete[]mas_of_ticket;
		break;
	case5:
		cout << "\t������� ����� �����������:" << endl;
		cin >> mas_of_ticket[0].DepDate;
		mas_of_ticket[0].ArrivalPlace = vec[2];
		mas_of_ticket[0].Number_of_route = vec[0];
		mas_of_ticket[0].DeparturePlace = vec[1];
		mas_of_ticket[0].ArrDate = vec[4];
		mas_of_ticket[0].Num_of_ticket = vec[5];
		mas_of_ticket[0].price = vec[6];
		writeEndFileTickets(mas_of_ticket[0]);
		delete[]mas_of_ticket;
		break;
	case 6:
		cout << "\t������� ����� ��������:" << endl;
		cin >> mas_of_ticket[0].ArrDate;
		mas_of_ticket[0].DepDate = vec[3];
		mas_of_ticket[0].ArrivalPlace = vec[2];
		mas_of_ticket[0].Number_of_route = vec[0];
		mas_of_ticket[0].DeparturePlace = vec[1];
		mas_of_ticket[0].ArrDate = vec[4];
		mas_of_ticket[0].Num_of_ticket = vec[5];
		mas_of_ticket[0].price = vec[6];
		writeEndFileTickets(mas_of_ticket[0]);
		delete[]mas_of_ticket;
		break;
	case 7:
		cout << "\t������� ���������� �������:" << endl;
		cin >> mas_of_ticket[0].Num_of_ticket;
		mas_of_ticket[0].Number_of_route = vec[0];
		mas_of_ticket[0].DeparturePlace = vec[1];
		mas_of_ticket[0].ArrivalPlace = vec[2];
		mas_of_ticket[0].DepDate = vec[3];
		mas_of_ticket[0].ArrDate = vec[4];
		mas_of_ticket[0].price = vec[6];
		writeEndFileTickets(mas_of_ticket[0]);
		delete[]mas_of_ticket;
		break;
	case 8:
		cout << "\t������� ����:" << endl;
		cin >> mas_of_ticket[0].price;
		mas_of_ticket[0].Number_of_route = vec[0];
		mas_of_ticket[0].DeparturePlace = vec[1];
		mas_of_ticket[0].ArrivalPlace = vec[2];
		mas_of_ticket[0].DepDate = vec[3];
		mas_of_ticket[0].ArrDate = vec[4];
		mas_of_ticket[0].Num_of_ticket = vec[5];
		writeEndFileTickets(mas_of_ticket[0]);
		delete[]mas_of_ticket;
		break;
	case 9:
		mas_of_ticket[0].Number_of_route = vec[0];
		mas_of_ticket[0].DeparturePlace = vec[1];
		mas_of_ticket[0].ArrivalPlace = vec[2];
		mas_of_ticket[0].DepDate = vec[3];
		mas_of_ticket[0].ArrDate = vec[4];
		mas_of_ticket[0].Num_of_ticket = vec[5];
		mas_of_ticket[0].price = vec[6];
		writeEndFileTickets(mas_of_ticket[0]);

		system("pause");
		admin();
		break;
	}
	admin();
}
void showInormatiom() {
	ifstream fout(FILE_OF_TICKETS, ios::in);
	TextTable t('-', '|', '+');
	t.add("����� �����");
	t.add("����� �����������");
	t.add("����� ��������");
	t.add("����� �����������");
	t.add("����� ��������");
	t.add("� �������");
	t.add("����,$");
	t.endOfRow();
	while (fout >> tk.Number_of_route >> tk.DeparturePlace >> tk.ArrivalPlace >> tk.DepDate >> tk.ArrDate >> tk.Num_of_ticket >> tk.price) {
		t.add(tk.Number_of_route);
		t.add(tk.DeparturePlace);
		t.add(tk.ArrivalPlace);
		t.add(tk.DepDate);
		t.add(tk.ArrDate);
		t.add(tk.Num_of_ticket);
		t.add(tk.price);
		t.endOfRow();
	}
	cout << t;
	fout.close();
}
void delInformation() {
	system("cls");
	ifstream fout(FILE_OF_TICKETS, ios::in);
	fout.seekg(0, ios::beg);
	showInormatiom();
	cout << "\t������� ����� ����� ������� ����� �������:" << endl;
	char* number_of_route = new char[256];
	char* number_check = new char[256];
	int counter = 0;
	int counter_check = 0;
	int counter_check_str = 0;
	int counter_check_str_first = 0;
	cin >> number_of_route;
	/*i_number_line_delete=atoi(number_of_route);*/
	vector <string> vec;
	while (!fout.eof()) {
		fout >> number_check;
		counter++;
		if (counter % 8 == 0 || counter == 1) {

			if (strcmp(number_of_route, number_check) == 0) {
				counter_check_str++;
				while (counter_check <= 6) {
					vec.push_back(number_check);
					fout >> number_check;
					counter_check++;

				}
				break;
			}
		}
		if (counter == 8) {
			counter = 1;
			counter_check_str++;

		}
	}
	if (counter == 1) {
		counter_check_str = 1;
	}
	else {
		counter_check_str++;
	}
	fout.seekg(0, ios::beg);
	int i_number_line_now = 0;
	string line;
	string line_file_text;

	while (getline(fout, line)) {
		i_number_line_now++;
		if (!(i_number_line_now == counter_check_str)) {
			line_file_text.insert(line_file_text.size(), line);
			line_file_text.insert(line_file_text.size(), "\r\n");
		}
	}
	fout.close();
	ofstream fzz;
	fzz.open(FILE_OF_TICKETS, ios::trunc | ios::binary);
	fzz.write(line_file_text.c_str(), line_file_text.size());
	fzz.clear();
	fzz.close();
	delete[]number_check;
	delete[]number_of_route;
	cout << "���������� �������" << endl;
}
void user() {
	menu::user();
	switch (checkInterval(1, 5)) {
	case 1: system("cls"); showInormatiom(); system("pause"); user(); break;
	case 2: system("cls"); buyPass(); system("pause"); user(); break;
	case 3: system("cls"); otchet(); user(); break;
	case 4: system("cls"); changePassword(); user(); break;
	case 5: system("cls"); balance(); break;
	}

}
void admin() {
	menu::admin();
	switch (checkInterval(1, 8)) {
	case 1: addInformation();  break;
	case 2: changeInformation(); break;
	case 3: system("cls"); showInormatiom(); system("pause"); system("cls"); admin(); break;
	case 4: delInformation(); showInormatiom(); system("pause"); system("cls"); admin(); break;
	case 5: system("cls"); sort(); showInormatiom(); system("pause"); admin(); break;
	case 6: system("cls"); change_user(); break;
	case 7: system("cls"); changePassword(); admin(); break;
	case 8: system("cls"); admin_menu(); break;
	}
}
void sort() {
	ifstream in(FILE_OF_TICKETS);
	vector<string>vs;
	string s;
	while (getline(in, s)) vs.push_back(s);
	sort(vs.begin(), vs.end());
	ofstream on(FILE_OF_TICKETS);
	copy(vs.begin(), vs.end(), ostream_iterator<string>(on, "\n"));
	cout << "���������� ������ �������" << endl;
	on.close();
	in.close();
}
void change_user() {
	ifstream fout(FILE_OF_ACCOUNTS, ios::in);
	cout << "������� �������������~" << endl;
	TextTable user('*', '|', '+');
	user.add("�����");
	user.add("������");
	user.add("������");
	user.endOfRow();
	while (fout >> ac.login >> ac.password >> ac.role) {
		user.add(ac.login);
		user.add(ac.password);
		user.add(ac.role);
		user.endOfRow();
	}
	cout << user;
	fout.close();
	menu::controlUsers();
	switch (checkInterval(1, 4)) {
	case 1: addAdmin(); break;
	case 2: addUser(); break;
	case 3: deleteUser(); break;
	case 4: admin(); break;
	}
}
void addUser() {
	char* login = new char[256];
	int controller = 0;
	Accounts mas_of_accounts[SIZE_ARR_OF_ACCOUNTS];
	ifstream fout(FILE_OF_ACCOUNTS);
	cout << "\t\t�����������(USER):" << endl;
	cout << "������� �����:" << endl;
	strcpy(login, SetLogin().data());

	char* login_check_povtor = new char[256];
	if (!fout.is_open()) {
		cout << "�� ������ ������� ��...���������� � ��������������" << endl;
	}
	else {
		while (!fout.eof()) {
			fout >> login_check_povtor;
			if (strcmp(login_check_povtor, login) != 0) {
				controller = 0;
			}
			else {
				controller = 1;
				break;
			}
		}
	}
	if (controller == 0) {
		mas_of_accounts[0].login = login;
		cout << "������� ������:" << endl;
		mas_of_accounts[0].password = SetPassword();
		mas_of_accounts[0].role = "100";
		account_point = 1;
		writeEndFileAccounts(mas_of_accounts[0]);
		system("cls");
		cout << "����������� ������ �������" << endl;
		change_user();
	}
	else {
		delete[] login;
		delete[] login_check_povtor;
		fout.close();
		cout << "����� ����� ��� ���������� ��������� �������...." << endl;
		addUser();
	}
}
void addAdmin() {
	char* login = new char[256];
	int controller = 0;
	Accounts mas_of_accounts[SIZE_ARR_OF_ACCOUNTS];
	ifstream fout(FILE_OF_ACCOUNTS);
	cout << "\t\t�����������(ADMIN):" << endl;
	cout << "������� �����:" << endl;
	strcpy(login, SetLogin().data());

	char* login_check_povtor = new char[256];
	if (!fout.is_open()) {
		cout << "�� ������ ������� ��...���������� � ��������������" << endl;
	}
	else {
		while (!fout.eof()) {
			fout >> login_check_povtor;
			if (strcmp(login_check_povtor, login) != 0) {
				controller = 0;
			}
			else {
				controller = 1;
				break;
			}
		}
	}
	if (controller == 0) {
		mas_of_accounts[0].login = login;
		cout << "������� ������:" << endl;
		mas_of_accounts[0].password = SetPassword();
		mas_of_accounts[0].role = "111";
		account_point = 1;
		writeEndFileAccounts(mas_of_accounts[0]);
		system("cls");
		cout << "����������� ������ �������" << endl;
		change_user();
	}
	else {
		delete[] login;
		delete[] login_check_povtor;
		fout.close();
		cout << "����� ����� ��� ���������� ��������� �������...." << endl;
		addAdmin();
	}
}
void deleteUser() {
	ifstream file_zin;
	file_zin.open(FILE_OF_ACCOUNTS);
	if (!file_zin) {
		cout << "������, ���������� ������� ����: " << FILE_OF_ACCOUNTS << endl;
	}
	cout << "������� ����� ������������ ������� ����� �������..." << endl;
	char* login = new char[256];
	cin >> login;
	char* login_check = new char[256];
	int checker = 0;
	int proverka = 0;
	int nomer_str = 0;
	while (!file_zin.eof()) {
		file_zin >> login_check;
		if (strcmp(login, login_check) == 0) {
			proverka = 1;
			nomer_str++;
			break;
		}
		else {
			checker++;
		}
		if (checker % 3 == 0) {
			checker = 0;
			nomer_str++;
		}
	}
	if (proverka != 1) {
		cout << "����� �� ������..." << endl;
	}
	else {
		file_zin.seekg(0, ios::beg);
		int i_number_line_now = 0;
		string line;
		string line_file_text;

		while (getline(file_zin, line))
		{
			i_number_line_now++;
			if (!(i_number_line_now == nomer_str))
			{
				line_file_text.insert(line_file_text.size(), line);
				line_file_text.insert(line_file_text.size(), "\r\n");
			}
		}
		file_zin.close();
		ofstream file_zout;
		file_zout.open(FILE_OF_ACCOUNTS, std::ios::trunc | std::ios::binary);
		file_zout.write(line_file_text.c_str(), line_file_text.size());
		file_zout.clear();
		file_zout.close();
	}
	system("pause");
	change_user();
	delete[]login_check;
	delete[]login;

}
void changePassword() {
	ifstream file_zin;
	file_zin.open(FILE_OF_ACCOUNTS);
	if (!file_zin) {
		cout << "������, ���������� ������� ����: " << FILE_OF_ACCOUNTS << endl;
	}
	char* login_check = new char[256];
	int checker = 0;
	int proverka = 0;
	int nomer_str = 0;
	int vec_check = 0;
	vector<string>changer;
	while (!file_zin.eof()) {
		file_zin >> login_check;
		if (strcmp(main_loogin, login_check) == 0) {
			proverka = 1;
			nomer_str++;
			while (vec_check <= 2) {
				changer.push_back(login_check);
				file_zin >> login_check;
				vec_check++;
			}
			break;
		}
		else {
			checker++;
		}
		if (checker % 3 == 0) {
			checker = 0;
			nomer_str++;
		}
	}
	if (proverka != 1) {
		cout << "����� �� ������..." << endl;
	}
	file_zin.seekg(0, ios::beg);
	int i_number_line_now = 0;
	string line;
	string line_file_text;

	while (getline(file_zin, line)) {
		i_number_line_now++;
		if (!(i_number_line_now == nomer_str)) {
			line_file_text.insert(line_file_text.size(), line);
			line_file_text.insert(line_file_text.size(), "\r\n");
		}
	}
	file_zin.close();
	ofstream fzz;
	fzz.open(FILE_OF_ACCOUNTS, ios::trunc | ios::binary);
	fzz.write(line_file_text.c_str(), line_file_text.size());
	fzz.clear();
	fzz.close();
	Accounts* mas_of_acc = new Accounts[1];
	cout << nomer_str;
	cout << "������� ����� ������:" << endl;
	mas_of_acc[0].login = changer[0];
	mas_of_acc[0].password = SetPassword();
	mas_of_acc[0].role = changer[2];
	writeEndFileAccounts(mas_of_acc[0]);
}
void buyPass() {
	ifstream file;
	file.open(FILE_OF_TICKETS);
	if (!file) {
		cout << "������, ���������� ������� ����: " << FILE_OF_TICKETS<< endl;
	}
	prov_bal();
	cout << "\t\t������� ����� ����� ��� �������:" << endl;
	char* nomer_of_route = new char[256];
	cin >> nomer_of_route;
	char* train_check = new char[256];
	int checker = 0;
	int proverka = 0;
	int nomer_str = 0;
	int vec_check = 0;
	vector<string>pass;
	while (!file.eof()) {
		file >> train_check;
		if (strcmp(nomer_of_route, train_check) == 0) {
			proverka = 1;
			nomer_str++;
			while (vec_check <= 6) {
				pass.push_back(train_check);
				file >> train_check;
				vec_check++;
			}
			break;
		}
		else {
			checker++;
		}
		if (checker % 7 == 0) {
			checker = 0;
			nomer_str++;
		}
	}
	if (proverka != 1) {
		cout << "���� �� ������..." << endl;
		cout << "��������� �������..." << endl;
		pass.clear();
		user();
	}
	TextTable tz('-', '|', '+');
	tz.add("����� �����");
	tz.add("����� �����������");
	tz.add("����� ��������");
	tz.add("����� �����������");
	tz.add("����� ��������");
	tz.add("� �������");
	tz.add("����,$");
	tz.endOfRow();
	tz.add(pass[0]);
	tz.add(pass[1]);
	tz.add(pass[2]);
	tz.add(pass[3]);
	tz.add(pass[4]);
	tz.add(pass[5]);
	tz.add(pass[6]);
	tz.endOfRow();
	cout << tz;
	cout << "\t\t������� ������� �� ������ ������?" << endl;
	int number_of_tickets;
	cin >> number_of_tickets;
	if (atoi(pass[5].c_str()) >= number_of_tickets) {
		string new_numbers = to_string(number_of_tickets);
		int price = atoi(pass[6].c_str()) * number_of_tickets;
		int new_chislo_tickets = atoi(pass[5].c_str()) - number_of_tickets;
		cout << "� ������ ~ " << price << "-$" << endl;
		if (atoi(main_balance) >= price) {
			cout << "\t\t������� ������ �������!" << endl;
			file.seekg(0, ios::beg);
			int i_number_line_now = 0;
			string line;
			string line_file_text;

			while (getline(file, line)) {
				i_number_line_now++;
				if (!(i_number_line_now == nomer_str)) {
					line_file_text.insert(line_file_text.size(), line);
					line_file_text.insert(line_file_text.size(), "\r\n");
				}
			}
			file.close();
			ofstream fzz;
			fzz.open(FILE_OF_TICKETS, ios::trunc | ios::binary);
			fzz.write(line_file_text.c_str(), line_file_text.size());
			fzz.clear();
			fzz.close();
			string new_chislo = to_string(new_chislo_tickets);
			string new_price = to_string(price);
			
			Tickets* mas_of_ticket = new Tickets[1];
			mas_of_ticket[0].Number_of_route = pass[0];
			mas_of_ticket[0].DeparturePlace = pass[1];
			mas_of_ticket[0].ArrivalPlace = pass[2];
			mas_of_ticket[0].DepDate = pass[3];
			mas_of_ticket[0].ArrDate = pass[4];
			mas_of_ticket[0].Num_of_ticket = new_chislo;
			mas_of_ticket[0].price = pass[6];
			writeEndFileTickets(mas_of_ticket[0]);
			TextTable tzz('-', '|', '+');
			tzz.add("����� �����");
			tzz.add(pass[0]);
			tzz.endOfRow();
			tzz.add("����� �����������");
			tzz.add(pass[1]);
			tzz.endOfRow();
			tzz.add("����� ��������");
			tzz.add(pass[2]);
			tzz.endOfRow();
			tzz.add("����� �����������");
			tzz.add(pass[3]);
			tzz.endOfRow();
			tzz.add("����� ��������");
			tzz.add(pass[4]);
			tzz.endOfRow();
			tzz.add("������� �������");
			tzz.add(new_numbers);
			tzz.endOfRow();
			tzz.add("����,$");
			tzz.add(new_price);
			tzz.endOfRow();
			ofstream otchet(FILE_OF_OCHET, ios::app);
			otchet << tzz;
			otchet.close();
			cout << tzz;
			int newbalance=0;
			newbalance = (atoi(main_balance) - stoi(new_price));
			strcpy(main_balance,(to_string(newbalance)).c_str());
			chan_bal();
		}
		else {
			cout << "�� ����� �����,������������ �������,��������� ������" << endl;
		}
	}
	else {
		cout << "������ ���������� ������� ���,���� ������ �����������." << endl;
	}

}
void otchet() {
	system("Otchet.txt");
}
void writeEndFileCard(PayMethod mas_card)
{
	ofstream fout(FILE_OF_BALANCE, ios::app);
	fout << mas_card.p_login << " " << mas_card.Number_card << " " << mas_card.name << " " << mas_card.Surname << " " << mas_card.data_card << " " << mas_card.balance << " " << mas_card.CCV;
	fout << endl;
	fout.close();
}
bool checkLuhn(std::string input) { int len = input.length(); int number = 0; int sum = 0; for (int i = len; i > 0; i--) { number = input[i] - '0'; if (i % 2 == 0) { number *= 2; if (number > 9) { number -= 9; } } sum += number; } if (sum % 10 == 0) { return false; } else { return true; } }
void addCard() {
	system("cls");
	ifstream fin(FILE_OF_BALANCE, ios::in);
	char* login_check = new char[256];
	int checker = 0;
	int proverka = 0;
	int nomer_str = 0;
	while (!fin.eof()) {
		fin >> login_check;
		if (strcmp(main_loogin, login_check) == 0) {
			proverka = 1;
			nomer_str++;
			break;
		}
		else {
			checker++;
		}
		if (checker % 7 == 0) {
			checker = 0;
			nomer_str++;
		}
	}
	if (proverka != 1) {
		PayMethod* mas_of_card = new PayMethod[1];
		mas_of_card[0].p_login = main_loogin;
		cout << "\t������� ������ � ��������('1111 1111 1111 1111')" << endl;
		string card;
		cin >> card;
		if (strlen(card.c_str()) == 16) {
			if (checkLuhn(card) == true) {
				mas_of_card[0].Number_card = card;
				cout << "\t������� ��� ��������� �����" << endl;
				cin >> mas_of_card[0].name;
				cout << "\t������� ������� ��������� �����" << endl;
				cin >> mas_of_card[0].Surname;
				cout << "\t������� ���� �������� �����" << endl;
				cin >> mas_of_card[0].data_card;
				string Balance;
				Balance = "43543";
				mas_of_card[0].balance = Balance;
				cout << "\t������� CCV" << endl;
				cin >> mas_of_card[0].CCV;
				writeEndFileCard(mas_of_card[0]);
				delete[]mas_of_card;
				balance();
			}
			else {
				cout << "�������� �������  �������.��������� �������" << endl;
				system("pause");
				delete[]mas_of_card;
				balance();
			}
		}
		else {
			cout << "�������� �������  �������.��������� �������" << endl;
			system("pause");
			delete[]mas_of_card;
			balance();
		}
	}
	else {
		cout << "� ��� ��� ���� ����������� ��������." << endl;
		system("pause");
		balance();
	}
}
void money() {
	ifstream fin(FILE_OF_BALANCE, ios::in);
	fin.seekg(0, ios::beg);
	char* login_check = new char[256];
	char* balance_check = new char[256];
	int checker = 0;
	int proverka = 0;
	int nomer_str = 0;
	while (!fin.eof()) {
		fin >> login_check;
		if (strcmp(main_loogin, login_check) == 0) {
			proverka = 1;
			nomer_str++;
			break;
		}
		else {
			checker++;
		}
		if (checker % 7 == 0) {
			checker = 0;
			nomer_str++;
		}
	}
	if (proverka != 1) {
		cout << "\t����������.��������� ��������,����� ������ ������ �����" << endl;
		system("pause");
		fin.close();
		delete[]login_check;
		delete[]balance_check;
		balance();
	}
	else {
		cout << "\t��� ������:" << main_balance << "$" << endl;
		system("pause");
		fin.close();
		delete[]login_check;
		delete[]balance_check;
		balance();

	}
}
void balance() {
	PayMethod* mas_of_ticket = new PayMethod[1];
	menu::card();
	switch (checkInterval(1, 3)) {
	case 1: {
		addCard();
		break;
	}
	case 2: {
		system("cls");
		money();
		break;
	}
	case 3: {
		system("cls");
		user();
		break;
	}
	}
}
void prov_bal(){
ifstream fin(FILE_OF_BALANCE, ios::in);
fin.seekg(0, ios::beg);
char* login_check = new char[256];
char* balance_check = new char[256];
int checker = 0;
int proverka = 0;
int nomer_str = 0;
while (!fin.eof()) {
	fin >> login_check;
	if (strcmp(main_loogin, login_check) == 0) {
		proverka = 1;
		nomer_str++;
		break;
	}
	else {
		checker++;
	}
	if (checker % 7 == 0) {
		checker = 0;
		nomer_str++;
	}
}
if (proverka != 1) {
	cout << "\t����������.��������� ��������,����� ��������� ������" << endl;
	system("pause");
	fin.close();
	delete[]login_check;
	delete[]balance_check;
	balance();
}
else {
	fin >> balance_check;
	fin >> balance_check;
	fin >> balance_check;
	fin >> balance_check;
	fin >> balance_check;
	strcpy(main_balance, balance_check);
	fin.close();
	delete[]login_check;
	delete[]balance_check;
	return;
}}
void chan_bal() {
	vector<string>pay;
	ifstream fin(FILE_OF_BALANCE, ios::in);
	fin.seekg(0, ios::beg);
	char* login_check = new char[256];
	char* balance_check = new char[256];
	int checker = 0;
	int proverka = 0;
	int nomer_str = 0;
	int count = 0;
	while (!fin.eof()) {
		fin >> login_check;
		if (strcmp(main_loogin, login_check) == 0) {
			proverka = 1;
			nomer_str++;
			while (count <= 6) {
				pay.push_back(login_check);
				fin >> login_check;
				count++;
			}
			break;
		}
		else {
			checker++;
		}
		if (checker % 7 == 0) {
			checker = 0;
			nomer_str++;
		}
	}
	if (proverka != 1) {
		cout << "\t����������.��������� ��������,����� ������ ������ �����" << endl;
		system("pause");
		fin.close();
		delete[]login_check;
		delete[]balance_check;
		balance();
	}
	else {
		fin.close();
		delete[]login_check;
		delete[]balance_check;
		ifstream filez;
		filez.open(FILE_OF_BALANCE);
		filez.seekg(0, ios::beg);
		int i_number_line_now = 0;
		string line;
		string line_file_text;
		while (getline(filez, line)) {
			i_number_line_now++;
			if (!(i_number_line_now == nomer_str)) {
				line_file_text.insert(line_file_text.size(), line);
				line_file_text.insert(line_file_text.size(), "\r\n");
			}
		}
		filez.close();
		ofstream fzzz;
		fzzz.open(FILE_OF_BALANCE, ios::trunc | ios::binary);
		fzzz.write(line_file_text.c_str(), line_file_text.size());
		fzzz.clear();
		fzzz.close();
		PayMethod* mas_of_balance = new PayMethod[1];
		mas_of_balance[0].p_login = pay[0];
		mas_of_balance[0].Number_card = pay[1];
		mas_of_balance[0].name = pay[2];
		mas_of_balance[0].Surname = pay[3];
		mas_of_balance[0].data_card = pay[4];
		mas_of_balance[0].balance = main_balance;
		mas_of_balance[0].CCV = pay[6];
		writeEndFileCard(mas_of_balance[0]);
		delete[] mas_of_balance;
		pay.clear();
	}
}