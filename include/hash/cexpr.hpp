#ifndef __UL_HASH_CEXPR_HPP
#define __UL_HASH_CEXPR_HPP

namespace ul{

namespace cexpr{

// Anonymous namespace, hides local function from external code, effectively a private function
namespace{
    constexpr uint32_t
    hash_rec(uint32_t _hash, const char* _str){
        return (*_str == 0) ? _hash : hash_rec(((_hash << 5) + _hash) + *_str, _str + 1);
    }

};  // PRIVATE NAMESPACE



constexpr uint32_t
hash(const char* _str){
    return (*_str == 0) ? 0 : hash_rec(5381, _str);
}


}; // CEXPR Namespace

}; // HASH Namespace

#endif // __UL_HASH_CEXPR_HPP
