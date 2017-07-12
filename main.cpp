#include <iostream>
#include "FBR.h"

using namespace std;
int main()
{
	Farmer A[6];
	Officer B[6];
	BusinessMan C[6];
	

	//DataBack
	for(int x=0;x<size;)
	{
		A[x].farmerBack(x);
		B[x].OfficerBack(x);
		C[x].BMBack(x);
		x++;
	}
		
	string nam;
	
	do
	{
		system("cls");
		cout<<"===================================================================================================================================================="<<endl;
		cout<<"===================================================================================================================================================="<<endl;
		cout<<"		       	               ***************  ********        ***********"<<endl; 
		cout<<"			   		**************   ***********     *************"<<endl;
		cout<<"					**             	 **      ****    **      ******"<<endl;		
		cout<<"					**		 **       ****   **       *****"<<endl;
		cout<<"					**		 **     *****    **       *****"<<endl;
		cout<<"					**   	         **   *****      **     *****"<<endl;
		cout<<"					**************   *******         **  *****"<<endl;
		cout<<"					**************   ***********     ******"<<endl;
		cout<<"					**               **      *****   **  ****"<<endl;		
		cout<<"					**		 **       ****   **   *****"<<endl;
		cout<<"					**		 **     *****    **       ****"<<endl;
		cout<<"					**   	         *********       **        ****"<<endl;
		cout<<"              			       **               *****           **         ****"<<endl;
		cout<<"===================================================================================================================================================="<<endl;
		cout<<"===================================================================================================================================================="<<endl;
		cout<<endl<<"							Enter User Name: ";
		cin>>nam;		
		if(nam=="Hassaan")
		break;
		else if(nam=="Afroz")
		break;
		else if(nam=="Soman")
		break;
		else if(nam=="Solat")
		break;
		else 
		cout<<"User Name Does not Exist Please Enter Again:"<<endl;
	}while(nam!="Hassaan" && nam!="Afroz" && nam!="Soman" && nam!="Solat");
	
	string pass;
	
	int turn=3;
	while(turn>0)
	{
		string choice;
		cout<<"							Enter Password: ";
		cin>>pass;
		
		if ((pass=="k163633" && nam=="Hassaan") || (pass=="1234" && nam=="Solat"))
		{
			cout<<"							Login Succesfull."<<endl;
			Admin *Ad=new Admin(A,B,C);
			
			while(1)
			{
				turn=0;
				do
				{			
					cout<<"							What Do You Want To Do?"<<endl<<"							1. Edit:\n							2.Register An Account:\n							3. Compensate:\n							4. Display Data:\n							5. Logout \n";
					cout<<"							Your Choice: ";
					cin>>choice;			
			
				}
				while(choice!="1" && choice!="2" && choice!="3" && choice!="4" && choice!="5");
		
				if(choice=="1")
				Ad->Edit();
				else if (choice=="2")
				Ad->Register(A,B,C);
				else if(choice=="3")
				Ad->Compensate();
				else if(choice=="4")
				Ad->Display();
				else if(choice=="5")
				break;
			}
			delete Ad;
		}
		else if (pass=="k163643" && nam=="Afroz" )
		{
			cout<<"Login Succesfull."<<endl;
			Manager *Ad=new Manager(A,B,C);
			turn=0;
			while(1)
			{
				do
				{			
					cout<<"							What Do You Want To Do?"<<endl<<"							1. Edit:\n							2. Request:\n							3. Compensate:\n							4. Display Data:\n							5. Logout: \n";
					cout<<"							Your Choice: ";
					cin>>choice;			
			
				}while(choice!="1" && choice!="2" && choice!="3" && choice!="4" && choice!="5");
		
				if(choice=="1")
				Ad->Edit();
				else if (choice=="2")
				Ad->Request();
				else if(choice=="3")
				Ad->Compensate();
				else if(choice=="4")
				Ad->Display();
				else if(choice=="5")
				break;
			}
			delete Ad;
		}
		else if (pass=="k163639" && nam=="Soman")
		{
			FBRWorker *Ad=new FBRWorker(A,B,C);
			cout<<"Login Succesfull."<<endl;
			turn=0;
			while(1)
			{
				do
				{			
					cout<<"							What Do You Want To Do?"<<endl<<"							1. Display Data\n							2. Tax Collect\n							3. Queries:\n							4. Logout\n";
					cout<<"							Your Choice: ";							
					cin>>choice;			
			
				}while(choice!="1" && choice!="2" && choice!="3" && choice!="4" && choice!="5");
		
				if(choice=="1")
				Ad->Display();
				else if (choice=="2")
				Ad->TaxCollect();
				else if(choice=="3")
				Ad->Queries();
				else if(choice=="4")
				break;
			}
			
			delete Ad;
		}
		else
		{
			cout<<endl<<"Enter Correct Password Again:"<<endl<<turn<< "Turns remaining: ";
		}
				turn--;
		}
	
	if(turn==0)
	{
		cout<<"Try again Later."<<endl;
	}			
	

		
	//DataPrint
	for(int x=0;x<size;)
	{
		A[x].PrintOnFileFarmer(x);
		B[x].PrintOnFileOfficer(x);
		C[x].PrintOnFileBM(x);
	
		x++;
	}
	
	return 0;

}
