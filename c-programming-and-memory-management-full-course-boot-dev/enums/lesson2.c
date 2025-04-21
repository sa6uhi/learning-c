typedef enum {
    EXIT_SUCCESS = 0,
    EXIT_FAILURE = 1,
    EXIT_COMMAND_NOT_FOUND = 127,
} ExitStatus;
  
//   Alternatively, you can define the first value and let the compiler fill in the rest (incrementing by 1):
  
typedef enum {
    LANE_WPM = 200,
    PRIME_WPM, // 201
    TEEJ_WPM,  // 202
} WordsPerMinute;

typedef enum Color {
    RED = 55,
    GREEN = 176,
    BLUE = 38,
  } color_t;