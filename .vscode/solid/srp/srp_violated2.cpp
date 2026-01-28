#include <iostream>
#include <fstream>
using namespace std;

class User {
public:
    string name;
    string email;

    void saveToFile() {
        ofstream file("user.txt");
        file << name << " " << email;
        file.close();
    }

    void printUser() {
        cout << "Name: " << name << ", Email: " << email << endl;
    }
};

int main(){
    User  *user1=new User();
    user1->name="sonu";
    user1->email="asksanoyar@gmail.com";

    user1->saveToFile();
    user1->printUser();
}