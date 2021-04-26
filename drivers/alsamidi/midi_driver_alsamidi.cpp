/*************************************************************************/
/*  midi_driver_alsamidi.cpp                                             */
/*************************************************************************/
/*                       This file is part of:                           */
/*                           GODOT ENGINE                                */
/*                      https://godotengine.org                          */
/*************************************************************************/
/* Copyright (c) 2007-2020 Juan Linietsky, Ariel Manzur.                 */
/* Copyright (c) 2014-2020 Godot Engine contributors (cf. AUTHORS.md).   */
/*                                                                       */
/* Permission is hereby granted, free of charge, to any person obtaining */
/* a copy of this software and associated documentation files (the       */
/* "Software"), to deal in the Software without restriction, including   */
/* without limitation the rights to use, copy, modify, merge, publish,   */
/* distribute, sublicense, and/or sell copies of the Software, and to    */
/* permit persons to whom the Software is furnished to do so, subject to */
/* the following conditions:                                             */
/*                                                                       */
/* The above copyright notice and this permission notice shall be        */
/* included in all copies or substantial portions of the Software.       */
/*                                                                       */
/* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,       */
/* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF    */
/* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.*/
/* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY  */
/* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,  */
/* TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE     */
/* SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                */
/*************************************************************************/

#ifdef ALSAMIDI_ENABLED

#include "midi_driver_alsamidi.h"

#include "core/os/os.h"
#include "core/print_string.h"

void MIDIDriverALSAMidi::midi_callback(double deltatime, std::vector<unsigned char> *message, void *userData) {
	uint64_t timestamp = (uint64_t) deltatime;
	uint32_t size = message->size();

	if (size > 0) {
		MIDIDriver::receive_input_packet(timestamp, &(*message)[0], size);
	}
}

Error MIDIDriverALSAMidi::open() {
	// Setup midi stream
	midiin.openVirtualPort();

	midiin.setCallback(&MIDIDriverALSAMidi::midi_callback);
	
	return OK;
}

void MIDIDriverALSAMidi::close() {
	// Bah
}

PoolStringArray MIDIDriverALSAMidi::get_connected_inputs() {

	PoolStringArray list;

	// In this paradigm, the application is a client, not a server

	return list;
}

MIDIDriverALSAMidi::MIDIDriverALSAMidi() {
}

MIDIDriverALSAMidi::~MIDIDriverALSAMidi() {
}

#endif // ALSAMIDI_ENABLED
