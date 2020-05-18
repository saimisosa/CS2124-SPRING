// Saimanasa Juluru
// Rec 09
// CS2124
// 3 April 2020
#include <iostream>
#include <vector>
using namespace std;
class PrintedMaterial {
public:
    PrintedMaterial(unsigned pages) : numberOfPages(pages) {}
    virtual void displayNumPages() const = 0;
protected:
private:
    unsigned numberOfPages;
};

void PrintedMaterial::displayNumPages() const {
    cout << numberOfPages << endl;
}

class Magazine : public PrintedMaterial {
public:
    Magazine(unsigned pages) : PrintedMaterial(pages) {}
    void displayNumPages() const {
        cout << "Magazine Pages: ";
        PrintedMaterial::displayNumPages();
    }
protected:
private:
};

class Book : public PrintedMaterial {
public:
    Book(unsigned pages) : PrintedMaterial(pages) {}
    void displayNumPages() const {
        cout << "Book Pages: ";
        PrintedMaterial::displayNumPages();
    }
protected:
private:

};

class TextBook : public Book {
public:
    TextBook(unsigned pages, unsigned indexPgs) : Book(pages), numOfIndexPages(indexPgs) {}
    void displayNumPages() const {
        cout << "Textbook Pages: ";
        PrintedMaterial::displayNumPages();
        cout << "Textbook Indexes: ";
        cout << numOfIndexPages << endl;
    }
protected:
private:
    unsigned numOfIndexPages;
};

class Novel : public Book {
public:
    Novel(unsigned pages) : Book(pages) {}
    void displayNumPages() const {
        cout << "Novel Pages: ";
        PrintedMaterial::displayNumPages();
    }
protected:
private:
};

void displayNumberOfPages( const PrintedMaterial& paperCollection ){
    paperCollection.displayNumPages();
}
// tester/modeler code
int main()
{
    TextBook t(2101,45);
    Novel n(500);
    Magazine m(10);
//    TextBook t;
//    Novel n;
//    Magazine m;

    t.displayNumPages();
    n.displayNumPages();
    m.displayNumPages();

//    //PrintedMaterial sample(4232);
//    sample.displayNumPages();
//
//    sample = t;
//    sample.displayNumPages(); // slicing

    // trying to use pointers
    PrintedMaterial* pmPtr;
    pmPtr = &t;
    pmPtr->displayNumPages(); // doesnt print out the indexes

    // testing out the general printed material function
    displayNumberOfPages(t);
    displayNumberOfPages(n);
    displayNumberOfPages(m);

    vector<PrintedMaterial*> variousPM;
    variousPM.push_back(&t);
    variousPM.push_back(&m);
    variousPM.push_back(&n);
    cout << endl;
    cout << "task 15; vector stuff" << endl;
    for (const PrintedMaterial* items : variousPM) {
        items->displayNumPages();
    }
}
