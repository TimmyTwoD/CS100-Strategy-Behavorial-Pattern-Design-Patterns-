#ifndef SELECT_AND_H
#define SELECT_AND_H

#include "select.hpp"

// can choose to derive from Select or Select_Column
class Select_And : public Select {
    private:
        Select* criteria1 = nullptr;
        Select* criteria2 = nullptr;
    public:
        Select_And() {}
        ~Select_And() {
          delete criteria1;
          delete criteria2;
        }
        Select_And(Select* input1, Select* input2) {
            criteria1 = input1;
            criteria2 = input2;
        }

        virtual bool select(const Spreadsheet* sheet, int row) const {
            return (criteria1->select(sheet, row) && criteria2->select(sheet, row)); //this should work
            
        } 
};

#endif
