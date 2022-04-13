#include<iostream>
#include<vector>


using matrix = std::vector<std::vector<int>>;


std::ostream& operator<<(std::ostream& os, const std::vector<int>& v)
{
    for(auto ele:v){
        os << ele << ' ';
    }
    return os;
}



std::ostream& operator<<(std::ostream& os, const matrix& m)
{
    for(auto& row:m){
        os << row << std::endl;
    }
    return os;
}
