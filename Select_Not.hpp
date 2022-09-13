#ifndef SELECT_NOT_H
#define SELECT_NOT_H

#include "select.hpp"

class Select_Not : public Select {
    private:
        Select* criteria = nullptr;
    public:
        Select_Not() {}
        ~Select_Not() {
          delete criteria;
        }
        Select_Not(Select* input) {
            criteria = input;
        }

        virtual bool select(const Spreadsheet* sheet, int row) const {
          return !criteria->select(sheet, row);

            if (criteria->select(sheet, row)) {
                return false;
            } 
            return true;
        }

#endif
