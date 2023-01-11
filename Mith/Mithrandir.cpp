#include <iostream>
#include "account.hpp"
#include "passRandomizer.hpp"
#include "database.hpp"
#include "menu.hpp"
#include "save.hpp"

int main()
{
    srand(time(NULL));
    Database db1;

    //db1.addCategory("medycyna alternatywna");
    //db1.addCategory("UFO");
    //db1.addCategory("porno");
    //auto ac1 = Account("czwarty wymiar", "gumowedildo", "leczenie");
    //auto ac2 = Account("dupa", "2137", "leczenie");
    //auto ac3 = Account("hub", "696969", "porn");
    //db1.add(ac1);
    //db1.add(ac2);
    //db1.add(ac3);

    bool correct = Menu::hello(db1);
        
}

