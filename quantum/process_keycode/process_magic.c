/* Copyright 2019 Jack Humbert
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
#include "process_magic.h"
#include "keycode_config.h"
#include "keycodes.h"
#include "eeconfig.h"

#ifdef AUDIO_ENABLE
#    include "audio.h"

#    ifndef AG_NORM_SONG
#        define AG_NORM_SONG SONG(AG_NORM_SOUND)
#    endif
#    ifndef AG_SWAP_SONG
#        define AG_SWAP_SONG SONG(AG_SWAP_SOUND)
#    endif
#    ifndef CG_NORM_SONG
#        define CG_NORM_SONG SONG(AG_NORM_SOUND)
#    endif
#    ifndef CG_SWAP_SONG
#        define CG_SWAP_SONG SONG(AG_SWAP_SOUND)
#    endif
float ag_norm_song[][2] = AG_NORM_SONG;
float ag_swap_song[][2] = AG_SWAP_SONG;
float cg_norm_song[][2] = CG_NORM_SONG;
float cg_swap_song[][2] = CG_SWAP_SONG;
#endif

/**
 * MAGIC actions (BOOTMAGIC without the boot)
 */
bool process_magic(uint16_t keycode, keyrecord_t *record) {
    // skip anything that isn't a keyup
    if (record->event.pressed) {
        if (IS_MAGIC_KEYCODE(keycode)) {
            /* keymap config */
            keymap_config.raw = 0;

            eeconfig_update_keymap(keymap_config.raw);
            clear_keyboard(); // clear to prevent stuck keys

            return false;
        }
    }

    // Not a magic keycode so continue processing
    return true;
}
