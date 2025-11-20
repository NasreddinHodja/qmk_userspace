#include "layer_report.h"

#include "raw_hid.h"

#include <string.h>

void send_layer_report(uint8_t layer) {
    uint8_t report[32] = {0};
    report[0] = 0x01;
    report[1] = layer;

    const char* layer_name =
        (layer < layer_count && layer_names[layer] != NULL)
            ? layer_names[layer]
            : "UNKNOWN";

    strncpy((char*)&report[2], layer_name, 30);
    raw_hid_send(report, sizeof(report));
}
