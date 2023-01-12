#include <iostream>
#include "account.hpp"
#include "passRandomizer.hpp"
#include "database.hpp"
#include "menu.hpp"
#include "save.hpp"


int main()
{
    srand(time(NULL));

    //Database db1;

    std::string path;
        std::cout << "Podaj : " << std::endl;
        std::cout << "    - insniejaca sciezke pliku do wczytania danych" << std::endl;
        std::cout << "    - nieistniejaca dla stworzenia nowego pliku  " << std::endl;
        std::cout << "    - 0 by uzyc pliku domyslnego" << std::endl;
        std::cin >> path;        

    Menu gandalf(path);

    gandalf.hello();

    //db1.addCategory("medycyna alternatywna");
    //db1.addCategory("UFO");
    //db1.addCategory("porno");
    //auto ac1 = Account("czwarty wymiar", "gumowedildo", "leczenie");
    //auto ac2 = Account("dupa", "2137", "leczenie");
    //auto ac3 = Account("hub", "696969", "porn");
    //db1.add(ac1);
    //db1.add(ac2);
    //db1.add(ac3);

    //bool correct = Menu::hello(db1);


        
}

