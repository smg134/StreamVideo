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
	
	// MOVIE stream
	{	
		Video myVideo("movie", 0, 2, 10, 0);
		Stream myStream(myVideo, 1);
		
		Account customer("Fred");
		
		customer.addStream(myStream);
		
		assert(customer.getName() == "Fred");
	
		assert(customer.data() == "Fred,MOVIE,movie,2,10,2\n");
		
		assert(customer.report() == "Stream Report for Account: Fred\nStreams:\n\tmovie\t2\n\nTotal Stream Events: 2\nNon-Original Stream Events: 2\nTotal Time: 2:10\n");
	}
    
	// TVSHOW stream
	{	
		Video myVideo("tv_show", 1, 4, 6, 12);
		Stream myStream(myVideo, 1);
		
		Account customer("Fred");
		
		customer.addStream(myStream);
		
		assert(customer.getName() == "Fred");
	
		assert(customer.data() == "Fred,TVSHOW,tv_show,4,6,1\n");
		
		assert(customer.report() == "Stream Report for Account: Fred\nStreams:\n\ttv_show\t1\n\nTotal Stream Events: 1\nNon-Original Stream Events: 1\nTotal Time: 4:6\n");
	}
	
	// ORIGINAL stream
	{	
		Video myVideo("video", 2, 0, 0, 2);
		Stream myStream(myVideo, 1);
		
		Account customer("Fred");
		
		customer.addStream(myStream);
		
		assert(customer.getName() == "Fred");
	
		assert(customer.data() == "Fred,ORIGINAL,video,0,0,1\n");
		
		assert(customer.report() == "Stream Report for Account: Fred\nStreams:\n\tvideo\t1\n\nTotal Stream Events: 1\nNon-Original Stream Events: 0\nTotal Time: 0:0\n");
	}
	
	//multiple streams
	{	
		Video myOriginal("original", 2, 0, 30, 1);
		Stream myStreamO(myOriginal, 1);

		Video myTVShow("tvshow", 1, 0, 30, 1);
		Stream myStreamTV(myTVShow, 1);

		Video myMovie("movie", 0, 2, 30, 1);
		Stream myStreamM(myMovie, 1);
		
		Account customer("Fred");
		
		customer.addStream(myStreamO);
		customer.addStream(myStreamTV);
		customer.addStream(myStreamM);
		
		assert(customer.getName() == "Fred");
	
		assert(customer.data() == "Fred,ORIGINAL,original,0,30,1\nFred,TVSHOW,tvshow,0,30,1\nFred,MOVIE,movie,2,30,2\n");

		assert(customer.report() == "Stream Report for Account: Fred\nStreams:\n\toriginal\t1\n\ttvshow\t1\n\tmovie\t2\n\n"
			"Total Stream Events: 4\nNon-Original Stream Events: 3\nTotal Time: 3:30\n");
}
	
	// 
    return 0;
}
