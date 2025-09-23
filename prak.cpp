#include <iostream>
#include <cstdlib>
using namespace std;

int main(){
    string username, password, nama;
    string user = "admin";
    string pass = "1234567";
    char opt;
    char grade;
    
    cout << "====Sistem Akademik SmartEdu===="<<endl;
    cout << "Input Username: ";cin>>username;
    cout << "Input Password: ";cin>>password;
    if(username == user && password == pass){
		cout << "Login Status 200"<<endl;
		system("clear");
		}
	else{
		cout << "login failed"<<endl;
		return 0;
		}
	cout << "===SmartEdu Menu===";
	cout << "1.Check Attendance Status";
	cout << "2.Check Student Peformance";
	cout << "0.exit";
	cout << "chose an option";
	cin >> opt;
	switch(opt){
		case '1':
		int attend;
		cout << "Input Nama: ";getline(cin, nama);
		cout << "Input Attendance (0-30): ";
		cin >> attend;
		if(attend >= 25 || attend <= 30){
			cout << "Kehadiran luar biasa";
			}
		else if(attend >= 20 || attend <= 24 ){
			cout << "Kehadiran Baik";
			}
		else if(attend >= 15 || attend <= 29){
			cout << "Kehadiran Rata Rata";
			}
		else if(attend == 0 || attend <= 14){
			cout<< "Kehadiran buruk";
			}
		case '2': 
		int nilai;
		cout << "Input Attendance (0-30): ";
		cin >> attend;
		cout << "Maneh boga Voucher teu? (y/n) ";cin >> 
		if(nila >= 85 || nilai <= 100){
			grade = A;
			}
		else if(nilai >= 70 || nilai <= 84 ){
			grade = B;
			}
		else if(nilai >= 55 || nilai <= 69){
			grade = c;
			}
		else if(nilai >= 40 || nilai <= 54){
			grade = D;
			}
		else if(nilai == 0 || nilai <= 30){
			grade = E;
			}
		}
}
