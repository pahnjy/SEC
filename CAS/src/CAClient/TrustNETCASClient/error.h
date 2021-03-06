#ifndef ERROR_H
#define ERROR_H

#define TN_ERROR					-500000

#define ER_INIT						-10000
#define ER_ISSUEDEVICECERT			-20000
#define ER_GETDEVICECERT			-30000
#define ER_GETDEVICEPRIKEYANDPASS	-40000
#define ER_GETAUTHKEYFROMMEF		-50000

#define ER_INITCONTEXT				-100
#define ER_SETCONFIG				-200
#define ER_INITCOMM					-300
#define ER_CHECKCONTEXT				-400
#define ER_CHECKDEVICEID			-500
#define ER_REGDEVICEGETDN			-600
#define ER_MAKECERTPASS				-700
#define ER_ISSUECERTSIMPLE			-800
#define ER_SAVECERTSET				-9000
#define ER_GETCERTSET				-1000
#define ER_AUTHBYCERT				-1100
#define ER_FINALCONTEXT				-1200

#define ER_ARG							-1
#define ER_MALLOC						-2
#define ER_FILEOPEN						-3
#define ER_RESULT						-4
#define ER_REQTOCASERVER_MAKEREQUEST	-5
#define ER_REQTOCASERVER_CONNECT		-6
#define ER_REQTOCASERVER_SEND			-7
#define ER_REQTOCASERVER_HTTP_RECV		-8
#define ER_PARSEXML						-9
#define ER_SETUSTRING					-10
#define ER_MAKEHMAC						-11
#define ER_BASE64ENCODING				-12
#define ER_MAKECSR						-13
#define ER_WRITETXTFILE					-14
#define ER_READTXTFILE					-15

#endif
