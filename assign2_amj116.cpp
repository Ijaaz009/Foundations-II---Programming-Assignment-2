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
#include <iomanip>
#include <stdio.h>

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
  
  scanf("%i %i %f", &items[counter].sku, &items[counter].quantity, &items[counter].price);
  
  cin >> ws;
  getline(cin, items[counter].productName);
  cout << endl;
  
  counter++;
}

// 2. REMOVE a product from the inventory (by sku).
void removeProduct(int &counter, Product items[]) {
  
  int target;
  cout << "Enter sku of product to remove: ";
  cin >> target;
  
  int position = -1; //position of target
  bool found = false; //flag, true when target is found
  
  for (int i=0; i < counter && !found; i++)
    {
      if (items[i].sku == target) //found the target!
	{
	  found = true; //set the flag
	  position = i; //record which item
	  items[i] = items[i+1];
	  counter--;
	    }
    }
  
  if (found == false)
    cout << "Item not found\n"
	 << endl;
}

// * NEED SORT
// 3. DISPLAY the inventory _by sku_
void displayInventory(int counter, Product items[]) {

  cout << endl;

  // error
  bool swap;
  int temp;
  do {
    swap = false;
    for (int i = 0; i <= counter; i++) {
      if (items[i].sku > items[i+1].sku) {
	temp = items[i];
	items[i] = items[i+1];
	items[i+1] = temp;
	swap = true;
      }
    }
  } while (swap);
  
  for (int i = 0 ; i < counter ; i++) {
    cout << setw(5) << right  << items[i].sku << " "
	 << setw(5) << right  << items[i].quantity << " "
	 << setw(8) << setprecision(2) << fixed << right << items[i].price << " "
	 << setw(10) << left << items[i].productName
	 << endl;    
  }
  cout << endl;
}

// 4. LOOKUP a product by sku MUST USE BINARY SEARCH
// BINARY search needed
void lookupInventory(int counter, Product items[]) {

  /*
  int first = 0, //index of beginning of search list
    last = size – 1, //index of end of search list
    middle, //index of midpoint of search list
    position = -1; //position of target value
  bool found = false; //flag
  while (first <= last && !found) {
    middle = (first + last) /2; //calculate midpoint
    if (array[middle] == target) {
      found = true;
      position = middle;
    } else if (target < array[middle]) {
      last = middle – 1; //search list = lower half
    } else {
      first = middle + 1; //search list = upper half
    }
  }
  return position;
  */
}

// 5. QUIT

int main () {

  int option = 0;
  int counter = 0;
  struct Product items[SIZE];

  do {
    cout << "Manage Inventory Menu\n"
	 << endl
	 << "1. Add product\n"
	 << "2. Remove product\n"
	 << "3. Display inventory sorted by sku\n"
	 << "5. Quit the program\n\n"
	 << "Enter your choice: ";

    cin >> option;
    
    switch(option) {
    case 1: addProduct(counter, items);
      break;
    case 2: removeProduct(counter, items);
      break;
    case 3: displayInventory(counter, items);
      break;
    case 4:lookupInventory(counter, items);
      break;
    case 5: cout << "Exiting the program.\n";
      break;
      //    default: cout << "please enter 1, 2, 3, 4, or 5: ";
      //      break;
    }
  } while (option != 5);
  
  return 0;
}
