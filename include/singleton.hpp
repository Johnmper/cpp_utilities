#ifndef __UL_SINGLETON_HPP
#define __UL_SINGLETON_HPP

namespace ul{

    template<typename T>
    class Singleton{
    static_assert(std::is_default_constructible<T>::value, "T must have default constructor");
    private:
        Singleton();
    public:
        Singleton(const Singleton&) = delete;
        Singleton(Singleton&&) = delete;
        Singleton& operator=(const Singleton&) = delete;
        Singleton& operator=(Singleton&&) = delete;
        static T& instance(){
            static T singleton;
            return singleton;
        }
    };


};

#endif
