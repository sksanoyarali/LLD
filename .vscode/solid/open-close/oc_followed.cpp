#include<iostream>
#include<vector>
using namespace std;
class Product{
    public:
    string name;
    double price;
    Product(string name,double price){
        this->name=name;
        this->price=price;
    }
};
// only responsible for cart related business logic
class ShoppingCart{
    private:
    vector<Product*>products;
    public:
    void addProduct(Product* p){
        products.push_back(p);
    }

    const vector<Product*> getProducts(){
        return products;
    }
    // calculate total price of cart
    int calculateTotal(){
        int total=0;
        for(auto p:products){
            total+=p->price;
        }
        return total;
    }
};
// ShoppingCartPrinter:only responsible for printing invoice
class ShoppingCartPrinter{
    private:
    ShoppingCart * cart;
    public:
    ShoppingCartPrinter(ShoppingCart* cart){
        this->cart=cart;
    }

    void printInvoice(){
        cout<<"Shopping cart invoice";
        for(auto p:cart->getProducts()){
            cout<<p->name<<" -RS "<<p->price<<endl;
        }
        cout<<"Total price:"<<cart->calculateTotal()<<endl;
    }
};

class Persistense{
    private:
    ShoppingCart* cart;
    public:
    virtual void save(ShoppingCart* cart)=0;//pure virtual function
};
class SQLPersistence:public Persistense{
    public:
    void save(ShoppingCart* cart) override{
        cout << "Saving shopping cart to SQL DB..." << endl;
    }
};
class MongoPersistence:public Persistense{
    public:
    void save(ShoppingCart* cart) override{
        cout << "Saving shopping cart to MONGO DB..." << endl;
    }
};
class FilePersistence:public Persistense{
    public:
    void save(ShoppingCart* cart) override{
        cout << "Saving shopping cart to file..." << endl;
    }
};

int main(){
    ShoppingCart* cart=new ShoppingCart();

    cart->addProduct(new Product("Laptop", 50000));
    cart->addProduct(new Product("Mouse", 2000));

    ShoppingCartPrinter* printer = new ShoppingCartPrinter(cart);
    printer->printInvoice();

    Persistense * db=new SQLPersistence();
    Persistense * mongo=new MongoPersistence();
    Persistense * file=new FilePersistence();

    db->save(cart);
    mongo->save(cart);
    file->save(cart);
    return 0;
}