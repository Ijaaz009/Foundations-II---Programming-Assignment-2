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
    string productName;
    int sku;
    int quantity;
    float price;
};

const int SIZE = 100;

// 1. ADD a new product to the inventory (prompt user for input values)
void addProduct() {}

// 2. REMOVE a product from the inventory (by sku).
//void removeProduct() {}

// 3. DISPLAY the inventory _by sku_
//void displayInventory() {}

// 4. LOOKUP a product by sku
//void lookupInventory() {}

// 5. QUIT


int main () {

  int option = 0;

  Product items[SIZE];
  
  
  addProduct();
  
  //    removeProduct();
  //    displayInventory();
  //    lookupInventory();
  
   return 0;
}
