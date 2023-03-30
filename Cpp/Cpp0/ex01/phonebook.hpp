#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

class Contact
{
public:
    std::string ad;
    std::string soyad;
    std::string takmaAd;
    std::string telefon;
    std::string enGizliSir;

    // Constructor
    Contact(){};

    // Destructor
    ~Contact(){};
};

class PhoneBook
{
public:
    Contact kisiler[8];
    int count;
    int tmp_count;

    PhoneBook(){};
    ~PhoneBook(){};
};

#endif // PHONEBOOK_H
