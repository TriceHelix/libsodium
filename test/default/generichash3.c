
#define TEST_NAME "generichash3"
#include "cmptest.h"

int main(void)
{
#define MAXLEN 64
    crypto_generichash_blake2b_state st;
    unsigned char salt[crypto_generichash_blake2b_SALTBYTES]
        = { '5', 'b', '6', 'b', '4', '1', 'e', 'd',
            '9', 'b', '3', '4', '3', 'f', 'e', '0' };
    unsigned char personal[crypto_generichash_blake2b_PERSONALBYTES]
        = { '5', '1', '2', '6', 'f', 'b', '2', 'a',
            '3', '7', '4', '0', '0', 'd', '2', 'a' };
    unsigned char in[MAXLEN], out[crypto_generichash_blake2b_BYTES_MAX],
        k[crypto_generichash_blake2b_KEYBYTES_MAX];
    size_t h, i, j;

    for (h = 0; h < crypto_generichash_blake2b_KEYBYTES_MAX; ++h)
        k[h] = h;

    for (i = 0; i < MAXLEN; ++i) {
        in[i] = i;
        crypto_generichash_blake2b_init_salt_personal(
            &st, k, 1 + i % crypto_generichash_blake2b_KEYBYTES_MAX,
            1 + i % crypto_generichash_blake2b_BYTES_MAX, salt, personal);
        crypto_generichash_blake2b_update(&st, in, i);
        crypto_generichash_blake2b_final(
            &st, out, 1 + i % crypto_generichash_blake2b_BYTES_MAX);
        for (j = 0; j < 1 + i % crypto_generichash_blake2b_BYTES_MAX; ++j) {
            printf("%02x", (unsigned int)out[j]);
        }
        printf("\n");
    }

    memset(out, 0, sizeof out);
    crypto_generichash_blake2b_init_salt_personal(
        &st, k, 0U, crypto_generichash_blake2b_BYTES_MAX, salt, personal);
    crypto_generichash_blake2b_update(&st, in, MAXLEN);
    crypto_generichash_blake2b_final(&st, out,
                                     crypto_generichash_blake2b_BYTES_MAX);
    for (j = 0; j < crypto_generichash_blake2b_BYTES_MAX; ++j) {
        printf("%02x", (unsigned int)out[j]);
    }
    printf("\n");

    memset(out, 0, sizeof out);
    crypto_generichash_blake2b_init_salt_personal(
        &st, NULL, 1U, crypto_generichash_blake2b_BYTES_MAX, salt, personal);
    crypto_generichash_blake2b_update(&st, in, MAXLEN);
    crypto_generichash_blake2b_final(&st, out,
                                     crypto_generichash_blake2b_BYTES_MAX);
    for (j = 0; j < crypto_generichash_blake2b_BYTES_MAX; ++j) {
        printf("%02x", (unsigned int)out[j]);
    }
    printf("\n");

    memset(out, 0, sizeof out);
    crypto_generichash_blake2b_init_salt_personal(
        &st, k, crypto_generichash_blake2b_KEYBYTES_MAX,
    crypto_generichash_blake2b_BYTES_MAX, NULL, personal);
    crypto_generichash_blake2b_update(&st, in, MAXLEN);
    crypto_generichash_blake2b_final(&st, out,
                                     crypto_generichash_blake2b_BYTES_MAX);
    for (j = 0; j < crypto_generichash_blake2b_BYTES_MAX; ++j) {
        printf("%02x", (unsigned int)out[j]);
    }
    printf("\n");

    memset(out, 0, sizeof out);
    crypto_generichash_blake2b_init_salt_personal(
        &st, k, crypto_generichash_blake2b_KEYBYTES_MAX,
        crypto_generichash_blake2b_BYTES_MAX, salt, NULL);
    crypto_generichash_blake2b_update(&st, in, MAXLEN);
    assert(crypto_generichash_blake2b_final(
        &st, out, crypto_generichash_blake2b_BYTES_MAX + 1U) == -1);
    crypto_generichash_blake2b_final(
        &st, out, crypto_generichash_blake2b_BYTES_MAX);
    for (j = 0; j < crypto_generichash_blake2b_BYTES_MAX; ++j) {
        printf("%02x", (unsigned int)out[j]);
    }
    printf("\n");

    memset(out, 0, sizeof out);
    crypto_generichash_blake2b_salt_personal(
        out, crypto_generichash_blake2b_BYTES_MAX, in, MAXLEN,
        k, 0U, salt, personal);
    for (j = 0; j < crypto_generichash_blake2b_BYTES_MAX; ++j) {
        printf("%02x", (unsigned int)out[j]);
    }
    printf("\n");

    memset(out, 0, sizeof out);
    crypto_generichash_blake2b_salt_personal(
        out, crypto_generichash_blake2b_BYTES_MAX, in, MAXLEN,
        NULL, crypto_generichash_blake2b_KEYBYTES_MAX, salt, personal);
    for (j = 0; j < crypto_generichash_blake2b_BYTES_MAX; ++j) {
        printf("%02x", (unsigned int)out[j]);
    }
    printf("\n");

    memset(out, 0, sizeof out);
    crypto_generichash_blake2b_salt_personal(
        out, crypto_generichash_blake2b_BYTES_MAX, in, MAXLEN,
        k, crypto_generichash_blake2b_KEYBYTES_MAX, salt, personal);
    for (j = 0; j < crypto_generichash_blake2b_BYTES_MAX; ++j) {
        printf("%02x", (unsigned int)out[j]);
    }
    printf("\n");

    memset(out, 0, sizeof out);
    crypto_generichash_blake2b_salt_personal(
        out, crypto_generichash_blake2b_BYTES_MAX, in, MAXLEN,
        k, crypto_generichash_blake2b_KEYBYTES_MAX, NULL, personal);
    for (j = 0; j < crypto_generichash_blake2b_BYTES_MAX; ++j) {
        printf("%02x", (unsigned int)out[j]);
    }
    printf("\n");

    memset(out, 0, sizeof out);
    crypto_generichash_blake2b_salt_personal(
        out, crypto_generichash_blake2b_BYTES_MAX, in, MAXLEN,
        k, crypto_generichash_blake2b_KEYBYTES_MAX, salt, NULL);
    for (j = 0; j < crypto_generichash_blake2b_BYTES_MAX; ++j) {
        printf("%02x", (unsigned int)out[j]);
    }
    printf("\n");

    assert(crypto_generichash_blake2b_init_salt_personal(&st, k, sizeof k, 0U,
                                                         salt, personal) == -1);
    assert(crypto_generichash_blake2b_init_salt_personal(&st, k, sizeof k,
                                                         crypto_generichash_BYTES_MAX + 1U,
                                                         salt, personal) == -1);
    assert(crypto_generichash_blake2b_init_salt_personal(&st, k,
                                                         crypto_generichash_KEYBYTES_MAX + 1U,
                                                         sizeof out, salt, personal) == -1);

    assert(crypto_generichash_blake2b_salt_personal(out, 0U, in, MAXLEN,
                                                    k, sizeof k,
                                                    salt, personal) == -1);
    assert(crypto_generichash_blake2b_salt_personal(out, crypto_generichash_BYTES_MAX + 1U,
                                                    in, MAXLEN, k, sizeof k,
                                                    salt, personal) == -1);
    assert(crypto_generichash_blake2b_salt_personal(out, sizeof out, in, MAXLEN,
                                                    k, crypto_generichash_KEYBYTES_MAX + 1U,
                                                    salt, personal) == -1);
    return 0;
}
