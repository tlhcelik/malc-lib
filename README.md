# malc-lib
 [DHT](https://github.com/adafruit/DHT-sensor-library) Temperature &amp; Humidity Sensor and Relay Control library for Arduino

**İncluding Libray and Create Object**
```c
#include <malc.h>
malc MALC;
```

**Setting Relay and DHT 11 Pins**
```c
int relay_pins[4]={2,3,4,5};
MALC.set_relay_pins(relay_pins,4);
MALC.set_dht_pin(7,11);
```

**Open and Close All Relays**
```c
MALC.open_all_relays();
MALC.close_all_relays();
```

**Reading Humidity and Temperature**
```c
MALC.read_dht();
double temperature = MALC.temperature;
double humidity = MALC.humidity;
```

**Getting Relay Status**

_When after reboot or shutdown save to **EEPROM** relay status automatically._  
_In this way get last opened relays and open last relays._  
_This code writing to **setup()** function._   
```c
for (int i = 0; i < relay_pins.length; i++)
{
  if (MALC.get_last_open_relay_after_reboot(i)==1) MALC.open_relay(relay_pins[i]);
}
```
---
# malc.h file 
**Relay pins setter method**
```c
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
```

