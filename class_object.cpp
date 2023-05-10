#include<iostream>

using namespace std;

class Book{
public:
    string title;
    string  author;
    int pages;
    Book(string ttitle,string tauthor,int tpages){
        title=ttitle;
        author=tauthor;
        pages=tpages;
    }

};

int main(){

    Book book1("Harry Potter","JK Rolling",900);
    Book book2("Percy Jackson","JK Stoning",781);


    cout<<book1.title<<"\t"<<book2.pages<<endl;
    return 0;
}
