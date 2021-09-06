#include "car.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <cstdlib>


using namespace std;

double fileread(vector<Car>& cars){

    string filename;
    string getcontent;
    ifstream is;
    cin >> filename;
    filename.append(".txt");
    is.open(filename.c_str());

    if (!is.is_open()) {
        exit(EXIT_FAILURE);
    }
    Car c;
    /*if you need to also read balance from the begining of the file uncomment, and return the balance instead of 0:
     * (if it is writen to the end place is>>balance after the loop)
     *double balance;
     is>>balance;*/
    while (is>>c)
    {
        cars.push_back(c);        
    }
    is.close();

    return 0;
}

int main()
{
    int option;
    string name;
    string color;
    double price = 0;
    double balance = 10000;
    vector <Car> cars;

    do
    {
        cout << "Please select an option:" << endl;
        cout << "1 - Show current inventory." << endl;
        cout << "2 - Show current balance." << endl;
        cout << "3 - Buy a car." << endl;
        cout << "4 - Sell a car." << endl;
        cout << "5 - Paint a car." << endl;
        cout << "6 - Load file." << endl;
        cout << "7 - Save file." << endl;
        cout << "8 - Quit program." << endl;
        cout << "\n";

        cin >> option;

        if (option == 1)
        {
            for (int i = 0; i < cars.size(); i++)
            {
                cout << cars[i].toString() <<"\n";
            }
        }
        else if (option == 2)
        {
            cout << "$" << balance << endl;
        }
        else if (option == 3)
        {
            cout << "Please enter the name, color, and price of the car you would like to buy." << endl;
            cin >> name;
            cin >> color;
            cin >> price;
            Car newcar(name, color, price);

            if (price <= balance)
            {
                cars.push_back(newcar);
                cout << "Car has been purchased." << endl;
                balance = balance - price;
            }
            else
            {
                cout << "You cannot afford that car." << endl;
                option = 0;
            }
        }
        else if (option == 4)
        {
            cout << "Please enter the name of the car you want to sell." << endl;
            cin >> name;
            bool found = false;
            int index;
            for (int j = 0; j < cars.size(); j++)
            {
                if (cars[j].getName() == name)
                {
                    found = true;
                    price = cars[j].getPrice();
                    cars.erase(cars.begin() + j);
                    cout << "You have sold the " << name << endl;
                    balance = balance + price;
                }
            }
            if (!found)
            {
                cout << "You don't own that car." << endl;
            }
        }
        else if (option == 5)
        {
            cout << "Please enter the name of the car you want to paint." << endl;
            cin >> name;
            bool found = false;

            for (int j = 0; j < cars.size(); j++)
            {
                if (cars[j].getName() == name)
                {
                    found = true;
                    cout << "What color do you want to paint the " << name << "?" << endl;
                    cin >> color;
                    cars[j].paint(color);
                    cout << "You have painted the " << name << " " << color << "." << endl;
                }
            }
            if (!found)
            {
                cout << "You don't own that car." << endl;
            }
        }
        else if (option == 6)
        {
            string chooseFile;
            cout<<"File name: ";
            //if the balance should be read too 
            //balance = fileread(cars);
            //if not:
            fileread(cars);
        }
        else if (option == 7)
        {
            for (int i = 0; i < cars.size(); i++)
            {
                ofstream fout;
                fout.open("cars3.txt");
                fout << cars[i].toString() << endl;
                fout << "$" << balance << endl;
            }
        }
        else if (option == 8) 
        {
            exit(0); //Why? the loop ends anyway
        }
        else
        {
            cout << "Please enter a number from 1-8." << endl;
        }

        cout << "\n";
    } while (option != 8);
}

