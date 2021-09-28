#include "SNTPClient.h"
#include "SNTPMessage.h"

SNTPClient::SNTPClient(UDP udpClient, std::function<time_t()> getTime, std::function<void(time_t)> adjustTime)
    : mUdpClient(udpClient), mGetTime(getTime), mAdjustTime(adjustTime)
{
}

SNTPClient::~SNTPClient()
{
}

SNTPClient::tick()
{
}