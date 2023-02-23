idf_component_register(SRCS "hl_nvs.c"
                       INCLUDE_DIRS "."
                       REQUIRES nvs_flash)

target_compile_options(${COMPONENT_LIB} PRIVATE "-Wno-format")
