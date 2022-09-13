#ifndef SELECT_OR_H
#define SELECT_OR_H

#include "select.hpp"

class Select_Or : public Select {
    private:
        Select* criteria1;
        Select* criteria2;
    public:
        Select_Or() {}
        Select_Or(Select* input1, Select* input2) {
            criteria1 = input1;
            criteria2 = input2;
        }        
        ~Select_Or() {
          delete criteria1;
          delete criteria2;
        }
        virtual bool select(const Spreadsheet* sheet, int row) const {
            return (criteria1->select(sheet, row) || criteria2->select(sheet, row));
        } 
};

#endif
