#pragma once

#include "Logger.hpp"

#include <string>
#include <iostream>
#include <sstream>

class Participant {
  
  public:
		//::---------------------------------------------------
		//::	Constructor/Destructor
		//::---------------------------------------------------

    Participant(std::string name);

    ~Participant();
    
		//::---------------------------------------------------
		//:: Pure Virtual Interface
		//::---------------------------------------------------

    // Deliver a message to those in the given chat room
    virtual void deliver(std::string& msg) = 0;

    virtual void listen(std::string& msg) = 0;

		//::---------------------------------------------------
		//:: Interface
		//::---------------------------------------------------
    
    unsigned int getId() const {
      return m_id; 
    }

    std::string getName() const {
      return m_name; 
    }

    // Output as string
    std::string getAsString() {
      std::ostringstream oss;
      oss << '[' << m_name << "]: ";
      return oss.str();
    }

		//::---------------------------------------------------
		//:: Logging
		//::---------------------------------------------------

    friend std::ostream& operator<<(std::ostream& lhs, Participant& participant) {
      return lhs << participant.getAsString(); 
    }

  private:
		//::---------------------------------------------------
		//:: Member Variables	
		//::---------------------------------------------------

    std::string m_name;
    
    unsigned short m_id;

    // The total number of existing participants
    static unsigned short st_totalId;

};
