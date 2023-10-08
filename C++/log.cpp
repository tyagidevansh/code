#include <iostream>

class Log{
public:
    enum Level{
        Error = 0, Warning, Info  
    };
private:
    int m_LogLevel = Info;
public:
    void setLevel(int level){
        m_LogLevel = level;
    }

    void error(const char* message){
        if (m_LogLevel >= Error)
        std::cout <<"[ERROR]:" << message << std::endl;
    }

    void warn(const char* message){
        if (m_LogLevel >= Warning)
        std::cout <<"[WARNING]:" << message << std::endl;
    }

    void info(const char* message){
        if (m_LogLevel >= Info)
        std::cout <<"[INFO]:" << message << std::endl;
    }
};

int main(){
    Log log;
    log.setLevel(log.Info);
    log.warn("BEWARE");

    return 0;
}