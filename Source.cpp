#include <iostream>
#include <string.h>
#include <ostream>
#include"string"
using namespace std;
const int sizearray = 100;
struct spisokCloth {
	string tupeVClothes;
	string sex;
	float costClothes;
};

class Clothes {
public:
	Clothes() {};
	Clothes(string Sex, int Condition) {
		this->Sex = Sex;
		this->condition = Condition;


	}

	virtual string GetSex() {
		return Sex;
	}
	virtual int GetCondition() {
		return condition;
	}
	virtual string GetType() {
		return type;
	}

private:
	int cost;
	string Sex;
	int condition;
	string type;


};

class Tshort : public Clothes {
public:

	Tshort(string Sex, int Condition) {
		this->Sex = Sex;
		this->condition = Condition;


	}

	string GetSex() override {
		return Sex;
	}
	int GetCondition() override {
		return condition;
	}

	string GetType() {
		return type;
	}
private:
	int cost;
	string Sex;
	int condition;
	string type = "Tshirt";

};

class Shooes : public Clothes {
public:

	Shooes(string Sex, int Condition) {
		this->Sex = Sex;
		this->condition = Condition;


	}

	string GetSex()override {
		return Sex;
	}
	int GetCondition()override {
		return condition;
	}
	string GetType() {
		return type;
	}
private:
	int cost;
	string Sex;
	int condition;
	string type = "Shooes";
};

class Pants : public Clothes {
public:

	Pants(string Sex, int Condition) {
		this->Sex = Sex;
		this->condition = Condition;


	}

	string GetSex()override {
		return Sex;
	}
	int GetCondition()override {
		return condition;
	}
	string GetType() {
		return type;
	}
private:
	int cost;
	string Sex;
	int condition;
	string type = "Pants";
};

class Bank {
public:
	Bank() {
		this->countMoney = 10000;
	}
	bool GiveMoney(float cost) {
		if (checkMoney(cost)) countMoney -= cost; else return false;

		return true;
	}

	void TakeMoney(float m) {
		countMoney += m;
	}

	float showMoney() {
		return countMoney;
	}

private:
	float countMoney;
	bool checkMoney(float cost) {
		if (countMoney < cost) return false; else return true;
	}
};


class SecondHand {
public:

	int  TakeClothes(Clothes *clothes) {
		float costClothes = 0;

		if (clothes->GetSex() == "Male")
			costClothes = 20;
		else if (clothes->GetSex() == "FeMale")
			costClothes = 40;

		costClothes += clothes->GetCondition() * 10;


		if (checkCkothes(clothes) && bank.GiveMoney(costClothes)) {
			arrayClothes[head + 1].costClothes = costClothes;
			arrayClothes[head + 1].tupeVClothes = clothes->GetType();
			arrayClothes[head + 1].sex = clothes->GetSex();
			head++;
			return 1;

		}
		return -1;
	};

	void SellClothes(string type, string sex) {
		string sp = SearchClothes(type, sex);
		int chouse;
		for (int i = 0; i < sp.size(); i++) {
			cout << sp[i];
		}
		if (sp != "") {
			char ch;
			cout << "Вы хоите что то купить? Д/Н" << endl;
			cin >> ch;
			if (ch == 'Y' || ch == 'y') {
				cout << "Выберите товар: " << endl;
				cin >> chouse;
				delClothes(chouse);
				cout << "Благодарим за покупку)))\n";
			}else cout << "досвидания\n";
		}

	}
	void showMoney() {
		cout << "дeнег в кассе " << bank.showMoney() << endl;
	}
	void showCloths() {

		for (int i = 0; i < head+1; i++) {
			cout << arrayClothes[i].tupeVClothes << endl;
		}
	}
private:
	spisokCloth arrayClothes[sizearray];
	int head = -1;
	bool checkCkothes(Clothes *clothes) {
		if (clothes->GetCondition() < 5)return false; else return true;
	}

	void delClothes(int num) {
		arrayClothes[num].costClothes = 0;
		arrayClothes[num].tupeVClothes = "";
		if (num == head)return;
		if (num == head && num==0)return;
		
		for (int i = num; i < head; i++) {
			arrayClothes[i].costClothes = arrayClothes[i + 1].costClothes;
			arrayClothes[i].tupeVClothes = arrayClothes[i+1].tupeVClothes;
		}
		arrayClothes[head].tupeVClothes = "";
		arrayClothes[head].costClothes = 0;
		head--;

		
	}
	string SearchClothes(string type, string sex) {
		string sp;
		int j = 1;
		for (int i = 0; i < head + 1; i++) {
			if (arrayClothes[i].tupeVClothes == type&& arrayClothes[i].sex==sex) {

				sp += "Товар под номером " + std::to_string(i) + " Тип: " + type + " цена: ";
				sp += std::to_string(arrayClothes[i].costClothes);
				sp += "\n";
				j++;
			}
		}
		if (sp == "") sp = "товар не найден";
		return sp;
	}
	Bank bank;
};






int main() {
	setlocale(LC_ALL, "rus");
	Pants p("FeMale", 6);
	Pants p1("Male", 8);
	Shooes sh("Male", 7);
	SecondHand SH;


	SH.TakeClothes(&p);
	SH.TakeClothes(&p1);
	SH.TakeClothes(&sh);

	SH.showCloths();

	cout << endl;
	SH.SellClothes("Pants", "Male");

	cout << endl;
	SH.showCloths();
	system("pause");
	return 0;
}