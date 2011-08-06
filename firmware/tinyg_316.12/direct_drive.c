/*
 * direct_drive.c - commands to drive stepper motors directly (no Gcode)
 * Part of TinyG project
 *
 * Copyright (c) 2010 - 2011 Alden S. Hart Jr.
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
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. 
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY 
 * CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, 
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE 
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

//#include <stdlib.h>
//#include <stdarg.h>
#include <avr/io.h>

//#include <stdio.h>
//#include <math.h>
//#include <avr/pgmspace.h>

#include "tinyg.h"
#include "config.h"
#include "stepper.h"

/*
 * Local Scope Data and Functions
 */

struct ddStruct {
 // motor configuration
  	uint8_t microstep;			// microsteps to apply for each axis (ex: 8)
 	uint8_t low_pwr_idle;		// 1=low power idle mode, 0=full power idle mode
	uint16_t seek_steps_sec;	// max seek whole steps per second (ex: 1600)
	uint16_t feed_steps_sec;	// max feed whole steps per second (ex: 1200)
	double degree_per_step;		// degrees per whole step (ex: 1.8)
 // machine configuration
	double mm_per_rev;			// millimeters of travel per revolution (ex: 2.54)
	double mm_travel;			// millimeters of travel max in N dimension (ex: 400)
	double steps_per_mm;		// # steps (actually usteps)/mm of travel (COMPUTED)
	uint8_t limit_enable;		// 1=limit switches enabled, 0=not enabled	
};

struct ddStruct dd;

/* 
 * dd_init() - initialize direct drive system 
 */

void dd_init() 
{
//	cfg_reset();
}

/* 
 * dd_parser() - parse a direct drive command 
 */

int dd_parser(char *text)
{
/*
	char c;
	char *val = 0;				// pointer to normalized value 
	char *end = 0;				// pointer to end of value
	uint8_t i = 0;				// buffer read index (buf must be < 256 chars)
	uint8_t j = 0;				// buffer write index
	uint8_t	axis = 0;			// axis index
*/

/*
	// normalize and split text in place
	while ((c = text[i++]) != 0) {
		if (c == '=') {							// handle separator
			text[j++] = 0;						// terminate tag at separator
			val = &text[j];						// new string starts at value
		} else if ((c == '-') || (c == '+') || (c == '.')) { // pass special chars
			text[j++] = c;		
		} else if (c == '?') { 					// question marks are OK, too
			text[j++] = c;		
		} else if (c >= 'a' && c <= 'z') {		// convert lower to upper
			text[j++] = c-'a'+'A';
		} else if (c >= 'A' && c <= 'Z') {		// pass upper case letters
			text[j++] = c;
		} else if (c >= '0' && c <= '9') {		// pass numbers
			text[j++] = c;
		}
	}
	text[j++] = 0;
	end = &text[j];								// needed for string-to-double

	// pick off tag characters starting with first character
	switch (text[0]) {
		case '?': cfg_dump(); return (CFG_STATUS_OK);
		case 'Q': return (CFG_STATUS_QUIT);
		case 'M': cfg.mm_per_arc_segment = strtod(val, &end); return(0);
		case 'X': axis = X_AXIS; break;
		case 'Y': axis = Y_AXIS; break;
		case 'Z': axis = Z_AXIS; break;
		case 'A': axis = A_AXIS; break;
		default: return (1); 	// error
	}
	switch (text[1]) {
		case 'S': cfg.a[axis].seek_steps_sec = (uint16_t)atoi(val); return(0);
		case 'F': cfg.a[axis].feed_steps_sec = (uint16_t)atoi(val); return(0);
		case 'D': cfg.a[axis].degree_per_step = strtod(val, &end); return(0);
		case 'M': 
			if (text[2] == 'I') {
				CFG(axis).microstep = (uint8_t)atoi(val); return(0);
			} else if (text[3] == 'R') {
				CFG(axis).mm_per_rev = strtod(val, &end); return(0);
			} else if (text[3] == 'T') {
				CFG(axis).mm_travel = strtod(val, &end); return(0);
			}
		case 'L': 
			if (text[2] == 'O') {
				CFG(axis).low_pwr_idle = (uint8_t)atoi(val); return(0);
			} else if (text[2] == 'I') {
				CFG(axis).limit_enable = (uint8_t)atoi(val); return(0);
			}
		default: return (1);	// error
	}
*/
	return (0);
}
