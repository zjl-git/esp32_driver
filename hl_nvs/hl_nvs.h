#ifndef _HL_NVS__
#define _HL_NVS__

#ifdef __cplusplus
extern "C"
{
#endif

typedef enum {
    NVS_DATA_TYPE_INI8_T,
    NVS_DATA_TYPE_UINI8_T,
    NVS_DATA_TYPE_INI16_T,
    NVS_DATA_TYPE_UINI16_T,
    NVS_DATA_TYPE_INI32_T,
    NVS_DATA_TYPE_UINI32_T,
    NVS_DATA_TYPE_INI64_T,
    NVS_DATA_TYPE_UINI64_T,
} nvs_data_type;

void hl_nvs_init(void);

#ifdef __cplusplus
}
#endif

#endif
