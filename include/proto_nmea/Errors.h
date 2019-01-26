#ifndef PROTO_NMEA_ERRORS
#define PROTO_NMEA_ERRORS

enum general_errors
{
    ENULL_STRING = 1
};

enum parser_errors
{
    EINVALID_PROTOCOL_BEGINNING = 30,
    EINVALID_PROTOCOL_ENDING,
    EMISPLACED_DELIMITER
};

#endif
