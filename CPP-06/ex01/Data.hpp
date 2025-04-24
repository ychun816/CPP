#ifndef DATA_HPP
#define DATA_HPP
#pragma once

#include <iostream>

class Data
{
    private:
        std::string _name;
        int _id;
        double _score;
    
    public:
        Data();
        Data(std::string name, int id, double score);
        ~Data();

        ////getter
        int getID() const;
        std::string getName() const;
        double getScore() const;
};

#endif