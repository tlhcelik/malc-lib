//
//    FILE: malc.h
//  AUTHOR: Talha Çelik
// VERSION: 1.0.0
// PURPOSE: DHT Temperature & Humidity Sensor and Relay Control library for Arduino
//     URL: http://talhacelik.com.tr
//

#ifndef malc_h
#define malc_h

#if ARDUINO < 100
#include <WProgram.h>
#else
#include <Arduino.h>
#endif

#define MALC_LIB_VERSION "1.0.0"

#include <dht.h>
#include <EEPROM.h>
#include <malc_exceptions.h>



class malc
{
public:

	// functions for relay	START
	int set_relay_pins(int relays[] ,int size);
	void open_all_relays();
	void close_all_relays();
	void open_relay(int relay_pin);
	void close_relay(int relay_pin);
	
	// functions for relay	END
	// functions for dht11 START
	
	int set_dht_pin(int dht ,int dht_model);
	void read_dht();
			
	double humidity;
    double temperature;
	// functions for dht11 END
	
	int get_last_open_relay_after_reboot(int relay_number);

	
private:
	
	void set_eeprom_to_relay_status(int relay_number, int relay_state);

	malc_exceptions e;
	dht DHT;
	
	int RELAY_COUNTER = 0;
	int dht_pin;
	bool all_relay_states = false; // for all relay state
	
	int relay_pins[];
	int all_using_pins[];


	};

	
#endif
