/*
 * Copyright (C) 2011-2021 Intel Corporation. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in
 *     the documentation and/or other materials provided with the
 *     distribution.
 *   * Neither the name of Intel Corporation nor the names of its
 *     contributors may be used to endorse or promote products derived
 *     from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

#ifndef _SGX_TTLS_H_
#define _SGX_TTLS_H_

#include <stddef.h>
#include <stdint.h>
#include "sgx_error.h"
#include "sgx_defs.h"
#include "sgx_qve_header.h"
#include "sgx_ql_quote.h"

#ifdef  __cplusplus
extern "C" {
#endif

/*
 * Copyright (C) 2011-2021 Intel Corporation. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in
 *     the documentation and/or other materials provided with the
 *     distribution.
 *   * Neither the name of Intel Corporation nor the names of its
 *     contributors may be used to endorse or promote products derived
 *     from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */
quote3_error_t SGXAPI tee_get_certificate_with_evidence(
    const unsigned char *p_subject_name,
    const uint8_t *p_prv_key,
    size_t private_key_size,
    const uint8_t *p_pub_key,
    size_t public_key_size,
    uint8_t **pp_output_cert,
    size_t *p_output_cert_size);

/**
 * tee_free_certificate
 *
 * Frees the output certificate buffer.
 * This function is only available in the enclave.
 *
 * @param[in] p_certificate A pointer to output certificate buffer after called API `tee_get_certificate_with_evidence`.
 * @retval SGX_QL_SUCCESS The function succeeded.
 * @retval other appropriate error code.
 */
quote3_error_t SGXAPI tee_free_certificate(uint8_t* p_certificate);


/**
 * tee_verify_certificate_with_evidence
 *
 * This function performs Intel(R) TEE quote and X.509 certificate verification.
 * The validation includes extracting quote extension from the certificate before 
 * validating the quote
 * 
 * @param[in] p_cert_in_der A pointer to buffer holding certificate contents in DER format
 * @param[in] cert_in_der_len The size of certificate buffer above
 * @param[in] expiration_check_date The date that verifier will use to determine if any of the verification collateral have expired
 * @param[out] p_qv_result SGX quote verification result
 * @param[out] pp_supplemental_data A pointer to SGX quote verification supplemental data pointer
 * @param[out] p_supplemental_data_size The size of supplemental data above
 * @retval SGX_SUCCESS on a successful validation
 *      Please also refer to output parameters 'p_qv_result' for some warnings, 
 *      You can refer to 'p_qv_result' and supplemental data to define your own quote verification policy
 * @retval SGX_ERROR_INVALID_PARAMETER At least one parameter is invalid
 * @retval SGX_ERROR_UNEXPECTED general failure
 */
quote3_error_t SGXAPI tee_verify_certificate_with_evidence(
    const uint8_t *p_cert_in_der,
    size_t cert_in_der_len,
    const time_t expiration_check_date,
    sgx_ql_qv_result_t *p_qv_result,
    uint8_t **pp_supplemental_data,
    uint32_t *p_supplemental_data_size);

/**
 * tee_free_supplemental_data_in_enclave
 *
 * Frees the quote verification supplemental data buffer.
 * This function is only available in the enclave.
 *
 * @param[in] p_supplemental_data A pointer to the quote verification supplemental data, which is 
 *  output of API `tee_verify_certificate_with_evidence`
 * @retval SGX_QL_SUCCESS The function succeeded.
 * @retval other appropriate error code.
 */
quote3_error_t SGXAPI tee_free_supplemental_data(uint8_t* p_supplemental_data);


#ifdef  __cplusplus
}
#endif

#endif
