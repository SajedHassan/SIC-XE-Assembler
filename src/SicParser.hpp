//
//  SicParser.hpp
//  SIC
//
//  Created by Khaled Abdelfattah on 4/26/18.
//  Copyright © 2018 Khaled Abdelfattah. All rights reserved.
//

#ifndef SicParser_hpp
#define SicParser_hpp

#include <stdio.h>
#include "SourceCodeTable.hpp"
#include <string>

using namespace std;

class SicParser {
public:
    SicParser();
    virtual ~SicParser();
    SourceCodeTable parse(string path);
    static string to_upper(string str);
private:
    string get_comment(vector<string> strings, int start);
    string get_quoted_operand(string);
    string get_operand(vector<string>, int);
};

#endif /* SicParser_hpp */
