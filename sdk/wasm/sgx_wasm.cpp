#include "sgx_wasm.h"

#define SE_PAGE_SIZE 0x1000

/* SGX Begin */
const uint8_t __attribute__((section(SGX_WASM_SEC_NAME))) sgx_wasm_sec_buf[SGX_WASM_SEC_SIZE] __attribute__((aligned (SE_PAGE_SIZE))) = {};
const uint8_t __attribute__((section(SGX_WASM_VM_MR_SEC_NAME))) sgx_wasm_ex_sec_buf[SGX_WASM_VM_MR_SEC_SIZE] __attribute__((aligned (SE_PAGE_SIZE))) = {};

uint8_t *sgx_get_wasm_sec_addr()
{
    return reinterpret_cast<uint8_t*>(reinterpret_cast<uint64_t>(sgx_wasm_sec_buf));
}

uint8_t *sgx_get_wasm_ex_sec_addr()
{
    return reinterpret_cast<uint8_t*>(reinterpret_cast<uint64_t>(sgx_wasm_ex_sec_buf));
}

uint32_t sgx_get_wasm_size()
{
    return *reinterpret_cast<uint32_t*>(reinterpret_cast<uint64_t>(sgx_wasm_sec_buf) + SGX_WASM_SEC_SIZE - sizeof(uint32_t));
}

uint8_t *sgx_get_wasm()
{
    return sgx_get_wasm_sec_addr() + SGX_WASM_SEC_SIZE - sgx_get_wasm_size() - sizeof(uint32_t);
}
