#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>



//定义结构体
typedef struct {
    char name[30];  // 物品名
    char code[8];   // 物品条码
    double price;   // 物品价格
} Item;

//初始化商品数据
Item items[] = {
    {"Cola", "001", 3.50},
    {"Lollipop", "002", 0.50},
    {"Noodles", "003", 6.00},
};




//主函数
int main()
{
	int choice = 0;
	int a = 1;
	char buy_code[8];
	int buying = 1;
	double allprice = 0;
	int mount_cola = 0;
	int mount_lollipop = 0;
	int mount_noodles = 0;


again:

	printf("\n欢迎来到七一一便利店\n");
	printf("1.price\n2.checkout\n3.exit\n");
	printf("请选择：");

	while (a)
	{
		scanf("%d", &choice);

		switch (choice)
		{
			//购买部分
		case 1:

			while (buying)
			{
				//显示所有商品
				printf("\n-------------------菜单------------------\n");

				for (int i = 0;i < 3; i++)
				{
					printf("名称：%-6s | 编号：%-6s | 价格：%.2f \n", items[i].name, items[i].code, items[i].price);
				}
				printf("-----------------------------------------\n");
				printf("请输入相应的操作：");

				//输入0返回
				scanf("%s", &buy_code);

				//选择商品，计算总价
				while (1)
				{
					if (strcmp(buy_code, "0") == 0)
					{
						goto again;
					}

					if (strcmp(buy_code,"001") == 0)


					{
						allprice += 3.50f;
						printf("已购买cola，总价为%.2f\n", allprice);
						mount_cola++;
						break;
					}

					else if (strcmp(buy_code,"002") == 0)
					{
						allprice += 0.50;
						printf("已购买lollipop，总价为%.2f\n", allprice);
						mount_lollipop++;
						break;
					}

					else if (strcmp(buy_code,"003") == 0)
					{
						allprice += 6.00;
						printf("已购买noodles，总价为%.2f\n", allprice);
						mount_noodles++;
						break;
					}

					//清空购物车
					else if (strcmp(buy_code, "drop") == 0)
					{
						mount_cola = 0;
						mount_lollipop = 0;
						mount_noodles = 0;
						allprice = 0;
						printf("购物车已清空，总价为%.2f\n", allprice);
						break;
					}

					//删除物品
					else if (strcmp(buy_code, "-001") == 0)
					{
						allprice -= 3.50f;
						printf("已删除cola，总价为%.2f\n", allprice);
						mount_cola--;
						break;
					}

					else if (strcmp(buy_code, "-002") == 0)
					{
						allprice -= 0.50;
						printf("已删除lollipop，总价为%.2f\n", allprice);
						mount_lollipop--;
						break;
					}

					else if (strcmp(buy_code, "-003") == 0)
					{
						allprice -= 6.00;
						printf("已删除noodles，总价为%.2f\n", allprice);
						mount_noodles--;
						break;
					}






					else
						printf("\n\n输入错误，请重新输入编号");
					break;

				}
			}
			break;

			//打印小票部分
		case 2:
			printf("                小票                 \n");
			printf("-------------------------------------\n");
			printf("名称\t数量\t单价\t总价\n");
			printf("%-6s\t%-6d\t%.2f\t%.2f\n", items[0].name, mount_cola, items[0].price, mount_cola * items[0].price);
			printf("%-6s%-6d\t%.2f\t%.2f\n", items[1].name, mount_lollipop, items[1].price, mount_lollipop * items[1].price);
			printf("%-6s\t%-6d\t%.2f\t%.2f\n", items[2].name, mount_noodles, items[2].price, mount_noodles * items[2].price);
			printf("-------------------------------------\n");

			printf("总价为：%.2f\n", allprice);
			printf("请支付\n\n\n");
			goto again;

			//输入3直接退出
		case 3:
			a--;
			break;

		default:
			printf("输入错误，请重新输入：");
			break;

		}
	}
}














































































































































































































































































