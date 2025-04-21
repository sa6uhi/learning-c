typedef enum DaysOfWeek {
    MONDAY,
    TACO_TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY,
    FUNDAY,
} days_of_week_t;

/*
The typedef and its alias days_of_week_t are optional, but like with structs, they make the enum easier to use.

In the example above, days_of_week_t is a new type that can only have one of the values defined in the enum:

MONDAY, which is 0
TACO_TUESDAY, which is 1
WEDNESDAY, which is 2
THURSDAY, which is 3
FRIDAY, which is 4
SATURDAY, which is 5
FUNDAY, which is 6
You can use the enum type like this:
*/

typedef struct Event {
  char *title;
  days_of_week_t day;
} event_t;

// Or if you don't want to use the alias:

typedef struct Event {
  char *title;
  enum DaysOfWeek day;
} event_t;

/*
An enum is not a collection type like a struct or an array. It's just a list of integers constrained to a new type, where each is given an explicit name.
*/

typedef enum Color {
  RED,
  GREEN,
  BLUE,
} color_t;