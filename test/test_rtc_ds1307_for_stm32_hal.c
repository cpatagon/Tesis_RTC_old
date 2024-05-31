/*
 * Nombre del archivo: test_rtc_ds1307_for_stm32_hal.c
 * Descripción: Pruebas orientadas a analizar conjuntos de datos entregados por los sensores de
 * MP (Material Particulado). Para su desarrollo, se utilizó la técnica de Desarrollo Guiado por
 * Pruebas (TDD, por sus siglas en inglés). El objetivo es implementar un conjunto de pruebas
 * unitarias que guíen el desarrollo del software de manera iterativa.
 * Autor: Luis Gómez P.
 * Derechos de Autor: (C) 2023 CESE FIUBA
 * Licencia: GNU General Public License v3.0
 *
 * Este programa es software libre: puedes redistribuirlo y/o modificarlo
 * bajo los términos de la Licencia Pública General GNU publicada por
 * la Free Software Foundation, ya sea la versión 3 de la Licencia, o
 * (a tu elección) cualquier versión posterior.
 *
 * Este programa se distribuye con la esperanza de que sea útil,
 * pero SIN NINGUNA GARANTÍA; sin siquiera la garantía implícita
 * de COMERCIABILIDAD o APTITUD PARA UN PROPÓSITO PARTICULAR. Ver la
 * Licencia Pública General GNU para más detalles.
 *
 * Deberías haber recibido una copia de la Licencia Pública General GNU
 * junto con este programa. Si no es así, visita <http://www.gnu.org/licenses/>.
 *
 * SPDX-License-Identifier: GPL-3.0-only
 *
 */
/*
//////////////////////////////////////////////
// *** lista de pruebas pendientes ***
07.- Prender leds que ya están prendidos antes.
08.- Apagar los leds que ya estén apagados.
09.- Comprobar valores prohibidos.
10.- Comprobar los valores de borde o límite.
///////////////////////////////////////////////
*/

/**
 * @file  test_rtc_ds1307_for_stm32_hal.c
 * @brief Este archivo contiene pruebas unitarias para el módulo 
 *
 *
 * @test Pruebas unitarias implementadas:
 */

/* === Headers files inclusions =============================================================== */

#include "unity.h"
#include "mock_i2c_adapter.h"
#include "rtc_ds1307_for_stm32_hal.h"

// Declarar la variable mock_i2c
I2C_Interface_t mock_i2c;

void setUp(void) {
    mock_i2c.Init = I2C_HAL_Init;
    mock_i2c.Transmit = I2C_HAL_Transmit;
    mock_i2c.Receive = I2C_HAL_Receive;
}

void tearDown(void) {
    // Limpiar si es necesario
}

/**
 * @brief Prueba la función DS1307_Init para asegurar que inicializa el I2C y arranca el reloj.
 *
 * Esta prueba configura expectativas para las funciones de inicialización y transmisión de I2C.
 * Luego, llama a la función DS1307_Init y verifica que las funciones I2C se llamen correctamente
 * para inicializar el reloj DS1307.
 */
void test_DS1307_Init_Should_InitializeI2CAndStartClock(void) {
    // Configurar expectativas para las funciones mock
    I2C_HAL_Init_CMockExpect(__LINE__);

    uint8_t expected_data[] = {DS1307_REG_SECOND, 0}; // Definir el arreglo explícitamente
    I2C_HAL_Transmit_CMockExpect(__LINE__, DS1307_I2C_ADDR << 1, expected_data, 2, DS1307_TIMEOUT);

    // Llamar a la función que se está probando
    DS1307_Init(&mock_i2c);

    // No se necesitan verificaciones adicionales de mock aquí, CMock se encargará de las expectativas.
}

void test_DS1307_GetDate_Should_ReturnCorrectDate(void) {
    uint8_t expected_date = 0x15; // Supongamos que esperamos que la fecha sea 15

    // Configurar expectativa para la función mock
    I2C_HAL_Transmit_CMockExpect(__LINE__, DS1307_I2C_ADDR, &DS1307_REG_DATE, 1, DS1307_TIMEOUT);
    I2C_HAL_Receive_CMockExpect(__LINE__, DS1307_I2C_ADDR, &expected_date, 1, DS1307_TIMEOUT);

    // Llamar a la función que se está probando
    uint8_t date = DS1307_GetDate();

    // Verificar que la función devuelve el valor esperado
    TEST_ASSERT_EQUAL_UINT8(expected_date, date);
}










/* === End of documentation ==================================================================== */
