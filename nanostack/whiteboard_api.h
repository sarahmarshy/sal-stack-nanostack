/*
 * Copyright (c) 2014-2015 ARM Limited. All rights reserved.
 *
 * SPDX-License-Identifier: LicenseRef-PBL
 *
 * Licensed under the Permissive Binary License, Version 1.0 (the "License"); you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * https://www.mbed.com/licenses/PBL-1.0
 *
 * See the License for the specific language governing permissions and limitations under the License.
 *
 */

#ifndef WHITEBOARD_API_H_
#define WHITEBOARD_API_H_

#include "net_interface.h"

/**
 * \file whiteboard_api.h
 * \brief An API for DAD, intercepting messages from backhaul network and keeping track of routes inside the PAN.
 */

#ifdef __cplusplus
extern "C" {
#endif

/*!
 * \struct whiteboard_entry_t
 * \brief A structure describing a whiteboarding entry.
 */
typedef struct whiteboard_entry_t {
    uint8_t                         address[16];        /*!< Registered IP address. */
    uint_least24_t                  ttl;                /*!< Whiteboard entry TTL (seconds). */
    uint8_t                         eui64[8];           /*!< EUI-64 of node that IP address is registered to. */
    int8_t                          interface_index;
} whiteboard_entry_t;

/**
 * \brief Read whiteboard entries
 * \param cur NULL to read first entry, or get next entry after cur.
 * \return A pointer to whiteboard_entry_t structure.
 */
extern whiteboard_entry_t *whiteboard_get(whiteboard_entry_t *cur);
#ifdef __cplusplus
}
#endif
#endif /* WHITEBOARD_API_H_ */
