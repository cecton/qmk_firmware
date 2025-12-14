/* Copyright 2016 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "keycode_config.h"

keymap_config_t keymap_config;

/** \brief keycode_config
 *
 * This function is used to check a specific keycode against the bootmagic config,
 * and will return the corrected keycode, when appropriate.
 */
__attribute__((weak)) uint16_t keycode_config(uint16_t keycode) {
    return keycode;
}

/** \brief mod_config
 *
 *  This function checks the mods passed to it against the bootmagic config,
 *  and will remove or replace mods, based on that.
 */

__attribute__((weak)) uint8_t mod_config(uint8_t mod) {
    /**
     * Note: This function is for the 5-bit packed mods, NOT the full 8-bit mods.
     * More info about the mods can be seen in modifiers.h.
     */
    if (keymap_config.swap_lalt_lgui) {
        /** If both modifiers pressed or neither pressed, do nothing
         * Otherwise swap the values
         * Note: The left mods are ANDed with the right-hand values to check
         * if they were pressed with the right hand bit set
         */
        if (((mod & MOD_RALT) == MOD_LALT) ^ ((mod & MOD_RGUI) == MOD_LGUI)) {
            mod ^= (MOD_LALT | MOD_LGUI);
        }
    }
    if (keymap_config.swap_ralt_rgui) {
        if (((mod & MOD_RALT) == MOD_RALT) ^ ((mod & MOD_RGUI) == MOD_RGUI)) {
            /* lefthand values to preserve the right hand bit */
            mod ^= (MOD_LALT | MOD_LGUI);
        }
    }
    if (keymap_config.swap_lctl_lgui) {
        /* left mods ANDed with right-hand values to check for right hand bit */
        if (((mod & MOD_RCTL) == MOD_LCTL) ^ ((mod & MOD_RGUI) == MOD_LGUI)) {
            mod ^= (MOD_LCTL | MOD_LGUI);
        }
    }
    if (keymap_config.swap_rctl_rgui) {
        if (((mod & MOD_RCTL) == MOD_RCTL) ^ ((mod & MOD_RGUI) == MOD_RGUI)) {
            /* lefthand values to preserve the right hand bit */
            mod ^= (MOD_LCTL | MOD_LGUI);
        }
    }
    if (keymap_config.no_gui) {
        mod &= ~MOD_LGUI;
        mod &= ~MOD_RGUI;
    }

    return mod;
}
