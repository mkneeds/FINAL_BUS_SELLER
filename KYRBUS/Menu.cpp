#include "Menu.h"
using namespace std;
void menu::authorization()
{
	cout << "\t������� ���������� �������" << endl;
	cout << "\t\t���� �����������" << endl;
	cout << "\t(1) ~ ����� ��� ������������ ���������" << endl;
	cout << "\t(2) ~ �����������" << endl;
	cout << "\t(3) ~ ����� �� ���������" << endl;
	cout << "��� �����: ";
}
void menu::admin() {
	cout << "\t\t������� ����(ADMIN)" << endl;
	cout << "\t(1) ~ �������� ������" << endl;
	cout << "\t(2) ~ ������������� ������" << endl;
	cout << "\t(3) ~ �������� ������ � ��������� ����" << endl;
	cout << "\t(4) ~ ������� ������" << endl;
	cout << "\t(5) ~ C��������� �� ������ �����" << endl;
	cout << "\t(6) ~ ���������� ��������������" << endl;
	cout << "\t(7) ~ �������� ������" << endl;
	cout << "\t(8) ~ �����" << endl;
	cout << "��� �����: ";
}
void menu::vibor_menu() {
	cout << "\t\t����� ����" << endl;
	cout << "\t� ��� ���� ���� ��������������,�������� ���������� ����" << endl;
	cout << "\t(1) ~ ADMIN-MENU" << endl;
	cout << "\t(2) ~ USER-MENU" << endl;
	cout << "\t(3) ~ ��������� � �����������" << endl;
	cout << "\t(4) ~ �����" << endl;
	cout << "��� �����: ";
}
void menu::user() {
	cout << "\t\t������� ����(USER)" << endl;
	cout << "\t(1) ~ �������� ���������� � ��������� ����" << endl;
	cout << "\t(2) ~ ������ ������" << endl;
	cout << "\t(3) ~ ������������ �����" << endl;
	cout << "\t(4) ~ �������� ������" << endl;
	cout << "\t(5) ~ ������" << endl;
	cout << "��� �����: ";
}
void menu::change_tickets() {
	cout << "\t\t��� �� ������ ��������?" << endl;
	cout << "\t(1) ~ ��������� ������ ������" << endl;
	cout << "\t(2) ~ ����� �����" << endl;
	cout << "\t(3) ~ ����� �����������" << endl;
	cout << "\t(4) ~ ����� ��������" << endl;
	cout << "\t(5) ~ ����� �����������" << endl;
	cout << "\t(6) ~ ����� ��������" << endl;
	cout << "\t(7) ~ ����� �������" << endl;
	cout << "\t(8) ~ ���� ������" << endl;
	cout << "\t(9) ~ ����� � ����" << endl;
	cout << "��� �����: ";
}
void menu::controlUsers()
{
	cout << "���� ���������� ��������������" << endl;
	cout << "(1) ~ �������� ��������������" << endl;
	cout << "(2) ~ �������� ������������" << endl;
	cout << "(3) ~ ������� ������������" << endl;
	cout << "(4) ~ �����" << endl;
	cout << "��� �����: ";
}
void menu::pasx() {
	cout << R"(                                                                                                    
                                                                                                                    
            .;;;, .;;;,                   .;;;, .;;;,
        .;;;,;;;;;,;;;;;,.;;;,       .;;;.,;;;;;,;;;;;,;;;.
       ;;;;xXXxXXxXXxXXxXXx;;;. .,. .;;;xXXxXXxXXxXXxXX;;;;;
   .,,.`xXX'             `xXXx,;;;;;,xXXx'            `XXx;;,,.
  ;;;;xXX'                  `xXXx;xXXx'                 `XXx;;;;
  `;;XX'                       `XXX'                      `XX;;'
 ,;;,XX                         `X'                        XX,;;,
 ;;;;XX,                                                  ,XX;;;;
  ``.;XX,                                                ,XX;,''
    ;;;;XX,                                            ,XX;;;;
     ```.;XX,                                        ,XX;,'''
        ;;;;XX,                                    ,XX;;;;
         ```,;XX,                                ,XX;,'''
             ;;;;XX,                          ,XX;;;;
              ````,;XX,                    ,XX;, '''
                  ;;;;;XX,              ,XX;;;;
                   `````,;XX,        ,XX;,''''  
                        ;;;;;XX,  ,XX;;;;;
                         `````;;XX;;'''''
                              `;;;;'                    ?????  ???    ?? ??    ??  ?????      
                                                       ??   ?? ????   ??  ??  ??  ??   ??     
                                                       ??????? ?? ??  ??   ????   ???????     
                                                       ??   ?? ??  ?? ??    ??    ??   ??     
                                                       ??   ?? ??   ????    ??    ??   ??     
                                                                                      
)";
}
void menu::pasxx() {
	cout << R"(
 .----------------.  .----------------.  .----------------.  .----------------. 
| .--------------. || .--------------. || .--------------. || .--------------. |
| |  ___  ____   | || |     _____    | || |  _______     | || |      __      | |
| | |_  ||_  _|  | || |    |_   _|   | || | |_   __ \    | || |     /  \     | |
| |   | |_/ /    | || |      | |     | || |   | |__) |   | || |    / /\ \    | |
| |   |  __'.    | || |      | |     | || |   |  __ /    | || |   / ____ \   | |
| |  _| |  \ \_  | || |     _| |_    | || |  _| |  \ \_  | || | _/ /    \ \_ | |
| | |____||____| | || |    |_____|   | || | |____| |___| | || ||____|  |____|| |
| |              | || |              | || |              | || |              | |
| '--------------' || '--------------' || '--------------' || '--------------' |
 '----------------'  '----------------'  '----------------'  '----------------' 
)" << endl;
	cout << R"(
		
 __   __  ___   ___   ___   ___    ___    _  _     _        __  
 \ \ / / | __| | _ \ / __| |_ _|  / _ \  | \| |   / |      /  \ 
  \ V /  | _|  |   / \__ \  | |  | (_) | | .` |   | |  _  | () |
   \_/   |___| |_|_\ |___/ |___|  \___/  |_|\_|   |_| (_)  \__/ 
                                                                
		)";
}
void menu::card() {
	cout << "\t\t~������" << endl;
	cout << "\t(1) ~ �������� ��������." << endl;
	cout << "\t(2) ~ ������ ������ �������." << endl;
	cout << "\t(3) ~ �����" << endl;
	cout << "��� �����: ";
}