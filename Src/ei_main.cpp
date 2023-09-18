
/* Include ----------------------------------------------------------------- */
#include "edge-impulse-sdk/porting/ei_classifier_porting.h"
#include "edge-impulse-sdk/classifier/ei_run_classifier.h"
#include "edge-impulse-sdk/dsp/numpy.hpp"

static const float features[] = {
    // copy raw features here (for example from the 'Live classification' page)
    // see https://docs.edgeimpulse.com/docs/running-your-impulse-spresense
  
    
-4.3545, -5.9393, -0.7353, -2.9492, -6.0235, -0.7322, -1.9520, -6.0882, -0.8360, -1.6306, -5.8224, -0.9999, -1.2827, -5.6138, -0.2146, -0.6820, -5.0856, 0.7278, 0.5520, -4.9324, 1.1027, 3.8033, -5.2054, 0.9716, 4.9249, -5.8833, 0.2424, 5.3772, -5.9891, 0.1269, 7.3177, -5.9177, 1.1410, 8.3628, -5.3781, 2.3813, 8.2836, -6.4872, 2.8105, 8.7899, -6.6904, 2.4029, 9.9261, -7.5631, 1.2909, 10.7163, -8.4071, 0.7227, 11.2360, -8.5718, 0.6931, 12.4476, -9.1523, 1.3018, 13.8292, -9.2617, 1.7847, 14.2530, -9.4653, 1.6180, 13.9558, -9.9982, 0.6033, 13.4560, -10.0099, 0.0009, 13.1876, -9.9826, 0.0606, 12.4340, -9.7861, 0.2041, 11.5574, -9.4815, -0.1954, 10.8950, -9.4445, -0.3904, 9.1556, -8.9868, -0.7507, 8.1187, -8.4861, -0.7346, 7.6384, -8.3751, -0.6104, 6.2649, -8.2827, -0.3959, 4.9142, -7.9456, -0.5537, 4.7716, -7.7026, -0.8244, 4.0239, -7.3147, -1.4503, 2.8431, -7.5325, -1.3122, 2.1887, -7.6037, -1.1305, 1.0527, -7.4413, -0.7582, 0.3026, -6.7485, -0.8443, -0.1312, -6.4703, -0.9143, -0.8323, -6.4108, -0.9236, -1.3770, -6.4980, -0.8863, -1.7154, -6.4633, -0.7621, -2.7888, -6.1559, -0.7941, -3.4550, -5.9502, -1.1241, -3.6265, -5.7724, -1.4790, -4.2080, -6.0790, -1.6581, -4.6588, -5.9957, -1.1004, -4.9350, -5.7757, -0.8706, -5.9328, -5.7884, -0.9460, -7.3080, -6.0255, -1.8920, -7.7967, -6.2394, -2.3135, -8.5537, -6.0280, -2.8838, -9.5372, -6.1969, -2.6695, -9.8661, -6.2375, -2.5093, -10.3826, -6.4599, -2.3361, -11.8045, -6.5553, -2.7451, -12.2959, -6.5401, -3.0124, -12.5323, -6.4935, -3.3106, -13.1668, -6.4349, -3.5005, -14.1207, -6.4977, -3.6227, -14.0882, -6.4631, -3.6340, -13.3745, -6.4467, -3.4532, -12.5642, -6.2987, -2.9854, -11.8045, -6.1196, -2.7756, -10.1923, -6.1289, -2.5836, -9.4806, -6.1878, -2.3158, -9.2142, -5.9874, -2.1623, -9.0495, -6.0359, -2.1642, -9.2552, -6.0512, -2.3953, -9.5779, -5.9060, -1.4344, -8.3968, -5.5107, -1.0385, -7.1144, -5.8026, -1.5390, -6.7915, -5.8975, -1.8227, -6.0653, -5.6368, -2.2507, -4.8429, -5.5004, -1.9905, -4.1605, -5.5230, -1.6002, -3.3930, -5.6110, -0.8368, -2.4301, -5.5655, -0.1655, -1.8352, -5.8662, -0.1987, -0.5261, -6.3167, -0.5790, 0.9548, -6.2478, -0.3909, 0.9704, -6.4531, -0.1003, 0.6412, -6.5405, 1.1670, 0.9406, -6.6822, 2.4151, 1.1531, -6.6225, 2.5601, 3.2850, -6.9773, 2.0222, 5.1267, -7.8976, 1.2677, 5.5055, -8.1642, 1.0068, 7.3370, -8.7308, 0.9602, 8.5883, -9.6913, 0.5007, 8.9513, -10.0544, -0.0495, 9.5804, -10.9321, -1.1829, 10.3467, -11.4920, -1.9716, 11.4622, -12.1895, -1.8073, 12.0702, -11.9300, -1.3611, 12.5904, -11.8113, -0.2295, 12.0180, -11.6607, 0.7938, 11.4215, -11.2966, 1.0653, 10.7006, -10.7123, 0.8710, 9.4263, -10.3896, 0.4398, 8.7394, -10.2466, 0.2774, 7.4057, -9.9754, -0.2409, 6.3240, -9.4818, -0.4760, 5.8350, -9.1924, -0.6238, 5.2463, -8.5159, -0.9717, 3.9799, -7.7559, -0.8145, 3.1990, -7.6706, -0.4949, 2.1635, -7.8292, -0.0406, 1.3035, -7.2176, -0.4148, 0.3279, -7.4331, -0.4115, -1.2722, -7.0689, -0.6743, -2.2393, -6.3879, -0.7094, -2.2413, -6.4356, -0.4884, -1.4268, -6.3885, -0.4236, -2.0824, -6.5885, -0.2424, -2.7478, -6.2282, -0.1589, -4.7363, -5.8199, -0.3006, -6.0841, -5.5638, -0.8438, -6.0144, -5.6633, -1.1271, -5.0286, -5.6044, -1.6137, -4.8902, -5.8538, -1.2396, -5.5897, -5.8290, -0.8839, -6.6248, -5.4149, -0.7141, -6.6884, -5.4419, -0.8570, -6.4947, -5.4754, -1.8049, -6.6863, -5.7205, -2.9859
};


int raw_feature_get_data(size_t offset, size_t length, float *out_ptr) {
    memcpy(out_ptr, features + offset, length * sizeof(float));
    return 0;
}

int ei_main(void) {
    ei_printf("Edge Impulse standalone inferencing (IAR Embedded Workbench)\n");

    if (sizeof(features) / sizeof(float) != EI_CLASSIFIER_DSP_INPUT_FRAME_SIZE) {
        ei_printf("The size of your 'features' array is not correct. Expected %d items, but had %u\n",
            EI_CLASSIFIER_DSP_INPUT_FRAME_SIZE, sizeof(features) / sizeof(float));
        return 1;
    }

    ei_impulse_result_t result = { 0 };

    while (1) {
        // the features are stored into flash, and we don't want to load everything into RAM
        signal_t features_signal;
        features_signal.total_length = sizeof(features) / sizeof(features[0]);
        features_signal.get_data = &raw_feature_get_data;

        // invoke the impulse
        EI_IMPULSE_ERROR res = run_classifier(&features_signal, &result, true);


        ei_printf("run_classifier returned: %d\n", res);

        if (res != 0) return 1;

        ei_printf("Predictions (DSP: %d ms., Classification: %d ms., Anomaly: %d ms.): \n",
            result.timing.dsp, result.timing.classification, result.timing.anomaly);

#if EI_CLASSIFIER_OBJECT_DETECTION == 1
    for (size_t ix = 0; ix < EI_CLASSIFIER_OBJECT_DETECTION_COUNT; ix++) {
        auto bb = result.bounding_boxes[ix]; 
        if (bb.value == 0) {
            continue;
        }

        ei_printf("%s (%f) [ x: %u, y: %u, width: %u, height: %u ]\n", bb.label, bb.value, bb.x, bb.y, bb.width, bb.height);
    }
#else
        // print the predictions
        ei_printf("[");
        for (size_t ix = 0; ix < EI_CLASSIFIER_LABEL_COUNT; ix++) {
            ei_printf("%.5f", result.classification[ix].value);
#if EI_CLASSIFIER_HAS_ANOMALY == 1
            ei_printf(", ");
#else
            if (ix != EI_CLASSIFIER_LABEL_COUNT - 1) {
                ei_printf(", ");
            }
#endif
        }
#if EI_CLASSIFIER_HAS_ANOMALY == 1
        printf("%.3f", result.anomaly);
#endif
        printf("]\n");
#endif

        ei_sleep(2000);
    }
}