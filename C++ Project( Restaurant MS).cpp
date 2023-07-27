#include <iostream>
using namespace std;

void menu()
{
	cout<<" WELCOME TO YASH'S SPACE :)"<<endl;
	cout<<"___________________________________________"<<endl;
	cout<<"No:	MENU			Price"<<endl;
	cout<<" 1.	PIZZA			500 Rs"<<endl;
	cout<<" 2.	PASTA			120 Rs"<<endl;
	cout<<" 3.	TANDOORI MOMOS		60 Rs"<<endl;
	cout<<" 4.	COLD COFFEE		40 Rs"<<endl;
	cout<<"___________________________________________"<<endl;
}

main()
{
	int n;
	int jum;
	int qty[4];
	int no[4];
	long price[4], total[4];
	string name[4];
	float change,pay;

	menu();

	cout<<"How many menu do you want to order ? : ";
	cin>>n;

	if (n>0 && n<=4)
	{
		for (int i=0; i<n; i++)
		{
			cout<<"Enter Your Choice "<<i+1<<" =";
			cin>>no[i];
			cout<<"Enter Quantity = ";cin>>qty[i];
			if (no[i]==1)
			{
				name[i]="PIZZA";
				price[i]=500;
				total[i]=price[i]*qty[i];
			}
			else if (no[i]==2)
			{
				name[i]="PASTA";
				price[i]=120;
				total[i]=price[i]*qty[i];
			}
			else if (no[i]==3)
			{
				name[i]="VEG MOMOS";
				price[i]=60;
				total[i]=price[i]*qty[i];
			}
			else if (no[i]==4)
			{
				name[i]="COLD COFFEE";
				price[i]=40;
				total[i]=price[i]*qty[i];
			}
			jum = jum + total[i];
		}
		system ("cls");
		menu();
		cout<<"Your Choice is : "<<endl;
		for (int i=0; i<n; i++)
		{
			cout<<qty[i]<<" "<<"Portion"<<" "<<name[i]<<endl;
			cout<<"Price/Portion = "<<price[i]<<endl;
			cout<<"Total Price "<<name[i]<<"="<<total[i]<<endl;
		}
		cout<<"Paid : Rs. ";
		cin>>pay;
		change=pay-jum;
		cout<<"Change : Rs. "<<change<<endl;
		cout<<"Thank You for visiting our Restaurant ;)";
	}
	else
	cout<<"Please Try Again ;)";
	return 0;


}
