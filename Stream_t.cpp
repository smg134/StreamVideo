/*
  Stream_t.cpp

  Test program for class Stream
*/

#include <cassert>

#include "Stream.hpp"

int main() {

	//Initialize empty stream object
    {Stream myStream();}


    //Test stream constructor with specific values
    //and assert those values with the corresponding
    //getter methods
    {
    const Video myVideo("video", 2, 0, 0, 2);
    Stream myStream(myVideo, 1);

    assert(myStream.getOccurrences() == 1);

    assert(myStream.getVideo().getTitle() == myVideo.getTitle());
    assert(myStream.getVideo().getType() == myVideo.getType());
    assert(myStream.getVideo().getHours() == myVideo.getHours());
    assert(myStream.getVideo().getMinutes() == myVideo.getMinutes());
	}

    return 0;
}
