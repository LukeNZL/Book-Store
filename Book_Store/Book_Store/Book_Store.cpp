// Book_Store.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstring>
#include<stdio.h>

using namespace std;

struct Book
{
    char Title[40];
    char Author[20];
    string DOP;
    double price;

   //default constructor
    Book()
    {
        strcpy_s(Title, "Book title");
        strcpy_s(Author, "Author Name");
        DOP = " 00/00/00";
        price = 0.0;
    }

    //parameterized constructor 

    Book( char t[20], char a[20] ,string dop, double p)
    {
        strcpy_s(Title, t);
        strcpy_s(Author, a);
        DOP = dop;
        price = p;
    }
};

struct publication {
    Book book;    // accessing another structure 
    string p_name;
    string contact_no;
    string address;
};

// fuction declartion with passing struct argument 

void display_details(struct Book);

// fuction declartion with returning struct argument
struct Book read_details();

int main()
{
	char t[40], a[20];

	strcpy_s(t, "title");

	strcpy_s(a, "author");

    Book book1, book2, book3{t, a,"12/12/99",102.87}, book[50];//invoking pameterized constructor 

    publication p{book1,"xxx","123456","Auckland" }; // initializing the struct 

    cout << "\n\nAuckland Book Store\n\n";
    cout << "*******************\n";
   
    cout << p.book.Title<<"\n";
    cout << p.book.Author << "\n";
    cout << p.book.DOP << "\n";
    cout << p.book.price << "\n";
    cout << p.contact_no << "\n";
    cout << p.address << "\n";


   // invoke constructor and assign values to the members
    display_details(book1);
    display_details(book3);


    // calling read function  and assigning to the struct object 
    book1 = read_details();
    book2 = read_details();

    // calling display function 
    display_details(book1);
    display_details(book2); 


    // structure array usage 
    for (int i = 0; i < 2; i++)
    {
        book[i] = read_details();
    }
     
    //display the records ..
    for (int i = 0; i < 2; i++)
    {
        display_details(book[i]);
    } 

    cout << "\n\n";
    return 0;
}


void display_details(struct Book book)
{
    cout << "\n Book Details\n\n ";
    cout << "\n Title    : " << book.Title;
    cout << "\n Author   : " << book.Author;
    cout << "\n DOP      : " << book.DOP;
    cout << "\n Price    : " << book.price;
    cout << "\n\n";
}

struct Book read_details()
{
    struct Book book;

    cout << "\nReading Process : \n\n";

    cout << "Enter book Title : ";
    cin.getline(book.Title, 40);
     

    cout << "Enter Author Name : ";
    cin.getline(book.Author, 20);

    cout << "Enter DOP : ";
    cin >> book.DOP;

    cout << "Enter book price : ";
    cin >> book.price;

    cin.ignore();

    return book;
}