/* Copyright (C)
* 2018 - John Melton, G0ORX/N6LYT
*
* This program is free software; you can redistribute it and/or
* modify it under the terms of the GNU General Public License
* as published by the Free Software Foundation; either version 2
* of the License, or (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program; if not, write to the Free Software
* Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
*
*/

#ifndef _NEW_PROTOCOL_H
#define _NEW_PROTOCOL_H

#include <semaphore.h>
#include "receiver.h"

// port definitions from host
#define GENERAL_REGISTERS_FROM_HOST_PORT 1024
#define PROGRAMMING_FROM_HOST_PORT 1024
#define RECEIVER_SPECIFIC_REGISTERS_FROM_HOST_PORT 1025
#define TRANSMITTER_SPECIFIC_REGISTERS_FROM_HOST_PORT 1026
#define HIGH_PRIORITY_FROM_HOST_PORT 1027
#define AUDIO_FROM_HOST_PORT 1028
#define TX_IQ_FROM_HOST_PORT 1029

// port definitions to host
#define COMMAND_RESPONCE_TO_HOST_PORT 1024
#define HIGH_PRIORITY_TO_HOST_PORT 1025
#define MIC_LINE_TO_HOST_PORT 1026
#define WIDE_BAND_TO_HOST_PORT 1027
#define RX_IQ_TO_HOST_PORT_0 1035
#define RX_IQ_TO_HOST_PORT_1 1036
#define RX_IQ_TO_HOST_PORT_2 1037
#define RX_IQ_TO_HOST_PORT_3 1038
#define RX_IQ_TO_HOST_PORT_4 1039
#define RX_IQ_TO_HOST_PORT_5 1040
#define RX_IQ_TO_HOST_PORT_6 1041
#define RX_IQ_TO_HOST_PORT_7 1042
#define RX_IQ_TO_HOST_PORT_8 1043
#define RX_IQ_TO_HOST_PORT_9 1044
#define RX_IQ_TO_HOST_PORT_10 1045
#define RX_IQ_TO_HOST_PORT_11 1046
#define RX_IQ_TO_HOST_PORT_12 1047
#define RX_IQ_TO_HOST_PORT_13 1048
#define RX_IQ_TO_HOST_PORT_14 1049
#define RX_IQ_TO_HOST_PORT_15 1050


#define MIC_SAMPLES 64

extern int data_socket;
extern sem_t *response_sem;

extern unsigned int exciter_power;
extern unsigned int alex_forward_power;
extern unsigned int alex_reverse_power;

extern void protocol2_init(RADIO *radio);
extern void protocol2_stop();
extern void protocol2_run();
extern void protocol2_start_receiver(RECEIVER *r);
extern void protocol2_stop_receiver(RECEIVER *r);
extern void protocol2_high_priority();
extern void protocol2_general();
extern void protocol2_receive_specific();

extern void protocol2_start_wideband(WIDEBAND *w);
extern void protocol2_stop_wideband();

extern void filter_board_changed();
extern void pa_changed();
extern void tuner_changed();
extern void cw_changed();

extern void setMox(int state);
extern int getMox();
extern void setTune(int state);
extern int getTune();

extern void protocol2_process_local_mic(RADIO *r);
extern void protocol2_audio_samples(RECEIVER *rx,short left_audio_sample,short right_audio_sample);
extern void protocol2_iq_samples(int isample,int qsample);
extern gboolean protocol2_is_running();
#endif
