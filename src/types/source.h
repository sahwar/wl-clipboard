/* wl-clipboard
 *
 * Copyright © 2019 Sergey Bugaev <bugaevc@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
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

#ifndef TYPES_SOURCE_H
#define TYPES_SOURCE_H

#include "selection-protocols.h"

struct source {
    /* These fields are filled in by whoever creates this source */
    void *user_data;
    void (*pasted_callback)(struct source *self);
    void (*cancelled_callback)(struct source *self);

    const char * const *data_to_copy;
    const char *temp_file_to_copy;

    struct wl_proxy *proxy;

    /* This field is initialized by the implementation */
    void (*do_offer)(struct wl_proxy *proxy, const char *mime_type);
};

void source_offer(struct source *self, char *mime_type);

/* Initializers */

void init_wl_data_source(struct source *self);

#ifdef HAVE_GTK_PRIMARY_SELECTION
void init_gtk_primary_selection_source(struct source *self);
#endif

#ifdef HAVE_WP_PRIMARY_SELECTION
void init_zwp_primary_selection_source_v1(struct source *self);
#endif

#ifdef HAVE_WLR_DATA_CONTROL
void init_zwlr_data_control_source_v1(struct source *self);
#endif

#endif /* TYPES_SOURCE_H */
