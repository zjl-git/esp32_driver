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

#gpio
set(gpio_source 
"hl_gpio/hl_gpio.c"
)
set(gpio_include 
"hl_gpio"
)
set(gpio_requires 
driver
)

#spi
set(spi_source 
"hl_spi/hl_spi.c"
)
set(spi_include 
"hl_spi"
)
set(spi_requires 
driver
)

#uart
set(uart_source 
"hl_uart/hl_uart.c"
)
set(uart_include 
"hl_uart"
)
set(uart_requires 
driver
)


idf_component_register(SRCS ${nvs_source}
                            ${ble_source}
                            ${gpio_source}
                            ${spi_source}
                            ${uart_source}
                       INCLUDE_DIRS ${nvs_include}
                                    ${ble_include}
                                    ${gpio_include}
                                    ${spi_include}
                                    ${uart_include}
                       REQUIRES ${nvs_requires}
                                ${ble_requires}
                                ${gpio_requires}
                                ${spi_requires}
                                ${uart_requires}
                       )

target_compile_options(${COMPONENT_LIB} PRIVATE "-Wno-format")
