#include<iostream>
using namespace std;
class employee{
    protected:
    float salary;
    char*name;
    public:
    employee(float s,char*n){
        this->name=n;
        this->salary=s;
    }
    friend ostream & operator<<(ostream&o,employee&e){
        return(o<<e.name<<"   is paid   "<<e.salary);

    }
   virtual void paycut(float amt){
       salary -=amt;
   }
   void payrise(){
       salary +=800;
   }

};




class manager:public employee{
    private:
    int level;
    public:
   


    manager(int l,char*n):employee(1000*l,n){

         level=l;
    }
    friend ostream& operator&&(ostream&o,manager&m){
        return(o<<m<<"  ,at level "<<m.level);
    }
    virtual void paycut(float amt){
        salary+=(level*amt);

    }
    void payrise(){
        salary+=100;
    }
};


class supermanager:public manager{
    public:
    supermanager(char*n):manager(10,n){

    }
    virtual void paycut(float a){
        salary*=2;
    }


};
int main(){
    cout<<"         employee       "<<endl;
    employee E(12000,"arham");
    cout<<E<<endl;
    E.paycut(300);
    
    cout<<E<<endl;
    E.payrise();
    

    cout<<E<<endl;

    cout<<"manager"<<endl;
    manager M(6,"irtiza");
    cout<<M<<endl;
    (cout&&M)<<endl;

    M.paycut(10);

    cout<<M<<endl;
    M.payrise();
    cout<<M<<endl;
    employee *e1=new employee(80000,"shakir");
    employee *e2=new supermanager("billo");
    cout<<"shakir is a employee"<<endl;
    cout<<*e1<<endl;
    e1->paycut(300);     //virtual function, binded at runtime (Runtime polymorphism)
     cout<<*e1<<endl;
    e1->payrise();     // Non-virtual function, binded at compile time
    cout<<*e1<<endl;
    cout<<"now shakir is promoted to super manager"<<endl;
    //for promotion from employee to super manager 
    *e2=*e1;
    cout<<*e2<<endl;
    e2->paycut(300);  //virtual function, binded at runtime (Runtime polymorphism)

    cout<<*e2<<endl;
    e2->payrise();   // Non-virtual function, binded at compile time
    cout<<*e2<<endl;




    // M.employee::paycut(300);



    return 0;
};






// int main(){
//     manager m(5,"kashif");
//     employee e(400,"aliza");
//     cout<<e<<endl;
//     cout<<m<<endl;
//     (cout &&m)<<endl;
//     return 0;



//     output:
//     aliza   is paid   400
//     kashif   is paid   5000
//     kashif   is paid   5000    ,at level    0
// };