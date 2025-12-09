#include "app_info.h"

static const char *APP_NAME = "Mini Telemetria ESP32";
static const char *APP_VERSION = "v0.1.0";

const char *app_info_get_name(void){
    return APP_NAME;
}

const char *app_info_get_version(void){
    return APP_VERSION;
}