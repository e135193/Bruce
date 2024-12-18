/**
 * @file rfid125.h
 * @author Rennan Cockles (https://github.com/rennancockles)
 * @brief Read RFID 125kHz tags
 * @version 0.1
 * @date 2024-08-13
 */

#ifndef __RFID125_H__
#define __RFID125_H__

#include "core/globals.h"

#define RFID125_PACKET_SIZE	14
#define RFID125_START_MARK	0x02
#define RFID125_END_MARK	0x03
#if !defined(RFID125_RX_PIN) || !defined(RFID125_TX_PIN)
    #define RFID125_RX_PIN	    GROVE_SCL
    #define RFID125_TX_PIN  	GROVE_SDA
#endif


class RFID125
{
    public:
        enum RFID125_State {
            READ_MODE,
            // CLONE_MODE,
            // WRITE_MODE,
            // WRITE_NDEF_MODE,
            // ERASE_MODE,
            // LOAD_MODE,
            SAVE_MODE,
        };

        /////////////////////////////////////////////////////////////////////////////////////
        // Constructor
        /////////////////////////////////////////////////////////////////////////////////////
        RFID125();
        RFID125(RFID125_State initial_state);

        /////////////////////////////////////////////////////////////////////////////////////
        // Arduino Life Cycle
        /////////////////////////////////////////////////////////////////////////////////////
        void setup();
        void loop();

    private:
        HardwareSerial *_stream = NULL;
	    RFID125_State _initial_state;
        RFID125_State _current_state;
	    String _printable_data;
	    String _printable_checksum;
	    bool _tag_read = false;
        char _tag_data[RFID125_PACKET_SIZE];

        /////////////////////////////////////////////////////////////////////////////////////
        // Display functions
        /////////////////////////////////////////////////////////////////////////////////////
        void cls();
        void display_banner();
        void dump_card_details();

        /////////////////////////////////////////////////////////////////////////////////////
        // State management
        /////////////////////////////////////////////////////////////////////////////////////
        void select_state();
        void set_state(RFID125_State state);

        /////////////////////////////////////////////////////////////////////////////////////
        // Operations
        /////////////////////////////////////////////////////////////////////////////////////
        void read_card();
        bool read_card_data();
        // void clone_card();
        // void erase_card();
        // void write_data();
        // void write_ndef_data();
        void save_file();
        void clear_stream();
        // void load_file();

        /////////////////////////////////////////////////////////////////////////////////////
        // File handlers
        /////////////////////////////////////////////////////////////////////////////////////
        bool write_file(String filename);
        // bool load_from_file();

        /////////////////////////////////////////////////////////////////////////////////////
        // Converters
        /////////////////////////////////////////////////////////////////////////////////////
        void format_data();
        // void parse_data();
};

#endif
