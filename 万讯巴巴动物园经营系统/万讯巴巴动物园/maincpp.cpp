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
	cout << "    · · ·		                                        " << endl;
	cout << " ·  两栖动物   ·	               *        *                  · · ·  \n";
	cout << "    · · ·                    *    *   *    *   ************·  鱼类动物   ·   \n";
	cout << "       **                     *        *        *                · · ·" << endl;
	cout << "         *******       · · ·                       \n";
	cout << "                *  ·  鸟类动物   ·                        \n";
	cout << "                 *     · · ·                                                            · · ·                                             \n";
	cout << "                  *        *                                ***************************·  哺乳类动物   ·                        \n";
	cout << "                   *       *                               *                              · · ·                      \n";
	cout << "                     ****                                *                                                                                           \n";
	cout << "                          *                              *                                                                \n";
	cout << "                            *                          *                                       · · ·                           \n";
	cout << "                              *                     *                                       *·  奶茶店   ·                                                          \n";
	cout << "                                 *                *                                       *    · · ·                          \n";
	cout << "                                      · · ·                                         *                                       \n";
	cout << "                                   ·  爬行类动物   ·                              *                                                      \n";
	cout << "                                      · · ·      *                              *                                             \n";
	cout << "                                   *                  *            *  *         *     *                                       \n";
	cout << "                                 *                      *        *      *    *          *                                     \n";
	cout << "                                *                         *    *          *               *      · · ·                                \n";
	cout << "                             · · ·                                                        * ·  猪脚饭店   ·                               \n";
	cout << "                          ·  咖啡店   ·                                                         · · ·                        \n";
	cout << "                             · · ·                                                                 *                            \n";
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
	cout << "                                                         *           ↓         *                                         \n";
	cout << "                                                         *         你在这       *                                         \n";
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
				  cout << "已存入文件中!" << endl;
				  break;
		}
		case 7:
			exit(0);
		default:
			cout << "请在1-6功能选项內重新输入！" << endl;
			system("pause");
			break;
		}
	}
	system("pause");
	return 0;
}