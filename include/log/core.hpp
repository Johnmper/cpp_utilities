#ifndef __UL_LOG_CORE_HPP
#define __UL_LOG_CORE_HPP

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <random>
#include <chrono>

#include "../singleton.hpp"
#include "../terminal/style.hpp"

namespace ul{
#define MAX_LOGGER_FILES_1MIN   100

    class Logger{
    public:
        Logger() : log_stream_(new std::fstream){
            std::time_t instanciation_time = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
            std::stringstream ss;
            ss << "/home/johnmper/.logs/"<<std::put_time(std::localtime(&instanciation_time),"%Y-%m-%d_%Hh%Mm_");
            for(int ii=0; ii < MAX_LOGGER_FILES_1MIN ; ++ii){
                std::fstream tmp(ss.str()+std::to_string(ii)+std::string(".txt"),std::fstream::in | std::fstream::ate);
                if(!tmp.is_open()){
                    log_stream_->open(ss.str()+std::to_string(ii)+std::string(".txt"),std::fstream::out);
                    filepath =  ss.str() + std::to_string(ii) + ".txt";
                    std::cerr << "Logging into: " << filepath << "\n";
                    break;
                }
            }

        }
        ~Logger(){
            log_stream_->close();
            delete log_stream_;
        }

        std::fstream& info(){
            (*log_stream_) << terminal::style::magenta << "Info:" << terminal::style::normal;
            return (*log_stream_);
        }
        std::fstream& warn(){
            (*log_stream_) << terminal::style::yellow << "Warning:" << terminal::style::normal;
            return (*log_stream_);
        }
        std::fstream& fatal(){
            (*log_stream_) << terminal::style::red << "Fatal:" << terminal::style::normal;
            return (*log_stream_);
        }


    private:
        std::fstream* log_stream_;
        std::string filepath;
    };

    enum {
        info=0,
        warn=1,
        fatal=2,
    };

    static std::fstream& Log(int n=0){
        auto& ref = ul::Singleton<ul::Logger>::instance();
        if(n==0){return ref.info();}
        else if(n==1){return ref.warn();}
        else if(n==2){return ref.fatal();}
    }
};

#endif // __UL_LOG_CORE_HPP
