/*
 * Copyright 2015-2017 the Pacemaker project contributors
 *
 * The version control history for this file may have further details.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 */

#ifndef CRM_COMMON_ISO8601_INTERNAL
#  define CRM_COMMON_ISO8601_INTERNAL
#include <time.h>
#include <sys/time.h>
#include <ctype.h>
#include <crm/common/iso8601.h>

typedef struct crm_time_us crm_time_hr_t;
crm_time_hr_t *crm_time_hr_convert(crm_time_hr_t *target, crm_time_t *dt);
void crm_time_set_hr_dt(crm_time_t *target, crm_time_hr_t *hr_dt);
crm_time_hr_t *crm_time_timeval_hr_convert(crm_time_hr_t *target,
                                           struct timeval *tv);
crm_time_hr_t *crm_time_hr_new(const char *date_time);
void crm_time_hr_free(crm_time_hr_t * hr_dt);
char *crm_time_format_hr(const char *format, crm_time_hr_t * hr_dt);
const char *crm_now_string(time_t *when);

crm_time_t *parse_date(const char *date_str); /* in iso8601.c global but
                                                 not in header */

struct crm_time_us {
    int years;
    int months;                 /* Only for durations */
    int days;
    int seconds;
    int offset;                 /* Seconds */
    bool duration;
    int useconds;
};
#endif
