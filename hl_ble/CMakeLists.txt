idf_component_register(SRCS "hl_ble.c"
                            "hl_ble_gap.c"
                       INCLUDE_DIRS "."
                       REQUIRES bt)

target_compile_options(${COMPONENT_LIB} PRIVATE "-Wno-format")
