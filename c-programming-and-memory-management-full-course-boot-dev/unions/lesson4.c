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

// Which is the correct order, from least to greatest, of the memory requirements of the given unions?
// 1. SensorData (8 bytes)
// 2. Item (12 bytes)
// 3. PacketPayload (256 bytes)
// 4. IntOrErrMessage (256 bytes)