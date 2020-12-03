/// @file SystemCfg.h
/// @brief Параметры компиляции ОС, относящиеся к расширениям, аппаратуре, etc.

#pragma once

#define MACS_USE_MPU             0
#define MACS_MPU_PROTECT_NULL    0     ///< Защита памяти по нулевому адресу от доступа.
#define MACS_MPU_PROTECT_STACK   0     ///< Аппаратная защита стека от переполнения.
