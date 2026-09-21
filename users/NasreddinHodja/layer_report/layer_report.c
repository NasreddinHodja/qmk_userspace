#include "layer_report.h"

#include "raw_hid.h"

#include <stdio.h>

void send_layer_report(uint8_t layer) {
    uint8_t report[32] = {0};
    report[0] = 0x01;
    report[1] = layer;

    const char* layer_name =
        (layer < layer_count && layer_names[layer] != NULL)
            ? layer_names[layer]
            : "UNKNOWN";

    snprintf((char*)&report[1], sizeof(report) - 1, "%u:%s", layer, layer_name);
    raw_hid_send(report, sizeof(report));
}
