/* It had generated by DirectStruct v1.6.3 */
#ifndef _H_BankTransaction_
#define _H_BankTransaction_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#if ( defined __unix ) || ( defined __linux__ )
#ifndef _WINDLL_FUNC
#define _WINDLL_FUNC
#endif
#elif ( defined _WIN32 )
#ifndef _WINDLL_FUNC
#define _WINDLL_FUNC		_declspec(dllexport)
#endif
#endif

#ifndef DSCTRUE
#define DSCTRUE	(unsigned char)'t'
#endif
#ifndef DSCFALSE
#define DSCFALSE	(unsigned char)'f'
#endif
#ifndef DSCNULL
#define DSCNULL	(unsigned char)127
#endif

#if ( defined __unix ) | ( defined __linux__ )
#include <arpa/inet.h>
#define SNPRINTF		snprintf
#elif ( defined _WIN32 )
#define SNPRINTF		_snprintf
#include "winsock.h"
#endif

#if ( defined __unix ) | ( defined __linux__ )
#ifndef longlong
#define longlong	long long
#define ulonglong	unsigned long long
#define LL(_ll_)	_ll_##LL
#define ULL(_ll_)	_ll_##ULL
#define LONGLONG_FORMAT_SPEC	"%lld"
#define ATOLL	atoll
#endif
#if ( defined _AIX )
#define __BIG_ENDIAN	BIG_ENDIAN
#define __LITTLE_ENDIAN	LITTLE_ENDIAN
#define __BYTE_ORDER	BYTE_ORDER
#endif
#elif ( defined _WIN32 )
#ifndef longlong
#define longlong	__int64
#define ulonglong	unsigned __int64
#define LL(_ll_)	_ll_
#define ULL(_ll_)	_ll_
#define LONGLONG_FORMAT_SPEC	"%I64"
#define ATOLL	_atoi64
#define __BIG_ENDIAN	4321
#define __LITTLE_ENDIAN	1234
#define __BYTE_ORDER	__LITTLE_ENDIAN
#endif
#endif

#ifndef NATOC
#define NATOC(_base_,_len_,_result_)	{char buf[3+1];memset(buf,0x00,sizeof(buf));strncpy(buf,_base_,3);_result_=(char)atoi(buf);}
#endif
#ifndef NATOS
#define NATOS(_base_,_len_,_result_)	{char buf[5+1];memset(buf,0x00,sizeof(buf));strncpy(buf,_base_,5);_result_=(short)atol(buf);}
#endif
#ifndef NATOI
#define NATOI(_base_,_len_,_result_)	{char buf[10+1];memset(buf,0x00,sizeof(buf));strncpy(buf,_base_,10);_result_=atoi(buf);}
#endif
#ifndef NATOLL
#define NATOLL(_base_,_len_,_result_)	{char buf[20+1];memset(buf,0x00,sizeof(buf));strncpy(buf,_base_,20);_result_=ATOLL(buf);}
#endif
#ifndef NATOF
#define NATOF(_base_,_len_,_result_)	{char buf[20+1];memset(buf,0x00,sizeof(buf));strncpy(buf,_base_,20);_result_=(float)atof(buf);}
#endif
#ifndef NATOLF
#define NATOLF(_base_,_len_,_result_)	{char buf[60+1];memset(buf,0x00,sizeof(buf));strncpy(buf,_base_,60);_result_=atof(buf);}
#endif
#ifndef NATOB
#define NATOB(_base_,_len_,_result_)	{if(memcmp(_base_,"true",4)==0)_result_=DSCTRUE;else _result_=DSCFALSE;}
#endif

#ifndef __HTONLL
#define __HTONLL(_ulonglong_)	if(__BYTE_ORDER==__LITTLE_ENDIAN){_ulonglong_=( (((ulonglong)htonl((unsigned int)(((_ulonglong_)<<32)>>32)))<<32) | ((ulonglong)htonl((unsigned int)((_ulonglong_)>>32))) ) ; }
#define __NTOHLL(_ulonglong_)	if(__BYTE_ORDER==__LITTLE_ENDIAN){_ulonglong_=( (ulonglong)( (((ulonglong)ntohl((unsigned int)(((_ulonglong_)<<32)>>32)))<<32) | ((ulonglong)ntohl((unsigned int)((_ulonglong_)>>32))) ) ) ; }
#endif

#ifndef __HTONF
#define __HTONF(_float_)		if(__BYTE_ORDER==__LITTLE_ENDIAN){union{unsigned int ui;float f;}_ui_f_; _ui_f_.f=_float_; _ui_f_.ui=htonl(_ui_f_.ui); _float_=_ui_f_.f; }
#define __NTOHF(_float_)		if(__BYTE_ORDER==__LITTLE_ENDIAN){union{unsigned int ui;float f;}_ui_f_; _ui_f_.f=_float_; _ui_f_.ui=ntohl(_ui_f_.ui); _float_=_ui_f_.f; }
#endif

#ifndef __HTONLF
#define __HTONLF(_double_)		if(__BYTE_ORDER==__LITTLE_ENDIAN){union{ulonglong ull;double d;}_ull_d_; _ull_d_.d=_double_; __HTONLL(_ull_d_.ull); _double_=_ull_d_.d; }
#define __NTOHLF(_double_)		if(__BYTE_ORDER==__LITTLE_ENDIAN){union{ulonglong ull;double d;}_ull_d_; _ull_d_.d=_double_; __NTOHLL(_ull_d_.ull); _double_=_ull_d_.d; }
#endif

#ifndef COMPRESS_INT4
#define COMPRESS_INT4(_int4_,_buf_,_bufoffset_)					\
	{									\
		unsigned char	_flag_ = 0 ;					\
		unsigned int	_h_ ;						\
		unsigned int	_n_ ;						\
		if( _int4_ < 0 )						\
		{								\
			_h_ = -_int4_ ;						\
			_n_ = htonl( _h_ ) ;					\
			_flag_ |= 0x10 ;					\
		}								\
		else								\
		{								\
			_h_ = _int4_ ;						\
			_n_ = htonl( _h_ ) ;					\
		}								\
		if( _h_ & 0xFF000000 )						\
		{								\
			_buf_[0] = _flag_ | 4 ;					\
			memcpy( _buf_+1 , ((unsigned char *)&_n_) , 4 );	\
			_bufoffset_+=5; _buf_+=5 ;				\
		}								\
		else if( _h_ & 0x00FF0000 )					\
		{								\
			_buf_[0] = _flag_ | 3 ;					\
			memcpy( _buf_+1 , ((unsigned char *)&_n_)+1 , 3 );	\
			_bufoffset_+=4; _buf_+=4 ;				\
		}								\
		else if( _h_ & 0x0000FF00 )					\
		{								\
			_buf_[0] = _flag_ | 2 ;					\
			memcpy( _buf_+1 , ((unsigned char *)&_n_)+2 , 2 );	\
			_bufoffset_+=3; _buf_+=3 ;				\
		}								\
		else								\
		{								\
			_buf_[0] = _flag_ | 1 ;					\
			memcpy( _buf_+1 , ((unsigned char *)&_n_)+3 , 1 );	\
			_bufoffset_+=2; _buf_+=2 ;				\
		}								\
	}
#endif

#ifndef UNCOMPRESS_INT4
#define UNCOMPRESS_INT4(_buf_,_bufoffset_,_int4_)				\
	{									\
		unsigned char	_flag_ = 0 ;					\
		_int4_ = 0 ;							\
		_flag_ = _buf_[0] & 0xF0 ;					\
		_buf_[0] &= 0x0F ;						\
		memcpy( ((unsigned char*)&_int4_) + (4-_buf_[0]) , _buf_+1 , _buf_[0] );\
		_int4_ = ntohl( _int4_ ) ;					\
		if( _flag_ & 0x10 )						\
		{								\
			_int4_ = -_int4_ ;					\
		}								\
		_bufoffset_+=1+_buf_[0]; _buf_+=1+_buf_[0];			\
	}
#endif

#ifndef COMPRESS_UINT4
#define COMPRESS_UINT4(_uint4_,_buf_,_bufoffset_)				\
	{									\
		unsigned int	_h_ ;						\
		unsigned int	_n_ ;						\
		_h_ = _uint4_ ;							\
		_n_ = htonl( _h_ ) ;						\
		if( _h_ & 0xFF000000 )						\
		{								\
			_buf_[0] = 4 ;						\
			memcpy( _buf_+1 , ((unsigned char *)&_n_) , 4 );	\
			_bufoffset_+=5; _buf_+=5 ;				\
		}								\
		else if( _h_ & 0x00FF0000 )					\
		{								\
			_buf_[0] = 3 ;						\
			memcpy( _buf_+1 , ((unsigned char *)&_n_)+1 , 3 );	\
			_bufoffset_+=4; _buf_+=4 ;				\
		}								\
		else if( _h_ & 0x0000FF00 )					\
		{								\
			_buf_[0] = 2 ;						\
			memcpy( _buf_+1 , ((unsigned char *)&_n_)+2 , 2 );	\
			_bufoffset_+=3; _buf_+=3 ;				\
		}								\
		else								\
		{								\
			_buf_[0] = 1 ;						\
			memcpy( _buf_+1 , ((unsigned char *)&_n_)+3 , 1 );	\
			_bufoffset_+=2; _buf_+=2 ;				\
		}								\
	}
#endif

#ifndef UNCOMPRESS_UINT4
#define UNCOMPRESS_UINT4(_buf_,_bufoffset_,_uint4_)				\
	{									\
		_uint4_ = 0 ;							\
		_buf_[0] &= 0x0F ;						\
		memcpy( ((unsigned char*)&_uint4_) + (4-_buf_[0]) , _buf_+1 , _buf_[0] );\
		_uint4_ = ntohl( _uint4_ ) ;					\
		_bufoffset_+=1+_buf_[0]; _buf_+=1+_buf_[0];			\
	}
#endif

#ifndef COMPRESS_INT8
#define COMPRESS_INT8(_int8_,_buf_,_bufoffset_)					\
	{									\
		unsigned char	_flag_ = 0 ;					\
		unsigned longlong	_h_ ;					\
		unsigned longlong	_n_ ;					\
		if( _int8_ < 0 )						\
		{								\
			_h_ = -_int8_ ;						\
			_n_ = _h_ ;						\
			__HTONLL( _n_ );					\
			_flag_ |= 0x10 ;					\
		}								\
		else								\
		{								\
			_h_ = _int8_ ;						\
			_n_ = _h_ ;						\
			__HTONLL( _n_ );					\
		}								\
		if( _h_ & ULL(0xFF00000000000000) )				\
		{								\
			_buf_[0] = _flag_ | 8 ;					\
			memcpy( _buf_+1 , ((unsigned char *)&_n_) , 8 );	\
			_bufoffset_+=9; _buf_+=9 ;				\
		}								\
		else if( _h_ & ULL(0x00FF000000000000) )				\
		{								\
			_buf_[0] = _flag_ | 7 ;					\
			memcpy( _buf_+1 , ((unsigned char *)&_n_)+1 , 7 );	\
			_bufoffset_+=8; _buf_+=8 ;				\
		}								\
		else if( _h_ & ULL(0x0000FF0000000000) )				\
		{								\
			_buf_[0] = _flag_ | 6 ;					\
			memcpy( _buf_+1 , ((unsigned char *)&_n_)+2 , 6 );	\
			_bufoffset_+=7; _buf_+=7 ;				\
		}								\
		else if( _h_ & ULL(0x000000FF00000000) )				\
		{								\
			_buf_[0] = _flag_ | 5 ;					\
			memcpy( _buf_+1 , ((unsigned char *)&_n_)+3 , 5 );	\
			_bufoffset_+=6; _buf_+=6 ;				\
		}								\
		else if( _h_ & ULL(0x00000000FF000000) )				\
		{								\
			_buf_[0] = _flag_ | 4 ;					\
			memcpy( _buf_+1 , ((unsigned char *)&_n_)+4 , 4 );	\
			_bufoffset_+=5; _buf_+=5 ;				\
		}								\
		else if( _h_ & ULL(0x0000000000FF0000) )				\
		{								\
			_buf_[0] = _flag_ | 3 ;					\
			memcpy( _buf_+1 , ((unsigned char *)&_n_)+5 , 3 );	\
			_bufoffset_+=4; _buf_+=4 ;				\
		}								\
		else if( _h_ & ULL(0x000000000000FF00) )				\
		{								\
			_buf_[0] = _flag_ | 2 ;					\
			memcpy( _buf_+1 , ((unsigned char *)&_n_)+6 , 2 );	\
			_bufoffset_+=3; _buf_+=3 ;				\
		}								\
		else								\
		{								\
			_buf_[0] = _flag_ | 1 ;					\
			memcpy( _buf_+1 , ((unsigned char *)&_n_)+7 , 1 );	\
			_bufoffset_+=2; _buf_+=2 ;				\
		}								\
	}
#endif

#ifndef UNCOMPRESS_INT8
#define UNCOMPRESS_INT8(_buf_,_bufoffset_,_int8_)				\
	{									\
		unsigned char	_flag_ = 0 ;					\
		_int8_ = 0 ;							\
		_flag_ = _buf_[0] & 0xF0 ;					\
		_buf_[0] &= 0x0F ;						\
		memcpy( ((unsigned char*)&_int8_) + (8-_buf_[0]) , _buf_+1 , _buf_[0] );\
		__NTOHLL( _int8_ );						\
		if( _flag_ & 0x10 )						\
		{								\
			_int8_ = -_int8_ ;					\
		}								\
		_bufoffset_+=1+_buf_[0]; _buf_+=1+_buf_[0];			\
	}
#endif

#ifndef COMPRESS_UINT8
#define COMPRESS_UINT8(_uint8_,_buf_,_bufoffset_)				\
	{									\
		unsigned longlong	_h_ ;					\
		unsigned longlong	_n_ ;					\
		_h_ = _uint8_ ;							\
		_n_ = _h_ ;							\
		__HTONLL( _n_ );						\
		if( _h_ & ULL(0xFF00000000000000) )				\
		{								\
			_buf_[0] = 8 ;						\
			memcpy( _buf_+1 , ((unsigned char *)&_n_) , 8 );	\
			_bufoffset_+=9; _buf_+=9 ;				\
		}								\
		else if( _h_ & ULL(0x00FF000000000000) )				\
		{								\
			_buf_[0] = 7 ;						\
			memcpy( _buf_+1 , ((unsigned char *)&_n_)+1 , 7 );	\
			_bufoffset_+=8; _buf_+=8 ;				\
		}								\
		else if( _h_ & ULL(0x0000FF0000000000) )				\
		{								\
			_buf_[0] = 6 ;						\
			memcpy( _buf_+1 , ((unsigned char *)&_n_)+2 , 6 );	\
			_bufoffset_+=7; _buf_+=7 ;				\
		}								\
		else if( _h_ & ULL(0x000000FF00000000) )				\
		{								\
			_buf_[0] = 5 ;						\
			memcpy( _buf_+1 , ((unsigned char *)&_n_)+3 , 5 );	\
			_bufoffset_+=6; _buf_+=6 ;				\
		}								\
		else if( _h_ & ULL(0x00000000FF000000) )				\
		{								\
			_buf_[0] = 4 ;						\
			memcpy( _buf_+1 , ((unsigned char *)&_n_)+4 , 4 );	\
			_bufoffset_+=5; _buf_+=5 ;				\
		}								\
		else if( _h_ & ULL(0x0000000000FF0000) )				\
		{								\
			_buf_[0] = 3 ;						\
			memcpy( _buf_+1 , ((unsigned char *)&_n_)+5 , 3 );	\
			_bufoffset_+=4; _buf_+=4 ;				\
		}								\
		else if( _h_ & ULL(0x000000000000FF00) )				\
		{								\
			_buf_[0] = 2 ;						\
			memcpy( _buf_+1 , ((unsigned char *)&_n_)+6 , 2 );	\
			_bufoffset_+=3; _buf_+=3 ;				\
		}								\
		else								\
		{								\
			_buf_[0] = 1 ;						\
			memcpy( _buf_+1 , ((unsigned char *)&_n_)+7 , 1 );	\
			_bufoffset_+=2; _buf_+=2 ;				\
		}								\
	}
#endif

#ifndef UNCOMPRESS_UINT8
#define UNCOMPRESS_UINT8(_buf_,_bufoffset_,_uint8_)				\
	{									\
		_uint8_ = 0 ;							\
		_buf_[0] &= 0x0F ;						\
		memcpy( ((unsigned char*)&_uint8_) + (8-_buf_[0]) , _buf_+1 , _buf_[0] );\
		__NTOHLL( _uint8_ );						\
		_bufoffset_+=1+_buf_[0]; _buf_+=1+_buf_[0];			\
	}
#endif

#ifndef COMPRESS_FLOAT4
#define COMPRESS_FLOAT4(_float4_,_buf_,_bufoffset_)				\
	{									\
		__HTONF( _float4_ );						\
		memcpy( _buf_ , ((unsigned char *)&_n_) , 4 );			\
		_bufoffset_+=4; _buf_+=4 ;					\
	}
#endif

#ifndef UNCOMPRESS_FLOAT4
#define UNCOMPRESS_FLOAT4(_buf_,_bufoffset_,_float4_)				\
	{									\
		memcpy( ((unsigned char*)&_float4_) , _buf_ , 4 );		\
		__NTOHF( _float4_ );						\
		_bufoffset_+=4; _buf_+=4;					\
	}
#endif

#ifndef COMPRESS_FLOAT8
#define COMPRESS_FLOAT8(_float8_,_buf_,_bufoffset_)				\
	{									\
		__HTONLF( _float8_ );						\
		memcpy( _buf_ , ((unsigned char *)&_n_) , 8 );			\
		_bufoffset_+=8; _buf_+=8 ;					\
	}
#endif

#ifndef UNCOMPRESS_FLOAT8
#define UNCOMPRESS_FLOAT8(_buf_,_bufoffset_,_float8_)				\
	{									\
		memcpy( ((unsigned char*)&_float8_) , _buf_ , 8 );		\
		__NTOHLF( _float8_ );						\
		_bufoffset_+=8; _buf_+=8;					\
	}
#endif

typedef struct
{
	char	version ;
	#define RESPONSE_CODE_PASSWORD_NOTMATCH	-12345
	struct
	{
		char	transaction_code[ 32 + 1 ] ;
		int	trans_jnlsno ;
		int	response_code ;
		char	response_desc[ 1024 + 1 ] ;
	} ResponseHeader ;
	struct
	{
		struct
		{
			struct
			{
				char	message_text[ 64 + 1 ] ;
			} AddonMessage [ 3 ] ;
			int	_AddonMessage_count ;
			int	_AddonMessage_size ;
		} AddonMessages ;
		struct
		{
			char	title_text[ 64 + 1 ] ;
			short	page_no ;
			short	page_size ;
		} TransactionDetailTitle ;
		struct
		{
			struct
			{
				char	trans_date[ 10 + 1 ] ;
				char	trans_time[ 10 + 1 ] ;
				char	outlet_id[ 6 + 1 ] ;
				char	card_no[ 20 + 1 ] ;
				float	trans_amount ;
			} TransactionDetail [ 10 ] ;
			int	_TransactionDetail_count ;
			int	_TransactionDetail_size ;
		} TransactionDetails ;
	} QueryTransactionDetails ;
} BankTransaction ;

_WINDLL_FUNC int DSCINIT_BankTransaction( BankTransaction *pst );

_WINDLL_FUNC int DSCNETORDER_BankTransaction( BankTransaction *pst );
_WINDLL_FUNC int DSCHOSTORDER_BankTransaction( BankTransaction *pst );

#define DSCSERIALIZE_COMPRESS_BUFSIZE_BankTransaction	2951

_WINDLL_FUNC int DSCSERIALIZE_COMPRESS_BankTransaction( BankTransaction *pst , char *buf , int *p_len );
_WINDLL_FUNC int DSCDESERIALIZE_COMPRESS_BankTransaction( char *buf , int *p_len , BankTransaction *pst );

#endif
