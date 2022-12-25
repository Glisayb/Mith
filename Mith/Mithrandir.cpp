#include <iostream>
#include "account.hpp"
#include "passRandomizer.hpp"
#include "database.hpp"
#include "menu.hpp"

int main()
{
    srand(time(NULL));
    Database db1;

    db1.addCategory("medycyna alternatywna");
    db1.addCategory("UFO");
    db1.addCategory("porno");
    auto ac1 = Account("czwarty wymiar", "jp2", "leczenie");
    auto ac2 = Account("dupa", "jp2", "leczenie");
    //ac1->print();
    db1.add(ac1);
    db1.add(ac2);

    std::cout << &db1.getDb()[0] << std::endl;
    std::cout << &db1.getDb()[1] << std::endl;


    std::cout << (& db1.getDb()[0])->getName() << std::endl;
    std::cout << (& db1.getDb()[1])->getName() << std::endl;

    Database::print(db1.getDb());
    Database::print(Database::filter(db1.getDb(), 3, "leczenie"));

    std::cout << "Hello World!\n" << std::endl ;

    std::cout << db1.getDb().size() << std::endl;

    Menu::hello(db1);

}

