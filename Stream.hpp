/*
  Stream.hpp

  Include file for Stream class
*/

#ifndef RENTAL_H
#define RENTAL_H

#include "Video.hpp"

class Stream {
public:

    // constructor
    Stream(const Video& video, int occurrences);

    // number of times watched
    int getOccurrences() const;

    // video rented
    const Video& getVideo() const;

private:
    Video video;
    int occurrences;
};

#endif
