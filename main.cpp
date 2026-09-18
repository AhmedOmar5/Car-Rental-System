//
//  main.cpp
//  Milestone 2
//
//  Created by Ahmed Omar on 24/08/2023.
//

#include <iostream>
#include<ctime>
using namespace std;
struct car
{
    string car_model;
    int cost;
    int num_car; // dee 3ashan ned5l ma3ana kam 3arbya men nafs el model
    int book_num; //dee 3ashan ne7sb kam mara el 3arbya dee et2agrt
};
struct user
{
    string name;
    string national_id;
    string phone_number;
    int reservation;
    string start_date;
    int days;
};

car cardata[200];
user userdata[200];
int CarNumber=0;
int usernumber=0;
int cars_counter=0;


void add();
void listCars();
void listUser();
int usercompare(string name);
int CarCompare(string model);
void remove();
void booking();
int favorite_car();
void average_rental_time();
void report();



int main()
{
    string choice;
    int password=12345;
    int answer;
    cc:
    cout<<"Admin or User : ";
    cin>>choice;
    if(choice=="Admin" || choice=="admin" || choice=="ADMIN" )
    {
        cout<<"enter password : ";
        aa:
        cin>>password;
        if(password==12345)
        {
            while(1)
            {
                cout<<" (1) add "<<endl;
                cout<<" (2) remove "<<endl;
                cout<<" (3) list of cars "<<endl;
                cout<<" (4) reservation "<<endl;
                cout<<" (5) list of renters"<<endl;
                cout<<" (6) Report"<<endl;
                cout<<" (7) exit"<<endl<<endl;
                cout<<" Please enter an answer : ";
                cin>>answer;
                if(answer==1)
                {
                    add();
                }
                else if (answer==2)
                {
                    remove();
                }
                else if (answer==3)
                {
                    listCars();
                }
                else if (answer==4)
                {
                    booking();
                }
                else if (answer==5)
                {
                    listUser();
                }
                else if (answer==6)
                {
                    report();
                }
                else if (answer==7)
                {
                    goto cc;
                }
                else
                {
                    cout<<"Please enter a correct value"<<endl;
                }
                cout<<"----------------------"<<endl<<endl;
            }
        }
        else
            cout<<"Password is not correct re-enter password : ";
        goto aa;
    }
   else if(choice=="User" || choice=="user" || choice=="USER" )
    {
        while(1)
        {
            cout<<" (1) list of cars "<<endl;
            cout<<" (2) reservation "<<endl;
            cout<<" (3) exit"<<endl;
            cout<<" Please enter an answer : ";
            cin>>answer;
           
            if (answer==1)
            {
                listCars();
            }
            else if (answer==2)
            {
                booking();
            }
            else if (answer==3)
            {
                goto cc;
            }
            else
            {
                cout<<"Please enter a correct value"<<endl;
            }
            cout<<endl<<endl;
            cout<<"----------------------"<<endl<<endl;
        }
    }
    
}


void add()
{
    if(CarNumber>200)
    {
        cout<<"The garage is full , you can not add more cars";
    }
    struct car car;
    cout<<"Please enter a car model : ";
    cin>>car.car_model;
    cout<<"Please enter the cost of the car per day : ";
    cin>>car.cost;
    cout<<"Please enter the number of cars available : ";
    cin>>car.num_car;
    cardata[CarNumber++]=car; // dee 3ashan nezawed el car ely da5lnaha fel global array
    
}

void listCars()
{
    for(int i=0 ; i<=CarNumber-1 ; i++)
    {
        cout<<"The list of car model available : " <<cardata[i].car_model<<endl;
        cout<<"The price of the car is : "<<cardata[i].cost<<endl;
        cout<<"The car available of this model is : "<<cardata[i].num_car<<endl;
        cout<<endl<<endl;
    }
}


void listUser()
{
    for(int i=0 ; i<=usernumber-1 ; i++)
    {
        struct user user;
        struct car car;
        cout<<"Name : "<<userdata[i].name<<endl;
        cout<<"National ID : "<<userdata[i].national_id<<endl;
        cout<<"Phone Number : "<<userdata[i].phone_number<<endl;
        cout<<"Reservation Number : "<<userdata[i].reservation<<endl;
        cout<<"Car booked : "<<cardata[i].car_model<<endl;
        cout<<"Starting date : "<<userdata[i].start_date<<endl;
        cout<<"Number of days: "<<userdata[i].days<<endl;
        cout<<"----------------------"<<endl;
        
    }
}



int usercompare(string name)
{
    for(int x = 0 ; x<=usernumber-1; x++ )
    {
        if(name==userdata[x].name)
        {
            return x;
        }
    }
    return -2;
}


int CarCompare(string model)
{
    for(int x = 0 ; x<=CarNumber-1; x++ )
    {
        if(model==cardata[x].car_model)
        {
            return x;
        }
    }
    return -2;
}
void remove()
{
    aa:
    cout<<"Please enter the car you would like to remove : ";
    string model;
    cin>>model;
    int y=CarCompare(model); // dee 3ashan ne3ml compare mabeen el 3arbya ely da5lnaha wel 3arbyat ely mwgooda fel array
    if(y>=0) // dee 3ashan net2akd en 3arbya mawgooda
    {
        ff:
        cout<<"Please enter the number of cars you would like to remove : ";
        int num;
        cin>>num;
        if(cardata[y].num_car>=num) // dee 3ashan net2akd en 3add el 3arbyat ely han3mlha remove tob2a as8ar men 3add el 3arbyat el metsagla
        {
            cardata[y].num_car = cardata[y].num_car-num ;
            cout<<endl;
            cout<<"The cars have been removed \n";
        }
        else
        {
            cout<<"you can't remove the cars, because the number exceed the limit \n";
            goto ff;
        }
    }
    else
    {
        cout<<"The car you have entered is not found \n";
        goto aa;
    }
}

void booking()
{
    
    struct user user;
    cout<<"please enter your name : ";
    cin>>user.name;
    cout<<"please enter your national id : ";
    cin>>user.national_id;
    cout<<"please enter your phone number : ";
    cin>>user.phone_number;
    
    bb:
    cout<<"please enter a car model : ";
    string model;
    cin>>model;
    cout<<"Please enter starting date(dd-mm-yy): ";
    cin>>user.start_date;
    cout<<"How many days you would like to rent the car: ";
    cin>>user.days;
    cout<<endl<<endl;
   int z = CarCompare(model);
    
    if(z>=0 && cardata[z].num_car>0 ) // dee 3ashan net2aked en el 3arbya mawgooda fel car data we en 3add el 3arbyat beta3t el model akbar men zero
    {
        userdata[usernumber++]=user;// dee 3ashan nesagl el user ely 7agazo 3arabyat fel global array beta3t el user
        cout<<"This car is available \n";
        cout<<"The price of the car per day is : "<<cardata[z].cost<<endl;
        
        
        
        int x = usercompare(user.name); //da 3ashan negyb el rakam el index bta3 el user
        if(x>=0) //hena 3ashan ne2dar nesgl el reservation number fel user database we negyb el total cost
        {
            int cost= cardata[z].cost*userdata[x].days;
            cout<<"The total cost is : "<<cost<<endl; // dee 3ashan ne7seb el total cost darabna el car dara of el indez fel user data
            srand(time(0));
            userdata[x].reservation=rand()%1000;
            cout<<"Your reservation number is : "<<userdata[x].reservation<<endl;
        }
        cout<<"Your reservation is succefully\n";
        cardata[z].num_car--;
        cars_counter++;
        cardata[z].book_num++;
    }
    else
    {
        cout<<"The car is not available\n";
        goto bb;
    }
}




int favorite_car()
{
    int temp;
    for(int i=0 ; i <=CarNumber-1 ;i++ )
    {
        if(cardata[i].book_num>cardata[i+1].book_num)
        {
            temp=cardata[i].book_num;
            cardata[i].book_num=cardata[i+1].book_num;
            cardata[i+1].book_num=temp;
            return  i;
        }
    }
    return 0;
}


void average_rental_time()
{
    double sum_car=0 ,sum_days=0, avg=0;
    for(int i=0 ; i<CarNumber ; i++)
    {
        sum_car=sum_car+cardata[i].num_car;
    }
    
    for(int i=0 ; i<usernumber ; i++)
    {
        sum_days=sum_days+userdata[i].days;
    }
    avg=sum_days/sum_car;
    cout<<"Average rental time: "<<avg<<endl;
}

void report()
{
    
    cout<<" (1) total number of rented cars per day "<<endl;
    cout<<" (2) favorite rented car "<<endl;
    cout<<" (3) average rental time "<<endl;
    cout<<" (4) renter summary per client "<<endl;
    int choice;
    cout<<"Please enter a choice: "<<endl;
    cin>>choice;
    if(choice==1)
    {
        cout<<"Number of rented cars today are : "<<cars_counter<<endl;
    }
    else if(choice==2)
    {
        int f = favorite_car();
        cout<<"Favorite rented car: "<<cardata[f].car_model<<endl;
    }
   else if (choice==3)
   {
       average_rental_time();
       
   }
    else if (choice==4)
    {
        listUser();
    }
    else
    {
        cout<<"Please enter a correct choice"<<endl;
        
    }
    
}
