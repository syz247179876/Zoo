#include<iostream>
#include<string>
#include<list>
#include<algorithm>
#include<functional>
#include<numeric>
#include<fstream>
#include"Animal.h"
using namespace std;
int main()
{
	cout << "    �� �� ��		                                        " << endl;
	cout << " ��  ���ܶ���   ��	               *        *                  �� �� ��  \n";
	cout << "    �� �� ��                    *    *   *    *   ************��  ���ද��   ��   \n";
	cout << "       **                     *        *        *                �� �� ��" << endl;
	cout << "         *******       �� �� ��                       \n";
	cout << "                *  ��  ���ද��   ��                        \n";
	cout << "                 *     �� �� ��                                                            �� �� ��                                             \n";
	cout << "                  *        *                                ***************************��  �����ද��   ��                        \n";
	cout << "                   *       *                               *                              �� �� ��                      \n";
	cout << "                     ****                                *                                                                                           \n";
	cout << "                          *                              *                                                                \n";
	cout << "                            *                          *                                       �� �� ��                           \n";
	cout << "                              *                     *                                       *��  �̲��   ��                                                          \n";
	cout << "                                 *                *                                       *    �� �� ��                          \n";
	cout << "                                      �� �� ��                                         *                                       \n";
	cout << "                                   ��  �����ද��   ��                              *                                                      \n";
	cout << "                                      �� �� ��      *                              *                                             \n";
	cout << "                                   *                  *            *  *         *     *                                       \n";
	cout << "                                 *                      *        *      *    *          *                                     \n";
	cout << "                                *                         *    *          *               *      �� �� ��                                \n";
	cout << "                             �� �� ��                                                        * ��  ��ŷ���   ��                               \n";
	cout << "                          ��  ���ȵ�   ��                                                         �� �� ��                        \n";
	cout << "                             �� �� ��                                                                 *                            \n";
	cout << "                                   *                                                                *                       \n";
	cout << "                                     *                                                            *                        \n";
	cout << "                                       *                                                        *                          \n";
	cout << "                                         *                                                    *                           \n";
	cout << "                                           *                                               *                            \n";
	cout << "                                              *                                          *                              \n";
	cout << "                                                 *                                     *                               \n";
	cout << "                                                    *                                *                                   \n";
	cout << "                                                      *                           *                                     \n";
	cout << "                                                         *                       *                                      \n";
	cout << "                                                         *                      *                                        \n";
	cout << "                                                         *           ��         *                                         \n";
	cout << "                                                         *         ������       *                                         \n";
	cout << "                                                         *                      *                                         \n";

	system("color 0F");
	Menu menu;
	int m = 0;
	while (1){
		menu.Menu_main();
		cin >> m;
		switch (m)
		{
		case 1:
		{	
				  menu.Menu_buymenu();
				menu.Menu_animal_buy();	  
				  break;
		}
		case 2:
			menu.Menu_animal_show();
			break;
		case 3:
		{
				  if (Shopkeeper::person == 1)
				  {
					  menu.old_shopkeeper();
					  menu.ShopKeeper();
					  menu.Menu_shopkeeper();
				  }
				  else
				  {
					  menu.ShopKeeper();
					  menu.Menu_shopkeeper();
				  }
				  break;
		}
		case 4:
		{
				
				  menu.Menu_tourist();
				  break;
		}
		case 5:
		{
		
				  menu.Menu_zookeeper();
				  break;
		}
		case 6:
		{
				  cout << "�Ѵ����ļ���!" << endl;
				  break;
		}
		case 7:
			exit(0);
		default:
			cout << "����1-6����ѡ����������룡" << endl;
			system("pause");
			break;
		}
	}
	system("pause");
	return 0;
}