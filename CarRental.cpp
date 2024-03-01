#include<iostream>
#include<fstream>
#include<vector>
#include<unordered_set>
#include<unordered_map>
#include<string>

using namespace std;

class User{
    public:
    string ID;
    string Password;
   public:
    string Name;
   void setPassword(string Password){
    this->Password=Password;
   }
   void setID(string ID){
    this->ID=ID;
   }
   string getPassword(){
    return Password;
   }
   string getID(){
    return ID;
   }
};
class Car{
  public:
    string model;
    int value;
    int condition; //from 0 to 100 percent
  public:
    Car(string name,int value,int condition){
        this->model=name;
        this->value=value;
        this->condition=condition;
    };
};
class Customer : public User{
   public:
   int rent_lim;
   int rent_score;
   unordered_set<string> rented_cars;

   public:
   Customer(string Name,string ID,string Password){
        this->Name=Name;
        setPassword(Password);
        setID(ID);
        rent_lim=3;
        rent_score=5;
   }
   Customer(string Name,string ID,string Password,int rent_lim,int rent_score,unordered_set<string> &rented_cars){
        this->Name=Name;
        setPassword(Password);
        setID(ID);
        this->rent_lim=rent_lim;
        this->rent_score=rent_score;
        this->rented_cars=rented_cars;
   }
   ~Customer(){}
   
   void return_request(unordered_set<string>&Cars,unordered_map<string,string> & CarOwner,vector<Car*> &AllCars){
              string car_to_return ; int days; int max_days=30; int fine_per_day=30; int condition;
              std::cout<<"Which car would you like to return ?\n";
              std::cin>>car_to_return ;
              std::cout<<"For how long you have taken the car?\n";
              std::cin>>days;
              rented_cars.erase(car_to_return);
              Cars.insert(car_to_return);
              CarOwner.erase(car_to_return);
              std::cout<<"Fine is "<<max(0,days-max_days)*fine_per_day<<"\n";
              if(days<=max_days) {
                rent_score=min(10,++rent_score); 
                std::cout<<"Congratulations, your rent_score increased. Keep up the punctuality.\n";
              }
              else {
                 rent_score=max(1,--rent_score);
                 std::cout<<"Your rent_score decreased. Please try to return the car on time.\n";
              }
              std::cout<<"what's the current condition of the car as stated by our mechanic?\n";
              std::cin>>condition;
              
              for(int i=0;i<AllCars.size();i++) if(AllCars[i]->model==car_to_return) AllCars[i]->condition=condition;
   }
   void rent(unordered_set<string>& Cars,unordered_map<string,string>& CarOwner,vector<Car*> &Allcars){
              string car_to_rent; int price_per_day=20;
              std::cout<<"Which car would you like to rent ?\n";

              for(auto x:Cars) std::cout<<x<<" ";

              std::cout<<"\n";
              std::cin>>car_to_rent;
              int value;
              for(int i=0;i<Allcars.size();i++) if(Allcars[i]->model==car_to_rent) value=Allcars[i]->value;

              if(rent_lim>rented_cars.size()){
                if(value<=rent_score){
                int days; string flag;
                std::cout<<"For how long you want the car?\n";
                std::cin>>days;
                std::cout<<"Do you accept the deal for "<<days*price_per_day<<"?\n";
                std::cout<<"Type---->yes or Type---->no\n";
                std::cin>>flag;
                if(flag=="yes"){
                rented_cars.insert(car_to_rent);
                Cars.erase(car_to_rent);
                CarOwner[car_to_rent]=Name;
                std::cout<<"Deal Successful, remember to return on time\n";
                }
                }
                else std::cout<<"You cannot rent this car due to less rent_score\n";
              }
              else{
                std::cout<<"Maximum limit reached. Can't rent the car!\n";
              }
   }
   friend void verify(vector<Customer*>&customers,int &flag,int &i,string id,string password){
    for(i=0;i<customers.size();i++){
            if(((customers[i])->getID()==id)&&((customers[i])->getPassword()==password)) {flag=1;break;}
        }
   }
   
   
};
class Employee : public User{ 
    public:
    int rent_lim;
    int rent_score;
    
    unordered_set<string> rented_cars;
    Employee(string Name,string ID,string Password){
        this->Name=Name;
        setPassword(Password);
        setID(ID);
        rent_lim=3;
        rent_score=5;
    }
    Employee(string Name,string ID,string Password,int rent_lim,int rent_score,unordered_set<string> &rented_cars){
        this->Name=Name;
        setPassword(Password);
        setID(ID);
        this->rent_lim=rent_lim;
        this->rent_score=rent_score;
        this->rented_cars=rented_cars;
   }

    ~Employee(){}
    
    void return_request(unordered_set<string>&Cars,unordered_map<string,string>&CarOwner,vector<Car*> &AllCars){
              string car_to_return ; int days; int max_days=30; int fine_per_day=30; int condition;
              std::cout<<"Which car would you like to return ?\n";
              std::cin>>car_to_return ;
              std::cout<<"For how long you have taken the car?\n";
              std::cin>>days;
              rented_cars.erase(car_to_return);
              Cars.insert(car_to_return);
              CarOwner.erase(car_to_return);
              std::cout<<"Fine is "<<max(0,days-max_days)*fine_per_day<<"\n";
              std::cout<<"what's the current condition of the car as stated by our mechanic?\n";
              std::cin>>condition;
              
              for(int i=0;i<AllCars.size();i++) if(AllCars[i]->model==car_to_return) AllCars[i]->condition=condition;

              if(days<=max_days) {
                rent_score=min(10,++rent_score); 
                std::cout<<"Congratulations, your rent_score increased. Keep up the punctuality.\n";
              }
              else {
                 rent_score=max(1,--rent_score);
                 std::cout<<"Your rent_score decreased. Please try to return the car on time.\n";
              }
    }
    void rent(unordered_set<string>& Cars,unordered_map<string,string>&CarOwner,vector<Car*> &Allcars){
              string car_to_rent; int price_per_day=20;
              std::cout<<"Which car would you like to rent ?\n";

              for(auto x:Cars) std::cout<<x<<" ";

              std::cout<<"\n";
              std::cin>>car_to_rent;
              int value;
              for(int i=0;i<Allcars.size();i++) if(Allcars[i]->model==car_to_rent) value=Allcars[i]->value;

              if(rent_lim>rented_cars.size()){
                if(value<=rent_score){
                int days; string flag;
                std::cout<<"For how long you want the car?\n";
                std::cin>>days;
                std::cout<<"Do you accept the deal for "<<days*price_per_day<<"?\n";
                std::cout<<"Type---->yes or Type---->no\n";
                std::cin>>flag;
                if(flag=="yes"){
                rented_cars.insert(car_to_rent);
                Cars.erase(car_to_rent);
                CarOwner[car_to_rent]=Name;
                std::cout<<"Deal Successful, remember to return on time\n";
                }
                }
                else std::cout<<"You cannot rent this car due to less rent_score\n";
              }
              else{
                std::cout<<"Maximum limit reached. Can't rent the car!\n";
              }
   }
   friend void verify(vector<Employee*>&employees,int &flag,int &i,string id,string password){
    for(i=0;i<employees.size();i++){
            if(((employees[i])->getID()==id)&&((employees[i])->getPassword()==password)) {flag=1;break;}
        }
   }
};
class Manager : public User{
    public:
    Manager(string Name,string ID,string Password){
        this->Name=Name;
        setPassword(Password);
        setID(ID);
    }
    ~Manager(){}
    
    void add_employee(vector<Employee*> &employees){
            string name,id,password;
               cout<<"Provide name\n";
               cin>>name;
               cout<<"Provide id\n";
               cin>>id;
               cout<<"Provide password\n";
               cin>>password;

            Employee* newemployee = new Employee(name,id,password);
               employees.push_back(newemployee);
    }
    void add_customer(vector<Customer*> &customers){
            string name,id,password;
               cout<<"Provide name\n";
               cin>>name;
               cout<<"Provide id\n";
               cin>>id;
               cout<<"Provide password\n";
               cin>>password;

            Customer* newcustomer = new Customer(name,id,password);
               customers.push_back(newcustomer);
    }
    void del_Customer(vector<Customer*> &customers,unordered_map<string,string>&CarOwner,unordered_set<string> &Cars){
         string customer_to_remove;
               cin>>customer_to_remove;
            
               int j;
               for(int j=0;j<customers.size();j++) if((customers[j]->Name)==customer_to_remove) break;
               for(auto y:(customers[j])->rented_cars){ CarOwner.erase(y); Cars.insert(y);}
               
               vector<Customer*> temporary;
               for(auto x:customers){
                if(x->Name!=customer_to_remove) temporary.push_back(x);
               }
               customers=temporary;
    }
    void del_Employee(vector<Employee*> &employees,unordered_map<string,string>&CarOwner,unordered_set<string> &Cars){
         string employee_to_remove;
               cin>>employee_to_remove;
            
               int j;
               for(int j=0;j<employees.size();j++) if((employees[j]->Name)==employee_to_remove) break;
               for(auto y:(employees[j])->rented_cars){ CarOwner.erase(y); Cars.insert(y);}
               
               vector<Employee*> temporary;
               for(auto x:employees){
                if(x->Name!=employee_to_remove) temporary.push_back(x);
               }
               employees=temporary;
    }
    void newCar(unordered_set<string> &Cars,vector<Car*> &Allcars){
         std::cout<<"Enter new car name.\n";
         string name; int condition; int val;
         std::cin>>name;
         std::cout<<"Enter new car value and condition.\n";
         std::cin>>val>>condition;
         
         Car* newcar= new Car(name,val,condition);
         Allcars.push_back(newcar);
         Cars.insert(name);
         std::cout<<"Addition Successful!\n";
    }
    string Car_holding(unordered_map<string,string> &CarOwner){
               string car;
               std::cout<<"what car?\n";
               getline(std::cin,car);
               return CarOwner[car];
    }
    friend void verify(vector<Manager*>&managers,int &flag,int &i,string id,string password){
    for(i=0;i<managers.size();i++){
            if(((managers[i])->getID()==id)&&((managers[i])->getPassword()==password)) {flag=1;break;}
        }
   }
};

int main(){

    ifstream fcustomers,fcars,femployees,fmanagers,fcarOwner,fallcars;
    fcustomers.open("Custs.txt");
    fcars.open("Cars.txt");
    femployees.open("Employees.txt");
    fmanagers.open("Managers.txt");
    fcarOwner.open("CarOwner.txt");
    fallcars.open("Allcars.txt");
    
    //loading all data
    string line;
    vector<Customer*> customers;
    fcustomers.seekg(0, ios::beg);
    
    while(getline(fcustomers,line)){
        string name,id,password,rented_cars;
        int limit,score;
        name=line; 
        getline(fcustomers,line);
        id=line;
        getline(fcustomers,line);
        password=line;
        getline(fcustomers,line);
        limit=stoi(line);
        getline(fcustomers,line);
        score=stoi(line);
        getline(fcustomers,line);
        string car; unordered_set<string> cars;
        for(int i=0;i<line.size();i++){
            if(line[i]==',') {cars.insert(car);car="";}
            else car+=line[i];
        }
        Customer* newcustomer = new Customer(name,id,password,limit,score,cars);
        customers.push_back(newcustomer);
    }
    
    vector<Employee*> employees;
    femployees.seekg(0, ios::beg);
    while(getline(femployees,line)){

        string name,id,password,rented_cars;
        int limit,score;

        name=line;
        getline(femployees,line);
        id=line;
        getline(femployees,line);
        password=line;
        getline(femployees,line);
        limit=stoi(line);
        getline(femployees,line);
        score=stoi(line);
        getline(femployees,line);
        rented_cars=line;

        
        string car; unordered_set<string> cars;
        for(int i=0;i<line.size();i++){
            if(line[i]==',') {cars.insert(car);car="";}
            else car+=line[i];
        }
        
        Employee* newemployee = new Employee(name,id,password,limit,score,cars);
        employees.push_back(newemployee);
    }

    vector<Manager*> managers;
    fmanagers.seekg(0, ios::beg);
    while(getline(fmanagers,line)){
        string name,id,password;

        name=line;
        getline(fmanagers,line);
        id=line;
        getline(fmanagers,line);
        password=line;
        
        Manager* newmanager = new Manager(name,id,password);
        managers.push_back(newmanager);
    }

    unordered_set<string> Cars;
    fcars.seekg(0, ios::beg);
    while(getline(fcars,line)){
        string car;
        for(int i=0;i<line.size();i++){
            if(line[i]==',') {Cars.insert(car);car="";}
            else car+=line[i];
        }
    }
    
    unordered_map<string,string> CarOwner;
    fcarOwner.seekg(0,ios::beg);
    while(getline(fcarOwner,line)){
        string line1=line;string line2;
        getline(fcarOwner,line);
        line2=line;
        CarOwner[line1]=line2;
    }
    vector<Car*> Allcars;
    fallcars.seekg(0,ios::beg);
    while(getline(fallcars,line)){
        string model;int value;int condition;
        model=line;
        getline(fallcars,line);
        value=stoi(line);
        getline(fallcars,line);
        condition=stoi(line);

        Car * acar= new Car(model,value,condition);
        Allcars.push_back(acar);
    }
    
    fcustomers.close(),fmanagers.close(),femployees.close(),fcars.close(),fcarOwner.close(),fallcars.close();

    //switch
    string designation,id,password;
    std::cout<<"Enter your designation:\n";
    std::cin>>designation; 
    std::cout<<"Enter your ID:\n";
    std::cin>>id;
    std::cout<<"Enter your password:\n";
    std::cin>>password;
    
    //checking existing database of users
    int flag=0;int i;
    if(designation=="customer"){
        verify(customers,flag,i,id,password);
    }
    if(designation=="employee"){
        verify(employees,flag,i,id,password);
    }
    if(designation=="manager"){
        verify(managers,flag,i,id,password);
    }
    
    //if such a user exits
    if(flag){
        if(designation=="customer"){
            std::cout<<"Type---->abort to end the program\nType---->return to return a car\nType---->rent to rent a car from the collection\n";
            string method;
           while(getline(std::cin,method)){
            
            std::cin>>method;
            if(method=="abort") break;

            if(method=="return"){
              customers[i]->return_request(Cars,CarOwner,Allcars);
            }
            if(method=="rent"){
              customers[i]->rent(Cars,CarOwner,Allcars);
            }
           }
        }
        else if(designation=="employee"){
            std::cout<<"Type---->abort to end the program\nType---->return to return a car\nType---->rent to rent a car from the collection\n";
            string method;
            while(getline(std::cin,method)){
            
            std::cin>>method;
            if(method=="abort") break;

            if(method=="return"){
              employees[i]->return_request(Cars,CarOwner,Allcars);
            }
            if(method=="rent"){
              employees[i]->rent(Cars,CarOwner,Allcars);
            }
           }
        }
        else {
           std::cout<<"Type---->abort to end the program\nType---->AddCustomer to add a new customer\nType---->AddEmployee to add a new employee\nType---->CarOwner to know the owner of the desired rented car\nType---->RemoveCustomer to remove a customer from the database\nType---->RemoveEmployee to remove an employee from the database\nType---->AddCar to add a new car in the store's collection\n";
           string method;
           while(getline(std::cin,method)){
            
            if(method=="abort") break;
            if(method=="AddCustomer"){
               managers[i]->add_customer(customers);
            }
            if(method=="AddEmployee"){
               managers[i]->add_employee(employees);
            }
            if(method=="CarOwner"){
               std::cout<<managers[i]->Car_holding(CarOwner)<<"\n";
            }
            if(method=="RemoveCustomer"){
               managers[i]->del_Customer(customers,CarOwner,Cars);
            }
            if(method=="RemoveEmployee"){
               managers[i]->del_Employee(employees,CarOwner,Cars);
            }
            if(method=="AddCar"){
                managers[i]->newCar(Cars,Allcars);
            }
           }
        }
    }
    //if such a user dosen't exist
    else std::cout<<"Get yourself registered by contacting one of the managers\n";

    //writing the data back on to the files
    ofstream f1customers,f1managers,f1employees,f1cars,f1carOwner,f1allcars;
    f1customers.open("Custs.txt");
    f1managers.open("Managers.txt");
    f1employees.open("Employees.txt");
    f1cars.open("Cars.txt");
    f1allcars.open("Allcars.txt");
    f1carOwner.open("CarOwner.txt");
    for(int i=0;i<(customers).size();i++){
        f1customers<<(customers[i])->Name<<"\n";
        f1customers<<(customers[i])->ID<<"\n";
        f1customers<<(customers[i])->Password<<"\n";
        f1customers<<(customers[i])->rent_lim<<"\n";
        f1customers<<(customers[i])->rent_score<<"\n";
        
        for(auto x:(customers[i])->rented_cars){
            f1customers<<x<<",";
        }
        f1customers<<"\n";
    }
    for(int i=0;i<(employees).size();i++){
        f1employees<<(employees[i])->Name<<"\n";
        f1employees<<(employees[i])->ID<<"\n";
        f1employees<<(employees[i])->Password<<"\n";
        f1employees<<(employees[i])->rent_lim<<"\n";
        f1employees<<(employees[i])->rent_score<<"\n";
        
        for(auto x:(employees[i])->rented_cars){
            f1employees<<x<<",";
        }
        f1employees<<"\n";
    }
    for(int i=0;i<(managers).size();i++){
        f1managers<<(managers[i])->Name<<"\n";
        f1managers<<(managers[i])->ID<<"\n";
        f1managers<<(managers[i])->Password<<"\n";
    }
    
    for(auto x: Cars){
        f1cars<<x<<",";
    }
    for(auto y: CarOwner){
        f1carOwner<<y.first<<"\n";
        f1carOwner<<y.second<<"\n";
    }
    for(int i=0;i<Allcars.size();i++){
        f1allcars<<Allcars[i]->model<<"\n";
        f1allcars<<Allcars[i]->value<<"\n";
        f1allcars<<Allcars[i]->condition<<"\n";
    }

    f1employees.close();f1customers.close();f1managers.close();f1cars.close();f1carOwner.close(),f1allcars.close();
    return 0;
}
