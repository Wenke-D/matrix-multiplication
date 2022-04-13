#include<iostream>
#include<vector>

template<typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& v)
{
    for(auto& ele:v){
        os << ele << ' ';
    }
    return os;
}
