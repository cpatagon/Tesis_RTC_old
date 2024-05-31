/*
 * Nombre del archivo: i2c_interface.h
 * Descripción: Este archivo define la interfaz abstracta para las operaciones de I2C.
 * Autor: lgomez
 * Creado en: 26-05-2024
 * Derechos de Autor: (C) 2023 Luis Gómez
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
#ifndef INC_I2C_INTERFACE_H
#define INC_I2C_INTERFACE_H
/** @file
 ** @brief
 **/

/* === Headers files inclusions ================================================================ */
#include <stdint.h>
#ifndef TEST // Esta línea se asegura que i2c.h no se incluya durante las pruebas
#include "i2c.h"
#endif
/* === Cabecera C++ ============================================================================ */
#ifdef __cplusplus
extern "C" {
#endif

/* === Public macros definitions =============================================================== */

/* === Public data type declarations =========================================================== */

typedef struct {
    void (*Init)(void);
    void (*Transmit)(uint16_t devAddr, uint8_t * data, uint16_t size, uint32_t timeout);
    void (*Receive)(uint16_t devAddr, uint8_t * data, uint16_t size, uint32_t timeout);
} I2C_Interface_t;

extern I2C_Interface_t I2C_Interface;

/* === Public variable declarations ============================================================ */

/* === Public function declarations ============================================================ */

void I2C_HAL_Init(void);
void I2C_HAL_Transmit(uint16_t devAddr, uint8_t * data, uint16_t size, uint32_t timeout);
void I2C_HAL_Receive(uint16_t devAddr, uint8_t * data, uint16_t size, uint32_t timeout);

/* === End of documentation ==================================================================== */

#ifdef __cplusplus
}
#endif
#endif /* INC_I2C_INTERFACE_H */
