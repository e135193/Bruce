/**
 * @file tag_o_matic.h
 * @author Rennan Cockles (https://github.com/rennancockles)
 * @brief Read and Write RFID tags
 * @version 0.1
 * @date 2024-07-17
 */

#include "mfrc522_i2c.h"
#include <Wire.h>
#include "core/globals.h"


struct PrintableUID{
	String uid;
	String bcc;
	String sak;
	String atqa;
	String picc_type;
};

class TagOMatic {
public:
	enum RFID_State {
		READ_MODE,
		CLONE_MODE,
		WRITE_MODE,
    RICKROLL_MODE,
		ERASE_MODE,
		LOAD_MODE,
		SAVE_MODE
  };

  MFRC522 mfrc522 = MFRC522(0x28);


	/////////////////////////////////////////////////////////////////////////////////////
	// Constructor
	/////////////////////////////////////////////////////////////////////////////////////
	TagOMatic();
	TagOMatic(RFID_State initial_state);

	/////////////////////////////////////////////////////////////////////////////////////
	// Arduino Life Cycle
	/////////////////////////////////////////////////////////////////////////////////////
	void setup();
	void loop();

private:
	RFID_State _initial_state;
	bool _read_uid = false;
  RFID_State current_state;
	MFRC522::Uid uid;
	PrintableUID printableUID;
	String strAllPages = "";
	int totalPages = 0;
	bool pageReadSuccess = false;

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
  void set_state(RFID_State state);

	/////////////////////////////////////////////////////////////////////////////////////
	// Operations
	/////////////////////////////////////////////////////////////////////////////////////
	void read_card();
	void clone_card();
	void erase_card();
	void write_data();
  void rickroll_card();
	void save_file();
	void load_file();

	/////////////////////////////////////////////////////////////////////////////////////
	// File handlers
	/////////////////////////////////////////////////////////////////////////////////////
  bool write_file(String filename);
  bool load_from_file();

	/////////////////////////////////////////////////////////////////////////////////////
	// Converters
	/////////////////////////////////////////////////////////////////////////////////////
  void format_data();
  void parse_data();

	/////////////////////////////////////////////////////////////////////////////////////
	// PICC Helpers
	/////////////////////////////////////////////////////////////////////////////////////
	bool PICC_IsNewCardPresent();

	String get_tag_type();
	bool read_data_blocks();
	bool read_mifare_classic_data_blocks(byte piccType, MFRC522::MIFARE_Key *key);
	bool read_mifare_classic_data_sector(MFRC522::MIFARE_Key *key, byte sector);
	bool read_mifare_ultralight_data_blocks();

	bool write_data_blocks();
	bool write_mifare_classic_data_block(int block, String data);
	bool write_mifare_ultralight_data_block(int block, String data);
	bool rickroll_data_blocks();

	bool erase_data_blocks();
};
