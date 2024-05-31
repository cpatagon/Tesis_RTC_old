/*
 * Nombre del archivo: i2c_hal_adapter.c
 * Descripción: contiene la implementación concreta de las funciones declaradas
 *              en i2c_hal_adapter.h. Aquí se usa la HAL de STM32 para realizar
 *              las operaciones de I2C.
 * Autor: lgomez
 * Creado en: 26-05-2024 
 * Derechos de Autor: (C) 2023 [Tu nombre o el de tu organización]
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
/** @file
 ** @brief contiene la implementación concreta de las funciones declaradas en
 ** i2c_hal_adapter.h. Aquí se usa la HAL de STM32 para realizar las operaciones de I2C.
 **/

/* === Headers files inclusions =============================================================== */

#include "i2c_adapter.h"
//#include "i2c.h" // Incluir solo en el archivo de implementación
// HAL de STM32
// #include "stm32f4xx_hal.h" // o la HAL específica que estés usando


/* === Macros definitions ====================================================================== */


/* === Private data type declarations ========================================================== */

/* === Private variable declarations =========================================================== */

/* === Private function declarations =========================================================== */

/* === Public variable definitions ============================================================= */

extern I2C_HandleTypeDef hi2c1;

/* === Private variable definitions ============================================================ */

/* === Private function implementation ========================================================= */

/* === Public function implementation ========================================================== */

void I2C_HAL_Init(void) {
    // Inicializa el I2C usando HAL
}

void I2C_HAL_Transmit(uint16_t devAddr, uint8_t* data, uint16_t size, uint32_t timeout) {
	HAL_I2C_Master_Transmit(&hi2c1, devAddr, data, size, timeout);
}

void I2C_HAL_Receive(uint16_t devAddr, uint8_t* data, uint16_t size, uint32_t timeout) {
	HAL_I2C_Master_Receive(&hi2c1, devAddr, data, size, timeout);
}

I2C_Interface_t I2C_Interface = {
    .Init = I2C_HAL_Init,
    .Transmit = I2C_HAL_Transmit,
    .Receive = I2C_HAL_Receive
};


/* === End of documentation ==================================================================== */

