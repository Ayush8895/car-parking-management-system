#include<iostream>
#include<vector>
#include<fstream>
#include<conio.h>
#include<string.h>
#include <ctime>
using namespace std;

class vehicle
{   int type;
    string pltno;
public:
    void addVehicle();
    void deleteVehicle();
    void printvehicle(vehicle v);
    void show();
};
vector<vehicle> veh(100);
int  totalvehicle=0,totalcar=0,totalbike=0,totalamt=0,i=0;
fstream file;
void vehicle::addVehicle()
{
      vehicle *v = new vehicle;
      cout<<"Enter vehicle type(1 for Car/2 for Bike) : ";
      cin>>v->type;
      cout<<"Enter vehicle number : ";
      cin>>v->pltno;
      veh.at(i).pltno=v->pltno;
      veh.at(i).type=v->type;
      i++;
      totalvehicle++;
      if(v->type == 1)
      {
          totalcar++;
                cout<<"\nVehicle added successfully"<<endl;
      }
      else if(v->type==2)
        {
        totalbike++;
              cout<<"\nVehicle added successfully"<<endl;
        }
        else{
        	cout<<"Added successfully";
		}
}
  void vehicle::deleteVehicle()
  {   string pno;
      int typ;
      int time_diff;
      int charge=0;
      cout<<"Enter vehicle type(1 for Car/2 for Bike) : ";
      cin>>typ;
      cout<<"Enter vehicle number : ";
      cin>>pno;
      for(int j=0;j<=i;j++)
      {
          if((veh.at(j).pltno==pno)&&(veh.at(j).type==typ))
          {
              if(veh.at(j).type== 1)
              {
                  totalcar--;
                  charge=20;                 
              }
              else
              {
                  totalbike--;  
                  charge=5;    
               }
              cout<<"\nVehicle No.: "<<veh.at(j).pltno<<" left the parking area and payed Rs. "<<charge<<endl;
              file.open("parkingDatabase.txt",ios::app);
               time_t now = time(0);
                 char* dt = ctime(&now);
                      
               file<<veh.at(j).type<<"\t"<<veh.at(j).pltno<<"\t"<<dt<<endl;
               file.close();
              veh.erase(veh.begin()+j);
              i--;
              totalvehicle--;
              totalamt = totalamt+charge;
              break;
          }
          if(j==i)
          {
              cout<<"\nWrong Entry , Try Again "<<endl;
              cout<<"Departure : "<<endl;
              deleteVehicle();
          }
      }
  }
  void vehicle::printvehicle(vehicle v)
  {     
    cout<<v.type<<"\t\t\t"<<v.pltno<<endl;
  }
  void vehicle::show()
  {
      cout<<"\nVehicle Type\t\tVehicle Number"<<endl;
      for(int j=0;j<i;j++)
      {
          printvehicle(veh[j]);
      }
  }
  void totalveh()
  {
      cout<<"\nTotal number of vehicle parked : "<< totalvehicle<<"/70"<<endl;
      cout<<"Total number of car parked : "<< totalcar<<"/30"<<endl;
      cout<<"Total number of bike parked : "<<  totalbike<<"/40"<<endl;
  }
  void totalamount()
  {
      cout<<"\nTotal Collection : "<<totalamt<<endl;
  }
class Demo {
	public:
	 Demo(){
     cout<<"  \t\t\t                                _..-------++._                       "<<endl;
     cout<<"  \t\t\t                          _.-'/ |      _||  \"--._                   " <<endl;
     cout<<"  \t\t\t                     __.--'`._/_\j_____/_||___\    `----.            "<<endl;
     cout<<"  \t\t\t               _.--'_____    |          \     _____    /             "<<endl;
     cout<<"  \t\t\t             _j    /,---.\   |        =o |   /,---.\   |_            "<<endl;
     cout<<"  \t\t\t            [__]==// .-. \\==`===========/==// .-. \\=[__]           "<<endl;
     cout<<"  \t\t\t               `-._|\ `-' /|___\_________/___|__'-` /|_.'             "<<endl;
     cout<<"  \t\t\t                    `---'                    `---'                  " <<endl;
     cout<<"\t\t\t************************************************************************"<<endl;
     cout<<"\t\t\t ______________________________________________________________________"<<endl;
}
};
  int main()
  { Demo e1;
  	int login();
    login();
    int choice;
    char ans;
    system ( "cls" ) ;
  do
  {
     system ( "cls" ) ;
      Demo e2;
     cout<<"\n\t\t\t                    VEHICLE PARKING SYSTEM                 "<<endl;
     cout<<"\t\t\t|1. Arrival of a vehicle"<<endl
         <<"\t\t\t|2. Departure of vehicle"<<endl
         <<"\t\t\t|3. Total vehicles parked"<<endl
         <<"\t\t\t|4. Total Amount collected "<<endl
         <<"\t\t\t|5. Display "<<endl
         <<"\t\t\t|6. Exit"<<endl
         <<"********************************************************************"<<endl
         <<"Enter your Choice : ";
         cin>>choice;
         switch(choice)
         {
             case 1: 
                     cout<<"Add : "<<endl;
                     veh.at(i).addVehicle();
                     break;
             case 2: 
                     cout<<"Departure : "<<endl;
                     veh.at(i).deleteVehicle();
                     break;
              case 3:             
                     totalveh();
                     break;
             case 4: 
                     totalamount();
                     break;
             case 5: 
                     veh.at(i).show();
                     break;
             case 6: exit(0);
         }
         cout<<"\nDo you want to continue, press y/n : "<<endl;
         cin>>ans;
         if(ans=='n')
         {
             break;
         }
         else
         {
             continue;
         }
  }
  while(1);
  }
  int login(){
   string pass ="";
   char ch;
   cout <<"\n\n\n\t\t\t\t\t  Vehicle Parking System Login";
   cout << "\n\n\n\n\n\t\t\t\t\t\tEnter Password: ";
   ch = _getch();
   while(ch != 13){//character 13 is enter
      pass.push_back(ch);
      cout << '*';
      ch = _getch();
   }
   if(pass == "pass"){
      cout << "\n\n\n\n\t\t\t\t\t  Access Granted! Welcome To The System \n\n";
      system("PAUSE");
   }
   else{
      cout << "\n\n\n\n\t\t\t\t\t Wrong Password! Please Try Again!\n";
      system("PAUSE");
      system("CLS");
      Demo e3;
      login();
   }
}
  

