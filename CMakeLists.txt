cmake_minimum_required(VERSION 3.28 FATAL_ERROR)

project(
    sodium
    LANGUAGES C
)

if(NOT DEFINED BUILD_SHARED_LIBS)
    set(BUILD_SHARED_LIBS TRUE)
endif()

set(
    sources
    "src/libsodium/crypto_aead/aegis128l/aead_aegis128l.c"
    "src/libsodium/crypto_aead/aegis128l/aegis128l_aesni.c"
    "src/libsodium/crypto_aead/aegis128l/aegis128l_armcrypto.c"
    "src/libsodium/crypto_aead/aegis128l/aegis128l_soft.c"
    "src/libsodium/crypto_aead/aegis256/aead_aegis256.c"
    "src/libsodium/crypto_aead/aegis256/aegis256_aesni.c"
    "src/libsodium/crypto_aead/aegis256/aegis256_armcrypto.c"
    "src/libsodium/crypto_aead/aegis256/aegis256_soft.c"
    "src/libsodium/crypto_aead/aes256gcm/aead_aes256gcm.c"
    "src/libsodium/crypto_aead/aes256gcm/aesni/aead_aes256gcm_aesni.c"
    "src/libsodium/crypto_aead/aes256gcm/armcrypto/aead_aes256gcm_armcrypto.c"
    "src/libsodium/crypto_aead/chacha20poly1305/aead_chacha20poly1305.c"
    "src/libsodium/crypto_aead/xchacha20poly1305/aead_xchacha20poly1305.c"
    "src/libsodium/crypto_auth/crypto_auth.c"
    "src/libsodium/crypto_auth/hmacsha256/auth_hmacsha256.c"
    "src/libsodium/crypto_auth/hmacsha512/auth_hmacsha512.c"
    "src/libsodium/crypto_auth/hmacsha512256/auth_hmacsha512256.c"
    "src/libsodium/crypto_box/crypto_box.c"
    "src/libsodium/crypto_box/crypto_box_easy.c"
    "src/libsodium/crypto_box/crypto_box_seal.c"
    "src/libsodium/crypto_box/curve25519xchacha20poly1305/box_curve25519xchacha20poly1305.c"
    "src/libsodium/crypto_box/curve25519xchacha20poly1305/box_seal_curve25519xchacha20poly1305.c"
    "src/libsodium/crypto_box/curve25519xsalsa20poly1305/box_curve25519xsalsa20poly1305.c"
    "src/libsodium/crypto_core/ed25519/core_ed25519.c"
    "src/libsodium/crypto_core/ed25519/core_ristretto255.c"
    "src/libsodium/crypto_core/ed25519/ref10/ed25519_ref10.c"
    "src/libsodium/crypto_core/hchacha20/core_hchacha20.c"
    "src/libsodium/crypto_core/hsalsa20/core_hsalsa20.c"
    "src/libsodium/crypto_core/hsalsa20/ref2/core_hsalsa20_ref2.c"
    "src/libsodium/crypto_core/salsa/ref/core_salsa_ref.c"
    "src/libsodium/crypto_core/softaes/softaes.c"
    "src/libsodium/crypto_generichash/crypto_generichash.c"
    "src/libsodium/crypto_generichash/blake2b/generichash_blake2.c"
    "src/libsodium/crypto_generichash/blake2b/ref/blake2b-compress-avx2.c"
    "src/libsodium/crypto_generichash/blake2b/ref/blake2b-compress-ref.c"
    "src/libsodium/crypto_generichash/blake2b/ref/blake2b-compress-sse41.c"
    "src/libsodium/crypto_generichash/blake2b/ref/blake2b-compress-ssse3.c"
    "src/libsodium/crypto_generichash/blake2b/ref/blake2b-ref.c"
    "src/libsodium/crypto_generichash/blake2b/ref/generichash_blake2b.c"
    "src/libsodium/crypto_hash/crypto_hash.c"
    "src/libsodium/crypto_hash/sha256/hash_sha256.c"
    "src/libsodium/crypto_hash/sha256/cp/hash_sha256_cp.c"
    "src/libsodium/crypto_hash/sha512/hash_sha512.c"
    "src/libsodium/crypto_hash/sha512/cp/hash_sha512_cp.c"
    "src/libsodium/crypto_kdf/crypto_kdf.c"
    "src/libsodium/crypto_kdf/blake2b/kdf_blake2b.c"
    "src/libsodium/crypto_kdf/hkdf/kdf_hkdf_sha256.c"
    "src/libsodium/crypto_kdf/hkdf/kdf_hkdf_sha512.c"
    "src/libsodium/crypto_kx/crypto_kx.c"
    "src/libsodium/crypto_onetimeauth/crypto_onetimeauth.c"
    "src/libsodium/crypto_onetimeauth/poly1305/onetimeauth_poly1305.c"
    "src/libsodium/crypto_onetimeauth/poly1305/donna/poly1305_donna.c"
    "src/libsodium/crypto_onetimeauth/poly1305/sse2/poly1305_sse2.c"
    "src/libsodium/crypto_pwhash/crypto_pwhash.c"
    "src/libsodium/crypto_pwhash/argon2/argon2.c"
    "src/libsodium/crypto_pwhash/argon2/argon2-core.c"
    "src/libsodium/crypto_pwhash/argon2/argon2-encoding.c"
    "src/libsodium/crypto_pwhash/argon2/argon2-fill-block-avx2.c"
    "src/libsodium/crypto_pwhash/argon2/argon2-fill-block-avx512f.c"
    "src/libsodium/crypto_pwhash/argon2/argon2-fill-block-ref.c"
    "src/libsodium/crypto_pwhash/argon2/argon2-fill-block-ssse3.c"
    "src/libsodium/crypto_pwhash/argon2/blake2b-long.c"
    "src/libsodium/crypto_pwhash/argon2/pwhash_argon2i.c"
    "src/libsodium/crypto_pwhash/argon2/pwhash_argon2id.c"
    "src/libsodium/crypto_pwhash/scryptsalsa208sha256/crypto_scrypt-common.c"
    "src/libsodium/crypto_pwhash/scryptsalsa208sha256/pbkdf2-sha256.c"
    "src/libsodium/crypto_pwhash/scryptsalsa208sha256/pwhash_scryptsalsa208sha256.c"
    "src/libsodium/crypto_pwhash/scryptsalsa208sha256/scrypt_platform.c"
    "src/libsodium/crypto_pwhash/scryptsalsa208sha256/nosse/pwhash_scryptsalsa208sha256_nosse.c"
    "src/libsodium/crypto_pwhash/scryptsalsa208sha256/sse/pwhash_scryptsalsa208sha256_sse.c"
    "src/libsodium/crypto_scalarmult/crypto_scalarmult.c"
    "src/libsodium/crypto_scalarmult/curve25519/scalarmult_curve25519.c"
    "src/libsodium/crypto_scalarmult/curve25519/ref10/x25519_ref10.c"
    "src/libsodium/crypto_scalarmult/curve25519/sandy2x/curve25519_sandy2x.c"
    "src/libsodium/crypto_scalarmult/curve25519/sandy2x/fe_frombytes_sandy2x.c"
    "src/libsodium/crypto_scalarmult/curve25519/sandy2x/fe51_invert.c"
    "src/libsodium/crypto_scalarmult/ed25519/ref10/scalarmult_ed25519_ref10.c"
    "src/libsodium/crypto_scalarmult/ristretto255/ref10/scalarmult_ristretto255_ref10.c"
    "src/libsodium/crypto_secretbox/crypto_secretbox.c"
    "src/libsodium/crypto_secretbox/crypto_secretbox_easy.c"
    "src/libsodium/crypto_secretbox/xchacha20poly1305/secretbox_xchacha20poly1305.c"
    "src/libsodium/crypto_secretbox/xsalsa20poly1305/secretbox_xsalsa20poly1305.c"
    "src/libsodium/crypto_secretstream/xchacha20poly1305/secretstream_xchacha20poly1305.c"
    "src/libsodium/crypto_shorthash/crypto_shorthash.c"
    "src/libsodium/crypto_shorthash/siphash24/shorthash_siphash24.c"
    "src/libsodium/crypto_shorthash/siphash24/shorthash_siphashx24.c"
    "src/libsodium/crypto_shorthash/siphash24/ref/shorthash_siphash24_ref.c"
    "src/libsodium/crypto_shorthash/siphash24/ref/shorthash_siphashx24_ref.c"
    "src/libsodium/crypto_sign/crypto_sign.c"
    "src/libsodium/crypto_sign/ed25519/sign_ed25519.c"
    "src/libsodium/crypto_sign/ed25519/ref10/keypair.c"
    "src/libsodium/crypto_sign/ed25519/ref10/obsolete.c"
    "src/libsodium/crypto_sign/ed25519/ref10/open.c"
    "src/libsodium/crypto_sign/ed25519/ref10/sign.c"
    "src/libsodium/crypto_stream/crypto_stream.c"
    "src/libsodium/crypto_stream/chacha20/stream_chacha20.c"
    "src/libsodium/crypto_stream/chacha20/dolbeau/chacha20_dolbeau-avx2.c"
    "src/libsodium/crypto_stream/chacha20/dolbeau/chacha20_dolbeau-ssse3.c"
    "src/libsodium/crypto_stream/chacha20/ref/chacha20_ref.c"
    "src/libsodium/crypto_stream/salsa20/stream_salsa20.c"
    "src/libsodium/crypto_stream/salsa20/ref/salsa20_ref.c"
    "src/libsodium/crypto_stream/salsa20/xmm6/salsa20_xmm6.c"
    "src/libsodium/crypto_stream/salsa20/xmm6int/salsa20_xmm6int-avx2.c"
    "src/libsodium/crypto_stream/salsa20/xmm6int/salsa20_xmm6int-sse2.c"
    "src/libsodium/crypto_stream/salsa2012/stream_salsa2012.c"
    "src/libsodium/crypto_stream/salsa2012/ref/stream_salsa2012_ref.c"
    "src/libsodium/crypto_stream/salsa208/stream_salsa208.c"
    "src/libsodium/crypto_stream/salsa208/ref/stream_salsa208_ref.c"
    "src/libsodium/crypto_stream/xchacha20/stream_xchacha20.c"
    "src/libsodium/crypto_stream/xsalsa20/stream_xsalsa20.c"
    "src/libsodium/crypto_verify/verify.c"
    "src/libsodium/randombytes/randombytes.c"
    "src/libsodium/randombytes/internal/randombytes_internal_random.c"
    "src/libsodium/randombytes/sysrandom/randombytes_sysrandom.c"
    "src/libsodium/sodium/codecs.c"
    "src/libsodium/sodium/core.c"
    "src/libsodium/sodium/runtime.c"
    "src/libsodium/sodium/utils.c"
    "src/libsodium/sodium/version.c"
)

add_library(
    libsodium
    ${sources}
)

target_include_directories(
    libsodium PRIVATE
    "src/libsodium/include/sodium"
)

set_target_properties(
    libsodium PROPERTIES
    C_STANDARD 11
    C_STANDARD_REQUIRED TRUE
)

target_compile_definitions(
    libsodium PRIVATE
    DEV_MODE=1
    CONFIGURED=1
    HAVE_ATOMIC_OPS=1
    HAVE_C11_MEMORY_FENCES=1
    HAVE_STDINT_H=1
)

if("${CMAKE_C_BYTE_ORDER}" STREQUAL "BIG_ENDIAN")
    target_compile_definitions(
        libsodium PRIVATE
        NATIVE_BIG_ENDIAN=1
    )
elseif("${CMAKE_C_BYTE_ORDER}" STREQUAL "LITTLE_ENDIAN")
    target_compile_definitions(
        libsodium PRIVATE
        NATIVE_LITTLE_ENDIAN=1
    )
else()
    message(FATAL_ERROR "Unknown system endianness.")
endif()

if(${WIN32})
    target_compile_definitions(
        libsodium PRIVATE
        SODIUM_DLL_EXPORT=1
        HAVE_RAISE=1
    )
    if(NOT ${BUILD_SHARED_LIBS})
        target_compile_definitions(
            libsodium PUBLIC
            SODIUM_STATIC=1
        )
    endif()
elseif(${LINUX})
    target_compile_definitions(
        libsodium PRIVATE
        ASM_HIDE_SYMBOL=.hidden
        TLS=_Thread_local
        HAVE_CATCHABLE_ABRT=1
        HAVE_CATCHABLE_SEGV=1
        HAVE_CLOCK_GETTIME=1
        HAVE_GETPID=1
        HAVE_MADVISE=1
        HAVE_MLOCK=1
        HAVE_MMAP=1
        HAVE_MPROTECT=1
        HAVE_NANOSLEEP=1
        HAVE_POSIX_MEMALIGN=1
        HAVE_PTHREAD_PRIO_INHERIT=1
        HAVE_PTHREAD=1
        HAVE_RAISE=1
        HAVE_SYSCONF=1
        HAVE_SYS_AUXV_H=1
        HAVE_SYS_MMAN_H=1
        HAVE_SYS_PARAM_H=1
        HAVE_SYS_RANDOM_H=1
        HAVE_WEAK_SYMBOLS=1
    )
elseif(${APPLE})
    target_compile_definitions(
        libsodium PRIVATE
        ASM_HIDE_SYMBOL=.private_extern
        TLS=_Thread_local
        HAVE_ARC4RANDOM=1
        HAVE_ARC4RANDOM_BUF=1
        HAVE_CATCHABLE_ABRT=1
        HAVE_CATCHABLE_SEGV=1
        HAVE_CLOCK_GETTIME=1
        HAVE_GETENTROPY=1
        HAVE_GETPID=1
        HAVE_MADVISE=1
        HAVE_MEMSET_S=1
        HAVE_MLOCK=1
        HAVE_MMAP=1
        HAVE_MPROTECT=1
        HAVE_NANOSLEEP=1
        HAVE_POSIX_MEMALIGN=1
        HAVE_PTHREAD=1
        HAVE_PTHREAD_PRIO_INHERIT=1
        HAVE_RAISE=1
        HAVE_SYSCONF=1
        HAVE_SYS_MMAN_H=1
        HAVE_SYS_PARAM_H=1
        HAVE_SYS_RANDOM_H=1
        HAVE_WEAK_SYMBOLS=1
    )
endif()

if(${CMAKE_SYSTEM_PROCESSOR} STREQUAL "x86_64")
    if(NOT ${WIN32})
        target_compile_definitions(
            libsodium PRIVATE
            HAVE_AMD64_ASM=1
            HAVE_AVX_ASM=1
        )
    endif()

    target_compile_definitions(
        libsodium PRIVATE
        HAVE_CPUID=1
        HAVE_MMINTRIN_H=1
        HAVE_EMMINTRIN_H=1
        HAVE_PMMINTRIN_H=1
        HAVE_TMMINTRIN_H=1
        HAVE_SMMINTRIN_H=1
        HAVE_AVXINTRIN_H=1
        HAVE_AVX2INTRIN_H=1
        HAVE_AVX512FINTRIN_H=1
        HAVE_WMMINTRIN_H=1
        HAVE_RDRAND=1
    )
elseif(${CMAKE_SYSTEM_PROCESSOR} STREQUAL "aarch64")
    target_compile_definitions(
        libsodium PRIVATE
        HAVE_ARMCRYPTO=1
    )
endif()

if(${MSVC})
    target_compile_options(
        libsodium PRIVATE
        /experimental:c11atomics
    )
else()
    target_compile_options(
        libsodium PRIVATE
        -fvisibility=hidden
        -fno-strict-aliasing
        -fno-strict-overflow
        -fwrapv
        -flax-vector-conversions
        -Werror=vla
    )
endif()
