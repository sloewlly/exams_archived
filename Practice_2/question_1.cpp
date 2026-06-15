#include <iostream>
#include <string>
#include <vector>

class Media {
    protected:
    std::string commonField;
    double price;
    public:
    Media(std::string commonField, double price) : commonField(commonField), price(price) {}
    virtual ~Media() = default;
    virtual void describe() const {}
};

class Book : public Media{
    public:
    Book(std::string name, double price) : Media(name, price) {}
    void describe() const override {
        std::cout << "Name: " << commonField << std::endl;
        std::cout << "Price: $ " << price << std::endl;
    }
};

class CD : public Media{
    public:
    CD(std::string ID, double price) : Media(ID, price) {}
    void describe() const override {
        std::cout << "Name: " << commonField << std::endl;
        std::cout << "Price: $" << price << std::endl;
    }
};

class Library {
    private:
    std::string name;
    std::vector<Media*> listofMedia;
    public:
    Library(std::string name) : name(name) {}
    void addMedia(Media* media) {
        listofMedia.push_back(media);
    }
    void describe() const {
        std::cout << "Library content: " << std::endl;
        std::cout << "Library's name: " << name << std::endl;
        for (const auto& media : listofMedia) {
            media->describe();
        }
    }
};

int main() {
    Book bookA("History of Vietnamese-German University", 10.99);
    CD cdA("Wolfgang Mozart's mixtape #9", 2.99);

    bookA.describe();
    cdA.describe();

    Book bookB("The path of mastering C++ programming language", 20.99);
    CD cdB("Ludwig van Beethoven's mixtape #9", 3.99);

    Library myLibrary("The library of Vietnamese-German University");

    myLibrary.addMedia(&bookA);
    myLibrary.addMedia(&bookB);
    myLibrary.addMedia(&cdA);
    myLibrary.addMedia(&cdB);

    myLibrary.describe();

    return 0;
}