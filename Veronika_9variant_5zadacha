#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class net_user {
private:
	string name;    //фамилия
	string strt;    //улица
	int house;      //дом
	int aprt;       //квартира
	int phone_num;  //телефон
public:
	net_user(){};
	~net_user(){};
	void get_info();
	void set_info();
	friend ostream& operator<<(ostream& os, const net_user& dt);
	friend istream& operator>>(istream& is, net_user& dt);

};
ostream& operator<<(ostream& os, const net_user& dt) {
	os << dt.name << '\n' << dt.strt << '\n' << dt.house << '\n';
	os << dt.aprt << '\n' << dt.phone_num << '\n';
	return os;
}

istream& operator >> (istream& is, net_user& dt) {
	is >> dt.name >> dt.strt >> dt.house >> dt.aprt >> dt.phone_num;
	return is;
}
void net_user::get_info() {
	ifstream fin("file.txt");
	if (!fin.is_open())
		cout << "Файл не может быть открыт!\n";
	else
		fin >> name >> strt >> house >> aprt >> phone_num;
	fin.close();
}

void net_user::set_info() {
	ofstream fout("result_file.txt", ios_base::trunc);
	fout << "Информация о пользователе:\n" << "Фамилия: " << name << '\n' << "Улица: " << '\n' << strt << '\n';
	fout << "Дом: " << house << '\n' << "Квартира: " << aprt << '\n' << "Телефонный номер: " << phone_num << '\n';
	fout.close();
}

int main()
{
	setlocale(LC_ALL, "");
	net_user Sergey;
	Sergey.get_info();
	Sergey.set_info();
	system("pause");
    return 0;
}
