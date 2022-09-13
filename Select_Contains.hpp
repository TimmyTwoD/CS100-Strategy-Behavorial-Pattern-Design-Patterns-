#ifndef SELECT_CONTAINS_H
#define SELECT_CONTAINS_H

#include "select.hpp"
#include "spreadsheet.hpp"

class Select_Contains : public Select_Column {
    private:
        int column;
        std::string input;
    public:
        Select_Contains() {}
        Select_Contains(Spreadsheet *sheet, const std::string &columnName, const std::string &inputToSearchFor) {
            column = sheet->get_column_by_name(columnName); 
            input = inputToSearchFor;
        }
        
        virtual bool select(const Spreadsheet *sheet, int row) const {
            return select(sheet->cell_data(row, column));
        } 

        virtual bool select(const std::string& s) const {
          return s.find(input) != std::string::npos; //this should work
        } 
};

#endif
