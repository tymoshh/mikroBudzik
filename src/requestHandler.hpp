#include <bits/stdc++.h>
#include <curl/curl.h>

CURL *curl;
CURLcode res;

void initCurl() {
    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
}

bool wakeDeviceV1(std::string &WOLWEB_HOST, std::string &DEVICE_NAME) {
    std::string runCommand = "curl -L http://" + WOLWEB_HOST + "/wake/" + DEVICE_NAME;
    system(runCommand.c_str());
    return 0;
}

bool wakeDeviceV2(std::string &WOLWEB_HOST, std::string &DEVICE_NAME) {
    initCurl();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, ("http://" + WOLWEB_HOST + "/wake/" + DEVICE_NAME).c_str());
        res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            return 1;
        }
    } else {
        return 1;
    }
    return 0;
}