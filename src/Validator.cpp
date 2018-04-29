//
//  Validator.cpp
//  SIC
//
//  Created by Khaled Abdelfattah on 4/29/18.
//  Copyright © 2018 Khaled Abdelfattah. All rights reserved.
//

#include "Validator.hpp"
#include <regex>

const regex twoRegesters ("(A|B|X|L|T|F|S|P),(A|B|X|L|T|F|S|P)");
const regex oneRegester ("(A|B|X|L|T|F|S|P)");
const regex indexing ("(\\w)+,X");
const regex memoryAddressing ("(#|@)*([A-Z])(\\w)*");
const regex notRegester ("(#|@)*(A|B|X|L|T|F|S|P)");
const regex expression ("(\\w)+(\\-|\\+)(\\w)+");
const regex notRelative ("([A-Z](\\w)*(\\+)[A-Z](\\w)*)|((\\d)+(\\-)[A-Z](\\w)*)");


Validator::Validator() {
    this->opTable = * new OpTable();
}

bool Validator::validate(string operation, string operand) {
    int lengthOfInstruction = opTable.found(operation);
    if (lengthOfInstruction == 2) {
        if (operation == "CLEAR" || operation == "TIXR")
            return regex_match(operand, oneRegester);
        return regex_match(operand, twoRegesters);
    } else if (operation == "RSUB") {
        return operand.length() == 0;
    } else if (regex_match(operand, expression)) {
        return !regex_match(operand, notRelative);
    } else {
        if (regex_match(operand, indexing) && !regex_match(operand, twoRegesters))
            return true;
        else if (regex_match(operand, memoryAddressing)
                 && !regex_match(operand, notRegester))
            return true;
        else
            return false;
    }
    return false;
}
