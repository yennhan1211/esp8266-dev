#ifndef _FOTA_VERSION_H_
#define _FOTA_VERSION_H_

#include "osapi.h"
#include "fota-util.h"

#define pHeadStatic "Connection: keep-alive\r\n\
Cache-Control: no-cache\r\n\
User-Agent: esp8266\r\n\
Accept: */*\r\n"

#define pHeadAuthen "UUID: %s\r\n\
Token: %s\r\n\
Client: %s\r\n\
Image: %s\r\n\
Version: %s\r\n"

#define FOTA_CLIENT   ESP8266
#define UUID_LEN    15
#define TOKEN_LEN   161
#define VERSION_LEN VERSION_BYTE_STR

#define VERSION_DIGIT_MAX   255             // max value of 1B
#define VERSION_BYTE        3               // MAJOR.MINOR.PATCH

#define HOST_LEN      30
#define URL_LEN       100
#define VERSION_LEN   (VERSION_BYTE*3+(VERSION_BYTE-1)+1)       // xxx.xxx.xxx\0
#define PROTOCOL_LEN  6 

typedef struct {
  ip_addr_t ip;
  uint16_t port;
  char *uuid;
  char *token;
  char *host;
  uint16_t interval;
  struct espconn *conn;
  os_timer_t periodic;
  os_timer_t request_timeout;
  struct fota_cdn_t fw_server;
} fota_client_t;

typedef struct {
  char *host;
  char *url;
  ip_addr_t ip;
  uint16_t port;
  uint8_t secure;
} fota_cdn_t

void start_fota(fota_client_t *client, uint16_t interval, char *host, uint16_t port, char *id, char* token);

#endif