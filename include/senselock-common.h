#ifndef SENSELOCK_COMMON_H
#define SENSELOCK_COMMON_H

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
#if defined(SDCC_mcs51)
#include <mcs51/lint.h>
#endif
#if (defined(SDCC_mcs51) || defined(__RCXA__) || defined(__C51__))
#include "senselock/ses_v3.h"
#endif



// Communication packet header size
#define PKT_HEADER_SIZE							sizeof(PKT) - MAX_PKT_CONTENT_SIZE
// Maximum communication packet content size
#define MAX_PKT_CONTENT_SIZE					240



#if (!defined(SDCC_mcs51) && !defined(__RCXA__) && !defined(__C51__))
#pragma pack(push, 1)
#endif

// Communication packet
typedef struct _pkt {
	// Command/Error code
	uint8_t cmd;
	// Actual content size
	uint8_t size;
	// Content
	uint8_t content[MAX_PKT_CONTENT_SIZE];
} PKT, *PPKT;

#if (!defined(SDCC_mcs51) && !defined(__RCXA__) && !defined(__C51__))
#pragma pack(pop)
#endif

#endif // !SENSELOCK_COMMON_H
