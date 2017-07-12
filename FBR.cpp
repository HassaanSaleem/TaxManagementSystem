#include<iostream>
#include<fstream>
#include<string>

using namespace std;

class Admin;
class Officer;
class BusinessMan;
class Farmer;
int position;
int size=4;

template<class T>
void editt(int choice,T *x)
{
    cout<<choice;
	switch (choice)
	{
		case 1:
		    cout<<"Enter Correct Name: ";
		    fflush(stdin);
		    getline(cin,x[position].name);
			break;
		case 2:
		    cout<<"Enter Correct Contact Number: ";
		    cin>>x[position].CoNo;
			break;
        case 3:
            cout<<"Enter Correct NIC Number: ";
            cin>>x[position].NIC;
            break;
            case 4:
                cout<<"Enter Correct Gender: ";
                cin>>x[position].gender;
                break;
        case 5: 
            cout<<"Enter Correct Address: ";
            getline(cin,x[position].Address);
            break;
	}

}


class Person
{
	protected:
		static int count;
		string name;
		string gender;
		string Address;
		size_t age;
		string NIC;
		long long int CoNo;

	public:
		template<class T>
	    friend void editt(int,T *);
	    
		Person()
		{
		    count++;
			name="ABC";
			gender="Male";
			Address="XYZ";
			age=18;
			NIC="42104-789789-8";
			CoNo=123456789;
		}

		void input()
		{
			cout<<"Enter Person Name: "<<endl;
			fflush(stdin);
			getline(cin,name);
			cout<<"Enter Gender: "<<endl;
			getline(cin,gender);
			cout<<"Enter Address: "<<endl;
			getline(cin,Address);
			cout<<"Enter Age: "<<endl;
			cin>>age;
			fflush(stdin);
			cout<<"Enter NIC Number: "<<endl;
			getline(cin,NIC);
			cout<<"Enter Contact Number: "<<endl;
			cin>>CoNo;
			cout<<endl;
			fflush(stdin);
		}

		void Display(int x=1) const
		{
			cout<<"Person ["<<x<<"] Name: "<<name<<endl;
			cout<<"Gender: "<<gender<<endl;
			cout<<"Address: "<<Address<<endl;
			cout<<"Age: "<<age<<endl;
			cout<<"NIC Number: "<<NIC<<endl;
			cout<<"Contact Number: +92"<<CoNo<<endl;
			cout<<endl;
		}
};


class Employee : public virtual Person
{
	protected:
		string EmployeeID;
		string Designation;

	public:
		Employee()
		{
			EmployeeID = "K163633";
			Designation = "XYZ";
		}

		void InputEmployee()
		{
			cout<<"Enter Employee ID: ";
			cin>>EmployeeID;
			cout<<"Enter Designation: ";
			cin>>Designation;
		}


		void DisplayEmployee()
		{
			cout<<"Employee ID: "<<EmployeeID<<endl;
			cout<<"Designation: "<<Designation<<endl;
		}

};	// END OF CLASS OFFICER


/* CLASS OF TAX PAYER*/
class Tax_Payer : protected virtual Person
{
	protected:
		unsigned int NTN;
		string Bank_Account;
		long double Balance; //Account Balance
		long double AmountPaid;	//tax amount paid by the customer
		static long double Tax_Amount; //Total tax amount paid by the custumer till now.
		long double Remaning_Balance; //Tax amount Remaning

	public:
		Tax_Payer()
		{
			AmountPaid=0;
			Balance=0;
			Tax_Amount=0;
			NTN=123;
			Bank_Account="42-55-645";
			Balance=21343;
		}

		void UpdateTax(long double *a)
		{
		    AmountPaid=*a;
		    Tax_Amount-=*a;
		    Remaning_Balance+=Tax_Amount;
		}

		void InputTax_Payer()
		{
			Person::input();
			cout<<"Enter Customer NTN Number: ";
			cin>>NTN;
			cout<<"Enter Customer Bank Account Number: ";
			cin>>Bank_Account;
			cout<<"Enter Amount Paid: ";
			cin>>AmountPaid;
		}

		void DisplayTax_Payer() const
		{
			Person::Display();
			cout<<"NTN: "<<NTN<<endl;
			cout<<"Bank Account Number: "<<Bank_Account<<endl;
			cout<<"Balance: "<<Balance<<endl;
			cout<<"Total Tax Amount Paid: "<<Tax_Amount<<endl;
			cout<<"Remaning Balance: "<<Remaning_Balance<<endl<<endl<<endl;
		}

};	// END OF CLASS TAX PAYER


class Farmer : public Tax_Payer
{

	protected:
		float landArea;
		float Permit_ID;
		fstream farmer0;
		fstream farmer1;
		fstream farmer2;
		fstream farmer3;
		fstream farmer4;
		fstream farmer5;
		
	public:
		template<class T>
	    friend void editt(int,T *);

	    friend void edittfarmer(int,Farmer*);

		friend int Search(const Farmer *x,const Officer *y,const BusinessMan *z);

		friend class Admin;

		void Inputfarmer()
		{
			Tax_Payer::InputTax_Payer();
			cout<<"Enter Land Area: ";
			cin>>landArea;
			cout<<"Enter Permit ID: ";
			cin>>Permit_ID;
		}
		
		void calculatefarmer()
		{
			Tax_Amount=(landArea)*20.5+Remaning_Balance;
		}

		void Displayfarmer()
		{
			Tax_Payer::DisplayTax_Payer();
			cout<<"Land Area: "<<landArea<<endl;
			cout<<"Permit ID: "<<Permit_ID;
		}

		void PrintOnFileFarmer(int x)
		{
			if(x==0)
			{
				farmer0.open("Farmer.txt",ios::out );
				farmer0<<name<<endl;
				farmer0<<gender<<endl;
				farmer0<<Address<<endl;
				farmer0<<NIC<<endl;
				farmer0<<Bank_Account<<endl;
				farmer0<<age<<endl;
				farmer0<<CoNo<<endl;
				farmer0<<NTN<<endl;
				farmer0<<AmountPaid<<endl;
				farmer0<<landArea<<endl;
				farmer0<<Permit_ID<<endl;
				farmer0<<Remaning_Balance<<endl;
				farmer0<<Tax_Amount<<endl;
				farmer0<<Balance<<endl;
			}
			else if(x==1)
			{
				farmer1.open("Farmer1.txt",ios::out );
				farmer1<<name<<endl;
				farmer1<<gender<<endl;
				farmer1<<Address<<endl;
				farmer1<<NIC<<endl;
				farmer1<<Bank_Account<<endl;
				farmer1<<age<<endl;
				farmer1<<CoNo<<endl;
				farmer1<<NTN<<endl;
				farmer1<<AmountPaid<<endl;
				farmer1<<landArea<<endl;
				farmer1<<Permit_ID<<endl;
				farmer1<<Remaning_Balance<<endl;
				farmer1<<Tax_Amount<<endl;
				farmer1<<Balance<<endl;
			}
			else if(x==2)
			{
				farmer2.open("Farmer2.txt",ios::out );
				farmer2<<name<<endl;
				farmer2<<gender<<endl;
				farmer2<<Address<<endl;
				farmer2<<NIC<<endl;
				farmer2<<Bank_Account<<endl;
				farmer2<<age<<endl;
				farmer2<<CoNo<<endl;
				farmer2<<NTN<<endl;
				farmer2<<AmountPaid<<endl;
				farmer2<<landArea<<endl;
				farmer2<<Permit_ID<<endl;
				farmer2<<Remaning_Balance<<endl;
				farmer2<<Tax_Amount<<endl;
				farmer2<<Balance<<endl;
			}
			else if(x==3)
			{
				farmer3.open("Farmer3.txt",ios::out );
				farmer3<<name<<endl;
				farmer3<<gender<<endl;
				farmer3<<Address<<endl;
				farmer3<<NIC<<endl;
				farmer3<<Bank_Account<<endl;
				farmer3<<age<<endl;
				farmer3<<CoNo<<endl;
				farmer3<<NTN<<endl;
				farmer3<<AmountPaid<<endl;
				farmer3<<landArea<<endl;
				farmer3<<Permit_ID<<endl;
				farmer3<<Remaning_Balance<<endl;
				farmer3<<Tax_Amount<<endl;
				farmer3<<Balance<<endl;
			}
			else if(x==4)
			{
				farmer4.open("Farmer4.txt",ios::out );
				farmer4<<name<<endl;
				farmer4<<gender<<endl;
				farmer4<<Address<<endl;
				farmer4<<NIC<<endl;
				farmer4<<Bank_Account<<endl;
				farmer4<<age<<endl;
				farmer4<<CoNo<<endl;
				farmer4<<NTN<<endl;
				farmer4<<AmountPaid<<endl;
				farmer4<<landArea<<endl;
				farmer4<<Permit_ID<<endl;
				farmer4<<Remaning_Balance<<endl;
				farmer4<<Tax_Amount<<endl;
				farmer4<<Balance<<endl;
			}
			else if(x==5)
			{
				farmer5.open("Farmer5.txt",ios::out );
				farmer5<<name<<endl;
				farmer5<<gender<<endl;
				farmer5<<Address<<endl;
				farmer5<<NIC<<endl;
				farmer5<<Bank_Account<<endl;
				farmer5<<age<<endl;
				farmer5<<CoNo<<endl;
				farmer5<<NTN<<endl;
				farmer5<<AmountPaid<<endl;
				farmer5<<landArea<<endl;
				farmer5<<Permit_ID<<endl;
				farmer5<<Remaning_Balance<<endl;
				farmer5<<Tax_Amount<<endl;
				farmer5<<Balance<<endl;
			}

			if(x==0)
			farmer0.close();
			else if(x=1)
			farmer1.close();
			else if(x==2)
			farmer2.close();
			else if(x==3)
			farmer3.close();
			else if(x==4)
			farmer3.close();
			else if(x==5)
			farmer3.close();
		
		
		}

		void farmerBack(int x)
		{
			if(x==0)
			{
				farmer0.open("Farmer.txt",ios::in);
				getline(farmer0,name);
				getline(farmer0,gender);
				getline(farmer0,Address);
				getline(farmer0,NIC);
				getline(farmer0,Bank_Account);
				farmer0>>age;
				farmer0>>CoNo;
				farmer0>>NTN;
				farmer0>>AmountPaid;
				farmer0>>landArea;
				farmer0>>Permit_ID;
				farmer0>>Remaning_Balance;
				farmer0>>Tax_Amount;
				farmer0>>Balance;
			
			}
			else if(x==1)
			{
				farmer1.open("Farmer1.txt",ios::in);
			
				getline(farmer1,name);
				getline(farmer1,gender);
				getline(farmer1,Address);
				getline(farmer1,NIC);
				getline(farmer1,Bank_Account);
				farmer1>>age;
				farmer1>>CoNo;
				farmer1>>NTN;
				farmer1>>AmountPaid;
				farmer1>>landArea;
				farmer1>>Permit_ID;
				farmer1>>Remaning_Balance;
				farmer1>>Tax_Amount;
				farmer1>>Balance;
			}
			else if(x==2)
			{
				farmer2.open("Farmer2.txt",ios::in);
				getline(farmer2,name);
				getline(farmer2,gender);
				getline(farmer2,Address);
				getline(farmer2,NIC);
				getline(farmer2,Bank_Account);
				farmer2>>age;
				farmer2>>CoNo;
				farmer2>>NTN;
				farmer2>>AmountPaid;
				farmer2>>landArea;
				farmer2>>Permit_ID;
				farmer2>>Remaning_Balance;
				farmer2>>Tax_Amount;
				farmer2>>Balance;
			
			}
			else if(x==3)
			{
				farmer3.open("Farmer3.txt",ios::in);
				getline(farmer3,name);
				getline(farmer3,gender);
				getline(farmer3,Address);
				getline(farmer3,NIC);
				getline(farmer3,Bank_Account);
				farmer3>>age;
				farmer3>>CoNo;
				farmer3>>NTN;
				farmer3>>AmountPaid;
				farmer3>>landArea;
				farmer3>>Permit_ID;
				farmer3>>Remaning_Balance;
				farmer3>>Tax_Amount;
				farmer3>>Balance;
			}
			else if(x==4)
			{
				farmer4.open("Farmer4.txt",ios::in);
				getline(farmer4,name);
				getline(farmer4,gender);
				getline(farmer4,Address);
				getline(farmer4,NIC);
				getline(farmer4,Bank_Account);
				farmer4>>age;
				farmer4>>CoNo;
				farmer4>>NTN;
				farmer4>>AmountPaid;
				farmer4>>landArea;
				farmer4>>Permit_ID;
				farmer4>>Remaning_Balance;
				farmer4>>Tax_Amount;
				farmer4>>Balance;
			}
			else if(x==5)
			{
				farmer5.open("Farmer5.txt",ios::in);
				getline(farmer5,name);
				getline(farmer5,gender);
				getline(farmer5,Address);
				getline(farmer5,NIC);
				getline(farmer5,Bank_Account);
				farmer5>>age;
				farmer5>>CoNo;
				farmer5>>NTN;
				farmer5>>AmountPaid;
				farmer5>>landArea;
				farmer5>>Permit_ID;
				farmer5>>Remaning_Balance;
				farmer5>>Tax_Amount;
				farmer5>>Balance;
			}
			
			
			if(x==0)
			farmer0.close();
			else if(x==1)
			farmer1.close();
			else if(x==2)
			farmer2.close();
			else if(x==3)
			farmer3.close();
			else if(x==4)
			farmer4.close();
			else if(x==5)
			farmer5.close();
			
			
			calculatefarmer();
		}

		Farmer()
		{	
			landArea=1;
			Permit_ID=123;
		}
		
};


class Officer : public Employee , public Tax_Payer	//Diamond Problem
{
	protected:
		string Position;
		double Salary;
		string CompanyName;
		fstream officer;
		fstream officer1;
		fstream officer2;
		fstream officer3;
		fstream officer4;
		fstream officer5;

	public:
		template<class T>
	    friend void editt(int,T *);

	    friend void edittofficer(int,Officer *);

		friend int Search(const Farmer *x,const Officer *y,const BusinessMan *z);
		
		friend class Admin;

		Officer()
		{
			Position="xyz";
			Salary=22323;
			CompanyName="ABC";
		}
		
		
		void calculateofficer()
		{
			long double exp=20;
			Tax_Amount=(((Salary))-exp)*12*0.075+Remaning_Balance;
		
		}
	
		void InputOfficer()
		{
			Tax_Payer::InputTax_Payer();
			Employee::InputEmployee();
			cout<<"Enter Employer Position: ";
			cin>>Position;
			cout<<"Enter Salary: ";
			cin>>Salary;
			cout<<"Enter Company Name: ";
			fflush(stdin);
			getline(cin,CompanyName);
		}

		void DisplayOfficer()
		{
			Tax_Payer::DisplayTax_Payer();
			Employee::DisplayEmployee();
			cout<<"Position Of Employer: "<<Position<<endl;
			cout<<"Salary is: "<<Salary<<endl;
			cout<<"Company Name is: "<<CompanyName<<endl;
		}

		void PrintOnFileOfficer(int x)
		{
			if(x==0)
			{
				officer.open("Officer.txt", ios::out);
				officer<<name<<endl;
				officer<<gender<<endl;
				officer<<Address<<endl;
				officer<<NIC<<endl;
				officer<<Bank_Account<<endl;
				officer<<EmployeeID<<endl;
				officer<<Designation<<endl;
				officer<<CompanyName<<endl;
				officer<<Position<<endl;
				officer<<age<<endl;
				officer<<CoNo<<endl;
				officer<<NTN<<endl;
				officer<<AmountPaid<<endl;
				officer<<Remaning_Balance<<endl;
				officer<<Tax_Amount<<endl;
				officer<<Balance<<endl;
				officer<<Salary<<endl;
				officer.close();
			}
			else if(x==1)
			{
				officer1.open("Officer1.txt", ios::out);
				officer1<<name<<endl;
				officer1<<gender<<endl;
				officer1<<Address<<endl;
				officer1<<NIC<<endl;
				officer1<<Bank_Account<<endl;
				officer1<<EmployeeID<<endl;
				officer1<<Designation<<endl;
				officer1<<CompanyName<<endl;
				officer1<<Position<<endl;
				officer1<<age<<endl;
				officer1<<CoNo<<endl;
				officer1<<NTN<<endl;
				officer1<<AmountPaid<<endl;
				officer1<<Remaning_Balance<<endl;
				officer1<<Tax_Amount<<endl;
				officer1<<Balance<<endl;
				officer1<<Salary<<endl;
				officer1.close();
			}
			else if(x==2)
			{
				officer2.open("Officer2.txt", ios::out);
				officer2<<name<<endl;
				officer2<<gender<<endl;
				officer2<<Address<<endl;
				officer2<<NIC<<endl;
				officer2<<Bank_Account<<endl;
				officer2<<EmployeeID<<endl;
				officer2<<Designation<<endl;
				officer2<<CompanyName<<endl;
				officer2<<Position<<endl;
				officer2<<age<<endl;
				officer2<<CoNo<<endl;
				officer2<<NTN<<endl;
				officer2<<AmountPaid<<endl;
				officer2<<Remaning_Balance<<endl;
				officer2<<Tax_Amount<<endl;
				officer2<<Balance<<endl;
				officer2<<Salary<<endl;
				officer2.close();
			}
			else if(x==3)
			{
				officer3.open("Officer3.txt", ios::out);
				officer3<<name<<endl;
				officer3<<gender<<endl;
				officer3<<Address<<endl;
				officer3<<NIC<<endl;
				officer3<<Bank_Account<<endl;
				officer3<<EmployeeID<<endl;
				officer3<<Designation<<endl;
				officer3<<CompanyName<<endl;
				officer3<<Position<<endl;
				officer3<<age<<endl;
				officer3<<CoNo<<endl;
				officer3<<NTN<<endl;
				officer3<<AmountPaid<<endl;
				officer3<<Remaning_Balance<<endl;
				officer3<<Tax_Amount<<endl;
				officer3<<Balance<<endl;
				officer3<<Salary<<endl;
				officer3.close();
			}
			else if(x==4)
			{
				officer4.open("Officer4.txt", ios::out);
				officer4<<name<<endl;
				officer4<<gender<<endl;
				officer4<<Address<<endl;
				officer4<<NIC<<endl;
				officer4<<Bank_Account<<endl;
				officer4<<EmployeeID<<endl;
				officer4<<Designation<<endl;
				officer4<<CompanyName<<endl;
				officer4<<Position<<endl;
				officer4<<age<<endl;
				officer4<<CoNo<<endl;
				officer4<<NTN<<endl;
				officer4<<AmountPaid<<endl;
				officer4<<Remaning_Balance<<endl;
				officer4<<Tax_Amount<<endl;
				officer4<<Balance<<endl;
				officer4<<Salary<<endl;
				officer4.close();
			}
			else if(x==5)
			{
				officer5.open("Officer5.txt", ios::out);
				officer5<<name<<endl;
				officer5<<gender<<endl;
				officer5<<Address<<endl;
				officer5<<NIC<<endl;
				officer5<<Bank_Account<<endl;
				officer5<<EmployeeID<<endl;
				officer5<<Designation<<endl;
				officer5<<CompanyName<<endl;
				officer5<<Position<<endl;
				officer5<<age<<endl;
				officer5<<CoNo<<endl;
				officer5<<NTN<<endl;
				officer5<<AmountPaid<<endl;
				officer5<<Remaning_Balance<<endl;
				officer5<<Tax_Amount<<endl;
				officer5<<Balance<<endl;
				officer5<<Salary<<endl;
				officer5.close();
			}

		}

		void OfficerBack(int x)
		{
			if(x==0)
			{
				officer.open("Officer.txt",ios::in);
				getline(officer,name);
				getline(officer,gender);
				getline(officer,Address);
				getline(officer,NIC);
				getline(officer,Bank_Account);
				getline(officer,EmployeeID);
				getline(officer,Designation);
				getline(officer,CompanyName);
				getline(officer,Position);
				officer>>age;
				officer>>CoNo;
				officer>>NTN;
				officer>>AmountPaid;
				officer>>Remaning_Balance;
				officer>>Tax_Amount;
				officer>>Balance;
				officer>>Salary;
				officer.close();
			}
			else if(x==1)
			{
				officer1.open("Officer1.txt",ios::in);
				getline(officer1,name);
				getline(officer1,gender);
				getline(officer1,Address);
				getline(officer1,NIC);
				getline(officer1,Bank_Account);
				getline(officer1,EmployeeID);
				getline(officer1,Designation);
				getline(officer1,CompanyName);
				getline(officer1,Position);
				officer1>>age;
				officer1>>CoNo;
				officer1>>NTN;
				officer1>>AmountPaid;
				officer1>>Remaning_Balance;
				officer1>>Tax_Amount;
				officer1>>Balance;
				officer1>>Salary;
				officer1.close();
			}
			else if(x==2)
			{
				officer2.open("Officer2.txt",ios::in);
				getline(officer2,name);
				getline(officer2,gender);
				getline(officer2,Address);
				getline(officer2,NIC);
				getline(officer2,Bank_Account);
				getline(officer2,EmployeeID);
				getline(officer2,Designation);
				getline(officer2,CompanyName);
				getline(officer2,Position);
				officer2>>age;
				officer2>>CoNo;
				officer2>>NTN;
				officer2>>AmountPaid;
				officer2>>Remaning_Balance;
				officer2>>Tax_Amount;
				officer2>>Balance;
				officer2>>Salary;
				officer2.close();
			}
			else if(x==3)
			{
				officer3.open("Officer3.txt",ios::in);
				getline(officer3,name);
				getline(officer3,gender);
				getline(officer3,Address);
				getline(officer3,NIC);
				getline(officer3,Bank_Account);
				getline(officer3,EmployeeID);
				getline(officer3,Designation);
				getline(officer3,CompanyName);
				getline(officer3,Position);
				officer3>>age;
				officer3>>CoNo;
				officer3>>NTN;
				officer3>>AmountPaid;
				officer3>>Remaning_Balance;
				officer3>>Tax_Amount;
				officer3>>Balance;
				officer3>>Salary;
				officer3.close();
			}
			else if(x==4)
			{
				officer4.open("Officer4.txt",ios::in);
				getline(officer4,name);
				getline(officer4,gender);
				getline(officer4,Address);
				getline(officer4,NIC);
				getline(officer4,Bank_Account);
				getline(officer4,EmployeeID);
				getline(officer4,Designation);
				getline(officer4,CompanyName);
				getline(officer4,Position);
				officer4>>age;
				officer4>>CoNo;
				officer4>>NTN;
				officer4>>AmountPaid;
				officer4>>Remaning_Balance;
				officer4>>Tax_Amount;
				officer4>>Balance;
				officer4>>Salary;
				officer4.close();
			}
			else if(x==5)
			{
				officer5.open("Officer5.txt",ios::in);
				getline(officer5,name);
				getline(officer5,gender);
				getline(officer5,Address);
				getline(officer5,NIC);
				getline(officer5,Bank_Account);
				getline(officer5,EmployeeID);
				getline(officer5,Designation);
				getline(officer5,CompanyName);
				getline(officer5,Position);
				officer5>>age;
				officer5>>CoNo;
				officer5>>NTN;
				officer5>>AmountPaid;
				officer5>>Remaning_Balance;
				officer5>>Tax_Amount;
				officer5>>Balance;
				officer5>>Salary;
				officer5.close();
			}
			
			calculateofficer();
		}


};


class BusinessMan : public Tax_Payer
{
	protected:
		string Type;
		string OfficeAddress;
		fstream BM;//Business Man
		fstream BM1;
		fstream BM2;
		fstream BM3;
		fstream BM4;
		fstream BM5;
		
	public:

		template<class T>
	    friend void editt(int,T *);

	    friend void edittbusinessman(int,BusinessMan*);

		friend int Search(const Farmer *x,const Officer *y,const BusinessMan *z);
		
		friend class Admin;
		
		BusinessMan()
		{
			Type="Import and Export";
			OfficeAddress="XYZ";
		}
		
		void calculatebusinessman()
		{
			long double inc=800000;
			Tax_Amount=0.8*inc+Remaning_Balance;
		}
		

		void PrintOnFileBM(int x)
		{
			if(x==0)
			{
				BM.open("BusinessMan.txt", ios::out);
				BM<<Type<<endl;
				BM<<OfficeAddress<<endl;
				BM<<name<<endl;
				BM<<gender<<endl;
				BM<<Address<<endl;
				BM<<NIC<<endl;
				BM<<Bank_Account<<endl;
				BM<<age<<endl;
				BM<<CoNo<<endl;
				BM<<NTN<<endl;
				BM<<AmountPaid<<endl;
				BM<<Remaning_Balance<<endl;
				BM<<Tax_Amount<<endl;
				BM<<Balance<<endl;
				BM.close();
			}
			else if(x==1)
			{
				BM1.open("BusinessMan1.txt", ios::out);
				BM1<<Type<<endl;
				BM1<<OfficeAddress<<endl;
				BM1<<name<<endl;
				BM1<<gender<<endl;
				BM1<<Address<<endl;
				BM1<<NIC<<endl;
				BM1<<Bank_Account<<endl;
				BM1<<age<<endl;
				BM1<<CoNo<<endl;
				BM1<<NTN<<endl;
				BM1<<AmountPaid<<endl;
				BM1<<Remaning_Balance<<endl;
				BM1<<Tax_Amount<<endl;
				BM1<<Balance<<endl;
				BM1.close();
			}
			else if(x==2)
			{
				BM2.open("BusinessMan2.txt", ios::out);
				BM2<<Type<<endl;
				BM2<<OfficeAddress<<endl;
				BM2<<name<<endl;
				BM2<<gender<<endl;
				BM2<<Address<<endl;
				BM2<<NIC<<endl;
				BM2<<Bank_Account<<endl;
				BM2<<age<<endl;
				BM2<<CoNo<<endl;
				BM2<<NTN<<endl;
				BM2<<AmountPaid<<endl;
				BM2<<Remaning_Balance<<endl;
				BM2<<Tax_Amount<<endl;
				BM2<<Balance<<endl;
				BM2.close();
			}
			else if(x==3)
			{
				BM3.open("BusinessMan3.txt", ios::out);
				BM3<<Type<<endl;
				BM3<<OfficeAddress<<endl;
				BM3<<name<<endl;
				BM3<<gender<<endl;
				BM3<<Address<<endl;
				BM3<<NIC<<endl;
				BM3<<Bank_Account<<endl;
				BM3<<age<<endl;
				BM3<<CoNo<<endl;
				BM3<<NTN<<endl;
				BM3<<AmountPaid<<endl;
				BM3<<Remaning_Balance<<endl;
				BM3<<Tax_Amount<<endl;
				BM3<<Balance<<endl;
				BM3.close();
			}
			else if(x==4)
			{
				BM4.open("BusinessMan4.txt", ios::out);
				BM4<<Type<<endl;
				BM4<<OfficeAddress<<endl;
				BM4<<name<<endl;
				BM4<<gender<<endl;
				BM4<<Address<<endl;
				BM4<<NIC<<endl;
				BM4<<Bank_Account<<endl;
				BM4<<age<<endl;
				BM4<<CoNo<<endl;
				BM4<<NTN<<endl;
				BM4<<AmountPaid<<endl;
				BM4<<Remaning_Balance<<endl;
				BM4<<Tax_Amount<<endl;
				BM4<<Balance<<endl;
				BM4.close();
			}
			else if(x==5)
			{
				BM5.open("BusinessMan5.txt", ios::out);
				BM5<<Type<<endl;
				BM5<<OfficeAddress<<endl;
				BM5<<name<<endl;
				BM5<<gender<<endl;
				BM5<<Address<<endl;
				BM5<<NIC<<endl;
				BM5<<Bank_Account<<endl;
				BM5<<age<<endl;
				BM5<<CoNo<<endl;
				BM5<<NTN<<endl;
				BM5<<AmountPaid<<endl;
				BM5<<Remaning_Balance<<endl;
				BM5<<Tax_Amount<<endl;
				BM5<<Balance<<endl;
				BM5.close();
			}
			
		}

		void BMBack(int x)
		{
			if(x==0)
			{
				BM.open("BusinessMan.txt",ios::in );
				getline(BM,Type);
				getline(BM,OfficeAddress);
				getline(BM,name);
				getline(BM,gender);
				getline(BM,Address);
				getline(BM,NIC);
				getline(BM,Bank_Account);
				BM>>age;
				BM>>CoNo;
				BM>>NTN;
				BM>>AmountPaid;
				BM>>Remaning_Balance;
				BM>>Tax_Amount;
				BM>>Balance;
				BM.close();
			}
			else if(x==1)
			{
				BM1.open("BusinessMan1.txt",ios::in );
				getline(BM1,Type);
				getline(BM1,OfficeAddress);
				getline(BM1,name);
				getline(BM1,gender);
				getline(BM1,Address);
				getline(BM1,NIC);
				getline(BM1,Bank_Account);
				BM1>>age;
				BM1>>CoNo;
				BM1>>NTN;
				BM1>>AmountPaid;
				BM1>>Remaning_Balance;
				BM1>>Tax_Amount;
				BM1>>Balance;
				BM1.close();
			}
			else if(x==2)
			{
				BM2.open("BusinessMan2.txt",ios::in );
				getline(BM2,Type);
				getline(BM2,OfficeAddress);
				getline(BM2,name);
				getline(BM2,gender);
				getline(BM2,Address);
				getline(BM2,NIC);
				getline(BM2,Bank_Account);
				BM2>>age;
				BM2>>CoNo;
				BM2>>NTN;
				BM2>>AmountPaid;
				BM2>>Remaning_Balance;
				BM2>>Tax_Amount;
				BM2>>Balance;
				BM2.close();
			}
			else if(x==3)
			{
				BM3.open("BusinessMan3.txt",ios::in );
				getline(BM3,Type);
				getline(BM3,OfficeAddress);
				getline(BM3,name);
				getline(BM3,gender);
				getline(BM3,Address);
				getline(BM3,NIC);
				getline(BM3,Bank_Account);
				BM3>>age;
				BM3>>CoNo;
				BM3>>NTN;
				BM3>>AmountPaid;
				BM3>>Remaning_Balance;
				BM3>>Tax_Amount;
				BM3>>Balance;
				BM3.close();
			}
			else if(x==4)
			{
				BM4.open("BusinessMan4.txt",ios::in );
				getline(BM4,Type);
				getline(BM4,OfficeAddress);
				getline(BM4,name);
				getline(BM4,gender);
				getline(BM4,Address);
				getline(BM4,NIC);
				getline(BM4,Bank_Account);
				BM4>>age;
				BM4>>CoNo;
				BM4>>NTN;
				BM4>>AmountPaid;
				BM4>>Remaning_Balance;
				BM4>>Tax_Amount;
				BM4>>Balance;
				BM4.close();
			}
			else if(x==5)
			{
				BM5.open("BusinessMan5.txt",ios::in );
				getline(BM5,Type);
				getline(BM5,OfficeAddress);
				getline(BM5,name);
				getline(BM5,gender);
				getline(BM5,Address);
				getline(BM5,NIC);
				getline(BM5,Bank_Account);
				BM5>>age;
				BM5>>CoNo;
				BM5>>NTN;
				BM5>>AmountPaid;
				BM5>>Remaning_Balance;
				BM5>>Tax_Amount;
				BM5>>Balance;
				BM5.close();
			}
		
			calculatebusinessman();	
		}

		void InputBusinessMan()
		{
			Tax_Payer::InputTax_Payer();
			cout<<"Enter Business Type: ";
			cin>>Type;
			cout<<"Enter Office Address: ";
			cin>>OfficeAddress;
		}

		void DisplayBussinessMan()
		{
			Tax_Payer::DisplayTax_Payer();
			cout<<"Business Type: "<<Type<<endl;
			cout<<"Office Address: "<<OfficeAddress;
		}

};



class FBRWorker
{
	protected:
	Farmer *x;
	Officer *y;
	BusinessMan *z;

	public:
		FBRWorker()
		{
			x=NULL;
			y=NULL;
			z=NULL;

		}

		FBRWorker(Farmer *a,Officer *b,BusinessMan *c)
		{
				x=a;
				y=b;
				z=c;

		}

		void Display()
		{
			int check=Search(x,y,z);
	
			if(check==1)
			x[position].Displayfarmer();	
			else if(check==2)
			y[position].DisplayOfficer();
        	else if(check==3)
			z[position].DisplayBussinessMan();

		}			

		void TaxCollect()
		{
		    long double q;
		    cout<<"Enter Amount To Be Paid: ";
		    cin>>q;
	
			int check=Search(x,y,z);
    	    if (check==1)
    	    {
	   	     	x[position].UpdateTax(&q);
			}
			if (check==2)
    	    {
	        	y[position].UpdateTax(&q);
			}
			if (check==1)
    	    {
    	    	z[position].UpdateTax(&q);
			}

		}

		void Queries()
		{
			string choice;
			cout<<endl<<"Do you have any Queries? (yes/no)";
			cin>>choice;
			if (choice == "YES" || choice == "yes")
			{
				cout<<"Kindly Go to the Manager.";

			}
			else
			{
				cout<<"Thank You for Coming.";
			}

		}
};

//void editt(int choice,Farmer *x);

class Manager : public FBRWorker
{ 
	public:
		Manager(Farmer *a,Officer *b,BusinessMan *c)
		{
				x=a;
				y=b;
				z=c;

		}

		void Edit()
		{
			
			cout<<endl<<"Manager: "<<"What do you want to be corrected?"<<endl;
			int check=Search(x,y,z);
			int choicee;
			if (check==2)
			{
				cout<<"1. Name:\n2. Contact Number:\n3. NIC Number:\n4. Gender:\n5. Address:\n6. Salary:\n7. Company Name:\n";
				cout<<"8. Position: ";
				cin>>choicee;
				editt(choicee,y);
			}
			else if(check==1)
			{
				cout<<"1. Name:\n2. Contact Number:\n3. NIC Number:\n4. Gender:\n5. Address:\n6. Permit ID:\n7. Area Of Land:\n";
				cin>>choicee;
				editt(choicee,x);
			}
			else if(check==3)
			{
				cout<<"1. Name:\n2. Contact Number:\n3. NIC Number:\n4. Gender:\n5. Address:\n6. Office Address:\n";
				cin>>choicee;
				editt(choicee,z);
			}

			if(check==2)
			{
				edittofficer(choicee,y);
			}

			if(check==1)
			{
				edittfarmer(choicee,x);
			}


			if (check==3)
			{
				edittbusinessman(choicee,z);
			}


		}
		
		void Request()
		{
			cout<<"Please Go To The Admin Office:"<<endl;
		}

		void Compensate()
		{
			string compen;
			cout<<"Do You Want to Compensate?(yes/no)";
			cin>>compen;
			while (compen!= "yes" && compen!="no")
			{
				cout<<"Enter Correct Choice:"<<endl;
				cout<<"Do You Want to Compensate?(yes/no)";
				cin>>compen;

			}
				if (compen=="yes")
				{
					Request();
				}
				else if(compen=="no")
				{
					TaxCollect();
				}
		}
};

class Admin : public FBRWorker
{		
	public:
		Admin(Farmer *a,Officer *b,BusinessMan *c)
		{
			x=a;
			y=b;
			z=c;

		}

		void Edit()
		{
			int check=Search(x,y,z);
			int choicee;
			cout<<endl<<"Manager: "<<"What do you want to be corrected?"<<endl;

			if (check==2)
			{
				cout<<"1. Name:\n2. Contact Number:\n3. NIC Number:\n4. Gender:\n5. Address:\n6. Salary:\n7. Company Name:\n";
				cout<<"8. Position: ";
				cin>>choicee;
				editt(choicee,y);
			}
			else if(check==1)
			{
				cout<<"1. Name:\n2. Contact Number:\n3. NIC Number:\n4. Gender:\n5. Address:\n6. Permit ID:\n7. Area Of Land:\n";
				cin>>choicee;
				editt(choicee,x);
			}
			else if(check==3)
			{
				cout<<"1. Name:\n2. Contact Number:\n3. NIC Number:\n4. Gender:\n5. Address:\n6. Office Address:\n";
				cin>>choicee;
				editt(choicee,z);
			}

			if(check==2)
			{
				edittofficer(choicee,y);
			}

			if(check==1)
			{
				edittfarmer(choicee,x);
			}


			if (check==3)
			{
				edittbusinessman(choicee,z);
			}


		}

	void Register(Farmer *a,Officer *b,BusinessMan *c)
	{
		int choice;
		cout<<"\nEnter\n1. For A Farmer\n2. For Officer\n3. For Business Man: ";
		cin>>choice;
		if(choice==1)
		a[size].Inputfarmer();
		else if(choice==2)
		b[size].InputOfficer();
		else if(choice==3)
		c[size].InputBusinessMan();
		else
		{
			cout<<"Wrong Input: "<<endl;
			Register(x,y,z);
		}
		
		size++;
		
	}

	void Display()
	{
		int check=Search(x,y,z);

		if(check==1)
		x[position].Displayfarmer();
        else if(check==2)
		y[position].DisplayOfficer();
        else if(check==3)
		z[position].DisplayBussinessMan();

	}
	
	void Compensate()
	{
		int ch=Search(x,y,z);
		long double a,bal;
		if(ch==1)
		bal=x[position].Balance - (x[position].Balance*0.3);
		else if(ch==2)
		bal=y[position].Balance-y[position].Balance*0.3;
		else if(ch==3)
		bal=z[position].Balance-z[position].Balance*0.3;
		cout<<"Enter Amount To be Paid: ";
		cin>>a;
		
		if (a<=(bal))
		{
			if(ch==1)
			x[position].UpdateTax(&a);
			else if(ch==2)
			y[position].UpdateTax(&a);
			else if(ch==3)
			z[position].UpdateTax(&a);
		}
		else {
			string choice;
			cout<<"Amount Must Be Greter Than or Equal To 70% Of the Remaining Tax Amount i.e: Rs."<<bal<<endl;
			cout<<"Do you have enough Money(yes/no): ";
			cin>>choice;
			while (choice!= "yes" || choice!="no")
			{
				cout<<"Enter Correct Choice:"<<endl;
				cout<<"Do You Want to Compensate?(yes/no)";
				cin>>choice;

			}
				if (choice=="yes")
				{
					Compensate();
				}
				else if(choice=="no")
				{
					cout<<"Thank For Coming:\n";
				}
		}
	}

};

int Person::count=0;
long double Tax_Payer::Tax_Amount=0;

void edittfarmer(int choice,Farmer *x)
{
	if (choice==6)
	{
		cout<<"Enter Correct Permit ID: ";
		cin>>x[position].Permit_ID;
	}

	if (choice==7)
	{
		cout<<"Enter Correct Area (Land): ";
		cin>>x[position].landArea;
	}
}

void edittofficer(int choice,Officer *x)
{
	if (choice==6)
    {
	    cout<<"Enter Correct Salary: ";
        cin>>x[position].Salary;
 	}
    if (choice==7)
    {
		cout<<"Enter Correct Company Name: ";
        getline (cin,x[position].CompanyName);
    }
    if(choice==8)
    {
        cout<<"Enter Correct Position: ";
        getline(cin,x[position].Position);
    }

}

void edittbusinessman(int choice,BusinessMan *x)
{
	if (choice==6)
	{
		cout<<"Enter Correct Office Address: ";
		getline (cin,x[position].OfficeAddress);
	}
}

int Search(const Farmer *x,const Officer *y,const BusinessMan *z)
{
	unsigned int n;
	cout<<"Enter NTN Number: ";
	cin>>n;
	
		for(int i=0;i<4;i++)
		if(n==x[i].NTN)
		{
			position=i;
			return 1;
		}
		else if(n==y[i].NTN)	
		{
			position=i;
			return 2;
		}
		else if(n==(z[i].NTN))
		{
			position=i;
			return 3;
		}
	
	
}


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
					cout<<"What Do You Want To Do?"<<endl<<"1. Edit:\n2.Register An Account:\n3. Compensate:\n4. Display Data:\n5. Logout ";
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
					cout<<"What Do You Want To Do?"<<endl<<"1. Edit:\n2. Request:\n3. Compensate:\n4. Display Data:\n5. Logout: ";
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
					cout<<"What Do You Want To Do?"<<endl<<"1. Display Data:2. Tax Collect:3. Quries:\n4. Logout: ";
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
	main();
	return 0;

}
