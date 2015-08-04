#include "senselock-common.h"
#include "senselock-exf-skeleton.h"

// Extended error code
DEFINE_AT(uint8_t, ext_error_code, 0x0400, RAM_EXT);

// Communication packet
PPKT pkt = (PPKT)pbInBuff;

/**
 * Get random data
 * @param output Output array
 * @param outputSize Size of output array
 * @return Error code
 */
uint8_t get_random(uint8_t *output, uint8_t outputSize)
{
	uint8_t error = _rand(outputSize, output);
	if (error != SES_SUCCESS)
	{
		ext_error_code = error;
		return ERR_GET_RANDOM;
	}
	return ERR_SUCCESS;
}

/**
 * Main
 */
void main(void) {

	uint8_t error = ERR_SUCCESS;
	uint8_t size = 0;

	// Reset extended error code
	if (pkt->cmd != CMD_GET_EXT_ERROR)
	{
		ext_error_code = 0;
	}

	// Execute command
	switch (pkt->cmd)
	{
	case CMD_GET_RANDOM:
		// Get random data
		{
			PREQ_RANDOM req = (PREQ_RANDOM)pkt->content;
			PRES_RANDOM res = (PRES_RANDOM)pkt->content;
			error = get_random(res->content, req->size);
			if (get_random(res->content, req->size) == SES_SUCCESS)
			{
				size = req->size;
			}
		}
		break;
	case CMD_GET_EXT_ERROR:
		// Get extended error code
		{
			PRES_EXT_ERROR res = (PRES_EXT_ERROR)pkt->content;
			res->error = ext_error_code;
			size = 1;
		}
		break;
	default:
		error = ERR_INVALID_CMD;
		break;
	}

	// Set error code and output data size
	if (error != ERR_SUCCESS)
	{
		size = 0;
	}
	pkt->cmd = error;
	pkt->size = size;

	_set_response(pkt->size + PKT_HEADER_SIZE, (uint8_t*)pkt);
	_exit();
}
