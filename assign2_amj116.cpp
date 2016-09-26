/*
File name: assign2_amj116.cpp
Author: Alec (Mason) Jones
Date: 2016-09-27
Assignment Number: 1
CS 2308.001 Fall 2016
Instructor: Jill Seaman

Description: "Electronic Store Inventory: Write a C++ program that
will allow a user to manage the inventory of a small store that sells
electronics like mobile phones, video games, and streaming devices." 
(Jill Seaman, CS 2308 001 and 002 Fall 2016)
*/



#include <iostream>

using namespace std;

struct Product {  
  int sku;
  int quantity;
  float price;
  string productName;
};

const int SIZE = 100;

// 1. ADD a new product to the inventory (prompt user for input values)
void addProduct(int &counter, Product items[]) {

  cout << "Enter the data for the new product in the following order:"
       << endl
       << "sku, quantity, price on one line, and the product name on a separate line"
       << endl;

  // need to input from user. example: $ 1234 3 99.95

  scanf("%i %i %f", &items[counter].sku, &items[counter].quantity, &items[counter].price);
  
  cin >> ws;
  getline(cin, items[counter].productName);
  cout << endl;
  
  counter++;
}

// 2. REMOVE a product from the inventory (by sku).
//void removeProduct() {}

// 3. DISPLAY the inventory _by sku_
//void displayInventory() {}

// 4. LOOKUP a product by sku
//void lookupInventory() {}

// 5. QUIT


int main () {

  int option = 0;
  int counter = 0;
  struct Product items[SIZE];

  do {
    cout << "Manage Inventory Menu\n"
	 << endl
	 << "1. Add product\n"
	 << "5. Quit the program\n";
    
    cin >> option;
    
    switch(option) {
    case 1: addProduct(counter, items);
      break;
      //    case 2: removeProduct();
      //      break;
      //    case 3: displayInventory();
      //      break;
      //    case 4:lookupInventory();
      //      break;
    case 5: break;
    }
  } while (option != 5);

  return 0;
}
