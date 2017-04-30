/*
  Video_t.cpp

  Test program for class Video
*/

#include <cassert>

#include "Video.hpp"

int main() {

  // TODO: Add test cases
  
  //Empty default constructor initializes
  {
    Video myVideo();
  }
  
  //Initalize a constuctor with default values and
  //use the getter functions to return those values.
  {
    Video myVideo("", 0, 0, 0, 0);
    
    assert(myVideo.getTitle() == "");
    assert(myVideo.getType() == 0);
    assert(myVideo.getHours() == 0);
    assert(myVideo.getMinutes() == 0);
    assert(myVideo.getEpisodes() == 0);
  }
  
  return 0;
}