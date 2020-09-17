#ifndef CIRCLE_H
#define CIRCLE_H
#include<iostream>
#include<string>
#include<list>
#include<algorithm>
#include<functional>
#include<numeric>
#include<time.h>
#include<fstream>
using namespace std;
class Animal                                                                 //�ò��ֿ��Գ���Ϊ��԰��ͬ�ľ���
{
public:
	string Name;
	int Life;
	int Size;
	int Value;
public:
	Animal(){}
	virtual void display();     //��ʾ������Ļ�����Ϣ
	virtual int get_money();
};
int Animal::get_money(){ return 1; }
void Animal::display(){}
class Amphibian :public Animal    //������
{
public:
	string Name;
	string Life;
	string Size;
	int Value;
	string Characteristic;//�����ද����������Ϊ��½����
public:
	virtual void display();
	Amphibian(string name, string life, string size, int value, string Characteristic = "��½����");
	virtual int get_money();
	
};
int Amphibian::get_money(){ return Value; }
void Amphibian::display()
{
	cout << Name << " " << Life << " " << " " << Size << " " << Characteristic << endl;
};
Amphibian::Amphibian(string name, string life, string size, int value, string Characteristic) :Animal()
{
	Name = name;
	Life = life;
	Value = value;
	Size = size;
}
class Fish :public Animal
{
public:
	string Name;
	string Life;
	string Size;
	int Value;
	string Characteristic;    //�����ද����������Ϊ��½����
public:
	virtual void display();
	Fish(string name, string life, string size, int value, string Characteristic = "��������");
	virtual int get_money();
};
int Fish::get_money(){ return Value; }
Fish::Fish(string name, string life, string size, int value, string Characteristic)
{
	Name = name;
	Life = life;
	Value = value;
	Size = size;
}
void Fish::display()
{
	cout << Name << " " << Life << " " << " " << Size << " " << Characteristic << endl;
};
class Bird :public Animal   //���ද��
{
public:
	string Name;
	string Life;
	string Size;
	int Value;
	string Characteristic; //��������
	virtual int get_money();
	virtual void display();
	Bird(string name, string life, string size, int value, string Characteristic = "Fly and Oviparity");
};
int Bird::get_money(){ return Value; }
Bird::Bird(string name, string life, string size, int value, string Characteristic)
{
	Name = name;
	Life = life;
	Size = size;
	Value = value;

}
void Bird::display()
{
	cout << Name << " " << Life << " " << " " << Size << " " << Characteristic << endl;
};
class Reptiles :public Animal     //�����ද��
{
public:
	string Name;
	string Life;
	string Size;
	int Value;
	string Characteristic; //��������
	virtual void display();
	virtual int get_money();
	Reptiles(string name, string life, string size, int value, string Characteristic = "Crawl");
};
int Reptiles::get_money(){ return Value; }
Reptiles::Reptiles(string name, string life, string size, int value, string Characteristic)
{
	Name = name;
	Life = life;
	Size = size;
	Value = value;
}
void Reptiles::display()
{
	cout << Name << " " << Life << " " << " " << Size << " " << Characteristic << endl;
};
class Mammal //���鶯��
{
public:
	string Name;
	string Life;
	string Size;
	int Value;
	string Characteristic; //̥������
	virtual void display();
	virtual int get_money();
	Mammal(string name, string life, string size, int value, string Characteristic = "Viviparous");
};
int Mammal::get_money(){ return Value; }
Mammal::Mammal(string name, string life, string size, int value, string Characteristic)
{
	Name = name;
	Life = life;
	Size = size;
	Value = value;
}
void Mammal::display()
{
	cout << Name << " " << Life << " " << " " << Size << " " << Characteristic << endl;
};

class Zoo_keeper;
class Shopkeeper
{
public:
	string Name;
	string Life;
	int Rent;    //ÿ��Ҫ�������
	string Reputation; //���ǵ������̶�
	int Food_price;  //����ʳ��۸�
	string Position;
	int Get_money;
	static int person;
public:
	void Dismiss(string name);
	friend class Zoo_keeper;

public:
	Shopkeeper(string name, string life = " ", int food_price = 0, string position = " ", int get_money = 0, int rent = 10000, string reputation = "����");
	void marry();    //����״��
	void show();     //��ʾ������Ϣ
};
int Shopkeeper::person = 1;
Shopkeeper::Shopkeeper(string name, string life, int food_price, string position, int get_money, int rent, string reputation)
{
	Name = name;
	Life = life;
	Food_price = food_price;
	Position = position;
	Rent = rent;
	Reputation = reputation;
	Get_money = get_money;
}
void Shopkeeper::Dismiss(string name)
{

	if (name == this->Name){
		cout << "���������Ϣ��" << endl;
		Name = " ";
		Life = " ";
		Rent =0;
		Position = " ";
		Reputation = " ";
		Get_money = 0;
		Food_price = 0;
	}
	Shopkeeper::person--;
}

void Shopkeeper::show()                                                              //�ò��ֿ��Գ���Ϊ��԰���ο���Ϣ�����ѵĳ���
{
	cout << "    ������" << Name << "    ����:" << Life << "    ���" << Rent << endl;
	cout << "    ְҵ:" << Position << "    н�꣺" << Get_money << "    ������" << Reputation << endl;
	cout << "��ʾ��ǰ�ĵ���������" << Shopkeeper::person << endl;
}
class Zoo_keeper                                                                               //�ò��ֳ���Ϊ��԰�Ĺ���㣬������һЩ����ܲ�
{
public:
	string Name;
	int Life;
	static int Property;
	string Position;
	static int syz_money;
	static int hgm_money;
	static int save_money;
	int m;
	int n;
public:
	Zoo_keeper(string name, int life, int property = 0);

	void get_Money();
	void Show(int m, int n);   //��ʾ������Ϣ
	void Show(int m);
	void Dismiss(Shopkeeper &SHOP);  //���Ա��
	void Employ(Shopkeeper &SHOP);    //Ƹ��Ա��
	void Profit();    //���ڼ����乫԰����  ������ȥнˮ  ��ȥ����ĳɱ�
	void Query();     //���ڲ�ѯ����Ļ�����Ϣ
	void Transfer();   //����ת�ƶ���
	void Buy_Animal();    //��������  ��������ĳɱ�
	void left_money();
};
int Zoo_keeper::syz_money = 0;
int Zoo_keeper::hgm_money = 0;
int Zoo_keeper::Property = 0;             //ԭ���ʲ�
int Zoo_keeper::save_money = Zoo_keeper::Property;        //�м����
Zoo_keeper::Zoo_keeper(string name, int life, int property)
{

	Name = name;
	Life = life;
	Property = property;

}
void Zoo_keeper::get_Money()
{
	if (Zoo_keeper::save_money == 0)
	{

		cout << "                                               ˾԰��ԭ���ʲ�:" << Zoo_keeper::Property / 2 << "Ԫ" << endl;
		cout << "                                               ��԰��ԭ���ʲ�:" << Zoo_keeper::Property / 2 << "Ԫ" << endl;
	}
	else
		return;

}
void Zoo_keeper::left_money()
{
	cout << "                                               ˾԰��ԭ���ʲ�:" << Zoo_keeper::syz_money << "Ԫ" << endl;
	cout << "                                                   ��԰��ԭ���ʲ�:" << Zoo_keeper::hgm_money << "Ԫ" << endl;
}
void Zoo_keeper::Show(int m)
{
	if (Zoo_keeper::save_money != 0)
		cout << "                                               ������" << Name << "  ����:" << Life << "  �ʲ�:" << Zoo_keeper::syz_money << endl;
	else
		return;

}
void Zoo_keeper::Show(int n, int m)                      //�������غ������ֱ����˾԰���ͺ�԰������Ϣ
{
	if (Zoo_keeper::save_money != 0)
		cout << "                                               ������" << Name << "  ����:" << Life << "  �ʲ�:" << Zoo_keeper::hgm_money << endl;
	else
		return;
}

void Zoo_keeper::Employ(Shopkeeper &SHOP)
{
	cout << "��ǰԱ��������" << Shopkeeper::person << endl;
	cout << "�¹�Ӷ���˵�������" << SHOP.Name << "   �¹�Ӷ�˵����䣺" << SHOP.Life << endl;
	cout << " �¹�Ӷ�˵�ְλ��" << SHOP.Position << "  ÿ��Ҫ�������:" << SHOP.Rent << "  ��н��" << endl;
	Shopkeeper::person++;
}

void Zoo_keeper::Profit()
{
	int sum;
	srand((unsigned)time(NULL));
	int You = 0;
	int YouM = 0;
	int YouB = 0;
	You = (rand() % (200 - 100 + 1)) + 100;//����ÿ���׶���Ʊ�����ķ�ΧΪ��100,200��
	cout << "                                               �����׶�������Ϊ��" << You << endl;
	YouB = (rand() % (50 - 0 + 1)) + 0;//�����ƱƱ���׶������ڡ�0,50���ķ�Χ��
	YouM = (rand() % (25 - 0 + 1)) + 0;//������Ʊ���׶������ڡ�0,25���ķ�Χ��
	cout << "                                               ���а��Ʊ������Ϊ��" << YouB << endl;
	cout << "                                               ������Ʊ������Ϊ��" << YouM << endl;
	cout << "                                               ��ѧ��Ⱥ��ȡ�õ�����Ϊ��" << (You - YouB - YouM) * 500 + (YouB * 250) << endl;

	int Stu = 0;
	int StuB = 0;
	cout << endl;
	Stu = (rand() % (2000 - 1000 + 1)) + 100;//����ÿ��ѧ����Ʊ�����ķ�ΧΪ��1000,2000��
	cout << "                                               ����ѧ��������Ϊ��" << Stu << endl;
	StuB = (rand() % (850 - 1500 + 1)) + 1500;//�������Ʊ��ѧ�������ڡ�550,1000���ķ�Χ��
	cout << "                                               ���а���Ʊ������Ϊ��" << StuB << endl;
	cout << "                                               ���׶�Ⱥ��ȡ�õ�����Ϊ��" << (Stu - Stu) * 800 + (StuB * 640) << endl;

	int Adu = 0;
	cout << endl;
	Adu = (rand() % (3000 - 1500 + 1)) + 1500;//����ÿ�³��˹�Ʊ�����ķ�ΧΪ��1500,3000��
	cout << "                                               ���³��˵�����Ϊ��" << Adu << endl;
	cout << "                                               �ڳ���Ⱥ��ȡ�õ�����Ϊ��" << Adu * 1000 << endl;

	int Lov = 0;
	cout << endl;
	Lov = (rand() % (850 - 630 + 1)) + 630;//����ÿ�����¹�Ʊ�����ķ�ΧΪ��630,850��
	cout << "                                               �������µ�����Ϊ��" << Lov << endl;
	cout << "                                               ������Ⱥ��ȡ�õ�����Ϊ��" << Lov * 2500 << endl;

	int Eld = 0;
	cout << endl;
	Eld = (rand() % (2300 - 1200 + 1)) + 1200;//����ÿ�����¹�Ʊ�����ķ�ΧΪ��1200,2300��
	cout << "                                               ������������Ⱥ�������Ϊ��" << Eld << endl;

	cout << endl;
	sum = (You - YouB - YouM) * 500 + (YouB * 250) + (Stu - Stu) * 800 + (StuB * 640) + Adu * 1000 + Lov * 2500;
	cout << "                                               ��������Ϊ��" << sum << endl;

	int Dre = 0, profit = 0;
	Dre = (rand() % (160000 - 35000 + 1)) + 35000;//�����³�ά�޵ļ۸��ڡ�35000,160000��
	cout << "                                               ����µ�ά�޷���Ϊ��" << Dre << endl;
	cout << "                                               ����µľ�����Ϊ��" << sum - Dre << endl;
	profit = sum - Dre;
	Zoo_keeper::Property = profit;

}

class Tourist                                                                       //�ⲿ�ֿ��Գ���Ϊ��԰�ſڵ���Ʊ��
{
public:
	string Identity;
public:
	Tourist(string identity = " ");
	virtual void Need_Money();    //��ʾ��Ҫ������Ǯ
	virtual void information();     //������ʾ������Ϣ
};
Tourist::Tourist(string identity){
	Identity = identity;
	cout << "                                                           ��ӭ��λ�ο͹��٣�" << endl;
}
void Tourist::Need_Money()
{
	cout << "                                                           ����԰���ƣ���Ѷ�ͰͶ���԰" << endl;
	cout << "                                                               ****��Ʊ��֪****" << endl;
	cout << "                                               �׶�����Ʊ��500һ�ˣ���ߵ���120cm�İ��,����С��3�����Ʊ��" << endl;
	cout << "                                               ѧ������Ʊ��800һ�ˣ�����ѧ��֤���Դ�8�ۣ�           " << endl;
	cout << "                                               ��������Ʊ��1000һ��                                 " << endl;
	cout << "                                               ��������Ʊ��1800����                                 " << endl;
	cout << "                                               ����70�����������ˣ�ƾ���֤�����꿨�������۾��ˡ��м����ˡ�" << endl;
	cout << "                                               ���������ݸɲ�������ƾ��Ч֤����Ʊ�������м��ˡ���֢���ˡ�" << endl;
	cout << "                                               �Ÿ����󡢳ֱ�����Ч֤����Ʊ��" << endl;
	cout << "                                               ����԰ʱ�䣺5:00---21:00" << endl;
	cout << "                                               ˾԰��qq��247179876����԰��qq��923619812" << endl;
}
void Tourist::information()
{
}
class Infant :public Tourist
{
public:
	string Identity;
	string Name;
	int Life;
	int Price;
	int Hold_money;
	int Height;

public:
	Infant(string name, int life, string identity, int height, int hold_money = 100, int price = 500);
	virtual void Need_Money();    //��ʾ��Ӧ������Ҫ������Ǯ
	virtual void information();     //������ʾ������Ϣ

};

void Infant::Need_Money()
{
	if (Life < 3)
	{
		cout << "��Ʊ" << endl;
		Price = 0;
	}
	else if (Height < 120)
	{
		cout << "�����Ʊ��250Ԫ" << endl;
		Price /= 2;
	}
	else
	{
		cout << "ȫ����Ʊ��500Ԫ" << endl;
		Price = 500;
	}
}
void Infant::information()
{
	cout << "��ʾ�ο͵���Ϣ" << endl;
	cout << "������" << Identity << endl;
	cout << "������" << Name << endl;
	cout << "���䣺" << Life << "��" << endl;
	cout << "��ߣ�" << Height << "cm" << endl;
	cout << "��԰����������ȯ��" << Hold_money << "Ԫ" << endl;
}

Infant::Infant(string name, int life, string identity, int height, int hold_money, int price) :Tourist(identity)
{
	Name = name;
	Life = life;
	Identity = identity;
	Height = height;
	Hold_money = hold_money;
	Price = price;
}

class Student :public Tourist
{
public:
	const double Discount;      //const�������ɸı�
	string Identity;
	string Name;
	int Life;
	int Price;
	int Hold_money;
	string Stu_ID;               //�ж��Ƿ��ѧ��֤
public:
	Student(string name, int life, string identity, string stu_id, int Hold_money = 100, int Price = 800);
	virtual void information();
	virtual void Need_Money();    //��ʾ��Ҫ������Ǯ
};

Student::Student(string name, int life, string identity, string stu_id, int hold_money, int price) :Tourist(identity), Discount(0.8)
{
	Name = name;
	Life = life;
	Identity = identity;
	Stu_ID = stu_id;
	Hold_money = hold_money;
	Price = price;
}

void Student::information()
{
	cout << "��ʾ�ο͵���Ϣ" << endl;
	cout << "������" << Identity << endl;
	cout << "������" << Name << endl;
	cout << "���䣺" << Life << "��" << endl;
	cout << "��԰����������ȯ��" << Hold_money << "Ԫ" << endl;
}

void Student::Need_Money()
{
	if (Stu_ID == "����")
		cout << "��ѧ��֤����8�ۣ�640Ԫ" << endl;
	else
		cout << "��ѧ��֤��ȫ��:800Ԫ" << endl;
}

class Adult :public Tourist
{
public:
	string Identity;
	string Name;
	int Life;
	int Price;
	int Hold_money;
public:
	Adult(string name, int life, string identity, int hold_money = 100, int price = 1000);
	virtual void information();
	virtual void Need_Money();    //��ʾ��Ҫ������Ǯ
};
Adult::Adult(string name, int life, string identity, int hold_money, int price) :Tourist(identity)
{
	Name = name;
	Life = life;
	Identity = identity;
	Hold_money = hold_money;
	Price = price;
}

void Adult::Need_Money()
{
	cout << "ȫ����Ʊ��1000" << endl;
}
void Adult::information()
{
	cout << "��ʾ�ο͵���Ϣ" << endl;
	cout << "������" << Identity << endl;
	cout << "������" << Name << endl;
	cout << "���䣺" << Life << "��" << endl;
	cout << "��԰����������ȯ��" << Hold_money << "Ԫ" << endl;
}
class lovers :public Tourist
{
public:

	string Identity;
	string Name;
	int Life;
	int Price;
	int Hold_money;
public:
	lovers(string name, int life, string identity, int hold_money = 200, int price = 2500);
	virtual void information();
	virtual void Need_Money();    //��ʾ��Ҫ������Ǯ
};
lovers::lovers(string name, int life, string identity, int hold_money, int price) :Tourist(identity)
{
	Name = name;
	Life = life;
	Identity = identity;
	Hold_money = hold_money;
	Price = price;
}
void lovers::Need_Money()
{
	cout << "���¼۸�900Ԫÿ��" << endl;
}
void lovers::information()
{
	cout << "��ʾ�ο͵���Ϣ" << endl;
	cout << "������" << Identity << endl;
	cout << "��԰����������ȯ��" << Hold_money << endl;
}


class Menu{                                                    //�ܲ˵���
public:
	void Menu_animal_buy();
	void Menu_animal_show();
	void Menu_zookeeper();
	void Menu_shopkeeper();
	void Menu_tourist();
	void Menu_main();
	void Menu_buymenu();
	void ShopKeeper();
	void old_shopkeeper();
};
void Menu::ShopKeeper()
{
	cout << "                                       ***************************************************\n";
	cout << "                                       ***                                             ***\n";
	cout << "                                       ***                                             ***\n";
	cout << "                                       ***             ��ѡ������ʹ�õĹ��ܣ�          ***\n";
	cout << "                                       ***      1.��Ӷ�곤            2.�����곤       ***\n";
	cout << "                                       ***************************************************\n" << endl;


}
void Menu::Menu_main()
{
	cout << "                                       ***************************************************\n";
	cout << "                                       ***                                             ***\n";
	cout << "                                       ***                                             ***\n";
	cout << "                                       ***                                             ***\n";
	cout << "                                       ***            ��ӭ������Ѷ�ͰͶ���԰           ***\n";
	cout << "                                       ***             ��ѡ������ʹ�õĹ��ܣ�          ***\n";
	cout << "                                       ***      1.������            2.�鿴����       ***\n";
	cout << "                                       ***     3.��Ӷ�뿪��           4.��Ʊ��֪       ***\n";
	cout << "                                       ***               5.�鿴��������                ***\n";
	cout << "                                       ***               6.�����ı��ĵ�                ***\n";
	cout << "                                       ***               7.  �˳�ϵͳ                  ***\n";
	cout << "                                       ***************************************************\n" << endl;
	cout << "                                                   ��������ţ�";
}
void Menu::Menu_buymenu()
{
	cout << "                                 ������Ҫ����Ķ������ࣺ" << endl;
	cout << "                                 1.������    2.����    3.����" << endl;
	cout << "                                 4.������              5.������" << endl;
	cout << "                                 ��������ţ�";
}

list<Zoo_keeper> Zoo;     //�洢԰������Ϣ
list<Shopkeeper> stu;    //�洢��������Ϣ 
list<Shopkeeper>::iterator shop;
ofstream ofs_shopkeeper;
list<Shopkeeper>::iterator S;
list<Shopkeeper>::iterator find(list<Shopkeeper>::iterator a1, list<Shopkeeper>::iterator a2, Shopkeeper &stu1)          //�����㷨��find������ʹ֮�ܵ������������ݣ����������ǻ�����������
{
	for (; a1 != a2; a1++)
	if (a1->Name == stu1.Name)
		break;
	return a1;

}
void Menu::old_shopkeeper()
{
	cout << "ԭ�е�����Ϣ:" << endl;
	stu.push_back(Shopkeeper("����", "19", 30, "��ŷ�", 15000, 8000, "����"));
	ofs_shopkeeper << "���� ,19��   ְλ�� ��ŷ��곤   ���۵�ʳ��۸� ��30Ԫ     ÿ����н��  15000Ԫ    �������: 8000    ������  ����  " << endl;
	Zoo_keeper::syz_money = Zoo_keeper::syz_money - 7500 - 4000;
	Zoo_keeper::syz_money = Zoo_keeper::syz_money - 7500 - 4000;
	for (shop = stu.begin(); shop != stu.end(); shop++)
	{
		shop->show();
	}
}
void Menu::Menu_shopkeeper()
{
	ofs_shopkeeper.open("C:\\Users\\ASUS\\Desktop\\��Ѷ�ͰͶ���԰\\shopkeeper.txt", ios::app);           //û����Ӷ��곤�󱣴浽�ļ�����ı�β����׷�����ݵķ�ʽ ios::app
	ofs_shopkeeper << "                             �곤��Ϣ�����������£�" << endl;
	ofs_shopkeeper << endl;


	cout << "                                                   �����빦����ţ�";
	int m;
	cin >> m;
	switch (m)
	{
	case 1:
		int number;
		cout << "����Ƹ�õ�������  ";
		cin >> number;
		for (int i = 0; i < number; i++)
		{
			string name;
			string life;
			int rent;    //ÿ��Ҫ�������
			string reputation; //���ǵ������̶�
			int food_price;  //����ʳ��۸�
			string position;
			int get_money;
			cout << "������";
			cin >> name;
			cout << "����: ";
			cin >> life;
			cout << "���";
			cin >> rent;
			cout << "ʳ��۸�";
			cin >> food_price;
			cout << "ְҵ: ";
			cin >> position;
			cout << "н��: ";
			cin >> get_money;
			cout << "����:";
			cin >> reputation;
			stu.push_back(Shopkeeper(name, life, food_price, position, get_money, rent, reputation));
			ofs_shopkeeper << name << "  " << life << "  ְλ�� " << position << "  ���۵�ʳ��۸�:  " << food_price << " Ԫ " << "   ÿ��н��: " << get_money << " Ԫ " << "  �������:  " << rent << "  ����:  " << endl;
			Zoo_keeper::syz_money = Zoo_keeper::syz_money - get_money / 2 - (rent / 2);
			Zoo_keeper::syz_money = Zoo_keeper::syz_money - get_money / 2 - (rent / 2);
			Shopkeeper::person++;
			cout << endl;
		}
		cout << "��ʾ���¹�Ӷ�ĵ�����Ϣ��" << endl;
		for (shop = stu.begin(); shop != stu.end(); shop++)
		{
			shop->show();
		}
		break;
	case 2:
	{
			  cout << "���������ĵ�����" << endl;
			  string name1;
			  cin >> name1;
			  Shopkeeper shop1(name1);
			  S = find(stu.begin(), stu.end(), shop1);        //�����㷨��find����  ��ָ���Ӧ���Ƕ�����stu�����в�����shop1���������ͬ���ֵ���
			  if (S == stu.end())
			  {
				  cout << "û�иõ�����" << endl;
				  break;
			  }

			  else
			  {
				  cout << "************************" << endl;
				  cout << "���ڸõ�����" << endl;
				  cout << "��ʾ�õ�����Ϣ" << endl;
				  S->show();
				  cout << "************************" << endl;
				  S->Dismiss(name1);
				
				  cout << "�������Ϣ:" << endl;
				  S->show();
				  cout << endl;
				  cout << endl;
			  }
			  cout << "��ʾ���¹�Ӷ�ĵ�����Ϣ��" << endl;
			  stu.erase(S);
			//  stu.pop_back();
			  for (shop = stu.begin(); shop != stu.end(); shop++)
			  {
				  shop->show();
			  }
			  break;
	}
		
	default:
		if (m > 2 || m < 1)
			cout << "��������" << endl;
		//��Ӧ������
		break;
	}
}

void Menu::Menu_tourist()
{
	Tourist tourist;
	tourist.Need_Money();
	int Summary = 0; int infant = 0; int student = 0; int adult = 0; int Lovers = 0;
	cout << "�����������ο͸���" << endl;                        //�����һ��������
	cin >> Summary;
	int k = 0;
	cout << "�м������͵��οͣ�";
	cin >> k;
	cout << "�׶�������";
	cin >> infant;
	cout << "ѧ������:";
	cin >> student;
	cout << "�����˸���:";
	cin >> adult;
	cout << "��������";
	cin >> Lovers;  
	int summary = 0;                                  //׷Ѱ����ο͵�������������whileѭ�����ж�
	list<Tourist*> INfant;                 //��������׶�������,ָ������
	list<Tourist*>::iterator INfant1;      //���������׶����ݵĵ�������ָ������
	list<Tourist*> Stu;                 //�������ѧ��������,ָ������
	list<Tourist*>::iterator Stu1;      //��������ѧ�����ݵĵ�������ָ������                 
	list<Tourist*> ADult;                 //������ų��˵�����,ָ������
	list<Tourist*>::iterator ADult1;      //�������ʳ������ݵĵ�������ָ������     
	list<Tourist*> LOvers;              //���������������ݵĵ�������ָ������
	list<Tourist*>::iterator LOvers1;   //���������������ݵ�������ָ������
	ofstream ofs_tourist;
	ofs_tourist.open("C:\\Users\\ASUS\\Desktop\\��Ѷ�ͰͶ���԰\\tourist.txt", ios::app);                     //û���ض������ο�����Ʊ��󱣴浽�ļ�����ı�β����׷�����ݵķ�ʽ ios::app
	ofs_tourist << "                            �ο���Ϣ�����������£�" << endl;
	ofs_tourist << endl;
	while (summary <= Summary)
	{
	
		for (int w = 0; w < k; w++)
		{

			string TYPE = " ";                     //��ʼ���ο�����
			cout << "**************************" << endl;
			cout << "���빺Ʊ���ο�����:   ";
			cin >> TYPE;
			if (TYPE == "�׶�")
			{
				for (int i = 0; i < infant; i++)
				{

					string name = ""; int life = 0; string identity = " "; int height = 0;
					cout << "����: ";
					cin >> name;
					cout << "���䣺";
					cin >> life;
					cout << "���: ";
					cin >> identity;
					cout << "��ߣ�";
					cin >> height;
					INfant.push_back(new Infant(name, life, identity, height));
					ofs_tourist << name << "  " << life << "  " << identity << "   ��ߣ� " << height << endl;
				}
				for (INfant1 = INfant.begin(); INfant1 != INfant.end(); INfant1++)
				{

					(*INfant1)->information();                            //ͨ��ָ�����͵ĵ��������ú���
					(*INfant1)->Need_Money();
				}

			}

			if (TYPE == "ѧ��")
			{

				for (int j = 0; j < student; j++)
				{

					string name = ""; int life = 0; string identity = " "; int height = 0; string stu_id = " ";
					cout << "����: ";
					cin >> name;
					cout << "���䣺";
					cin >> life;
					cout << "���: ";
					cin >> identity;
					cout << "�Ƿ��ѧ��֤��";
					cin >> stu_id;

					Stu.push_back(new Student(name, life, identity, stu_id));
					ofs_tourist << name << "  " << life << "  " << identity << "   �Ƿ����ѧ��֤�� " << stu_id << endl;
				}
				for (Stu1 = Stu.begin(); Stu1 != Stu.end(); Stu1++)
				{

					(*Stu1)->information();                            //ͨ��ָ�����͵ĵ��������ú���
					(*Stu1)->Need_Money();
				}

			}

			if (TYPE == "����")
			{

				for (int k = 0; k < adult; k++)
				{

					string name = ""; int life = 0; string identity = " ";
					cout << "����: ";
					cin >> name;
					cout << "���䣺";
					cin >> life;
					cout << "���: ";
					cin >> identity;

					ADult.push_back(new Adult(name, life, identity));
					ofs_tourist << name << "  " << life << "  " << identity << endl;
				}
				for (ADult1 = ADult.begin(); ADult1 != ADult.end(); ADult1++)
				{

					(*ADult1)->information();                            //ͨ��ָ�����͵ĵ��������ú���
					(*ADult1)->Need_Money();
				}

			}

			if (TYPE == "����")
			{

				for (int m = 0; m < Lovers; m++)
				{

					string name = ""; int life = 0; string identity = " "; int height = 0;
					cout << "����: ";
					cin >> name;
					cout << "���䣺";
					cin >> life;
					cout << "���: ";
					cin >> identity;
					LOvers.push_back(new lovers(name, life, identity));
					ofs_tourist << name << "  " << life << "  " << identity << endl;
				}
				for (LOvers1 = LOvers.begin(); LOvers1 != LOvers.end(); LOvers1++)
				{

					(*LOvers1)->information();                            //ͨ��ָ�����͵ĵ��������ú���
					(*LOvers1)->Need_Money();
				}

			}
		}
		summary = infant + student + adult + Lovers + 1;
	}
}

void Menu::Menu_zookeeper()
{
	int m = 0; int n = 0;
	cout << "                                  ��ӭ˾԰��������    ";
	Zoo_keeper keeper1("˾����", 19);
	cout << "                  ��ӭ��԰��������" << endl;
	Zoo_keeper keeper2("��־��", 19);
	keeper1.Profit();
	keeper1.get_Money();
	if (Zoo_keeper::syz_money != 0)
	{
		keeper1.left_money();
	}
	cout << "                                               ********************" << endl;
	cout << "                                               ********************" << endl;
	keeper1.Show(m);
	keeper2.Show(m, n);
}

list<Animal*> amphibian;          //���������麯����ϣ����û���ָ��������ָ������
list<Fish*> fish;
list<Bird*> bird;
list<Reptiles*> reptiles;
list<Mammal*> mammal;
list<Animal*>::iterator amp;
list<Fish*> ::iterator fi;
list<Bird*>::iterator bi;
list<Reptiles*>::iterator re;
list<Mammal*>::iterator ma;

void Menu::Menu_animal_buy()
{

	list<Zoo_keeper> siyunzhong;
	list<Zoo_keeper> huzhiming;
	int sum_money = 0;
	int choise = 0;
	int choiseA = 0;
	int choiseB = 0;
	int choiseC = 0;
	int choiseD = 0;
	int choiseE = 0;
	cin >> choise;
	Zoo_keeper::save_money = Zoo_keeper::Property / 2;              // �м侲̬��Ա���������ʲ���ʣ��Ǯ��ת��
	Zoo_keeper::syz_money = Zoo_keeper::Property / 2;                //��Ǯ����˾԰���ͺ�԰�����˻�
	Zoo_keeper::hgm_money = Zoo_keeper::Property / 2;
	ofstream ofs_animal;                                  //�������뵽�ļ��Ķ���Ȼ��ÿ�����궯��֮�󱣴浽�ļ�����ı�β����׷�����ݵķ�ʽ ios::app                                          
	ofs_animal.open("C:\\Users\\ASUS\\Desktop\\��Ѷ�ͰͶ���԰\\animal.txt", ios::app);        //�������뵽�ļ��Ķ���Ȼ��ÿ�����궯��֮�󱣴浽�ļ�����ı�β����׷�����ݵķ�ʽ ios::app
	ofs_animal << "                             ����Ķ��ﱣ����Ϣ����" << endl;
	ofs_animal << endl;
	switch (choise)
	{
	case 1:

		cout << "                                 ����Ҫ����������ද��" << endl;
		cout << "                         1.����   2.�������    3.����СϿ����   4.�ذͰ���" << endl;
		cout << "                         5.ȫ������                              " << endl;
		cout << "                                 ��������ţ�";
		cin >> choiseA;
		if (Zoo_keeper::syz_money >= Zoo_keeper::hgm_money)
		{
			cout << "˾԰�����ȸ�Ǯ���ڶ��" << endl;
			if (choiseA == 1)
			{
				amphibian.push_back(new Amphibian("����", "5��", "�����峤42��44mm�������峤62mm����", 8700));
				Zoo_keeper::syz_money -= 8700;
				ofs_animal << "����  ��5�꣬ �����峤42��44mm�������峤62mm���ң�8700Ԫ" << endl;
				break;
			}
			if (choiseA == 2)
			{
				amphibian.push_back(new Amphibian("�������", "20��", "6��������", 7900));
				Zoo_keeper::syz_money -= 7900;
				ofs_animal << "�������  ,20�� ,6�������� ,  7900" << endl;
				break;
			}
			if (choiseA == 3)
			{
				amphibian.push_back(new Amphibian("����С������", "14��", "�³����峤12 mm", 5400));
				Zoo_keeper::syz_money -= 5400;
				ofs_animal << "����С������  , 14��, �³����峤12 mm, 5400" << endl;
				break;
			}
			if (choiseA == 4)
			{
				amphibian.push_back(new Amphibian("̩�Ͱ���", "8��", "125cm", 10600));
				Zoo_keeper::syz_money -= 10600;
				ofs_animal << "̩�Ͱ���  , 8��, 125cm, 10600" << endl;
				break;
			}
			if (choiseA == 5)
			{

				amphibian.push_back(new Amphibian("����", "5��", "�����峤42��44mm�������峤62mm����", 8700));
				amphibian.push_back(new Amphibian("�������", "20��", "6��������", 7900));
				amphibian.push_back(new Amphibian("����С������", "14��", "�³����峤12 mm", 5400));
				amphibian.push_back(new Amphibian("̩�Ͱ���", "8��", "125cm", 10600));
				Zoo_keeper::syz_money = Zoo_keeper::syz_money - (8700 + 7900 + 5400 + 10600);
				ofs_animal << "����  ��5�꣬ �����峤42��44mm�������峤62mm���ң�8700Ԫ" << endl;
				ofs_animal << "�������  ,20�� ,6�������� ,  7900" << endl;
				ofs_animal << "����С������  , 14��, �³����峤12 mm, 5400" << endl;
				ofs_animal << "̩�Ͱ���  , 8��, 125cm, 10600" << endl;
				break;
			}

		}
		if (choiseA > 5 || choiseA < 1)
			cout << "��������" << endl;
		//��Ӧ������
		break;

	case 2:
		cout << "                                 ����Ҫ��������ද��" << endl;
		cout << "                         1.������ʨ      2.�л���     3.������" << endl;
		cout << "                         4.ȫ������                              " << endl;
		cout << "                                 ��������ţ�";
		cin >> choiseB;
		cout << "��ʱ��԰��Ǯ����˾԰�������Ժ�԰����������һ���Ķ���Ľ���" << endl;
		if (choiseB == 1)
		{
			fish.push_back(new Fish("������ʨ", "2��", "�峤����", 14302));
			Zoo_keeper::hgm_money -= 14302;
			ofs_animal << "������ʨ  , 2��, �峤����, 14302" << endl;
			break;
		}
		if (choiseB == 2)
		{
			fish.push_back(new Fish("�л���", "3��", "�峤ƽ��Լ40����", 18888));
			Zoo_keeper::hgm_money -= 18888;
			ofs_animal << "�л���  , 3��, �峤ƽ��Լ40����, 18888" << endl;
			break;
		}
		if (choiseB == 3)
		{
			fish.push_back(new Fish("������", "1��", "�峤Լ100-130����", 16888));
			Zoo_keeper::hgm_money -= 16888;
			ofs_animal << "������  , 1��, �峤Լ100-130����, 16888" << endl;
			break;
		}
		if (choiseB == 4)
		{
			fish.push_back(new Fish("������ʨ", "2��", "�峤����", 14302));
			fish.push_back(new Fish("�л���", "3��", "�峤ƽ��Լ40����", 18888));
			fish.push_back(new Fish("������", "1��", "�峤Լ100-130���ס�", 16888));
			Zoo_keeper::hgm_money = Zoo_keeper::hgm_money - 14302 - 18888 - 16888;
			ofs_animal << "������ʨ  , 2��, �峤����, 14302" << endl;
			ofs_animal << "�л���  , 3��, �峤ƽ��Լ40����, 18888" << endl;
			ofs_animal << "������  , 1��, �峤Լ100-130����, 16888" << endl;
			break;
		}

		if (choiseB > 4 || choiseB < 1)
			cout << "��������" << endl;
		//��Ӧ������
		break;
	case 3:
		cout << "                                 ����Ҫ��������ද��" << endl;
		cout << "                         1.����      2.����     3.������     4.�ɺ�" << endl;
		cout << "                         5.ȫ������                              " << endl;
		cout << "                                 ��������ţ�";
		cin >> choiseC;
		if (Zoo_keeper::syz_money >= Zoo_keeper::hgm_money)
		{
			cout << "˾԰�����ʲ��Ⱥ�԰���Ķ࣬������һ����˾԰����������" << endl;
			if (choiseC == 1)
			{
				bird.push_back(new Bird("����", " ", "�峤��6-12����֮��", 5120));
				ofs_animal << "����  ,  , �峤��6-12����֮��,  5120" << endl;
				Zoo_keeper::syz_money -= 5120;
				break;
			}
			if (choiseC == 2)
			{
				bird.push_back(new Bird("����", " ", "�峤�ɴ�100����", 2560));
				Zoo_keeper::syz_money -= 2560;
				ofs_animal << "����  ,  , �峤�ɴ�100����, 2560" << endl;
				break;
			}
			if (choiseC == 3)
			{
				bird.push_back(new Bird("������", " ", "�峤16-18����", 10240));
				Zoo_keeper::syz_money -= 10240;
				ofs_animal << "������  ,  , �峤16-18����, 10240" << endl;
				break;
			}
			if (choiseC == 4)
			{
				bird.push_back(new Bird("�ɺ�", " ", "�峤120-160����", 7700));
				Zoo_keeper::syz_money -= 7700;
				ofs_animal << "�ɺ�  ,  , �峤120-160����, 7700" << endl;
				break;
			}
			if (choiseC == 5)
			{
				bird.push_back(new Bird("����", " ", "�峤��6-12����֮��", 5120));
				bird.push_back(new Bird("����", " ", "�峤�ɴ�100����", 2560));
				bird.push_back(new Bird("������", " ", "�峤16-18����", 10240));
				bird.push_back(new Bird("�ɺ�", " ", "�峤120-160����", 7700));
				Zoo_keeper::syz_money = Zoo_keeper::syz_money - 5120 - 2560 - 10240 - 7700;
				ofs_animal << "����,  , �峤��6-12����֮��, 16888" << endl;
				ofs_animal << "����  ,  , �峤�ɴ�100����, 2560" << endl;
				ofs_animal << "������  ,  , �峤16-18����, 10240" << endl;
				ofs_animal << "�ɺ�  ,  , �峤120-160����, 7700" << endl;
			}
		}
		else
		{
			cout << "��԰���ʲ���˾԰���ʲ��࣬��������ɺ�԰���������" << endl;
			if (choiseC == 1)
			{
				bird.push_back(new Bird("����", " ", "�峤��6-12����֮��", 5120));
				Zoo_keeper::hgm_money -= 5120;
				ofs_animal << "����,  , �峤��6-12����֮��, 16888" << endl;
				break;
			}
			if (choiseC == 2)
			{
				bird.push_back(new Bird("����", " ", "�峤�ɴ�100����", 2560));
				Zoo_keeper::hgm_money -= 2560;
				ofs_animal << "����  ,  , �峤�ɴ�100����, 2560" << endl;
				break;
			}
			if (choiseC == 3)
			{
				bird.push_back(new Bird("������", " ", "�峤16-18����", 10240));
				Zoo_keeper::hgm_money -= 10240;
				ofs_animal << "������  ,  , �峤16-18����, 10240" << endl;
				break;
			}
			if (choiseC == 4)
			{
				bird.push_back(new Bird("�ɺ�", " ", "�峤120-160����", 7700));
				Zoo_keeper::hgm_money -= 7700;
				ofs_animal << "�ɺ�  ,  , �峤120-160����, 7700" << endl;
				break;
			}
			if (choiseC == 5)
			{
				bird.push_back(new Bird("����", " ", "�峤��6-12����֮��", 5120));
				bird.push_back(new Bird("����", " ", "�峤�ɴ�100����", 2560));
				bird.push_back(new Bird("������", " ", "�峤16-18����", 10240));
				bird.push_back(new Bird("�ɺ�", " ", "�峤120-160����", 7700));
				Zoo_keeper::hgm_money = Zoo_keeper::hgm_money - 5120 - 2560 - 10240 - 7700;
				ofs_animal << "����,  , �峤��6-12����֮��, 16888" << endl;
				ofs_animal << "����  ,  , �峤�ɴ�100����, 2560" << endl;
				ofs_animal<< "������  ,  , �峤16-18����, 10240" << endl;
				ofs_animal << "�ɺ�  ,  , �峤120-160����, 7700" << endl;
			}
		}

		if (choiseC > 5 || choiseC < 1)
			cout << "��������" << endl;
		//��Ӧ������
		break;
	case 4:
		cout << "                                 ����Ҫ����������ද��" << endl;
		cout << "                    1.��Ƥ�߹�      2.��Ī�����     3.������     4.����ѷɭ��      5.��ˮ��" << endl;
		cout << "                    6.ȫ������                              " << endl;
		cout << "                                 ��������ţ�";
		cin >> choiseD;
		if (Zoo_keeper::syz_money >= Zoo_keeper::hgm_money)
		{
			cout << "˾԰�����ʲ��Ⱥ�԰���Ķ࣬������һ����˾԰����������!" << endl;
			if (choiseD == 1)
			{
				reptiles.push_back(new Reptiles("��Ƥ����", " ", "������9Ӣ�߳�", 13400));
				Zoo_keeper::syz_money -= 13400;
				ofs_animal << "��Ƥ����  ,  , ������9Ӣ�߳�, ��ֵ13400Ԫ" << endl;
				break;
			}
			if (choiseD == 2)
			{
				reptiles.push_back(new Reptiles("��Ī����� ", " ", "ƽ���峤2��3��", 12600));
				Zoo_keeper::syz_money -= 12600;
				ofs_animal << "��Ī�����  ,  , ƽ���峤2��3��, ��ֵ12600Ԫ" << endl;
				break;
			}
			if (choiseD == 3)
			{
				reptiles.push_back(new Reptiles("������", " ", "����Ϊ1.5��-2.3��", 10086));
				Zoo_keeper::syz_money -= 10086;
				ofs_animal << "������  ,  , ����Ϊ1.5��-2.3��, ��ֵ10086Ԫ" << endl;
				break;
			}
			if (choiseD == 4)
			{
				reptiles.push_back(new Reptiles("����ѷɭ��", " ", "��ɴ�ʮ��", 11526));
				Zoo_keeper::syz_money -= 11526;
				ofs_animal << "����ѷɭ��  ,  , ��ɴ�ʮ��, ��ֵ11526Ԫ" << endl;
				break;
			}
			if (choiseD == 5)
			{
				reptiles.push_back(new Reptiles("��ˮ��", " ", "����һ�㳤3��5�ף���ɴ�7������", 7600));
				Zoo_keeper::syz_money -= 7600;
				ofs_animal << "��ˮ��  ,  , ����һ�㳤3��5�ף���ɴ�7������, ��ֵ7600Ԫ" << endl;
				break;

			}
			if (choiseD == 6)
			{
				reptiles.push_back(new Reptiles("��Ƥ����", " ", "������9Ӣ�߳�", 13400));
				reptiles.push_back(new Reptiles("��Ī����� ", " ", "ƽ���峤2��3��", 12600));
				reptiles.push_back(new Reptiles("������", " ", "����Ϊ1.5��-2.3��", 10086));
				reptiles.push_back(new Reptiles("����ѷɭ��", " ", "��ɴ�ʮ��", 11526));
				reptiles.push_back(new Reptiles("��ˮ��", " ", "����һ�㳤3��5�ף���ɴ�7������", 7600));
				Zoo_keeper::syz_money = Zoo_keeper::syz_money - 13400 - 12600 - 10086 - 11526 - 7600;
				ofs_animal << "��Ƥ����  ,  , ������9Ӣ�߳�, ��ֵ13400Ԫ" << endl;
				ofs_animal << "��Ī�����  ,  , ƽ���峤2��3��, ��ֵ12600Ԫ" << endl;
				ofs_animal << "������  ,  , ����Ϊ1.5��-2.3��, ��ֵ10086Ԫ" << endl;
				ofs_animal << "����ѷɭ��  ,  , ��ɴ�ʮ��, ��ֵ11526Ԫ" << endl;
				ofs_animal << "��ˮ��  ,  , ����һ�㳤3��5�ף���ɴ�7������, ��ֵ7600Ԫ" << endl;
				break;
			}
		}
		else
		{

			cout << "��԰���ʲ���˾԰���ʲ��࣬��������ɺ�԰���������" << endl;
			if (choiseD == 1)
			{
				reptiles.push_back(new Reptiles("��Ƥ����", " ", "������9Ӣ�߳�", 13400));
				Zoo_keeper::hgm_money -= 13400;
				ofs_animal << "��Ƥ����  ,  , ������9Ӣ�߳�, ��ֵ13400Ԫ" << endl;
				break;
			}
			if (choiseD == 2)
			{
				reptiles.push_back(new Reptiles("��Ī����� ", " ", "ƽ���峤2��3��", 12600));
				Zoo_keeper::hgm_money -= 12600;
				ofs_animal << "��Ī�����  ,  , ƽ���峤2��3��, ��ֵ12600Ԫ" << endl;
				break;
			}
			if (choiseD == 3)
			{
				reptiles.push_back(new Reptiles("������", " ", "����Ϊ1.5��-2.3��", 10086));
				Zoo_keeper::hgm_money -= 10086;
				ofs_animal << "������  ,  , ����Ϊ1.5��-2.3��, ��ֵ10086Ԫ" << endl;
				break;
			}
			if (choiseD == 4)
			{
				reptiles.push_back(new Reptiles("����ѷɭ��", " ", "��ɴ�ʮ��", 11526));
				Zoo_keeper::hgm_money -= 11526;
				ofs_animal << "����ѷɭ��  ,  , ��ɴ�ʮ��, ��ֵ11526Ԫ" << endl;
				break;
			}
			if (choiseD == 5)
			{
				reptiles.push_back(new Reptiles("��ˮ��", " ", "����һ�㳤3��5�ף���ɴ�7������", 7600));
				Zoo_keeper::hgm_money -= 7600;
				ofs_animal << "��ˮ��  ,  , ����һ�㳤3��5�ף���ɴ�7������, ��ֵ7600Ԫ" << endl;
				break;
			}
			if (choiseD == 6)
			{
				reptiles.push_back(new Reptiles("��Ƥ����", " ", "������9Ӣ�߳�", 13400));
				reptiles.push_back(new Reptiles("��Ī����� ", " ", "ƽ���峤2��3��", 12600));
				reptiles.push_back(new Reptiles("������", " ", "����Ϊ1.5��-2.3��", 10086));
				reptiles.push_back(new Reptiles("����ѷɭ��", " ", "��ɴ�ʮ��", 11526));
				reptiles.push_back(new Reptiles("��ˮ��", " ", "����һ�㳤3��5�ף���ɴ�7������", 7600));
				Zoo_keeper::hgm_money = Zoo_keeper::hgm_money - 13400 - 12600 - 10086 - 11526 - 7600;
				ofs_animal << "��Ƥ����  ,  , ������9Ӣ�߳�, ��ֵ13400Ԫ" << endl;
				ofs_animal << "��Ī�����  ,  , ƽ���峤2��3��, ��ֵ12600Ԫ" << endl;
				ofs_animal << "������  ,  , ����Ϊ1.5��-2.3��, ��ֵ10086Ԫ" << endl;
				ofs_animal << "����ѷɭ��  ,  , ��ɴ�ʮ��, ��ֵ11526Ԫ" << endl;
				ofs_animal << "��ˮ��  ,  , ����һ�㳤3��5�ף���ɴ�7������, ��ֵ7600Ԫ" << endl;
				break;
			}
		}
		if (choiseD > 6 || choiseD < 1)
			cout << "��������" << endl;
		//��Ӧ������
		break;
	case 5:
		cout << "                                 ����Ҫ����Ĳ����ද��" << endl;
		cout << "                    1.��è      2.�ϼ�����     3.����     4.����      5.��ͷҶ��" << endl;
		cout << "                    6.ȫ������                              " << endl;
		cout << "                                 ��������ţ�";
		cin >> choiseE;
		if (Zoo_keeper::syz_money >= Zoo_keeper::hgm_money)
		{
			cout << "˾԰�����ʲ��Ⱥ�԰���Ķ࣬������һ����˾԰����������!" << endl;
			if (choiseE == 1)
			{
				cout << "�����޼�֮�������ܹ���" << endl;
				//mammal.push_back(new Mammal("��è", " ", "ͷ����1.2-1.8�ף�β��10-12���� ", 99999999));
				break;
			}
			if (choiseE == 2)
			{
				mammal.push_back(new Mammal("�ϼ�����", " ", "�ϼ��������Լ��90-110���ף�ƽ���峤290����", 14320));
				Zoo_keeper::syz_money -= 14320;
				ofs_animal << "�ϼ�����  ,  , �ϼ��������Լ��90-110���ף�ƽ���峤290����, ��ֵ14320Ԫ" << endl;
				break;
			}
			if (choiseE == 3)
			{
				mammal.push_back(new Mammal("����", " ", "��С", 6400));
				Zoo_keeper::syz_money -= 6400;
				ofs_animal << "����  ,  , ��С, ��ֵ6400Ԫ" << endl;
				break;
			}
			if (choiseE == 4)
			{
				mammal.push_back(new Mammal("����", " ", " ������峤Լ30��40����  ��������峤�ɴ�45����", 2600));
				Zoo_keeper::syz_money -= 2600;
				ofs_animal << "����  ,  , ������峤Լ30��40����  ��������峤�ɴ�45����, ��ֵ2600Ԫ" << endl;
				break;
			}
			if (choiseE == 5)
			{
				mammal.push_back(new Mammal("��ͷҶ��", " ", "�������峤Ϊ50-70���ף�β��60-80����", 12888));
				Zoo_keeper::syz_money -= 12888;
				ofs_animal << "��ͷҶ��  ,  , �������峤Ϊ50-70���ף�β��60-80����, ��ֵ12888Ԫ" << endl;
				break;
			}
			if (choiseE == 6)
			{
				cout << "��è�ǹ��������ܹ��򣬱�Ǹ~~" << endl;
				mammal.push_back(new Mammal("�ϼ�����", " ", "�ϼ��������Լ��90-110���ף�ƽ���峤290����", 14320));
				mammal.push_back(new Mammal("����", " ", "��С", 6400));
				mammal.push_back(new Mammal("����", " ", " ������峤Լ30��40����  ��������峤�ɴ�45����", 2600));
				mammal.push_back(new Mammal("��ͷҶ��", " ", "�������峤Ϊ50-70���ף�β��60-80����", 12888));
				Zoo_keeper::syz_money = Zoo_keeper::syz_money - 14320 - 6400 - 2600 - 12888;
				ofs_animal << "�ϼ�����  ,  , �ϼ��������Լ��90-110���ף�ƽ���峤290����, ��ֵ14320Ԫ" << endl;
				ofs_animal << "����  ,  , ��С, ��ֵ6400Ԫ" << endl;
				ofs_animal << "����  ,  , ������峤Լ30��40����  ��������峤�ɴ�45����, ��ֵ2600Ԫ" << endl;
				ofs_animal << "��ͷҶ��  ,  , �������峤Ϊ50-70���ף�β��60-80����, ��ֵ12888Ԫ" << endl;
				break;
			}
		}
		else
		{
			cout << "��԰���ʲ���˾԰���ʲ��࣬��������ɺ�԰���������" << endl;
			if (choiseE == 1)
			{
				cout << "�����޼�֮�������ܹ���" << endl;
				//mammal.push_back(new Mammal("��è", " ", "ͷ����1.2-1.8�ף�β��10-12���� ", 99999999));
				ofs_animal << "�ϼ�����  ,  , �ϼ��������Լ��90-110���ף�ƽ���峤290����, ��ֵ14320Ԫ" << endl;
				break;
			}
			if (choiseE == 2)
			{
				mammal.push_back(new Mammal("�ϼ�����", " ", "�ϼ��������Լ��90-110���ף�ƽ���峤290����", 14320));
				Zoo_keeper::hgm_money -= 14320;
				ofs_animal << "�ϼ�����  ,  , �ϼ��������Լ��90-110���ף�ƽ���峤290����, ��ֵ14320Ԫ" << endl;
				break;
			}
			if (choiseE == 3)
			{
				mammal.push_back(new Mammal("����", " ", "��С", 6400));
				Zoo_keeper::hgm_money -= 6400;
				ofs_animal << "����  ,  , ��С, ��ֵ6400Ԫ" << endl;
				break;
			}
			if (choiseE == 4)
			{
				mammal.push_back(new Mammal("����", " ", " ������峤Լ30��40����  ��������峤�ɴ�45����", 2600));
				Zoo_keeper::hgm_money -= 2600;
				ofs_animal << "����  ,  , ������峤Լ30��40����  ��������峤�ɴ�45����, ��ֵ2600Ԫ" << endl;
				break;
			}
			if (choiseE == 5)
			{
				mammal.push_back(new Mammal("��ͷҶ��", " ", "�������峤Ϊ50-70���ף�β��60-80����", 12888));
				Zoo_keeper::hgm_money -= 12888;
				ofs_animal << "��ͷҶ��  ,  , �������峤Ϊ50-70���ף�β��60-80����, ��ֵ12888Ԫ" << endl;
				break;
			}
			if (choiseE == 6)
			{
				cout << "��è�ǹ��������ܹ��򣬱�Ǹ~~" << endl;
				mammal.push_back(new Mammal("�ϼ�����", " ", "�ϼ��������Լ��90-110���ף�ƽ���峤290����", 14320));
				mammal.push_back(new Mammal("����", " ", "��С", 6400));
				mammal.push_back(new Mammal("����", " ", " ������峤Լ30��40����  ��������峤�ɴ�45����", 2600));
				mammal.push_back(new Mammal("��ͷҶ��", " ", "�������峤Ϊ50-70���ף�β��60-80����", 12888));
				Zoo_keeper::hgm_money = Zoo_keeper::hgm_money - 14320 - 6400 - 2600 - 12888;
				ofs_animal << "�ϼ�����  ,  , �ϼ��������Լ��90-110���ף�ƽ���峤290����, ��ֵ14320Ԫ" << endl;
				ofs_animal << "����  ,  , ��С, ��ֵ6400Ԫ" << endl;
				ofs_animal << "����  ,  , ������峤Լ30��40����  ��������峤�ɴ�45����, ��ֵ2600Ԫ" << endl;
				ofs_animal << "��ͷҶ��  ,  , �������峤Ϊ50-70���ף�β��60-80����, ��ֵ12888Ԫ" << endl;
				break;
			}
		}
		if (choiseE > 6 || choiseE < 1)
			cout << "��������" << endl;
		//��Ӧ������
		break;
		ofs_animal.close();
	default:
		cout << "��������" << endl;
		break;
	}
}

void Menu::Menu_animal_show()
{
	string animal_type;
	cout << "����Ҫ��ѯ�Ķ������" << endl;
	cin >> animal_type;
	if (animal_type == "������")
	for (amp = amphibian.begin(); amp != amphibian.end(); amp++)
	{
		(*amp)->display();
		cout << "���ﻨ�ѵ�Ǯ" << (*amp)->get_money() << "Ԫ" << endl;
	}
	else if (animal_type == "����")
	for (fi = fish.begin(); fi != fish.end(); fi++)
	{
		(*fi)->display();
		cout << "���ﻨ�ѵ�Ǯ" << (*fi)->get_money() << "Ԫ" << endl;
	}
	else if (animal_type == "����")
	for (bi = bird.begin(); bi != bird.end(); bi++)
	{
		(*bi)->display();
		cout << "���ﻨ�ѵ�Ǯ" << (*bi)->get_money() << "Ԫ" << endl;
	}
	else if (animal_type == "������")
	for (re = reptiles.begin(); re != reptiles.end(); re++)
	{
		(*re)->display();
		cout << "���ﻨ�ѵ�Ǯ" << (*re)->get_money() << "Ԫ" << endl;
	}
	else if (animal_type == "������")
	for (ma = mammal.begin(); ma != mammal.end(); ma++)
	{
		(*ma)->display();
		cout << "���ﻨ�ѵ�Ǯ" << (*ma)->get_money() << "Ԫ" << endl;
	}
	else
		cout << "û�и����͵Ķ������ʧ�ܣ�" << endl;
}
   

/*class Ofs{
public:
	void ofs_in();
	
};
ofstream& operator<<(ofstream& fs, list<Amphibian*> &amphibian)
{

	for (amp = amphibian.begin(); amp != amphibian.end(); amp++)
	{
		
		(*amp)->display();
	}
	return fs;
}
void Ofs::ofs_in()
{
	ofstream ofs;
	ofs.open("C:\\Users\\ASUS\\Desktop\\��Ѷ�ͰͶ���԰\\a.txt", ios::out);
	if (ofs)
	{
		ofs << amphibian << endl;
	}
	ofs.close();
}*/
#endif   