#include <stdint.h>

typedef union Color {
    struct {
        uint8_t r;
        uint8_t g;
        uint8_t b;
        uint8_t a;
    } components;
    uint32_t rgba;
} color_t;

// EXERCISE

typedef struct TCP {
    uint16_t src_port;
    uint16_t dest_port;
    uint32_t seq_num;
} tcp_header_t;

typedef union PacketHeader{
    tcp_header_t tcp_header;
    uint8_t raw[8];
} packet_header_t;