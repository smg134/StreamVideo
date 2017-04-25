/*
  Account_t.cpp

  Test program for class Account
*/

#include <iostream>
#include <cassert>
#include <string>

#include "Account.hpp"

int main() {

    // no streaming
    {
        Account customer("Fred");

        assert(customer.getName() == "Fred");

        // test using literal string
        assert(customer.data() == "");
    }

    // TODO: Add test cases
    
    return 0;
}
