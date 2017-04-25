/*
  Stream.cpp

  Definition file for Stream class
*/

#include "Stream.hpp"

// constructor
Stream::Stream(const Video& video, int occurrences)
    : video(video), occurrences(occurrences)
{ }

// number of times watched
int Stream::getOccurrences() const {

    return occurrences;
}

// movie rented
const Video& Stream::getVideo() const {

    return video;
}
