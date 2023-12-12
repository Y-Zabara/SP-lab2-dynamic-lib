// Database.h
#pragma once

#include <iostream>
#include "Defect.h"  // Include the new header file

namespace Records {
  const int kMaxDefects = 50;
  const int kFirstDefectCode = 100; // Adjust the maximum number of defect types
  class Database {
  public:
    Database();
    ~Database();
    Defect& addDefect(int inModel, std::string inDescription, std::string inRepairMethods);
    Defect& getDefect(int inCode);
    void displayAllDefects();
    void displayFixed();
    void displayUnfixed();

  protected:
    Defect mDefects[kMaxDefects];
    int mNextSlot;
    int mNextDefectCode;
  };
}  // namespace Records

