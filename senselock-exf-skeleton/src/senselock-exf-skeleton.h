#ifndef SENSELOCK_EXF_SKELETON_H
#define SENSELOCK_EXF_SKELETON_H

/**
 * Exported functions
 */
// Get random data
#define CMD_GET_RANDOM						1
// Get extended error code
#define CMD_GET_EXT_ERROR					99

/**
 * Error codes
 */
// No errors
#define ERR_SUCCESS							0
// Invalid command
#define ERR_INVALID_CMD						1
// Unable to get random data
#define ERR_GET_RANDOM						2


#if (!defined(SDCC_mcs51) && !defined(__RCXA__) && !defined(__C51__))
#pragma pack(push, 1)
#endif

// Random data request
typedef struct _req_random {
	// Number of random bytes to generate
	uint8_t size;
} REQ_RANDOM, *PREQ_RANDOM;

// Random data response
typedef struct _res_random {
	// Random data
	uint8_t content[MAX_PKT_CONTENT_SIZE];
} RES_RANDOM, *PRES_RANDOM;

// Extended error code response
typedef struct _res_ext_error {
	// Extended error code
	uint8_t error;
} RES_EXT_ERROR, *PRES_EXT_ERROR;

#if (!defined(SDCC_mcs51) && !defined(__RCXA__) && !defined(__C51__))
#pragma pack(pop)
#endif

#endif // !SENSELOCK_EXF_SKELETON_H
