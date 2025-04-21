typedef enum
{
    LOG_DEBUG = 0,
    LOG_INFO,
    LOG_WARN,
    LOG_ERROR
} LogLevel;

int main()
{
    // Switch Case
    // One of the best features of enums is that it can be used in switch statements. Enums + switch statements:

    // Avoid "magic numbers"
    // Use descriptive names
    // With modern tooling, will give you an error/warning that you haven't handled all the cases in your switch
    // Here's an example:

    int logLevel;
    int errorCode;

    switch (logLevel)
    {
    case LOG_DEBUG:
        printf("Debug logging enabled\n");
        break;
    case LOG_INFO:
        printf("Info logging enabled\n");
        break;
    case LOG_WARN:
        printf("Warning logging enabled\n");
        break;
    case LOG_ERROR:
        printf("Error logging enabled\n");
        break;
    default:
        printf("Unknown log level: %d\n", logLevel);
        break;
    }
    // You'll notice that we have a break after each case. If you do not have a break (or return), the next case will still execute: it "falls through" to the next case. Many devs have written bugs when using switch statements, because they forgot to add break.

    // In some rare cases, you might want the fallthrough:
    switch (errorCode)
    {
        case 1:
        case 2:
        case 3:
            // 1, 2, and 3 are all minor errors
            printf("Minor error occurred. Please try again.\n");
            break;
        case 4:
        case 5:
            // 4 and 5 are major errors
            printf("Major error occurred. Restart required.\n");
            break;
        default:
            printf("Unknown error.\n");
            break;
    }
}
// But usually, it's a footgun. You'll almost always want a break at the end of each case statement.

typedef enum
{
    HTTP_BAD_REQUEST = 400,
    HTTP_UNAUTHORIZED = 401,
    HTTP_NOT_FOUND = 404,
    HTTP_TEAPOT = 418,
    HTTP_INTERNAL_SERVER_ERROR = 500
} HttpErrorCode;

char *http_to_str(HttpErrorCode code)
{
    switch (code)
    {
        case HTTP_BAD_REQUEST: return "400 Bad Request";
        case HTTP_UNAUTHORIZED: return "401 Unauthorized";
        case HTTP_NOT_FOUND: return "404 Not Found";
        case HTTP_TEAPOT: return "418 I AM A TEAPOT!";
        case HTTP_INTERNAL_SERVER_ERROR: return "500 Internal Server Error";
        default: return "Unknown HTTP status code";
    }
}
