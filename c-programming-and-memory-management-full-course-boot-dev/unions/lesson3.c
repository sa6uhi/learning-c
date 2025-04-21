typedef union IntOrErrMessage {
    int data;
    char err[256];
  } int_or_err_message_t;

union SensorData {
    long int temperature;
    long int humidity;
    long int pressure;
  };
  
union PacketPayload {
    char text[256];
    unsigned char binary[256];
    struct ImageData {
        int width;
        int height;
        unsigned char data[1024];
    } image;
};
  
union Item {
    struct {
        int damage;
        int range;
        int size;
    } weapon;
    struct {
        int healingAmount;
        int duration;
    } potion;
    struct {
        int doorID;
    } key;
};

// How many bytes will an instance of SensorData require?
// 8 bytes (assuming long int is 8 bytes on your system)
// How many bytes will an instance of PacketPayload require?
// 256 bytes (the size of the largest member, which is the char array)
// How many bytes will an instance of Item require?
// 12 bytes (the size of the largest member, which is the struct for weapon)
// How many bytes will an instance of IntOrErrMessage require?
// 256 bytes (the size of the char array, which is the largest member)