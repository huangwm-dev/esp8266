#define LSB(x) (0x00FF & x)
#define MSB(x) ((0xFF00 & x) >> 8)
#define MIN_BYTE_EXPECTED 3
#define MAX_FRAME_LEN 4080
#define BUF_SIZE 4080

enum SERIAL_BYTES {
	SERIAL_STOP_BYTE = 0x7e,
	SERIAL_ESC_BYTE = 0x7d,
	SERIAL_XOR_BYTE = 0x20,
	SERIAL_ESC_STUFFED_BYTE = 0x5d,
	SERIAL_END_STUFFED_BYTE = 0x5e,
	SERIAL_TIMEOUT = 300
};

enum FORWARDING_MODE {
	FORWARDING_MODE_NONE = 0,
	FORWARDING_MODE_IP,
	FORWARDING_MODE_ETHER
};

enum WIFI_SLEEP_MODE {
	WIFI_SLEEP_NONE = 0,
	WIFI_SLEEP_MODEM,
	WIFI_SLEEP_LIGHT
};

enum DEVICE_MODE {
	DEVICE_MODE_STAION = 1,
	DEVICE_MODE_AP = 2
};

enum ESP_MSG_TYPE {
	MSG_STATUS = 0x80,
	MSG_WIFI_SLEEP_MODE_SET = 0x21,
	MSG_WIFI_SCAN_REQUEST = 0x22,
	MSG_WIFI_SCAN_REPLY = 0x23,
	MSG_WIFI_SCAN_ENTRY = 0x24,
	MSG_SET_FORWARDING_MODE = 0x11,
	MSG_WIFI_MODE_SET = 0x20,
	MSG_ETHER_PACKET = 0x01,
	MSG_WIFI_GET_MACADDR_REQUEST = 0x25,
	MSG_WIFI_GET_MACADDR_REPLY = 0x26,
	MSG_STATION_CONF_SET = 0x40,
	MSG_STATION_CONN_STATUS_REQUEST = 0x45,
	MSG_STATION_CONN_STATUS_REPLY = 0x46,
	MSG_ECHO_REQUEST = 0x84,
	MSG_ECHO_REPLY = 0x85,
	MSG_SET_BAUD = 0x86,
	MSG_LOG = 0x83
};

struct msg_station_conf {
	uint8_t msg_type;
	uint8_t ssid_len;
	uint8_t ssid[32];
	uint8_t password_len;
	uint8_t password[64];
};

struct msg_wifi_scan_request {
	uint8_t msg_type;
	uint8_t ssid_len;
	uint8_t ssid[32];
	uint8_t use_bssid;
	uint8_t bssid[6];
	uint8_t channel;
	uint8_t show_hidden;
};

struct msg_wifi_scan_entry {
	uint16_t index; /* index of current message, starts at 0 */
	uint8_t ssid_len; /* ssid len */
	uint8_t ssid[32];
	uint8_t bssid[6];
	uint8_t channel;
	uint8_t auth_mode; /* enum wifi_auth_mode encoded as uint8_t */
	int16_t rssi;
	uint8_t is_hidden;
};

enum wifi_auth_mode {
	WIFI_AUTH_OPEN = 0,
	WIFI_AUTH_WEP = 1,
	WIFI_AUTH_WPA_PSK = 2,
	WIFI_AUTH_WPA2_PSK = 3,
	WIFI_AUTH_WPA_WPA2_PSK = 4,
} PACKED;
