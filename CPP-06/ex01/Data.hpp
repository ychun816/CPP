#ifndef DATA_HPP
#define DATA_HPP
#pragma once

#include <iostream>
#include <cstdint> // for uintptr_t

class Data
{
    private:
        int _id;
        std::string _name;
        double _score;
    
    public:
        Data();
        Data(std::string name, int id, double score);

        //getters
        int getID() const;
        std::string getName() const;
        double getScore() const;
};

#endif