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
char*productName[5]={"0","신라면","안성탕면","진라면","너구리"};
char*toppingName[4]={"없음","달걀","파","소세지"};
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
		printf ("\n투입금액 %5d\n", total_money);
		number=print_menu();
		if (number==0) 
		{
			if (total_money>0)
			{
				printf ("\n%d 원을 반환하고 종료합니다.",total_money);
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
		printf ("\n감사합니다 고객님");
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
	printf ("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
	printf ("■■■■■                                      ■                  ■■■■■\n");
	printf ("■■■■■           끓인 라면 자판기           ■  추가 토핑+      ■■■■■\n");
	printf ("■■■■■                                      ■                  ■■■■■\n");
	printf ("■■■■■                                      ■  ① 달걀   500   ■■■■■\n");
	printf ("■■■■■  ①신라면♨ 2500  ②안성탕면♨ 2300  ■                  ■■■■■\n");
	printf ("■■■■■                                      ■  ② 파     300   ■■■■■\n");
	printf ("■■■■■  ③진라면♨ 2000  ④너구리  ♨ 2600  ■                  ■■■■■\n");
	printf ("■■■■■                                      ■  ③ 소세지 700   ■■■■■\n");
	printf ("■■■■■                                      ■                  ■■■■■\n");
	printf ("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
}

int print_menu(void)
{
   int number=0; 
   printf("\n라면을 선택해 주세요. \n\n①신라면: %d개 ②안성탕면: %d개③진라면: %d개 ④너구리%: %d개 0. 전체취소버튼\n",inventory[1],inventory[2],inventory[3],inventory[4]);
   for(;;)
   {
	  for(;;)
	  {
      printf("\n1번부터 4번까지 제품번호를 선택하세요.");
      scanf("%d",&number);
	  if(number>=0&&number<=4) break;
	  }
      if(number>=1&&number<=4)
      {
         if(inventory[number]<=0)
         {
            printf("\n%s는 %d개로 품절입니다.다시 입력해주세요",productName[number],inventory[number]);
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
			printf ("\n투입금액 %5d 금액종류 100, 500, 1000, 5000, 10000중 입력 ", total_money);
			scanf ("%d",&money);
			if(money==100||money==500||money==1000||money==5000||money==10000) break;
			else printf ("\n\n잘못된 금액입니다.  총액에 반영되지 않습니다.\n"); 
		}
		total_money= total_money + money;
		printf ("\n금액을 더 입력하시겠습니까?(y/n)");
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
	printf("\n토핑을 선택해 주세요. \n\n1.달걀: %d개 2.파: %d개 3.소세지: %d개 0.선택하지않음 \n",topping_inventory[1],topping_inventory[2],topping_inventory[3]);
	for(;;)
	{
		for(;;)
		{
			printf("\n1번부터 3번까지 토핑번호를 선택하세요.");
			scanf("%d",&number);
			if (number>=0&&number<=3) break;
		}
		if (number<=0) break;
		if(number>=1&&number<=3)
		{
			topping_count[number]++;

			if(topping_inventory[number]<=0)
			{
			printf("\n%s는 %d개로 품절입니다.다시 입력해주세요",toppingName[number],topping_inventory[number]);
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

	printf("\n토핑을 선택해 주세요. \n\n1.달걀: %d개 2.파: %d개 3.소세지: %d개 0.선택하지않음 \n",topping_inventory[1],topping_inventory[2],topping_inventory[3]);
	for(;;)
	{
		for(;;)
		{
			printf("\n1번부터 3번까지 토핑번호를 선택하세요.");
			scanf("%d",&number);
			if (number>=0&&number<=3) break;
		}
		if (number<=0) break;
		if(number>=1&&number<=3)
		{
			topping_count[number]++;
			if(topping_inventory[number]<=0)
			{
			printf("\n%s는 %d개로 품절입니다.다시 입력해주세요",toppingName[number],topping_inventory[number]);
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
		printf ("\n토핑을 더 추가하시겠습니까?(y/n)");
		while(getchar()!='\n');
		scanf ("%c",&val);
		if (val == 'y' || val == 'n')break;
		else printf ("\n다시 입력하세요\n");
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
			printf ("\n투입금액이 부족합니다. 돈을 더 투입해주세요.");
			input_money();
		}
		else
		{
			sound ();
			printf ("\n%s♨이(가) 나왔습니다.(토핑: %s)",productName[number],toppingName[toping_number1]);
			total_money= total_money-price[number]-price_topping[toping_number1];
			inventory[number]--;
			topping_inventory[toping_number1]--;
			topping_count[toping_number1]--;
			for(;;)
			{
				printf ("\n\n남은금액: %d, 더 주문하시겠습니까?(y/n)",total_money);
				while(getchar()!='\n');
				scanf ("%c",&select);
				if (select == 'y' || select == 'n') break;
				else printf ("\n다시 입력하세요\n");
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
				printf ("\n%d 원을 반환하고 종료합니다.\n",total_money);
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
			printf ("\n투입금액이 부족합니다. 돈을 더 투입해주세요.");
			input_money();
		}
		else
		{
			if(toping_number1==toping_number2)
			{
				sound ();
				printf ("\n%s ♨이(가) 나왔습니다.(토핑: %s %d개)",productName[number],toppingName[toping_number1],topping_count[toping_number1]);
			}
			else
			{
				sound ();
				printf ("\n%s ♨이(가) 나왔습니다.(토핑: %s, %s)",productName[number],toppingName[toping_number1],toppingName[toping_number2]);
			}
			total_money= total_money-price[number]-price_topping[toping_number1]-price_topping[toping_number2];
			inventory[number]--;
			topping_inventory[toping_number1]--;
			topping_inventory[toping_number2]--;
			topping_count[toping_number1]--;
			topping_count[toping_number2]--;
			for(;;)
			{
				printf ("\n\n남은금액: %d, 더 주문하시겠습니까?(y/n)",total_money);
				while(getchar()!='\n');
				scanf ("%c",&select);
				if (select == 'y' || select == 'n')break;
				else printf ("\n다시 입력하세요\n");
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
				printf ("\n%d 원을 반환하고 종료합니다.\n",total_money);
				total_money=0;
				break;
			}
		}
	}	

}

void sound (void)
{
	Sleep(1000);
	printf("\n라면 취사를 시작합니다.\n");
	Sleep(1000);
	printf("\n 보글보글 \n");
	Sleep(1500);
	printf("\n 보글보글 \n");
	Sleep(1500);
	printf("\n 보글보글 \n");
	Sleep(1500);

}