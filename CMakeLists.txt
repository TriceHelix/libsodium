cmake_minimum_required(VERSION 3.28 FATAL_ERROR)

project(
    sodium
    LANGUAGES C
)

option(SODIUM_SHARED "Build libsodium as a dynamic library" TRUE)

set(
    sources
    "crypto_aead/aegis128l/aead_aegis128l.c"
    "crypto_aead/aegis128l/aegis128l_aesni.c"
    "crypto_aead/aegis128l/aegis128l_armcrypto.c"
    "crypto_aead/aegis128l/aegis128l_soft.c"
    "crypto_aead/aegis256/aead_aegis256.c"
    "crypto_aead/aegis256/aegis256_aesni.c"
    "crypto_aead/aegis256/aegis256_armcrypto.c"
    "crypto_aead/aegis256/aegis256_soft.c"
    "crypto_aead/aes256gcm/aead_aes256gcm.c"
    "crypto_aead/aes256gcm/aesni/aead_aes256gcm_aesni.c"
    "crypto_aead/aes256gcm/armcrypto/aead_aes256gcm_armcrypto.c"
    "crypto_aead/chacha20poly1305/aead_chacha20poly1305.c"
    "crypto_aead/xchacha20poly1305/aead_xchacha20poly1305.c"
    "crypto_auth/crypto_auth.c"
    "crypto_auth/hmacsha256/auth_hmacsha256.c"
    "crypto_auth/hmacsha512/auth_hmacsha512.c"
    "crypto_auth/hmacsha512256/auth_hmacsha512256.c"
    "crypto_box/crypto_box.c"
    "crypto_box/crypto_box_easy.c"
    "crypto_box/crypto_box_seal.c"
    "crypto_box/curve25519xchacha20poly1305/box_curve25519xchacha20poly1305.c"
    "crypto_box/curve25519xchacha20poly1305/box_seal_curve25519xchacha20poly1305.c"
    "crypto_box/curve25519xsalsa20poly1305/box_curve25519xsalsa20poly1305.c"
    "crypto_core/ed25519/core_ed25519.c"
    "crypto_core/ed25519/core_ristretto255.c"
    "crypto_core/ed25519/ref10/ed25519_ref10.c"
    "crypto_core/hchacha20/core_hchacha20.c"
    "crypto_core/hsalsa20/core_hsalsa20.c"
    "crypto_core/hsalsa20/ref2/core_hsalsa20_ref2.c"
    "crypto_core/salsa/ref/core_salsa_ref.c"
    "crypto_core/softaes/softaes.c"
    "crypto_generichash/crypto_generichash.c"
    "crypto_generichash/blake2b/generichash_blake2.c"
    "crypto_generichash/blake2b/ref/blake2b-compress-avx2.c"
    "crypto_generichash/blake2b/ref/blake2b-compress-ref.c"
    "crypto_generichash/blake2b/ref/blake2b-compress-sse41.c"
    "crypto_generichash/blake2b/ref/blake2b-compress-ssse3.c"
    "crypto_generichash/blake2b/ref/blake2b-ref.c"
    "crypto_generichash/blake2b/ref/generichash_blake2b.c"
    "crypto_hash/crypto_hash.c"
    "crypto_hash/sha256/hash_sha256.c"
    "crypto_hash/sha256/cp/hash_sha256_cp.c"
    "crypto_hash/sha512/hash_sha512.c"
    "crypto_hash/sha512/cp/hash_sha512_cp.c"
    "crypto_kdf/crypto_kdf.c"
    "crypto_kdf/blake2b/kdf_blake2b.c"
    "crypto_kdf/hkdf/kdf_hkdf_sha256.c"
    "crypto_kdf/hkdf/kdf_hkdf_sha512.c"
    "crypto_kx/crypto_kx.c"
    "crypto_onetimeauth/crypto_onetimeauth.c"
    "crypto_onetimeauth/poly1305/onetimeauth_poly1305.c"
    "crypto_onetimeauth/poly1305/donna/poly1305_donna.c"
    "crypto_onetimeauth/poly1305/sse2/poly1305_sse2.c"
    "crypto_pwhash/crypto_pwhash.c"
    "crypto_pwhash/argon2/argon2.c"
    "crypto_pwhash/argon2/argon2-core.c"
    "crypto_pwhash/argon2/argon2-encoding.c"
    "crypto_pwhash/argon2/argon2-fill-block-avx2.c"
    "crypto_pwhash/argon2/argon2-fill-block-avx512f.c"
    "crypto_pwhash/argon2/argon2-fill-block-ref.c"
    "crypto_pwhash/argon2/argon2-fill-block-ssse3.c"
    "crypto_pwhash/argon2/blake2b-long.c"
    "crypto_pwhash/argon2/pwhash_argon2i.c"
    "crypto_pwhash/argon2/pwhash_argon2id.c"
    "crypto_pwhash/scryptsalsa208sha256/crypto_scrypt-common.c"
    "crypto_pwhash/scryptsalsa208sha256/pbkdf2-sha256.c"
    "crypto_pwhash/scryptsalsa208sha256/pwhash_scryptsalsa208sha256.c"
    "crypto_pwhash/scryptsalsa208sha256/scrypt_platform.c"
    "crypto_pwhash/scryptsalsa208sha256/nosse/pwhash_scryptsalsa208sha256_nosse.c"
    "crypto_pwhash/scryptsalsa208sha256/sse/pwhash_scryptsalsa208sha256_sse.c"
    "crypto_scalarmult/crypto_scalarmult.c"
    "crypto_scalarmult/curve25519/scalarmult_curve25519.c"
    "crypto_scalarmult/curve25519/ref10/x25519_ref10.c"
    "crypto_scalarmult/curve25519/sandy2x/curve25519_sandy2x.c"
    "crypto_scalarmult/curve25519/sandy2x/fe_frombytes_sandy2x.c"
    "crypto_scalarmult/curve25519/sandy2x/fe51_invert.c"
    "crypto_scalarmult/ed25519/ref10/scalarmult_ed25519_ref10.c"
    "crypto_scalarmult/ristretto255/ref10/scalarmult_ristretto255_ref10.c"
    "crypto_secretbox/crypto_secretbox.c"
    "crypto_secretbox/crypto_secretbox_easy.c"
    "crypto_secretbox/xchacha20poly1305/secretbox_xchacha20poly1305.c"
    "crypto_secretbox/xsalsa20poly1305/secretbox_xsalsa20poly1305.c"
    "crypto_secretstream/xchacha20poly1305/secretstream_xchacha20poly1305.c"
    "crypto_shorthash/crypto_shorthash.c"
    "crypto_shorthash/siphash24/shorthash_siphash24.c"
    "crypto_shorthash/siphash24/shorthash_siphashx24.c"
    "crypto_shorthash/siphash24/ref/shorthash_siphash24_ref.c"
    "crypto_shorthash/siphash24/ref/shorthash_siphashx24_ref.c"
    "crypto_sign/crypto_sign.c"
    "crypto_sign/ed25519/sign_ed25519.c"
    "crypto_sign/ed25519/ref10/keypair.c"
    "crypto_sign/ed25519/ref10/obsolete.c"
    "crypto_sign/ed25519/ref10/open.c"
    "crypto_sign/ed25519/ref10/sign.c"
    "crypto_stream/crypto_stream.c"
    "crypto_stream/chacha20/stream_chacha20.c"
    "crypto_stream/chacha20/dolbeau/chacha20_dolbeau-avx2.c"
    "crypto_stream/chacha20/dolbeau/chacha20_dolbeau-ssse3.c"
    "crypto_stream/chacha20/ref/chacha20_ref.c"
    "crypto_stream/salsa20/stream_salsa20.c"
    "crypto_stream/salsa20/ref/salsa20_ref.c"
    "crypto_stream/salsa20/xmm6/salsa20_xmm6.c"
    "crypto_stream/salsa20/xmm6int/salsa20_xmm6int-avx2.c"
    "crypto_stream/salsa20/xmm6int/salsa20_xmm6int-sse2.c"
    "crypto_stream/salsa2012/stream_salsa2012.c"
    "crypto_stream/salsa2012/ref/stream_salsa2012_ref.c"
    "crypto_stream/salsa208/stream_salsa208.c"
    "crypto_stream/salsa208/ref/stream_salsa208_ref.c"
    "crypto_stream/xchacha20/stream_xchacha20.c"
    "crypto_stream/xsalsa20/stream_xsalsa20.c"
    "crypto_verify/verify.c"
    "randombytes/randombytes.c"
    "randombytes/internal/randombytes_internal_random.c"
    "randombytes/sysrandom/randombytes_sysrandom.c"
    "sodium/codecs.c"
    "sodium/core.c"
    "sodium/runtime.c"
    "sodium/utils.c"
    "sodium/version.c"
)

set(sources_full "")
foreach(file ${sources})
    list(APPEND sources_full "${PROJECT_SOURCE_DIR}/src/libsodium/${file}")
endforeach()
set(sources ${sources_full})

if(${SODIUM_SHARED})
    set(sodium_lib_type SHARED)
else()
    set(sodium_lib_type STATIC)
endif()

add_library(
    libsodium
    ${sodium_lib_type}
    ${sources}
)

target_include_directories(
    libsodium PRIVATE
    "${PROJECT_SOURCE_DIR}/src/libsodium/include/sodium"
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
