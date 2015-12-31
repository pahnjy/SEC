
/***********************************************
	 Copyright (C) 2015, UNETsystem
 
     e_cfb_lea.c  LEA, CFB mode

	 Creadted by DEV3

************************************************/ 

#ifndef NO_LEA

#ifndef NO_LEA_CFB

#include "../include/scrt.h"
#include "../include/lea.h"
#include <string.h>
#include <math.h>

static int S_lea_cfb128_128_init_key(SCRT_CIPHER_CTX *ctx, U8 *key, U8 *iv, int isenc);

static void S_lea_cfb128_cipher(SCRT_CIPHER_CTX *ctx, U8 *out, U8 *in, unsigned int inl);

/* LEA 128bit CFB128 모드 알고리즘의 특성에 알맞는 값들을 structure 구조에 저장 */
static SCRT_CIPHER d_cfb128_128_lea=
{
	NID_lea_128_cfb128, /* nid */
	1,  /* block length */
	16, /* key length */
	16,  /* iv length */
	S_lea_cfb128_128_init_key, /* iv, key setting 함수 */
	S_lea_cfb128_cipher,   /* 암복호화 함수 */
	NULL,				   /* 마무리 함수 */
	sizeof(SCRT_CIPHER_CTX)-sizeof((((SCRT_CIPHER_CTX *)NULL)->c))+ /* structure size */
		sizeof((((SCRT_CIPHER_CTX *)NULL)->c.lea_ks))
};

/* structure를 return 하는 함수 */
/*	
	Name : SCRT_lea_128_cfb128
	Description: LEA 128 bit CFB128 모드 암호알고리즘을 사용하기 위한 정보를 담은 구조체를 반환한다
	Parameters
	Return Value : d_cfb128_128_lea 구조체를 반환한다
	Note :
*/
SCRT_CIPHER *SCRT_lea_128_cfb128(void)
{
	return(&d_cfb128_128_lea);
}

/*	
	Name : S_lea_cfb128_128_init_key
	Description: 암호키 및 초기벡터를 이용하여 LEA 128bit CFB128 모드 암호알고리즘에 필요한 키 구조체 및 알고리즘 정보를 설정한다
	Parameters
	[out] ctx : LEA 암/복호화를 위한 LEA_KEY 키 구조체 및 정보를 담은 구조체
	[in] key : 암호키 데이터
	[in] iv : 초기벡터
	[in] isenc : 암/복호화 여부 FLAG ( 1 : 암호화 , 그외 : 복호화 )
	Return Value : 성공하였을 경우 1, 그외의 경우 0 값을 반환한다
	Note :
*/
static int S_lea_cfb128_128_init_key(SCRT_CIPHER_CTX *ctx, U8 *key, U8 *iv, int isenc)
{
	int ret ;

	ctx->num=0;

	if (iv != NULL)
		memcpy(&(ctx->oiv[0]),iv,16);

	memcpy(&(ctx->iv[0]),&(ctx->oiv[0]),16);  /* iv setting */

	if (isenc == 1)
		ret = S_LEA_Keyschedule(&(ctx->c.lea_ks), key, 16);
	else
		ret = S_LEA_Keyschedule(&(ctx->c.lea_ks), key, 16);
	
	if (ret < 0) return 0;
	
	return 1;
}

/*	
	Name : S_lea_cfb128_cipher
	Description: 암호키 및 초기벡터를 이용하여 LEA CFB128 모드 암호알고리즘을 이용하여 입력/암호화된 데이터를 암/복호화 한다
	Parameters
	[in] ctx : LEA 암/복호화를 위한 LEA_KEY 키 구조체 및 정보를 담은 구조체
	[out] out : 암/복호화 된 데이터
	[in] in : 암/복호화 할 데이터
	[in] inl : 암/복호화 할 데이터 길이
	Return Value : 
	Note :
*/
static void S_lea_cfb128_cipher(SCRT_CIPHER_CTX *ctx, U8 *out, U8 *in, unsigned int inl)
{
	if (ctx->encrypt) 
		S_LEA_CFB128_Encrypt(&(ctx->c.lea_ks), (U8 *)&(ctx->iv), in, inl, out);
	else
		S_LEA_CFB128_Decrypt(&(ctx->c.lea_ks), (U8 *)&(ctx->iv), in, inl, out);
}

#endif

#endif
