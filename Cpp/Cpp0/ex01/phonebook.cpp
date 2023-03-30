#include    "phonebook.hpp"

void    Search(PhoneBook *str){

    std::string seperator = ".-------------------------------------------.\n";
    std::string temp_int;
    int i = 1;
    int kisiNo;

    if (str->count == 1)
    {
        std::cout << "\033[33mKişi Bilgisi Yok\n\033[0m" << std::endl;
        return ;
    }
    if(str->count < str->tmp_count)
        str->count = str->tmp_count;

    std::cout << "\n\033[32mKayıtlı Kişiler\033[0m" << std::endl;

    while (str->count > i)
    {
        std::cout << seperator
        << "|" << std::setw(10) << i
        << "|" << std::setw(10) << (str->kisiler[i].ad.length() > 10 ? str->kisiler[i].ad.substr(0,9) + "." : str->kisiler[i].ad)
        << "|" << std::setw(10) << (str->kisiler[i].soyad.length() > 10 ? str->kisiler[i].soyad.substr(0,9) + "." : str->kisiler[i].soyad)
        << "|" << std::setw(10) << (str->kisiler[i].takmaAd.length() > 10 ? str->kisiler[i].takmaAd.substr(0,9) + "." : str->kisiler[i].takmaAd)
        << "|" << std::endl << seperator;
        i++;
    }
    std::cout << "Kişi numarasını girin: ";
    std::getline(std::cin,temp_int);
	std::istringstream my_stream(temp_int); //Stringin integer çevrilip çevrilmediğine göre işlem yapıyor.
    if(!(my_stream >> kisiNo))
	{
		std::cout<<"\033[1;31mENTER A VALID NUMBER!\n1-8 arasında değer girmelisiniz!\033[0m"<<std::endl;
		return ;
	}
    if (kisiNo >= 9 || kisiNo <= 0)
    {
        std::cout << "1-8 arasında değer girmelisiniz!\n";
        return ;
    }
    if (i >= 1 && i <= 8 )
    {
        std::cout << "\033[34m" + std::to_string(kisiNo) << ". Kişi bilgileri\n\033[0m";
        std::cout << "Ad: " << str->kisiler[kisiNo].ad << std::endl;
        std::cout << "Soyad: " << str->kisiler[kisiNo].soyad << std::endl;
        std::cout << "Takma Ad: " << str->kisiler[kisiNo].takmaAd << std::endl;
        std::cout << "Telefon: " << str->kisiler[kisiNo].telefon << std::endl;
        std::cout << "Sır: " << str->kisiler[kisiNo].enGizliSir << std::endl;
    }
    else
        std::cout << "\033[1;31mKişi Bulunamadı!\nDoğru index giriniz..\033[0m\n" << std::endl;
}

void    Add(PhoneBook *str){

    if (str->count > 8)
    {
        str->tmp_count = str->count;
        str->count = 1;
    }

    std::cout << "\033[31m|---> Kişi Bilgileri <---|\n\033[0m";
    std::cout << "Ad: ";
    std::getline(std::cin, str->kisiler[str->count].ad);
    std::cout << "Soyad: ";
    std::getline(std::cin, str->kisiler[str->count].soyad);
    std::cout << "Takma Ad: ";
    std::getline(std::cin, str->kisiler[str->count].takmaAd);
    std::cout << "Telefon: ";
    std::getline(std::cin, str->kisiler[str->count].telefon);
    for (int i = 0; i < str->kisiler[str->count].telefon[i]; i++)
    {
        if (!isdigit(str->kisiler[str->count].telefon[i]))
        {
            std::cout << "Sadece rakam giriniz\n";
            Add(str);
            return ;
        }
    }
    std::cout << "Sır: ";
    std::getline(std::cin, str->kisiler[str->count].enGizliSir);

    if (str->kisiler[str->count].ad.empty() || str->kisiler[str->count].soyad.empty() || \
        str->kisiler[str->count].takmaAd.empty() || str->kisiler[str->count].telefon.empty() || str->kisiler[str->count].enGizliSir.empty())
        return ;

    str->count++;
    std::cout << "\033[35m" << str->count - 1 << ". Kisi eklendi\033[0m\n";
}

int main()
{
    PhoneBook   kisi;
    std::string str;
    
    std::cout << "Belirtilen komutları girin -> ADD, SEARCH, EXIT\n" << std::endl;

    kisi.count = 1;
    kisi.tmp_count = 1;
    while (1)
    {
        std::cout << "\033[30mSeçim yapın: \033[0m";
        std::getline(std::cin, str);
        if (str.compare("ADD") == 0)
            Add(&kisi);
        else if (str.compare("SEARCH") == 0)
            Search(&kisi);
        else if (str.compare("EXIT") == 0)
        {
            std::cout << "\033[33mProgram başarıyla sonlandırıldı..\033[0m\n";
            exit(0);
        }
        else
        {
            std::cout << "\033[1;31mYANLIŞ KOMUT!\033[0m\n--->>> KOMUTLAR: ADD, SEARCH, EXIT\n";
        }
    }
    return (0);
}
