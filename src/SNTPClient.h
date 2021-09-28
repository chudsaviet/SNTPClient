#pragma once

#include <Arduino.h>

class SNTPClient
{
private:
    UDP mUdpClient;
    std::function<time_t()> mGetTime;
    std::function<void(time_t)> mAdjustTime;

public:
    SNTPClient(UDP udpClient, std::function<time_t()> getTime, std::function<void(time_t)> adjustTime);
    ~SNTPClient();
    tick();
};
