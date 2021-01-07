//
// Created by Fourest on 2021/1/7.
//

#ifndef CUBE_ERROR_H
#define CUBE_ERROR_H

#include <string>

enum Message{WrongPosition,WrongColour,WrongKind,Empty};

class Error
{
    Message message=Empty;
    std::string other_message="";

public:

    Error(std::string _message)
    {
        if(_message=="WrongPosition") message=WrongPosition;
        else if(_message=="WrongColour") message=WrongColour;
        else if(_message=="WrongKind") message=WrongKind;
        else other_message=_message;
    }
    Error(Message _message):message(_message){}


    bool ErrorIsDefined() {return message!=Empty;}
    Message value() {return message;}
    std::string value_str() {return other_message;}
};


#endif //CUBE_ERROR_H
