// Defect.h
#include <iostream>
#include <string>

namespace Records {
    const double kDefaultRepairCost = 100.0;

    class Defect {
    public:
        // Constructor
        Defect();

        void incRepairCost(int inRaiseAmount = 25);
        void decRepairCost(int inDemeritAmount = 25);
        void fix();
        void unfix();
        void display();

        // Accessors and setters
        void setDefectCode(int inDefectCode);
        int getDefectCode();
        void setModelCode(int inModelCode);
        int getModelCode();
        void setDescription(std::string inDescription);
        std::string getDescription();
        void setRepairMethods(std::string inRepairMethods);
        std::string getRepairMethods();
        void setRepairCost(double inRepairCost);
        double getRepairCost();
        bool getIsFixed();



    private:
        int mDefectCode;
        int mModelCode;
        std::string mDescription;
        std::string mRepairMethods;
        double mRepairCost;
        bool iFixed;
    };
}

