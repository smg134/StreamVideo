/*
  Account.cpp

  Definition file for Account class
*/

#include "Account.hpp"
#include "Video.hpp"

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

//Video Types
std::string v_type[3] = {"MOVIE", "TVSHOW", "ORIGINAL"};

// constructor
Account::Account(const std::string& name)
    : name(name)
{ }

// account name
std::string Account::getName() const {
    return name;
}

// add a stream to this account
void Account::addStream(const Stream& stream) {
    streams.push_back(stream);
}

//Refactoring Function: Gets total hours/minutes and multiples my total occurences

int calcTotalTime(int time, int occurences){
  return (time * occurences);
}

// get the stream count
int getStreamCount(std::vector<Stream>::const_iterator it, int type) {
    if (type == 0) {
		return it->getOccurrences() * (it->getVideo().getHours() ? it->getVideo().getHours() : 1);
	}
	else {
		return it->getOccurrences();
	}
}

// account streaming report
std::string Account::report() const {

    // stringstream to convert data
    std::ostringstream reportOutput;
  
    // customer name
    reportOutput << "Stream Report for Account: " << getName() << '\n';

    // list of streams
    reportOutput << "Streams:" << '\n';
    int totalStreams = 0;
    int totalOriginals = 0;
    int totalHours = 0;
    int totalMinutes = 0;
    for (std::vector<Stream>::const_iterator it = streams.begin(); it != streams.end(); ++it) {

	// title of stream
	reportOutput << '\t' << it->getVideo().getTitle();

	// current total hours and minutes
	totalHours += calcTotalTime(it->getVideo().getHours(), it->getOccurrences());
	totalMinutes += calcTotalTime(it->getVideo().getMinutes(), it->getOccurrences());
	
        // stream counts and originals
        int streamCount = 0;
        int originals = 0;
        
        // for movies, the stream count is the number of hours, with a minimum of 1
        if(v_type[it->getVideo().getType()] == "MOVIE"){
            streamCount += getStreamCount(it, Video::MOVIE);
        } 
        
        // for TV shows, the stream count is just the number of streams
        if(v_type[it->getVideo().getType()] == "TVSHOW"){
            streamCount += getStreamCount(it, Video::TVSHOW);
        } 
        
        // for TV shows, the stream count is just the number of streams
        if(v_type[it->getVideo().getType()] == "ORIGINAL"){
            originals += getStreamCount(it, Video::ORIGINAL);
            streamCount = originals;
        } 

        // stream counts for this video
        std::ostringstream out_str_stream;
        reportOutput << '\t' << streamCount << '\n';

        totalStreams += streamCount;
        totalOriginals += originals;
    }
    int totalNonOriginalStream = totalStreams - totalOriginals;
    
    // total stream counts
    reportOutput << "\nTotal Stream Events: " << totalStreams << '\n';

    // total non-original stream counts
    reportOutput << "Non-Original Stream Events: " << totalNonOriginalStream << '\n';

    // total time
    int minutes = totalMinutes % 60;
    int hours = totalHours + totalMinutes / 60;
    reportOutput << "Total Time: " << hours << ":" << minutes << '\n';

    return reportOutput.str();
}

// account data in CSV
std::string Account::data() const {

    // stringstream to convert data
    std::ostringstream output;

    // customer name
    std::string name = getName();

    // list of streams
    for (std::vector<Stream>::const_iterator it = streams.begin(); it != streams.end(); ++it) {

    	// customer name
    	output << name << ',';

    	// stream type
         output << v_type[it->getVideo().getType()];

        // stream title
        output << ',' << it->getVideo().getTitle();

        // stream hours and minutes
        output << ',' << calcTotalTime(it->getVideo().getHours(), it->getOccurrences());
        output << ',' << calcTotalTime(it->getVideo().getMinutes(), it->getOccurrences());

        // stream counts
        output << ',';
        
        // for movies, the stream count is the number of hours, with a minimum of 1
        if(v_type[it->getVideo().getType()] == "MOVIE"){
            output << getStreamCount(it, Video::MOVIE);
        } else{
            // all others are just the number of occurrences
            output << it->getOccurrences();
        }

        output << '\n';
    }

    return output.str();
}
