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
class Animal                                                                 //该部分可以抽象为公园不同的景区
{
public:
	string Name;
	int Life;
	int Size;
	int Value;
public:
	Animal(){}
	virtual void display();     //显示各动物的基本信息
	virtual int get_money();
};
int Animal::get_money(){ return 1; }
void Animal::display(){}
class Amphibian :public Animal    //两栖类
{
public:
	string Name;
	string Life;
	string Size;
	int Value;
	string Characteristic;//两栖类动物特征类型为海陆兼容
public:
	virtual void display();
	Amphibian(string name, string life, string size, int value, string Characteristic = "海陆兼容");
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
	string Characteristic;    //两栖类动物特征类型为海陆兼容
public:
	virtual void display();
	Fish(string name, string life, string size, int value, string Characteristic = "用鳃呼吸");
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
class Bird :public Animal   //鸟类动物
{
public:
	string Name;
	string Life;
	string Size;
	int Value;
	string Characteristic; //鸟类特性
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
class Reptiles :public Animal     //爬行类动物
{
public:
	string Name;
	string Life;
	string Size;
	int Value;
	string Characteristic; //爬行特性
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
class Mammal //哺乳动物
{
public:
	string Name;
	string Life;
	string Size;
	int Value;
	string Characteristic; //胎生特性
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
	int Rent;    //每年要付的租金
	string Reputation; //他们的信誉程度
	int Food_price;  //定义食物价格
	string Position;
	int Get_money;
	static int person;
public:
	void Dismiss(string name);
	friend class Zoo_keeper;

public:
	Shopkeeper(string name, string life = " ", int food_price = 0, string position = " ", int get_money = 0, int rent = 10000, string reputation = "良好");
	void marry();    //婚姻状况
	void show();     //显示基本信息
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
		cout << "清除个人信息：" << endl;
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

void Shopkeeper::show()                                                              //该部分可以抽象为公园中游客休息和消费的场所
{
	cout << "    姓名：" << Name << "    年龄:" << Life << "    租金：" << Rent << endl;
	cout << "    职业:" << Position << "    薪酬：" << Get_money << "    信誉：" << Reputation << endl;
	cout << "显示当前的店主数量：" << Shopkeeper::person << endl;
}
class Zoo_keeper                                                                               //该部分抽象为公园的管理层，类似于一些监管总部
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
	void Show(int m, int n);   //显示个人信息
	void Show(int m);
	void Dismiss(Shopkeeper &SHOP);  //解雇员工
	void Employ(Shopkeeper &SHOP);    //聘请员工
	void Profit();    //用于计算其公园利润  包含减去薪水  出去买动物的成本
	void Query();     //用于查询动物的基本信息
	void Transfer();   //用于转移动物
	void Buy_Animal();    //用于买动物  包含买动物的成本
	void left_money();
};
int Zoo_keeper::syz_money = 0;
int Zoo_keeper::hgm_money = 0;
int Zoo_keeper::Property = 0;             //原有资产
int Zoo_keeper::save_money = Zoo_keeper::Property;        //中间变量
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

		cout << "                                               司园长原有资产:" << Zoo_keeper::Property / 2 << "元" << endl;
		cout << "                                               胡园长原有资产:" << Zoo_keeper::Property / 2 << "元" << endl;
	}
	else
		return;

}
void Zoo_keeper::left_money()
{
	cout << "                                               司园长原有资产:" << Zoo_keeper::syz_money << "元" << endl;
	cout << "                                                   胡园长原有资产:" << Zoo_keeper::hgm_money << "元" << endl;
}
void Zoo_keeper::Show(int m)
{
	if (Zoo_keeper::save_money != 0)
		cout << "                                               姓名：" << Name << "  年龄:" << Life << "  资产:" << Zoo_keeper::syz_money << endl;
	else
		return;

}
void Zoo_keeper::Show(int n, int m)                      //利用重载函数来分别输出司园长和胡园长的信息
{
	if (Zoo_keeper::save_money != 0)
		cout << "                                               姓名：" << Name << "  年龄:" << Life << "  资产:" << Zoo_keeper::hgm_money << endl;
	else
		return;
}

void Zoo_keeper::Employ(Shopkeeper &SHOP)
{
	cout << "当前员工数量：" << Shopkeeper::person << endl;
	cout << "新雇佣的人的姓名：" << SHOP.Name << "   新雇佣人的年龄：" << SHOP.Life << endl;
	cout << " 新雇佣人的职位：" << SHOP.Position << "  每年要交的租金:" << SHOP.Rent << "  年薪酬" << endl;
	Shopkeeper::person++;
}

void Zoo_keeper::Profit()
{
	int sum;
	srand((unsigned)time(NULL));
	int You = 0;
	int YouM = 0;
	int YouB = 0;
	You = (rand() % (200 - 100 + 1)) + 100;//定义每月幼儿购票人数的范围为【100,200】
	cout << "                                               今月幼儿的人数为：" << You << endl;
	YouB = (rand() % (50 - 0 + 1)) + 0;//定义半票票的幼儿数量在【0,50】的范围内
	YouM = (rand() % (25 - 0 + 1)) + 0;//定义免票的幼儿数量在【0,25】的范围内
	cout << "                                               其中半价票的数量为：" << YouB << endl;
	cout << "                                               其中免票的数量为：" << YouM << endl;
	cout << "                                               在学生群体取得的收益为：" << (You - YouB - YouM) * 500 + (YouB * 250) << endl;

	int Stu = 0;
	int StuB = 0;
	cout << endl;
	Stu = (rand() % (2000 - 1000 + 1)) + 100;//定义每月学生购票人数的范围为【1000,2000】
	cout << "                                               今月学生的人数为：" << Stu << endl;
	StuB = (rand() % (850 - 1500 + 1)) + 1500;//定义八折票的学生数量在【550,1000】的范围内
	cout << "                                               其中八折票的数量为：" << StuB << endl;
	cout << "                                               在幼儿群体取得的收益为：" << (Stu - Stu) * 800 + (StuB * 640) << endl;

	int Adu = 0;
	cout << endl;
	Adu = (rand() % (3000 - 1500 + 1)) + 1500;//定义每月成人购票人数的范围为【1500,3000】
	cout << "                                               今月成人的人数为：" << Adu << endl;
	cout << "                                               在成人群体取得的收益为：" << Adu * 1000 << endl;

	int Lov = 0;
	cout << endl;
	Lov = (rand() % (850 - 630 + 1)) + 630;//定义每月情侣购票人数的范围为【630,850】
	cout << "                                               今月情侣的人数为：" << Lov << endl;
	cout << "                                               在情侣群体取得的收益为：" << Lov * 2500 << endl;

	int Eld = 0;
	cout << endl;
	Eld = (rand() % (2300 - 1200 + 1)) + 1200;//定义每月情侣购票人数的范围为【1200,2300】
	cout << "                                               今月老年特殊群体的人数为：" << Eld << endl;

	cout << endl;
	sum = (You - YouB - YouM) * 500 + (YouB * 250) + (Stu - Stu) * 800 + (StuB * 640) + Adu * 1000 + Lov * 2500;
	cout << "                                               今月收入为：" << sum << endl;

	int Dre = 0, profit = 0;
	Dre = (rand() % (160000 - 35000 + 1)) + 35000;//定义月常维修的价格在【35000,160000】
	cout << "                                               这个月的维修费用为：" << Dre << endl;
	cout << "                                               这个月的净利润为：" << sum - Dre << endl;
	profit = sum - Dre;
	Zoo_keeper::Property = profit;

}

class Tourist                                                                       //这部分可以抽象为公园门口的售票处
{
public:
	string Identity;
public:
	Tourist(string identity = " ");
	virtual void Need_Money();    //提示需要交多少钱
	virtual void information();     //用于显示个人信息
};
Tourist::Tourist(string identity){
	Identity = identity;
	cout << "                                                           欢迎各位游客光临！" << endl;
}
void Tourist::Need_Money()
{
	cout << "                                                           动物园名称：万讯巴巴动物园" << endl;
	cout << "                                                               ****购票须知****" << endl;
	cout << "                                               幼儿类门票：500一人（身高低于120cm的半价,年龄小于3岁的免票）" << endl;
	cout << "                                               学生类门票：800一人（持有学生证可以打8折）           " << endl;
	cout << "                                               成人类门票：1000一人                                 " << endl;
	cout << "                                               情侣类门票：1800两人                                 " << endl;
	cout << "                                               国内70周岁以上老人（凭身份证，老年卡）、现役军人、残疾军人、" << endl;
	cout << "                                               军队离退休干部、三属凭有效证件免票；市区残疾人、癌症病人、" << endl;
	cout << "                                               优抚对象、持本人有效证件免票。" << endl;
	cout << "                                               开关园时间：5:00---21:00" << endl;
	cout << "                                               司园长qq：247179876，胡园长qq：923619812" << endl;
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
	virtual void Need_Money();    //提示对应的类需要交多少钱
	virtual void information();     //用于显示个人信息

};

void Infant::Need_Money()
{
	if (Life < 3)
	{
		cout << "免票" << endl;
		Price = 0;
	}
	else if (Height < 120)
	{
		cout << "半价门票：250元" << endl;
		Price /= 2;
	}
	else
	{
		cout << "全价门票：500元" << endl;
		Price = 500;
	}
}
void Infant::information()
{
	cout << "显示游客的信息" << endl;
	cout << "身份类别：" << Identity << endl;
	cout << "姓名：" << Name << endl;
	cout << "年龄：" << Life << "岁" << endl;
	cout << "身高：" << Height << "cm" << endl;
	cout << "公园回馈的消费券金额：" << Hold_money << "元" << endl;
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
	const double Discount;      //const常量不可改变
	string Identity;
	string Name;
	int Life;
	int Price;
	int Hold_money;
	string Stu_ID;               //判断是否带学生证
public:
	Student(string name, int life, string identity, string stu_id, int Hold_money = 100, int Price = 800);
	virtual void information();
	virtual void Need_Money();    //提示需要交多少钱
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
	cout << "显示游客的信息" << endl;
	cout << "身份类别：" << Identity << endl;
	cout << "姓名：" << Name << endl;
	cout << "年龄：" << Life << "岁" << endl;
	cout << "公园回馈的消费券金额：" << Hold_money << "元" << endl;
}

void Student::Need_Money()
{
	if (Stu_ID == "带了")
		cout << "有学生证，打8折：640元" << endl;
	else
		cout << "无学生证，全价:800元" << endl;
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
	virtual void Need_Money();    //提示需要交多少钱
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
	cout << "全价门票：1000" << endl;
}
void Adult::information()
{
	cout << "显示游客的信息" << endl;
	cout << "身份类别：" << Identity << endl;
	cout << "姓名：" << Name << endl;
	cout << "年龄：" << Life << "岁" << endl;
	cout << "公园回馈的消费券金额：" << Hold_money << "元" << endl;
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
	virtual void Need_Money();    //提示需要交多少钱
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
	cout << "情侣价格：900元每人" << endl;
}
void lovers::information()
{
	cout << "显示游客的信息" << endl;
	cout << "身份类别：" << Identity << endl;
	cout << "公园回馈的消费券金额：" << Hold_money << endl;
}


class Menu{                                                    //总菜单类
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
	cout << "                                       ***             请选择您想使用的功能：          ***\n";
	cout << "                                       ***      1.雇佣店长            2.开除店长       ***\n";
	cout << "                                       ***************************************************\n" << endl;


}
void Menu::Menu_main()
{
	cout << "                                       ***************************************************\n";
	cout << "                                       ***                                             ***\n";
	cout << "                                       ***                                             ***\n";
	cout << "                                       ***                                             ***\n";
	cout << "                                       ***            欢迎来到万讯巴巴动物园           ***\n";
	cout << "                                       ***             请选择您想使用的功能：          ***\n";
	cout << "                                       ***      1.购买动物            2.查看动物       ***\n";
	cout << "                                       ***     3.雇佣与开除           4.购票须知       ***\n";
	cout << "                                       ***               5.查看该月利润                ***\n";
	cout << "                                       ***               6.存入文本文档                ***\n";
	cout << "                                       ***               7.  退出系统                  ***\n";
	cout << "                                       ***************************************************\n" << endl;
	cout << "                                                   请输入序号：";
}
void Menu::Menu_buymenu()
{
	cout << "                                 输入你要购买的动物种类：" << endl;
	cout << "                                 1.两栖类    2.鱼类    3.鸟类" << endl;
	cout << "                                 4.爬行类              5.哺乳类" << endl;
	cout << "                                 请输入序号：";
}

list<Zoo_keeper> Zoo;     //存储园长的信息
list<Shopkeeper> stu;    //存储店主的信息 
list<Shopkeeper>::iterator shop;
ofstream ofs_shopkeeper;
list<Shopkeeper>::iterator S;
list<Shopkeeper>::iterator find(list<Shopkeeper>::iterator a1, list<Shopkeeper>::iterator a2, Shopkeeper &stu1)          //重载算法中find函数，使之能调用类对象的数据，而不仅仅是基本数据类型
{
	for (; a1 != a2; a1++)
	if (a1->Name == stu1.Name)
		break;
	return a1;

}
void Menu::old_shopkeeper()
{
	cout << "原有店主信息:" << endl;
	stu.push_back(Shopkeeper("葛庆", "19", 30, "猪脚饭", 15000, 8000, "优秀"));
	ofs_shopkeeper << "葛庆 ,19岁   职位： 猪脚饭店长   出售的食物价格 ：30元     每月月薪：  15000元    店面租金: 8000    信誉：  优秀  " << endl;
	Zoo_keeper::syz_money = Zoo_keeper::syz_money - 7500 - 4000;
	Zoo_keeper::syz_money = Zoo_keeper::syz_money - 7500 - 4000;
	for (shop = stu.begin(); shop != stu.end(); shop++)
	{
		shop->show();
	}
}
void Menu::Menu_shopkeeper()
{
	ofs_shopkeeper.open("C:\\Users\\ASUS\\Desktop\\万讯巴巴动物园\\shopkeeper.txt", ios::app);           //没当雇佣完店长后保存到文件里，在文本尾采用追加数据的方式 ios::app
	ofs_shopkeeper << "                             店长信息保存数据如下：" << endl;
	ofs_shopkeeper << endl;


	cout << "                                                   请输入功能序号：";
	int m;
	cin >> m;
	switch (m)
	{
	case 1:
		int number;
		cout << "决定聘用的人数：  ";
		cin >> number;
		for (int i = 0; i < number; i++)
		{
			string name;
			string life;
			int rent;    //每年要付的租金
			string reputation; //他们的信誉程度
			int food_price;  //定义食物价格
			string position;
			int get_money;
			cout << "姓名：";
			cin >> name;
			cout << "年龄: ";
			cin >> life;
			cout << "租金：";
			cin >> rent;
			cout << "食物价格：";
			cin >> food_price;
			cout << "职业: ";
			cin >> position;
			cout << "薪酬: ";
			cin >> get_money;
			cout << "信誉:";
			cin >> reputation;
			stu.push_back(Shopkeeper(name, life, food_price, position, get_money, rent, reputation));
			ofs_shopkeeper << name << "  " << life << "  职位： " << position << "  出售的食物价格:  " << food_price << " 元 " << "   每月薪酬: " << get_money << " 元 " << "  店面租金:  " << rent << "  信誉:  " << endl;
			Zoo_keeper::syz_money = Zoo_keeper::syz_money - get_money / 2 - (rent / 2);
			Zoo_keeper::syz_money = Zoo_keeper::syz_money - get_money / 2 - (rent / 2);
			Shopkeeper::person++;
			cout << endl;
		}
		cout << "显示最新雇佣的店主信息：" << endl;
		for (shop = stu.begin(); shop != stu.end(); shop++)
		{
			shop->show();
		}
		break;
	case 2:
	{
			  cout << "决定开除的店主：" << endl;
			  string name1;
			  cin >> name1;
			  Shopkeeper shop1(name1);
			  S = find(stu.begin(), stu.end(), shop1);        //重载算法中find函数  ，指针对应的是对象，在stu对象中查找与shop1对象具有相同名字的人
			  if (S == stu.end())
			  {
				  cout << "没有该店主！" << endl;
				  break;
			  }

			  else
			  {
				  cout << "************************" << endl;
				  cout << "存在该店主！" << endl;
				  cout << "显示该店主信息" << endl;
				  S->show();
				  cout << "************************" << endl;
				  S->Dismiss(name1);
				
				  cout << "清除其信息:" << endl;
				  S->show();
				  cout << endl;
				  cout << endl;
			  }
			  cout << "显示最新雇佣的店主信息：" << endl;
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
			cout << "输入有误！" << endl;
		//相应的数据
		break;
	}
}

void Menu::Menu_tourist()
{
	Tourist tourist;
	tourist.Need_Money();
	int Summary = 0; int infant = 0; int student = 0; int adult = 0; int Lovers = 0;
	cout << "旅游团团内游客个数" << endl;                        //抽象成一个旅游团
	cin >> Summary;
	int k = 0;
	cout << "有几种类型的游客：";
	cin >> k;
	cout << "幼儿个数：";
	cin >> infant;
	cout << "学生个数:";
	cin >> student;
	cout << "成年人个数:";
	cin >> adult;
	cout << "情侣数：";
	cin >> Lovers;  
	int summary = 0;                                  //追寻标记游客的总数量，用于while循环的判断
	list<Tourist*> INfant;                 //创建存放幼儿的容器,指针类型
	list<Tourist*>::iterator INfant1;      //创建访问幼儿数据的迭代器，指针类型
	list<Tourist*> Stu;                 //创建存放学生的容器,指针类型
	list<Tourist*>::iterator Stu1;      //创建访问学生数据的迭代器，指针类型                 
	list<Tourist*> ADult;                 //创建存放成人的容器,指针类型
	list<Tourist*>::iterator ADult1;      //创建访问成人数据的迭代器，指针类型     
	list<Tourist*> LOvers;              //创建访问情侣数据的迭代器，指针类型
	list<Tourist*>::iterator LOvers1;   //创建访问情侣数据的容器，指针类型
	ofstream ofs_tourist;
	ofs_tourist.open("C:\\Users\\ASUS\\Desktop\\万讯巴巴动物园\\tourist.txt", ios::app);                     //没当特定类型游客买完票后后保存到文件里，在文本尾采用追加数据的方式 ios::app
	ofs_tourist << "                            游客信息保存数据如下：" << endl;
	ofs_tourist << endl;
	while (summary <= Summary)
	{
	
		for (int w = 0; w < k; w++)
		{

			string TYPE = " ";                     //初始化游客类型
			cout << "**************************" << endl;
			cout << "输入购票的游客类型:   ";
			cin >> TYPE;
			if (TYPE == "幼儿")
			{
				for (int i = 0; i < infant; i++)
				{

					string name = ""; int life = 0; string identity = " "; int height = 0;
					cout << "姓名: ";
					cin >> name;
					cout << "年龄：";
					cin >> life;
					cout << "身份: ";
					cin >> identity;
					cout << "身高：";
					cin >> height;
					INfant.push_back(new Infant(name, life, identity, height));
					ofs_tourist << name << "  " << life << "  " << identity << "   身高： " << height << endl;
				}
				for (INfant1 = INfant.begin(); INfant1 != INfant.end(); INfant1++)
				{

					(*INfant1)->information();                            //通过指针类型的迭代器调用函数
					(*INfant1)->Need_Money();
				}

			}

			if (TYPE == "学生")
			{

				for (int j = 0; j < student; j++)
				{

					string name = ""; int life = 0; string identity = " "; int height = 0; string stu_id = " ";
					cout << "姓名: ";
					cin >> name;
					cout << "年龄：";
					cin >> life;
					cout << "身份: ";
					cin >> identity;
					cout << "是否带学生证：";
					cin >> stu_id;

					Stu.push_back(new Student(name, life, identity, stu_id));
					ofs_tourist << name << "  " << life << "  " << identity << "   是否带了学生证： " << stu_id << endl;
				}
				for (Stu1 = Stu.begin(); Stu1 != Stu.end(); Stu1++)
				{

					(*Stu1)->information();                            //通过指针类型的迭代器调用函数
					(*Stu1)->Need_Money();
				}

			}

			if (TYPE == "成人")
			{

				for (int k = 0; k < adult; k++)
				{

					string name = ""; int life = 0; string identity = " ";
					cout << "姓名: ";
					cin >> name;
					cout << "年龄：";
					cin >> life;
					cout << "身份: ";
					cin >> identity;

					ADult.push_back(new Adult(name, life, identity));
					ofs_tourist << name << "  " << life << "  " << identity << endl;
				}
				for (ADult1 = ADult.begin(); ADult1 != ADult.end(); ADult1++)
				{

					(*ADult1)->information();                            //通过指针类型的迭代器调用函数
					(*ADult1)->Need_Money();
				}

			}

			if (TYPE == "情侣")
			{

				for (int m = 0; m < Lovers; m++)
				{

					string name = ""; int life = 0; string identity = " "; int height = 0;
					cout << "姓名: ";
					cin >> name;
					cout << "年龄：";
					cin >> life;
					cout << "身份: ";
					cin >> identity;
					LOvers.push_back(new lovers(name, life, identity));
					ofs_tourist << name << "  " << life << "  " << identity << endl;
				}
				for (LOvers1 = LOvers.begin(); LOvers1 != LOvers.end(); LOvers1++)
				{

					(*LOvers1)->information();                            //通过指针类型的迭代器调用函数
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
	cout << "                                  欢迎司园长到来！    ";
	Zoo_keeper keeper1("司云中", 19);
	cout << "                  欢迎胡园长到来！" << endl;
	Zoo_keeper keeper2("胡志明", 19);
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

list<Animal*> amphibian;          //将容器和虚函数结合，采用基类指针或子类的指针声明
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
	Zoo_keeper::save_money = Zoo_keeper::Property / 2;              // 中间静态成员进行买动物资产和剩余钱的转换
	Zoo_keeper::syz_money = Zoo_keeper::Property / 2;                //将钱存入司园长和胡园长的账户
	Zoo_keeper::hgm_money = Zoo_keeper::Property / 2;
	ofstream ofs_animal;                                  //建立输入到文件的对象，然后每次买完动物之后保存到文件里，在文本尾采用追加数据的方式 ios::app                                          
	ofs_animal.open("C:\\Users\\ASUS\\Desktop\\万讯巴巴动物园\\animal.txt", ios::app);        //建立输入到文件的对象，然后每次买完动物之后保存到文件里，在文本尾采用追加数据的方式 ios::app
	ofs_animal << "                             购买的动物保存信息如下" << endl;
	ofs_animal << endl;
	switch (choise)
	{
	case 1:

		cout << "                                 输入要购买的两栖类动物" << endl;
		cout << "                         1.树蛙   2.卧龙蟾蜍    3.云南小峡口蛙   4.秦巴巴鲵" << endl;
		cout << "                         5.全部购买                              " << endl;
		cout << "                                 请输入序号：";
		cin >> choiseA;
		if (Zoo_keeper::syz_money >= Zoo_keeper::hgm_money)
		{
			cout << "司园长率先付钱进口动物！" << endl;
			if (choiseA == 1)
			{
				amphibian.push_back(new Amphibian("树蛙", "5年", "雄蛙体长42～44mm，雌蛙体长62mm左右", 8700));
				Zoo_keeper::syz_money -= 8700;
				ofs_animal << "树蛙  ，5年， 雄蛙体长42～44mm，雌蛙体长62mm左右，8700元" << endl;
				break;
			}
			if (choiseA == 2)
			{
				amphibian.push_back(new Amphibian("卧龙蟾蜍", "20年", "6厘米左右", 7900));
				Zoo_keeper::syz_money -= 7900;
				ofs_animal << "卧龙蟾蜍  ,20年 ,6厘米左右 ,  7900" << endl;
				break;
			}
			if (choiseA == 3)
			{
				amphibian.push_back(new Amphibian("云南小狭口蛙", "14年", "新成蛙体长12 mm", 5400));
				Zoo_keeper::syz_money -= 5400;
				ofs_animal << "云南小狭口蛙  , 14年, 新成蛙体长12 mm, 5400" << endl;
				break;
			}
			if (choiseA == 4)
			{
				amphibian.push_back(new Amphibian("泰巴巴鲵", "8年", "125cm", 10600));
				Zoo_keeper::syz_money -= 10600;
				ofs_animal << "泰巴巴鲵  , 8年, 125cm, 10600" << endl;
				break;
			}
			if (choiseA == 5)
			{

				amphibian.push_back(new Amphibian("树蛙", "5年", "雄蛙体长42～44mm，雌蛙体长62mm左右", 8700));
				amphibian.push_back(new Amphibian("卧龙蟾蜍", "20年", "6厘米左右", 7900));
				amphibian.push_back(new Amphibian("云南小狭口蛙", "14年", "新成蛙体长12 mm", 5400));
				amphibian.push_back(new Amphibian("泰巴巴鲵", "8年", "125cm", 10600));
				Zoo_keeper::syz_money = Zoo_keeper::syz_money - (8700 + 7900 + 5400 + 10600);
				ofs_animal << "树蛙  ，5年， 雄蛙体长42～44mm，雌蛙体长62mm左右，8700元" << endl;
				ofs_animal << "卧龙蟾蜍  ,20年 ,6厘米左右 ,  7900" << endl;
				ofs_animal << "云南小狭口蛙  , 14年, 新成蛙体长12 mm, 5400" << endl;
				ofs_animal << "泰巴巴鲵  , 8年, 125cm, 10600" << endl;
				break;
			}

		}
		if (choiseA > 5 || choiseA < 1)
			cout << "输入有误！" << endl;
		//相应的数据
		break;

	case 2:
		cout << "                                 输入要购买的鱼类动物" << endl;
		cout << "                         1.冰见寒狮      2.中华鲟     3.异龙鲤" << endl;
		cout << "                         4.全部购买                              " << endl;
		cout << "                                 请输入序号：";
		cin >> choiseB;
		cout << "此时胡园长钱多余司园长，所以胡园长担任起下一批的动物的进口" << endl;
		if (choiseB == 1)
		{
			fish.push_back(new Fish("冰见寒狮", "2年", "体长１米", 14302));
			Zoo_keeper::hgm_money -= 14302;
			ofs_animal << "冰见寒狮  , 2年, 体长１米, 14302" << endl;
			break;
		}
		if (choiseB == 2)
		{
			fish.push_back(new Fish("中华鲟", "3年", "体长平均约40厘米", 18888));
			Zoo_keeper::hgm_money -= 18888;
			ofs_animal << "中华鲟  , 3年, 体长平均约40厘米, 18888" << endl;
			break;
		}
		if (choiseB == 3)
		{
			fish.push_back(new Fish("异龙鲤", "1年", "体长约100-130毫米", 16888));
			Zoo_keeper::hgm_money -= 16888;
			ofs_animal << "异龙鲤  , 1年, 体长约100-130毫米, 16888" << endl;
			break;
		}
		if (choiseB == 4)
		{
			fish.push_back(new Fish("冰见寒狮", "2年", "体长１米", 14302));
			fish.push_back(new Fish("中华鲟", "3年", "体长平均约40厘米", 18888));
			fish.push_back(new Fish("异龙鲤", "1年", "体长约100-130毫米。", 16888));
			Zoo_keeper::hgm_money = Zoo_keeper::hgm_money - 14302 - 18888 - 16888;
			ofs_animal << "冰见寒狮  , 2年, 体长１米, 14302" << endl;
			ofs_animal << "中华鲟  , 3年, 体长平均约40厘米, 18888" << endl;
			ofs_animal << "异龙鲤  , 1年, 体长约100-130毫米, 16888" << endl;
			break;
		}

		if (choiseB > 4 || choiseB < 1)
			cout << "输入有误！" << endl;
		//相应的数据
		break;
	case 3:
		cout << "                                 输入要购买的鸟类动物" << endl;
		cout << "                         1.蜂鸟      2.鹦鹉     3.金腰燕     4.仙鹤" << endl;
		cout << "                         5.全部购买                              " << endl;
		cout << "                                 请输入序号：";
		cin >> choiseC;
		if (Zoo_keeper::syz_money >= Zoo_keeper::hgm_money)
		{
			cout << "司园长的资产比胡园长的多，所以这一次又司园长进购动物" << endl;
			if (choiseC == 1)
			{
				bird.push_back(new Bird("蜂鸟", " ", "体长在6-12厘米之间", 5120));
				ofs_animal << "蜂鸟  ,  , 体长在6-12厘米之间,  5120" << endl;
				Zoo_keeper::syz_money -= 5120;
				break;
			}
			if (choiseC == 2)
			{
				bird.push_back(new Bird("鹦鹉", " ", "体长可达100厘米", 2560));
				Zoo_keeper::syz_money -= 2560;
				ofs_animal << "鹦鹉  ,  , 体长可达100厘米, 2560" << endl;
				break;
			}
			if (choiseC == 3)
			{
				bird.push_back(new Bird("金腰燕", " ", "体长16-18厘米", 10240));
				Zoo_keeper::syz_money -= 10240;
				ofs_animal << "金腰燕  ,  , 体长16-18厘米, 10240" << endl;
				break;
			}
			if (choiseC == 4)
			{
				bird.push_back(new Bird("仙鹤", " ", "体长120-160厘米", 7700));
				Zoo_keeper::syz_money -= 7700;
				ofs_animal << "仙鹤  ,  , 体长120-160厘米, 7700" << endl;
				break;
			}
			if (choiseC == 5)
			{
				bird.push_back(new Bird("蜂鸟", " ", "体长在6-12厘米之间", 5120));
				bird.push_back(new Bird("鹦鹉", " ", "体长可达100厘米", 2560));
				bird.push_back(new Bird("金腰燕", " ", "体长16-18厘米", 10240));
				bird.push_back(new Bird("仙鹤", " ", "体长120-160厘米", 7700));
				Zoo_keeper::syz_money = Zoo_keeper::syz_money - 5120 - 2560 - 10240 - 7700;
				ofs_animal << "蜂鸟,  , 体长在6-12厘米之间, 16888" << endl;
				ofs_animal << "鹦鹉  ,  , 体长可达100厘米, 2560" << endl;
				ofs_animal << "金腰燕  ,  , 体长16-18厘米, 10240" << endl;
				ofs_animal << "仙鹤  ,  , 体长120-160厘米, 7700" << endl;
			}
		}
		else
		{
			cout << "胡园长资产比司园长资产多，所以这次由胡园长进购动物！" << endl;
			if (choiseC == 1)
			{
				bird.push_back(new Bird("蜂鸟", " ", "体长在6-12厘米之间", 5120));
				Zoo_keeper::hgm_money -= 5120;
				ofs_animal << "蜂鸟,  , 体长在6-12厘米之间, 16888" << endl;
				break;
			}
			if (choiseC == 2)
			{
				bird.push_back(new Bird("鹦鹉", " ", "体长可达100厘米", 2560));
				Zoo_keeper::hgm_money -= 2560;
				ofs_animal << "鹦鹉  ,  , 体长可达100厘米, 2560" << endl;
				break;
			}
			if (choiseC == 3)
			{
				bird.push_back(new Bird("金腰燕", " ", "体长16-18厘米", 10240));
				Zoo_keeper::hgm_money -= 10240;
				ofs_animal << "金腰燕  ,  , 体长16-18厘米, 10240" << endl;
				break;
			}
			if (choiseC == 4)
			{
				bird.push_back(new Bird("仙鹤", " ", "体长120-160厘米", 7700));
				Zoo_keeper::hgm_money -= 7700;
				ofs_animal << "仙鹤  ,  , 体长120-160厘米, 7700" << endl;
				break;
			}
			if (choiseC == 5)
			{
				bird.push_back(new Bird("蜂鸟", " ", "体长在6-12厘米之间", 5120));
				bird.push_back(new Bird("鹦鹉", " ", "体长可达100厘米", 2560));
				bird.push_back(new Bird("金腰燕", " ", "体长16-18厘米", 10240));
				bird.push_back(new Bird("仙鹤", " ", "体长120-160厘米", 7700));
				Zoo_keeper::hgm_money = Zoo_keeper::hgm_money - 5120 - 2560 - 10240 - 7700;
				ofs_animal << "蜂鸟,  , 体长在6-12厘米之间, 16888" << endl;
				ofs_animal << "鹦鹉  ,  , 体长可达100厘米, 2560" << endl;
				ofs_animal<< "金腰燕  ,  , 体长16-18厘米, 10240" << endl;
				ofs_animal << "仙鹤  ,  , 体长120-160厘米, 7700" << endl;
			}
		}

		if (choiseC > 5 || choiseC < 1)
			cout << "输入有误！" << endl;
		//相应的数据
		break;
	case 4:
		cout << "                                 输入要购买的爬行类动物" << endl;
		cout << "                    1.棱皮蛇龟      2.科莫多巨蜥     3.网纹蟒     4.亚马逊森蚺      5.咸水鳄" << endl;
		cout << "                    6.全部购买                              " << endl;
		cout << "                                 请输入序号：";
		cin >> choiseD;
		if (Zoo_keeper::syz_money >= Zoo_keeper::hgm_money)
		{
			cout << "司园长的资产比胡园长的多，所以这一次又司园长进购动物!" << endl;
			if (choiseD == 1)
			{
				reptiles.push_back(new Reptiles("棱皮海龟", " ", "生长至9英尺长", 13400));
				Zoo_keeper::syz_money -= 13400;
				ofs_animal << "棱皮海龟  ,  , 生长至9英尺长, 价值13400元" << endl;
				break;
			}
			if (choiseD == 2)
			{
				reptiles.push_back(new Reptiles("科莫多巨蜥 ", " ", "平均体长2—3米", 12600));
				Zoo_keeper::syz_money -= 12600;
				ofs_animal << "科莫多巨蜥  ,  , 平均体长2—3米, 价值12600元" << endl;
				break;
			}
			if (choiseD == 3)
			{
				reptiles.push_back(new Reptiles("网纹蟒", " ", "长仅为1.5米-2.3米", 10086));
				Zoo_keeper::syz_money -= 10086;
				ofs_animal << "网纹蟒  ,  , 长仅为1.5米-2.3米, 价值10086元" << endl;
				break;
			}
			if (choiseD == 4)
			{
				reptiles.push_back(new Reptiles("亚马逊森蚺", " ", "最长可达十米", 11526));
				Zoo_keeper::syz_money -= 11526;
				ofs_animal << "亚马逊森蚺  ,  , 最长可达十米, 价值11526元" << endl;
				break;
			}
			if (choiseD == 5)
			{
				reptiles.push_back(new Reptiles("咸水鳄", " ", "成体一般长3～5米，最长可达7米以上", 7600));
				Zoo_keeper::syz_money -= 7600;
				ofs_animal << "咸水鳄  ,  , 成体一般长3～5米，最长可达7米以上, 价值7600元" << endl;
				break;

			}
			if (choiseD == 6)
			{
				reptiles.push_back(new Reptiles("棱皮海龟", " ", "生长至9英尺长", 13400));
				reptiles.push_back(new Reptiles("科莫多巨蜥 ", " ", "平均体长2—3米", 12600));
				reptiles.push_back(new Reptiles("网纹蟒", " ", "长仅为1.5米-2.3米", 10086));
				reptiles.push_back(new Reptiles("亚马逊森蚺", " ", "最长可达十米", 11526));
				reptiles.push_back(new Reptiles("咸水鳄", " ", "成体一般长3～5米，最长可达7米以上", 7600));
				Zoo_keeper::syz_money = Zoo_keeper::syz_money - 13400 - 12600 - 10086 - 11526 - 7600;
				ofs_animal << "棱皮海龟  ,  , 生长至9英尺长, 价值13400元" << endl;
				ofs_animal << "科莫多巨蜥  ,  , 平均体长2—3米, 价值12600元" << endl;
				ofs_animal << "网纹蟒  ,  , 长仅为1.5米-2.3米, 价值10086元" << endl;
				ofs_animal << "亚马逊森蚺  ,  , 最长可达十米, 价值11526元" << endl;
				ofs_animal << "咸水鳄  ,  , 成体一般长3～5米，最长可达7米以上, 价值7600元" << endl;
				break;
			}
		}
		else
		{

			cout << "胡园长资产比司园长资产多，所以这次由胡园长进购动物！" << endl;
			if (choiseD == 1)
			{
				reptiles.push_back(new Reptiles("棱皮海龟", " ", "生长至9英尺长", 13400));
				Zoo_keeper::hgm_money -= 13400;
				ofs_animal << "棱皮海龟  ,  , 生长至9英尺长, 价值13400元" << endl;
				break;
			}
			if (choiseD == 2)
			{
				reptiles.push_back(new Reptiles("科莫多巨蜥 ", " ", "平均体长2—3米", 12600));
				Zoo_keeper::hgm_money -= 12600;
				ofs_animal << "科莫多巨蜥  ,  , 平均体长2—3米, 价值12600元" << endl;
				break;
			}
			if (choiseD == 3)
			{
				reptiles.push_back(new Reptiles("网纹蟒", " ", "长仅为1.5米-2.3米", 10086));
				Zoo_keeper::hgm_money -= 10086;
				ofs_animal << "网纹蟒  ,  , 长仅为1.5米-2.3米, 价值10086元" << endl;
				break;
			}
			if (choiseD == 4)
			{
				reptiles.push_back(new Reptiles("亚马逊森蚺", " ", "最长可达十米", 11526));
				Zoo_keeper::hgm_money -= 11526;
				ofs_animal << "亚马逊森蚺  ,  , 最长可达十米, 价值11526元" << endl;
				break;
			}
			if (choiseD == 5)
			{
				reptiles.push_back(new Reptiles("咸水鳄", " ", "成体一般长3～5米，最长可达7米以上", 7600));
				Zoo_keeper::hgm_money -= 7600;
				ofs_animal << "咸水鳄  ,  , 成体一般长3～5米，最长可达7米以上, 价值7600元" << endl;
				break;
			}
			if (choiseD == 6)
			{
				reptiles.push_back(new Reptiles("棱皮海龟", " ", "生长至9英尺长", 13400));
				reptiles.push_back(new Reptiles("科莫多巨蜥 ", " ", "平均体长2—3米", 12600));
				reptiles.push_back(new Reptiles("网纹蟒", " ", "长仅为1.5米-2.3米", 10086));
				reptiles.push_back(new Reptiles("亚马逊森蚺", " ", "最长可达十米", 11526));
				reptiles.push_back(new Reptiles("咸水鳄", " ", "成体一般长3～5米，最长可达7米以上", 7600));
				Zoo_keeper::hgm_money = Zoo_keeper::hgm_money - 13400 - 12600 - 10086 - 11526 - 7600;
				ofs_animal << "棱皮海龟  ,  , 生长至9英尺长, 价值13400元" << endl;
				ofs_animal << "科莫多巨蜥  ,  , 平均体长2—3米, 价值12600元" << endl;
				ofs_animal << "网纹蟒  ,  , 长仅为1.5米-2.3米, 价值10086元" << endl;
				ofs_animal << "亚马逊森蚺  ,  , 最长可达十米, 价值11526元" << endl;
				ofs_animal << "咸水鳄  ,  , 成体一般长3～5米，最长可达7米以上, 价值7600元" << endl;
				break;
			}
		}
		if (choiseD > 6 || choiseD < 1)
			cout << "输入有误！" << endl;
		//相应的数据
		break;
	case 5:
		cout << "                                 输入要购买的哺乳类动物" << endl;
		cout << "                    1.熊猫      2.孟加拉虎     3.树懒     4.竹鼠      5.白头叶猴" << endl;
		cout << "                    6.全部购买                              " << endl;
		cout << "                                 请输入序号：";
		cin >> choiseE;
		if (Zoo_keeper::syz_money >= Zoo_keeper::hgm_money)
		{
			cout << "司园长的资产比胡园长的多，所以这一次又司园长进购动物!" << endl;
			if (choiseE == 1)
			{
				cout << "国宝无价之宝，不能购买！" << endl;
				//mammal.push_back(new Mammal("熊猫", " ", "头躯长1.2-1.8米，尾长10-12厘米 ", 99999999));
				break;
			}
			if (choiseE == 2)
			{
				mammal.push_back(new Mammal("孟加拉虎", " ", "孟加拉虎雄性肩高90-110厘米，平均体长290厘米", 14320));
				Zoo_keeper::syz_money -= 14320;
				ofs_animal << "孟加拉虎  ,  , 孟加拉虎雄性肩高90-110厘米，平均体长290厘米, 价值14320元" << endl;
				break;
			}
			if (choiseE == 3)
			{
				mammal.push_back(new Mammal("树懒", " ", "较小", 6400));
				Zoo_keeper::syz_money -= 6400;
				ofs_animal << "树懒  ,  , 较小, 价值6400元" << endl;
				break;
			}
			if (choiseE == 4)
			{
				mammal.push_back(new Mammal("竹鼠", " ", " 竹鼠成体长约30～40厘米  大竹鼠的体长可达45厘米", 2600));
				Zoo_keeper::syz_money -= 2600;
				ofs_animal << "竹鼠  ,  , 竹鼠成体长约30～40厘米  大竹鼠的体长可达45厘米, 价值2600元" << endl;
				break;
			}
			if (choiseE == 5)
			{
				mammal.push_back(new Mammal("白头叶猴", " ", "该物种体长为50-70厘米，尾长60-80厘米", 12888));
				Zoo_keeper::syz_money -= 12888;
				ofs_animal << "白头叶猴  ,  , 该物种体长为50-70厘米，尾长60-80厘米, 价值12888元" << endl;
				break;
			}
			if (choiseE == 6)
			{
				cout << "熊猫是国宝，不能购买，抱歉~~" << endl;
				mammal.push_back(new Mammal("孟加拉虎", " ", "孟加拉虎雄性肩高90-110厘米，平均体长290厘米", 14320));
				mammal.push_back(new Mammal("树懒", " ", "较小", 6400));
				mammal.push_back(new Mammal("竹鼠", " ", " 竹鼠成体长约30～40厘米  大竹鼠的体长可达45厘米", 2600));
				mammal.push_back(new Mammal("白头叶猴", " ", "该物种体长为50-70厘米，尾长60-80厘米", 12888));
				Zoo_keeper::syz_money = Zoo_keeper::syz_money - 14320 - 6400 - 2600 - 12888;
				ofs_animal << "孟加拉虎  ,  , 孟加拉虎雄性肩高90-110厘米，平均体长290厘米, 价值14320元" << endl;
				ofs_animal << "树懒  ,  , 较小, 价值6400元" << endl;
				ofs_animal << "竹鼠  ,  , 竹鼠成体长约30～40厘米  大竹鼠的体长可达45厘米, 价值2600元" << endl;
				ofs_animal << "白头叶猴  ,  , 该物种体长为50-70厘米，尾长60-80厘米, 价值12888元" << endl;
				break;
			}
		}
		else
		{
			cout << "胡园长资产比司园长资产多，所以这次由胡园长进购动物！" << endl;
			if (choiseE == 1)
			{
				cout << "国宝无价之宝，不能购买！" << endl;
				//mammal.push_back(new Mammal("熊猫", " ", "头躯长1.2-1.8米，尾长10-12厘米 ", 99999999));
				ofs_animal << "孟加拉虎  ,  , 孟加拉虎雄性肩高90-110厘米，平均体长290厘米, 价值14320元" << endl;
				break;
			}
			if (choiseE == 2)
			{
				mammal.push_back(new Mammal("孟加拉虎", " ", "孟加拉虎雄性肩高90-110厘米，平均体长290厘米", 14320));
				Zoo_keeper::hgm_money -= 14320;
				ofs_animal << "孟加拉虎  ,  , 孟加拉虎雄性肩高90-110厘米，平均体长290厘米, 价值14320元" << endl;
				break;
			}
			if (choiseE == 3)
			{
				mammal.push_back(new Mammal("树懒", " ", "较小", 6400));
				Zoo_keeper::hgm_money -= 6400;
				ofs_animal << "树懒  ,  , 较小, 价值6400元" << endl;
				break;
			}
			if (choiseE == 4)
			{
				mammal.push_back(new Mammal("竹鼠", " ", " 竹鼠成体长约30～40厘米  大竹鼠的体长可达45厘米", 2600));
				Zoo_keeper::hgm_money -= 2600;
				ofs_animal << "竹鼠  ,  , 竹鼠成体长约30～40厘米  大竹鼠的体长可达45厘米, 价值2600元" << endl;
				break;
			}
			if (choiseE == 5)
			{
				mammal.push_back(new Mammal("白头叶猴", " ", "该物种体长为50-70厘米，尾长60-80厘米", 12888));
				Zoo_keeper::hgm_money -= 12888;
				ofs_animal << "白头叶猴  ,  , 该物种体长为50-70厘米，尾长60-80厘米, 价值12888元" << endl;
				break;
			}
			if (choiseE == 6)
			{
				cout << "熊猫是国宝，不能购买，抱歉~~" << endl;
				mammal.push_back(new Mammal("孟加拉虎", " ", "孟加拉虎雄性肩高90-110厘米，平均体长290厘米", 14320));
				mammal.push_back(new Mammal("树懒", " ", "较小", 6400));
				mammal.push_back(new Mammal("竹鼠", " ", " 竹鼠成体长约30～40厘米  大竹鼠的体长可达45厘米", 2600));
				mammal.push_back(new Mammal("白头叶猴", " ", "该物种体长为50-70厘米，尾长60-80厘米", 12888));
				Zoo_keeper::hgm_money = Zoo_keeper::hgm_money - 14320 - 6400 - 2600 - 12888;
				ofs_animal << "孟加拉虎  ,  , 孟加拉虎雄性肩高90-110厘米，平均体长290厘米, 价值14320元" << endl;
				ofs_animal << "树懒  ,  , 较小, 价值6400元" << endl;
				ofs_animal << "竹鼠  ,  , 竹鼠成体长约30～40厘米  大竹鼠的体长可达45厘米, 价值2600元" << endl;
				ofs_animal << "白头叶猴  ,  , 该物种体长为50-70厘米，尾长60-80厘米, 价值12888元" << endl;
				break;
			}
		}
		if (choiseE > 6 || choiseE < 1)
			cout << "输入有误！" << endl;
		//相应的数据
		break;
		ofs_animal.close();
	default:
		cout << "输入有误！" << endl;
		break;
	}
}

void Menu::Menu_animal_show()
{
	string animal_type;
	cout << "输入要查询的动物类别：" << endl;
	cin >> animal_type;
	if (animal_type == "两栖类")
	for (amp = amphibian.begin(); amp != amphibian.end(); amp++)
	{
		(*amp)->display();
		cout << "买动物花费的钱" << (*amp)->get_money() << "元" << endl;
	}
	else if (animal_type == "鱼类")
	for (fi = fish.begin(); fi != fish.end(); fi++)
	{
		(*fi)->display();
		cout << "买动物花费的钱" << (*fi)->get_money() << "元" << endl;
	}
	else if (animal_type == "鸟类")
	for (bi = bird.begin(); bi != bird.end(); bi++)
	{
		(*bi)->display();
		cout << "买动物花费的钱" << (*bi)->get_money() << "元" << endl;
	}
	else if (animal_type == "爬行类")
	for (re = reptiles.begin(); re != reptiles.end(); re++)
	{
		(*re)->display();
		cout << "买动物花费的钱" << (*re)->get_money() << "元" << endl;
	}
	else if (animal_type == "哺乳类")
	for (ma = mammal.begin(); ma != mammal.end(); ma++)
	{
		(*ma)->display();
		cout << "买动物花费的钱" << (*ma)->get_money() << "元" << endl;
	}
	else
		cout << "没有该类型的动物，查找失败！" << endl;
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
	ofs.open("C:\\Users\\ASUS\\Desktop\\万讯巴巴动物园\\a.txt", ios::out);
	if (ofs)
	{
		ofs << amphibian << endl;
	}
	ofs.close();
}*/
#endif   