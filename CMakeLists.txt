#nvs
set(nvs_source 
"hl_nvs/hl_nvs.c"
)
set(nvs_include 
"hl_nvs"
)
set(nvs_requires 
nvs_flash
)

#ble
set(ble_source 
"hl_ble/hl_ble.c"
"hl_ble/hl_ble_gap.c"
"hl_ble/hl_ble_gatt.c"
)
set(ble_include 
"hl_ble"
)
set(ble_requires 
bt
)

idf_component_register(SRCS ${nvs_source}
                            ${ble_source}
                       INCLUDE_DIRS ${nvs_include}
                                    ${ble_include}
                       REQUIRES ${nvs_requires}
                                ${ble_requires}
                       )

target_compile_options(${COMPONENT_LIB} PRIVATE "-Wno-format")
