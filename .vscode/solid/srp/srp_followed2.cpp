#include <iostream>
#include <fstream>

using namespace std;
class User{
    public:
    string name;
    string email;
     User(string name,string email):name(name),email(email){

     }
};

class UserRepository {
public:
    void save(const User* user) {
        ofstream file("user.txt");
        file << user->name << " " << user->email;
        file.close();
    }
};

class UserPrinter {
public:
    void print(const User* user) {
        cout << "Name: " << user->name 
             << ", Email: " << user->email << endl;
    }
};

int main(){
    User* user=new User("sonu","asksanoyar33@gmail.com");
    UserRepository ur;
    UserPrinter up;
    cout<<"Save method"<<endl;
    ur.save(user);
    cout<<"Print method"<<endl;
    up.print(user);
}