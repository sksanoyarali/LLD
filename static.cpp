#include<iostream>
using namespace std;
void count() {
    static int x = 0;
    x++;
    cout << x << endl;
}
int main(){
    count();
    count();
    count();
}
// initialized only once
//persist between function function call

//statis member function belongs to class even before 
//  a object is created it still exist