//
//    FILE: malc.cpp
//  AUTHOR: Talha Çelik
// VERSION: 1.0.0
// PURPOSE: DHT Temperature & Humidity Sensor and Relay Control library for Arduino
//     URL: http://talhacelik.com.tr
//
#include "malc.h"

int malc::set_relay_pins(int relays[] ,int size){
	
	RELAY_COUNTER = size;
	
	for (int i = 0; i < RELAY_COUNTER; i++)
	{
		relay_pins[i] = relays[i];
		pinMode(relay_pins[i] ,OUTPUT);
	}
	
	// WHEN RELAY SET AGAIN CLOSE ALL RELAYS
	for (int i = 0; i < RELAY_COUNTER; i++)
		{
			digitalWrite(relay_pins[i],HIGH);
		}
	return 0;
}

void malc::close_all_relays(){
	
	for (int i = 0; i < RELAY_COUNTER; i++)
		{
			digitalWrite(relay_pins[i],HIGH);
			set_eeprom_to_relay_status(i,0); // ALL RELAYS CLOSE SAVE TO EEPROM 
		}
	all_relay_states = false; // all relay is close
}

void malc::open_all_relays(){
	
	for (int i = 0; i < RELAY_COUNTER; i++)
		{
			digitalWrite(relay_pins[i],LOW);
			set_eeprom_to_relay_status(i,1); // ALL RELAYS OPEN SAVE TO EEPROM 
		}
		all_relay_states = true; // true is open all relays
		

}

void malc::close_relay(int relay_pin){
	for (int i = 0; i < RELAY_COUNTER; i++)
	{
		if (relay_pin == relay_pins[i])
		{
			digitalWrite(relay_pins[i],HIGH);
			//EEPROM SAVE TO RELAYS LAST STATE ALL RELAYS
			set_eeprom_to_relay_status(i,0);
		}
	}
	
}
void malc::open_relay(int relay_pin){
	for (int i = 0; i < RELAY_COUNTER; i++)
	{
		if (relay_pin == relay_pins[i])
		{
			digitalWrite(relay_pins[i],LOW);
			//EEPROM SAVE TO RELAYS LAST STATE ALL RELAYS
			set_eeprom_to_relay_status(i,1);
		}
	}

}

int malc::set_dht_pin(int dht ,int dht_model){
	if (dht_model != 11)  e.model_exception(); // if dht model is not 11 end program except to error zero (0) 
	dht_pin = dht;
}

void malc::read_dht(){
	int chk = DHT.read11(dht_pin);
	humidity = DHT.humidity;
	temperature = DHT.temperature;
	
}

void malc::set_eeprom_to_relay_status(int relay_number, int relay_state){
	
	EEPROM.write(relay_number,relay_state);
	
}

int malc::get_last_open_relay_after_reboot(int relay_number){
	
	int value = EEPROM.read(relay_number);
	return value;
}

/*

set_eeprom_to_relay_status(int relay_number, int status)
relay number MAX RELAY_COUNTER
status 0 = relay OFF
status 1 = relay ON
*/
