/**
 * The purpose of this module is to define shared
 * cryptographic wrappers for OpenSSL and urandom
 * as a replacement for how thttpd handled passwords
 * which was inexcusably insecure
 *
 * (c) 2016 Dagan Martinez, some rights reserved
 * You are free to modify, distribute, sell, 
 * masturbate, etc, as long as this copyright
 * notice is not removed.
 *
 * TODO: add a real license
 *
 */
#ifndef NEWTHTTPD_NEWTCRYPTO_H_
#define NEWTHTTPD_NEWTCRYPTO_H_
/* Measured in bits*/
#define NEWT_SALT_BITS 64
/* Measured in bytes - total hash + salt + '$'*/
#define NEWT_HASH_SIZE 81


/* Create has with PBKDF2/sha256 */
void generate_secure_hash(unsigned char *out, const char* password);

/* Compare hashes made with generate_secure_hash */
int compare_hashes(char* old_hash, char* new_password);


#endif
