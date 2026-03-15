#include <iostream>
using namespace std;


class Media {
protected:
    string title;
    int publicationYear;
    int uniqueID;
    string publisher;
    bool isCheckedOut;

public:
    Media(string t, int year, int id, string pub) {
        title = t;
        publicationYear = year;
        uniqueID = id;
        publisher = pub;
        isCheckedOut = false;
    }

    virtual void displayInfo() {
        cout << "Title: " << title << endl;
        cout << "Publication Year: " << publicationYear << endl;
        cout << "ID: " << uniqueID << endl;
        cout << "Publisher: " << publisher << endl;
    }

    void checkOut() {
        if (!isCheckedOut) {
            isCheckedOut = true;
            cout << title << " has been checked out.\n";
        } else {
            cout << title << " is already checked out.\n";
        }
    }

    void returnItem() {
        if (isCheckedOut) {
            isCheckedOut = false;
            cout << title << " has been returned.\n";
        } else {
            cout << title << " was not checked out.\n";
        }
    }

    string getTitle() {
        return title;
    }

    int getYear() {
        return publicationYear;
    }

    virtual ~Media() {}
};

class Book : public Media {
private:
    string author;
    string ISBN;
    int numberOfPages;

public:
    Book(string t, int year, int id, string pub,
         string a, string isbn, int pages)
        : Media(t, year, id, pub) {
        author = a;
        ISBN = isbn;
        numberOfPages = pages;
    }

    void displayInfo() override {
        Media::displayInfo();
        cout << "Author: " << author << endl;
        cout << "ISBN: " << ISBN << endl;
        cout << "Pages: " << numberOfPages << endl;
    }

    string getAuthor() {
        return author;
    }
};

class DVD : public Media {
private:
    string director;
    int duration;
    string rating;

public:
    DVD(string t, int year, int id, string pub,
        string dir, int dur, string rate)
        : Media(t, year, id, pub) {
        director = dir;
        duration = dur;
        rating = rate;
    }

    void displayInfo() override {
        Media::displayInfo();
        cout << "Director: " << director << endl;
        cout << "Duration: " << duration << " minutes\n";
        cout << "Rating: " << rating << endl;
    }
};

class CD : public Media {
private:
    string artist;
    int numberOfTracks;
    string genre;

public:
    CD(string t, int year, int id, string pub,
       string art, int tracks, string g)
        : Media(t, year, id, pub) {
        artist = art;
        numberOfTracks = tracks;
        genre = g;
    }

    void displayInfo() override {
        Media::displayInfo();
        cout << "Artist: " << artist << endl;
        cout << "Tracks: " << numberOfTracks << endl;
        cout << "Genre: " << genre << endl;
    }
};


class Magazine : public Media {
private:
    int issueNumber;

public:
    Magazine(string t, int year, int id, string pub, int issue)
        : Media(t, year, id, pub) {
        issueNumber = issue;
    }

    void displayInfo() override {
        Media::displayInfo();
        cout << "Issue Number: " << issueNumber << endl;
    }
};

class Library {
private:
    Media* items[20];
    int count;

public:
    Library() {
        count = 0;
    }

    void addItem(Media* m) {
        if (count < 20)
            items[count++] = m;
    }

    void search(string title) {
        cout << "\nSearching by Title...\n";
        for (int i = 0; i < count; i++) {
            if (items[i]->getTitle() == title)
                items[i]->displayInfo();
        }
    }

    
    void search(int year) {
        cout << "\nSearching by Year...\n";
        for (int i = 0; i < count; i++) {
            if (items[i]->getYear() == year)
                items[i]->displayInfo();
        }
    }

    void searchByAuthor(string author) {
        cout << "\nSearching by Author...\n";
        for (int i = 0; i < count; i++) {
            Book* b = dynamic_cast<Book*>(items[i]);
            if (b && b->getAuthor() == author)
                b->displayInfo();
        }
    }
};

int main() {

    Library lib;

    Book b1("C++ Programming", 2020, 101, "TechPress", "Bjarne", "12345", 500);
    DVD d1("Inception", 2010, 201, "Warner Bros", "Christopher Nolan", 148, "PG-13");
    CD c1("Thriller", 1982, 301, "Epic Records", "Michael Jackson", 9, "Pop");
    Magazine m1("National Geographic", 2023, 401, "NatGeo", 15);

    lib.addItem(&b1);
    lib.addItem(&d1);
    lib.addItem(&c1);
    lib.addItem(&m1);

    cout << "\n--- Media Details ---\n";
    b1.displayInfo();
    cout << endl;

    d1.displayInfo();
    cout << endl;


    b1.checkOut();
    b1.returnItem();


    lib.search("C++ Programming");
    lib.search(2010);
    lib.searchByAuthor("Bjarne");

    return 0;
}