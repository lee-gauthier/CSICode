#include <fstream>
#include <string>

class SimpleLogger {
public:
    SimpleLogger(const std::string& filename) : logFile(filename, std::ios::app) {
        // 'std::ios::app' opens the file in append mode, so new log messages are added to the end.
    }

    void Log(const std::string& message) {
        if (logFile.is_open()) {
            logFile << message << std::endl;
        }
    }

    ~SimpleLogger() {
        if (logFile.is_open()) {
            logFile.close();
        }
    }

private:
    std::ofstream logFile;
};
