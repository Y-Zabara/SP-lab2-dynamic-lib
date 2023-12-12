
// Database.cpp
#include <iostream>
#include <stdexcept>
#include <string>
#include "Database.h"
using namespace std;
namespace Records {
  Database::Database() {
    mNextSlot = 0;
    mNextDefectCode = kFirstDefectCode;
  }

  Database::~Database() {
  }

  Defect& Database::addDefect(int inModel, std::string inDescription, string inRepairMethods) {
    if (mNextSlot >= kMaxDefects) {
      cerr << "There is no more spase to add the new defect!" << endl;
      throw exception();
    }

    Defect& theDefect = mDefects[mNextSlot++];
    theDefect.setDefectCode(mNextDefectCode++);
    theDefect.setModelCode(inModel);
    theDefect.setDescription(inDescription);
    theDefect.setRepairMethods(inRepairMethods);
       return theDefect;
  }

  Defect& Database::getDefect(int inCode) {
    for (int i = 0; i < mNextSlot; i++) {
      if (mDefects[i].getDefectCode() == inCode) {
        return mDefects[i];
      }
    }
    cerr << "No defect type with code " << inCode << endl;
    throw exception();
  }

  void Database::displayAllDefects() {
    for (int i = 0; i < mNextSlot; i++) {
    	mDefects[i].display();
    }
  }

  void Database::displayFixed() {
    for (int i = 0; i < mNextSlot; i++) {
    	if(mDefects[i].getIsFixed()){
            mDefects[i].display();
        }
    }
  }

  void Database::displayUnfixed() {
    for (int i = 0; i < mNextSlot; i++) {
    	if(!mDefects[i].getIsFixed()){
    	    mDefects[i].display();
        }
    }


// namespace Records
}
}
