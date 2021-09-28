#pragma once

#include <Arduino.h>

/*
    Parsed SNTP message.
    See RFC 4330 for fields reference.
*/
struct SNTPMessage
{
    enum LeapIndicator
    {
        NO_WARNING,        /* No warning. */
        MINUTE_61_SECONDS, /* Last minute has 61 seconds. */
        MINUTE_59_SECONDS, /* Last minute has 59 seconds. */
        ALARM              /* Alarm condition(clock not synchronized). */
    };
    LeapIndicator leapIndicator;

    enum VersionNumber
    {
        V1,
        V2,
        V3,
        V4, /* Current, SNTP/NTP v4. */
        UNKNOWN
    };
    VersionNumber versionNumber;

    enum Mode
    {
        RESERVED,             /* Reserved. */
        SYMMETRIC_ACTIVE,     /* Symmetric active. */
        SYMMETRIC_PASSIVE,    /* Symmetric passive. */
        CLIENT,               /* Client. */
        SERVER,               /* Server. */
        BROADCAST,            /* Broadcast. */
        RESERVED_NTP_CONTROL, /* Reserved for NTP control message. */
        RESERVED_PRIVATE,     /* Reserved for private use. */
    };
    Mode mode;

    enum Stratum
    {
        KISS_O_DEATH, /* Kiss-o'-death message. */
        PRIMARY,      /* Primary reference. */
        SECONDARY,    /* Secondary reference. */
        RESERVED      /* Reserved. */
    };
    Stratum stratum;

    uint8_t pollInterval;
    uint8_t precision;
    int32_t rootDelay;
    uint32_t roodDispersion;

    enum ReferenceIdentifier
    {
        LOCL, /* Uncalibrated local clock. */
        CESM, /* Calibrated Cesium clock. */
        RBDM, /* Calibrated Rubidium clock. */
        PPS,  /* Calibrated quartz clock or other pulse-per-second source. */
        IRIG, /* Inter-Range Instrumentation Group. */
        ACTS, /* NIST telephone modem service. */
        USNO, /* USNO telephone modem service. */
        PTB,  /* PTB (Germany) telephone modem service. */
        TDF,  /* Allouis (France) Radio 164 kHz. */
        DCF,  /* Mainflingen (Germany) Radio 77.5 kHz. */
        MSF,  /* Rugby (UK) Radio 60 kHz. */
        WWV,  /* Ft. Collins (US) Radio 2.5, 5, 10, 15, 20 MHz. */
        WWVB, /* Boulder (US) Radio 60 kHz. */
        WWVH, /* Kauai Hawaii (US) Radio 2.5, 5, 10, 15 MHz. */
        CHU,  /* Ottawa (Canada) Radio 3330, 7335, 14670 kHz. */
        LORC, /* LORAN-C radionavigation system. */
        OMEG, /* OMEGA radionavigation system. */
        GPS,  /* Global Positioning Service. */
        UNKNOWN
    };
    ReferenceIdentifier referenceIdentifier;

    time_t referenceTimestamp;
    time_t originateTimestamp;
    time_t receiveTimestamp;
    time_t transmitTimestamp;

    uint32_t keyIdentifier;
    uint8_t messageDigest[32];
};
