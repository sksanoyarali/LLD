#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Database{
    public:
    virtual void save(string user)=0;
};
class MySqlDatabase:public Database{
    public:
    void save(string name) override{
        cout<<"Saved user in mySql databse the user name is:"<<name<<endl;
    }
};
class MongoDbDatabase:public Database{
    public:
    void save(string name) override{
        cout<<"Saved user in mongodb databse the user name is:"<<name<<endl;
    }
};

class UserService{
    private:
    Database* db;

    public:
    UserService(Database* db){
        this->db=db;
    }
    void storeUser(string user){
        db->save(user);
    }
};
int main(){
    MySqlDatabase mysql;
    MongoDbDatabase mongoDb;
    UserService service1(&mysql);
    service1.storeUser("sanoyar");
    service1.storeUser("zafar");
    UserService service2(&mongoDb);
    service2.storeUser("asgar");

    return 0;
}