/*
 * config.h - configuration sub-system
 * Part of TinyG project
 *
 * Copyright (c) 2010 - 2012 Alden S. Hart Jr.
 *
 * TinyG is free software: you can redistribute it and/or modify it 
 * under the terms of the GNU General Public License as published by 
 * the Free Software Foundation, either version 3 of the License, 
 * or (at your option) any later version.
 *
 * TinyG is distributed in the hope that it will be useful, but 
 * WITHOUT ANY WARRANTY; without even the implied warranty of 
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. 
 * See the GNU General Public License for details.
 *
 * You should have received a copy of the GNU General Public License 
 * along with TinyG  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef config_h
#define config_h

#define NVM_RECORD_LEN 8			// NVM record length (fixed length)
#define NVM_BASE_ADDR 0x0000		// base address of usable NVM

// Choose one: This sets the index size into the cmdArray
#define INDEX_T int16_t				// default setting for > 127 indexed objects
//#define INDEX_T int8_t			// OK as long as there are less than 127 records

/**** Command definitions and objects (used by config and JSON) ****/

#define CMD_TOKEN_LEN 3				// mnemonic token string
#define CMD_NAME_LEN 24				// friendly name string
#define CMD_VALUE_STRING_LEN 32		// original value string or value as a string
#define CMD_FORMAT_LEN 48			// print formatting string
#define CMD_MAX_OBJECTS 16			// maximum number of objects in a status or other report

// CMD_ARRAY_SIZE - this is the biggest memory hog in the whole system with 
// the possible exception of the planner queue. It is dominated by the size 
// of CMD_NAME_LEN and CMD_VALUE_STRING_LEN which are statically allocated 
// and should be as short as possible. The array size needs to allow for one 
// parent JSON object and enough children to complete the largest possible 
// operation. Right now this is a the general group display display. 

#define CMD_ARRAY_SIZE (1 + CMD_MAX_OBJECTS) // a root + maximum children

#define CMD_NAMES_FIELD_LEN (CMD_TOKEN_LEN + CMD_NAME_LEN +2)
#define CMD_STRING_FIELD_LEN (CMD_TOKEN_LEN + CMD_NAME_LEN + CMD_FORMAT_LEN +3)
#define JSON_STRING_LEN (OUTPUT_BUFFER_LEN)	// biggest thing that can fit in the input buffer

enum cmdValueType {					// value typing for config and JSON
	VALUE_TYPE_ERROR = -2,			// was unable to process the record
	VALUE_TYPE_NULL = -1,			// value is 'null'
	VALUE_TYPE_FALSE = false,		// value is 'false'
	VALUE_TYPE_TRUE = true,			// value is 'true'
	VALUE_TYPE_INT32,				// value is a uint32_t
	VALUE_TYPE_FLOAT,				// value is a floating point number
	VALUE_TYPE_STRING,				// value is in string field
	VALUE_TYPE_PARENT				// object is a parent to a sub-object
};

struct cmdObject {					// depending on use, not all elements may be populated
	INDEX_T index;					// index of tokenized name, or -1 if no token
	uint8_t nesting_level;			// 0 is root
	struct cmdObject *nx;			// pointer to next object or NULL if last (or only) object
	uint8_t	status;					// return status for this object
	int8_t value_type;				// see cfgValueType
	double value;					// numeric value (if applicable)
	char token[CMD_TOKEN_LEN+1];	// mnemonic token 
	char string[CMD_VALUE_STRING_LEN+1];// value string (if applicable)
	char name[CMD_NAME_LEN+1];		// JSON name field or friendly name
};									// OK, so it's not REALLY an object
typedef struct cmdObject cmdObj;
typedef uint8_t (*fptrCmd)(const INDEX_T i, cmdObj *cmd); // required for cmd table access
cmdObj cmd_array[CMD_ARRAY_SIZE];	// cmd_array[0] is the root object

/*
 * Global Scope Functions
 */

void cfg_init(void);
uint8_t cfg_config_parser(char *str);
void cfg_init_gcode_model(void);

// cmd accessors
uint8_t cmd_get(const INDEX_T i, cmdObj *cmd);	// entry point for gets
uint8_t cmd_set(const INDEX_T i, cmdObj *cmd);	// entry point for sets
void cmd_print(const INDEX_T i);				// entry point for print

struct cmdObject *cmd_new_object(cmdObj *cmd);
uint8_t cmd_get_cmd(const INDEX_T i, cmdObj *cmd);
INDEX_T cmd_get_index_by_token(const char *str);
INDEX_T cmd_get_index(const char *str);
INDEX_T cmd_get_max_index(void);
char *cmd_get_token(const INDEX_T i, char *string);
char cmd_get_group(const INDEX_T i);

uint8_t cmd_read_NVM(const INDEX_T i, cmdObj *cmd);
uint8_t cmd_write_NVM(const INDEX_T i, const cmdObj *cmd);

#ifdef __DEBUG
void cfg_dump_NVM(const uint16_t start_record, const uint16_t end_record, char *label);
#endif

/**** Global scope config structures ****/

// main configuration parameter table
struct cfgAxisParameters {
	uint8_t axis_mode;				// see tgAxisMode in gcode.h
	double feedrate_max;			// max velocity in mm/min or deg/min
	double velocity_max;			// max velocity in mm/min or deg/min
	double travel_max;				// work envelope w/warned or rejected blocks
	double jerk_max;				// max jerk (Jm) in mm/min^3
	double junction_dev;			// aka cornering delta
	double radius;					// radius in mm for rotary axis modes

	// homing cycle settings
	uint8_t switch_mode;			// 1=limit switches enabled, 0=not enabled
	double homing_travel;			// distance between crashes or switches
	double homing_search_velocity;	// homing search velocity
	double homing_latch_velocity;	// homing latch velocity
	double homing_zero_offset;		// machine coordinate system zero offset from switches (backoff value)
	double homing_work_offset;		// work coorinate system zero offset from machine zero
};

struct cfgMotorParameters {
	uint8_t	motor_map;				// map motor to axis
  	uint8_t microsteps;				// microsteps to apply for each axis (ex: 8)
	uint8_t polarity;				// 0=normal polarity, 1=reverse motor direction
 	uint8_t power_mode;				// 1=lo power idle mode, 0=full power idle mode
	double step_angle;				// degrees per whole step (ex: 1.8)
	double travel_rev;				// mm or deg of travel per motor revolution
	double steps_per_unit;			// steps (usteps)/mm or deg of travel
};

struct cfgParameters {
	double profile;					// configuration profile in effect
	double version;					// configuration version for migration

	uint16_t nvm_base_addr;			// NVM base address
	uint16_t nvm_profile_base;		// NVM base address of current profile

	// general settings / globals
	double min_segment_len;			// line drawing resolution in mm
	double arc_segment_len;			// arc drawing resolution in mm
	double estd_segment_usec;		// approximate segment time in microseconds
	double corner_acceleration;		// centripetal acceleration max for cornering
	uint8_t enable_acceleration;	// enable acceleration control

	// gcode power-on default settings - defaults are not the same as the gm state
	double select_plane;			// G17,G18,G19 reset default
	double inches_mode;				// G20,G21 reset default
	double path_control;			// G61,G61.1,G64 reset default
	double absolute_mode;			// G90,G91 reset default

	// communications settings		// these are shadow settigns for XIO cntrl bits
	uint8_t ignore_cr;				// ignore CR on RX
	uint8_t ignore_lf;				// ignore LF on RX
	uint8_t enable_cr;				// enable CR in CRFL expansion on TX
	uint8_t enable_echo;			// enable echo - also used for gating JSON responses
	uint8_t enable_xon;				// enable XON/XOFF mode

	// axis and motor structs
	struct cfgAxisParameters a[AXES];	// settings for axes X,Y,Z,A B,C
	struct cfgMotorParameters m[MOTORS];// settings for motors 1-4

	// status report configs
	uint8_t status_report_interval;	// in MS. set non-zero to enable
	INDEX_T status_report_spec[CMD_MAX_OBJECTS];
};
struct cfgParameters cfg; 			// declared in the header to make it global
#define CFG(x) cfg.a[x]				// handy macro for referencing axis values,
									// e.g: CFG(X_AXIS).steps_per_mm

/* unit test setup */
//#define __UNIT_TEST_CONFIG		// uncomment to enable config unit tests
#ifdef __UNIT_TEST_CONFIG
void cfg_unit_tests(void);
#define	CONFIG_UNITS cfg_unit_tests();
#else
#define	CONFIG_UNITS
#endif // __UNIT_TEST_CONFIG

#endif