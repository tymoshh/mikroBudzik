#include <bits/stdc++.h>

#include "configReader.hpp"
#include "requestHandler.hpp"

#define VERSION 0.4



int main() {

    std::cout << "mikroBudzik v" << VERSION << std::endl;
    std::cout << std::endl;

    // check if config file exists
    if (!cfgReader::checkForConfig()) {
        std::cout << "no config file found, you need to mount" << std::endl;
        std::cout << "./conf.toml:/app/conf.toml" << std::endl;
        return 1;
    }

    // load the config file
    if (cfgReader::loadConfig()) {
        return 1;
    }

    // getting important data
    std::string WOLWEB_HOST = cfgReader::getHost();
    std::string DEVICE_NAME = cfgReader::getDeviceName();
    int WAKE_TIME = cfgReader::getHour();

    // output config data
    std::cout << "WOLWEB HOST: " << WOLWEB_HOST << std::endl;
    std::cout << "WOL DEVICE: " << DEVICE_NAME << std::endl;
    std::cout << "WAKE HOUR: " << WAKE_TIME << std::endl;
    std::cout << std::endl;
    
    // main loop
    while (true) {
        // get current time
        auto now = std::chrono::system_clock::now();
        // time_t
        std::time_t nowc = std::chrono::system_clock::to_time_t(now);
        // tm*
        std::tm *nowtm = std::localtime(&nowc);
        // get time as str
        std::stringstream tandatess;
        tandatess << std::put_time(nowtm, "%d-%m-%Y %H:%M:%S");
        // if statement
        if (nowtm->tm_hour == WAKE_TIME) {\
            // wake task
            if (wakeDeviceV2(WOLWEB_HOST, DEVICE_NAME)) {
                std::cout << "[ " << tandatess.str() << " ]   " << "wol packet has been probably sent" << std::endl; 
            } else {
                std::cout << "[ " << tandatess.str() << " ]   " << "failed to send wol packet" << std::endl;
            }
            std::this_thread::sleep_for(std::chrono::hours(24));
        } else {
            std::this_thread::sleep_for(std::chrono::minutes(1));
        }
        std::cout << std::endl;
    }
    
}