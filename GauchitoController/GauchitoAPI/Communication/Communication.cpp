#include "Communication.h"

uchar_t security_type = 0;

uchar_t local_ip[4];
uchar_t gateway_ip[4];
uchar_t subnet_mask[4];
uchar_t target_ip[4];
int target_port = 0;

const prog_uchar wep_keys[] PROGMEM = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d,	// Key 0
		 		 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,	// Key 1
				 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,	// Key 2
				 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};	// Key 3

uchar_t wireless_mode = WIRELESS_MODE_INFRA;
uchar_t ssid_len;
uchar_t security_passphrase_len;

Communication* Communication::instance = 0;
Communication* Communication::getInstance() {
    if (!instance) {
        instance = new Communication();
    }
    return instance;
}

Communication &Communication::localIp(uchar_t a, uchar_t b, uchar_t c, uchar_t d) {
    local_ip[0] = a;
    local_ip[1] = b;
    local_ip[2] = c;
    local_ip[3] = d;
    return *this;
}

Communication &Communication::gatewayIp(uchar_t a, uchar_t b, uchar_t c, uchar_t d) {
    gateway_ip[0] = a;
    gateway_ip[1] = b;
    gateway_ip[2] = c;
    gateway_ip[3] = d;
    return *this;
}

Communication &Communication::subnetMask(uchar_t a, uchar_t b, uchar_t c, uchar_t d) {
    subnet_mask[0] = a;
    subnet_mask[1] = b;
    subnet_mask[2] = c;
    subnet_mask[3] = d;
    return *this;
}

Communication &Communication::securityType(SecurityType::Enum value) {
    security_type = (uchar_t) value;
    return *this;
}

Communication &Communication::targetIp(uchar_t a, uchar_t b, uchar_t c, uchar_t d) {
    target_ip[0] = a;
    target_ip[1] = b;
    target_ip[2] = c;
    target_ip[3] = d;
    return *this;
}

Communication &Communication::targetPort(int value) {
    target_port = value;
    return *this;
}

void Communication::connect() {
    WiFi.init();
}

void Communication::run() {
    WiFi.run();
}
