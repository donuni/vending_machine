#include<stdio.h>
#include<Windows.h>
void input_print(void);
int question(void);
int inventory[5]={0,30,30,30,30};
int topping_inventory[4]={0,30,30,30};
int topping_count[4]={0};
int price[5]={0,2500,2300,2000,2600};
int price_topping[4]={0,500,300,700};
int total_money=0;
char*productName[5]={"0","�Ŷ��","�ȼ�����","�����","�ʱ���"};
char*toppingName[4]={"����","�ް�","��","�Ҽ���"};
int print_menu(void);
int print_topping1(void);
int print_topping2(void);
void input_money(void);
void finish1 (int number,int toping_number, int select);
void finish2 (int number,int toping_number1,int toping_number2, int select);
void sound (void);

int main()
{
	int anser=0;
	int number=0;
	int toping_number1=0;
	int toping_number2=0;
	char select=0;

   for(;;)
   {
	    input_print();
		input_money();
		printf ("\n���Աݾ� %5d\n", total_money);
		number=print_menu();
		if (number==0) 
		{
			if (total_money>0)
			{
				printf ("\n%d ���� ��ȯ�ϰ� �����մϴ�.",total_money);
				total_money=0;
			}
			break;
		}
		toping_number1=print_topping1();
		if (toping_number1>0) anser= question();
		if (anser=='y')
		toping_number2=print_topping2();

		if (toping_number2>0)
		finish2 (number, toping_number1, toping_number2, select);
		else
		finish1 (number, toping_number1, select);
		printf ("\n�����մϴ� ����");
		break;
   }
   
   getchar ();
   getchar ();
   getchar ();
   getchar ();
   return 0;
}

void input_print(void)
{
	printf ("����������������������������������������\n");
	printf ("������                                      ��                  ������\n");
	printf ("������           ���� ��� ���Ǳ�           ��  �߰� ����+      ������\n");
	printf ("������                                      ��                  ������\n");
	printf ("������                                      ��  �� �ް�   500   ������\n");
	printf ("������  ��Ŷ��� 2500  ��ȼ������ 2300  ��                  ������\n");
	printf ("������                                      ��  �� ��     300   ������\n");
	printf ("������  �������� 2000  ��ʱ���  �� 2600  ��                  ������\n");
	printf ("������                                      ��  �� �Ҽ��� 700   ������\n");
	printf ("������                                      ��                  ������\n");
	printf ("����������������������������������������\n");
}

int print_menu(void)
{
   int number=0; 
   printf("\n����� ������ �ּ���. \n\n��Ŷ��: %d�� ��ȼ�����: %d���������: %d�� ��ʱ���%: %d�� 0. ��ü��ҹ�ư\n",inventory[1],inventory[2],inventory[3],inventory[4]);
   for(;;)
   {
	  for(;;)
	  {
      printf("\n1������ 4������ ��ǰ��ȣ�� �����ϼ���.");
      scanf("%d",&number);
	  if(number>=0&&number<=4) break;
	  }
      if(number>=1&&number<=4)
      {
         if(inventory[number]<=0)
         {
            printf("\n%s�� %d���� ǰ���Դϴ�.�ٽ� �Է����ּ���",productName[number],inventory[number]);
            continue;
         }
		 break;
	  }
	  if (number==0) break;
   }
   return number;
}

void input_money(void)
{
	int money=0;
	char select =0;
	for (;;)
	{
		for(;;)
		{
			printf ("\n���Աݾ� %5d �ݾ����� 100, 500, 1000, 5000, 10000�� �Է� ", total_money);
			scanf ("%d",&money);
			if(money==100||money==500||money==1000||money==5000||money==10000) break;
			else printf ("\n\n�߸��� �ݾ��Դϴ�.  �Ѿ׿� �ݿ����� �ʽ��ϴ�.\n"); 
		}
		total_money= total_money + money;
		printf ("\n�ݾ��� �� �Է��Ͻðڽ��ϱ�?(y/n)");
		while(getchar()!='\n');
		scanf ("%c",&select);
		
		if (select=='y')
		{
			continue;
		}
		else if (select=='n')
		{
			break;
		}
		else
		{
			continue;
		}
	}
}


int print_topping1(void)
{
	int number=0; 
	char select=0;
	printf("\n������ ������ �ּ���. \n\n1.�ް�: %d�� 2.��: %d�� 3.�Ҽ���: %d�� 0.������������ \n",topping_inventory[1],topping_inventory[2],topping_inventory[3]);
	for(;;)
	{
		for(;;)
		{
			printf("\n1������ 3������ ���ι�ȣ�� �����ϼ���.");
			scanf("%d",&number);
			if (number>=0&&number<=3) break;
		}
		if (number<=0) break;
		if(number>=1&&number<=3)
		{
			topping_count[number]++;

			if(topping_inventory[number]<=0)
			{
			printf("\n%s�� %d���� ǰ���Դϴ�.�ٽ� �Է����ּ���",toppingName[number],topping_inventory[number]);
			continue;
			}
			break;
		}
	}
   return number;
}

int print_topping2(void)
{
	int number=0; 
	char select=0;

	printf("\n������ ������ �ּ���. \n\n1.�ް�: %d�� 2.��: %d�� 3.�Ҽ���: %d�� 0.������������ \n",topping_inventory[1],topping_inventory[2],topping_inventory[3]);
	for(;;)
	{
		for(;;)
		{
			printf("\n1������ 3������ ���ι�ȣ�� �����ϼ���.");
			scanf("%d",&number);
			if (number>=0&&number<=3) break;
		}
		if (number<=0) break;
		if(number>=1&&number<=3)
		{
			topping_count[number]++;
			if(topping_inventory[number]<=0)
			{
			printf("\n%s�� %d���� ǰ���Դϴ�.�ٽ� �Է����ּ���",toppingName[number],topping_inventory[number]);
			continue;
			}
			break;
		}
	}
   return number;
}

int question(void)
{
	char val=0;
	for(;;)
	{
		printf ("\n������ �� �߰��Ͻðڽ��ϱ�?(y/n)");
		while(getchar()!='\n');
		scanf ("%c",&val);
		if (val == 'y' || val == 'n')break;
		else printf ("\n�ٽ� �Է��ϼ���\n");
	}
	return val;

}

void finish1 (int number, int toping_number1, int select)
{
	int toping_number2=0;
	char anser=0;
	
	for (;;)
	{
		if(total_money<price[number]+price_topping[toping_number1])
		{
			printf ("\n���Աݾ��� �����մϴ�. ���� �� �������ּ���.");
			input_money();
		}
		else
		{
			sound ();
			printf ("\n%s����(��) ���Խ��ϴ�.(����: %s)",productName[number],toppingName[toping_number1]);
			total_money= total_money-price[number]-price_topping[toping_number1];
			inventory[number]--;
			topping_inventory[toping_number1]--;
			topping_count[toping_number1]--;
			for(;;)
			{
				printf ("\n\n�����ݾ�: %d, �� �ֹ��Ͻðڽ��ϱ�?(y/n)",total_money);
				while(getchar()!='\n');
				scanf ("%c",&select);
				if (select == 'y' || select == 'n') break;
				else printf ("\n�ٽ� �Է��ϼ���\n");
			}
			if (select=='y')
			{
				number=print_menu();
				toping_number1=print_topping1();
				if (toping_number1>0) anser= question();
				if (anser=='n') continue;
				if (anser=='y') toping_number2=print_topping2();

				if (toping_number2>0) continue;
			}
			if (select=='n')
			{
				printf ("\n%d ���� ��ȯ�ϰ� �����մϴ�.\n",total_money);
				total_money=0;
				break;
			}
		}
	}	

}

void finish2 (int number,int toping_number1,int toping_number2, int select)
{
	char anser=0;
	
	for (;;)
	{
		if(total_money<price[number]+price_topping[toping_number1]+price_topping[toping_number2])
		{
			printf ("\n���Աݾ��� �����մϴ�. ���� �� �������ּ���.");
			input_money();
		}
		else
		{
			if(toping_number1==toping_number2)
			{
				sound ();
				printf ("\n%s ����(��) ���Խ��ϴ�.(����: %s %d��)",productName[number],toppingName[toping_number1],topping_count[toping_number1]);
			}
			else
			{
				sound ();
				printf ("\n%s ����(��) ���Խ��ϴ�.(����: %s, %s)",productName[number],toppingName[toping_number1],toppingName[toping_number2]);
			}
			total_money= total_money-price[number]-price_topping[toping_number1]-price_topping[toping_number2];
			inventory[number]--;
			topping_inventory[toping_number1]--;
			topping_inventory[toping_number2]--;
			topping_count[toping_number1]--;
			topping_count[toping_number2]--;
			for(;;)
			{
				printf ("\n\n�����ݾ�: %d, �� �ֹ��Ͻðڽ��ϱ�?(y/n)",total_money);
				while(getchar()!='\n');
				scanf ("%c",&select);
				if (select == 'y' || select == 'n')break;
				else printf ("\n�ٽ� �Է��ϼ���\n");
			}
			if (select=='y')
			{
				number=print_menu();
				toping_number1=print_topping1();
				if (toping_number1>0) anser= question();
				if (anser=='n') continue;
				if (anser=='y') toping_number2=print_topping2();

				if (toping_number2>0) continue;
			}
			if (select=='n')
			{
				printf ("\n%d ���� ��ȯ�ϰ� �����մϴ�.\n",total_money);
				total_money=0;
				break;
			}
		}
	}	

}

void sound (void)
{
	Sleep(1000);
	printf("\n��� ��縦 �����մϴ�.\n");
	Sleep(1000);
	printf("\n ���ۺ��� \n");
	Sleep(1500);
	printf("\n ���ۺ��� \n");
	Sleep(1500);
	printf("\n ���ۺ��� \n");
	Sleep(1500);

}