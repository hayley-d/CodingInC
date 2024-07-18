#include <iostream>
struct document;

/*struct IMachine{
    virtual void print(Document& doc) = 0;
    virtual void scan(Document& doc) = 0;
    virtual void fax(Document& doc) = 0;
};*/

//Segregate the functions into their own interfaces

struct IPrinter{
    virtual void print(Document& doc) = 0;
};

struct IScanner{
    virtual void scan(Document& doc) = 0;
};

struct IFaxer{
    virtual void fax(Document& doc) = 0;
};


struct MFP : IMachine{
    void print(Document& doc) override{
        //do something
    }

    void scan(Document& doc) override{
        //do something
    }

    void fax(Document& doc) override{
        //do something
    }
};

struct Scanner : IScanner {

    void scan(Document& doc) override{
        //Need this function
    }

};

int main() {

    return 0;
}
