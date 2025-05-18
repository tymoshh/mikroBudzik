#include <bits/stdc++.h>

#include "toml.hpp"

namespace fs = std::filesystem; 

namespace cfgReader {

    toml::table configTbl;

    bool checkForConfig() {
        return fs::exists("/app/conf.toml");
    }

    bool loadConfig() {
        try {
            configTbl = toml::parse_file("conf.toml");
            std::cout << "config loaded" << std::endl;
            return 0;
        } catch (toml::parse_error &myError) {
            std::cout << "failed to load config" << std::endl;
            return 1;
        }
    }

    std::string getHost() {
        return configTbl["wolwebHost"].value<std::string>().value();
    }

    std::string getDeviceName() {
        return configTbl["deviceName"].value<std::string>().value();
    }

    int getHour() {
        return configTbl["wakeTime"].value<int>().value();
    }

}