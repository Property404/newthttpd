#include <stdio.h>
#include <string.h>
#include "newtcrypto.h"
#include <openssl/evp.h>
#include <openssl/crypto.h>
#include <openssl/sha.h>

#define PBKDF2_ROUNDS 100
#define KEY_LENGTH 32
/* Fill a char* with random bits */
static void generate_salt(char* salt, int size){
	FILE *urandom = fopen("/dev/urandom", "r");
	int j;

	if(urandom==NULL){
		fprintf(stderr, "abort: could not access /dev/urandom");
		exit(1);
	}
	for(j=0;j<size;j++)salt[j]=fgetc(urandom);

	fclose(urandom);
}

/* Convert char* to hexidecimal */
static void to_hex(char* hex, const char* text, int size){
	int j;
	for(j=0;j<size;j++){
		hex[2*j] = "0123456789abcdef"[text[j]/16];
		hex[2*j+1] = "0123456789abcdef"[text[j]%16];
	}
}

/* Convert hex digit to int*/
static int htoi(char digit){
	if (digit>='0' && digit<='9'){
		return digit-'0';
	}
	else if(digit >='a' && digit <='f'){
		return 10 + (digit-'a');
	}
	else{
		fprintf(stderr, "Fuck, man, '%c' ain't real hexidecimal\n", digit);
		exit(1);
	}
}
/* convert const char* to bytes */
static void to_bytes(char* bytes, const char* hex, int size){
	int j;
	for(j=0;j<size;j++){
		bytes[j] = htoi(hex[2*j])*16+htoi(hex[2*j+1]);
	}
}

/* Non-statics */
int generate_secure_hash(unsigned char* out, const char* password){
	char salt[NEWT_SALT_BITS/8];
	unsigned char* raw_hash[KEY_LENGTH];
	int ret;

	generate_salt(salt, NEWT_SALT_BITS/8);


	/* Create raw hash */
	ret = PKCS5_PBKDF2_HMAC(password, strlen(password), (unsigned char*)salt, NEWT_SALT_BITS/8,PBKDF2_ROUNDS, EVP_sha256(), KEY_LENGTH, raw_hash); 

	/* Check for errors */		
	if(!ret){
		fprintf(stderr, "error generating hash\n");
		return 0;	
	}

	/* Convert to SALTHEX$HASHHEX form */
	for (i=0;i<NEWT_SALT_BITS/8;i++){
		
}


int main(){
unsigned char flex[22];
flex[21] = 0;
generate_secure_hash(flex, "poopy butthole");
printf("Test: %s(%d)\n", flex, strlen(flex));
return 0;
}

