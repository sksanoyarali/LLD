#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class MySqlDatabase{
    public:
    void saveToMySqlDatabase(string name){
        cout<<"Saved user in mySql databse the user name is:"<<name<<endl;
    }
};
class MongoDbDatabase{
    public:
    void saveToMongodbDatabase(string name){
        cout<<"Saved user in mongodb databse the user name is:"<<name<<endl;
    }
};

class UserService{
    private:
    MySqlDatabase sqlDb;
    MongoDbDatabase mongoDb;

    public:
    void storeUserToMysql(string user){
        sqlDb.saveToMySqlDatabase(user);
    }
    void storeUserToMongodb(string user){
        mongoDb.saveToMongodbDatabase(user);
    }
};
int main(){
    UserService service;
    service.storeUserToMysql("sanoyar");
    service.storeUserToMongodb("asgar");
}