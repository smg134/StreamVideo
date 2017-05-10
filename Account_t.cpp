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

    // one stream
	{	
		Video myVideo("video", 2, 0, 0, 2);
		Stream myStream(myVideo, 1);
		
		Account customer("Fred");
		
		customer.addStream(myStream);
		
		assert(customer.getName() == "Fred");
	
		assert(customer.data() == "Fred,ORIGINAL,video,0,0,1\n");
		
		// FIXME: possibly fix testing method?
		// not sure if testing with string literal here is good. any feedback/help is appreciated
		assert(customer.report() == "Stream Report for Account: Fred\nStreams:\n\tvideo\t1\n\nTotal Stream Events: 1\nNon-Original Stream Events: 0\nTotal Time: 0:0\n");
	}
    
	// 
    return 0;
}
