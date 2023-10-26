#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Product
{
private:
    int id;
    string name;

public:
    Product(int id, string name)
    {
        this->id = id;
        this->name = name;
    }

    int getId() const
    {
        return id;
    }

    string getName() const
    {
        return name;
    }
};

class Inventory
{
private:
    vector<Product> products;

public:
    void addProduct(Product product)
    {
        products.push_back(product);
        cout << "Product added successfully." << endl;
    }

    void removeProduct(int id)
    {
        for (auto it = products.begin(); it != products.end(); ++it)
        {
            if (it->getId() == id)
            {
                products.erase(it);
                cout << "Product removed successfully." << endl;
                return;
            }
        }
        cout << "Product not found." << endl;
    }

    void printProducts() const
    {
        cout << "Products in Inventory:" << endl;
        for (const Product &product : products)
        {
            cout << "ID: " << product.getId() << ", Name: " << product.getName() << endl;
        }
    }
};

int main()
{
    Inventory inventory;
    cout << "------------------- Inventory Management System (Mid-Term) -------------------" << endl;
    char choice;

    do
    {
        cout << "Please choose an option:" << endl;
        cout << "1. Add a product" << endl;
        cout << "2. Remove a product" << endl;
        cout << "3. View all products" << endl;
        cout << "Q. Quit" << endl;
        cin >> choice;

        switch (choice)
        {
        case '1':
        {
            int id;
            string name;
            cout << "Enter ID: ";
            cin >> id;
            cout << "Enter product name: ";
            cin >> name;
            Product product(id, name);
            inventory.addProduct(product);
            break;
        }

        case '2':
        {
            int id;
            cout << "Enter product ID to remove: ";
            cin >> id;
            inventory.removeProduct(id);
            break;
        }

        case '3':
        {
            inventory.printProducts();
            break;
        }

        case 'q':
        case 'Q':
            cout << "Goodbye!" << endl;
            return 0;

        default:
            cout << "Invalid Choice. Please Try again" << endl;
            break;
        }
    } while (true);

    return 0;
}
