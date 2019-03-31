#ifndef __UL_HASH_CORE_HPP
#define __UL_HASH_CORE_HPP

namespace ul{

// Anonymous namespace, hides local function from external code, effectively a private function
namespace{
    uint32_t
    hash_rec(uint32_t _hash, const char* _str){
        return (*_str == 0) ? _hash : hash_rec(((_hash << 5) + _hash) + *_str, _str + 1);
    }

};  // PRIVATE NAMESPACE



    uint32_t
    hash(const char* _str){
        return (*_str == 0) ? 0 : hash_rec(5381, _str);
    }

    uint32_t
    hash(const std::string _str){
        if( _str.empty() ){
            return 0;
        }
        return hash_rec(5381, _str.c_str());
    }



};  // UL NAMESPACE

#endif // __UL_HASH_CORE_HPP
