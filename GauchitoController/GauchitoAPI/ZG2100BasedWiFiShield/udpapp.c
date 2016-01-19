/******************************************************************************

  Filename:   udpapp.h
  Description:  UDP app for the WiShield 1.0

 ******************************************************************************

  TCP/IP stack and driver for the WiShield 1.0 wireless devices

  Copyright(c) 2009 Async Labs Inc. All rights reserved.

  This program is free software; you can redistribute it and/or modify it
  under the terms of version 2 of the GNU General Public License as
  published by the Free Software Foundation.

  This program is distributed in the hope that it will be useful, but WITHOUT
  ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
  FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
  more details.

  You should have received a copy of the GNU General Public License along with
  this program; if not, write to the Free Software Foundation, Inc., 59
  Temple Place - Suite 330, Boston, MA  02111-1307, USA.

  Contact Information:
  <asynclabs@asynclabs.com>

   Author               Date        Comment
  ---------------------------------------------------------------
   AsyncLabs      07/11/2009  Initial version

 *****************************************************************************/

#include "uip.h"
#include <string.h>
#include "udpapp.h"
#include "config.h"

#define STATE_INIT              0
#define STATE_LISTENING         1
#define STATE_HELLO_RECEIVED    2
#define STATE_NAME_RECEIVED     3

#define BUFFER_SIZE 1024

static struct udpapp_state s;

typedef struct { char *value; } Data;
typedef struct { Data dataset[20]; } GauchitoData;

extern GauchitoData gData;

void dummy_app_appcall(void)
{
}

void udpapp_init(void)
{
  uip_ipaddr_t addr;
  struct uip_udp_conn *c;

  uip_ipaddr(&addr, target_ip[0], target_ip[1], target_ip[2], target_ip[3]);
  c = uip_udp_new(&addr, HTONS(target_port));
  if(c != NULL) {
    uip_udp_bind(c, HTONS(target_port));
  }

  s.state = STATE_INIT;

  PT_INIT(&s.pt);
}

static unsigned char parse_msg(void)
{
  if (memcmp(uip_appdata, "Hello", 5) == 0) {
    return 1;
  }

  return 0;
}

static void send_request(void)
{
  char str[] = "Hello. What is your name?\n";

  memcpy(uip_appdata, str, strlen(str));
  uip_send(uip_appdata, strlen(str));
}

static void send_response(void)
{
  char i = 0;
  char str[] = "Hello ";

  while ( ( ((char*)uip_appdata)[i] != '\n') && i < 9) {
    s.inputbuf[i] = ((char*)uip_appdata)[i];
    i++;
  }
  s.inputbuf[i] = '\n';

  memcpy(uip_appdata, str, 6);
  memcpy(uip_appdata+6, s.inputbuf, i+1);
  uip_send(uip_appdata, i+7);
}

char* showIndice(GauchitoData data){
    char buffer[10];
    sprintf(buffer, "%s",
  data.dataset[0].value
    );
    return buffer;
}

char* readGPS(GauchitoData data){
    char buffer[128];
    sprintf(buffer, "%s|%s",
  data.dataset[1].value,
  data.dataset[2].value
    );
    return buffer;
}

char* readIR(GauchitoData data) {
   char buffer[128];   
   sprintf(buffer, "%s|%s|%s|%s|%s|%s",
        data.dataset[3].value,
        data.dataset[4].value,
        data.dataset[5].value,
        data.dataset[6].value,
        data.dataset[7].value,
        data.dataset[8].value
   );
   return buffer;
}

char* readSonar(GauchitoData data) {
    char buffer[128];
    sprintf(buffer, "%s|%s",
        data.dataset[9].value,
        data.dataset[10].value
    );
    return buffer;
}

char* readEngine(GauchitoData data) {
    char buffer[256];
    sprintf(buffer, "%s|%s|%s|%s|%s|%s",
        data.dataset[11].value,
        data.dataset[12].value,
        data.dataset[13].value,
        data.dataset[14].value,
        data.dataset[15].value,
        data.dataset[16].value
    );
    return buffer;
}

char* readUltrassom(GauchitoData data) {
    char buffer[128];
    sprintf(buffer, "%s|%s",
        data.dataset[17].value,
        data.dataset[18].value
    );
    return buffer;
}

char* readBussola(GauchitoData data) {
    char buffer[128];
    sprintf(buffer, "%s",
        data.dataset[19].value
    );
    return buffer;
}

static PT_THREAD(handle_connection(void))
{
    PT_BEGIN(&s.pt);

    char buffer[BUFFER_SIZE];

    PT_WAIT_UNTIL(&s.pt, readData(buffer));
    
    uip_send(buffer, strlen(buffer));
    
    PT_END(&s.pt);
}

int readData(char* buffer) {
    GauchitoData cpyData;
    memcpy(&cpyData, &gData, sizeof(cpyData));
//    snprintf(buffer, 1024, "%s\n - %s\n - %s\n - %s\n - %s\n - %s\n - %s\n", 
    snprintf(buffer, 1024, "%s - %s - %s - %s - %s - %s - %s", 
      showIndice(cpyData),
      readGPS(cpyData), 
      readIR(cpyData), 
      readSonar(cpyData), 
      readEngine(cpyData), 
      readUltrassom(cpyData), 
      readBussola(cpyData)
  );
    return 1;
}

void udpapp_appcall(void)
{
  handle_connection();
}